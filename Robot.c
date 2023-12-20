#include "Robot.h"

extern void robotInit(){
    initHat();
    run(RELEASE, motors[1]);    //left motor off
    run(RELEASE, motors[2]);    //right motor off
}

extern void setLeftSpeed(int speed){
    //add error checking later
    setSpeed(motors[1].pwm, speed);
}

extern void setRightSpeed(int speed){
    //add error checking later
    setSpeed(motors[2].pwm, speed);
}

extern void stop(){
    run(RELEASE, 1);    //left motor off
    run(RELEASE, 2);    //right motor off
}

extern void forward(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(FORWARD, 1);    //left motor forward
    run(FORWARD, 2);    //right motor forward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}

extern void backward(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(BACKWARD, 1);    //left motor backward
    run(BACKWARD, 2);    //right motor backward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}

extern void right(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(FORWARD, 1);    //left motor forward
    run(BACKWARD, 2);    //right motor backward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}

extern void left(int speed, int seconds){
    setLeftSpeed(speed);
    setRightSpeed(speed);
    run(BACKWARD, 1);    //left motor backward
    run(FORWARD, 2);    //right motor forward
    if (seconds > 0){   //definite
        sleep(seconds);
        stop();
    }
}