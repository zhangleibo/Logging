#pragma once
#include "DEecode.h"

class CMsgProtoBase : CDEecode
{
public:
	CMsgProtoBase();
	~CMsgProtoBase();

protected:
	std::string EncodeMsg(google::protobuf::Message &pMsg);
	bool DecodeMsg(std::string &msg, std::string type, google::protobuf::Message* &pMsg);
};