/*
 * sensor.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Trevor.Moore
 */

#ifndef SENSOR_H_
#define SENSOR_H_
void initSensors();
void leftSensorTest();
void centerSensorTest();
void rightSensorTest();
int closeLeft(int threshold);
void closeRight(int threshold);
int closeCenter(int threshold);
#endif /* SENSOR_H_ */
