#include <Windows.h>
#include "resource.h"
#include "CDandDVDGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;


BOOL CDAndDVDDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_CDAndDVD:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_CDAndDVD2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("AMW")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_CDAndDVD1, AMWCDAndDVD);
					}
					else if (wcscmp(ListItem, TEXT("Astrad")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_CDAndDVD1, AstradCDAndDVD);
					}
					else if (wcscmp(ListItem, TEXT("Acrox")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_CDAndDVD1, AcroxCDAndDVD);
					}
				}
				break;

			case LB_CDAndDVD1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				if (wcscmp(ListItem, TEXT("amw s99 dvd player")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AMWCDAndDVDPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("AmphionAMW V99 Player")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AMWCDAndDVDPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("AMW M280 Portable")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AMWCDAndDVDPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("AMW DVD Player V99")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AMWCDAndDVDPrice + 3));
				}
				else if (wcscmp(ListItem, TEXT("Astrad s99 dvd player")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AstradCDAndDVDPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("AmphionAstrad V99 Player")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AstradCDAndDVDPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("AstradM280 Portable")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AstradCDAndDVDPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Astrad DVD Player V99")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AstradCDAndDVDPrice + 3));
				}
				else if (wcscmp(ListItem, TEXT("Acrox s99 dvd player")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AcroxCDAndDVDPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("AmphionAcrox V99 Player")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AcroxCDAndDVDPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("AcroxM280 Portable")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AcroxCDAndDVDPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Acrox DVD Player V99")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_CDAndDVD2, (AcroxCDAndDVDPrice + 3));
				}
				break;

			case LB_CDAndDVD2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_CDAndDVD:
				index = SendMessage(GetDlgItem(hDlg, LB_CDAndDVD), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)cd->Company); //string in above got index is got here
				wcscpy_s(cd->Price, TEXT("-"));
				break;

			case LB_CDAndDVD1:
				index = SendMessage(GetDlgItem(hDlg, LB_CDAndDVD1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)cd->Product); //string in above got index is got here
				break;

			case LB_CDAndDVD2:
				index = SendMessage(GetDlgItem(hDlg, LB_CDAndDVD2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)cd->Price); //string in above got index is got here	
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
