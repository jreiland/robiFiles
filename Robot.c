#include "Robot.h"

extern void robotInit(){
    initHat();
    initMotors();
    run(RELEASE, 0);    //left motor off
    run(RELEASE, 1);    //right motor off
}

extern void setLeftSpeed(int speed){
    //add error checking later
    setSpeed(motors[0].pwm, speed);
}

extern void setRightSpeed(int speed){
    //add error checking later
    setSpeed(motors[1].pwm, speed);
}

extern void stop(){
    run(RELEASE, 0);    //left motor off
    run(RELEASE, 1);    //right motor off
}

extern void forward(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(FORWARD, 0);    //left motor forward
    run(FORWARD, 1);    //right motor forward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}

extern void backward(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(BACKWARD, 0);    //left motor backward
    run(BACKWARD, 1);    //right motor backward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}

extern void right(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(FORWARD, 0);    //left motor forward
    run(BACKWARD, 1);    //right motor backward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}

extern void left(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(BACKWARD, 0);    //left motor backward
    run(FORWARD, 1);    //right motor forward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}