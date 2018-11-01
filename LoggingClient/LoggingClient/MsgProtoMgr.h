#pragma once
#include "ModuleRegister.h"
#include "ModuleInfo.h"

class CWork;

class CMsgProtoMgr
{
public:
	CMsgProtoMgr(CWork* work);
	~CMsgProtoMgr();

	void HandleMsg(std::string &msg);
	void Process();
private:
	CWork* m_work;

	CModuleRegister m_moduleRegister;
	CModuleInfo m_moduleInfo;
};