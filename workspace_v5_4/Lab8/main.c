#include <msp430g2553.h>
#include "move.h"
#include "sensor.h"
/*
 * main.c
 */

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    initSensors();
	pulseWidthModulation();
    for(;;){
    		int leftWall = closeLeft(0x2FF);
    		int frontWall = closeCenter(0x1FF);
    		if (frontWall == 1){
    			turnRight(50,50,35);
    		}
    		/*else if (frontWall == 1 && leftWall ==0){
    			turnLeft(50,50, 100);
    		}*/
    		else if (frontWall == 0 && leftWall == 1) {
    		    turnRight(50,50,1);
    		}
    		else {
    			moveForward(50,50,60);
    			turnLeft(40,50,15);
    			stop();
    			__delay_cycles(10);
    		}
    }
	return 0;
}
