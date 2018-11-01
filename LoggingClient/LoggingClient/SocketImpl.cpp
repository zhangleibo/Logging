#include "SocketImpl.h"
#include "CritSec.h"

/**************************************************************************
Author: zlb
Date:2017-1-16
Description:��������
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

Description:��������

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
		iRet = send(m_iLocalSocket, s.c_str() + iSendSize, iTmpLen, 0);//ʧ�����������������
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

Description:��ʼ�� ��socket�׽��ֲ����ӷ�����

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

Description:�ر�socket�׽���

**************************************************************************/
bool CSocketImpl::close()
{
	//shutdown(m_iLocalSocket, 0x01);
	if (m_iLocalSocket && (INVALID_SOCKET != m_iLocalSocket))
	{
		closesocket(m_iLocalSocket);
		m_iLocalSocket = NULL;
	}

	//��From MSDN:There must be a call to WSACleanup for every successful call to WSAStartup made by a task.��
	if (SOCKET_ERROR == WSACleanup())
	{
		return false;
	}

	return true;
}
/**************************************************************************

Author: zlb

Date:2017-1-16

Description:����socket
ע�ͣ�
TCP_NODELAY ѡ��:
Ĭ������£��������ݲ���Nagle �㷨��������Ȼ���������������������ʵʱ��ȴ�����ˣ�
��һЩ�����Ժ�ǿ��Ӧ�ó�����˵�ǲ�����ģ�ʹ��TCP_NODELAYѡ����Խ�ֹNagle �㷨��
��ʱ��Ӧ�ó������ں˵ݽ���ÿ�����ݰ������������ͳ�ȥ��
��Ҫע����ǣ���Ȼ��ֹ��Nagle �㷨��������Ĵ�����Ȼ�ܵ�TCPȷ���ӳٻ��Ƶ�Ӱ�졣
**************************************************************************/
bool CSocketImpl::CreatSocket()
{
	if (m_iLocalSocket && (INVALID_SOCKET != m_iLocalSocket))
	{
		closesocket(m_iLocalSocket);//�������������ԭ����������ڹر�ԭ����Socket�����
		m_iLocalSocket = NULL;
	}

	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);

	bool bIsOk = false;

	do 
	{
		if (0 != WSAStartup(wVersionRequested, &wsaData)) //�����Socket��ʼ���Ƿ�ɹ���
		{
			break;
		}

		m_iLocalSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (INVALID_SOCKET == m_iLocalSocket)
		{
			break;
		}

		int on = 1;
		//�������������͡�������ע��
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

Description:���ӷ�����

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

	//������˶˵�ip��ַ�Ͷ˿ڡ�
	szSeraddr.sin_addr.S_un.S_addr = inet_addr(ip);
	szSeraddr.sin_family = AF_INET;
	szSeraddr.sin_port = htons(iPort);

	int iMode = 1;
	int m = ioctlsocket(m_iLocalSocket, FIONBIO, (u_long FAR*)&iMode); //����Ϊ������ģʽ

	printf("���ӷ����� ip:%s Port:%d\n", ip, iPort);

	while (nCount)
	{
		//����Socket
		if (SOCKET_ERROR == connect(m_iLocalSocket, (struct sockaddr *)&szSeraddr, sizeof(sockaddr)))
		{
			struct timeval timeout;
			fd_set w;

			FD_ZERO(&w);
			FD_SET(m_iLocalSocket, &w);
			timeout.tv_sec = iTimeOut; //���ӳ�ʱʱ��
			timeout.tv_usec = 0;

			int ret = select(0, 0, &w, 0, &timeout);

			if (ret <= 0)
			{
				printf("���ӳ�ʱ����...\n");
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
					printf("���ӳ�ʱ����...\n");
					nCount--;
					Sleep(3000);
				}
				else
				{
					iMode = 0;
					ioctlsocket(m_iLocalSocket, FIONBIO, (unsigned long*)&iMode); //����Ϊ����ģʽ
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
