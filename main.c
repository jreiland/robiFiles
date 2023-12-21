#include "Robot.h"
#include "Sensor.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    robotInit();

    // printf("execute forward\n");
    // forward(100, 2);

    // printf("execute left\n");
    // left(100, 2);

    // printf("execute backward\n");
    // backward(100, 2);

    // printf("execute right\n");
    // right(100, 2);

    // printf("execute forward2\n");
    // forward(100, 2);

    double pulse_start, pulse_end, pulse_duration;
    double distance;


    bcm2835_gpio_fsel(ECHO, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(TRIG, BCM2835_GPIO_FSEL_OUTP);

    bcm2835_gpio_write(TRIG,LOW);

    printf("Waiting for sensor to settle\n");

    bcm2835_delay(2000);

    while (1){
        

        printf("Set TRIG to true\n");

        bcm2835_gpio_write(TRIG,HIGH);

        printf("Sleep\n");

        bcm2835_delayMicroseconds(10);

        printf("Set TRIG to false\n");

        bcm2835_gpio_write(TRIG,LOW);

        printf("First while loop\n");

        while (bcm2835_gpio_lev(ECHO)==0)
            pulse_start = get_time();//get the time in microseconds

        printf("pulse start: %Lf\n",pulse_start);

        printf("Second while loop\n");

        while(bcm2835_gpio_lev(ECHO)==1)
            pulse_end = get_time();//get the time in micorseconds

        printf("pulse end:%Lf\n",pulse_end);

        //pulse_duration = (double)(pulse_end - pulse_start)/CLOCKS_PER_SEC;
        //CLOCKS_PER_SEC is equal to 1000000 on the raspberry pi.
        //in order for this to work, you have to get the time in micro seconds.

        pulse_duration = (pulse_end - pulse_start)/1000000;

        printf("pulse duration:%Lf\n",pulse_duration);

        distance = pulse_duration * 17150;

        printf("Distance:%.2f cm\n",distance);

        forward(100, -1);

        if (distance < 5 || distance > 1000){
            stop();
            backward(50, 1);
            stop();
            right(2, 1);
            stop();
            continue;
        }
    }

    bcm2835_close();

    stop();

    return 0;
}