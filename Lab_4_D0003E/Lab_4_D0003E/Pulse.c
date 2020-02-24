/*
 * Pulse.c
 *
 * Created: 2020-02-24 15:55:41
 *  Author: User
 */ 

// .c for pulse object

#include "Pulse.h"


void subFreq(pulse p) {
	if (p.freq > 0) {
		p.freq--;
	}
}

void addFreq(pulse p) {
	if (p.freq < 99) {
		p.freq++;
	}
}

void storeFreq(pulse p) {
	p.saved_freq = p.freq;
}

void restoreFreq(pulse p) {
	p.freq = p.saved_freq;
}
