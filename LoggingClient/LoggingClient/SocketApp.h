#pragma once
#include "../ThreadPool/thread.h"
#include "SocketImpl.h"
#include "CritSec.h"

class CSocketApp : public CSocketImpl, IThread
{
public:
	CSocketApp();
	~CSocketApp();

	bool open(const char* ip, const int iPort, int iTimeOut = 3);
	virtual void HandleMsg(std::string &msg) {};//子类实现，处理消息
protected:
	virtual void Run();
	bool Recv(std::string &msg);

public:
	bool Send(std::string &msg);

private:
	bool m_bRun;
	CritSec m_cirtSec;
};