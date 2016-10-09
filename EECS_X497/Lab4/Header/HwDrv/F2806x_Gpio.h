/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_Gpio.h
 * Description:	F2806x Device GPIO Register Definitions
 * Language:    TMS320F2806xM C
 * Author:		Louis Zhu
 * Created:		12/18/2014
 * Mod History: V1.0: Initial version developed on F28069ControlStick platform
 ****************************************************************************************/
#ifndef F2806x_GPIO_H
#define F2806x_GPIO_H

#include "F2806x_Gpio.h"               // General Purpose I/O Registers
#include "F2806x_Device.h"

//---------------------------------------------------------------------------
// GPIO Individual Register Bit Definitions:

struct GPACTRL_BITS {     	// bits description
	Uint16	QUALPRD0:8;		// 7:0		GPIO0 to 7 Qual Cycles
	Uint16	QUALPRD1:8;		// 15:8		GPIO8 to 15 Qual Cycles
	Uint16	QUALPRD2:8;		// 23:16	GPIO16 to 23 Qual Cycles
	Uint16	QUALPRD3:8;		// 31:24	GPIO24 to 31 Qual Cycles
};

union GPACTRL_REG {
	Uint32 all;
	struct GPACTRL_BITS	bit;
};

struct GPACTRL2_BITS {		// bits description
	Uint16	USB0IOEN:1;		// 0	USB I/O Enable Bit
	Uint16	rsvd1:15;		// 15:1	Reserved
};

union GPACTRL2_REG {
	Uint16	all;
	struct GPACTRL2_BITS	bit;
};

struct GPBCTRL_BITS {     // bits description
	Uint16	QUALPRD0:8;			// 7:0	GPIO32 to 39 Qual Cycles
	Uint16	QUALPRD1:8;			// 15:8	GPIO40 to 47 Qual Cycles
	Uint16	QUALPRD2:8;			// 23:16	GPIO48 to 55 Qual Cycles
	Uint16	QUALPRD3:8;			// 31:24	GPIO56 to 63 Qual Cycles
};

union GPBCTRL_REG {
	Uint32 all;
	struct GPBCTRL_BITS	bit;
};

struct GPA1_BITS {     // bits description
	Uint16	GPIO0:2;			// 1:0	GPIO0
	Uint16	GPIO1:2;			// 3:2	GPIO1
	Uint16	GPIO2:2;			// 5:4	GPIO2
	Uint16	GPIO3:2;			// 7:6	GPIO3
	Uint16	GPIO4:2;			// 9:8	GPIO4
	Uint16	GPIO5:2;			// 11:10	GPIO5
	Uint16	GPIO6:2;			// 13:12	GPIO6
	Uint16	GPIO7:2;			// 15:14	GPIO7
	Uint16	GPIO8:2;			// 17:16	GPIO8
	Uint16	GPIO9:2;			// 19:18	GPIO9
	Uint16	GPIO10:2;			// 21:20	GPIO10
	Uint16	GPIO11:2;			// 23:22	GPIO11
	Uint16	GPIO12:2;			// 25:24	GPIO12
	Uint16	GPIO13:2;			// 27:26	GPIO13
	Uint16	GPIO14:2;			// 29:28	GPIO14
	Uint16	GPIO15:2;			// 31:30	GPIO15
};

union GPA1_REG {
	Uint32 all;
	struct GPA1_BITS	bit;
};

struct GPA2_BITS {     // bits description
	Uint16	GPIO16:2;			// 1:0	GPIO16
	Uint16	GPIO17:2;			// 3:2	GPIO17
	Uint16	GPIO18:2;			// 5:4	GPIO18
	Uint16	GPIO19:2;			// 7:6	GPIO19
	Uint16	GPIO20:2;			// 9:8	GPIO20
	Uint16	GPIO21:2;			// 11:10	GPIO21
	Uint16	GPIO22:2;			// 13:12	GPIO22
	Uint16	GPIO23:2;			// 15:14	GPIO23
	Uint16	GPIO24:2;			// 17:16	GPIO24
	Uint16	GPIO25:2;			// 19:18	GPIO25
	Uint16	GPIO26:2;			// 21:20	GPIO26
	Uint16	GPIO27:2;			// 23:22	GPIO27
	Uint16	GPIO28:2;			// 25:24	GPIO28
	Uint16	GPIO29:2;			// 27:26	GPIO29
	Uint16	GPIO30:2;			// 29:28	GPIO30
	Uint16	GPIO31:2;			// 31:30	GPIO31
};

union GPA2_REG {
	Uint32 all;
	struct GPA2_BITS	bit;
};

