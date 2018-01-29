#include<windows.h>
#include "resource.h"
#include "AskFilePath.h"
#include "ProcessorGlobalDefs.h"
#include "RamGlobalDefs.h"
#include "MotherboardGlobalDefs.h"
#include "HarddiskGlobalDefs.h"
#include "GraphicCardGlobalDefs.h"
#include "CDandDVDGlobalDefs.h"
#include "MonitorGlobalDefs.h"
#include"CabinetGlobalDefs.h"
#include "KeyboardGlobalDefs.h"
#include "MouseGlobalDefs.h"
#include "SMPSGlobalDefs.h"
#include "InitializationGlobalDefs.h"
#include "ValidateGlobalDefs.h"
#include "ScreenResolutionGlobalDefs.h"
#include "DeleteCodeGlobalShare.h"
#include "SSDGlobalDefs.h"

#pragma comment(lib,"User32.lib")
#pragma comment (lib,"gdi32.lib")
#pragma comment (lib,"Shlwapi.lib")


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	void uninitialize(void);
	LRESULT CALLBACK AcCallBack(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	void DisplayError(LPTSTR lpszFunction);

	MSG msg;

	HWND hwnd;

	ghInstance = hInstance;

	ac.cbSize = sizeof(WNDCLASSEX);
	ac.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	ac.cbClsExtra = 0;
	ac.cbWndExtra = 0;
	ac.hInstance = hInstance;
	ac.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	ac.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(APPLICATION_ICON));
	ac.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(APPLICATION_CURSOR));
	ac.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(APPLICATION_ICON));
	ac.lpfnWndProc = AcCallBack;
	ac.lpszClassName = szClassName;
	ac.lpszMenuName = NULL;


	RegisterClassEx(&ac);

	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szClassName,
		TEXT("Shree Ganesha"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (hwnd == NULL)
	{
		MessageBox(NULL, TEXT("Parent Window creation failed"), TEXT("Error"), MB_OK);
		exit(0);
	}

	ghwnd = hwnd;

	ShowWindow(hwnd, SW_MAXIMIZE);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	uninitialize();
	return ((int)msg.wParam);
}

void uninitialize(void)
{
	dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
	SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
	SetWindowPlacement(ghwnd, &wpPrev);
	SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
	ShowCursor(TRUE);
	DestroyWindow(ghwnd);
}

