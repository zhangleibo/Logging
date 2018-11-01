// LoggingServer.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "Work.h"

int main(int argc, char* argv[])
{
	if (argc >= 2)
	{
		CWork work;
		if (work.Init(argv[1]))
		{
			work.Run();
		}
	}
	else
	{
		MessageBoxA(nullptr, "Server Ip is null", "Error", 0);
	}

	return 0;
}
