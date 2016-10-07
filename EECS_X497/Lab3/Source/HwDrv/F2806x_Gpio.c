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

/****************************************************
 * #pragma section
 ****************************************************/
#pragma DATA_SECTION(GpioCtrlRegs, "GpioCtrlRegsFile");
#pragma DATA_SECTION(GpioDataRegs, "GpioDataRegsFile");
#pragma DATA_SECTION(GpioIntRegs, "GpioIntRegsFile");

/****************************************************
 * variable declaration
 ****************************************************/
volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
volatile struct GPIO_DATA_REGS GpioDataRegs;
volatile struct GPIO_INT_REGS GpioIntRegs;

/**********************************************************************
* Function: InitGpio()
*
* Description: Initializes the shared GPIO pins on the F2806x
**********************************************************************/
void InitGpio(void)
{
	EALLOW;								// Enable EALLOW protected register access

	// Group A pins
	GpioCtrlRegs.GPACTRL.all  = 0x00000000;		// QUALPRD = SYSCLKOUT for all group A GPIO
	GpioCtrlRegs.GPAQSEL1.all = 0x00000000;		// No qualification for all group A GPIO 0-15
	GpioCtrlRegs.GPAQSEL2.all = 0x00000000;		// No qualification for all group A GPIO 16-31
	GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = GPIO_QUAL_Async;		// Asynchronous
	GpioCtrlRegs.GPADIR.all   = 0x00000000;		// All group A GPIO are inputs
	GpioCtrlRegs.GPAPUD.all   = 0x00000FEF;		// Pullups enabled GPIO31-12 and GPIO04, disabled GPIO11-0

	GpioCtrlRegs.GPAMUX1.bit.GPIO0  = GPIO0_MUX_EPWM1A;		// 0=GPIO			1=EPWM1A     2=rsvd       3=rsvd
	GpioCtrlRegs.GPAMUX1.bit.GPIO1  = GPIO1_MUX_GPIO;		// 0=GPIO           1=EPWM1B     2=rsvd       3=COMP1OUT
	GpioCtrlRegs.GPAMUX1.bit.GPIO2  = GPIO2_MUX_EPWM2A;		// 0=GPIO           1=EPWM2A     2=rsvd       3=rsvd
	GpioCtrlRegs.GPAMUX1.bit.GPIO3  = GPIO3_MUX_GPIO;		// 0=GPIO           1=EPWM2B     2=SPISOMIA   3=COMP2OUT
	GpioCtrlRegs.GPAMUX1.bit.GPIO4  = GPIO4_MUX_GPIO;		// 0=GPIO           1=EPWM3A     2=rsvd       3=rsvd
	GpioCtrlRegs.GPAMUX1.bit.GPIO5  = GPIO5_MUX_ECAP1;		// 0=GPIO           1=EPWM3B     2=SPISIMOA   3=ECAP1
	GpioCtrlRegs.GPAMUX1.bit.GPIO6  = GPIO6_MUX_GPIO;		// 0=GPIO           1=EPWM4A     2=EPWMSYNCI  3=EPWMSYNCO
	GpioCtrlRegs.GPAMUX1.bit.GPIO7  = GPIO7_MUX_GPIO;		// 0=GPIO           1=EPWM4B     2=SCIRXDA    3=ECAP2
	GpioCtrlRegs.GPAMUX1.bit.GPIO8  = GPIO8_MUX_GPIO;		// 0=GPIO           1=EPWM5A     2=rsvd       3=ADCSOCAO
	GpioCtrlRegs.GPAMUX1.bit.GPIO9  = GPIO9_MUX_GPIO;		// 0=GPIO           1=EPWM5B     2=SCITXDB    3=ECAP3
	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = GPIO10_MUX_GPIO;		// 0=GPIO           1=EPWM6A     2=rsvd       3=ADCSOCBO
	GpioCtrlRegs.GPAMUX1.bit.GPIO11 = GPIO11_MUX_GPIO;		// 0=GPIO           1=EPWM6B     2=SCIRXDB    3=ECAP1
	GpioCtrlRegs.GPAMUX1.bit.GPIO12 = GPIO12_MUX_GPIO;		// 0=GPIO           1=TZ1        2=SCITXDA    3=SPISIMOB
	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = GPIO13_MUX_GPIO;		// 0=GPIO           1=TZ2        2=rsvd       3=SPISOMIB
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = GPIO14_MUX_GPIO;		// 0=GPIO           1=TZ3        2=SCITXDB    3=SPICLKB
	GpioCtrlRegs.GPAMUX1.bit.GPIO15 = GPIO15_MUX_GPIO;		// 0=GPIO           1=ECAP2      2=SCIRXDB    3=SPISTEB

	GpioCtrlRegs.GPAMUX2.bit.GPIO16 = GPIO16_MUX_TZ2;		// 0=GPIO           1=SPISIMOA   2=rsvd       3=TZ2
	GpioCtrlRegs.GPAMUX2.bit.GPIO17 = GPIO17_MUX_GPIO;		// 0=GPIO           1=SPISOMIA   2=rsvd       3=TZ3
	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = GPIO18_MUX_XCLKOUT;	// 0=GPIO           1=SPICLKA    2=SCITXDB    3=XCLKOUT
	GpioCtrlRegs.GPAMUX2.bit.GPIO19 = GPIO19_MUX_GPIO_XCLKIN;	// 0=GPIO/XCLKIN    1=SPISTEA    2=SCIRXDB    3=ECAP1
	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = GPIO20_MUX_GPIO;		// 0=GPIO           1=EQEP1A     2=MDXA       3=COMP1OUT
	GpioCtrlRegs.GPAMUX2.bit.GPIO21 = GPIO21_MUX_GPIO;		// 0=GPIO           1=EQEP1B     2=MDRA       3=COMP2OUT
	GpioCtrlRegs.GPAMUX2.bit.GPIO22 = GPIO22_MUX_GPIO;		// 0=GPIO           1=EQEP1S     2=MCLKXA     3=SCITXDB
	GpioCtrlRegs.GPAMUX2.bit.GPIO23 = GPIO23_MUX_GPIO;		// 0=GPIO           1=EQEP1I     2=MFSXA      3=SCIRXDB
	GpioCtrlRegs.GPAMUX2.bit.GPIO24 = GPIO24_MUX_GPIO;		// 0=GPIO           1=ECAP1      2=EQEP2A     3=SPISIMOB
	GpioCtrlRegs.GPAMUX2.bit.GPIO25 = GPIO25_MUX_GPIO;		// 0=GPIO           1=ECAP2      2=EQEP2B     3=SPISOMIB
	GpioCtrlRegs.GPAMUX2.bit.GPIO26 = GPIO26_MUX_GPIO;		// 0=GPIO           1=ECAP3      2=EQEP2I     3=SPICLKB
	GpioCtrlRegs.GPAMUX2.bit.GPIO27 = GPIO27_MUX_GPIO;		// 0=GPIO           1=HRCAP2     2=EQEP2S     3=SPISTEB
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = GPIO28_MUX_SCIRXDA;	// 0=GPIO           1=SCIRXDA    2=SDAA       3=TZ2
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = GPIO29_MUX_SCITXDA;	// 0=GPIO           1=SCITXDA    2=SCLA       3=TZ3
	GpioCtrlRegs.GPAMUX2.bit.GPIO30 = GPIO30_MUX_GPIO;		// 0=GPIO           1=CANRXA     2=EQEP2I     3=EPWM7A
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = GPIO31_MUX_GPIO;		// 0=GPIO           1=CANTXA     2=EQEP2S     3=EPWM8A

	// Group B pins
	GpioCtrlRegs.GPBCTRL.all  = 0x00000000;		// QUALPRD = SYSCLKOUT for all group B GPIO
	GpioCtrlRegs.GPBQSEL1.all = 0x00000000;		// No qualification for all group B GPIO 32-44
	GpioCtrlRegs.GPBQSEL2.all = 0x00000000;		// No qualification for all group B GPIO 50-58
	GpioCtrlRegs.GPBDIR.all   = 0x00000000;		// All group B GPIO are inputs
	GpioCtrlRegs.GPBPUD.all   = 0x00000000;		// All group B pullups enabled

	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = GPIO32_MUX_GPIO;		// 0=GPIO           1=SDAA      2=EPWMSYNCI  3=ADCSOCAO
	GpioCtrlRegs.GPBMUX1.bit.GPIO33 = GPIO33_MUX_GPIO;		// 0=GPIO           1=SCLA      2=EPWMSYNCO  3=ADCSOCBO
	GpioCtrlRegs.GPBMUX1.bit.GPIO34 = GPIO34_MUX_GPIO;		// 0=GPIO           1=COMP2OUT  2=rsvd       3=COMP3OUT
	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = GPIO35_MUX_GPIO_TDI;	// 0=GPIO (TDI)     1=rsvd      2=rsvd       3=rsvd
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = GPIO36_MUX_GPIO_TMS;	// 0=GPIO (TMS)     1=rsvd      2=rsvd       3=rsvd
	GpioCtrlRegs.GPBMUX1.bit.GPIO37 = GPIO37_MUX_GPIO_TDO;	// 0=GPIO (TDO)     1=rsvd      2=rsvd       3=rsvd
	GpioCtrlRegs.GPBMUX1.bit.GPIO38 = GPIO38_MUX_GPIO_XCLKIN;	// 0=GPIO/XCLKIN (TCK)  1=rsvd      2=rsvd       3=rsvd
	GpioCtrlRegs.GPBMUX1.bit.GPIO39 = GPIO39_MUX_GPIO;		// 0=GPIO           1=rsvd      2=rsvd       3=rsvd
	GpioCtrlRegs.GPBMUX1.bit.GPIO40 = GPIO40_MUX_GPIO;		// 0=GPIO           1=EPWM7A    2=SCITXDB    3=rsvd
	GpioCtrlRegs.GPBMUX1.bit.GPIO41 = GPIO41_MUX_GPIO;		// 0=GPIO           1=EPWM7B    2=SCIRXDB    3=rsvd
	GpioCtrlRegs.GPBMUX1.bit.GPIO42 = GPIO42_MUX_GPIO;		// 0=GPIO           1=EPWM8A    2=TZ1        3=COMP1OUT
	GpioCtrlRegs.GPBMUX1.bit.GPIO43 = GPIO43_MUX_GPIO;		// 0=GPIO           1=EPWM8B    2=TZ2        3=COMP2OUT
	GpioCtrlRegs.GPBMUX1.bit.GPIO44 = GPIO44_MUX_GPIO;		// 0=GPIO           1=MFSRA     2=SCIRXDB    3=EPWM7B

	GpioCtrlRegs.GPBMUX2.bit.GPIO50 = GPIO50_MUX_GPIO;		// 0=GPIO           1=EQEP1A    2=MDXA       3=TZ1
	GpioCtrlRegs.GPBMUX2.bit.GPIO51 = GPIO51_MUX_GPIO;		// 0=GPIO           1=EQEP1B    2=MDRA       3=TZ2
	GpioCtrlRegs.GPBMUX2.bit.GPIO52 = GPIO52_MUX_GPIO;		// 0=GPIO           1=EQEP1S    2=MCLKXA     3=TZ3
	GpioCtrlRegs.GPBMUX2.bit.GPIO53 = GPIO39_MUX_GPIO;		// 0=GPIO           1=EQEP1I    2=MFSXA      3=rsvd
	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = GPIO54_MUX_GPIO;		// 0=GPIO           1=SPISIMOA  2=EQEP2A     3=HRCAP1
	GpioCtrlRegs.GPBMUX2.bit.GPIO55 = GPIO55_MUX_GPIO;		// 0=GPIO           1=SPISOMIA  2=EQEP2B     3=HRCAP2
	GpioCtrlRegs.GPBMUX2.bit.GPIO56 = GPIO56_MUX_GPIO;		// 0=GPIO           1=SPICLKA   2=EQEP2I     3=HRCAP3
	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = GPIO57_MUX_GPIO;		// 0=GPIO           1=SPISTEA   2=EQEP2S     3=HRCAP4
	GpioCtrlRegs.GPBMUX2.bit.GPIO58 = GPIO58_MUX_GPIO;		// 0=GPIO           1=MCLKRA    2=SCITXDB    3=EPWM7A

	// Analog I/O Mux pins
	GpioCtrlRegs.AIOMUX1.bit.AIO2 = AIO2_MUX_ADCINA2_COMP1A;			// 0,1=AIO2     2,3=ADCINA2/COMP1A
	GpioCtrlRegs.AIOMUX1.bit.AIO4 = AIO4_MUX_ADCINA4_COMP2A;			// 0,1=AIO4     2,3=ADCINA4/COMP2A
	GpioCtrlRegs.AIOMUX1.bit.AIO6 = AIO6_MUX_ADCINA6_COMP3A;			// 0,1=AIO6     2,3=ADCINA6/COMP3A
	GpioCtrlRegs.AIOMUX1.bit.AIO10 = AIO10_MUX_ADCINB2_COMP1B;			// 0,1=AIO10    2,3=ADCINB2/COMP1B
	GpioCtrlRegs.AIOMUX1.bit.AIO12 = AIO12_MUX_ADCINB4_COMP2B;			// 0,1=AIO12    2,3=ADCINB4/COMP2B
	GpioCtrlRegs.AIOMUX1.bit.AIO14 = AIO14_MUX_ADCINB6_COMP3B;			// 0,1=AIO14    2,3=ADCINB6/COMP3B

	GpioCtrlRegs.AIODIR.bit.AIO2 = AIO_DIR_INPUT;			// AIO2 is an input (when selected as digital function)
	GpioCtrlRegs.AIODIR.bit.AIO4 = AIO_DIR_INPUT;			// AIO4 is an input (when selected as digital function)
	GpioCtrlRegs.AIODIR.bit.AIO6 = AIO_DIR_INPUT;			// AIO6 is an input (when selected as digital function)
	GpioCtrlRegs.AIODIR.bit.AIO10 = AIO_DIR_INPUT;			// AIO10 is an input (when selected as digital function)
	GpioCtrlRegs.AIODIR.bit.AIO12 = AIO_DIR_INPUT;			// AIO12 is an input (when selected as digital function)
	GpioCtrlRegs.AIODIR.bit.AIO14 = AIO_DIR_INPUT;			// AIO14 is an input (when selected as digital function)

	// Selected pin configurations
	GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;					// GPIO34 pin is set to 0 (turn LED on)
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = GPIO_DIR_OUTPUT;		// GPIO34 is an output (connected to LED on F28069 controlSTICK)

	// Finish up
	EDIS;								// Disable EALLOW protected register access
}

//--- end of file -----------------------------------------------------
