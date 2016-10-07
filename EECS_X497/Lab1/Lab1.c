/*
 * Lab1.c
 *
 *  Created on: 3 oct. 2016
 *      Author: Aymeric
 */

// Includes
#include <math.h>

// Defines
#define TWO_THIRDS_PI 2.0943951
#define NUM_PHASES 3
#define NUM_SAMPLES 100
#define STEP_SCALE 0.1

// Global Variables
float volt[NUM_PHASES][NUM_SAMPLES];
float mag = 3; // sine function magnitude
float omega = 2; // sine function frequency

// main() function
void main( void ){
	int ii;
	float angle;
	while ( 1 ){
		for ( ii = 0; ii < NUM_SAMPLES; ii++ ){
			angle = omega * ii * STEP_SCALE;
			volt[0][ii] = mag * sin( angle );
			volt[1][ii] = mag * sin( angle + TWO_THIRDS_PI );
			volt[2][ii] = mag * sin( angle - TWO_THIRDS_PI );
		} // end for ii
		asm( " NOP" ); // empty executable line for breakpoint
	} // end while 1
} // end main()
