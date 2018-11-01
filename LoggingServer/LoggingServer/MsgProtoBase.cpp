#include "MsgProtoBase.h"

CMsgProtoBase::CMsgProtoBase()
{

}

CMsgProtoBase::~CMsgProtoBase()
{

}

std::string CMsgProtoBase::EncodeMsg(google::protobuf::Message &pMsg)
{
	//proto msg
	std::vector<string> vecProto;
	string strType, strMsg;
	strType = pMsg.GetTypeName();
	pMsg.AppendToString(&strMsg);
	vecProto.push_back(strType);
	vecProto.push_back(strMsg);

	return EncodeProtobuf(vecProto);
}

bool CMsgProtoBase::DecodeMsg(std::string &msg, std::string type, google::protobuf::Message* &pMsg)
{
	bool bOk = false;

	do
	{
		std::string strHead;

		if (!PBDecode(msg, strHead, pMsg))
		{
			break;
		}

		if (type != strHead)
		{
			break;
		}

		bOk = true;
	} while (0);

	return bOk;
}
