#include <Windows.h>
#include "resource.h"
#include "KeyboardGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;

BOOL KeyboardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_Keyboard:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_Keyboard2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_Keyboard1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_Keyboard2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Yamaha")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Keyboard1, YamahaKeyboard);
					}
					else if (wcscmp(ListItem, TEXT("KORG")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Keyboard1, KorgKeyboard);
					}
					else if (wcscmp(ListItem, TEXT("Roland")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Keyboard1, RolandKeyboard);
					}
				}
				break;

			case LB_Keyboard1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				if ((wcscmp(ListItem, TEXT("Wired")) == 0) && (wcscmp(ki->Company, TEXT("Yamaha")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Keyboard2, (YamahaKeyboardPrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("Wired")) == 0) && (wcscmp(ki->Company, TEXT("KORG")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Keyboard2, (KorgKeyboardPrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("Wired")) == 0) && (wcscmp(ki->Company, TEXT("Roland")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Keyboard2, (RolandKeyboardPrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("Wireless")) == 0) && (wcscmp(ki->Company, TEXT("Yamaha")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Keyboard2, (YamahaKeyboardPrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("Wireless")) == 0) && (wcscmp(ki->Company, TEXT("KORG")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Keyboard2, (KorgKeyboardPrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("Wireless")) == 0) && (wcscmp(ki->Company, TEXT("Roland")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Keyboard2, (RolandKeyboardPrice + 1));
				}
				break;

			case LB_Keyboard2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_Keyboard:
				index = SendMessage(GetDlgItem(hDlg, LB_Keyboard), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ki->Company); //string in above got index is got here
				wcscpy_s(ki->Price, TEXT("-"));
				break;

			case LB_Keyboard1:
				index = SendMessage(GetDlgItem(hDlg, LB_Keyboard1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ki->Product); //string in above got index is got here
				break;

			case LB_Keyboard2:
				index = SendMessage(GetDlgItem(hDlg, LB_Keyboard2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ki->Price); //string in above got index is got here	
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
