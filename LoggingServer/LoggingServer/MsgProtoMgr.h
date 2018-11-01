#pragma once
#include "ModuleRegister.h"
#include "ModuleInfo.h"
#include <WinSock2.h>

class CWork;

class CMsgProtoMgr
{
public:
	CMsgProtoMgr(CWork* work);
	~CMsgProtoMgr();

	void Handle(SOCKET newsock, std::string &msg);
private:
	CWork* m_work;

	CModuleRegister m_moduleRegister;
	CModuleInfo m_moduleInfo;
};