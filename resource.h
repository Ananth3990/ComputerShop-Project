#pragma once
#include<Windows.h>
#define MINIONS_IMAGE_ID 911
#define APPLICATION_ICON 912
#define APPLICATION_CURSOR 913
#define MINIONS_IMAGE1_ID 914

#define IDRESET 981
#define IDDELETELAST 982
#define IDDELETECHOICE 983

#define LB_Processor                    201
#define LB_Processor1                   300
#define LB_Processor2                   301
#define LB_Processor3                   302

#define LB_Ram 303
#define LB_Ram1 304
#define LB_Ram2 305

#define LB_MotherBoard 306
#define LB_MotherBoard1 307
#define LB_MotherBoard2 308

#define LB_HardDisk    309
#define LB_HardDisk1   311
#define LB_HardDisk2   312

#define LB_GraphicCard   313
#define LB_GraphicCard1  314
#define LB_GraphicCard2  315

#define LB_CDAndDVD   316
#define LB_CDAndDVD1  317
#define LB_CDAndDVD2  318

#define LB_Monitor  319
#define LB_Monitor1  320
#define LB_Monitor2  321

#define LB_Cabinet 322
#define LB_Cabinet1 323
#define LB_Cabinet2 324

#define LB_Keyboard 325
#define LB_Keyboard1 326	
#define LB_Keyboard2 327

#define LB_Mouse 328
#define LB_Mouse1 329
#define LB_Mouse2 330

#define LB_SMPS 331
#define LB_SMPS1 332
#define LB_SMPS2 333

#define LB_SSD 856
#define LB_SSD1 857
#define LB_SSD2 858

struct ProcessorInfo
{
	TCHAR Company[50];
	TCHAR CPU[50];
	TCHAR Generation[50];
	TCHAR Price[50];
};

struct RamInfo
{
	TCHAR Company[50];
	TCHAR Size[50];
	TCHAR Price[50];
};

struct MotherBoardInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};

struct HardDiskInfo
{
	TCHAR Company[50];
	TCHAR Size[50];
	TCHAR Price[50];
};

struct GraphicCardInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};

struct CDandDVDInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};

struct MonitorInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};

struct CabinetInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};

struct KeyboardInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};

struct MouseInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};

struct SMPSInfo
{
	TCHAR Company[50];
	TCHAR Voltage[50];
	TCHAR Price[50];
};

struct SSDInfo
{
	TCHAR Company[50];
	TCHAR Product[50];
	TCHAR Price[50];
};


struct Combined
{
	struct SSDInfo ssi;
	struct SMPSInfo smpi;
	struct MouseInfo moui;
	struct KeyboardInfo ki;
	struct CabinetInfo cabi;
	struct MonitorInfo moni;
	struct CDandDVDInfo cdi;
	struct GraphicCardInfo gci;
	struct HardDiskInfo hdi;
	struct MotherBoardInfo mbi;
	struct RamInfo ri;
	struct ProcessorInfo pi;
};

struct ResolutionDetails
{
	UINT x;
	UINT y;
	UINT width;
	UINT height;
};

struct DateandTime
{
	TCHAR day[3];
	TCHAR month[3];
	TCHAR year[5];
	TCHAR hour[3];
	TCHAR min[3];
	TCHAR sec[3];
};
