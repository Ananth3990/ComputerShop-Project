#include <Windows.h>
#include "resource.h"
#include "HarddiskGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;

BOOL HardDiskDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_HardDisk:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_HardDisk2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_HardDisk1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_HardDisk2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Western Digital")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_HardDisk1, HardDiskSize);
					}
					else if (wcscmp(ListItem, TEXT("Seagate")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_HardDisk1, HardDiskSize);
					}
				}
				break;

			case LB_HardDisk1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				if ((wcscmp(ListItem, TEXT("500GB")) == 0) && (wcscmp(hi->Company, TEXT("Western Digital")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_HardDisk2, (WesternDigitalPrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("1TB")) == 0) && (wcscmp(hi->Company, TEXT("Western Digital")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_HardDisk2, (WesternDigitalPrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("2TB")) == 0) && (wcscmp(hi->Company, TEXT("Western Digital")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_HardDisk2, (WesternDigitalPrice + 2));
				}
				else if ((wcscmp(ListItem, TEXT("500GB")) == 0) && (wcscmp(hi->Company, TEXT("Seagate")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_HardDisk2, (SeagatePrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("1TB")) == 0) && (wcscmp(hi->Company, TEXT("Seagate")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_HardDisk2, (SeagatePrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("2TB")) == 0) && (wcscmp(hi->Company, TEXT("Seagate")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_HardDisk2, (SeagatePrice + 2));
				}
				break;

			case LB_HardDisk2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_HardDisk:
				index = SendMessage(GetDlgItem(hDlg, LB_HardDisk), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)hi->Company); //string in above got index is got here
				wcscpy_s(hi->Price, TEXT("-"));
				break;

			case LB_HardDisk1:
				index = SendMessage(GetDlgItem(hDlg, LB_HardDisk1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)hi->Size); //string in above got index is got here
				break;

			case LB_HardDisk2:
				index = SendMessage(GetDlgItem(hDlg, LB_HardDisk2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)hi->Price); //string in above got index is got here
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