struct GPB1_BITS {     // bits description
	Uint16	GPIO32:2;			// 1:0	GPIO32
	Uint16	GPIO33:2;			// 3:2	GPIO33
	Uint16	GPIO34:2;			// 5:4	GPIO34
	Uint16	GPIO35:2;			// 7:6	GPIO35
	Uint16	GPIO36:2;			// 9:8	GPIO36
	Uint16	GPIO37:2;			// 11:10	GPIO37
	Uint16	GPIO38:2;			// 13:12	GPIO38
	Uint16	GPIO39:2;			// 15:14	GPIO39
	Uint16	GPIO40:2;			// 17:16	GPIO40
	Uint16	GPIO41:2;			// 19:18	GPIO41
	Uint16	GPIO42:2;			// 21:20	GPIO42
	Uint16	GPIO43:2;			// 23:22	GPIO43
	Uint16	GPIO44:2;			// 25:24	GPIO44
	Uint16	rsvd1:6;			// 31:26	Reserved
};

union GPB1_REG {
	Uint32 all;
	struct GPB1_BITS	bit;
};

struct GPB2_BITS {     // bits description
	Uint16	rsvd1:4;			// 3:0	Reserved
	Uint16	GPIO50:2;			// 5:4	GPIO50
	Uint16	GPIO51:2;			// 7:6	GPIO51
	Uint16	GPIO52:2;			// 9:8	GPIO52
	Uint16	GPIO53:2;			// 11:10	GPIO53
	Uint16	GPIO54:2;			// 13:12	GPIO54
	Uint16	GPIO55:2;			// 15:14	GPIO55
	Uint16	GPIO56:2;			// 17:16	GPIO56
	Uint16	GPIO57:2;			// 19:18	GPIO57
	Uint16	GPIO58:2;			// 21:20	GPIO58
	Uint16	rsvd2:10;			// 31:22	Reserved
};

union GPB2_REG {
	Uint32 all;
	struct GPB2_BITS	bit;
};

struct AIO_BITS {     // bits description
	Uint16	rsvd1:2;			// 1:0	Reserved
	Uint16	rsvd2:2;			// 3:2	Reserved
	Uint16	AIO2:2;				// 5:4	AIO2
	Uint16	rsvd3:2;			// 7:6	Reserved
	Uint16	AIO4:2;				// 9:8	AIO4
	Uint16	rsvd4:2;			// 11:10	Reserved
	Uint16	AIO6:2;				// 13:12	AIO6
	Uint16	rsvd5:2;			// 15:14	Reserved
	Uint16	rsvd6:2;			// 17:16	Reserved
	Uint16	rsvd7:2;			// 19:18	Reserved
	Uint16	AIO10:2;			// 21:20	AIO10
	Uint16	rsvd8:2;			// 23:22	Reserved
	Uint16	AIO12:2;			// 25:24	AIO12
	Uint16	rsvd9:2;			// 27:26	Reserved
	Uint16	AIO14:2;			// 29:28	AIO14
	Uint16	rsvd10:2;			// 31:30	Reserved
};

union AIO_REG {
	Uint32 all;
	struct AIO_BITS	bit;
};

struct GPADAT_BITS {     // bits description
	Uint16	GPIO0:1;			// 0	GPIO0 Data
	Uint16	GPIO1:1;			// 1	GPIO1 Data
	Uint16	GPIO2:1;			// 2	GPIO2 Data
	Uint16	GPIO3:1;			// 3	GPIO3 Data
	Uint16	GPIO4:1;			// 4	GPIO4 Data
	Uint16	GPIO5:1;			// 5	GPIO5 Data
	Uint16	GPIO6:1;			// 6	GPIO6 Data
	Uint16	GPIO7:1;			// 7	GPIO7 Data
	Uint16	GPIO8:1;			// 8	GPIO8 Data
	Uint16	GPIO9:1;			// 9	GPIO9 Data
	Uint16	GPIO10:1;			// 10	GPIO10 Data
	Uint16	GPIO11:1;			// 11	GPIO11 Data
	Uint16	GPIO12:1;			// 12	GPIO12 Data
	Uint16	GPIO13:1;			// 13	GPIO13 Data
	Uint16	GPIO14:1;			// 14	GPIO14 Data
	Uint16	GPIO15:1;			// 15	GPIO15 Data
	Uint16	GPIO16:1;			// 16	GPIO16 Data
	Uint16	GPIO17:1;			// 17	GPIO17 Data
	Uint16	GPIO18:1;			// 18	GPIO18 Data
	Uint16	GPIO19:1;			// 19	GPIO19 Data
	Uint16	GPIO20:1;			// 20	GPIO20 Data
	Uint16	GPIO21:1;			// 21	GPIO21 Data
	Uint16	GPIO22:1;			// 22	GPIO22 Data
	Uint16	GPIO23:1;			// 23	GPIO23 Data
	Uint16	GPIO24:1;			// 24	GPIO24 Data
	Uint16	GPIO25:1;			// 25	GPIO25 Data
	Uint16	GPIO26:1;			// 26	GPIO26 Data
	Uint16	GPIO27:1;			// 27	GPIO27 Data
	Uint16	GPIO28:1;			// 28	GPIO28 Data
	Uint16	GPIO29:1;			// 29	GPIO29 Data
	Uint16	GPIO30:1;			// 30	GPIO30 Data
	Uint16	GPIO31:1;			// 31	GPIO31 Data
};

