/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2013
 * Project:		EECS X497.32 Course Project
 * File Name:	LedDrv.c
 * Description:	F28069 ContrlStick LED Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/18/2014
 * Notes:
 * Mod History: V1.0: Initial version developed on F28069ControlStick platform
 ****************************************************************************************/
#include "F2806x_Device.h"

/*******************************************************************************************
 * Function: ToggleLD2
 *
 * Description: This function toggles LED LD2
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void ToggleLD2(void)
{
	//GPBTOGGLE address 0x006FCE
	*(Uint16 *)(0x006FCE) = 0x0004; 		// Toggle GPIO34 (LD2) of Control Stick
}

//--- end of file -----------------------------------------------------
