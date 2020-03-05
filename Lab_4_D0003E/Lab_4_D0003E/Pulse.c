/*
 * Pulse.c
 *
 * Created: 2020-02-24 15:55:41
 *  Author: User
 */ 

// .c for pulse object

#include "Pulse.h"
#include "DediWriter.h"
#include "LCD.h"


void subFreq(pulse *self) {
	if (self->freq > 0) {
		self->freq--;
	}
}

void addFreq(pulse *self) {
	if (self->freq == 0) {
		self->freq++;
		AFTER((MSEC(500)/self->freq), self, writeToPort, NULL);
	} else if (self->freq < 99){
		self->freq++;
	}
}

void storeFreq(pulse *self) {
	if (self->freq != 0){
		self->saved_freq = self->freq;
		self->freq = 0;
	} else if (self->saved_freq != 0){
		self->freq = self->saved_freq;
		self->saved_freq = 0;
		AFTER((MSEC(500)/self->freq), self, writeToPort, NULL);
	}
}

void writeToPort(pulse *self){
	if (self->freq != 0){
		SYNC(self->writer, writePort, self->portNum);
		AFTER((MSEC(500)/self->freq), self, writeToPort, NULL);
	}
}

int getFreq(pulse *self) {
	return self->freq;
}