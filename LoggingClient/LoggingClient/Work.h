#pragma once
#include "SocketApp.h"
#include "MsgProtoMgr.h"

class CWork : public CSocketApp
{
public:
	static CWork* GetInstance()
	{
		static CWork Obj;
		return &Obj;
	}

	void work(const char* ip, int port);
	virtual void HandleMsg(std::string &msg);
	void SendMsg(std::string &msg);

private:
	CWork();
	~CWork();

	CMsgProtoMgr m_msgProtoMfr;
};