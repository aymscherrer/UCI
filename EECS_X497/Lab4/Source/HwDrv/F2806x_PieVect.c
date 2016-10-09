/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2013
 * Project:		EECS X497.19 Course Project
 * File Name:	F2806x_PieVect.c
 * Description:	F2806x Device PIE Vector Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		9/15/2013
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/

#include "F2806x_PieVect.h"
#include "F2806x_Xint1.h"

/****************************************************
 * #pragma section
 ****************************************************/
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");

/****************************************************
 * variable declaration
 ****************************************************/
struct PIE_VECT_TABLE PieVectTable;

/****************************************************
 * private function prototypes
 ****************************************************/
interrupt void ISR_ILLEGAL(void);

/*******************************************************************************************
 * Function: InitPieVectTable
 *
 * Description: This function initializes PIE vector table
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void InitPieVectTable(void)
{
   	PINT *dest = &PieVectTable.TINT1;
   	PINT *destEnd = &PieVectTable.LUF;

   	EALLOW;
   	do
   	{
   		*dest++ = &ISR_ILLEGAL;
   	}while(dest <= destEnd);

   	//initialize XINT1 vector
   	PieVectTable.XINT1 = &Xint1_isr;

	EDIS;
}

/*******************************************************************************************
 * Function: ISR_ILLEGAL
 *
 * Description: This function handles undefined interrupt faults.
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes: when any illegal interrupts occur, the LED2 will blink abnormally
 *
 *******************************************************************************************/
interrupt void ISR_ILLEGAL(void)
{
  	// Insert fault handling code
	// Next two lines for debug only - remove after inserting your ISR
	asm (" ESTOP0");							// Emulator Halt instruction
	while(1);
}

//--- end of file -----------------------------------------------------
