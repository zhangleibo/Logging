#ifndef SOCKET_IMPL_INCLUDE_H
#define SOCKET_IMPL_INCLUDE_H

#pragma comment(lib, "ws2_32.lib")
#include <winsock.h>
#include "SocketBase.h"

class CSocketImpl : public CSocketBase
{
protected:
	//接收数据
	virtual bool RecvData(char* sMsg, int len);

	//发送数据
	virtual bool sendData(string s);

	//打开Socket
	virtual bool open(const char* ip, const int iPort, int iTimeOut);

	//关闭Socket
	virtual bool close();

public:
	CSocketImpl(void);
	~CSocketImpl(void);

	SOCKET GetSockfd()
	{
		return m_iLocalSocket;
	}

private:
	//创建socket
	bool CreatSocket();

	//连接服务器
	bool ConnectToServer(const char* ip, const int iPort, int iTimtOut);

	SOCKET m_iLocalSocket;//【套接字】
};
#endif //SOCKET_IMPL_INCLUDE_H