#include<stdio.h>
#include<bcm2835.h>
#include"MotorHat.h"

#ifndef ROBOT
#define ROBOT

void robotInit();
void setLeftSpeed(int speed);
void setRightSpeed(int speed);
void stop();
void forward(int speed, int seconds);
void backward(int speed, int seconds);
void right(int speed, int seconds);
void left(int speed, int seconds);

#endif

