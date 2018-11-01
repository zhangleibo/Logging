#ifndef SOCKET_BASE_INCLUDE_H
#define SOCKET_BASE_INCLUDE_H

#include <string>
using namespace std;

class CSocketBase
{
public:
	virtual bool RecvData(char* sMsg, int len) = 0; //接收数据
	virtual bool sendData(string s) = 0; //发送数据
	virtual bool open(const char* ip, const int iPort, int iTimtOut) = 0; //打开Socket
	virtual bool close() = 0; //关闭Socket
};

#endif //SOCKET_BASE_INCLUDE_H