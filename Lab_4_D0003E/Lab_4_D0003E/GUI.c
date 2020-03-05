/*
 * GUI.c
 *
 * Created: 2020-02-29 12:02:53
 *  Author: User
 */ 

#include "GUI.h"

void printActivePulse(GUI *self) {
	printAt(self->p->freq, 0);
	printAt(self->q->freq, 4);
}

void printAt(long num, int pos) {
	int pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
}

void interHandlerSwitch(GUI *self, int arg) {
	if (((PINE >> 3) & 1) == 0) {
		self->activePulse = self->q;
		LCDDR2 &= 0xF9;
		LCDDR2 |= 0x60;
	} else if (((PINE >> 2) & 1) == 0){
		self->activePulse = self->p;
		LCDDR2 &= 0x9F;
		LCDDR2 |= 0x06;
	}
}

void interHandlerFreq(GUI *self, int arg) {
	if (((PINB >> 6) & 1) == 0) {
		SYNC(self->activePulse, addFreq, NULL);
		pressing(self);
		printActivePulse(self);
		return;
	} else if (((PINB >> 7) & 1) == 0) {
		SYNC(self->activePulse, subFreq, NULL);
		pressing(self);
		printActivePulse(self);
		return;
	} else if (((PINB >> 4) & 1) == 0) {
		SYNC(self->activePulse, storeFreq, NULL);
		printActivePulse(self);
	}
}

void pressing(GUI *self) {
	if (!self->held) {
		self->increment = 0;
		self->held = true;
		AFTER(MSEC(1000), self, pressing, NULL);
		return;
	} else if (((PINB >> 6) & 1) == 0) {
		if (self->increment%100 ==0) ASYNC(self->activePulse, addFreq, NULL);
		printActivePulse(self);
		self->increment++;
		AFTER(MSEC(400), self, pressing, NULL);
		return;
	} else if (((PINB >> 7) & 1) == 0) {
		if (self->increment%100 ==0) ASYNC(self->activePulse, subFreq, NULL);
		printActivePulse(self);
		self->increment++;
		AFTER(MSEC(400), self, pressing, NULL);
		return;
	} else {
			self->held =false;
			self->increment = 0;
	}
}