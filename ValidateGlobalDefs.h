#pragma once
#include<Windows.h>
#include "resource.h"
#include "CabinetGlobalShare.h"
#include "CDandDVDGlobalShare.h"
#include "GraphicCardGlobalShare.h"
#include "HarddiskGlobalShare.h"
#include "KeyboardGlobalShare.h"
#include "ProcessorGlobalShare.h"
#include "RamGlobalShare.h"
#include "MotherboardGlobalShare.h"
#include "MonitorGlobalShare.h"
#include "MouseGlobalShare.h"
#include "SMPSGlobalShare.h"

struct Combined *combi = NULL;

BOOL time_to_show_in_window = FALSE;
