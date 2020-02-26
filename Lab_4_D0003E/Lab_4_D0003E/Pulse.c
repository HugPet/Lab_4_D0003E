/*
 * Pulse.c
 *
 * Created: 2020-02-24 15:55:41
 *  Author: User
 */ 

// .c for pulse object

#include "Pulse.h"

#include "LCD.h"

void subFreq(pulse *p) {
	if (p->freq > 0 && p->active) {
		p->freq--;
	}
}

void addFreq(pulse *p) {
	int i = PINB & 0x40;
	if (p->freq < 99 && p->active) {
		if (i != 0x40) {
			p->freq++;
		} i = PINB & 0x80;
		if (i != 0x80) {
			p->freq--;
		}
	}
	printAt(getFreq(p), getPos(p));
}

void storeFreq(pulse *p) {
	p->saved_freq = p->freq;
}

void restoreFreq(pulse *p) {
	p->freq = p->saved_freq;
}

void activate(pulse *p) {
	p->active = true;
}

void deactivate(pulse *p) {
	p->active = false;
}

int getFreq(pulse *p) {
	return p->freq;
}

int getPos(pulse *p) {
	return p->pos;
}