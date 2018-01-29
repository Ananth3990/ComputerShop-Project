#pragma once
#include<Windows.h>
TCHAR *GraphicCards[5] = { TEXT("Select Company"), TEXT("AMD"),TEXT("NVIDIA"),TEXT("Zotac"),0 };

TCHAR *GraphicCardsNvidia[5] = { TEXT("GeForce GTX 1050"), TEXT("GeForce GTX 1060"),TEXT("GeForce GTX 1080"),TEXT("GeForce GTX 1080 Ti"),0 };
TCHAR *GraphicCardsAMD[4] = { TEXT("AMD Radeon R7 240"),TEXT("AMD Radeon R9 280X"),TEXT("AMD Radeon Pro Duo"),0 };
TCHAR *GraphicCardsZotac[4] = { TEXT("Zotac NVIDIA GT 730"),TEXT("Zotac NVIDIA GT 1050 TI"),TEXT("Zotac NVIDIA GT 1050"),0 };

TCHAR *GraphicCardsNvidiaPrice[5] = { TEXT("8270"),TEXT("9470"),TEXT("100000"),TEXT("10850"),0 };
TCHAR *GraphicCardsAMDPrice[4] = { TEXT("5654"),TEXT("7569"),TEXT("9870"),0 };
TCHAR *GraphicCardsZotacPrice[4] = { TEXT("5689"),TEXT("7523"),TEXT("9200"),0 };

struct GraphicCardInfo *gi;

BOOL all_ok_with_graphiccard=FALSE;
