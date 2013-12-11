#include<msp430g2553.h>
#include"sensor.h"
/*
 * sensor.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Trevor.Moore
 */
int leftWall;
int frontWall;
void initSensors(){
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK
    ADC10CTL1 |= ADC10DIV_7;
    P1DIR |= BIT0|BIT6;                            // Set P1.0 to output direction
    P1OUT &= ~(BIT0|BIT6);
}
void leftSensorTest(){
    ADC10CTL0 &= ~ENC;
    ADC10CTL1 &= ~(INCH_3|INCH_4|INCH_5);
    ADC10CTL1 |= INCH_3;
    ADC10AE0 &= ~(BIT3|BIT4|BIT5);
    ADC10AE0 |= BIT3;
    ADC10CTL0 |= ENC + ADC10SC;

}

void centerSensorTest(){
    ADC10CTL0 &= ~ENC;
    ADC10CTL1 &= ~(INCH_3|INCH_4|INCH_5);
    ADC10CTL1 |= INCH_4;
    ADC10AE0 &= ~(BIT3|BIT4|BIT5);
    ADC10AE0 |= BIT4;
    ADC10CTL0 |= ENC + ADC10SC;

}
void rightSensorTest(){
    ADC10CTL0 &= ~ENC;
    ADC10CTL1 &= ~(INCH_3|INCH_4|INCH_5);
    ADC10CTL1 |= INCH_5;
    ADC10AE0 &= ~(BIT3|BIT4|BIT5);
    ADC10AE0 |= BIT5;
    ADC10CTL0 |= ENC + ADC10SC;

}
int closeLeft(int threshold){
	leftSensorTest();
    __bis_SR_register(CPUOFF + GIE);
	if (ADC10MEM < threshold){
	  P1OUT &= ~BIT0;                       // Clear P1.0 LED off
		leftWall = 0;
	}
	else{
	  P1OUT |= BIT0;
	  leftWall =1;
	}
	return leftWall;
}
void closeRight(int threshold){
	rightSensorTest();
    __bis_SR_register(CPUOFF + GIE);
	if (ADC10MEM < threshold)
	  P1OUT &= ~BIT6;                       // Clear P1.0 LED off
	else
	  P1OUT |= BIT6;
}

int closeCenter(int threshold){
	centerSensorTest();
    __bis_SR_register(CPUOFF + GIE);
	if (ADC10MEM < threshold){
	  P1OUT &= ~BIT6;                       // Clear P1.0 LED off
	 frontWall =0;
	}
	  else{
	  P1OUT |= BIT6;
	  frontWall = 1;
	  }
	return frontWall;
}
// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}


