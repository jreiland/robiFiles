#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ECHO RPI_V2_GPIO_P1_18
#define TRIG RPI_V2_GPIO_P1_16

double get_time();
void gpio_reset();
