#pragma once
#include <Windows.h>

TCHAR *SMPS[5] = { TEXT("Select Company"),TEXT("Circle"),TEXT("Artis"),TEXT("Intex"),0 };
TCHAR *Products[4] = { TEXT("400W"),TEXT("450W"),TEXT("550W"),0 };

TCHAR *CircleSMPSPrice[4] = { TEXT("3400"),TEXT("4500"),TEXT("5500"),0 };
TCHAR *ArtisSMPSPrice[4] = { TEXT("4500"),TEXT("6740"),TEXT("7800"),0 };
TCHAR *IntexSMPSPrice[4] = { TEXT("5623"),TEXT("7500"),TEXT("9000"),0 };

struct SMPSInfo *smpi;

BOOL all_ok_for_smps= FALSE;