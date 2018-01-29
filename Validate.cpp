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
#include "ValidateGlobalShare.h"
#include "SSDGlobalShare.h"

extern HWND ghwnd;

void Validate(struct Combined *res)
{
	if ((wcscmp(mi->Company, TEXT("Select Company")) != 0) && (wcscmp(mi->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->mbi.Company, mi->Company);
		wcscpy_s(combi->mbi.Product, mi->Product);
		wcscpy_s(combi->mbi.Price, mi->Price);
	}
	else
	{
		wcscpy_s(combi->mbi.Company, TEXT("-"));
		wcscpy_s(combi->mbi.Product, TEXT("-"));
		wcscpy_s(combi->mbi.Price, TEXT("-"));
	}

	if ((wcscmp(pi->Company, TEXT("Select Company")) != 0) && (wcscmp(pi->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->pi.Company, pi->Company);
		wcscpy_s(combi->pi.CPU, pi->CPU);
		wcscpy_s(combi->pi.Generation, pi->Generation);
		wcscpy_s(combi->pi.Price, pi->Price);
	}
	else
	{
		wcscpy_s(combi->pi.Company, TEXT("-"));
		wcscpy_s(combi->pi.CPU, TEXT("-"));
		wcscpy_s(combi->pi.Generation, TEXT("-"));
		wcscpy_s(combi->pi.Price, TEXT("-"));
	}

	if ((wcscmp(ri->Company, TEXT("Select Company")) != 0) && (wcscmp(ri->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->ri.Company, ri->Company);
		wcscpy_s(combi->ri.Size, ri->Size);
		wcscpy_s(combi->ri.Price, ri->Price);
	}
	else
	{
		wcscpy_s(combi->ri.Company, TEXT("-"));
		wcscpy_s(combi->ri.Size, TEXT("-"));
		wcscpy_s(combi->ri.Price, TEXT("-"));
	}

	if ((wcscmp(hi->Company, TEXT("Select Company")) != 0) && (wcscmp(hi->Price, TEXT("-")) != 0))
	{
		//all_ok_for_harddisk = TRUE;
		wcscpy_s(combi->hdi.Company, hi->Company);
		wcscpy_s(combi->hdi.Size, hi->Size);
		wcscpy_s(combi->hdi.Price, hi->Price);
	}
	else
	{
		wcscpy_s(combi->hdi.Company, TEXT("-"));
		wcscpy_s(combi->hdi.Size, TEXT("-"));
		wcscpy_s(combi->hdi.Price, TEXT("-"));
	}

	if ((wcscmp(gi->Company, TEXT("Select Company")) != 0) && (wcscmp(gi->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->gci.Company, gi->Company);
		wcscpy_s(combi->gci.Product, gi->Product);
		wcscpy_s(combi->gci.Price, gi->Price);
	}
	else
	{
		wcscpy_s(combi->gci.Company, TEXT("-"));
		wcscpy_s(combi->gci.Product, TEXT("-"));
		wcscpy_s(combi->gci.Price, TEXT("-"));
	}

	if ((wcscmp(cd->Company, TEXT("Select Company")) != 0) && (wcscmp(cd->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->cdi.Company, cd->Company);
		wcscpy_s(combi->cdi.Product, cd->Product);
		wcscpy_s(combi->cdi.Price, cd->Price);
	}
	else
	{
		wcscpy_s(combi->cdi.Company, TEXT("-"));
		wcscpy_s(combi->cdi.Product, TEXT("-"));
		wcscpy_s(combi->cdi.Price, TEXT("-"));
	}

	if ((wcscmp(moni->Company, TEXT("Select Company")) != 0) && (wcscmp(moni->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->moni.Company, moni->Company);
		wcscpy_s(combi->moni.Product, moni->Product);
		wcscpy_s(combi->moni.Price, moni->Price);
	}
	else
	{
		wcscpy_s(combi->moni.Company, TEXT("-"));
		wcscpy_s(combi->moni.Product, TEXT("-"));
		wcscpy_s(combi->moni.Price, TEXT("-"));
	}

	if ((wcscmp(cbi->Company, TEXT("Select Company")) != 0) && (wcscmp(cbi->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->cabi.Company, cbi->Company);
		wcscpy_s(combi->cabi.Product, cbi->Product);
		wcscpy_s(combi->cabi.Price, cbi->Price);
	}
	else
	{
		//all_ok_with_cabinet = FALSE;
		wcscpy_s(combi->cabi.Company, TEXT("-"));
		wcscpy_s(combi->cabi.Product, TEXT("-"));
		wcscpy_s(combi->cabi.Price, TEXT("-"));
	}

	if ((wcscmp(ki->Company, TEXT("Select Company")) != 0) && (wcscmp(ki->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->ki.Company, ki->Company);
		wcscpy_s(combi->ki.Product, ki->Product);
		wcscpy_s(combi->ki.Price, ki->Price);
	}
	else
	{
		wcscpy_s(combi->ki.Company, TEXT("-"));
		wcscpy_s(combi->ki.Product, TEXT("-"));
		wcscpy_s(combi->ki.Price, TEXT("-"));
	}

	if ((wcscmp(moi->Company, TEXT("Select Company")) != 0) && (wcscmp(moi->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->moui.Company, moi->Company);
		wcscpy_s(combi->moui.Product, moi->Product);
		wcscpy_s(combi->moui.Price, moi->Price);
	}
	else
	{
		wcscpy_s(combi->moui.Company, TEXT("-"));
		wcscpy_s(combi->moui.Product, TEXT("-"));
		wcscpy_s(combi->moui.Price, TEXT("-"));
	}

	if ((wcscmp(smpi->Company, TEXT("Select Company")) != 0) && (wcscmp(smpi->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->smpi.Company, smpi->Company);
		wcscpy_s(combi->smpi.Voltage, smpi->Voltage);
		wcscpy_s(combi->smpi.Price, smpi->Price);
	}
	else
	{
		wcscpy_s(combi->smpi.Company, TEXT("-"));
		wcscpy_s(combi->smpi.Voltage, TEXT("-"));
		wcscpy_s(combi->smpi.Price, TEXT("-"));
	}

	if ((wcscmp(ssi->Company, TEXT("Select Company")) != 0) && (wcscmp(ssi->Price, TEXT("-")) != 0))
	{
		wcscpy_s(combi->ssi.Company, ssi->Company);
		wcscpy_s(combi->ssi.Product,ssi->Product);
		wcscpy_s(combi->ssi.Price, ssi->Price);
	}
	else
	{
		wcscpy_s(combi->ssi.Company, TEXT("-"));
		wcscpy_s(combi->ssi.Product, TEXT("-"));
		wcscpy_s(combi->ssi.Price, TEXT("-"));
	}
}

void ValidateOnContinue(struct Combined *res,BOOL *dont_go_forward)
{
	int itemCount = 0;

	if ((wcscmp(mi->Company, TEXT("Select Company")) != 0) && (wcscmp(mi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;	
		itemCount++;
	}

	if ((wcscmp(pi->Company, TEXT("Select Company")) != 0) && (wcscmp(pi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}

	if ((wcscmp(ri->Company, TEXT("Select Company")) != 0) && (wcscmp(ri->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}

	if ((wcscmp(hi->Company, TEXT("Select Company")) != 0) && (wcscmp(hi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}

	if ((wcscmp(gi->Company, TEXT("Select Company")) != 0) && (wcscmp(gi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}

	if ((wcscmp(cd->Company, TEXT("Select Company")) != 0) && (wcscmp(cd->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}
	

	if ((wcscmp(moni->Company, TEXT("Select Company")) != 0) && (wcscmp(moni->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}
	
	if ((wcscmp(cbi->Company, TEXT("Select Company")) != 0) && (wcscmp(cbi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}
	

	if ((wcscmp(ki->Company, TEXT("Select Company")) != 0) && (wcscmp(ki->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}

	if ((wcscmp(moi->Company, TEXT("Select Company")) != 0) && (wcscmp(moi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}

	if ((wcscmp(smpi->Company, TEXT("Select Company")) != 0) && (wcscmp(smpi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}
	
	if ((wcscmp(ssi->Company, TEXT("Select Company")) != 0) && (wcscmp(ssi->Price, TEXT("-")) != 0))
	{
		time_to_show_in_window = TRUE;
		itemCount++;
	}
	
	if (itemCount==0)
	{
		*dont_go_forward = TRUE;
		time_to_show_in_window = FALSE;
	}
	else
	{
		*dont_go_forward = FALSE;
		InvalidateRect(ghwnd, NULL, TRUE);
	}
}

