#include<Windows.h>
#include "resource.h"
#include<stdio.h>

void ShowinWindow(HDC hdc, PAINTSTRUCT ps, struct Combined *combi, struct ResolutionDetails *rod)
{
	extern void ValidateTimeandDate(struct DateandTime *dt);
	extern double GetTotalAmount(struct Combined *res);
	void DrawLine(HDC hdc, PAINTSTRUCT ps, struct Combined *res, struct ResolutionDetails *rod);

	TCHAR str[10000];
	struct DateandTime *dt = NULL;

	FillRect(hdc, &ps.rcPaint, (HBRUSH)GetStockObject(GRAY_BRUSH));

	SetBkColor(hdc, RGB(128, 128, 128));
	SetTextColor(hdc, RGB(0, 255, 255));

	wsprintf(str, TEXT("%20s"), TEXT("\r\t\r\t\r\t\r\t\r\t\r\t\r\t----MyComputer Shoppe Bill Receipt------\r\n"));
	DrawText(hdc, str, -1, &ps.rcPaint, DT_TOP | DT_CENTER | DT_SINGLELINE);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%20s"), TEXT("Thank you for shopping at My Computer Shoppe"));
	DrawText(hdc, str, -1, &ps.rcPaint, DT_BOTTOM | DT_CENTER | DT_SINGLELINE);
	memset((void**)&str, 0, sizeof(str));

	dt = (struct DateandTime *)malloc(sizeof(struct DateandTime));
	ValidateTimeandDate(dt);

	wsprintf(str, TEXT("\r\t\r\t\r\t\r\t\r\t\r\t\r\tDate : %2s/%2s/%4s\r\t"), dt->day, dt->month, dt->year);
	TextOut(hdc, ((ps.rcPaint.right-ps.rcPaint.left) / 4) + 140, ps.rcPaint.top + 40, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("\r\tTime : %2s:%2s:%2s\r\n"), dt->hour, dt->min, dt->sec);
	TextOut(hdc, ((ps.rcPaint.right - ps.rcPaint.left) / 4) + 440, ps.rcPaint.top + 40, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//-----------------------------------------------------------------------------
	wsprintf(str, TEXT("%25s\r\t"), TEXT("Category"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 100, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Company"));
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 100, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Product"));
	TextOut(hdc, ps.rcPaint.left  + 410, ps.rcPaint.top + 100, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Other Information"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 100, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), TEXT("Price"));
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 100, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Processor"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 130, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->pi.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 130, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->pi.CPU);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 130, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->pi.Generation);
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 130, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->pi.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 130, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Ram"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 170, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ri.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 170, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ri.Size);
	TextOut(hdc,ps.rcPaint.left + 410, ps.rcPaint.top + 170, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 170, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->ri.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 170, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Motherboard"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 210, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->mbi.Company);
	TextOut(hdc,ps.rcPaint.left + 230, ps.rcPaint.top + 210, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->mbi.Product);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 210, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 210, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->mbi.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 210, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Graphic Card"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 250, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->gci.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 250, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->gci.Product);
	TextOut(hdc, ps.rcPaint.left + 410,ps.rcPaint.top + 250, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 250, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->gci.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 250, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("HardDisk"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 290, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->hdi.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 290, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->hdi.Size);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 290, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 290, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->hdi.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 290, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("CD and DVD"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 330, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cdi.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 330, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cdi.Product);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 330, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 330, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->cdi.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 330, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("SMPS"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 370, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->smpi.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 370, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->smpi.Voltage);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 370, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 370, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->smpi.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 370, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Monitor"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 410, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moni.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 410, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moni.Product);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 410, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 410, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->moni.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 410, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Keyboard"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 450, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ki.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 450, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ki.Product);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 450, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 450, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->ki.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 450, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Mouse"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 490, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moui.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 490, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moui.Product);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 490, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 490, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->moui.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 490, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));
	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Cabinet"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 530, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cabi.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 530, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cabi.Product);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 530, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 530, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->cabi.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 530, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("SSD"));
	TextOut(hdc, ps.rcPaint.left + 50, ps.rcPaint.top + 570, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ssi.Company);
	TextOut(hdc, ps.rcPaint.left + 230, ps.rcPaint.top + 570, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ssi.Product);
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 570, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	TextOut(hdc, ps.rcPaint.left + 690, ps.rcPaint.top + 570, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->ssi.Price);
	TextOut(hdc, ps.rcPaint.left + 1050, ps.rcPaint.top + 570, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//---------------------------------------------------------------------

	swprintf_s(str, TEXT("%150s = Rs %lf"), TEXT("Total Price "), GetTotalAmount(combi));
	TextOut(hdc, ps.rcPaint.left + 410, ps.rcPaint.top + 610, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Press P to print receipt"));
	TextOut(hdc, ps.rcPaint.left + 450, ps.rcPaint.top + 640, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Press Esc to exit"));
	TextOut(hdc, ps.rcPaint.left + 740, ps.rcPaint.top + 640, str, wcslen(str));
	memset((void**)&str, 0, sizeof(str));

	//---------------------------------------------------------------------

	DrawLine(hdc, ps, combi, rod);
}

void DrawLine(HDC hdc, PAINTSTRUCT ps, struct Combined *res, struct ResolutionDetails *rod)
{
	HPEN hMyPen;
	LPPOINT lppoint = NULL;

	hMyPen = (HPEN)GetStockObject(WHITE_PEN);

	SelectObject(hdc, hMyPen);

	//--------------------------------------------------------

	MoveToEx(hdc, 100, 80, lppoint);			//1
	LineTo(hdc, 1200, 80);

	MoveToEx(hdc, 100, 125, lppoint);			//2
	LineTo(hdc, 1200, 125);

	MoveToEx(hdc, 100, 160, lppoint);			//3
	LineTo(hdc, 1200, 160);

	MoveToEx(hdc, 100, 195, lppoint);			//3
	LineTo(hdc, 1200, 195);

	MoveToEx(hdc, 100, 240, lppoint);			//4
	LineTo(hdc, 1200, 240);

	MoveToEx(hdc, 100, 275, lppoint);			//5
	LineTo(hdc, 1200, 275);

	MoveToEx(hdc, 100, 275, lppoint);			//6
	LineTo(hdc, 1200, 275);

	MoveToEx(hdc, 100, 320, lppoint);			//7
	LineTo(hdc, 1200, 320);

	MoveToEx(hdc, 100, 355, lppoint);			//8
	LineTo(hdc, 1200, 355);

	MoveToEx(hdc, 100, 395, lppoint);			//9
	LineTo(hdc, 1200, 395);

	MoveToEx(hdc, 100, 435, lppoint);			//10
	LineTo(hdc, 1200, 435);

	MoveToEx(hdc, 100, 475, lppoint);			//11
	LineTo(hdc, 1200, 475);

	MoveToEx(hdc, 100, 515, lppoint);			//11
	LineTo(hdc, 1200, 515);

	MoveToEx(hdc, 100, 555, lppoint);			//12
	LineTo(hdc, 1200, 555);

	MoveToEx(hdc, 100, 595, lppoint);			//13
	LineTo(hdc, 1200, 595);

	MoveToEx(hdc, 100, 630, lppoint);			//14
	LineTo(hdc, 1200, 630);

	//--------------------------------------------------------

	/*
	MoveToEx(hdc, 100, 80, lppoint);			//14
	LineTo(hdc, 100, 595);

	MoveToEx(hdc, 230, 80, lppoint);			//15
	LineTo(hdc, 230, 595);

	MoveToEx(hdc, 410, 80, lppoint);			//16
	LineTo(hdc, 410, 595);

	MoveToEx(hdc, 690, 80, lppoint);			//17
	LineTo(hdc, 690, 595);

	MoveToEx(hdc, 1050, 80, lppoint);			//18
	LineTo(hdc, 1050, 595);

	MoveToEx(hdc, 1200, 80, lppoint);			//19
	LineTo(hdc, 1200, 595);
	*/

	MoveToEx(hdc, 100, 80, lppoint);			//14
	LineTo(hdc, 100, 630);

	MoveToEx(hdc, 230, 80, lppoint);			//15
	LineTo(hdc, 230, 595);

	MoveToEx(hdc, 410, 80, lppoint);			//16
	LineTo(hdc, 410, 595);

	MoveToEx(hdc, 690, 80, lppoint);			//17
	LineTo(hdc, 690, 595);

	MoveToEx(hdc, 1050, 80, lppoint);			//18
	LineTo(hdc, 1050, 595);

	MoveToEx(hdc, 1200, 80, lppoint);			//19
	LineTo(hdc, 1200, 630);

	//--------------------------------------------------------

	DeleteObject(hMyPen);
}
