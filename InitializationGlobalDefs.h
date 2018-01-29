#pragma once
#include <Windows.h>
#include<stdio.h>
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

HINSTANCE ghInstance = NULL;
HWND ghwnd;

DWORD dwStyle;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };

WNDCLASSEX ac;
MSG msg;
TCHAR szClassName[] = TEXT("Parent Window");

struct AcFileName
{
	TCHAR FileName[256];
};

struct AcFileName *fn = NULL;

extern void DisplayError(LPTSTR lpszFunction);
extern int HandleFileIO(TCHAR *filepath, TCHAR *data);

static UINT SpaceKeyPessed = 0;
static int number_of_items = 0;

static BOOL ContinueKeyIsPressed = FALSE;