union GPADAT_REG {
	Uint32 all;
	struct GPADAT_BITS	bit;
};

struct GPBDAT_BITS {     // bits description
	Uint16	GPIO32:1;			// 0	GPIO32 Data
	Uint16	GPIO33:1;			// 1	GPIO33 Data
	Uint16	GPIO34:1;			// 2	GPIO34 Data
	Uint16	GPIO35:1;			// 3	GPIO35 Data
	Uint16	GPIO36:1;			// 4	GPIO36 Data
	Uint16	GPIO37:1;			// 5	GPIO37 Data
	Uint16	GPIO38:1;			// 6	GPIO38 Data
	Uint16	GPIO39:1;			// 7	GPIO39 Data
	Uint16	GPIO40:1;			// 8	GPIO40 Data
	Uint16	GPIO41:1;			// 9	GPIO41 Data
	Uint16	GPIO42:1;			// 10	GPIO42 Data
	Uint16	GPIO43:1;			// 11	GPIO43 Data
	Uint16	GPIO44:1;			// 12	GPIO44 Data
	Uint16	rsvd1:3;			// 15:13	Reserved
	Uint16	rsvd2:2;			// 17:16	Reserved
	Uint16	GPIO50:1;			// 18	GPIO50 Data
	Uint16	GPIO51:1;			// 19	GPIO51 Data
	Uint16	GPIO52:1;			// 20	GPIO52 Data
	Uint16	GPIO53:1;			// 21	GPIO53 Data
	Uint16	GPIO54:1;			// 22	GPIO54 Data
	Uint16	GPIO55:1;			// 23	GPIO55 Data
	Uint16	GPIO56:1;			// 24	GPIO56 Data
	Uint16	GPIO57:1;			// 25	GPIO57 Data
	Uint16	GPIO58:1;			// 26	GPIO58 Data
	Uint16	rsvd3:5;			// 31:27	Reserved
};

union GPBDAT_REG {
	Uint32 all;
	struct GPBDAT_BITS	bit;
};

struct AIODAT_BITS {     // bits description
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	rsvd2:1;			// 1	Reserved
	Uint16	AIO2:1;				// 2	AIO2
	Uint16	rsvd3:1;			// 3	Reserved
	Uint16	AIO4:1;				// 4	AIO4
	Uint16	rsvd4:1;			// 5	Reserved
	Uint16	AIO6:1;				// 6	AIO6
	Uint16	rsvd5:1;			// 7	Reserved
	Uint16	rsvd6:1;			// 8	Reserved
	Uint16	rsvd7:1;			// 9	Reserved
	Uint16	AIO10:1;			// 10	AIO10
	Uint16	rsvd8:1;			// 11	Reserved
	Uint16	AIO12:1;			// 12	AIO12
	Uint16	rsvd9:1;			// 13	Reserved
	Uint16	AIO14:1;			// 14	AIO14
	Uint16	rsvd10:1;			// 15	Reserved
	Uint16	rsvd11:16;			// 31:16 Reserved
};

union AIODAT_REG {
	Uint32 all;
	struct AIODAT_BITS	bit;
};

struct GPIOXINT_BITS {     // bits description
	Uint16	GPIOSEL:5;			// 4:0	Select GPIO Interrupt Input Source
	Uint16	rsvd1:11;			// 15:5	Reserved
};

union GPIOXINT_REG {
	Uint16 all;
	struct GPIOXINT_BITS	bit;
};

struct GPIO_CTRL_REGS {
	union	GPACTRL_REG		GPACTRL;	// GPIO A Control Register (GPIO0 to 31)
	union	GPA1_REG		GPAQSEL1;	// GPIO A Qualifier Select 1 Register (GPIO0 to 15)
	union	GPA2_REG		GPAQSEL2;	// GPIO A Qualifier Select 2 Register (GPIO16 to 31)
	union	GPA1_REG		GPAMUX1;	// GPIO A Mux 1 Register (GPIO0 to 15)
	union	GPA2_REG		GPAMUX2;	// GPIO A Mux 2 Register (GPIO16 to 31)
	union	GPADAT_REG		GPADIR;		// GPIO A Direction Register (GPIO0 to 31) )
	union	GPADAT_REG		GPAPUD;		// GPIO A Pull-Up Disable Register
	union	GPACTRL2_REG	GPACTRL2;	// GPIO A Control Register 2
	Uint16					rsvd1;		// Reserved
	union	GPBCTRL_REG		GPBCTRL;	// GPIO B Control Register (GPIO32 to 63)
	union	GPB1_REG		GPBQSEL1;	// GPIO B Qualifier Select 1 Register (GPIO32 to 47)
	union	GPB2_REG		GPBQSEL2;	// GPIO B Qualifier Select 2 Register (GPIO48 to 63)
	union	GPB1_REG		GPBMUX1;	// GPIO B Mux 1 Register (GPIO32 to 47)
	union	GPB2_REG		GPBMUX2;	// GPIO B Mux 2 Register (GPIO48 to 63)
	union	GPBDAT_REG		GPBDIR;		// GPIO B Direction Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBPUD;		// GPIO B Pull-Up Disable Register
	Uint16					rsvd2[24];	// Reserved
	union	AIO_REG			AIOMUX1;	// Analog IO Mux 1 Register
	Uint16					rsvd3[2];	// Reserved
	union	AIODAT_REG		AIODIR;		// Analog IO Direction Register
	Uint16					rsvd4[4];	// Reserved
};

