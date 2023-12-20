#include "PWM.h"
#include <time.h>
#include <math.h>

extern void setAllPWM(int on, int off){
    write8(__ALL_LED_ON_L, on & 0xFF);
    write8(__ALL_LED_ON_H, on >> 8);
    write8(__ALL_LED_OFF_L, off & 0xFF);
    write8(__ALL_LED_OFF_H, off >> 8);
}

extern void PWMInit(unsigned int address){
    setAllPWM(0, 0);
    write8(__MODE2, __OUTDRV);
    write8(__MODE1, __ALLCALL);
    usleep(5000);
    unsigned int mode1 = readU8(__MODE1);
    mode1 = mode1 & ~__SLEEP;
    write8(__MODE1, mode1);
    usleep(5000);
}

extern void setPWMFreq(int freq){
    float preScaleVal = 25000000.0; //25 mhz
    preScaleVal /= 4096.0;
    preScaleVal = preScaleVal / float(freq);
    preScaleVal -= 1.0;
    float preScale = floorf(preScaleVal + 0.5);
    unsigned int oldMode = readU8(__MODE1);
    unsigned int newMode = readU8(oldMode & 0x7F) | 0x10; //sleep
    write8(__MODE1, newMode);
    write8(__PRESCALE, unsigned int(floorf(preScale)));
    write8(__MODE1, oldMode);
    usleep(5000);
    write8(__MODE1, oldMode | 0x80);
}

extern void setPWM(int channel, int on, int off){
    write8(__LED0_ON_L+4*channel, on & 0xFF);
    write8(__LED0_ON_H+4*channel, on >> 8);
    write8(__LED0_OFF_L+4*channel, off & 0xFF);
    write8(__LED0_OFF_H+4*channel, off >> 8);
}