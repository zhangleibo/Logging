#include "SocketApp.h"

typedef unsigned long ulong;

CSocketApp::CSocketApp() : m_bRun(true)
{

}

CSocketApp::~CSocketApp()
{
	m_bRun = false;
}

bool CSocketApp::open(const char* ip, const int iPort, int iTimeOut /*= 3*/)
{
	//open socket
	bool bOk = CSocketImpl::open(ip, iPort, iTimeOut);

	if (bOk)
	{
		m_bRun = true;
		Start();//create recv thread
	}

	return bOk;
}

void CSocketApp::Run()
{
	std::string strBuff;

	while (m_bRun)
	{
		if (Recv(strBuff))
		{
			//TODO:接受数据如何处理
			if (strBuff.size())
			{
				HandleMsg(strBuff);
			}
		}
		else
		{
			m_bRun = false;
			Stop();
		}
	}
}

bool CSocketApp::Recv(std::string &msg)
{
	bool bOk = false;

	do
	{
		ulong nNetBodyLen = 0;
		ulong nHostBodyLen = 0;

		//接收头信息
		if (!CSocketImpl::RecvData((char *)&nNetBodyLen, sizeof(ulong)))
			break;

		nHostBodyLen = ntohl(nNetBodyLen);

		ulong nTotalLen = nHostBodyLen + sizeof(ulong);
		string msgInfo(nTotalLen, '\0');
		char* pMsg = &msgInfo.at(0);
		char* pMsgBody = pMsg + sizeof(ulong);

		memcpy(pMsg, &nNetBodyLen, sizeof(nNetBodyLen));
		if (!CSocketImpl::RecvData(pMsgBody, nHostBodyLen))
			break;

		msg = msgInfo;

		bOk = true;
	}while(0);

	return bOk;
}

bool CSocketApp::Send(std::string &msg)
{
	//线程锁
	AutoLock lock(&m_cirtSec);

	return CSocketImpl::sendData(msg);
}