struct GPIO_DATA_REGS {
	union	GPADAT_REG		GPADAT;		// GPIO A Data Register (GPIO0 to 31)
	union	GPADAT_REG		GPASET;		// GPIO A Data Set Register (GPIO0 to 31)
	union	GPADAT_REG		GPACLEAR;	// GPIO A Data Clear Register (GPIO0 to 31)
	union	GPADAT_REG		GPATOGGLE;	// GPIO A Data Toggle Register (GPIO0 to 31)
	union	GPBDAT_REG		GPBDAT;		// GPIO B Data Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBSET;		// GPIO B Data Set Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBCLEAR;	// GPIO B Data Clear Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBTOGGLE;	// GPIO B Data Toggle Register (GPIO32 to 63)
	Uint16					rsvd1[8];	// Reserved
	union	AIODAT_REG		AIODAT;		// Analog IO Data Register (AIO0 to 15)
	union	AIODAT_REG		AIOSET;		// Analog IO Data Set Register (AIO0 to 15)
	union	AIODAT_REG		AIOCLEAR;	// Analog IO Data Clear Register (AIO0 to 15)
	union	AIODAT_REG		AIOTOGGLE;	// Analog IO Data Toggle Register (AIO0 to 15)
};

struct GPIO_INT_REGS {
	union	GPIOXINT_REG	GPIOXINT1SEL;	// XINT1 GPIO Input Select Register (GPIO0 to 31)
	union	GPIOXINT_REG	GPIOXINT2SEL;	// GPTRIP2 (TZ2n) Input Select Register (GPIO0 to 63)
	union	GPIOXINT_REG	GPIOXINT3SEL;	// GPTRIP3 (TZ3n) Input Select Register (GPIO0 to 63)
	Uint16					rsvd1[5];		// Reserved
	union	GPADAT_REG		GPIOLPMSEL;		// GPTRIP5 (XINT2) Input Select Register (GPIO0 to 63)
	Uint16					rsvd2[22];		// Reserved
};

//GPIO Pin Enum
enum tGpioPinEnum
{
	GPIO0 = 0,	//GPIO0
	GPIO1,		//GPIO1
	GPIO2,		//GPIO2
	GPIO3,		//GPIO3
	GPIO4,		//GPIO4
	GPIO5,		//GPIO5
	GPIO6,		//GPIO6
	GPIO7,		//GPIO7
	GPIO8,		//GPIO8
	GPIO9,		//GPIO9
	GPIO10,		//GPIO10
	GPIO11,		//GPIO11
	GPIO12,		//GPIO12
	GPIO13,		//GPIO13
	GPIO14,		//GPIO14
	GPIO15,		//GPIO15
	GPIO16,		//GPIO16
	GPIO17,		//GPIO17
	GPIO18,		//GPIO18
	GPIO19,		//GPIO19
	GPIO20,		//GPIO20
	GPIO21,		//GPIO21
	GPIO22,		//GPIO22
	GPIO23,		//GPIO23
	GPIO24,		//GPIO24
	GPIO25,		//GPIO25
	GPIO26,		//GPIO26
	GPIO27,		//GPIO27
	GPIO28,		//GPIO28
	GPIO29,		//GPIO29
	GPIO30,		//GPIO30
	GPIO31		//GPIO31
};
//GPIO0 mux enum
enum tGpio0MuxEnum
{
	GPIO0_MUX_GPIO = 0,		//configured as GPIO
	GPIO0_MUX_EPWM1A		//configured as EPWM1A
};

//GPIO1 mux enum
enum tGpio1MuxEnum
{
	GPIO1_MUX_GPIO = 0,		//configured as GPIO
	GPIO1_MUX_EPWM1B,		//configured as EPWM1B
	GPIO1_MUX_RSVD,			//reserved
	GPIO1_MUX_COMP1OUT		//configured as COMP1OUT
};

//GPIO2 mux enum
enum tGpio2MuxEnum
{
	GPIO2_MUX_GPIO = 0,		//configured as GPIO
	GPIO2_MUX_EPWM2A		//configured as EPWM2A
};

//GPIO3 mux enum
enum tGpio3MuxEnum
{
	GPIO3_MUX_GPIO = 0,		//configured as GPIO
	GPIO3_MUX_EPWM2B,		//configured as EPWM1B
	GPIO3_MUX_SPISOMIA,		//configured as SPISOMIA
	GPIO3_MUX_COMP2OUT		//configured as COMP2OUT
};

