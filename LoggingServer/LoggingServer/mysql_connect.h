#pragma once

#ifndef _MYSQL_CONNECTION_
#define _MYSQL_CONNECTION_

//c++
#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <functional>

//mysql driver
#include <mysql_driver.h>
#include <mysql_connection.h>

//mysql execute
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <exception>

#pragma comment(lib, "mysqlcppconn.lib")
//thread mutex 
#include <mutex>

using namespace sql;
using namespace std;

using delFunc = std::function<void(Connection*)>;

//for demonstration only. never save your password in the code!
const string g_server = "tcp://127.0.0.1:3306";
const string g_username = "root";
const string g_password = "root";

class ConnectionPool
{
public:
	//��ȡ���ݿ����ӳض��� static����ģʽ
	static ConnectionPool* getInstance();
	//�õ�һ������
	auto getConnect()->std::shared_ptr<Connection>;
	//�黹һ������
	auto retConnect(std::shared_ptr<Connection> &ret)->void;
	~ConnectionPool();


private:
	ConnectionPool(std::string name, std::string pwd, std::string nurl, int maxSize);
	//��ʼ�����ӳ�
	auto initConnectPool(int initialSize)->void;
	//�ٻ����ӳ�
	auto destoryPool()->void;
	//destory one connection
	auto destoryOneConn()->void;
	//�������ݿ����ӳ�
	auto expandPool(int size)->void;
	//��С���ݿ����ӳ�
	auto reducePool(int size)->void;
	//add conn
	auto addConn(int size)->void;
public:
	//get size
	auto getPoolSize()->int;

private:
	std::string username; //�ʺ�
	std::string password; //����
	std::string url;      //����url
	int poolSize;       //pool size

						//�����������
	std::list<std::shared_ptr<Connection>> conList;

	static ConnectionPool *pool;//���ӳض���
	std::mutex lock;//��
	Driver *driver;//mysql driver
};



#endif