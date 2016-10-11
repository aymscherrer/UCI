/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2013
 * Project:		EECS X497.32 Course Project
 * File Name:	LedDrv.h
 * Description:	F28069 ContrlStick LED Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/18/2014
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/
/*******************************************************************************************
 * Data type definition
 *******************************************************************************************/

//LED brink pattern emuneration

typedef enum eLedPatternEnum {
	LED_OFF=0,
	LED_ON,
	LED_BLINK
}LedPatternEnum;

#ifndef LED_DRV_H
#define LED_DRV_H

/*******************************************************************************************
 * Public function prototypes
 *******************************************************************************************/
//void ToggleLD2(void);
void DisplayLD2(LedPatternEnum pat);


#endif  // end of LED_DRV_H definition
//===========================================================================
// End of file.
//===========================================================================
