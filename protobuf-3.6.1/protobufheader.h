#pragma once
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

#define NOMINMAX
//#define PROTOBUF_USE_DLLS

#ifdef _DEBUG
#pragma comment(lib, "libprotobufd.lib")
#pragma comment(lib, "libprotocd.lib")
#pragma comment(lib, "libprotobuf-lited.lib")
#else
#pragma comment(lib, "libprotobuf.lib")
#pragma comment(lib, "libprotoc.lib")
#pragma comment(lib, "libprotobuf-lite.lib")
#endif // DEBUG