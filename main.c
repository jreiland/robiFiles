#include "Robot.h"
#include "Sensor.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    robotInit();

    printf("execute forward\n");
    forward(100, 2);

    printf("execute left\n");
    left(100, 2);

    printf("execute backward\n");
    backward(100, 2);

    printf("execute right\n");
    right(100, 2);

    printf("execute forward2\n");
    forward(100, 2);

    stop();
}