#include "MsgProtoMgr.h"
#include "Work.h"

CMsgProtoMgr::CMsgProtoMgr(CWork* work) : m_work(work)
{

}

CMsgProtoMgr::~CMsgProtoMgr()
{

}

void CMsgProtoMgr::Handle(SOCKET newsock, std::string &msg)
{
	std::string strRet;
	if (m_moduleRegister.MsgDecode(msg))
	{
		printf("Ä£¿é×¢²áÇëÇó\n");

		static int icnt = 0;

		strRet = m_moduleRegister.MsgEncode(++icnt);
	}
	else if (m_moduleInfo.MsgDecode(msg))
	{
		strRet = m_moduleInfo.MsgEncode();
	}

	if (!strRet.empty())
	{
		send(newsock, strRet.c_str(), strRet.size(), 0);
	}
}

