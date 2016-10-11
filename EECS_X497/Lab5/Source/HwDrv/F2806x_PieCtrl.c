/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_PieCtrl.c
 * Description:	F2806x Device PIE Control Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/15/2014
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/

#include "F2806x_PieCtrl.h"
#include "F2806x_PieVect.h"

/****************************************************
 * #pragma section
 ****************************************************/
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");

/****************************************************
 * variable declaration
 ****************************************************/
volatile struct PIE_CTRL_REGS PieCtrlRegs;

/**********************************************************************
* Function: InitPieCtrl()
*
* Description: Initializes and enables the PIE interrupts on the F2806x
**********************************************************************/
void InitPieCtrl(void)
{
	// Disable Interrupts at the CPU level:
	//DINT;
	asm(" SETC INTM, DBGM");

	// Disable the PIE
	PieCtrlRegs.PIECTRL.bit.ENPIE = 0;

//--- Disable all PIE interrupts
	PieCtrlRegs.PIEIER1.all =  0x0000;
	PieCtrlRegs.PIEIER2.all =  0x0000;
	PieCtrlRegs.PIEIER3.all =  0x0000;
	PieCtrlRegs.PIEIER4.all =  0x0000;
	PieCtrlRegs.PIEIER5.all =  0x0000;
	PieCtrlRegs.PIEIER6.all =  0x0000;
	PieCtrlRegs.PIEIER7.all =  0x0000;
	PieCtrlRegs.PIEIER8.all =  0x0000;
	PieCtrlRegs.PIEIER9.all =  0x0000;
	PieCtrlRegs.PIEIER10.all = 0x0000;
	PieCtrlRegs.PIEIER11.all = 0x0000;
	PieCtrlRegs.PIEIER12.all = 0x0000;

//--- Clear any potentially pending PIEIFR flags
	PieCtrlRegs.PIEIFR1.all  = 0x0000;
	PieCtrlRegs.PIEIFR2.all  = 0x0000;
	PieCtrlRegs.PIEIFR3.all  = 0x0000;	
	PieCtrlRegs.PIEIFR4.all  = 0x0000;
	PieCtrlRegs.PIEIFR5.all  = 0x0000;
	PieCtrlRegs.PIEIFR6.all  = 0x0000;
	PieCtrlRegs.PIEIFR7.all  = 0x0000;
	PieCtrlRegs.PIEIFR8.all  = 0x0000;
	PieCtrlRegs.PIEIFR9.all  = 0x0000;
	PieCtrlRegs.PIEIFR10.all = 0x0000;
	PieCtrlRegs.PIEIFR11.all = 0x0000;
	PieCtrlRegs.PIEIFR12.all = 0x0000;
}

/*******************************************************************************************
 * Function: EnablePieInterrupts
 *
 * Description: This function enables the PIE module and CPU interrupts
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *     1 -
 *
 *******************************************************************************************/
void EnablePieInterrupts(void)
{
	//Enable ADCINT1 in PIE group 1
	PieCtrlRegs.PIEIER1.bit.INTx1 = 1;

	//Clears the Ack bits to enable PIE to drive a pulse into the CPU
	PieCtrlRegs.PIEACK.all = 0xFFFF;

    //Enable the PIE
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;

    // Enable PIE group 1 interrupt 1 for XINT1
    PieCtrlRegs.PIEIER1.bit.INTx4 = 1;

	// Enable CPU INT1
	IER |= M_INT1;

	// Enable global Interrupts
	EINT;

	// Enable higher priority real-time debug events DBGM
	ERTM;
}

//--- end of file -----------------------------------------------------
