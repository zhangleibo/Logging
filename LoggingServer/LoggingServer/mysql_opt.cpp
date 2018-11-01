#include "mysql_opt.h"
#include "ModuleInfo.pb.h"
#include <windows.h>

#define BUFFER_SIZE 2048

#define DATABASE_NAME "LOGGING"
#define CREATE_DATABASE "CREATE DATABASE IF NOT EXISTS %s;"
#define CREATE_TABLE_BY_PCID "CREATE TABLE IF NOT EXISTS %s "\
"(id serial PRIMARY KEY, appid INTEGER, filename VARCHAR(512), funcname VARCHAR(128), line INTEGER, machinename VARCHAR(128), time VARCHAR(128));"
#define INSERT_DATA_BY_PCID "INSERT INTO %s (appid, filename, funcname, line, machinename, time) VALUES(?,?,?,?,?,?)"

CMySqlOpt::CMySqlOpt()
{
	m_connectionPool = ConnectionPool::getInstance();

	std::shared_ptr<Connection> con;
	sql::Statement *stmt = NULL;

	ConnectionPool* pool = m_connectionPool;

	//获得一个连接
	con = pool->getConnect();

	//获得一个数据库连接对象
	stmt = con->createStatement();

	char sql_cmd[BUFFER_SIZE] = {};
	sprintf_s(sql_cmd, CREATE_DATABASE, DATABASE_NAME);
	bool bRet = stmt->execute(sql_cmd);

	delete stmt;
	pool->retConnect(con);
}

CMySqlOpt::~CMySqlOpt()
{

}

bool CMySqlOpt::InsertData(google::protobuf::Message* pMsg)
{
	//提取数据
	const CMSGProto::module_info_req* pModule = (const CMSGProto::module_info_req*)pMsg;
	if (NULL == pModule)
	{
		return false;
	}

	string pc_id = pModule->pc_id();
	int app_id = pModule->app_id();
	std::string file_name = pModule->file_name();
	std::string func_name = pModule->func_name();
	int line = pModule->line();
	std::string machine_name = pModule->machine_name();
	std::string time = pModule->time();

	//数据库操作
	//////////////////////////////////////////////////////////////////////////
	std::shared_ptr<Connection> con;
	sql::Statement *stmt = NULL;
	sql::PreparedStatement *pstmt = NULL;

	ConnectionPool* pool = m_connectionPool;

	//获得一个连接
	con = pool->getConnect();

	try
	{
		//使用xxx这个数据库
		con->setSchema(DATABASE_NAME);
	}
	catch (sql::SQLException e)   
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		MessageBoxA(NULL, e.what(), "Could not connect to server. Error message:", 0);
		return false;
	}

	//获得一个数据库连接对象
	stmt = con->createStatement();

	char sql_cmd[BUFFER_SIZE] = {};
	sprintf_s(sql_cmd, CREATE_TABLE_BY_PCID, pc_id.c_str());
	bool bRet = stmt->execute(sql_cmd);

	delete stmt;
	//////////////////////////////////////////////////////////////////////////
	//insert data

	memset(sql_cmd, '\0', BUFFER_SIZE);
	sprintf_s(sql_cmd, INSERT_DATA_BY_PCID, pc_id.c_str());

	pstmt = con->prepareStatement(sql_cmd);
	pstmt->setInt(1, app_id);//appid
	pstmt->setString(2, file_name);//filename
	pstmt->setString(3, func_name);//funcname
	pstmt->setInt(4, line);//line
	pstmt->setString(5, machine_name);//machinename
	pstmt->setString(6, time);//time

	pstmt->execute();
	cout << "One row inserted." << endl;
	//////////////////////////////////////////////////////////////////////////

	delete pstmt;
	pool->retConnect(con);
	std::cout << pool->getPoolSize() << std::endl;

	return true;
}
