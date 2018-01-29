#pragma once
#include<Windows.h>
#include "InitializationShare.h"
#include "ProcessorGlobalShare.h"
#include "CabinetGlobalShare.h"
#include "CDandDVDGlobalShare.h"
#include "GraphicCardGlobalShare.h"
#include "HarddiskGlobalShare.h"
#include "KeyboardGlobalShare.h"
#include "MonitorGlobalShare.h"
#include "MotherboardGlobalShare.h"
#include "MouseGlobalShare.h"
#include "RamGlobalShare.h"
#include "SMPSGlobalShare.h"
#include "SSDGlobalShare.h"
#include "resource.h"

extern HWND ghwnd;


int deletionindex = 0;
TCHAR *Categories[] = { TEXT("Select Category"),TEXT("Processor"),TEXT("RAM"),TEXT("Motherboard"),TEXT("Graphics Card"),TEXT("HardDisk"),TEXT("CD and DVD"),TEXT("SMPS"),TEXT("Monitor"),TEXT("Keyboard"),TEXT("Mouse"),TEXT("Cabinet"),TEXT("SSD"),0 };
