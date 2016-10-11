/****************************************************************************************
 * Copyright:  	GoldenMaple Technologies (C) 2014
 * Project:		EECS X497.19 Course Project
 * File Name:	F2806x_Adc.h
 * Description:	F2806x Device ADC Register Definitions
 * Language:    TI TMS320F2806x C
 * Author:		Louis Zhu
 * Created:		9/15/2014
 * Notes:
 * Mod History: V1.0: Initial version
 ****************************************************************************************/

#ifndef F2806x_ADC_H
#define F2806x_ADC_H

#include "F2806x_Device.h"

#define ADC_CH0_SAMP_COUNT	100			// Number of sample data
#define TEMP_ACQ_WINDOW_CYCLES	25		//Acquisition window set to (25+1)=26 cycles

#define ADCREGS_ADCCTL1_INIT	0x00E5		// Power-up reference and main ADC
// bit 15        0:      RESET, ADC software reset, 0=no effect, 1=resets the ADC
// bit 14        0:      ADCENABLE, ADC enable, 0=disabled, 1=enabled
// bit 13        0:      ADCBSY, ADC busy, read-only
// bit 12-8      0's:    ADCBSYCHN, ADC busy channel, read-only
// bit 7         1:      ADCPWDN, ADC power down, 0=powered down, 1=powered up
// bit 6         1:      ADCBGPWD, ADC bandgap power down, 0=powered down, 1=powered up
// bit 5         1:      ADCREFPWD, ADC reference power down, 0=powered down, 1=powered up
// bit 4         0:      reserved
// bit 3         0:      ADCREFSEL, ADC reference select, 0=internal, 1=external
// bit 2         1:      INTPULSEPOS, INT pulse generation, 0=start of conversion, 1=end of conversion
// bit 1         0:      VREFLOCONV, VREFLO convert, 0=VREFLO not connected, 1=VREFLO connected to B5
// bit 0         1:      TEMPCONV, Temperature sensor convert.  0=ADCINA5 is pin, 1=ADCINA5 is temp sensor

#define	ADCREGS_ADCCTL2_INIT	0x0001		// ADC clock configuration
// bit 15-3      0's:    reserved
// bit 2         1:      CLKDIV4EN, ADC clock divider.  0=no effect, 1=CPUCLK/4 if CLKDIV2EN=1 (else no effect)
// bit 1         0:      ADCNONOVERLAP, 0=overlap sample and conversion, 1=no overlap
// bit 0         1:      CLKDIV2EN, ADC clock divider.  0=CPUCLK, 1=CPUCLK/2

//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:
//ADC Control Register 1 Bit Structure
struct ADCCTL1_BITS {     		// bits description
	Uint16	TEMPCONV:1;			// 0	Temperature sensor connection
	Uint16	VREFLOCONV:1;		// 1	VSSA connection
	Uint16	INTPULSEPOS :1;		// 2	INT pulse generation control
	Uint16	ADCREFSEL:1;		// 3	Internal/external reference select
	Uint16	rsvd1:1;			// 4	Reserved
	Uint16	ADCREFPWD:1;		// 5	Reference buffers powerdown
	Uint16	ADCBGPWD:1;			// 6	ADC bandgap powerdown
	Uint16	ADCPWDN:1;			// 7	ADC powerdown
	Uint16	ADCBSYCHN:5;		// 12:8	ADC busy on a channel
	Uint16	ADCBSY:1;			// 13	ADC Busy
	Uint16	ADCENABLE:1;		// 14	ADC Enable
	Uint16	RESET:1;			// 15	ADC Master Reset
};

union ADCCTL1_REG {
	Uint16 all;
	struct ADCCTL1_BITS	bit;
};

struct ADCCTL2_BITS {     // bits description
	Uint16	CLKDIV2EN:1;		// 0	ADC CLK Div2 enable
	Uint16	ADCNONOVERLAP:1;	// 1	Non Sample Overlap enable
	Uint16	CLKDIV4EN:1;		// 2	ADC CLK Div4 enable
	Uint16	rsvd1:13;			// 15:3	Reserved
};