//GPIO4 mux enum
enum tGpio4MuxEnum
{
	GPIO4_MUX_GPIO = 0,		//configured as GPIO
	GPIO4_MUX_EPWM3A		//configured as EPWM3A
};

//GPIO5 mux enum
enum tGpio5MuxEnum
{
	GPIO5_MUX_GPIO = 0,		//configured as GPIO
	GPIO5_MUX_EPWM3B,		//configured as EPWM3B
	GPIO5_MUX_SPISIMOA,		//configured as SPISIMOA
	GPIO5_MUX_ECAP1			//configured as ECAP1
};

//GPIO6 mux enum
enum tGpio6MuxEnum
{
	GPIO6_MUX_GPIO = 0,		//configured as GPIO
	GPIO6_MUX_EPWM4A,		//configured as EPWM4A
	GPIO6_MUX_EPWMSYNCI,	//configured as EPWMSYNCI
	GPIO6_MUX_EPWMSYNCO		//configured as EPWMSYNCO
};

//GPIO7 mux enum
enum tGpio7MuxEnum
{
	GPIO7_MUX_GPIO = 0,		//configured as GPIO
	GPIO7_MUX_EPWM4B,		//configured as EPWM4B
	GPIO7_MUX_SCIRXDA,		//configured as SCIRXDA
	GPIO7_MUX_ECAP2			//configured as ECAP2
};

//GPIO8 mux enum
enum tGpio8MuxEnum
{
	GPIO8_MUX_GPIO = 0,		//configured as GPIO
	GPIO8_MUX_EPWM5A,		//configured as EPWM5A
	GPIO8_RSVD,				//Reserved
	GPIO8_MUX_ADCSOCAO		//configured as ADCSOCAO
};

//GPIO9 mux enum
enum tGpio9MuxEnum
{
	GPIO9_MUX_GPIO = 0,		//configured as GPIO
	GPIO9_MUX_EPWM5B,		//configured as EPWM5B
	GPIO9_MUX_SCITXDB,		//configured as SCITXDB
	GPIO9_MUX_ECAP3			//configured as ECAP3
};

//GPIO10 mux enum
enum tGpio10MuxEnum
{
	GPIO10_MUX_GPIO = 0,	//configured as GPIO
	GPIO10_MUX_EPWM6A,		//configured as EPWM6A
	GPIO10_RSVD,			//Reserved
	GPIO10_MUX_ADCSOCBO		//configured as ADCSOCBO
};

//GPIO11 mux enum
enum tGpio11MuxEnum
{
	GPIO11_MUX_GPIO = 0,	//configured as GPIO
	GPIO11_MUX_EPWM6B,		//configured as EPWM6B
	GPIO11_MUX_SCIRXDB,		//configured as SCIRXDB
	GPIO11_MUX_ECAP1		//configured as ECAP1
};

//GPIO12 mux enum
enum tGpio12MuxEnum
{
	GPIO12_MUX_GPIO = 0,	//configured as GPIO
	GPIO12_MUX_TZ1,			//configured as TZ1
	GPIO12_MUX_SCITXDA,		//configured as SCITXDA
	GPIO12_MUX_SPISIMOB		//configured as SPISIMOB
};

//GPIO13 mux enum
enum tGpio13MuxEnum
{
	GPIO13_MUX_GPIO = 0,	//configured as GPIO
	GPIO13_MUX_TZ2,			//configured as TZ2
	GPIO13_RSVD,			//Reserved
	GPIO13_MUX_SPISOMIB		//configured as SPISOMIB
};

//GPIO14 mux enum
enum tGpio14MuxEnum
{
	GPIO14_MUX_GPIO = 0,	//configured as GPIO
	GPIO14_MUX_TZ3,			//configured as TZ3
	GPIO14_MUX_SCITXDB,		//configured as SCITXDB
	GPIO14_MUX_SPICLKB		//configured as SPICLKB
};

//GPIO15 mux enum
enum tGpio15MuxEnum
{
	GPIO15_MUX_GPIO = 0,	//configured as GPIO
	GPIO15_MUX_ECAP2,		//configured as ECAP2
	GPIO15_MUX_SCIRXDB,		//configured as SCIRXDB
	GPIO15_MUX_SPISTEB		//configured as SPISTEB
};

//GPIO16 mux enum
enum tGpio16MuxEnum
{
	GPIO16_MUX_GPIO = 0,	//configured as GPIO
	GPIO16_MUX_SPISIMOA,	//configured as SPISIMOA
	GPIO16_RSVD,			//reserved
	GPIO16_MUX_TZ2			//configured as TZ2
};

//GPIO17 mux enum
enum tGpio17MuxEnum
{
	GPIO17_MUX_GPIO = 0,	//configured as GPIO
	GPIO17_MUX_SPISOMIA,	//configured as SPISOMIA
	GPIO17_RSVD,			//reserved
	GPIO17_MUX_TZ3			//configured as TZ3
};

