#pragma once
#include "MsgProtoBase.h"
#include "ModuleInfo.pb.h"
#include <windows.h>
#include <time.h>
#include "mysql_opt.h"

using namespace CMSGProto;
class CModuleInfo : public CMsgProtoBase
{
public:
	CModuleInfo() {};
	~CModuleInfo() {};

	std::string MsgEncode(int id = 0)
	{
		module_info_reply module;
		module.set_reply(id);

		return EncodeMsg(module);
	}

	bool MsgDecode(std::string &strMsg)
	{
		bool bOk = false;
		google::protobuf::Message* pMsg = NULL;

		do
		{
			module_info_req module;
			if (!DecodeMsg(strMsg, module.GetTypeName(), pMsg))
			{
				break;
			}

			/*		const module_info_req* pModule = (const module_info_req*)pMsg;

					if (NULL == pModule)
					{
						break;
					}

					int unique_id = pModule->unique_id();
					int app_id = pModule->app_id();
					int index = pModule->index();
					std::string file_name = pModule->file_name();
					std::string func_name = pModule->func_name();
					int line = pModule->line();
					std::string machine_name = pModule->machine_name();
					std::string time = pModule->time();

					printf("%s unique_id:%d app_id:%d,index:%d file_name:%s func_name:%s line:%d machine_name:%s\n",
						time.c_str(),
						unique_id,
						app_id,
						index,
						file_name.c_str(),
						func_name.c_str(),
						line,
						machine_name.c_str());*/

			//≤Â»Î ˝æ›ø‚
			m_mySqlOpt.InsertData(pMsg);

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

private:
	CMySqlOpt m_mySqlOpt;
};