#include <Windows.h>
#include "resource.h"
#include "SSDGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;

BOOL SSDDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_SSD:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_SSD2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_SSD1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_SSD2), SW_HIDE);
				}
				else
				{
					/*
					if (wcscmp(ListItem, TEXT("Kingston")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_SSD1, KingstionConsumerSSD);
					}
					else if (wcscmp(ListItem, TEXT("Corsair")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_SSD1, SeagateSSD);
					}
					else if (wcscmp(ListItem, TEXT("Antec")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_SSD2, CorsairSSD);
					}
					*/

					if (wcscmp(ListItem, *(ConsumerSSD +1)) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_SSD1, KingstionConsumerSSD);
					}
					else if (wcscmp(ListItem, *(ConsumerSSD + 2)) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_SSD1, SeagateSSD);
					}
					else if (wcscmp(ListItem, *(ConsumerSSD + 3)) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_SSD1, CorsairSSD);
					}
				}
				break;

			case LB_SSD1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here


				if (wcscmp(ListItem, *(KingstionConsumerSSD+0)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (KingstionConsumerSSDPrice + 0));
				}
				else if (wcscmp(ListItem, *(KingstionConsumerSSD + 1)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (KingstionConsumerSSDPrice + 1));
				}
				else if (wcscmp(ListItem, *(KingstionConsumerSSD + 2)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (KingstionConsumerSSDPrice + 2));
				}
				else if (wcscmp(ListItem, *(SeagateSSD+0)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (SeagateSSDPrice + 0));
				}
				else if (wcscmp(ListItem, *(SeagateSSD + 1)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (SeagateSSDPrice + 1));
				}
				else if (wcscmp(ListItem, *(SeagateSSD + 2)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (SeagateSSDPrice + 2));
				}
				else if (wcscmp(ListItem, *(CorsairSSD + 0)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (CorsairSSDPrice + 0));
				}
				else if (wcscmp(ListItem, *(CorsairSSD + 1)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (CorsairSSDPrice + 1));
				}
				else if (wcscmp(ListItem, *(CorsairSSD + 2)) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_SSD2, (CorsairSSDPrice + 2));
				}
				break;

			case LB_SSD2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_SSD:
				index = SendMessage(GetDlgItem(hDlg, LB_SSD), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ssi->Company); //string in above got index is got here
				wcscpy_s(ssi->Price, TEXT("-"));
				break;

			case LB_SSD1:
				index = SendMessage(GetDlgItem(hDlg, LB_SSD1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ssi->Product); //string in above got index is got here
				break;

			case LB_SSD2:
				index = SendMessage(GetDlgItem(hDlg, LB_SSD2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ssi->Price); //string in above got index is got here	
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