//GPIO18 mux enum
enum tGpio18MuxEnum
{
	GPIO18_MUX_GPIO = 0,	//configured as GPIO
	GPIO18_MUX_SPICLKA,		//configured as SPICLKA
	GPIO18_MUX_SCITXDB,		//configured as SCITXDB
	GPIO18_MUX_XCLKOUT		//configured as XCLKOUT
};

//GPIO19 mux enum
enum tGpio19MuxEnum
{
	GPIO19_MUX_GPIO_XCLKIN = 0,	//configured as GPIO/XCLKIN
	GPIO19_MUX_SPISTEA,		//configured as SPISTEA
	GPIO19_MUX_SCIRXDB,		//configured as SCIRXDB
	GPIO19_MUX_ECAP1		//configured as ECAP1
};

//GPIO20 mux enum
enum tGpio20MuxEnum
{
	GPIO20_MUX_GPIO = 0,	//configured as GPIO
	GPIO20_MUX_EQEP1A,		//configured as EQEP1A
	GPIO20_MUX_MDXA,		//configured as MDXA
	GPIO20_MUX_COMP1OUT		//configured as COMP1OUT
};

//GPIO21 mux enum
enum tGpio21MuxEnum
{
	GPIO21_MUX_GPIO = 0,	//configured as GPIO
	GPIO21_MUX_EQEP1B,		//configured as EQEP1B
	GPIO21_MUX_MDRA,		//configured as MDRA
	GPIO21_MUX_COMP2OUT		//configured as COMP2OUT
};

//GPIO22 mux enum
enum tGpio22MuxEnum
{
	GPIO22_MUX_GPIO = 0,	//configured as GPIO
	GPIO22_MUX_EQEP1S,		//configured as EQEP1S
	GPIO22_MUX_MCLKXA,		//configured as MCLKXA
	GPIO22_MUX_SCITXDB		//configured as SCITXDB
};

//GPIO23 mux enum
enum tGpio23MuxEnum
{
	GPIO23_MUX_GPIO = 0,	//configured as GPIO
	GPIO23_MUX_EQEP1I,		//configured as EQEP1I
	GPIO23_MUX_MFSXA,		//configured as MFSXA
	GPIO23_MUX_SCIRXDB		//configured as SCIRXDB
};

//GPIO24 mux enum
enum tGpio24MuxEnum
{
	GPIO24_MUX_GPIO = 0,	//configured as GPIO
	GPIO24_MUX_ECAP1,		//configured as ECAP1
	GPIO24_MUX_EQEP2A,		//configured as EQEP2A
	GPIO24_MUX_SPISIMOB		//configured as SPISIMOB
};

//GPIO25 mux enum
enum tGpio25MuxEnum
{
	GPIO25_MUX_GPIO = 0,	//configured as GPIO
	GPIO25_MUX_ECAP2,		//configured as ECAP2
	GPIO25_MUX_EQEP2B,		//configured as EQEP2B
	GPIO25_MUX_SPISOMIB		//configured as SPISOMIB
};

//GPIO26 mux enum
enum tGpio26MuxEnum
{
	GPIO26_MUX_GPIO = 0,	//configured as GPIO
	GPIO26_MUX_ECAP3,		//configured as ECAP3
	GPIO26_MUX_EQEP2I,		//configured as EQEP2I
	GPIO26_MUX_SPICLKB		//configured as SPICLKB
};

//GPIO27 mux enum
enum tGpio27MuxEnum
{
	GPIO27_MUX_GPIO = 0,	//configured as GPIO
	GPIO27_MUX_HRCAP2,		//configured as HRCAP2
	GPIO27_MUX_EQEP2S,		//configured as EQEP2S
	GPIO27_MUX_SPISTEB		//configured as SPISTEB
};

//GPIO28 mux enum
enum tGpio28MuxEnum
{
	GPIO28_MUX_GPIO = 0,	//configured as GPIO
	GPIO28_MUX_SCIRXDA,		//configured as SCIRXDA
	GPIO28_MUX_SDAA,		//configured as SDAA
	GPIO28_MUX_TZ2			//configured as TZ2
};

//GPIO29 mux enum
enum tGpio29MuxEnum
{
	GPIO29_MUX_GPIO = 0,	//configured as GPIO
	GPIO29_MUX_SCITXDA,		//configured as SCITXDA
	GPIO29_MUX_SCLA,		//configured as SCLA
	GPIO29_MUX_TZ3			//configured as TZ3
};

//GPIO30 mux enum
enum tGpio30MuxEnum
{
	GPIO30_MUX_GPIO = 0,	//configured as GPIO
	GPIO30_MUX_CANRXA,		//configured as CANRXA
	GPIO30_MUX_EQEP2I,		//configured as EQEP2I
	GPIO30_MUX_EPWM7A		//configured as EPWM7A
};

