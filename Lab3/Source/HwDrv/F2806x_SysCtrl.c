/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.32 Course Project
 * File Name:	F2806x_SysCtrl.c
 * Description:	F2806x Device System Control Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		12/15/2014
 * Notes:
 * Mod History: V1.0: Initial version developed on F28069ControlStick platform
 ****************************************************************************************/

#include "F2806x_SysCtrl.h"
#include "F2806x_DevEmu.h"

/****************************************************
 * #pragma section
 ****************************************************/
#pragma DATA_SECTION(SysCtrlRegs,"SysCtrlRegsFile");
#pragma DATA_SECTION(DevEmuRegs,"DevEmuRegsFile");

/****************************************************
 * private function prototypes
 ****************************************************/
void SelectClockSource(void);
void SetSystemFrequency(CpuClockEmum freq);
void ConfigurePLL(void);
void SetPeripheralClocks(void);

/****************************************************
 * variable declaration
 ****************************************************/
volatile struct SYS_CTRL_REGS SysCtrlRegs;
volatile struct DEV_EMU_REGS DevEmuRegs;
CpuClockEmum cpuClock;	//system clock setting

/*******************************************************************************************
 * Function: InitSystemClock
 *
 * Description: This function initializes system CPU clock and peripheral clock
 *
 * Parameters: CpuClockEmum cpu_freq
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void InitSystemClock(CpuClockEmum cpu_freq)
{
	//Select internal clock source
	SelectClockSource();

	//set system frequency variable
	SetSystemFrequency(cpu_freq);

	//Configure the PLL for desired frequency
	ConfigurePLL();

	//Configure the peripheral clocks
	SetPeripheralClocks();
}

/*******************************************************************************************
 * Function: SelectClockSource
 *
 * Description: This function selects clock source for CPU and Watchdog
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes: call to Device_cal() function located in reserved OTP is included here
 *				  just in case the bootloader is bypassed during development
 *******************************************************************************************/
void SelectClockSource(void)
{
	EALLOW;

	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;	// Enable ADC peripheral clock
	(*Device_cal)();						// Call the device calibration routine
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 0; 	// Disable ADC peripheral clock

	DevEmuRegs.DEVICECNF.bit.ENPROT = 1;	// Enable write/read protection

	SysCtrlRegs.CLKCTL.all = SYSCTRL_CLKCTL_INIT;		// Configure the clock control register

	SysCtrlRegs.XCLK.all = SYSCTRL_XCLK_INIT;			// Configure the clocking register

	EDIS;
}

