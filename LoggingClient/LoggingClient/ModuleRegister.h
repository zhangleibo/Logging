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

	std::string MsgEncode(std::string name, int id = 0)
	{
		module_register_req module;

		module.set_id(id);
		module.set_name(name);

		return EncodeMsg(module);
	}

	bool MsgDecode(std::string &strMsg)
	{
		bool bOk = false;
		google::protobuf::Message* pMsg = NULL;

		do
		{
			module_register_reply module;
			if (!DecodeMsg(strMsg, module.GetTypeName(), pMsg))
			{
				break;
			}

			const module_register_reply* pModuleRegister = (const module_register_reply*)pMsg;

			if (NULL == pModuleRegister)
			{
				break;
			}

			int id = pModuleRegister->id();
			std::string name = pModuleRegister->name();

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
};