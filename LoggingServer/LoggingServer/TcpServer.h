#pragma once

//////////////////////////////////////////////////////////////////////////
//
// 	单进程 单线程 并发tcp server
//
//////////////////////////////////////////////////////////////////////////

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

//最大可用描述符的个数，一般受操作系统内核的设置影响 1024
#ifndef FD_SETSIZE
#define FD_SETSIZE 1024
#endif


#include <stdio.h>
#include <stdlib.h>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <string>


class CTcpServer 
{
public:
	CTcpServer();
	~CTcpServer();

	bool Init(const char* ip = nullptr, int port = 32001);
	void Run();
	virtual void Handle(SOCKET newsock, std::string &msg);

protected:
	void PreHandle(SOCKET newsock, fd_set *set);
	std::string PreRecv(SOCKET newsock, fd_set *set);
	bool RecvData(SOCKET sock, fd_set *set, char* sMsg, int len);

private:
	SOCKET m_sock;
	fd_set m_socks;
	fd_set m_readsocks;
	SOCKET m_maxsock;
	int m_reuseaddr;
	struct addrinfo m_hints;
	struct addrinfo *m_pres;
};