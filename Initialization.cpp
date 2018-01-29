#include<Windows.h>
#include "resource.h"
#include "CabinetGlobalShare.h"
#include "CDandDVDGlobalShare.h"
#include "GraphicCardGlobalShare.h"
#include "HarddiskGlobalShare.h"
#include "KeyboardGlobalShare.h"
#include "ProcessorGlobalShare.h"
#include "RamGlobalShare.h"
#include "MotherboardGlobalShare.h"
#include "MonitorGlobalShare.h"
#include "MouseGlobalShare.h"
#include "SMPSGlobalShare.h"
#include "SSDGlobalShare.h"


void InitializeProcessor(HWND hDlg)
{
	ShowWindow(GetDlgItem(hDlg, LB_Processor1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Processor2), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Processor3), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Processor));
	SendDlgItemMessage(hDlg, LB_Processor, CB_RESETCONTENT, 0, 0);
	for (int i = 0; (*(Processor + i)) != 0; i++)
	{
		SendMessage(GetDlgItem(hDlg, LB_Processor), CB_ADDSTRING, 0, (LPARAM)(*(Processor + i)));
	}
	SendMessage(GetDlgItem(hDlg, LB_Processor), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	ShowWindow(GetDlgItem(hDlg, LB_Processor), SW_SHOW);
}

void InitializeRam(HWND hDlg)
{
	ShowWindow(GetDlgItem(hDlg, LB_Ram1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Ram2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Ram));
	SendDlgItemMessage(hDlg, LB_Ram, CB_RESETCONTENT, 0, 0);
	for (int i = 0; (*(Ram + i)) != 0; i++)
	{
		SendMessage(GetDlgItem(hDlg, LB_Ram), CB_ADDSTRING, 0, (LPARAM)(*(Ram + i)));
	}
	SendMessage(GetDlgItem(hDlg, LB_Ram), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	ShowWindow(GetDlgItem(hDlg, LB_Ram), SW_SHOW);
}

void InitializeMotherboard(HWND hDlg)
{
	ShowWindow(GetDlgItem(hDlg, LB_MotherBoard1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_MotherBoard2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_MotherBoard));
	SendDlgItemMessage(hDlg, LB_MotherBoard, CB_RESETCONTENT, 0, 0);
	for (int i = 0; (*(MotherBoards + i)) != 0; i++)
	{
		SendMessage(GetDlgItem(hDlg, LB_MotherBoard), CB_ADDSTRING, 0, (LPARAM)(*(MotherBoards + i)));
	}
	SendMessage(GetDlgItem(hDlg, LB_MotherBoard), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	ShowWindow(GetDlgItem(hDlg, LB_MotherBoard), SW_SHOW);
}

void InitializeHardDisk(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_HardDisk1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_HardDisk2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_HardDisk));
	proc = GetDlgItem(hDlg, LB_HardDisk);
	if (proc != NULL)
	{
		for (int i = 0; (*(HardDisk + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(HardDisk + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_HardDisk), SW_SHOW);
}

void InitializeGraphicCard(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_GraphicCard1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_GraphicCard2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_GraphicCard));
	proc = GetDlgItem(hDlg, LB_GraphicCard);
	if (proc != NULL)
	{
		for (int i = 0; (*(GraphicCards + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(GraphicCards + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_GraphicCard), SW_SHOW);
}

void InitializeCDandDVD(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_CDAndDVD));
	proc = GetDlgItem(hDlg, LB_CDAndDVD);
	if (proc != NULL)
	{
		for (int i = 0; (*(CDAndDVD + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(CDAndDVD + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD), SW_SHOW);
}

void InitializeMonitor(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Monitor1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Monitor2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Monitor));
	proc = GetDlgItem(hDlg, LB_Monitor);
	if (proc != NULL)
	{
		for (int i = 0; (*(Monitor + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Monitor + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Monitor), SW_SHOW);
}

void InitializeCabinet(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Cabinet1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Cabinet2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Cabinet));
	proc = GetDlgItem(hDlg, LB_Cabinet);
	if (proc != NULL)
	{
		for (int i = 0; (*(Cabinet + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Cabinet + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Cabinet), SW_SHOW);
}

void InitializeKeyboard(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Keyboard1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Keyboard2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Keyboard));
	proc = GetDlgItem(hDlg, LB_Keyboard);
	if (proc != NULL)
	{
		for (int i = 0; (*(Keyboard + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Keyboard + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Keyboard), SW_SHOW);
}

void InitializeMouse(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_Mouse1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_Mouse2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_Mouse));
	proc = GetDlgItem(hDlg, LB_Mouse);
	if (proc != NULL)
	{
		for (int i = 0; (*(Mouse + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(Mouse + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_Mouse), SW_SHOW);
}

void InitializeSMPS(HWND hDlg)
{
	HWND proc;

	ShowWindow(GetDlgItem(hDlg, LB_SMPS1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_SMPS2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_SMPS));
	proc = GetDlgItem(hDlg, LB_SMPS);
	if (proc != NULL)
	{
		for (int i = 0; (*(SMPS + i)) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(SMPS + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, LB_SMPS), SW_SHOW);
}

void AddArrayinCombobox(HWND hDlg, UINT comboId, TCHAR **str)
{
	HWND proc;
	SendDlgItemMessage(hDlg, comboId, CB_RESETCONTENT, 0, 0);

	SetFocus(GetDlgItem(hDlg, comboId));
	proc = GetDlgItem(hDlg, comboId);
	if (proc != NULL)
	{
		for (int i = 0; *(str + i) != 0; i++)
		{
			SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)(*(str + i)));
		}
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, comboId), SW_SHOWNORMAL);
}

void InitializeSSD(HWND hDlg)
{
	ShowWindow(GetDlgItem(hDlg, LB_SSD1), SW_HIDE);
	ShowWindow(GetDlgItem(hDlg, LB_SSD2), SW_HIDE);

	SetFocus(GetDlgItem(hDlg, LB_SSD));
	SendDlgItemMessage(hDlg, LB_SSD, CB_RESETCONTENT, 0, 0);
	for (int i = 0; *(ConsumerSSD + i) != 0; i++)
	{
		SendMessage(GetDlgItem(hDlg,LB_SSD), CB_ADDSTRING, 0, (LPARAM)(*(ConsumerSSD + i)));
	}
	SendMessage(GetDlgItem(hDlg, LB_SSD), CB_SETCURSEL, (WPARAM)0, (LPARAM)0);
	ShowWindow(GetDlgItem(hDlg, LB_SSD), SW_SHOW);
}


