#ifndef DECODE_INCLUDE_H
#define DECODE_INCLUDE_H
#include <string>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

enum DecodeErrorType
{
	DECODE_SUCCESS = 0,
	DECODE_ERROR_TOTAL_SIZE = -100,
	DECODE_ERROR_CHECKSUM = -100,
	DECODE_ERROR_NAMELEN = -101,
	DECODE_ERROR_UNKNOW_MSG_TYPE = -102,
	DECODE_ERROR_PARSE_MSG_FAIL = -103,

};

using namespace std;
using namespace google::protobuf;

class CDEecode
{
public:
	bool PBDecode(std::string& strMsg, std::string& head, google::protobuf::Message* &pMsg);
	void PBEncode(std::vector<std::string> &vecMsg, std::vector<std::string> &retVec);
protected:
	DecodeErrorType DecodeProtobuf(const std::string &strMsg, Message* &pMsg);
	std::string EncodeProtobuf(const std::vector<std::string>& vecMsg);
private:
	int32_t NetToHost(const char* pbuf);
	int32_t HostToNet(int32_t tmp);
};

#endif // !DECODE_INCLUDE_H
