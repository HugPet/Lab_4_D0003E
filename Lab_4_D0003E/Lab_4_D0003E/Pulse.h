/*
 * Pulse.h
 *
 * Created: 2020-02-24 15:55:16
 *  Author: User
 */ 

// .h for pulse object

#include "TinyTimber.h"
#include "DediWriter.h"
#include <stdbool.h>
#include <avr/io.h>
#ifndef PULSE_H_
#define PULSE_H_
#define NULL 0
#define initPulse(r, t, i, w) {initObject(), r, 0, t, i, w}

struct pulse_block 
{
	Object Super;
	int freq;
	int saved_freq;
	int portNum;
	int iD;
	dediWrite *writer;
};

typedef struct pulse_block pulse;

void subFreq(pulse *self);
void addFreq(pulse *self);
void storeFreq(pulse *self);
int getFreq(pulse *self);
void writeToPort(pulse *self);

#endif /* PULSE_H_ */