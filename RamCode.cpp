#include <Windows.h>
#include "resource.h"
#include "RamGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;

//Changed the adresses for working confirmation
BOOL RamDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_Ram:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_Ram2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_Ram1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_Ram2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("Corsair")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Ram1, RamSize);
					}
					else if (wcscmp(ListItem, TEXT("G.Skill")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Ram1, RamSize);
					}
					else if (wcscmp(ListItem, TEXT("OCZ")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Ram1, RamSize);
					}
					else if (wcscmp(ListItem, TEXT("Muskin")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_Ram1, RamSize);
					}
				}
				break;

			case LB_Ram1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				if ((wcscmp(ListItem, TEXT("4GB")) == 0) && (wcscmp(ri->Company, TEXT("Corsair"))==0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (CorsairPrice+0));
				}
				else if ((wcscmp(ListItem, TEXT("4GB")) == 0) && (wcscmp(ri->Company, TEXT("G.Skill")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (GSkillPrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("4GB")) == 0) && (wcscmp(ri->Company, TEXT("OCZ")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (OCZPrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("4GB")) == 0) && (wcscmp(ri->Company, TEXT("Muskin")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (MuskinPrice + 0));
				}
				else if ((wcscmp(ListItem, TEXT("8GB")) == 0) && (wcscmp(ri->Company, TEXT("Corsair")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (CorsairPrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("8GB")) == 0) && (wcscmp(ri->Company, TEXT("G.Skill")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (GSkillPrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("8GB")) == 0) && (wcscmp(ri->Company, TEXT("OCZ")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (OCZPrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("8GB")) == 0) && (wcscmp(ri->Company, TEXT("Muskin")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (MuskinPrice + 1));
				}
				else if ((wcscmp(ListItem, TEXT("16GB")) == 0) && (wcscmp(ri->Company, TEXT("Corsair")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (CorsairPrice + 2));
				}
				else if ((wcscmp(ListItem, TEXT("16GB")) == 0) && (wcscmp(ri->Company, TEXT("G.Skill")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (GSkillPrice + 2));
				}
				else if ((wcscmp(ListItem, TEXT("16GB")) == 0) && (wcscmp(ri->Company, TEXT("OCZ")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (OCZPrice + 2));
				}
				else if ((wcscmp(ListItem, TEXT("16GB")) == 0) && (wcscmp(ri->Company, TEXT("Muskin")) == 0))
				{
					AddStringinSpecifiedComboBox(hDlg, LB_Ram2, (MuskinPrice + 2));
				}
				break;

			case LB_Ram2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_Ram:
				index = SendMessage(GetDlgItem(hDlg, LB_Ram), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ri->Company); //string in above got index is got here
				wcscpy_s(ri->Price, TEXT("-"));
				break;

			case LB_Ram1:
				index = SendMessage(GetDlgItem(hDlg, LB_Ram1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ri->Size); //string in above got index is got here
				break;

			case LB_Ram2:
				index = SendMessage(GetDlgItem(hDlg, LB_Ram2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)ri->Price); //string in above got index is got here
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