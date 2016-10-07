/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_SysCtrl.c
 * Description:	F2806x Device System Control Driver Functions
 * Language:    TMS320F2806xM C
 * Author:		Louis Zhu
 * Created:		12/12/2014
 * Mod History: V1.0: Initial version developed on platform F28069ControlStick
 ****************************************************************************************/

#include "F2806x_SysCtrl.h"


/*******************************************************************************************
 * Function: InitSystemClock
 *
 * Description: This function initializes system CPU clock and peripheral clock
 *
 * Parameters: CpuClockEmum cpu_freq
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void InitSystemClock(void)
{
	EALLOW;

	//WDCR address 0x00 7029
	*(Uint16 *)(0x007029) = 0x0068;	//disable watchdog

	//CLKCTL address 0x007012
	*(Uint16 *)(0x007012) = 0x2400;

	EDIS;
}

//--- end of file -----------------------------------------------------
