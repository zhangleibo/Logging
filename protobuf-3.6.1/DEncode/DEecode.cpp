#include "DEecode.h"
#include <stdint.h>
#include <string>
#include <assert.h>
#include <WinSock.h>
#include "crc32.h"

using namespace google::protobuf;


#define SIZEOF_INT sizeof(int)

/**************************************************************************
protobuf消息体结构
+-------------------------------------------------------------------------+
| TotalLen | TypeNameLen |    TypeName    |    ProtobufData    | CheckSum |
+-------------------------------------------------------------------------+
|  4 byte  |   4 byte    |     n byte     |       n byte       |  4 byte  |
+-------------------------------------------------------------------------+

注：TypeNameLen include '\0'; TypeName >= 2 byte; ProtobufData >= 1 byte.
**************************************************************************/

DecodeErrorType CDEecode::DecodeProtobuf(const std::string &strMsg, Message* &pMsg)
{
	DecodeErrorType errType = DECODE_ERROR_TOTAL_SIZE;
	Message* pNewMessage = NULL;

	if (strMsg.empty())
	{
		return errType;
	}

	const char* pbuf = (char*)strMsg.c_str();//字符串指针
	size_t bufSize = strMsg.size();//字符串总长度

	do 
	{
		//校验字符串总大小 bufSize >= TotalLen + TypeNameLen + TypeName + ProtobufData + CheckSum
		if (bufSize < (SIZEOF_INT + SIZEOF_INT + 2 + 1 + SIZEOF_INT))
		{
			break;
		}

		//消息长度断言
		//assert(bufSize == (size_t)(NetToHost(pbuf) + SIZEOF_INT));
		if (bufSize != (size_t)(NetToHost(pbuf) + SIZEOF_INT))
		{
			break;
		}

		//crc32 校验
		int32_t uCheckSum = NetToHost(pbuf + bufSize - SIZEOF_INT);
		UINT crcCheckSum = GenerateCrc32(pbuf + SIZEOF_INT, bufSize - 2 * SIZEOF_INT);
		if (uCheckSum != crcCheckSum)
		{
			errType = DECODE_ERROR_CHECKSUM;
			break;
		}

		//TypeName校验
		UINT uTypeNameLen = NetToHost(pbuf + SIZEOF_INT);
		if ((uTypeNameLen < 2) || ( (bufSize - 3 * SIZEOF_INT - 1) < uTypeNameLen))
		{
			errType = DECODE_ERROR_NAMELEN;
			break;
		}

		//TypeName解析 uTypeNameLen 包含 '\0'
		std::string typeName(pbuf + 2 * SIZEOF_INT, uTypeNameLen - 1);
		const Descriptor* pDesc = DescriptorPool::generated_pool()->FindMessageTypeByName(typeName);

		if (!pDesc)
		{
			errType = DECODE_ERROR_UNKNOW_MSG_TYPE;
			break;
		}

		const Message* pPrototype = MessageFactory::generated_factory()->GetPrototype(pDesc);

		if (!pPrototype)
		{
			errType = DECODE_ERROR_UNKNOW_MSG_TYPE;
			break;
		}

		pNewMessage = pPrototype->New();

		if (!pNewMessage)
		{
			errType = DECODE_ERROR_UNKNOW_MSG_TYPE;
			break;
		}

		//ProtobufData解析
		const char* pProtobufData = pbuf + 2 * SIZEOF_INT + uTypeNameLen;
		int32_t uProtobufDataLen = bufSize - 3 * SIZEOF_INT - uTypeNameLen;

		//解析消息
		if (!pNewMessage->ParseFromArray(pProtobufData, uProtobufDataLen))
		{
			errType = DECODE_ERROR_PARSE_MSG_FAIL;
			break;
		}

		pMsg = pNewMessage;
		pNewMessage = NULL;

		errType = DECODE_SUCCESS;

	} while (0);

	if (NULL != pNewMessage)
	{
		delete pNewMessage;
		pNewMessage = NULL;
	}

	return errType;
}

/**************************************************************************
protobuf消息体结构
+-------------------------------------------------------------------------+
| TotalLen | TypeNameLen |    TypeName    |    ProtobufData    | CheckSum |
+-------------------------------------------------------------------------+
|  4 byte  |   4 byte    |     n byte     |       n byte       |  4 byte  |
+-------------------------------------------------------------------------+

注：TypeNameLen include '\0'; TypeName >= 2 byte; ProtobufData >= 1 byte.
**************************************************************************/
std::string CDEecode::EncodeProtobuf(const std::vector<std::string>& vecMsg)
{
	std::string strResult;
	if (vecMsg.size() < 2)
	{
		return strResult;
	}

	//TotalLen size byte
	strResult.resize(SIZEOF_INT);

	//TypeNameLen size
	const std::string &typeName = vecMsg[0];
	int32_t iTypeNameLen = typeName.size() + 1;//include '\0'
	int32_t iHToNTypeName = HostToNet(iTypeNameLen);
	strResult.append(reinterpret_cast<char*>(&iHToNTypeName), SIZEOF_INT);

	//TypeName string
	strResult.append(typeName.c_str(), iTypeNameLen);

	//ProtobufData string
	strResult.append(vecMsg[1]);

	//CheckSum size
	int32_t iCheckSum = GenerateCrc32(strResult.c_str() + SIZEOF_INT, strResult.size() - SIZEOF_INT);
	int32_t iHToNCheckSum = HostToNet(iCheckSum);
	strResult.append(reinterpret_cast<char*>(&iHToNCheckSum), SIZEOF_INT);

	//TotalLen size recover
	int32_t  iBodyLen = strResult.size() - SIZEOF_INT;
	int32_t iHToNBodyLen = HostToNet(iBodyLen);
	std::copy(reinterpret_cast<char*>(&iHToNBodyLen), reinterpret_cast<char*>(&iHToNBodyLen) + SIZEOF_INT, strResult.begin());

	return strResult;
}

int32_t CDEecode::NetToHost(const char* pbuf)
{
	if (NULL == pbuf)
		return 0;

	int32_t tmp = 0;
	memcpy(&tmp, pbuf, sizeof(tmp));

	return ntohl(tmp);
}

int32_t CDEecode::HostToNet(int32_t tmp)
{
	return htonl(tmp);
}

bool CDEecode::PBDecode(std::string& strMsg, std::string& head, google::protobuf::Message* &pMsg)
{
	bool bOk = false;
	DecodeErrorType ErrTpye = DecodeProtobuf(strMsg, pMsg);

	if ((ErrTpye == DECODE_SUCCESS) && (NULL != pMsg))
	{
		head = pMsg->GetTypeName();
		bOk = true;
	}

	return bOk;
}

void CDEecode::PBEncode(std::vector<std::string> &vecMsg, std::vector<std::string> &retVec)
{
	std::vector<std::string> vec;
	for (size_t i = 0; i < vecMsg.size(); ++i)
	{
		vec.push_back(vecMsg[i]);
		if (!((i + 1) % 2))//每两条字符串为一个编码单元
		{
			retVec.push_back(EncodeProtobuf(vec));//编码
			vec.clear();
		}
	}
}
