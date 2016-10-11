 /****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2013
 * Project:		EECS X497.19 Course Project
 * File Name:	F2806x_Adc.c
 * Description:	F2806x Device ADC Driver Functions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		9/15/2013
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/

#include "F2806x_Adc.h"
#include "F2806x_Gpio.h"
#include "F2806x_PieCtrl.h"

/****************************************************
 * #pragma section
 ****************************************************/
#pragma DATA_SECTION(AdcRegs,"AdcRegsFile");
#pragma DATA_SECTION(AdcResult,"AdcResultFile");

/****************************************************
 * Variable Declaration
 ****************************************************/
volatile struct ADC_REGS AdcRegs;
volatile struct ADC_RESULT_REGS AdcResult;
Uint16 aveTemp;

/****************************************************
 * Static Function Prototypes
 ****************************************************/
void InitTempSensor(void);

/*******************************************************************************************
 * Function: InitAdc
 *
 * Description: This function initializes ADC module SOC0 for channel A0
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *     1 -
 *
 *******************************************************************************************/
void InitAdc(void)
{
	EALLOW;

	AdcRegs.ADCCTL1.all = ADCREGS_ADCCTL1_INIT;		// Power-up reference and main ADC
	AdcRegs.ADCCTL2.all = ADCREGS_ADCCTL2_INIT;		// ADC clock configuration
	DelayUs(1000);									// Wait 1 ms after power-up before using the ADC

	InitTempSensor();

	AdcRegs.ADCCTL1.bit.ADCENABLE = ADCCTL1_ADC_EN;			// Enable the ADC

	EDIS;
}

/*******************************************************************************************
 * Function: InitTempSensor
 *
 * Description: This function configures SOC1 - SOC4 for temperature sensoring
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *     1 -
 *
 *******************************************************************************************/
void InitTempSensor(void)
{
	AdcRegs.ADCSOC0CTL.bit.TRIGSEL = ADCTRIG_SW;			// Trigger using software
	AdcRegs.ADCSOC0CTL.bit.CHSEL = ADC_INA5;				// Convert channel ADCINA5
	AdcRegs.ADCSOC0CTL.bit.ACQPS = TEMP_ACQ_WINDOW_CYCLES;	// 

	AdcRegs.ADCSOC1CTL.bit.TRIGSEL = ADCTRIG_SW;			// Trigger using software
	AdcRegs.ADCSOC1CTL.bit.CHSEL = ADC_INA5;				// Convert channel ADCINA5
	AdcRegs.ADCSOC1CTL.bit.ACQPS = TEMP_ACQ_WINDOW_CYCLES;	// Acquisition window 

	AdcRegs.ADCSOC2CTL.bit.TRIGSEL = ADCTRIG_SW;			// Trigger using software
	AdcRegs.ADCSOC2CTL.bit.CHSEL = ADC_INA5;				// Convert channel ADCINA5
	AdcRegs.ADCSOC2CTL.bit.ACQPS = TEMP_ACQ_WINDOW_CYCLES;	// Acquisition window set

	AdcRegs.ADCSOC3CTL.bit.TRIGSEL = ADCTRIG_SW;			// Trigger using software
	AdcRegs.ADCSOC3CTL.bit.CHSEL = ADC_INA5;				// Convert channel ADCINA5
	AdcRegs.ADCSOC3CTL.bit.ACQPS = TEMP_ACQ_WINDOW_CYCLES;	// Acquisition window set 

	AdcRegs.ADCINTSOCSEL1.bit.SOC0 = ADCTRIG_ADCINT1;		// ADCINT1 triggers SOC0
	AdcRegs.ADCINTSOCSEL1.bit.SOC1 = ADCTRIG_ADCINT1;		// ADCINT1 triggers SOC1
	AdcRegs.ADCINTSOCSEL1.bit.SOC2 = ADCTRIG_ADCINT1;		// ADCINT1 triggers SOC2
	AdcRegs.ADCINTSOCSEL1.bit.SOC3 = ADCTRIG_ADCINT1;		// ADCINT1 triggers SOC3
	
	//ADCINT1 configuration
	AdcRegs.INTSEL1N2.bit.INT1SEL = ADCINT_SRC_EOC3;		// Configures SOC3 as int1 source
	AdcRegs.INTSEL1N2.bit.INT1CONT = ADCINT_CONT_MODE_EN;	// ADCINT1 pulses regardless of ADCINT1 flag state
	AdcRegs.INTSEL1N2.bit.INT1E = ADCINT_EN;				// Enable ADCINT1
}

void StartTempSampling(void)
{
	AdcRegs.ADCSOCFRC1.bit.SOC0 = 1;
	AdcRegs.ADCSOCFRC1.bit.SOC1 = 1;
	AdcRegs.ADCSOCFRC1.bit.SOC2 = 1;
	AdcRegs.ADCSOCFRC1.bit.SOC3 = 1;
}

/*******************************************************************************************
 * Function: GetTempRawData
 *
 * Description: This function reads temperature ADC raw data
 *
 * Parameters: None
 *
 * Returns: Uint16
 *
 * Special Notes:
 *
 *******************************************************************************************/
Uint16 GetTempRawData(void)
{
	return aveTemp;
}

/*******************************************************************************************
 * Function: ADCINT1_ISR
 *
 * Description: This function serves ADCINT1 interrupts and saves sampling data to a buffer.
 *
 * Parameters: None
 *
 * Returns: None
 *
 * Special Notes:
 *     1 - PIE1.1 @ 0x000D40  ADCINT1
 *
 *******************************************************************************************/
interrupt void ADCINT1_ISR(void)
{
	Uint16 temp;

	//read raw data
	temp = AdcResult.ADCRESULT0;
	temp += AdcResult.ADCRESULT1;
	temp += AdcResult.ADCRESULT2;
	temp += AdcResult.ADCRESULT3;
	aveTemp = temp >> 2;

	//ack interrupts
	AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;		// Clear ADCINT1 flag
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;		// Must acknowledge the PIE group
}

//--- end of file -----------------------------------------------------