//GPIO31 mux enum
enum tGpio31MuxEnum
{
	GPIO31_MUX_GPIO = 0,	//configured as GPIO
	GPIO31_MUX_CANTXA,		//configured as CANTXA
	GPIO31_MUX_EQEP2S,		//configured as EQEP2S
	GPIO31_MUX_EPWM8A		//configured as EPWM8A
};

//GPIO32 mux enum
enum tGpio32MuxEnum
{
	GPIO32_MUX_GPIO = 0,	//configured as GPIO
	GPIO32_MUX_SDAA,		//configured as SDAA
	GPIO32_MUX_EPWMSYNCI,	//configured as EPWMSYNCI
	GPIO32_MUX_ADCSOCAO		//configured as ADCSOCAO
};

//GPIO33 mux enum
enum tGpio33MuxEnum
{
	GPIO33_MUX_GPIO = 0,	//configured as GPIO
	GPIO33_MUX_SCLA,		//configured as SCLA
	GPIO33_MUX_EPWMSYNCO,	//configured as EPWMSYNCO
	GPIO33_MUX_ADCSOCBO		//configured as ADCSOCBO
};

//GPIO34 mux enum
enum tGpio34MuxEnum
{
	GPIO34_MUX_GPIO = 0,	//configured as GPIO
	GPIO34_MUX_COMP2OUT,	//configured as COMP2OUT
	GPIO34_RSVD,			//Reserved
	GPIO34_MUX_COMP3OUT		//configured as COMP3OUT
};

//GPIO35 mux enum
enum tGpio35MuxEnum
{
	GPIO35_MUX_GPIO_TDI = 0		//configured as GPIO (TDI)
};

//GPIO36 mux enum
enum tGpio36MuxEnum
{
	GPIO36_MUX_GPIO_TMS = 0		//configured as GPIO (TMS)
};

//GPIO37 mux enum
enum tGpio37MuxEnum
{
	GPIO37_MUX_GPIO_TDO = 0		//configured as GPIO (TDO)
};

//GPIO38 mux enum
enum tGpio38MuxEnum
{
	GPIO38_MUX_GPIO_XCLKIN = 0		//configured as GPIO/XCLKIN (TCK)
};

//GPIO39 mux enum
enum tGpio39MuxEnum
{
	GPIO39_MUX_GPIO = 0		//configured as GPIO
};

//GPIO40 mux enum
enum tGpio40MuxEnum
{
	GPIO40_MUX_GPIO = 0,	//configured as GPIO
	GPIO40_MUX_EPWM7A,		//configured as EPWM7A
	GPIO40_MUX_SCITXDB		//configured as SCITXDB
};

//GPIO41 mux enum
enum tGpio41MuxEnum
{
	GPIO41_MUX_GPIO = 0,	//configured as GPIO
	GPIO41_MUX_EPWM7B,		//configured as EPWM7B
	GPIO41_MUX_SCIRXDB		//configured as SCIRXDB
};

//GPIO42 mux enum
enum tGpio42MuxEnum
{
	GPIO42_MUX_GPIO = 0,	//configured as GPIO
	GPIO42_MUX_EPWM8A,		//configured as EPWM8A
	GPIO42_MUX_TZ1,			//configured as TZ1
	GPIO42_MUX_COMP1OUT		//configured as COMP1OUT
};

//GPIO43 mux enum
enum tGpio43MuxEnum
{
	GPIO43_MUX_GPIO = 0,	//configured as GPIO
	GPIO43_MUX_EPWM8B,		//configured as EPWM8B
	GPIO43_MUX_TZ2,			//configured as TZ2
	GPIO43_MUX_COMP2OUT		//configured as COMP2OUT
};

//GPIO44 mux enum
enum tGpio44MuxEnum
{
	GPIO44_MUX_GPIO = 0,	//configured as GPIO
	GPIO44_MUX_MFSRA,		//configured as MFSRA
	GPIO44_MUX_SCIRXDB,		//configured as SCIRXDB
	GPIO44_MUX_EPWM7B		//configured as EPWM7B
};

//GPIO50 mux enum
enum tGpio50MuxEnum
{
	GPIO50_MUX_GPIO = 0,	//configured as GPIO
	GPIO50_MUX_EQEP1A,		//configured as EQEP1A
	GPIO50_MUX_MDXA,		//configured as MDXA
	GPIO50_MUX_TZ1			//configured as TZ1
};

//GPIO51 mux enum
enum tGpio51MuxEnum
{
	GPIO51_MUX_GPIO = 0,	//configured as GPIO
	GPIO51_MUX_EQEP1B,		//configured as EQEP1B
	GPIO51_MUX_MDRA,		//configured as MDRA
	GPIO51_MUX_TZ2			//configured as TZ2
};

//GPIO52 mux enum
enum tGpio52MuxEnum
{
	GPIO52_MUX_GPIO = 0,	//configured as GPIO
	GPIO52_MUX_EQEP1S,		//configured as EQEP1S
	GPIO52_MUX_MCLKXA,		//configured as MCLKXA
	GPIO52_MUX_TZ3			//configured as TZ3
};

