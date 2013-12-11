/*
 * move.h
 *
 *  Created on: Nov 20, 2013
 *      Author: C15Trevor.Moore
 */

#ifndef MOVE_H_
#define MOVE_H_

void pulseWidthModulation();
void moveLeftWheelForward(char speed);
void moveLeftWheelBackward(char speed);
void stopLeftWheel();
void moveRightWheelForward(char speed);
void moveRightWheelBackward(char speed);
void stopRightWheel();
void moveForward(char speedLeft, char speedRight, int clocks);
void moveBackward(char speedLeft, char speedRight, int clocks);
void stop();
void turnLeft(char speedLeft, char speedRight, int clocks);
void turnRight(char speedLeft,char speedRight, int clocks);
void veerRight(char speedRight, int clocks);
#endif /* MOVE_H_ */
