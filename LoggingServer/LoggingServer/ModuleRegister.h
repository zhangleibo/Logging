#pragma once
#include <string>
#include "ModuleRegister.pb.h"
#include "MsgProtoBase.h"

using namespace CMSGProto;
class CModuleRegister : public CMsgProtoBase
{
public:
	CModuleRegister() {};
	~CModuleRegister() {};

	std::string MsgEncode(int id = 0)
	{
		module_register_reply module;

		module.set_id(id);
		module.set_name(m_moduleName);

		return EncodeMsg(module);
	}

	bool MsgDecode(std::string &strMsg)
	{
		bool bOk = false;
		google::protobuf::Message* pMsg = NULL;

		do
		{
			module_register_req module;
			if (!DecodeMsg(strMsg, module.GetTypeName(), pMsg))
			{
				break;
			}

			const module_register_req* pModuleRegister = (const module_register_req*)pMsg;

			if (NULL == pModuleRegister)
			{
				break;
			}

			int id = pModuleRegister->id();
			std::string name = pModuleRegister->name();
			m_moduleName = name;

			printf("id = %d name = %s\n", id, name.c_str());

			bOk = true;
		} while (0);

		if (NULL != pMsg)
		{
			delete pMsg;
			pMsg = NULL;
		}

		return bOk;
	}

private:
	std::string m_moduleName;
};