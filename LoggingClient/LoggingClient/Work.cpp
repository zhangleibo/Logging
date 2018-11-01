#include "Work.h"


bool g_bRun = true;

CWork::CWork() : m_msgProtoMfr(this)
{
}

CWork::~CWork()
{
}

void CWork::work(const char* ip, int port)
{
	do 
	{
		if(nullptr == ip) break;

		if (!CSocketApp::open(ip, port)) continue;

		printf("Open socket succ!\n");

		g_bRun = true;

		while (g_bRun)
		{
			m_msgProtoMfr.Process();
			Sleep(500);
		}
	} while (1);
}

void CWork::HandleMsg(std::string &msg)
{
	m_msgProtoMfr.HandleMsg(msg);
}

void CWork::SendMsg(std::string &msg)
{
	if (!Send(msg))
	{
		printf("send msg fail!\n");
		g_bRun = false;
	}
}