/*******************************************************************************************
 * Function: ConfigurePLL
 *
 * Description: This function configures PLLCR register for desired CPU frequency
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void ConfigurePLL(void)
{
	Uint16 divVal;

	switch(cpuClock)
	{
	case CPU_5MHz:
		divVal = PLLCR_DIV_1;
		break;

	case CPU_10MHz:
		divVal = PLLCR_DIV_2;
		break;

	case CPU_15MHz:
		divVal = PLLCR_DIV_3;
		break;

	case CPU_20MHz:
		divVal = PLLCR_DIV_4;
		break;

	case CPU_25MHz:
		divVal = PLLCR_DIV_5;
		break;

	case CPU_30MHz:
		divVal = PLLCR_DIV_6;
		break;

	case CPU_35MHz:
		divVal = PLLCR_DIV_7;
		break;

	case CPU_40MHz:
		divVal = PLLCR_DIV_8;
		break;

	case CPU_45MHz:
		divVal = PLLCR_DIV_9;
		break;

	case CPU_50MHz:
		divVal = PLLCR_DIV_10;
		break;

	case CPU_55MHz:
		divVal = PLLCR_DIV_11;
		break;

	case CPU_60MHz:
		divVal = PLLCR_DIV_12;
		break;

	case CPU_65MHz:
		divVal = PLLCR_DIV_13;
		break;

	case CPU_70MHz:
		divVal = PLLCR_DIV_14;
		break;

	case CPU_75MHz:
		divVal = PLLCR_DIV_15;
		break;

	case CPU_80MHz:
		divVal = PLLCR_DIV_16;
		break;

	case CPU_85MHz:
		divVal = PLLCR_DIV_17;
		break;

	case CPU_90MHz:
		divVal = PLLCR_DIV_18;
		break;

	default:
		divVal = PLLCR_DIV_0;
		break;
	}

   	// Change the PLLCR only if it is different
   	if (SysCtrlRegs.PLLCR.bit.DIV != divVal)
   	{
   		// Make sure the PLL is not running in limp mode
		if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 1)
		{
			// PLL is not running in limp mode
	   		EALLOW;

			if ((SysCtrlRegs.PLLSTS.bit.DIVSEL == 2) || (SysCtrlRegs.PLLSTS.bit.DIVSEL == 3))
			{
				SysCtrlRegs.PLLSTS.bit.DIVSEL = 0;			// DIVSEL must be 0 or 1 (/4 CLKIN mode) before changing PLLCR
			}

			SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;				// Turn off missing clock detect before changing PLLCR
	      	SysCtrlRegs.PLLCR.bit.DIV = divVal;
			// Wait for PLL to lock.
			// During this time the CPU will run at OSCCLK/4 until the PLL is stable.
			// Once the PLL is stable the CPU will automatically switch to the new PLL value.
			// Code is not required to sit and wait for the PLL to lock.  However,
			// if the code does anything that is timing critical (e.g. something that
			// relies on the CPU clock frequency to be at speed), then it is best to wait
			// until PLL lock is complete.
			while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1)		// Wait for PLLLOCKS bit to set
			{
				SysCtrlRegs.WDKEY = 0x0055;					// Service the watchdog while waiting
				SysCtrlRegs.WDKEY = 0x00AA;					// in case the user enabled it.
			}

	      	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;		// Turn on missing clock detect logic
	      	DelayUs(10);

			//divide down SysClk by 2 to increase stability
			SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
			EDIS;
		}
		else
		{
			// User should replace the below with a call to an appropriate function,
			// for example shutdown the system (since something is very wrong!).
			asm(" ESTOP0");
		}
	}
}

/*******************************************************************************************
 * Function: SetPeripheralClocks
 *
 * Description: This function sets clocks for peripheral modules
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void SetPeripheralClocks(void)
{
	EALLOW;
	SysCtrlRegs.LOSPCP.all = 0x0002;			// Lo-speed periph clock prescaler, LSPCLK=SYSCLKOUT/4

	SysCtrlRegs.PCLKCR0.bit.ECANAENCLK = 0;		// SYSCLKOUT/2 to ECAN-A disabled
	SysCtrlRegs.PCLKCR0.bit.MCBSPAENCLK = 0;	// LSPCLK to MCBSP-A disabled
	SysCtrlRegs.PCLKCR0.bit.SCIBENCLK = 0;		// LSPCLK to SCI-B disabled
	SysCtrlRegs.PCLKCR0.bit.SCIAENCLK = 0;		// LSPCLK to SCI-A disabled
	SysCtrlRegs.PCLKCR0.bit.SPIBENCLK = 0;		// LSPCLK to SPI-B disabled
	SysCtrlRegs.PCLKCR0.bit.SPIAENCLK = 0;		// LSPCLK to SPI-A disabled
	SysCtrlRegs.PCLKCR0.bit.I2CAENCLK = 0;		// SYSCLKOUT to I2C-A disabled
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;		// SYSCLKOUT to ADC enabled
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;		// TBCLKSYNC bit is handled separately in InitEPwm()
	SysCtrlRegs.PCLKCR0.bit.HRPWMENCLK = 0;		// SYSCLKOUT to HRPWM disabled

	SysCtrlRegs.PCLKCR1.bit.EQEP2ENCLK = 0;		// SYSCLKOUT to eQEP2 disabled
	SysCtrlRegs.PCLKCR1.bit.EQEP1ENCLK = 0;		// SYSCLKOUT to eQEP1 disabled
	SysCtrlRegs.PCLKCR1.bit.ECAP3ENCLK = 0;		// SYSCLKOUT to eCAP3 disabled
	SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 0;		// SYSCLKOUT to eCAP2 disabled
	SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;		// SYSCLKOUT to eCAP1 enabled
	SysCtrlRegs.PCLKCR1.bit.EPWM8ENCLK = 0;		// SYSCLKOUT to ePWM8 disabled
	SysCtrlRegs.PCLKCR1.bit.EPWM7ENCLK = 0;		// SYSCLKOUT to ePWM7 disabled
	SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 0;		// SYSCLKOUT to ePWM6 disabled
	SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 0;		// SYSCLKOUT to ePWM5 disabled
	SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 0;		// SYSCLKOUT to ePWM4 disabled
	SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 0;		// SYSCLKOUT to ePWM3 disabled
	SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 0;		// SYSCLKOUT to ePWM2 disabled
	SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 0;		// SYSCLKOUT to ePWM1 disabled

	SysCtrlRegs.PCLKCR2.bit.HRCAP4ENCLK = 0;	// SYSCLKOUT to HRCAP4 disabled
	SysCtrlRegs.PCLKCR2.bit.HRCAP3ENCLK = 0;	// SYSCLKOUT to HRCAP4 disabled
	SysCtrlRegs.PCLKCR2.bit.HRCAP2ENCLK = 0;	// SYSCLKOUT to HRCAP4 disabled
	SysCtrlRegs.PCLKCR2.bit.HRCAP1ENCLK = 0;	// SYSCLKOUT to HRCAP4 disabled

	SysCtrlRegs.PCLKCR3.bit.USB0ENCLK = 0;		// SYSCLKOUT to USB0 disabled
	SysCtrlRegs.PCLKCR3.bit.CLA1ENCLK = 0;		// SYSCLKOUT to CLA1 disabled
	SysCtrlRegs.PCLKCR3.bit.DMAENCLK = 0;		// SYSCLKOUT to DMA disabled
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER2ENCLK = 0;	// SYSCLKOUT to CPU Timer2 disabled
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER1ENCLK = 0;	// SYSCLKOUT to CPU Timer1 disabled
	SysCtrlRegs.PCLKCR3.bit.CPUTIMER0ENCLK = 0;	// SYSCLKOUT to CPU Timer0 disabled
	SysCtrlRegs.PCLKCR3.bit.COMP3ENCLK = 0;		// SYSCLKOUT to COMP3 disabled
	SysCtrlRegs.PCLKCR3.bit.COMP2ENCLK = 0;		// SYSCLKOUT to COMP2 disabled
	SysCtrlRegs.PCLKCR3.bit.COMP1ENCLK = 0;		// SYSCLKOUT to COMP1 disabled

	// Configure the low-power modes
	SysCtrlRegs.LPMCR0.all = 0x00FC;	// LPMCR0 set to default value

	EDIS;						// Disable EALLOW protected register access
}

/*******************************************************************************************
 * Function: SetSystemFrequency
 *
 * Description: This function sets system frequency variable
 *
 * Parameters: CpuClockEmum freq
 *
 * Returns: None
 *
 * Special Notes:
 *
 *******************************************************************************************/
void SetSystemFrequency(CpuClockEmum freq)
{
	cpuClock = freq;
}

/*******************************************************************************************
 * Function: GetSystemFrequency
 *
 * Description: This function gets system frequency variable
 *
 * Parameters: None
 *
 * Returns: CpuClockEmum
 *
 * Special Notes:
 *
 *******************************************************************************************/
CpuClockEmum GetSystemFrequency(void)
{
	return cpuClock;
}

//--- end of file -----------------------------------------------------
