#include "MsgProtoMgr.h"
#include "Work.h"

CMsgProtoMgr::CMsgProtoMgr(CWork* work) : m_work(work)
{

}

CMsgProtoMgr::~CMsgProtoMgr()
{

}

void CMsgProtoMgr::HandleMsg(std::string &msg)
{
	if (m_moduleRegister.MsgDecode(msg))
	{
		printf("Ä£¿é×¢²á³É¹¦\n");
	}
	else if (m_moduleInfo.MsgDecode(msg))
	{

	}
}

void CMsgProtoMgr::Process()
{
	if (m_work)
	{
		static bool bRegister = false;
		if (!bRegister)
		{
			m_work->SendMsg(m_moduleRegister.MsgEncode("Module_Register"));
			bRegister = true;
		}

		m_work->SendMsg(m_moduleInfo.MsgEncode("Module_Info"));
	}
}
