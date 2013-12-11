#include<msp430.h>
/*
 * move.c
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Trevor.Moore
 */
int i;
void pulseWidthModulation(){

	P1DIR |= BIT1|BIT2;	//Set pins as outputs
	P1SEL |= BIT1|BIT2;
	P2DIR |= BIT0|BIT1;
	P2SEL |= BIT0|BIT1;

	TA0CTL &= ~(MC1|MC0);  			//Stop timers
	TA1CTL &= ~(MC1|MC0);

    TA0CTL |= TACLR;                // clear timer A0
    TA1CTL |= TACLR;

    TA0CTL |= TASSEL1;				// configure for SMCLK
    TA1CTL |= TASSEL1;

    TA0CCR0 = 100;
    TA1CCR0 = 100;

    TA0CTL |= MC0;					//start timer
    TA1CTL |= MC0;
}

void moveLeftWheelForward(char speed){
	TA0CTL &= ~(MC0|MC1);
	TA0CCR1= speed;
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA0CCTL1 |= OUTMOD_7;
	TA0CCTL0 |= OUTMOD_5;
	TA0CTL |= MC0;
}
void moveLeftWheelBackward(char speed){
	TA0CTL &= ~(MC0|MC1);
	TA0CCR1= speed;
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA0CCTL1 |= OUTMOD_5;
	TA0CCTL0 |= OUTMOD_4;
	TA0CTL |= MC0;
}
void stopLeftWheel(){
	TA0CTL &= ~(MC0|MC1);
	TA0CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA0CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA0CCTL1 |= OUTMOD_5;
	TA0CCTL0 |= OUTMOD_5;
	TA0CTL |= MC0;
}
void moveRightWheelForward(char speed){
	TA1CTL &= ~(MC0|MC1);
	TA1CCR1= speed;
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL1 |= OUTMOD_7;
	TA1CCTL0 |= OUTMOD_5;
	TA1CTL |= MC0;
}
void moveRightWheelBackward(char speed){
	TA1CTL &= ~(MC0|MC1);
	TA1CCR1= speed;
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL1 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_4;
	TA1CTL |= MC0;
}
void stopRightWheel(){
	TA1CTL &= ~(MC0|MC1);
	TA1CCTL0 &= ~(OUTMOD_4|OUTMOD_5);
	TA1CCTL1 &= ~(OUTMOD_7|OUTMOD_5);
	TA1CCTL1 |= OUTMOD_5;
	TA1CCTL0 |= OUTMOD_5;
	TA1CTL |= MC0;
}
void moveForward(char speedLeft, char speedRight, int clocks){
	moveLeftWheelForward(speedLeft);
	moveRightWheelForward(speedRight);
	for(i=1; i<=clocks; i++){
		_delay_cycles(100);
	}
}
void moveBackward(char speedLeft, char speedRight, int clocks){
	moveLeftWheelBackward(speedLeft);
	moveRightWheelBackward(speedRight);
	for(i=1; i<=clocks; i++){
		_delay_cycles(100);
	}
}
void stop(){
	stopLeftWheel();
	stopRightWheel();
}
void turnLeft(char speedLeft, char speedRight, int clocks){
	moveLeftWheelBackward(speedLeft);
	moveRightWheelForward(speedRight);
	for(i=1; i<=clocks; i++){
		_delay_cycles(100);
	}
}
void turnRight(char speedLeft, char speedRight, int clocks){
	moveRightWheelBackward(speedRight);
	moveLeftWheelForward(speedLeft);
	for(i=1; i<=clocks; i++){
		_delay_cycles(100);
	}
}
void veerRight(char speedRight, int clocks){
	moveRightWheelBackward(speedRight);
	stopLeftWheel();
	for(i=1; i<=clocks; i++){
		_delay_cycles(10);
	}
}
