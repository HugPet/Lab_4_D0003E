/*
 * Lab_4_D0003E.c
 *
 * Created: 2020-02-24 15:50:48
 * Author : User
 */ 

#include "TinyTimber.h"
#include "Pulse.h"
#include "DediWriter.h"
#include "LCD.h"
#include <avr/io.h>


int main(void)
{
    pulse p = initPulse();
	addFreq(p);
	LCDInit();
	printAt(p.freq, 0);
}

