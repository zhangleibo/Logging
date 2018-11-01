#pragma once
#include "TcpServer.h"
#include "MsgProtoMgr.h"

class CWork : public CTcpServer
{
public:
	CWork();
	~CWork();

	virtual void Handle(SOCKET newsock, std::string &msg);

private:
	CMsgProtoMgr m_msgProtoMgr;
};