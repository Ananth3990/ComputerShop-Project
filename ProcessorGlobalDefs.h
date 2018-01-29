#pragma once
#include<Windows.h>
//--------------
TCHAR *Processor[4] = { TEXT("Select Company"),TEXT("Intel"),TEXT("AMD"),0 };

TCHAR *Intel_Processor[4] = { TEXT("Core-i3"),TEXT("Core-i5"),TEXT("Core-i7"),0 };
TCHAR *AMD_Processor[4] = { TEXT("AMD FX"),TEXT("Athlon 64"),TEXT("AMD Ryzen 3"),0 };

TCHAR *AMD_ProcessorFXFamily[4] = { TEXT("Athlon64"),TEXT("Bulldozer"),TEXT("PileDriverCore"),0 };
TCHAR *AMD_ProcessorAthlon64Family[4] = { TEXT("SledgeHammer"),TEXT("ClawHammer"),TEXT("SanDiego"),0 };
TCHAR *AMD_ProcessorRyzen3Family[3] = { TEXT("AMD Ryzen 3 1200"),TEXT("AMD Ryzen 3 1300X"),0 };

TCHAR *Intel_Processor_Generation[5] = { TEXT("Haswell"),TEXT("Broadwell"),TEXT("KabyLake"),TEXT("Skylake"),0 };

TCHAR *AMD_ProcessorFXPrice[4] = { TEXT("3452"),TEXT("4560"),TEXT("6540"),0 };
TCHAR  *AMD_ProcessorAthlon64Price[4] = { TEXT("2346"),TEXT("4512"),TEXT("7890"),0 };
TCHAR *AMD_ProcessorRyzen3Price[3] = { TEXT("2100"),TEXT("5400"),0 };

TCHAR *i3Price[5] = { TEXT("1534"),TEXT("2360"),TEXT("4567"),TEXT("6590"),0 };
TCHAR *i5Price[5] = { TEXT("2360"),TEXT("3400"),TEXT("5600"),TEXT("7800"),0};
TCHAR *i7Price[5] = { TEXT("4500"),TEXT("6700"),TEXT("7600"),TEXT("9000"),0};

struct ProcessorInfo *pi;

BOOL all_ok_for_processor = FALSE;
//--------------
