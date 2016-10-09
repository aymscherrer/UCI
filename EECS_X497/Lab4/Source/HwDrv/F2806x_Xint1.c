/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_Xint.c
 * Description:	F2806x Device External Interrupt 1 Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/15/2014
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/

#include "F2806x_Gpio.h"
#include "F2806x_Xint1.h"
#include "F2806x_PieCtrl.h"

/****************************************************
 * #pragma section
 ****************************************************/
#pragma DATA_SECTION(XIntruptRegs, "XIntruptRegsFile");


/****************************************************
 * variable declaration
 ****************************************************/
volatile struct XINTRUPT_REGS XIntruptRegs;
volatile Uint16 xint1Counter;	//this variable records latency counts from interrupt event to ISR
volatile Uint16 xint1Cycle;		//this variable cycles every 3 counts

/*******************************************************************************************
 * Function: InitXint1
 *
 * Description: This function initializes XINT1 with GPIO04 as interrupt source
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void InitXint1(void)
{
	EALLOW;			//don't forget protection
	GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = GPIO4;   // XINT1 source is GPIO04
	EDIS;

	// Configure XINT1
	XIntruptRegs.XINT1CR.bit.POLARITY = XINT_FALLING_EDGE;  // Falling edge interrupt
	XIntruptRegs.XINT1CR.bit.ENABLE = 1;        	// Enable XINT1

	xint1Cycle = 0;
}

/*******************************************************************************************
 * Function: Xint1_isr
 *
 * Description: This function services XINT1 interrupt
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
__interrupt void Xint1_isr(void)
{
	xint1Counter = XIntruptRegs.XINT1CTR;	//capture the count

	if (++xint1Cycle >= XINT1_CYCLE)
	{
		xint1Cycle = 0;
	}

	// Acknowledge this interrupt to service next interrupt from group 1
	// Must use the mask value, don't use bit value b/c of read-modify-write effect
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

#ifdef _DEBUG
	asm (" ESTOP0");						// Emulator Halt instruction for debug only
#endif
}

/*******************************************************************************************
 * Function: Xint1_isr
 *
 * Description: This function returns XINT1 interrupt count cycle
 *
 * Parameters: None
 *
 * Returns: Uint16
 *
 * Special Notes:
 *
 *******************************************************************************************/
Uint16 GetXint1Cycle(void)
{
	return xint1Cycle;
}
//--- end of file -----------------------------------------------------
