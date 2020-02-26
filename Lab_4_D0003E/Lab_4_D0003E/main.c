/*
 * Lab_4_D0003E.c
 *
 * Created: 2020-02-24 15:50:48
 * Author : User
 */ 

//#include <avr/interrupt.h>

#include "TinyTimber.h"
#include "Pulse.h"
#include "DediWriter.h"
#include "LCD.h"
#include <avr/io.h>


int main(void)
{
	LCDInit();
    pulse p = initPulse(0,0);
	pulse q = initPulse(10,4);
	activate(&p);
	INSTALL(&p, addFreq, IRQ_PCINT1);
	INSTALL(&q, addFreq, IRQ_PCINT1);
	addFreq(&q);
	//printAt(getFreq(&p), getPos(&p));
	//printAt(getFreq(&q), getPos(&q));
}