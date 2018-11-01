#include "TcpServer.h"

#pragma comment(lib, "ws2_32.lib")

#define BACKLOG 128      /* Passed to listen() */
#define MAXPACKETSIZE 4096
typedef unsigned long ulong;


CTcpServer::CTcpServer()
{
	 m_reuseaddr = 1; /* True */

}

CTcpServer::~CTcpServer()
{
	/* Clean up */
	closesocket(m_sock);
	WSACleanup();
}

bool CTcpServer::Init(const char* ip /*= nullptr*/, int port /*= 32001*/)
{
	bool bOk = false;

	// if set ip used ip else used 127.0.0.1 
	bool bSetIp = nullptr != ip;

	do 
	{
		WORD wVersion = MAKEWORD(2, 2);
		WSADATA wsaData;
		int iResult;

		/* Initialise Winsock */
		if (iResult = (WSAStartup(wVersion, &wsaData)) != 0) {
			printf("WSAStartup failed: %d\n", iResult);
			break;
		}

		/* Get the address info */
		ZeroMemory(&m_hints, sizeof(m_hints));
		m_hints.ai_family = AF_INET;
		m_hints.ai_socktype = SOCK_STREAM;
		if (getaddrinfo(NULL, std::to_string(port).c_str(), &m_hints, &m_pres) != 0) {
			perror("getaddrinfo");
			break;
		}

		/* Create the socket */
		m_sock = socket(m_pres->ai_family, m_pres->ai_socktype, m_pres->ai_protocol);
		if (m_sock == -1) {
			perror("socket");
			break;
		}

		/* Enable the socket to reuse the address */
		if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&m_reuseaddr,
			sizeof(int)) == SOCKET_ERROR) {
			perror("setsockopt");
			break;
		}

		struct sockaddr_in addr_serv;
		if (bSetIp)
		{
			/* set local ip */
			memset(&addr_serv, 0, sizeof(addr_serv));
			addr_serv.sin_family = m_hints.ai_family;
			addr_serv.sin_port = htons(port);
			addr_serv.sin_addr.s_addr = inet_addr(ip);

			/* Bind to the address */
			if (bind(m_sock, (struct sockaddr *)&addr_serv, sizeof(struct sockaddr_in)) < 0) {
				perror("bind");
				break;
			}
		}
		else
		{
			/* Bind to the address 127.0.0.1*/
			if (bind(m_sock, m_pres->ai_addr, (int)m_pres->ai_addrlen) == SOCKET_ERROR) {
				perror("bind");
				break;
			}
		}

		/* Listen */
		if (listen(m_sock, BACKLOG) == SOCKET_ERROR) {
			perror("listen");
			break;
		}

		/* Set up the fd_set */
		FD_ZERO(&m_socks);
		FD_SET(m_sock, &m_socks);
		m_maxsock = m_sock;

		//////////////////////////////////////////////////////////////////////////
		//server ip info
		char *ipVal = bSetIp ? inet_ntoa(addr_serv.sin_addr) : "127.0.0.1";

		printf("*******************************************************\n");
		printf("SERVER IP : %s \nPORT: %d \nFD_SETSIZE : %d \nServer Ready OK...\n", ipVal, port, FD_SETSIZE);
		printf("*******************************************************\n");
		printf("Waiting for connection...");

		bOk = true;
	} while (0);

	if (!bOk) {
		WSACleanup();
	}

	return bOk;
}

void CTcpServer::Run()
{
	/* Main loop */
	while (1) {
		SOCKET s;
		m_readsocks = m_socks;
		if (select(int(m_maxsock + 1), &m_readsocks, NULL, NULL, NULL) == SOCKET_ERROR) {
			perror("select");
			break;
		}
		for (s = 0; s <= m_maxsock; s++) {
			if (FD_ISSET(s, &m_readsocks)) {
				//printf("Socket %lld was ready\n", s);
				if (s == m_sock) {
					/* New connection */
					SOCKET newsock;
					struct sockaddr_in their_addr;
					size_t size = sizeof(struct sockaddr_in);

					newsock = accept(m_sock, (struct sockaddr*)&their_addr, (int*)&size);
					if (newsock == INVALID_SOCKET) {
						perror("accept");
					}
					else {
						printf("Got a connection from %s on port %d\n",
							inet_ntoa(their_addr.sin_addr), htons(their_addr.sin_port));
						FD_SET(newsock, &m_socks);
						if (newsock > m_maxsock) {
							m_maxsock = newsock;
						}
					}
				}
				else {
					/* Handle read or disconnection */
					PreHandle(s, &m_socks);
				}
			}
		}
	}

	WSACleanup();
}

void CTcpServer::Handle(SOCKET newsock, std::string &msg)
{
	static int icnt = 0;
	printf("recv msg %d \n", icnt++);
	send(newsock, msg.c_str(), msg.size(), 0);
}

void CTcpServer::PreHandle(SOCKET newsock, fd_set *set)
{
	/* send(), recv(), closesocket() */
	/* Call FD_CLR(newsock, set) on disconnection */

	std::string strData;

	do
	{
		ulong nNetBodyLen = 0;
		ulong nHostBodyLen = 0;

		//接收头信息
		if (!RecvData(newsock, set, (char *)&nNetBodyLen, sizeof(ulong))) {
			break;
		}

		nHostBodyLen = ntohl(nNetBodyLen);

		ulong nTotalLen = nHostBodyLen + sizeof(ulong);
		std::string msgInfo(nTotalLen, '\0');
		char* pMsg = &msgInfo.at(0);
		char* pMsgBody = pMsg + sizeof(ulong);

		memcpy(pMsg, &nNetBodyLen, sizeof(nNetBodyLen));
		if (!RecvData(newsock, set, pMsgBody, nHostBodyLen)) {
			break;
		}

		strData = msgInfo;

		Handle(newsock, strData);
	} while (0);
}

std::string CTcpServer::PreRecv(SOCKET newsock, fd_set *set)
{
	return "";
}

bool CTcpServer::RecvData(SOCKET sock, fd_set *set, char* sMsg, int len)
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
		iRet = recv(sock, sMsg + iRecvSize, iTmpLen, 0);
		if (SOCKET_ERROR == iRet)
		{
			closesocket(sock);
			FD_CLR(sock, set);
			return false;
		}

		iRecvSize += iRet;
		iTmpLen -= iRet;
	}

	return true;
}
