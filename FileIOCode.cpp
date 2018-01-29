#include "FileIOCode.h"

extern HWND ghwnd;

int HandleFileIO(TCHAR *filepath, TCHAR *data)
{
	void DisplayError(LPTSTR lpszFunction);

	HANDLE hFile;
	BOOL bErrorFlag = FALSE;
	DWORD dwBytesToWrite = (DWORD)wcslen(data);
	DWORD dwBytesWritten = 0;
	char *temp = (char*)malloc(wcslen(data) * sizeof(TCHAR));
	TCHAR str[256];

	hFile = CreateFile(filepath,    // name of the write
		FILE_APPEND_DATA,          // open for writing
		0,                      // do not share
		NULL,                   // default security
		OPEN_ALWAYS,             // create new file only
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		DisplayError(TEXT("CreateFile"));
		return -1;
	}

	if (WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)data, -1, temp, wcslen(data) * sizeof(TCHAR), NULL, NULL) == 0)
	{
		DisplayError(TEXT("WideCharToMultiByte"));
		return -2;
	}

	bErrorFlag = WriteFile(
		hFile,           // open file handle
		temp,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure

	free(temp);
	temp = NULL;

	if (FALSE == bErrorFlag)
	{
		DisplayError(TEXT("WriteFile"));
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			// This is an error because a synchronous write that results in
			// success (WriteFile returns TRUE) should write all data as
			// requested. This would not necessarily be the case for
			// asynchronous writes.
			MessageBox(ghwnd,TEXT("dwBytesWritten != dwBytesToWrite\n"),TEXT("Error"),MB_OK);
		}
		else
		{
			wsprintf(str,TEXT("Wrote %d bytes to %ls successfully.\n"), dwBytesWritten, filepath);
			//MessageBox(ghwnd,str,TEXT("Message"),MB_OK);
		}
	}

	CloseHandle(hFile);

	return 0;
}

void DisplayError(LPTSTR lpszFunction)
// Routine Description:
// Retrieve and output the system error message for the last-error code
{
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0,
		NULL);

	lpDisplayBuf =
		(LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf)
			+ lstrlen((LPCTSTR)lpszFunction)
			+ 40) // account for format string
			* sizeof(TCHAR));

	if (FAILED(StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error code %d as follows:\n%s"),
		lpszFunction,
		dw,
		lpMsgBuf)))
	{
		printf("FATAL ERROR: Unable to output error code.\n");
	}

	printf("ERROR: %ls\n", (LPCTSTR)lpDisplayBuf);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
}

void CreateBill(TCHAR *file_path,struct Combined *combi)
{
	void DisplayError(LPTSTR lpszFunction);
	int HandleFileIO(TCHAR *filepath, TCHAR *data);
	double GetTotalAmount(struct Combined *res);
	void ValidateTimeandDate(struct DateandTime *dt);

	struct DateandTime *dt=NULL;

	dt = (struct DateandTime*)malloc(sizeof(struct DateandTime));
	ValidateTimeandDate(dt);

	TCHAR str[10000];

	wsprintf(str, TEXT("%20s"), TEXT("\r\t\r\t\r\t\r\t\r\t\r\t\r\t----MyComputer Shoppe Bill Receipt------\r\n"));
	HandleFileIO(file_path,str);
	memset((void**)&str,0,sizeof(str));

	wsprintf(str, TEXT("\r\t\r\t\r\t\r\t\r\t\r\t\r\tDate : %2s/%2s/%4s\r\t"),dt->day,dt->month,dt->year);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("\r\tTime : %2s:%2s:%2s\r\n"),dt->hour, dt->min,dt->sec);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Category"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Company"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Product"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Other Information"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), TEXT("Price"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));
	//----------------------------------
	
	wsprintf(str, TEXT("%25s\r\t"), TEXT("Processor"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"),combi->pi.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->pi.CPU);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->pi.Generation);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->pi.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Ram"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ri.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ri.Size);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));


	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->ri.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));
	//-----------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Motherboard"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->mbi.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->mbi.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->mbi.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Graphic Card"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->gci.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->gci.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->gci.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//-----------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("HardDisk"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->hdi.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->hdi.Size);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->hdi.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//-------------------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("CD and DVD"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cdi.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cdi.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->cdi.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//-------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("SMPS"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->smpi.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->smpi.Voltage);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->smpi.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Monitor"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moni.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moni.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->moni.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//--------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Keyboard"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ki.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ki.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->ki.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//---------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Mouse"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moui.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->moui.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->moui.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("Cabinet"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cabi.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->cabi.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->cabi.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));
	//-------------------------------------------------------

	wsprintf(str, TEXT("%25s\r\t"), TEXT("SSD"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ssi.Company);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), combi->ssi.Product);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t"), TEXT("-"));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	wsprintf(str, TEXT("%25s\r\t\r\n"), combi->ssi.Price);
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//-------------------------------------------------------
	swprintf_s(str, TEXT("%150s = Rs %lf"),TEXT("Total Price "),GetTotalAmount(combi));
	HandleFileIO(file_path, str);
	memset((void**)&str, 0, sizeof(str));

	//------------------------------------------------------

	free(dt);
	dt = NULL;
}

BOOL CheckFileExistance(TCHAR *file_path)
{
	TCHAR str[256];
	if (PathFileExists(file_path)==TRUE)
	{
		wsprintf(str,TEXT("The requested file having path %s already exixts"),file_path);
		MessageBox(ghwnd, str, TEXT("Message"), MB_OK);
		return FALSE;
	}
	else
	{
		MessageBox(ghwnd, TEXT("Proceeding for Bill Receipt"), TEXT("Message"), MB_OK);
	}
	return TRUE;
}

double GetTotalAmount(struct Combined *res)
{
	double price = 0.0;

	if (wcscmp(res->cabi.Price,TEXT("-"))!=0)
	{
		price += _wtof(res->cabi.Price);
	}

	if (wcscmp(res->cdi.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->cdi.Price);
	}

	if (wcscmp(res->gci.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->gci.Price);
	}

	if (wcscmp(res->hdi.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->hdi.Price);
	}

	if (wcscmp(res->ki.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->ki.Price);
	}

	if (wcscmp(res->mbi.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->mbi.Price);
	}

	if (wcscmp(res->moni.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->moni.Price);
	}

	if (wcscmp(res->moui.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->moui.Price);
	}

	if (wcscmp(res->pi.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->pi.Price);
	}

	if (wcscmp(res->ri.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->ri.Price);
	}

	if (wcscmp(res->smpi.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->smpi.Price);
	}

	if (wcscmp(res->ssi.Price, TEXT("-")) != 0)
	{
		price += _wtof(res->ssi.Price);
	}

	return price;
}

