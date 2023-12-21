#include "Robot.h"
#include "Sensor.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    robotInit();

    printf("execute forward\n");
    forward(50, 10);

    printf("execute left\n");
    left(10, 2);

    printf("execute backward\n");
    backward(60, 1);

    printf("execute right\n");
    right(10, 5);

    printf("execute forward2\n");
    forward(100, 3);

    stop();
}