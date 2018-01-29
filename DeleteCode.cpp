#include "DeleteCodeGlobalDefs.h"

void FindCurrentlySelectedItem(struct Combined *res, int *delete_index)
{
	if ((wcscmp(pi->Company, TEXT("Select Company")) != 0) && (wcscmp(pi->Price, TEXT("-")) != 0))
	{
		*delete_index = 1;
	}

	if ((wcscmp(ri->Company, TEXT("Select Company")) != 0) && (wcscmp(ri->Price, TEXT("-")) != 0))
	{
		*delete_index = 2;
	}

	if ((wcscmp(mi->Company, TEXT("Select Company")) != 0) && (wcscmp(mi->Price, TEXT("-")) != 0))
	{
		*delete_index = 3;
	}

	if ((wcscmp(gi->Company, TEXT("Select Company")) != 0) && (wcscmp(gi->Price, TEXT("-")) != 0))
	{
		*delete_index = 4;
	}

	if ((wcscmp(hi->Company, TEXT("Select Company")) != 0) && (wcscmp(hi->Price, TEXT("-")) != 0))
	{
		*delete_index = 5;
	}

	if ((wcscmp(cd->Company, TEXT("Select Company")) != 0) && (wcscmp(cd->Price, TEXT("-")) != 0))
	{
		*delete_index = 6;
	}

	if ((wcscmp(smpi->Company, TEXT("Select Company")) != 0) && (wcscmp(smpi->Price, TEXT("-")) != 0))
	{
		*delete_index = 7;
	}

	if ((wcscmp(moni->Company, TEXT("Select Company")) != 0) && (wcscmp(moni->Price, TEXT("-")) != 0))
	{
		*delete_index = 8;
	}

	if ((wcscmp(ki->Company, TEXT("Select Company")) != 0) && (wcscmp(ki->Price, TEXT("-")) != 0))
	{
		*delete_index = 9;
	}

	if ((wcscmp(moi->Company, TEXT("Select Company")) != 0) && (wcscmp(moi->Price, TEXT("-")) != 0))
	{
		*delete_index = 10;
	}

	if ((wcscmp(cbi->Company, TEXT("Select Company")) != 0) && (wcscmp(cbi->Price, TEXT("-")) != 0))
	{
		*delete_index = 11;
	}

	if ((wcscmp(ssi->Company, TEXT("Select Company")) != 0) && (wcscmp(ssi->Price, TEXT("-")) != 0))
	{
		*delete_index = 12;
	}
}

void ResetLastSelectedRow(HWND hDlg,int index)
{
	void InitializeProcessor(HWND hDlg);
	void InitializeRam(HWND hDlg);
	void InitializeMotherboard(HWND hDlg);
	void InitializeHardDisk(HWND hDlg);
	void InitializeGraphicCard(HWND hDlg);
	void InitializeCDandDVD(HWND hDlg);
	void InitializeMonitor(HWND hDlg);
	void InitializeCabinet(HWND hDlg);
	void InitializeKeyboard(HWND hDlg);
	void InitializeMouse(HWND hDlg);
	void InitializeSMPS(HWND hDlg);
	void InitializeSSD(HWND hDlg);

	if (index == 0)
	{
		MessageBox(ghwnd, TEXT("No items selected"), TEXT("Message"), MB_OK);
	}
	else if (index == 1)
	{
		InitializeProcessor(hDlg);
	}
	else if (index == 2)
	{
		InitializeRam(hDlg);
	}
	else if (index == 3)
	{
		InitializeMotherboard(hDlg);
	}
	else if (index == 4)
	{
		InitializeGraphicCard(hDlg);
	}
	else if (index == 5)
	{
		InitializeHardDisk(hDlg);
	}
	else if (index == 6)
	{
		InitializeCDandDVD(hDlg);
	}
	else if (index == 7)
	{
		InitializeProcessor(hDlg);
	}
	else if (index == 8)
	{
		InitializeMonitor(hDlg);
	}
	else if (index == 9)
	{
		InitializeKeyboard(hDlg);
	}
	else if (index == 10)
	{
		InitializeMouse(hDlg);
	}
	else if (index == 11)
	{
		InitializeCabinet(hDlg);
	}
	else if (index == 12)
	{
		InitializeSSD(hDlg);
	}
}


