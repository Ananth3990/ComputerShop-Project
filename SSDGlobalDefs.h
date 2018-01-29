#pragma once
#include<Windows.h>
TCHAR *ConsumerSSD[5] = { TEXT("Select Company"),TEXT("Kingston"),TEXT("Seagate"),TEXT("Corsair"),0 };

TCHAR *KingstionConsumerSSD[4] = { TEXT("HyperX Fury 120GB SSD"),TEXT("HyperX Fury 240GB SSD"),TEXT("HyperX Fury 480GB SSD"),0 };
TCHAR *KingstionConsumerSSDPrice[4] = { TEXT("5014"),TEXT("7944"),TEXT("15648"),0 };
TCHAR *SeagateSSD[4] = { TEXT("Seagate FireCuda 1TB"),TEXT("Seagate FireCuda 2TB"),TEXT("Seagate FireCuda 10TB"),0 };
TCHAR *SeagateSSDPrice[4] = { TEXT("6102"),TEXT("5320"),TEXT("12090"),0 };
TCHAR *CorsairSSD[4] = { TEXT("CorsairForce LE200 120GB"),TEXT("CorsairForce LE200 240GB"),TEXT("CorsairForce SeriesMP500"),0 };
TCHAR *CorsairSSDPrice[4] = { TEXT("4400"),TEXT("7448"),TEXT("13904"),0 };

struct  SSDInfo *ssi;

