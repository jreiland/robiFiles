#include "Robot.h"
#include "Sensor.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    robotInit();    //initialize hat and motors

    double pulse_start, pulse_end, pulse_duration;
    double distance;

    //get input from sensor
    bcm2835_gpio_fsel(ECHO, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_fsel(TRIG, BCM2835_GPIO_FSEL_OUTP);

    printf("Waiting for sensor to settle\n");

    bcm2835_delay(2000); 

    while (1){
        //set up sensor and measure time to for sound to come back
        bcm2835_gpio_write(TRIG,LOW);

        printf("Set TRIG to true\n");

        bcm2835_gpio_write(TRIG,HIGH);

        printf("Sleep\n");

        bcm2835_delayMicroseconds(10);

        printf("Set TRIG to false\n");

        bcm2835_gpio_write(TRIG,LOW);

        printf("First while loop\n");

        while (bcm2835_gpio_lev(ECHO)==0)
            pulse_start = get_time();//get the time in microseconds

        while(bcm2835_gpio_lev(ECHO)==1)
            pulse_end = get_time();//get the time in micorseconds

        pulse_duration = (pulse_end - pulse_start)/1000000;

        distance = pulse_duration * 17150;

        printf("Distance:%.2f cm\n",distance);

        if (distance < 8){  //if distance less than 8cm, back up and turn right before proceeding
            printf("going backward\n");
            backward(100, 1);
            printf("turning right\n");
            right(40, 1);
            continue;
        }
        else{
            printf("going forward\n");
            forward(100, -1);   //go forward unless distance is too close
        }
    }

    bcm2835_close();
    stop();
    return 0;
}