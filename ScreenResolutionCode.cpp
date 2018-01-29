#include<Windows.h>
#include "ScreenResolutionGlobalShare.h"
#include "resource.h"

extern HWND ghwnd;

void GetScreenResolution(HWND hwnd,struct ResolutionDetails *rod )
{
	MONITORINFO mi = { sizeof(MONITORINFO) };
	BOOL IsMonitorInfo;
	HMONITOR hMonitor;
	TCHAR str[256];

	hMonitor = MonitorFromWindow(hwnd, MONITORINFOF_PRIMARY);
	IsMonitorInfo = GetMonitorInfo(hMonitor, &mi);

	rod->x = mi.rcWork.left;
	rod->y = mi.rcWork.right;
	rod->width = mi.rcWork.right - mi.rcMonitor.left;
	rod->height = mi.rcWork.bottom - mi.rcMonitor.top;

	wsprintf(str,TEXT("%d"),rod->x);
	MessageBox(ghwnd,str,TEXT("x"),MB_OK);
	memset((void**)&str,0,sizeof(str));
	wsprintf(str, TEXT("%d"), rod->y);
	MessageBox(ghwnd, str, TEXT("y"), MB_OK);
	memset((void**)&str, 0, sizeof(str));
	wsprintf(str, TEXT("%d"), rod->width);
	MessageBox(ghwnd, str, TEXT("width"), MB_OK);
	memset((void**)&str, 0, sizeof(str));
	wsprintf(str, TEXT("%d"), rod->height);
	MessageBox(ghwnd, str, TEXT("height"), MB_OK);
}
