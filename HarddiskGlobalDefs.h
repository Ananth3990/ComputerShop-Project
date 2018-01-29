#pragma once
#include<Windows.h>

TCHAR *HardDisk[4] = { TEXT("Select Company"),TEXT("Western Digital"),TEXT("Seagate"),0 };
TCHAR *HardDiskSize[4] = { TEXT("500GB"),TEXT("1TB"),TEXT("2TB"),0 };
TCHAR* WesternDigitalPrice[4] = { TEXT("3459"),TEXT("5467"),TEXT("8528"),0 };
TCHAR* SeagatePrice[4] = { TEXT("3500"),TEXT("5600"),TEXT("7000"),0 };

struct HardDiskInfo *hi;

BOOL all_ok_for_harddisk=FALSE;
