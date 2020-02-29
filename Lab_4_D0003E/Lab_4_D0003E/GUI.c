/*
 * GUI.c
 *
 * Created: 2020-02-29 12:02:53
 *  Author: User
 */ 

#include "GUI.h"

void switchPulse(GUI *g) {
	if (g->pulseSwitch == 0) {
		g->pulseSwitch = 1;
	} else {
		g->pulseSwitch = 0;
	}
}

void interHandlerFreq(GUI *g, enum Vector v) {
	int i = PINB & 0x40;
	printAt(11, 2);
	if (g->pulseSwitch == 0) {
	pulse temp = g->p;
	if (i != 0x40) {
	addFreq(&temp);
	} else {
	subFreq(&temp);
	}
	} else {
	pulse temp = g->q;
	if (i != 0x40) {
	addFreq(&temp);
	} else {
	subFreq(&temp);
	}
	}
}

void printActivePulse(GUI *g) {
	if (g->pulseSwitch == 0) {
		LCDDR2 &= 0x9F;
		LCDDR2 |= 0x06;
	} else {
		LCDDR2 &= 0xF9;
		LCDDR2 |= 0x60;
	}
	printAt(g->p.freq, 0);
	printAt(g->q.freq, 4);
}