/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_Device.h
 * Description:	F2806x Device Definitions
 * Language:    TMS320F2806xM C
 * Author:		Louis Zhu
 * Created:		12/12/2014
 * Mod History: V1.0: Initial version developed on F28069ControlStick platform
 ****************************************************************************************/

#ifndef F2806x_DEVICE_H
#define F2806x_DEVICE_H

//---------------------------------------------------------------------------
// Constant Definitions
//

#define Device_cal (void (*)(void))0x3D7C80

//---------------------------------------------------------------------------
// Common CPU Definitions:
//
extern __cregister volatile unsigned int IFR;
extern __cregister volatile unsigned int IER;

#define  EINT   __asm(" clrc INTM")
#define  DINT   __asm(" setc INTM")
#define  ERTM   __asm(" clrc DBGM")
#define  DRTM   __asm(" setc DBGM")
#define  EALLOW __asm(" EALLOW")
#define  EDIS   __asm(" EDIS")
#define  ESTOP0 __asm(" ESTOP0")



//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use Following Data Type Size
// Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
//
/*
 * These types are also defined in DSP/BIOS 5.x's <std.h> and the
 * SYS/BIOS 6.x's <xdc/std.h> files.  We need to protect their
 * definition with the #ifndef/#define guard to avoid the duplicate
 * definition warning.
 *
 * SYS/BIOS requires that the <xdc/std.h> file be included before
 * any other .h files.
 */
#ifndef _TI_STD_TYPES
#define _TI_STD_TYPES

typedef int             Int;
typedef unsigned        Uns;
typedef char            Char;
typedef char            *String;
typedef void            *Ptr;

typedef enum eBoolean
{
	False = 0,
	True
} Bool;
typedef unsigned long   Uint32;
typedef unsigned int    Uint16;
typedef unsigned char   Uint8;
typedef float           Float32;
typedef long double     Float64;
typedef long            Int32;
typedef int             Int16;
typedef char            Int8;

#endif

//---------------------------------------------------------------------------
// Global Function References
//
extern void DelayUs(Uint16);

#endif

//===========================================================================
// End of file.
//===========================================================================
