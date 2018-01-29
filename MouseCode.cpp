#include <Windows.h>
#include "resource.h"
#include "MouseGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;

BOOL MouseDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_Mouse:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_Mouse2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_Mouse1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_Mouse2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Logitech")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Mouse1, LogitechMouse);
					}
					else if (wcscmp(ListItem, TEXT("Asus")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Mouse1, AsusMouse);
					}
					else if (wcscmp(ListItem, TEXT("Corsair")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Mouse1, CorsairMouse);
					}
				}
				break;

			case LB_Mouse1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here


				if ((wcscmp(ListItem, TEXT("Wired")) == 0) && (wcscmp(moi->Company, TEXT("Logitech")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Mouse2, (LogitechMousePrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("Wired")) == 0) && (wcscmp(moi->Company, TEXT("Asus")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Mouse2, (AsusMousePrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("Wired")) == 0) && (wcscmp(moi->Company, TEXT("Corsair")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Mouse2, (CorsairMousePrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("Wireless")) == 0) && (wcscmp(moi->Company, TEXT("Logitech")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Mouse2, (LogitechMousePrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("Wireless")) == 0) && (wcscmp(moi->Company, TEXT("Asus")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Mouse2, (AsusMousePrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("Wireless")) == 0) && (wcscmp(moi->Company, TEXT("Corsair")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Mouse2, (CorsairMousePrice + 1));
				}
				break;

			case LB_Mouse2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_Mouse:
				index = SendMessage(GetDlgItem(hDlg, LB_Mouse), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)moi->Company); //string in above got index is got here
				wcscpy_s(moi->Price, TEXT("-"));
				break;

			case LB_Mouse1:
				index = SendMessage(GetDlgItem(hDlg, LB_Mouse1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)moi->Product); //string in above got index is got here
				break;

			case LB_Mouse2:
				index = SendMessage(GetDlgItem(hDlg, LB_Mouse2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)moi->Price); //string in above got index is got here	
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
