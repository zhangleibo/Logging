#include "Work.h"

CWork::CWork() : m_msgProtoMgr(this)
{

}

CWork::~CWork()
{

}

void CWork::Handle(SOCKET newsock, std::string &msg)
{
	m_msgProtoMgr.Handle(newsock, msg);
}