LRESULT CALLBACK AcCallBack(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	void uninitialize(void);
	BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	void GetScreenResolution(HWND hwnd, struct ResolutionDetails *rod);
	void ShowinWindow(HDC hdc, PAINTSTRUCT ps, struct Combined *combi, struct ResolutionDetails *rod);
	BOOL CALLBACK AskFilePathDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

	static HBITMAP bmpSource = NULL;
	static BITMAP bmp;
	static HDC hdcSource = NULL;
	PAINTSTRUCT ps;
	HDC hdc;
	//RECT rc;

	TCHAR Ac_Show_String[255] = TEXT("Press Space bar to Proceed");

	HINSTANCE hInst;
	HGDIOBJ temp;
	
	switch (iMsg)
	{
	case WM_CREATE:
		pi = (struct ProcessorInfo*)malloc(sizeof(struct ProcessorInfo));
		number_of_items++;
		ri = (struct RamInfo*)malloc(sizeof(struct RamInfo));
		number_of_items++;
		mi = (struct MotherBoardInfo*)malloc(sizeof(struct MotherBoardInfo));
		number_of_items++;
		hi = (struct HardDiskInfo*)malloc(sizeof(struct HardDiskInfo));
		number_of_items++;
		gi = (struct GraphicCardInfo*)malloc(sizeof(struct GraphicCardInfo));
		number_of_items++;
		cd = (struct CDandDVDInfo*)malloc(sizeof(struct CDandDVDInfo));
		number_of_items++;
		moni = (struct MonitorInfo*)malloc(sizeof(struct MonitorInfo));
		number_of_items++;
		cbi = (struct CabinetInfo*)malloc(sizeof(struct CabinetInfo));
		number_of_items++;
		moi = (struct MouseInfo*)malloc(sizeof(struct MouseInfo));
		number_of_items++;
		smpi = (struct SMPSInfo*)malloc(sizeof(struct SMPSInfo));
		number_of_items++;
		ki = (struct KeyboardInfo*)malloc(sizeof(struct KeyboardInfo));
		number_of_items++;
		ssi=(struct SSDInfo*)malloc(sizeof(struct SSDInfo));
		number_of_items++;
		combi = (struct Combined*)malloc(sizeof(struct Combined));
		fn = (struct AcFileName*)malloc(sizeof(struct AcFileName));


		bmpSource = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(MINIONS_IMAGE_ID), IMAGE_BITMAP, 0, 0,LR_CREATEDIBSECTION);
		GetObject(bmpSource, sizeof(bmp), &bmp);
		hdcSource = CreateCompatibleDC(GetDC(0));
		SelectObject(hdcSource, bmpSource);
		break;
		
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		if (time_to_show_in_window == FALSE)
		{
			StretchBlt(hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right-ps.rcPaint.left, ps.rcPaint.bottom-ps.rcPaint.top, hdcSource, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
			
			temp=SelectObject(hdc, CreateFont(60, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Palatino LinoType")));
			SetTextColor(hdc, RGB(0, 0, 0));
			SetBkColor(hdc, TRANSPARENT);
			SetBkMode(hdc, TRANSPARENT);
			DrawText(hdc, Ac_Show_String, -1, &ps.rcPaint,DT_BOTTOM|DT_CENTER | DT_SINGLELINE);
			SelectObject(hdc,temp);

			temp=SelectObject(hdc, CreateFont(50, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Palatino LinoType")));
			SetTextColor(hdc, RGB(0, 0, 0));
			SetBkColor(hdc, TRANSPARENT);
			SetBkMode(hdc, TRANSPARENT);
			DrawText(hdc, TEXT("ASTROMEDICOMP"), -1, &ps.rcPaint, DT_LEFT| DT_SINGLELINE);
			SelectObject(hdc, temp);

			temp=SelectObject(hdc, CreateFont(30, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Palatino LinoType")));
			SetTextColor(hdc, RGB(0, 0, 0));
			SetBkColor(hdc, TRANSPARENT);
			SetBkMode(hdc, TRANSPARENT);
			DrawText(hdc, TEXT("SDK-2017"), -1, &ps.rcPaint, DT_RIGHT | DT_SINGLELINE);
			SelectObject(hdc, temp);

			temp=SelectObject(hdc, CreateFont(30, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Palatino LinoType")));
			SetTextColor(hdc, RGB(0,0,0));
			SetBkColor(hdc, TRANSPARENT);
			SetBkMode(hdc, TRANSPARENT);
			TextOut(hdc, ps.rcPaint.left + ((ps.rcPaint.right - ps.rcPaint.left) - 265), ps.rcPaint.left + 30, TEXT("Ananth Chandrasekharan"), 31);
			SelectObject(hdc, temp);
		}
		else
		{
			DeleteObject(hdcSource);
			ShowinWindow(hdc,ps,combi,rod);
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_CLOSE:
		uninitialize();
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;

		case VK_SPACE:
			SpaceKeyPessed++;
			if (SpaceKeyPessed<=1)
			{
				hInst = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
				//Further task will be a call to dialog box
				DialogBox(hInst, TEXT("DataEntry"), ghwnd, MyDlgProc);
			}
			break;

		case 0x50:
			if (ContinueKeyIsPressed==TRUE)
			{
				hInst = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
				DialogBox((HINSTANCE)GetWindowLong(ghwnd, GWL_HINSTANCE), TEXT("ASKFILEPATH"), ghwnd, AskFilePathDlgProc);
			}
			break;

		default:
			break;
		}
		break;

	case WM_DESTROY:
		free(pi);
		pi = NULL;
		free(ri);
		ri = NULL;
		free(mi);
		mi = NULL;
		free(hi);
		hi = NULL;
		free(gi);
		gi = NULL;
		free(cd);
		cd = NULL;
		free(moni);
		moni = NULL;
		free(cbi);
		cbi = NULL;
		free(ki);
		ki = NULL;
		free(moi);
		moi = NULL;
		free(smpi);
		smpi = NULL;
		free(combi);
		combi = NULL;
		free(fn);
		fn = NULL;
		free(rod);
		rod = NULL;
		free(ssi);
		ssi = NULL;
		PostQuitMessage(0);
		break;

	default:
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	BOOL  ProcessorDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL RamDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL MotherboardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL HardDiskDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL GraphicCardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL CDAndDVDDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL MonitorDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL CabinetDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL KeyboardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL MouseDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL SMPSDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	void Validate(struct Combined *res);
	void ValidateOnContinue(struct Combined *res, BOOL *dont_go_forward);
	void FindCurrentlySelectedItem(struct Combined *res, int *delete_index);
	void ResetLastSelectedRow(HWND hDlg, int index);
	BOOL CALLBACK AskForCategoryDeleteOptions(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	BOOL SSDDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);

	static HBITMAP bmpSourceDialog = NULL;
	static BITMAP bmpDialog;
	
	static HDC hdcSourceDialog = NULL;

	PAINTSTRUCT psDialog;

	HDC hdcDialog;

	RECT rcDialog;

	BOOL do_not_continue = FALSE;

	int currentIndex=0;
	int retval;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		ShowWindow(hDlg, SW_MAXIMIZE);
		InitializeSSD(hDlg);
		InitializeHardDisk(hDlg);
		InitializeMotherboard(hDlg);
		InitializeRam(hDlg);
		InitializeGraphicCard(hDlg);
		InitializeCDandDVD(hDlg);
		InitializeMonitor(hDlg);
		InitializeCabinet(hDlg);
		InitializeKeyboard(hDlg);
		InitializeMouse(hDlg);
		InitializeSMPS(hDlg);
		InitializeProcessor(hDlg);

		bmpSourceDialog = (HBITMAP)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(MINIONS_IMAGE1_ID), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		GetObject(bmpSourceDialog, sizeof(bmpDialog), &bmpDialog);
		hdcSourceDialog = CreateCompatibleDC(GetDC(0));
		SelectObject(hdcSourceDialog, bmpSourceDialog);
		return TRUE;
		break;

	case WM_CTLCOLORSTATIC:
		//SelectObject((HDC)wParam, CreateFont(20, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("MS Sans Serif")));
		SetTextColor((HDC)wParam,RGB(0,0,0));
		//SetBkMode((HDC)wParam,TRANSPARENT);
		//return (LRESULT)GetStockObject(NULL_BRUSH);
		break;

	case WM_PAINT:
		GetClientRect(hDlg, &rcDialog);
		hdcDialog = BeginPaint(hDlg, &psDialog);
		StretchBlt(hdcDialog, rcDialog.left, rcDialog.top, rcDialog.right-rcDialog.left, rcDialog.bottom-rcDialog.top, hdcSourceDialog, 0, 0, bmpDialog.bmWidth, bmpDialog.bmHeight, SRCCOPY);
		EndPaint(hDlg, &psDialog);
		break;

	case WM_COMMAND:
		switch (HIWORD(wParam))
		{
		case CBN_SELCHANGE:
			switch (LOWORD(wParam))
			{
			case  LB_Processor:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor1:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor2:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor3:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram1:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram2:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard1:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard2:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk1:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk2:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard1:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard2:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD1:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD2:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor1:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor2:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet1:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet2:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard1:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard2:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse1:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse2:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case  LB_SMPS:
				SMPSDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case  LB_SMPS1:
				SMPSDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case  LB_SMPS2:
				SMPSDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_SSD:
				SSDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_SSD1:
				SSDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_SSD2:
				SSDDlgProc(hDlg, iMsg, wParam, lParam);
				break;
			}
		break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_Processor:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor1:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor2:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Processor3:
				ProcessorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram1:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Ram2:
				RamDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard1:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_MotherBoard2:
				MotherboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk1:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_HardDisk2:
				HardDiskDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard1:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_GraphicCard2:
				GraphicCardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD1:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_CDAndDVD2:
				CDAndDVDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor1:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Monitor2:
				MonitorDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet1:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Cabinet2:
				CabinetDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard1:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Keyboard2:
				KeyboardDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse1:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_Mouse2:
				MouseDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case  LB_SMPS:
				SMPSDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case  LB_SMPS1:
				SMPSDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case  LB_SMPS2:
				SMPSDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_SSD:
				SSDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_SSD1:
				SSDDlgProc(hDlg, iMsg, wParam, lParam);
				break;

			case LB_SSD2:
				SSDDlgProc(hDlg, iMsg, wParam, lParam);
				break;
			}
			break;

		default:
			break;
		}

		switch (LOWORD(wParam))
		{
		case IDOK:
			Validate(combi);
			break;

		case IDCANCEL:
			EndDialog(hDlg, 0); 
			DestroyWindow(ghwnd);
			break;

		case IDCONTINUE:
			ContinueKeyIsPressed = TRUE;
			ValidateOnContinue(combi, &do_not_continue);
			if (do_not_continue == TRUE)
			{
				//dont go forward since no items chosen
				MessageBox(ghwnd, TEXT("You need to choose a product"), TEXT("Message"), MB_OK);
			}
			else
			{
				DeleteObject(hdcSourceDialog);
				EndDialog(hDlg, TRUE);
			}
			break;

		case IDRESET:
			ShowWindow(hDlg, SW_MAXIMIZE);
			InitializeHardDisk(hDlg);
			InitializeMotherboard(hDlg);
			InitializeRam(hDlg);
			InitializeGraphicCard(hDlg);
			InitializeCDandDVD(hDlg);
			InitializeMonitor(hDlg);
			InitializeCabinet(hDlg);
			InitializeKeyboard(hDlg);
			InitializeMouse(hDlg);
			InitializeSMPS(hDlg);
			InitializeProcessor(hDlg);
			InitializeSSD(hDlg);
			break;

		case IDDELETELAST:
			FindCurrentlySelectedItem(combi,&currentIndex);
			ResetLastSelectedRow(hDlg,currentIndex);
			break;

		case IDDELETECHOICE:
			FindCurrentlySelectedItem(combi, &currentIndex);
			if (currentIndex!=0)
			{
				retval=DialogBox((HINSTANCE)GetWindowLong(ghwnd, GWL_HINSTANCE), TEXT("CHOICEDELETION"), ghwnd, AskForCategoryDeleteOptions);
				if (retval==0)
				{
					if (deletionindex == 0)
					{
						MessageBox(ghwnd, TEXT("Invalid option selected"), TEXT("Message"), MB_OK);
					}
					else if (deletionindex == 1)
					{
						InitializeProcessor(hDlg);
					}
					else if (deletionindex == 2)
					{
						InitializeRam(hDlg);
					}
					else if (deletionindex == 3)
					{
						InitializeMotherboard(hDlg);
					}
					else if (deletionindex == 4)
					{
						InitializeGraphicCard(hDlg);
					}
					else if (deletionindex == 5)
					{
						InitializeHardDisk(hDlg);
					}
					else if (deletionindex == 6)
					{
						InitializeCDandDVD(hDlg);
					}
					else if (deletionindex == 7)
					{
						InitializeSMPS(hDlg);
					}
					else if (deletionindex == 8)
					{
						InitializeMonitor(hDlg);
					}
					else if (deletionindex == 9)
					{
						InitializeKeyboard(hDlg);
					}
					else if (deletionindex == 10)
					{
						InitializeMouse(hDlg);
					}
					else if (deletionindex == 11)
					{
						InitializeCabinet(hDlg);
					}
					else if (deletionindex == 12)
					{
						InitializeSSD(hDlg);
					}
				}
			}
			else
			{
				MessageBox(ghwnd,TEXT("No items selected"),TEXT("Message"),MB_OK);
			}
			break;

		default:
			break;
		}
		break;
	}
	return FALSE;
}

BOOL CALLBACK AskFilePathDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	void CreateBill(TCHAR *file_path, struct Combined *combi);
	BOOL CheckFileExistance(TCHAR *file_path);
	BOOL CALLBACK AskToProceedDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam);
	void ValidateTimeandDate(struct DateandTime *dt);
	double GetTotalAmount(struct Combined *res);


	TCHAR str[256];
	TCHAR str1[256];
	struct DateandTime *dt = NULL;
	switch (iMsg)
	{
	case WM_INITDIALOG:
		SetFocus(GetDlgItem(hDlg, ID_ETFILEPATH));
		return TRUE;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hDlg, ID_ETFILEPATH, fn->FileName, 256);
			if (wcscmp(fn->FileName, TEXT("")) == 0)
			{
				MessageBox(ghwnd, TEXT("Please enter appropriate file name"), TEXT("Error"), MB_OK);
			}
			else
			{
				wcscpy_s(str, TEXT("./"));
				wcscat_s(str, fn->FileName);
				wcscat_s(str, TEXT(".txt"));
				MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
				EndDialog(hDlg, TRUE);

				if (CheckFileExistance(str) == TRUE)
				{
					CreateBill(str, combi);
				}
				else
				{
					MessageBox(ghwnd, TEXT("The file already exists. So renaming it"), TEXT("Error"), MB_OK);
					dt = (struct DateandTime*)malloc(sizeof(struct DateandTime));
					ValidateTimeandDate(dt);
					wsprintf(str1, TEXT("_%2s%2s%2s%2s"), dt->day,dt->hour, dt->min, dt->sec);
					wcscat_s(fn->FileName, str1);
					memset((void**)&str1, 0, sizeof(str1));
					wcscpy_s(str, TEXT("./"));
					wcscat_s(str, fn->FileName);
					wcscat_s(str, TEXT(".txt"));
					MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
					EndDialog(hDlg, TRUE);
					CreateBill(str, combi);
					free(dt);
					dt = NULL;
				}
				PostQuitMessage(0);
			}
			break;

		case IDCANCEL:
			EndDialog(hDlg,TRUE);
			break;
		}
	}
	return FALSE;
}

BOOL CALLBACK AskForCategoryDeleteOptions(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	void AddArrayinCombobox(HWND hDlg, UINT comboId, TCHAR **str);
	void SetChosenIndex(int index);

	int index;
	TCHAR ListItem[256];
	int retval=0;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		AddArrayinCombobox(hDlg, DELCHOICE, Categories);
		return TRUE;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			EndDialog(hDlg,FALSE);
			break;

		case IDCANCEL:
			EndDialog(hDlg, TRUE);
			break;
		}

		switch (HIWORD(wParam))
		{
		case CBN_SELCHANGE:
			index = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ListItem);

			if (wcscmp(ListItem, TEXT("Select Category")) == 0)
			{
				deletionindex = 0;
			}
			else
			{
				if (wcscmp(ListItem, TEXT("Processor")) == 0)
				{
					deletionindex = 1;
				}
				else if (wcscmp(ListItem, TEXT("RAM")) == 0)
				{
					deletionindex = 2;
				}
				else if (wcscmp(ListItem, TEXT("Motherboard")) == 0)
				{
					deletionindex = 3;
				}
				else if (wcscmp(ListItem, TEXT("Graphics Card")) == 0)
				{
					deletionindex = 4;
				}
				else if (wcscmp(ListItem, TEXT("HardDisk")) == 0)
				{
					deletionindex = 5;
				}
				else if (wcscmp(ListItem, TEXT("CD and DVD")) == 0)
				{
					deletionindex = 6;
				}
				else if (wcscmp(ListItem, TEXT("SMPS")) == 0)
				{
					deletionindex = 7;
				}
				else if (wcscmp(ListItem, TEXT("Monitor")) == 0)
				{
					deletionindex = 8;
				}
				else if (wcscmp(ListItem, TEXT("Keyboard")) == 0)
				{
					deletionindex = 9;
				}
				else if (wcscmp(ListItem, TEXT("Mouse")) == 0)
				{
					deletionindex = 10;
				}
				else if (wcscmp(ListItem, TEXT("Cabinet")) == 0)
				{
					deletionindex = 11;
				}
				else if (wcscmp(ListItem, TEXT("SSD")) == 0)
				{
					deletionindex = 12;
				}
			}
			break;
		}
	}
	return FALSE;
}
