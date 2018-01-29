//Changed the adresses

#pragma once
#include <Windows.h>
#include "resource.h"
#include "ProcessorGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;

//Changed the adresses for working confirmation
BOOL ProcessorDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	int ItemIndex;
	TCHAR ListItem[256];

	int index;

	switch (iMsg)
	{
	case WM_INITDIALOG:
		return TRUE;
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			break;
			
		case IDCANCEL:
			break;
		}

		switch (HIWORD(wParam))
		{
		case CBN_SELCHANGE:
			switch (LOWORD(wParam))
			{
			case  LB_Processor:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here
					
				ShowWindow(GetDlgItem(hDlg, LB_Processor2), SW_HIDE);
				ShowWindow(GetDlgItem(hDlg, LB_Processor3), SW_HIDE);
				
				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_Processor1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_Processor2), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_Processor3), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Intel")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Processor1, Intel_Processor);
					}
					else if (wcscmp(ListItem, TEXT("AMD")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Processor1, AMD_Processor);
					}
				}
					break;

			case LB_Processor1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here


				ShowWindow(GetDlgItem(hDlg, LB_Processor3), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Core-i3")) == 0)
				{
					AddStringsinSpecifiedComboBox(hDlg, LB_Processor2, Intel_Processor_Generation);
				}
				else if (wcscmp(ListItem, TEXT("Core-i5")) == 0)
				{
					AddStringsinSpecifiedComboBox(hDlg, LB_Processor2, Intel_Processor_Generation);
				}
				else if (wcscmp(ListItem, TEXT("Core-i7")) == 0)
				{
					AddStringsinSpecifiedComboBox(hDlg, LB_Processor2, Intel_Processor_Generation);
				}
				else if (wcscmp(ListItem, TEXT("AMD FX")) == 0)
				{
					AddStringsinSpecifiedComboBox(hDlg, LB_Processor2, AMD_ProcessorFXFamily);
				}
				else if (wcscmp(ListItem, TEXT("Athlon 64")) == 0)
				{
					AddStringsinSpecifiedComboBox(hDlg, LB_Processor2, AMD_ProcessorAthlon64Family);
				}
				else if (wcscmp(ListItem, TEXT("AMD Ryzen 3")) == 0)
				{
					AddStringsinSpecifiedComboBox(hDlg, LB_Processor2, AMD_ProcessorRyzen3Family);
				}
				break;

			case LB_Processor2:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				if ((wcscmp(ListItem, TEXT("Haswell")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i3")) == 0))
				{
				    AddStringinSpecifiedComboBox(hDlg, LB_Processor3,i3Price);
				}
				else if ((wcscmp(ListItem, TEXT("Haswell")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i5")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3,i5Price);
				}
				else if ((wcscmp(ListItem, TEXT("Haswell")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i7")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3,i7Price);
				}
				else if ((wcscmp(ListItem, TEXT("Broadwell")) == 0)  && (wcscmp(pi->CPU, TEXT("Core-i3")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3,(i3Price+1));
				}
				else if ((wcscmp(ListItem, TEXT("Broadwell")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i5")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3,(i5Price + 1));
				}
				else if ((wcscmp(ListItem, TEXT("Broadwell")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i7")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (i7Price + 1));
				}
				else if ((wcscmp(ListItem, TEXT("KabyLake")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i3")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (i3Price + 2));
				}
				else if ((wcscmp(ListItem, TEXT("KabyLake")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i5")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (i5Price + 2));
				}
				else if ((wcscmp(ListItem, TEXT("KabyLake")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i7")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (i7Price + 2));
				}
				else if ((wcscmp(ListItem, TEXT("Skylake")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i3")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3,(i3Price + 3));
				}
				else if ((wcscmp(ListItem, TEXT("Skylake")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i5")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (i5Price + 3));
				}
				else if ((wcscmp(ListItem, TEXT("Skylake")) == 0) && (wcscmp(pi->CPU, TEXT("Core-i7")) == 0))
				{
					
					AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (i7Price + 3));
				}
				else if (wcscmp(ListItem, TEXT("Athlon64")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (AMD_ProcessorFXPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Bulldozer")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3,(AMD_ProcessorFXPrice + 1)); //Change
				}
				else if (wcscmp(ListItem, TEXT("PileDriverCore")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (AMD_ProcessorFXPrice + 2)); //Change
				}
				else if (wcscmp(ListItem, TEXT("SledgeHammer")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3,(AMD_ProcessorAthlon64Price + 0)); //Change
				}
				else if (wcscmp(ListItem, TEXT("ClawHammer")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (AMD_ProcessorAthlon64Price + 1)); //Change
				}
				else if (wcscmp(ListItem, TEXT("SanDiego")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (AMD_ProcessorAthlon64Price + 2)); //Change
				}
				else if (wcscmp(ListItem, TEXT("AMD Ryzen 3 1200")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3, (AMD_ProcessorRyzen3Price + 0)); //Change
				}
				else if (wcscmp(ListItem, TEXT("AMD Ryzen 3 1300X")) == 0)
				{
						AddStringinSpecifiedComboBox(hDlg, LB_Processor3,(AMD_ProcessorRyzen3Price + 1)); //Change
				}
				ShowWindow(GetDlgItem(hDlg, LB_Processor3), SW_SHOWNORMAL);
				break;

			case LB_Processor3:
				MessageBox(NULL, TEXT("LB_Processor3 in CBN_SELCHANGE"), TEXT("Message"), MB_OK);
				SetFocus(GetDlgItem(hDlg, LB_Processor3));
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_Processor:
				index = SendMessage(GetDlgItem(hDlg, LB_Processor), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)pi->Company); //string in above got index is got here
				wcscpy_s(pi->Generation,TEXT("-"));
				wcscpy_s(pi->Price, TEXT("-"));
				break;

			case LB_Processor1:
				index = SendMessage(GetDlgItem(hDlg, LB_Processor1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)pi->CPU); //string in above got index is got here
				wcscpy_s(pi->Price, TEXT("-"));
				break;

			case LB_Processor2:
				index = SendMessage(GetDlgItem(hDlg, LB_Processor2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)pi->Generation); //string in above got index is got here
				break;

			case LB_Processor3:
				index = SendMessage(GetDlgItem(hDlg, LB_Processor3), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)pi->Price); //string in above got index is got here
				break;
			}
			break;
		}
		return TRUE;
		break;
	}
	return FALSE;
}

static void AddStringsinSpecifiedComboBox(HWND hDlg,UINT comboId,TCHAR **str)
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

static void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId,TCHAR **str)
{
	HWND proc;
	
	SendDlgItemMessage(hDlg, comboId, CB_RESETCONTENT, 0, 0);

	SetFocus(GetDlgItem(hDlg, comboId));
	proc = GetDlgItem(hDlg, comboId);
	if (proc != NULL)
	{
		SendMessage(proc, CB_ADDSTRING, 0, (LPARAM)*str);
		SendMessage(proc, CB_SETCURSEL, (WPARAM)0, (LPARAM)0);  //Bcoz of (WPARAM)0 combo box shows first index of array.
	}
	ShowWindow(GetDlgItem(hDlg, comboId), SW_SHOWNORMAL);
	SendDlgItemMessage(hDlg, IDOK, BM_CLICK, (WPARAM)0, (LPARAM)0);
}