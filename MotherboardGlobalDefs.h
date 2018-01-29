#pragma once
#include<Windows.h>

TCHAR *MotherBoards[6] = { TEXT("Select Company"),TEXT("Asus"),TEXT("Gigabyte"),TEXT("Biostar"),TEXT("AsRock"),0 };

TCHAR *AsusMotherboards[4] = { TEXT("Prime H270-PLUS"),TEXT("Asus Intel H61M-CS"),TEXT("ASUS H81M-CS"),0 };
TCHAR *GigabyteMotherboards[4] = { TEXT("Gigabyte GA-H110M-S2"),TEXT("Gigabyte GA-H61M-S"),TEXT("Gigabyte GA-B250-DS3H"),0 };
TCHAR *BioStarMotherboards[4] = { TEXT("Biostar H81MHV3"),TEXT("Biostar B150GT5"),TEXT("Biostar A68N-2100"),0 };
TCHAR *AsRockMotherboards[4] = { TEXT("Asrock B250M Pro4"),TEXT("Asrock AB350"),TEXT("Asrock AB345"),0 };

TCHAR *AsusMotherboardsPrice[4] = { TEXT("8270"),TEXT("9820"),TEXT("10000"),0 };
TCHAR *GigabyteMotherboardsPrice[4] = { TEXT("6378"),TEXT("12000"),TEXT("15000"),0 };
TCHAR *BioStarMotherboardsPrice[4] = { TEXT("4345"),TEXT("6457"),TEXT("8900"),0 };
TCHAR *AsRockMotherboardsPrice[4] = { TEXT("7000"),TEXT("8934"),TEXT("12000"),0 };

struct MotherBoardInfo *mi;

BOOL all_ok_for_motherboard = FALSE;
