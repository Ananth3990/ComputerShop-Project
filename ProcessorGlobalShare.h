#pragma once
#include<Windows.h>
extern TCHAR *Processor[4];

extern TCHAR *Intel_Processor[4];
extern TCHAR *AMD_Processor[4];

extern TCHAR *AMD_ProcessorFXFamily[4];
extern TCHAR *AMD_ProcessorAthlon64Family[4];
extern TCHAR *AMD_ProcessorRyzen3Family[3];

extern  TCHAR *Intel_Processor_Generation[5];

extern TCHAR *AMD_ProcessorFXPrice[4];
extern TCHAR  *AMD_ProcessorAthlon64Price[4];
extern TCHAR *AMD_ProcessorRyzen3Price[3];

extern TCHAR *i3Price[5];
extern TCHAR *i5Price[5];
extern TCHAR *i7Price[5];

extern struct ProcessorInfo *pi;

extern BOOL all_ok_for_processor;
//--------------
