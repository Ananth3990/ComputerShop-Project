#include <Windows.h>
#include "resource.h"
#include "GraphicCardGlobalShare.h"

void AddStringsinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);
void AddStringinSpecifiedComboBox(HWND hDlg, UINT comboId, TCHAR **str);

extern HWND ghwnd;


BOOL GraphicCardDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
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
			case  LB_GraphicCard:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				ShowWindow(GetDlgItem(hDlg, LB_GraphicCard2), SW_HIDE);

				if (wcscmp(ListItem, TEXT("Select Company")) == 0)
				{
					ShowWindow(GetDlgItem(hDlg, LB_GraphicCard1), SW_HIDE);
					ShowWindow(GetDlgItem(hDlg, LB_GraphicCard2), SW_HIDE);
				}
				else
				{
					if (wcscmp(ListItem, TEXT("AMD")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_GraphicCard1, GraphicCardsAMD);
					}
					else if (wcscmp(ListItem, TEXT("NVIDIA")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_GraphicCard1, GraphicCardsNvidia);
					}
					else if (wcscmp(ListItem, TEXT("Zotac")) == 0)
					{
						AddStringsinSpecifiedComboBox(hDlg, LB_GraphicCard1, GraphicCardsZotac);
					}
				}
				break;

			case LB_GraphicCard1:
				ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0); //index of array is got here
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)ItemIndex, (LPARAM)ListItem); //string in above got index is got here

				if (wcscmp(ListItem, TEXT("GeForce GTX 1050")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsNvidiaPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("GeForce GTX 1060")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsNvidiaPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("GeForce GTX 1080")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsNvidiaPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("GeForce GTX 1080 Ti")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsNvidiaPrice + 3));
				}
				else if (wcscmp(ListItem, TEXT("Zotac NVIDIA GT 730")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsZotacPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("Zotac NVIDIA GT 1050 TI")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsZotacPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("Zotac NVIDIA GT 1050")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsZotacPrice + 2));
				}
				else if (wcscmp(ListItem, TEXT("AMD Radeon R7 240")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsAMDPrice + 0));
				}
				else if (wcscmp(ListItem, TEXT("AMD Radeon R9 280X")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsAMDPrice + 1));
				}
				else if (wcscmp(ListItem, TEXT("AMD Radeon Pro Duo")) == 0)
				{
					AddStringinSpecifiedComboBox(hDlg, LB_GraphicCard2, (GraphicCardsAMDPrice + 2));
				}
				break;

			case LB_GraphicCard2:
				break;
			}
			break;

		case CBN_KILLFOCUS:
			switch (LOWORD(wParam))
			{
			case  LB_GraphicCard:
				index = SendMessage(GetDlgItem(hDlg, LB_GraphicCard), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)gi->Company); //string in above got index is got here
				wcscpy_s(gi->Price, TEXT("-"));
				break;

			case LB_GraphicCard1:
				index = SendMessage(GetDlgItem(hDlg, LB_GraphicCard1), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)gi->Product); //string in above got index is got here
				break;

			case LB_GraphicCard2:
				index = SendMessage(GetDlgItem(hDlg, LB_GraphicCard2), CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT, (WPARAM)index, (LPARAM)gi->Price); //string in above got index is got here	
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
