/*
 * Pulse.c
 *
 * Created: 2020-02-24 15:55:41
 *  Author: User
 */ 

// .c for pulse object

#include "Pulse.h"

#include "LCD.h"


void subFreq(pulse *self) {
	if (self->freq > 0) {
		self->freq--;
	}
}

void addFreq(pulse *self) {
	if (self->freq < 99) {
		self->freq++;
	}
}

void storeFreq(pulse *self) {
	self->saved_freq = self->freq;
	self->freq = 0;
}

void restoreFreq(pulse *self) {
	self->freq = self->saved_freq;
	self->saved_freq = 0;
}

int getFreq(pulse *self) {
	return self->freq;
}

void printAt(pulse *self, int pos) {
	int num = self->freq;
	int pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;
	writeChar( num % 10 + '0', pp);
}