union ADCCTL2_REG {
	Uint16 all;
	struct ADCCTL2_BITS	bit;
};

struct ADCSAMPLEMODE_BITS {     // bits description
	Uint16	SIMULEN0:1;			// 0	Simultaneous sampling enable for SOC0
	Uint16	SIMULEN2:1;			// 1	Simultaneous sampling enable for SOC2
	Uint16	SIMULEN4:1;			// 2	Simultaneous sampling enable for SOC4
	Uint16	SIMULEN6:1;			// 3	Simultaneous sampling enable for SOC6
	Uint16	SIMULEN8:1;			// 4	Simultaneous sampling enable for SOC8
	Uint16	SIMULEN10:1;		// 5	Simultaneous sampling enable for SOC10
	Uint16	SIMULEN12:1;		// 6	Simultaneous sampling enable for SOC12
	Uint16	SIMULEN14:1;		// 7	Simultaneous sampling enable for SOC14
	Uint16	rsvd1:8;			// 15:8	Reserved
};

union ADCSAMPLEMODE_REG {
	Uint16 all;
	struct ADCSAMPLEMODE_BITS	bit;
};

struct SOCPRICTL_BITS {     // bits description
	Uint16	SOCPRIORITY:5;		// 4:0	Start-of-conversion Priority
	Uint16	RRPOINTER:6;		// 10:5	Round Robin Pointer
	Uint16	rsvd1:4;			// 14:11	Reserved
	Uint16	ONESHOT:1;			// 15	One Shot Mode Enabled
};

union SOCPRICTL_REG {
	Uint16 all;
	struct SOCPRICTL_BITS	bit;
};

struct ADCSOC_BITS {     // bits description
	Uint16	SOC0:1;			// 0	Start of conversion for CONV0
	Uint16	SOC1:1;			// 1	Start of conversion for CONV1
	Uint16	SOC2:1;			// 2	Start of conversion for CONV2
	Uint16	SOC3:1;			// 3	Start of conversion for CONV3
	Uint16	SOC4:1;			// 4	Start of conversion for CONV4
	Uint16	SOC5:1;			// 5	Start of conversion for CONV5
	Uint16	SOC6:1;			// 6	Start of conversion for CONV6
	Uint16	SOC7:1;			// 7	Start of conversion for CONV7
	Uint16	SOC8:1;			// 8	Start of conversion for CONV8
	Uint16	SOC9:1;			// 9	Start of conversion for CONV9
	Uint16	SOC10:1;		// 10	Start of conversion for CONV10
	Uint16	SOC11:1;		// 11	Start of conversion for CONV11
	Uint16	SOC12:1;		// 12	Start of conversion for CONV12
	Uint16	SOC13:1;		// 13	Start of conversion for CONV13
	Uint16	SOC14:1;		// 14	Start of conversion for CONV14
	Uint16	SOC15:1;		// 15	Start of conversion for CONV15
};

union ADCSOC_REG {
	Uint16 all;
	struct ADCSOC_BITS	bit;
};

struct INTSEL1N2_BITS {     	// bits description
	Uint16	INT1SEL:5;			// 4:0	INT1 EOC Source Select
	Uint16	INT1E:1;			// 5	INT1 Interrupt Enable
	Uint16	INT1CONT:1;			// 6	INT1 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT2SEL:5;			// 12:8	INT2 EOC Source Select
	Uint16	INT2E:1;			// 13	INT2 Interrupt Enable
	Uint16	INT2CONT:1;			// 14	INT2 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL1N2_REG {
	Uint16 all;
	struct INTSEL1N2_BITS	bit;
};

struct INTSEL3N4_BITS {     // bits description
	Uint16	INT3SEL:5;			// 4:0	INT3 EOC Source Select
	Uint16	INT3E:1;			// 5	INT3 Interrupt Enable
	Uint16	INT3CONT:1;			// 6	INT3 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT4SEL:5;			// 12:8	INT4 EOC Source Select
	Uint16	INT4E:1;			// 13	INT4 Interrupt Enable
	Uint16	INT4CONT:1;			// 14	INT4 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL3N4_REG {
	Uint16 all;
	struct INTSEL3N4_BITS	bit;
};

