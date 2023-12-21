#include "MotorHat.h"

extern void initMotors(){   //initialize motors
    motors[0].pwm = 8;
    motors[0].in2 = 9;
    motors[0].in1 = 10;

    motors[1].pwm = 13;
    motors[1].in2 = 12;
    motors[1].in1 = 11;

    motors[2].pwm = 2;
    motors[2].in2 = 3;
    motors[2].in1 = 4;

    motors[3].pwm = 7;
    motors[3].in2 = 6;
    motors[3].in1 = 5;
}

extern void initHat(){  //initialize i2c and PWM
    i2cInit(0x60);
    PWMInit(0x60);
    setPWMFreq(1600);
}

extern void setSpeed(int pin, int speed){
    setPWM(pin, 0, speed*16);
}

extern void run(unsigned char command, unsigned char motorID){  //set up FORWARD, BACKWARD, and RELEASE commands
    if (command == FORWARD){
        setPin(motors[motorID].in2, 1);
        setPin(motors[motorID].in1, 0);
    }
    else if (command == BACKWARD){
        setPin(motors[motorID].in2, 0);
        setPin(motors[motorID].in1, 1);
    }
    else if (command == RELEASE){
        setPin(motors[motorID].in2, 0);
        setPin(motors[motorID].in1, 0);
    }
}

extern void setPin(unsigned char pin, unsigned char value){ //to set correct motor pin
    if (value == 0){
        setPWM(pin, 0, 4096);
    }
    else if (value == 1){
        setPWM(pin, 4096, 0);
    }
}