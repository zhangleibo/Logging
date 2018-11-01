#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mysql_connect.h"

ConnectionPool*
ConnectionPool::pool = nullptr;

//private
//���캯��
ConnectionPool::ConnectionPool(std::string name, std::string pwd, std::string nurl, int maxSize) :
	username(name), password(pwd), url(nurl), poolSize(maxSize)
{
	//�õ�mysql����
	driver = get_driver_instance();
	//��ʼ��ʼ����Сһ��
	initConnectPool(poolSize / 2);
}

//��������
ConnectionPool::~ConnectionPool()
{
	destoryPool();
}

//�õ����ӳش�С
int
ConnectionPool::getPoolSize()
{
	return conList.size();
}

//��������
void
ConnectionPool::addConn(int size)
{
	for (int i = 0; i < size; ++i)
	{
		//��������
		Connection *conn = driver->connect(url, username, password);
		std::shared_ptr<Connection> sp(conn,
			[](Connection *conn) {
			delete conn;
		});
		conList.push_back(std::move(sp));
	}
}

//��ʼ�����ӳ�
void
ConnectionPool::initConnectPool(int initialSize)
{
	//����������һ������
	std::lock_guard<std::mutex> locker(lock);
	addConn(initialSize);
}

//����һ������
void
ConnectionPool::destoryOneConn()
{
	//����ָ���std::moveת��һ�����ӵġ�����Ȩ��������������ʱ���Զ����ùر�connect
	std::shared_ptr<Connection> &&sp = std::move(conList.front());
	sp->close();
	--poolSize;
}

//�����������ӳ�
void
ConnectionPool::destoryPool()
{
	for (auto &conn : conList)
	{
		//����ת������Ȩ����������ʱ���ر����ӣ���������ʱ����ָ���Զ��ͷ�
		std::shared_ptr<Connection> &&sp = std::move(conList.front());
		sp->close();
	}
}

//�������ӳ�
void
ConnectionPool::expandPool(int size)
{
	std::lock_guard<std::mutex> locker(lock);
	addConn(size);
	poolSize += size;
}

//��С���ӳ�
void
ConnectionPool::reducePool(int size)
{
	std::lock_guard<std::mutex> locker(lock);
	//��С�Ĵ�С���ܳ����洢�Ĵ�С
	if (size > poolSize)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		//sp point new object, old object release
		destoryOneConn();
	}
	poolSize -= size;
}

//public
//�õ����ӳ�ʵ��
ConnectionPool*
ConnectionPool::getInstance()
{
	if (pool == nullptr)
	{
		//3306��mysqlռ�õĶ˿ڣ���ʵ����40������
		pool = new ConnectionPool(g_username, g_password, g_server, 40);
	}
	return pool;
}

//�õ�һ������
std::shared_ptr<Connection>
ConnectionPool::getConnect()
{
	std::lock_guard<std::mutex> locker(lock);
	std::shared_ptr<Connection> sp = conList.front();
	conList.pop_front();
	return sp;
}

//�黹һ������
void
ConnectionPool::retConnect(std::shared_ptr<Connection> &ret)
{
	std::lock_guard<std::mutex>locker(lock);
	conList.push_back(ret);
}