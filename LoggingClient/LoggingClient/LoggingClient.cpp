// LoggingClient.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Work.h"

int main(int argc, char* argv[])
{
	if (argc >= 2)
	{
		CWork::GetInstance()->work(argv[1], 32001);
	}
	else
	{
		MessageBoxA(nullptr, "Command Paramer ip is null", "Error", 0);
	}

    return 0;
}

