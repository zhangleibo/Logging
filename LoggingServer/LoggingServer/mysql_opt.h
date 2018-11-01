#pragma once
#include "DEecode.h"
#include "mysql_connect.h"

typedef struct data_struct
{

}DATA_STRUCT, *PDATA_STRUCT;

class CMySqlOpt
{
public:
	CMySqlOpt();
	~CMySqlOpt();
	bool InsertData(google::protobuf::Message* pMsg);

private:
	ConnectionPool *m_connectionPool;
};
