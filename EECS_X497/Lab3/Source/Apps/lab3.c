/*
 * lab2.c
 *
 *  Created on: 5 oct. 2016
 *      Author: Aymeric
 */

// Include header files
#include "F2806x_Device.h"
#include "F2806x_Gpio.h"
#include "LedDrv.h"
#include "F2806x_DevEmu.h"
#include "F2806x_SysCtrl.h"

// Private function Prototypes
void Delay(int count);
void InitDevice(void);

//Global Variables

volatile int toggleCount=0;

void main(void){
	InitDevice();

	while(1){
		ToggleLD2();		//toggle LD2
		Delay(1000);		//create a delay of O.5 sec
		toggleCount +=1; 	//keep track of #toggles
	}
}

void InitDevice(void){
	InitSystemClock(CPU_80MHz);
	InitGpio();
}

void Delay(int count){
	volatile int i =0;
	volatile int j=0;

	for (i=0; i < count; i++){
		for(j=0; j < 5000; j++){}
	}
}
