#pragma once
#include<Windows.h>
TCHAR *Cabinet[5] = { TEXT("Select Company"),TEXT("Circle"),TEXT("Corsair"),TEXT("Antec"),0 };

TCHAR *CircleCabinet[4] = { TEXT("Circle Pheonix Cabinet"),TEXT("Circle CC 819"),TEXT("Circle CC 890"),0 };
TCHAR *CircleCabinetPrice[4] = { TEXT("4567"),TEXT("5645"),TEXT("8900"),0 };
TCHAR *AntecCabinet[4] = { TEXT("Antec Cabinet gx200"),TEXT("Antec Cabinet x1"),TEXT("Antec Cabinet 900"),0 };
TCHAR *AntecCabinetPrice[4] = { TEXT("4560"),TEXT("6700"),TEXT("9000"),0 };
TCHAR *CorsairCabinet[4] = { TEXT("Corsair Carbide 2100"),TEXT("Corsair Carbide 123"),TEXT("Corsair Carbide 900"),0 };
TCHAR *CorsairCabinetPrice[4] = { TEXT("3450"),TEXT("5675"),TEXT("7500"),0 };

struct  CabinetInfo *cbi;

BOOL all_ok_with_cabinet= FALSE;