//GPIO53 mux enum
enum tGpio53MuxEnum
{
	GPIO53_MUX_GPIO = 0,	//configured as GPIO
	GPIO53_MUX_EQEP1I,		//configured as EQEP1I
	GPIO53_MUX_MFSXA		//configured as MFSXA
};

//GPIO54 mux enum
enum tGpio54MuxEnum
{
	GPIO54_MUX_GPIO = 0,	//configured as GPIO
	GPIO54_MUX_SPISIMOA,	//configured as SPISIMOA
	GPIO54_MUX_EQEP2A,		//configured as EQEP2A
	GPIO54_MUX_HRCAP1		//configured as HRCAP1
};

//GPIO55 mux enum
enum tGpio55MuxEnum
{
	GPIO55_MUX_GPIO = 0,	//configured as GPIO
	GPIO55_MUX_SPISOMIA,	//configured as SPISOMIA
	GPIO55_MUX_EQEP2B,		//configured as EQEP2B
	GPIO55_MUX_HRCAP2		//configured as HRCAP2
};

//GPIO56 mux enum
enum tGpio56MuxEnum
{
	GPIO56_MUX_GPIO = 0,	//configured as GPIO
	GPIO56_MUX_SPICLKA,		//configured as SPICLKA
	GPIO56_MUX_EQEP2I,		//configured as EQEP2I
	GPIO56_MUX_HRCAP3		//configured as HRCAP3
};

//GPIO57 mux enum
enum tGpio57MuxEnum
{
	GPIO57_MUX_GPIO = 0,	//configured as GPIO
	GPIO57_MUX_SPISTEA,		//configured as SPISTEA
	GPIO57_MUX_EQEP2S,		//configured as EQEP2S
	GPIO57_MUX_HRCAP4		//configured as HRCAP4
};

//GPIO58 mux enum
enum tGpio58MuxEnum
{
	GPIO58_MUX_GPIO = 0,	//configured as GPIO
	GPIO58_MUX_MCLKRA,		//configured as MCLKRA
	GPIO58_MUX_SCITXDB,		//configured as SCITXDB
	GPIO58_MUX_EPWM7A		//configured as EPWM7A
};

//GPIO Dir Enum
enum tGpioDirEmum
{
	GPIO_DIR_INPUT = 0,		//Configures the GPIO pin as an input. (default)
	GPIO_DIR_OUTPUT			//Configures the GPIO pin as an output
};

//AIO2 mux enum
enum tAio2MuxEnum
{
	AIO2_MUX_AIO = 0,		//configured as AIO
	AIO2_MUX_ADCINA2_COMP1A = 2		//configured as ADCINA2/COMP1A
};

//AIO4 mux enum
enum tAio4MuxEnum
{
	AIO4_MUX_AIO = 0,		//configured as AIO
	AIO4_MUX_ADCINA4_COMP2A = 2		//configured as ADCINA4/COMP2A
};

//AIO6 mux enum
enum tAio6MuxEnum
{
	AIO6_MUX_AIO = 0,		//configured as AIO
	AIO6_MUX_ADCINA6_COMP3A = 2		//configured as ADCINA6/COMP3A
};

//AIO10 mux enum
enum tAio10MuxEnum
{
	AIO10_MUX_AIO = 0,		//configured as AIO
	AIO10_MUX_ADCINB2_COMP1B = 2		//configured as ADCINB2/COMP1B
};

//AIO12 mux enum
enum tAio12MuxEnum
{
	AIO12_MUX_AIO = 0,		//configured as AIO
	AIO12_MUX_ADCINB4_COMP2B = 2		//configured as ADCINB4/COMP2B
};

//AIO14 mux enum
enum tAio14MuxEnum
{
	AIO14_MUX_AIO = 0,		//configured as AIO
	AIO14_MUX_ADCINB6_COMP3B = 2		//configured as ADCINB6/COMP3B
};

//AIO Dir Enum
enum tAioDirEmum
{
	AIO_DIR_INPUT = 0,		//Configures the AIO pin as an input. (default)
	AIO_DIR_OUTPUT			//Configures the AIO pin as an output
};

//GPIO Qualification Select enum
enum tGpioQualSecEnum
{
	GPIO_QUAL_SYSCLKOUT = 0,	//Synchronize to SYSCLKOUT only
	GPIO_QUAL_3_SAMPLES,		//Qualification using 3 samples
	GPIO_QUAL_6_SAMPLES,		//Qualification using 6 samples
	GPIO_QUAL_Async				//Asynchronous, no synchronization or qualification
};

//---------------------------------------------------------------------------
// Gpio External References & Function Declarations:
//
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS  GpioIntRegs;

/*******************************************************************************************
 * Public function prototypes
 *******************************************************************************************/
void InitGpio(void);

#endif  // end of F2806x_GPIO_H definition
//===========================================================================
// End of file.
//===========================================================================
