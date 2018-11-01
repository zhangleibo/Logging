#pragma once
#include "MsgProtoBase.h"
#include "ModuleInfo.pb.h"
#include <windows.h>
#include <time.h>

using namespace CMSGProto;
class CModuleInfo : public CMsgProtoBase
{
public:
	CModuleInfo() {};
	~CModuleInfo() {};

	std::string MsgEncode(std::string name, int id = 0)
	{
		module_info_req module;
		int processId = ::GetCurrentProcessId();
		int threadId = ::GetCurrentThreadId();


		module.set_pc_id("pcid123456678794161361");
		module.set_app_id(threadId);
		module.set_file_name(__FILE__);
		module.set_func_name(__FUNCTION__);
		module.set_line(__LINE__);
		module.set_machine_name("TEST");
		module.set_time(GetLocalTimeText());

		return EncodeMsg(module);
	}

	bool MsgDecode(std::string &strMsg)
	{
		bool bOk = false;
		google::protobuf::Message* pMsg = NULL;

		do
		{
			module_info_reply module;
			if (!DecodeMsg(strMsg, module.GetTypeName(), pMsg))
			{
				break;
			}

			const module_info_reply* pModule = (const module_info_reply*)pMsg;

			if (NULL == pModule)
			{
				break;
			}

			if (0 == pModule->reply())
			{
				printf("%s module_info_reply ok\n", GetLocalTimeText().c_str());
			}
			else
			{
				printf("module_info_reply failed\n");
			}

			bOk = true;
		} while (0);

		if (NULL != pMsg)
		{
			delete pMsg;
			pMsg = NULL;
		}

		return bOk;
	}

	std::string GetLocalTimeText()
	{
		SYSTEMTIME tmNow;
		::GetLocalTime(&tmNow);

		char szTime[MAX_PATH] = { 0 };
		sprintf_s(szTime, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d:%.3d ",
			tmNow.wYear, tmNow.wMonth, tmNow.wDay,
			tmNow.wHour, tmNow.wMinute, tmNow.wSecond,
			tmNow.wMilliseconds);

		return szTime;
	}
};