struct INTSEL5N6_BITS {     // bits description
	Uint16	INT5SEL:5;			// 4:0	INT5 EOC Source Select
	Uint16	INT5E:1;			// 5	INT5 Interrupt Enable
	Uint16	INT5CONT:1;			// 6	INT5 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT6SEL:5;			// 12:8	INT6 EOC Source Select
	Uint16	INT6E:1;			// 13	INT6 Interrupt Enable
	Uint16	INT6CONT:1;			// 14	INT6 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL5N6_REG {
	Uint16 all;
	struct INTSEL5N6_BITS	bit;
};

struct INTSEL7N8_BITS {     // bits description
	Uint16	INT7SEL:5;			// 4:0	INT7 EOC Source Select
	Uint16	INT7E:1;			// 5	INT7 Interrupt Enable
	Uint16	INT7CONT:1;			// 6	INT7 Continuous Mode Enable
	Uint16	rsvd1:1;			// 7	Reserved
	Uint16	INT8SEL:5;			// 12:8	INT8 EOC Source Select
	Uint16	INT8E:1;			// 13	INT8 Interrupt Enable
	Uint16	INT8CONT:1;			// 14	INT8 Continuous Mode Enable
	Uint16	rsvd2:1;			// 15	Reserved
};

union INTSEL7N8_REG {
	Uint16 all;
	struct INTSEL7N8_BITS	bit;
};

struct INTSEL9N10_BITS {     	// bits description
	Uint16	INT9SEL:5;			// 4:0	INT9 EOC Source Select
	Uint16	INT9E:1;			// 5	INT9 Interrupt Enable
	Uint16	INT9CONT:1;			// 6	INT9 Continuous Mode Enable
	Uint16	rsvd1:9;			// 15:7	Reserved
};

union INTSEL9N10_REG {
	Uint16 all;
	struct INTSEL9N10_BITS	bit;
};

