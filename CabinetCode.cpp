#include <Windows.h>
#include "resource.h"
#include "CabinetGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;


BOOL CabinetDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_Cabinet:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_Cabinet2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_Cabinet1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_Cabinet2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Circle")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Cabinet1, CircleCabinet);
					}
					else if (wcscmp(ListItem, TEXT("Corsair")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Cabinet1, CorsairCabinet);
					}
					else if (wcscmp(ListItem, TEXT("Antec")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Cabinet1, AntecCabinet);
					}
				}
				break;

			case LB_Cabinet1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here


				if (wcscmp(ListItem, TEXT("Circle Pheonix Cabinet")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (CircleCabinetPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Circle CC 819")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (CircleCabinetPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Circle CC 890")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (CircleCabinetPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Antec Cabinet gx200")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (AntecCabinetPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Antec Cabinet x1")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (AntecCabinetPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Antec Cabinet 900")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (AntecCabinetPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Corsair Carbide 2100")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (CorsairCabinetPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Corsair Carbide 123")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (CorsairCabinetPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Corsair Carbide 900")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Cabinet2, (CorsairCabinetPrice + 2));
				}
				break;

			case LB_Cabinet2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_Cabinet:
				index = SendMessage(GetDlgItem(hDlg, LB_Cabinet), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)cbi->Company); //string in above got index is got here
				wcscpy_s(cbi->Price, TEXT("-"));
				break;

			case LB_Cabinet1:
				index = SendMessage(GetDlgItem(hDlg, LB_Cabinet1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)cbi->Product); //string in above got index is got here
				break;

			case LB_Cabinet2:
				index = SendMessage(GetDlgItem(hDlg, LB_Cabinet2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)cbi->Price); //string in above got index is got here	
				break;
			}
			break;
		}
		return TRUE;
		break;
	}
	return FALSE;
}

static void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str)
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

static void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str)
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
