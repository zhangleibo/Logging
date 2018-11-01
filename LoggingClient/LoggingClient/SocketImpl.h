#ifndef SOCKET_IMPL_INCLUDE_H
#define SOCKET_IMPL_INCLUDE_H

#pragma comment(lib, "ws2_32.lib")
#include <winsock.h>
#include "SocketBase.h"

class CSocketImpl : public CSocketBase
{
protected:
	//��������
	virtual bool RecvData(char* sMsg, int len);

	//��������
	virtual bool sendData(string s);

	//��Socket
	virtual bool open(const char* ip, const int iPort, int iTimeOut);

	//�ر�Socket
	virtual bool close();

public:
	CSocketImpl(void);
	~CSocketImpl(void);

	SOCKET GetSockfd()
	{
		return m_iLocalSocket;
	}

private:
	//����socket
	bool CreatSocket();

	//���ӷ�����
	bool ConnectToServer(const char* ip, const int iPort, int iTimtOut);

	SOCKET m_iLocalSocket;//���׽��֡�
};
#endif //SOCKET_IMPL_INCLUDE_H