/*
 * GUI.c
 *
 * Created: 2020-02-29 12:02:53
 *  Author: User
 */ 

#include "GUI.h"

void switchPulse(GUI *self) {
	if (self->activePulse.iD == 0) {
		self->activePulse = self->q;
	} else {
		self->activePulse = self->p;
	}
}


void printActivePulse(GUI *self) {
	//ASYNC(&self->p, addFreq, NULL);
	if (self->activePulse.iD == 0) {
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
	if (((PINE >> 2) & 1) == 0 || ((PINE >> 3) & 1) == 0) {
		SYNC(self, switchPulse, NULL);
	}
	ASYNC(self, printActivePulse, NULL);
}

void interHandlerFreq(GUI *self, int arg) {
	if (((PINB >> 6) & 1) == 0) {
		//printAt(99, 2);
		SYNC(&self->activePulse, addFreq, NULL);
		ASYNC(self, pressing, NULL);
		ASYNC(self, printActivePulse, NULL);
		return;
	} else if (((PINB >> 7) & 1) == 0) {
		SYNC(&self->activePulse, subFreq, NULL);
		ASYNC(self, pressing, NULL);
		ASYNC(self, printActivePulse, NULL);
		return;
	} else if (((PINB >> 4) & 1) == 0) {
		if (SYNC(&self->activePulse, getFreq, NULL) != 0) {
			SYNC(&self->activePulse, storeFreq, NULL);
			ASYNC(self, printActivePulse, NULL);
		}
		else {
			SYNC(&self->activePulse, restoreFreq, NULL);
			ASYNC(self, printActivePulse, NULL);
		}
	}
}

void pressing(GUI *self) {
	if (self->heldU == false || self->heldD == false) {
		if (((PINB >> 6) & 1) == 0) {self->heldU = true; }
		else if (((PINB >> 7) & 1) == 0) {self->heldD = true; }
		AFTER(MSEC(500), self, pressing, NULL);
		return;
	} else if (self->heldU || self->heldD) {
		if (((PINB >> 6) & 1) == 0 && self->heldU) {
			SYNC(&self->activePulse, addFreq, NULL);
			ASYNC(self, printActivePulse, NULL);
			AFTER(MSEC(100), self, pressing, NULL);
			return;
		} else if (((PINB >> 7) & 1) == 0 && self->heldD) {
			SYNC(&self->activePulse, addFreq, NULL);
			ASYNC(self, printActivePulse, NULL);
			AFTER(MSEC(100), self, pressing, NULL);
			return;
		} else {
			self->heldU = false;
			self->heldD = false;
		}
	}
}