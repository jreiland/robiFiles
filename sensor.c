// #include<bcm2835.h>
// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// #include<sys/time.h>

// #define ECHO RPI_V2_GPIO_P1_18
// #define TRIG RPI_V2_GPIO_P1_16

#include "Sensor.h"

extern double get_time()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_usec;
}

extern void gpio_reset()
{
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_18, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_16, BCM2835_GPIO_PUD_OFF);

	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_18, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_16, BCM2835_GPIO_FSEL_INPT);
}