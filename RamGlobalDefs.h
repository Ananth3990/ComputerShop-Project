#pragma once
#include <Windows.h>
TCHAR *Ram[6] = { TEXT("Select Company"),TEXT("Corsair"),TEXT("G.Skill"),TEXT("OCZ"),TEXT("Muskin"),0 };

TCHAR *RamSize[4] = { TEXT("4GB"),TEXT("8GB"),TEXT("16GB"),0 };
TCHAR *CorsairPrice[4] = { TEXT("1000"),TEXT("2300"),TEXT("3600"),0};
TCHAR *GSkillPrice[4] = { TEXT("2500"),TEXT("4500"),TEXT("6700"),0 };
TCHAR *OCZPrice[4] = { TEXT("1080"),TEXT("3450"),TEXT("5000"),0 };
TCHAR *MuskinPrice[4] = { TEXT("2300"),TEXT("4500"),TEXT("6300"),0 };

struct RamInfo *ri;

BOOL all_ok_for_ram = FALSE;