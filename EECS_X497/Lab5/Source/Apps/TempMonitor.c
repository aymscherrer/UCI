 /****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2013
 * Project:		EECS X497.19 Course Project
 * File Name:	F2806x_Temp.c
 * Description:	F2806x Device Temperature Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		9/15/2013
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/

#include "TempMonitor.h"
#include "F2806x_Adc.h"

/****************************************************
 * #pragma section
 ****************************************************/

/****************************************************
 * Variable Declaration
 ****************************************************/
TempDataStruct tempData;


/****************************************************
 * Static Function Prototypes
 ****************************************************/


/*******************************************************************************************
 * Function: ConvertTemp
 *
 * Description: This function reads temperature ADC value and converts to deg C
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void ConvertTemp(void)
{
	tempData.RawData = GetTempRawData();
	tempData.DegC = ((tempData.RawData - getTempOffset())*(Int32)getTempSlope() + FP_ROUND + KELVIN_OFF)/FP_SCALE - KELVIN;
}
//--- end of file -----------------------------------------------------
