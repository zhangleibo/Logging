#include "SocketImpl.h"
#include "CritSec.h"

/**************************************************************************
Author: zlb
Date:2017-1-16
Description:接收数据
**************************************************************************/

bool CSocketImpl::RecvData(char* sMsg, int len)
{
	if ((0 == len) || (nullptr == sMsg))
	{
		return false;
	}

	UINT iTmpLen = len;
	UINT iRecvSize = 0;
	UINT iRet = 0;

	while (iTmpLen > 0)
	{
		iRet = recv(m_iLocalSocket, sMsg + iRecvSize, iTmpLen, 0);

		if (SOCKET_ERROR == iRet)
		{
			return false;
		}

		iRecvSize += iRet;
		iTmpLen -= iRet;
	}

	return true;
}
/**************************************************************************

Author: zlb

Date:2017-1-16

Description:发送数据

**************************************************************************/
bool CSocketImpl::sendData(string s)
{
	if (s.empty())
	{
		return true;
	}

	UINT iTmpLen = (UINT)s.size();
	UINT iSendSize = 0;
	UINT iRet = 0;

	while (iTmpLen > 0)
	{
		iRet = send(m_iLocalSocket, s.c_str() + iSendSize, iTmpLen, 0);//失败情况，网络有问题
		if (SOCKET_ERROR == iRet)
		{
			return false;
		}

		iSendSize += iRet;
		iTmpLen -= iRet;
	}

	return true;
}
/**************************************************************************

Author: zlb

Date:2017-1-16

Description:初始化 打开socket套接字并连接服务器

**************************************************************************/
bool CSocketImpl::open(const char* ip, const int iPort, int iTimeOut)
{
	bool bIsOk = false;

	do 
	{
		if (!CreatSocket())
		{
			break;
		}

		if (!ConnectToServer(ip, iPort, iTimeOut))
		{
			break;
		}

		bIsOk = true;

	} while (0);

	return bIsOk;
}
/**************************************************************************

Author: zlb

Date:2017-1-16

Description:关闭socket套接字

**************************************************************************/
bool CSocketImpl::close()
{
	//shutdown(m_iLocalSocket, 0x01);
	if (m_iLocalSocket && (INVALID_SOCKET != m_iLocalSocket))
	{
		closesocket(m_iLocalSocket);
		m_iLocalSocket = NULL;
	}

	//【From MSDN:There must be a call to WSACleanup for every successful call to WSAStartup made by a task.】
	if (SOCKET_ERROR == WSACleanup())
	{
		return false;
	}

	return true;
}
/**************************************************************************

Author: zlb

Date:2017-1-16

Description:创建socket
注释：
TCP_NODELAY 选项:
默认情况下，发送数据采用Nagle 算法。这样虽然提高了网络吞吐量，但是实时性却降低了，
在一些交互性很强的应用程序来说是不允许的，使用TCP_NODELAY选项可以禁止Nagle 算法。
此时，应用程序向内核递交的每个数据包都会立即发送出去。
需要注意的是，虽然禁止了Nagle 算法，但网络的传输仍然受到TCP确认延迟机制的影响。
**************************************************************************/
bool CSocketImpl::CreatSocket()
{
	if (m_iLocalSocket && (INVALID_SOCKET != m_iLocalSocket))
	{
		closesocket(m_iLocalSocket);//【在重启后如果原来句柄还存在关闭原来的Socket句柄】
		m_iLocalSocket = NULL;
	}

	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);

	bool bIsOk = false;

	do 
	{
		if (0 != WSAStartup(wVersionRequested, &wsaData)) //【检查Socket初始化是否成功】
		{
			break;
		}

		m_iLocalSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (INVALID_SOCKET == m_iLocalSocket)
		{
			break;
		}

		int on = 1;
		//【设置立即发送】见函数注释
		if (SOCKET_ERROR == setsockopt(m_iLocalSocket, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(on)))
		{
			break;
		}

		bIsOk = true;

	} while (0);

	return bIsOk;
}
/**************************************************************************

Author: zlb

Date:2017-1-16

Description:连接服务器

**************************************************************************/
bool CSocketImpl::ConnectToServer(const char* ip, const int iPort, int iTimeOut)
{
	if (NULL == ip)
	{
		return false;
	}

	bool bRet = false;
	int nCount = 3;

	sockaddr_in  szSeraddr;

	//【服务端端的ip地址和端口】
	szSeraddr.sin_addr.S_un.S_addr = inet_addr(ip);
	szSeraddr.sin_family = AF_INET;
	szSeraddr.sin_port = htons(iPort);

	int iMode = 1;
	int m = ioctlsocket(m_iLocalSocket, FIONBIO, (u_long FAR*)&iMode); //设置为非阻塞模式

	printf("连接服务器 ip:%s Port:%d\n", ip, iPort);

	while (nCount)
	{
		//连接Socket
		if (SOCKET_ERROR == connect(m_iLocalSocket, (struct sockaddr *)&szSeraddr, sizeof(sockaddr)))
		{
			struct timeval timeout;
			fd_set w;

			FD_ZERO(&w);
			FD_SET(m_iLocalSocket, &w);
			timeout.tv_sec = iTimeOut; //连接超时时间
			timeout.tv_usec = 0;

			int ret = select(0, 0, &w, 0, &timeout);

			if (ret <= 0)
			{
				printf("连接超时重连...\n");
				nCount--;
				Sleep(3000);
			}
			else
			{
				int error = -1;
				int optLen = sizeof(int);

				getsockopt(m_iLocalSocket, SOL_SOCKET, SO_ERROR, (char*)&error, &optLen);

				if (0 != error)
				{
					printf("连接超时重连...\n");
					nCount--;
					Sleep(3000);
				}
				else
				{
					iMode = 0;
					ioctlsocket(m_iLocalSocket, FIONBIO, (unsigned long*)&iMode); //设置为阻塞模式
					bRet = true;
					break;
				}
			}
		}
	}

	return bRet;
}

CSocketImpl::CSocketImpl(void) : m_iLocalSocket(NULL)
{

}

CSocketImpl::~CSocketImpl(void)
{

}
