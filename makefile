robi: main.c I2C.c MotorHat.c PWM.c Robot.c Sensor.c
	gcc -c I2C.c MotorHat.c PWM.c Robot.c sensor.c
	gcc -o test.out main.c I2C.o MotorHat.o PWM.o Robot.o sensor.o -lbcm2835 -lm