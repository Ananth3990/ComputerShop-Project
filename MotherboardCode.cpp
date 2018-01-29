#include <Windows.h>
#include "resource.h"
#include "MotherboardGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;


BOOL MotherboardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_MotherBoard:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_MotherBoard2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_MotherBoard1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_MotherBoard2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Asus")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_MotherBoard1, AsusMotherboards);
					}
					else if (wcscmp(ListItem, TEXT("Gigabyte")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_MotherBoard1, GigabyteMotherboards);
					}
					else if (wcscmp(ListItem, TEXT("Biostar")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_MotherBoard1, BioStarMotherboards);
					}
					else if (wcscmp(ListItem, TEXT("AsRock")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_MotherBoard1, AsRockMotherboards);
					}
				}
				break;

			case LB_MotherBoard1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				if (wcscmp(ListItem, TEXT("Prime H270-PLUS")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (AsusMotherboardsPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Asus Intel H61M-CS")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (AsusMotherboardsPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("ASUS H81M-CS")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (AsusMotherboardsPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Gigabyte GA-H110M-S2")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (GigabyteMotherboardsPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Gigabyte GA-H61M-S")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (GigabyteMotherboardsPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Gigabyte GA-B250-DS3H")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (GigabyteMotherboardsPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Biostar H81MHV3")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (BioStarMotherboardsPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Biostar B150GT5")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (BioStarMotherboardsPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Biostar A68N-2100")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (BioStarMotherboardsPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("Asrock B250M Pro4")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (AsRockMotherboardsPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Asrock AB350")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (AsRockMotherboardsPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Asrock AB345")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_MotherBoard2, (AsRockMotherboardsPrice + 2));
				}
				break;

			case LB_MotherBoard2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_MotherBoard:
				index = SendMessage(GetDlgItem(hDlg, LB_MotherBoard), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)mi->Company); //string in above got index is got here
				wcscpy_s(mi->Price,TEXT("-"));
				break;

			case LB_MotherBoard1:
				index = SendMessage(GetDlgItem(hDlg, LB_MotherBoard1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)mi->Product); //string in above got index is got here
				break;

			case LB_MotherBoard2:
				index = SendMessage(GetDlgItem(hDlg, LB_MotherBoard2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)mi->Price); //string in above got index is got here	
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
