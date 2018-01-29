#pragma once
#include<Windows.h>
TCHAR *CDAndDVD[5] = { TEXT("Select Company"),TEXT("AMW"),TEXT("Astrad"),TEXT("Acrox"),0 };

TCHAR *AMWCDAndDVD[5] = { TEXT("amw s99 dvd player"),TEXT("AmphionAMW V99 Player"),TEXT("AMW M280 Portable"),TEXT("AMW DVD Player V99"),0 };
TCHAR *AstradCDAndDVD[5] = { TEXT("Astrad s99 dvd player"),TEXT("AmphionAstrad V99 Player"),TEXT("AstradM280 Portable"),TEXT("Astrad DVD Player V99"),0 };
TCHAR *AcroxCDAndDVD[5] = { TEXT("Acrox s99 dvd player"),TEXT("AmphionAcrox V99 Player"),TEXT("AcroxM280 Portable"),TEXT("Acrox DVD Player V99"),0 };
TCHAR *AMWCDAndDVDPrice[5] = { TEXT("2375"),TEXT("4500"),TEXT("6000"),TEXT("9000"),0 };
TCHAR *AstradCDAndDVDPrice[5] = { TEXT("3400"),TEXT("4500"), TEXT("6000"),TEXT("8000"),0 };
TCHAR *AcroxCDAndDVDPrice[5] = { TEXT("1000") ,TEXT("2000"),TEXT("3000"),TEXT("4000"),0 };

struct CDandDVDInfo *cd;

BOOL all_ok_with_cdanddvd = FALSE;

