/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_Gpio.c
 * Description:	F2806x Device Gpio Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/15/2014
 * Notes:
 * Mod History: V1.0: Initial version developed on F28069ControlStick platform
 ****************************************************************************************/

#include "F2806x_Gpio.h"

/*******************************************************************************************
 * Function: InitGpio
 *
 * Description: This function initializes the shared GPIO pins on the F2806x
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes: GPIO34 is connected to LED on F28069 controlSTICK.
 *
 *******************************************************************************************/
void InitGpio(void)
{
	EALLOW;								// Enable EALLOW protected register access

	//GPBMUX1 address 0x006F96
	*(Uint16 *)(0x006F96) = 0x0000;		// 0=GPIO, 1=COMP2OUT, 2=rsvd, 3=COMP3OUT

	// Selected pin configurations
	//GPBCLEAR address 0x006FCC
	*(Uint16 *)(0x006FCC) = 0x0004;		// GPIO34 pin is set to 0 (turn LED on)
	//GPBDIR address 0x006F9A
	*(Uint16 *)(0x006F9A) = 0x0004;		// GPIO34 is an output

	// Finish up
	EDIS;								// Disable EALLOW protected register access
}

//--- end of file -----------------------------------------------------
