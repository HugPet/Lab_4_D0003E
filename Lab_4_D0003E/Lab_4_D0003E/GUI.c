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


void printActivePulse(GUI *self) {
	if (self->pulseSwitch == 0) {
		LCDDR2 &= 0x9F;
		LCDDR2 |= 0x06;
	} else {
		LCDDR2 &= 0xF9;
		LCDDR2 |= 0x60;
	}
	ASYNC(&self->p, printAt, 0);
	ASYNC(&self->q, printAt, 4);
}

void interHandlerSwitch(GUI *self, int arg) {
	//printAt(11, 2);
	if ((PINB >> 4) == 0 || (PINB >> 3) == 0) {
		ASYNC(self, switchPulse, NULL);
	}
	ASYNC(self, printActivePulse, NULL);
}

void interHandlerFreq(GUI *self, int arg) {
	int i = PINB & 0x40;
	//printAt(22, 2);
	pulse temp;
	if (self->pulseSwitch == 0) {
		temp = self->p;
	} else {
		temp = self->q;
	}
	
	if (((PINB >> 6) & 1) == 0) {
		//printAt(99, 2);
		ASYNC(&temp, addFreq, NULL);
		ASYNC(self, printActivePulse, NULL);
	} else if (((PINB >> 7) & 1) == 0) {
			ASYNC(&temp, subFreq, NULL);
	} else {
		if (temp.freq != 0) {
			ASYNC(&temp, storeFreq, NULL);
		}
		else {
			ASYNC(&temp, restoreFreq, NULL);
		}
	}
	ASYNC(self, printActivePulse, NULL);
}