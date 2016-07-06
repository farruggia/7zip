// Common/CRC.cpp

#include <StdAfx.h>

#include <7zCrc.h>

struct CCRCTableInit { CCRCTableInit() { CrcGenerateTable(); } } g_CRCTableInit;
