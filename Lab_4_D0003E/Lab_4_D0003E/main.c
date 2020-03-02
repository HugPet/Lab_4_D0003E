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
#include "interHandlers.h"
#include "DediWriter.h"
#include "LCD.h"
#include <avr/io.h>


int main(void)
{
	LCDInit();
    pulse p = initPulse(0, 0);
	pulse q = initPulse(30, 1);
	GUI g = GUI_init(p, q);
	INSTALL(&g, interHandlerFreq, IRQ_PCINT1);
	INSTALL(&g, interHandlerSwitch, IRQ_PCINT0);
	return TINYTIMBER(&g, printActivePulse, NULL);
	//addFreq(&q);
	//printAt(getFreq(&p), getPos(&p));
	//printAt(getFreq(&q), getPos(&q));
}