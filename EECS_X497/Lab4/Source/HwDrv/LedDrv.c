/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	LedDrv.c
 * Description:	F28069 ContrlStick LED Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/18/2014
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/

#include "F2806x_Gpio.h"
#include "LedDrv.h"

/*******************************************************************************************
 * Function: TurnOnLD2
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
void DisplayLD2(LedPatternEnum pat) {
	switch (pat){
	case LED_ON:
		GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
		break;

	case LED_BLINK:
		GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
		break;

	case LED_OFF:
	default:
		GpioDataRegs.GPBSET.bit.GPIO34 = 1;
		break;
	}
}
//--- end of file -----------------------------------------------------