struct ADCINT_BITS {     // bits description
	Uint16	ADCINT1:1;			// 0	ADC Interrupt Flag 1
	Uint16	ADCINT2:1;			// 1	ADC Interrupt Flag 2
	Uint16	ADCINT3:1;			// 2	ADC Interrupt Flag 3
	Uint16	ADCINT4:1;			// 3	ADC Interrupt Flag 4
	Uint16	ADCINT5:1;			// 4	ADC Interrupt Flag 5
	Uint16	ADCINT6:1;			// 5	ADC Interrupt Flag 6
	Uint16	ADCINT7:1;			// 6	ADC Interrupt Flag 7
	Uint16	ADCINT8:1;			// 7	ADC Interrupt Flag 8
	Uint16	ADCINT9:1;			// 8	ADC Interrupt Flag 9
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union ADCINT_REG {
	Uint16 all;
	struct ADCINT_BITS	bit;
};

struct ADCINTSOCSEL1_BITS {     // bits description
	Uint16	SOC0:2;			// 1:0	ADCINT Start-of-conversion Select
	Uint16	SOC1:2;			// 3:2	ADCINT Start-of-conversion Select
	Uint16	SOC2:2;			// 5:4	ADCINT Start-of-conversion Select
	Uint16	SOC3:2;			// 7:6	ADCINT Start-of-conversion Select
	Uint16	SOC4:2;			// 9:8	ADCINT Start-of-conversion Select
	Uint16	SOC5:2;			// 11:10	ADCINT Start-of-conversion Select
	Uint16	SOC6:2;			// 13:12	ADCINT Start-of-conversion Select
	Uint16	SOC7:2;			// 15:14	ADCINT Start-of-conversion Select
};

union ADCINTSOCSEL1_REG {
	Uint16 all;
	struct ADCINTSOCSEL1_BITS	bit;
};

struct ADCINTSOCSEL2_BITS {     // bits description
	Uint16	SOC8:2;				// 1:0	ADCINT Start-of-conversion Select
	Uint16	SOC9:2;				// 3:2	ADCINT Start-of-conversion Select
	Uint16	SOC10:2;			// 5:4	ADCINT Start-of-conversion Select
	Uint16	SOC11:2;			// 7:6	ADCINT Start-of-conversion Select
	Uint16	SOC12:2;			// 9:8	ADCINT Start-of-conversion Select
	Uint16	SOC13:2;			// 11:10	ADCINT Start-of-conversion Select
	Uint16	SOC14:2;			// 13:12	ADCINT Start-of-conversion Select
	Uint16	SOC15:2;			// 15:14	ADCINT Start-of-conversion Select
};

union ADCINTSOCSEL2_REG {
	Uint16 all;
	struct ADCINTSOCSEL2_BITS	bit;
};

struct ADCSOCxCTL_BITS {     // bits description
	Uint16	ACQPS:6;			// 5:0	Acquisition Pulse Size
	Uint16	CHSEL:4;			// 9:6	SOCx Channel Select
	Uint16	rsvd1:1;			// 10	Reserved
	Uint16	TRIGSEL:5;			// 15:11	SOCx Trigger Select
};

union ADCSOCxCTL_REG {
	Uint16 all;
	struct ADCSOCxCTL_BITS	bit;
};

struct ADCREFTRIM_BITS {     // bits description
	Uint16	BG_FINE_TRIM:5;			// 4:0	Course Trim for Internal BG
	Uint16	BG_COARSE_TRIM:4;		// 8:5	Fine Trim for Internal BG
	Uint16	EXTREF_FINE_TRIM:5;		// 13:9	Fine Trim for External Reference
	Uint16	rsvd1:2;				// 15:14	Reserved
};

union ADCREFTRIM_REG {
	Uint16 all;
	struct ADCREFTRIM_BITS	bit;
};

struct ADCOFFTRIM_BITS {     // bits description
	Int16	OFFTRIM:9;			// 8:0	Offset Trim
	Uint16	rsvd1:7;			// 15:9	Reserved
};

union ADCOFFTRIM_REG {
	Uint16 all;
	struct ADCOFFTRIM_BITS	bit;
};

struct COMPHYSTCTL_BITS{                // bits description
    Uint16  rsvd1:1;             	   // 0    reserved
    Uint16  COMP1_HYST_DISABLE:1;      // 1    Comparator 1 Hysteresis Disable
    Uint16  rsvd2:4;                   // 5:2  reserved
    Uint16  COMP2_HYST_DISABLE:1;      // 6    Comparator 2 Hysteresis Disable
    Uint16  rsvd3:4;                   // 10:7 reserved
    Uint16  COMP3_HYST_DISABLE:1;      // 11   Comparator 3 Hysteresis Disable
    Uint16  rsvd4:4;                   // 15:12 reserved
};

union COMPHYSTCTL_REG{
    Uint16      all;
    struct COMPHYSTCTL_BITS bit;
};

struct ADC_REGS {
	union	ADCCTL1_REG			ADCCTL1;		// Control 1 Register
	union	ADCCTL2_REG			ADCCTL2;		// Control 2 Register
	Uint16						rsvd1;			// Reserved
	Uint16						rsvd2;			// Reserved
	union	ADCINT_REG			ADCINTFLG;		// Interrupt Flag Register
	union	ADCINT_REG			ADCINTFLGCLR;	// Interrupt Flag Clear Register
	union	ADCINT_REG			ADCINTOVF;		// Interrupt Overflow Register
	union	ADCINT_REG			ADCINTOVFCLR;	// Interrupt Overflow Clear Register
	union	INTSEL1N2_REG		INTSEL1N2;		// Interrupt 1 and 2 Selection Register
	union	INTSEL3N4_REG		INTSEL3N4;		// Interrupt 3 and 4 Selection Register
	union	INTSEL5N6_REG		INTSEL5N6;		// Interrupt 5 and 6 Selection Register
	union	INTSEL7N8_REG		INTSEL7N8;		// Interrupt 7 and 8 Selection Register
	union	INTSEL9N10_REG		INTSEL9N10;		// Interrupt 9 Selection Register
	Uint16						rsvd3;			// Reserved
	Uint16						rsvd4;			// Reserved
	Uint16						rsvd5;			// Reserved
	union	SOCPRICTL_REG		SOCPRICTL;		// SOC Priority Control Register
	Uint16						rsvd6;			// Reserved
	union	ADCSAMPLEMODE_REG	ADCSAMPLEMODE;	// Sampling Mode Register
	Uint16						rsvd7;			// Reserved
	union	ADCINTSOCSEL1_REG	ADCINTSOCSEL1;	// Interrupt SOC Selection 1 Register (for 8 channels)
	union	ADCINTSOCSEL2_REG	ADCINTSOCSEL2;	// Interrupt SOC Selection 2 Register (for 8 channels)
	Uint16						rsvd8;			// Reserved
	Uint16						rsvd9;			// Reserved
	union	ADCSOC_REG			ADCSOCFLG1;		// SOC Flag 1 Register (for 16 channels)
	Uint16						rsvd10;			// Reserved
	union	ADCSOC_REG			ADCSOCFRC1;		// SOC Force 1 Register (for 16 channels)
	Uint16						rsvd11;			// Reserved
	union	ADCSOC_REG			ADCSOCOVF1;		// SOC Overflow 1 Register (for 16 channels)
	Uint16						rsvd12;			// Reserved
	union	ADCSOC_REG			ADCSOCOVFCLR1;	// SOC Overflow Clear 1 Register (for 16 channels)
	Uint16						rsvd13;			// Reserved
	union	ADCSOCxCTL_REG		ADCSOC0CTL;		// SOC0 Control Register
	union	ADCSOCxCTL_REG		ADCSOC1CTL;		// SOC1 Control Register
	union	ADCSOCxCTL_REG		ADCSOC2CTL;		// SOC2 Control Register
	union	ADCSOCxCTL_REG		ADCSOC3CTL;		// SOC3 Control Register
	union	ADCSOCxCTL_REG		ADCSOC4CTL;		// SOC4 Control Register
	union	ADCSOCxCTL_REG		ADCSOC5CTL;		// SOC5 Control Register
	union	ADCSOCxCTL_REG		ADCSOC6CTL;		// SOC6 Control Register
	union	ADCSOCxCTL_REG		ADCSOC7CTL;		// SOC7 Control Register
	union	ADCSOCxCTL_REG		ADCSOC8CTL;		// SOC8 Control Register
	union	ADCSOCxCTL_REG		ADCSOC9CTL;		// SOC9 Control Register
	union	ADCSOCxCTL_REG		ADCSOC10CTL;	// SOC10 Control Register
	union	ADCSOCxCTL_REG		ADCSOC11CTL;	// SOC11 Control Register
	union	ADCSOCxCTL_REG		ADCSOC12CTL;	// SOC12 Control Register
	union	ADCSOCxCTL_REG		ADCSOC13CTL;	// SOC13 Control Register
	union	ADCSOCxCTL_REG		ADCSOC14CTL;	// SOC14 Control Register
	union	ADCSOCxCTL_REG		ADCSOC15CTL;	// SOC15 Control Register
	Uint16						rsvd14[16];		// Reserved
	union	ADCREFTRIM_REG		ADCREFTRIM;		// Reference Trim Register
	union	ADCOFFTRIM_REG		ADCOFFTRIM;		// Offset Trim Register
	Uint16                      rsvd15 [10];    // reserved
	union   COMPHYSTCTL_REG     COMPHYSTCTL;    // COMP Hysteresis Control Register
	Uint16                      rsvd16 [3];     // reserved
};

struct ADC_RESULT_REGS {
	Uint16		ADCRESULT0;		// Conversion Result Buffer 0
	Uint16		ADCRESULT1;		// Conversion Result Buffer 1
	Uint16		ADCRESULT2;		// Conversion Result Buffer 2
	Uint16		ADCRESULT3;		// Conversion Result Buffer 3
	Uint16		ADCRESULT4;		// Conversion Result Buffer 4
	Uint16		ADCRESULT5;		// Conversion Result Buffer 5
	Uint16		ADCRESULT6;		// Conversion Result Buffer 6
	Uint16		ADCRESULT7;		// Conversion Result Buffer 7
	Uint16		ADCRESULT8;		// Conversion Result Buffer 8
	Uint16		ADCRESULT9;		// Conversion Result Buffer 9
	Uint16		ADCRESULT10;	// Conversion Result Buffer 10
	Uint16		ADCRESULT11;	// Conversion Result Buffer 11
	Uint16		ADCRESULT12;	// Conversion Result Buffer 12
	Uint16		ADCRESULT13;	// Conversion Result Buffer 13
	Uint16		ADCRESULT14;	// Conversion Result Buffer 14
	Uint16		ADCRESULT15;	// Conversion Result Buffer 15
};

//ADC channel selection enum
enum tAdcChEnum
{
	ADC_INA0 = 0,			//channel A0
	ADC_INA0B0 = ADC_INA0,	//channel A0B0 simultaneously
	ADC_INA1,				//channel A1
	ADC_INA1B1 = ADC_INA1,	//channel A1B1 simultaneously
	ADC_INA2,				//channel A2
	ADC_INA2B2 = ADC_INA2,	//channel A2B2 simultaneously
	ADC_INA3,				//channel A3
	ADC_INA3B3 = ADC_INA3,	//channel A3B3 simultaneously
	ADC_INA4,				//channel A4
	ADC_INA4B4 = ADC_INA4,	//channel A4B4 simultaneously
	ADC_INA5,				//channel A5
	ADC_INA5B5 = ADC_INA5,	//channel A5B5 simultaneously
	ADC_INA6,				//channel A6
	ADC_INA6B6 = ADC_INA6,	//channel A6B6 simultaneously
	ADC_INA7,				//channel A7
	ADC_INA7B7 = ADC_INA7,	//channel A7B7 simultaneously
	ADC_INB0,				//channel B0
	ADC_INB1,				//channel B1
	ADC_INB2,				//channel B2
	ADC_INB3,				//channel B3
	ADC_INB4,				//channel B4
	ADC_INB5,				//channel B5
	ADC_INB6,				//channel B6
	ADC_INB7				//channel B7
};

//sample mode enum
enum tAdcSampModeEnum
{
	ADC_SAMP_SINGLE,	//Single sample mode
	ADC_SAMP_SIMU		//Simultaneous sample mode
};

//ADC trigger source selection enum
enum tAdcSocTrigSelEnum
{
	ADCTRIG_SW = 0,		//ADCTRIG0 - Software only
	ADCTRIG_TIMER0,		//ADCTRIG1 - CPU Timer 0, TINT0n
	ADCTRIG_TIMER1,		//ADCTRIG2 - CPU Timer 1, TINT1n
	ADCTRIG_TIMER2,		//ADCTRIG3 - CPU Timer 2, TINT2n
	ADCTRIG_XINT2,		//ADCTRIG4 – XINT2, XINT2SOC
	ADCTRIG_EPWM1SOCA,	//ADCTRIG5 – ePWM1, ADCSOCA
	ADCTRIG_EPWM1SOCB,	//ADCTRIG6 – ePWM1, ADCSOCB
	ADCTRIG_EPWM2SOCA,	//ADCTRIG7 – ePWM2, ADCSOCA
	ADCTRIG_EPWM2SOCB,	//ADCTRIG8 – ePWM2, ADCSOCB
	ADCTRIG_EPWM3SOCA,	//ADCTRIG9 – ePWM3, ADCSOCA
	ADCTRIG_EPWM3SOCB,	//ADCTRIG10 – ePWM3, ADCSOCB
	ADCTRIG_EPWM4SOCA,	//ADCTRIG11 – ePWM4, ADCSOCA
	ADCTRIG_EPWM4SOCB,	//ADCTRIG12 – ePWM4, ADCSOCB
	ADCTRIG_EPWM5SOCA,	//ADCTRIG13 – ePWM5, ADCSOCA
	ADCTRIG_EPWM5SOCB,	//ADCTRIG14 – ePWM5, ADCSOCB
	ADCTRIG_EPWM6SOCA,	//ADCTRIG15 – ePWM6, ADCSOCA
	ADCTRIG_EPWM6SOCB,	//ADCTRIG16 – ePWM6, ADCSOCB
	ADCTRIG_EPWM7SOCA,	//ADCTRIG17 – ePWM7, ADCSOCA
	ADCTRIG_EPWM7SOCB,	//ADCTRIG18 – ePWM7, ADCSOCB
	ADCTRIG_EPWM8SOCA,	//ADCTRIG19 – ePWM8, ADCSOCA
	ADCTRIG_EPWM8SOCB	//ADCTRIG20 – ePWM8, ADCSOCB
};

#define ADCSOC_ACQPS_MIN	6	//minimum ACQPS value, sample window is 7 cycles long

//ADC Interrupt Trigger SOC Select Enum
enum tAdcIntSocSelEnum
{
	ADCTRIG_NO_INT = 0,		//No ADCINT will trigger SOCx. TRIGSEL field determines SOCx trigger
	ADCTRIG_ADCINT1,		//ADCINT1 will trigger SOCx. TRIGSEL field is ignored
	ADCTRIG_ADCINT2			//ADCINT2 will trigger SOCx. TRIGSEL field is ignored
};

//ADC SOC Priority Enum
enum tAdcSocPriorityEnum
{
	ADCSOC_PRI_CUTOFF_NO = 0,	//SOC priority is handled in round robin mode for all channels
	ADCSOC_PRI_CUTOFF_SOC0,		//SOC0 is high priority, rest of channels are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC1,		//SOC0-SOC1 are high priority, SOC2-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC2,		//SOC0-SOC2 are high priority, SOC3-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC3,		//SOC0-SOC3 are high priority, SOC4-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC4,		//SOC0-SOC4 are high priority, SOC5-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC5,		//SOC0-SOC5 are high priority, SOC6-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC6,		//SOC0-SOC6 are high priority, SOC7-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC7,		//SOC0-SOC7 are high priority, SOC8-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC8,		//SOC0-SOC8 are high priority, SOC8-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC9,		//SOC0-SOC9 are high priority, SOC10-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC10,	//SOC0-SOC10 are high priority, SOC11-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC11,	//SOC0-SOC11 are high priority, SOC12-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC12,	//SOC0-SOC12 are high priority, SOC13-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC13,	//SOC0-SOC13 are high priority, SOC14-SOC15 are in round robin mode
	ADCSOC_PRI_CUTOFF_SOC14,	//SOC0-SOC14 are high priority, SOC15 is in round robin mode
	ADCSOC_PRI_ALL				//All SOCs are in high priority mode, arbitrated by SOC number
};

//ADC Interrupt Continuous Mode Enum
enum tAdcIntContEnEnum
{
	ADCINT_CONT_MODE_DIS = 0,	//No further ADCINTy pulses are generated until ADCINTy flag (in ADCINTFLG register) is cleared by user
	ADCINT_CONT_MODE_EN			//ADCINTy pulses are generated whenever an EOC pulse is generated irrespective if the flag bit is cleared or not
};

//ADC Interrupt Enable Enum
enum tAdcIntEnEnum
{
	ADCINT_DIS = 0,		//ADCINTx is disabled
	ADCINT_EN			//ADCINTx is enabled
};

//ADC Interrupt Trigger Source Enum
enum tAdcIntSourceSelEnum
{
	ADCINT_SRC_EOC0 = 0,		//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC1,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC2,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC3,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC4,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC5,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC6,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC7,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC8,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC9,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC10,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC11,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC12,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC13,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC14,			//EOC0 is trigger for ADCINTx/y
	ADCINT_SRC_EOC15			//EOC0 is trigger for ADCINTx/y
};

//ADCCTL1 ADC Enable Enum
enum tAdcCtl1AdcEnEnum
{
	ADCCTL1_ADC_DIS = 0,		//ADCINTx is disabled
	ADCCTL1_ADC_EN				//ADCINTx is enabled
};


extern volatile struct ADC_RESULT_REGS AdcResult;

/*******************************************************************************************
 * Public function prototypes
 *******************************************************************************************/
void InitAdc(void);
interrupt void ADCINT1_ISR(void);
void StartTempSampling(void);
Uint16 GetTempRawData(void);
#endif
//===========================================================================
// End of file.
//===========================================================================
