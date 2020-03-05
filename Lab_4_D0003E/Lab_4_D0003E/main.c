/*
 * Lab_4_D0003E.c
 *
 * Created: 2020-02-24 15:50:48
 * Author : User
 */ 

//#include <avr/interrupt.h>

#include "TinyTimber.h"
//#include "GUI.h"
//#include "Pulse.h"
#include "GUI.h"
#include "DediWriter.h"
#include "LCD.h"
#include <avr/io.h>


int main(void)
{
	LCDInit();
	dediWrite w = initDediWrite();
    pulse p = initPulse(0, 4, 0, &w);
	pulse q = initPulse(0, 6, 1, &w);
	GUI g = GUI_init(&p, &q);
	INSTALL(&g, interHandlerFreq, IRQ_PCINT1);
	INSTALL(&g, interHandlerSwitch, IRQ_PCINT0);
	return TINYTIMBER(&g, printActivePulse, NULL);
	//addFreq(&q);
	//printAt(getFreq(&p), getPos(&p));
	//printAt(getFreq(&q), getPos(&q));
}