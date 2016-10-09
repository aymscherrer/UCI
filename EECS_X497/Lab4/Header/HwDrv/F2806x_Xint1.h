/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_Xint.h
 * Description:	F2806x Device External Interrupt 1 Driver Definitions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/15/2014
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/
#ifndef F2806x_XINT1_H
#define F2806x_XINT1_H

#define XINT1_CYCLE		3

/*******************************************************************************************
 Data Type Definitions
 *******************************************************************************************/
struct XINTCR_BITS {		//bit   discription
    Uint16   ENABLE:1;    	// 0    enable/disable
    Uint16   rsvd1:1;     	// 1    reserved
    Uint16   POLARITY:2;  	// 3:2  pos/neg, both triggered
    Uint16   rsvd2:12;    	//15:4  reserved
};

union XINTCR_REG {
   Uint16               all;
   struct XINTCR_BITS   bit;
};

//---------------------------------------------------------------------------
// External Interrupt Register File:
//
struct XINTRUPT_REGS {
   union XINTCR_REG XINT1CR;
   union XINTCR_REG XINT2CR;
   union XINTCR_REG XINT3CR;
   Uint16           rsvd1[5];
   Uint16           XINT1CTR;
   Uint16           XINT2CTR;
   Uint16           XINT3CTR;
   Uint16           rsvd2[5];
};

//XINT edge enum
enum tXintEdgeTypeEnum
{
	XINT_FALLING_EDGE = 0,	//falling edge type
	XINT_RISING_EDGE		//rising edge type
};

//---------------------------------------------------------------------------
// Global Function References
//
void InitXint1(void);
__interrupt void Xint1_isr(void);
Uint16 GetXint1Cycle(void);
#endif

//===========================================================================
// End of file.
//===========================================================================
