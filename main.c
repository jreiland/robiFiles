#include "Robot.h"
#include "Sensor.h"

int main(int argc, char *argv[]){
    robotInit();
    forward(50, 10);
    //left(10, 2);
    //backward(60, 1);
    //right(10, 5);
    //forward(100, 3);
    stop();
}