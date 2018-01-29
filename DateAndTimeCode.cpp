#include<Windows.h>
#include<strsafe.h>
#include "resource.h"

void ValidateTimeandDate(struct DateandTime *dt)
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	if ((st.wHour / 10) == 0)
	{
		wsprintf(dt->hour, TEXT("0%d"), st.wHour);
	}
	else
	{
		wsprintf(dt->hour, TEXT("%d"), st.wHour);
	}

	if ((st.wMinute / 10) == 0)
	{
		wsprintf(dt->min, TEXT("0%d"), st.wMinute);
	}
	else
	{
		wsprintf(dt->min, TEXT("%d"), st.wMinute);
	}

	if ((st.wSecond / 10) == 0)
	{
		wsprintf(dt->sec, TEXT("0%d"), st.wSecond);
	}
	else
	{
		wsprintf(dt->sec, TEXT("%d"), st.wSecond);
	}

	if ((st.wDay / 10) == 0)
	{
		wsprintf(dt->day, TEXT("0%d"), st.wDay);
	}
	else
	{
		wsprintf(dt->day, TEXT("%d"), st.wDay);
	}

	if ((st.wMonth / 10) == 0)
	{
		swprintf_s(dt->month, TEXT("0%d"), st.wMonth);
	}
	else
	{
		swprintf_s(dt->month, TEXT("%d"), st.wMonth);
	}

	swprintf_s(dt->year, TEXT("%d"), st.wYear);
}
