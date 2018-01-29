#pragma once
#include<Windows.h>
TCHAR *Monitor[5] = { TEXT("Select Company"),TEXT("Sony"),TEXT("Dell"),TEXT("HP"),0 };

TCHAR *SonyMonitor[4] = { TEXT("Sony Bravia"),TEXT("Sony XAV"),TEXT("Sony XLM"),0 };
TCHAR *SonyMonitorprice[4] = { TEXT("34560"),TEXT("56780"),TEXT("99870"),0 };
TCHAR *DellMonitor[4] = { TEXT("Dell MSD14"),TEXT("Dell 12216HV"),TEXT("Dell SE2216H"),0 };
TCHAR *DellMonitorprice[4] = { TEXT("23000"),TEXT("67000"),TEXT("89000"),0 };
TCHAR *HPMonitor[4] = { TEXT("HP Bravia"),TEXT("HP XAV"),TEXT("HP XLM"),0 };
TCHAR *HPMonitorprice[4] = { TEXT("34000"),TEXT("56000"),TEXT("89000"),0 };

struct MonitorInfo *moni;

BOOL all_ok_with_monitor = FALSE;
