/*
 * DediWriter.c
 *
 * Created: 2020-02-24 16:08:46
 *  Author: User
 */ 

// .c for a dedicated writer

#include "DediWriter.h"


void writeToOsc(dediWrite *self) {
	if (self->pOn) {
		PORTE &= 0xEF;
		PORTE |= (1 << self->p.portNum);
	} else {
		PORTE &= 0xEF;
		PORTE |= (0 << self->p.portNum);
	}
	
	if (self->qOn) {
		PORTE &= 0xBF;
		PORTE |= (1 << self->q.portNum);
	} else {
		PORTE &= 0xBF;
		PORTE |= (0 << self->q.portNum);
	}
}

void writeA(dediWrite *self) {
	if (self->pOn) {
		PORTE &= 0xEF;
		PORTE |= (1 << self->p.portNum);
	} else {
		PORTE &= 0xEF;
		PORTE |= (0 << self->p.portNum);
	}
	self->pOn = !self->pOn;
	
	//writeToOsc(self);
	if (self->p.freq != 0) {
		int tim = 1/2*(self->p.freq);
		AFTER(SEC(tim), self, writeA, NULL);
		return;
	} AFTER(MSEC(400), self, writeA, NULL);
}

void writeB(dediWrite *self) {
	self->qOn = !self->qOn;
	if (self->qOn) {
		PORTE &= 0xEF;
		PORTE |= (1 << self->q.portNum);
	} else {
		PORTE &= 0xEF;
		PORTE |= (0 << self->q.portNum);
	}
	//writeToOsc(self);
	if (self->q.freq != 0) {
		int tim = 1/2*(self->q.freq);
		AFTER(SEC(tim), self, writeB, NULL);
		return;
	} AFTER(MSEC(400), self, writeB, NULL);
}

void writeChar(char ch, int pos){
	DISABLE;
	int SCC_X_0 = 0, SCC_X_1 = 0, SCC_X_2 = 0, SCC_X_3 = 0;
		
	switch (ch)					/* a switch statement for which character is to be printed on the display.
								   sets various bytes of SCC_X to certain values, depending on which areas
								   should light up. These values are derived from the documentation.    */
	{
	case '0' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x5;
		SCC_X_2 = 0x5;
		SCC_X_3 = 0x1;
		
		break;
	case '1' :
		SCC_X_0 = 0x0;
		SCC_X_1 = 0x1;
		SCC_X_2 = 0x1;
		SCC_X_3 = 0x0;
		break;
	case '2' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x1;
		SCC_X_2 = 0xE;
		SCC_X_3 = 0x1;
		break;
	case '3' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x1;
		SCC_X_2 = 0xb;
		SCC_X_3 = 0x1;
		break;
	case '4' :
		SCC_X_0 = 0x0;
		SCC_X_1 = 0x5;
		SCC_X_2 = 0xb;
		SCC_X_3 = 0x0;
		break;
	case '5' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x4;
		SCC_X_2 = 0xb;
		SCC_X_3 = 0x1;
		break;
	case '6' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x4;
		SCC_X_2 = 0xf;
		SCC_X_3 = 0x1;
		break;
	case '7' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x1;
		SCC_X_2 = 0x1;
		SCC_X_3 = 0x0;
		break;
	case '8' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x5;
		SCC_X_2 = 0xf;
		SCC_X_3 = 0x1;
		break;
	case '9' :
		SCC_X_0 = 0x1;
		SCC_X_1 = 0x5;
		SCC_X_2 = 0xb;
		SCC_X_3 = 0x1;
		break;
	default:
		return;
	}
	
	switch(pos){										/* a switch statement for the position of the digit. Depending on the position 
														   we will write to different registers. We use a boolean value to show if 
														   the lower byte of the register or not, since the positions are paired up 
														   per register. */
	case 0:
		LCDDR0=writeReg(SCC_X_0, LCDDR0, false);
		LCDDR5=writeReg(SCC_X_1, LCDDR5, false);
		LCDDR10=writeReg(SCC_X_2, LCDDR10, false);
		LCDDR15=writeReg(SCC_X_3, LCDDR15, false);		
		break;
	case 1:
		LCDDR0=writeReg(SCC_X_0, LCDDR0, true);
		LCDDR5=writeReg(SCC_X_1, LCDDR5, true);
		LCDDR10=writeReg(SCC_X_2, LCDDR10, true);
		LCDDR15=writeReg(SCC_X_3, LCDDR15, true);
		break;
	case 2:
		LCDDR1 = writeReg(SCC_X_0, LCDDR1, false);
		LCDDR6 = writeReg(SCC_X_1, LCDDR6, false);
		LCDDR11 = writeReg(SCC_X_2, LCDDR11, false);
		LCDDR16 = writeReg(SCC_X_3, LCDDR16, false);
		break;
	case 3:
		LCDDR1 = writeReg(SCC_X_0, LCDDR1, true);
		LCDDR6 = writeReg(SCC_X_1, LCDDR6, true);
		LCDDR11 = writeReg(SCC_X_2, LCDDR11, true);
		LCDDR16 = writeReg(SCC_X_3, LCDDR16, true);
		break;
	case 4:
		LCDDR2 &= 0xF6;
		LCDDR2 |= writeReg(SCC_X_0, LCDDR2, false);
		LCDDR7 = writeReg(SCC_X_1, LCDDR7, false);
		LCDDR12 = writeReg(SCC_X_2, LCDDR12, false);
		LCDDR17 = writeReg(SCC_X_3, LCDDR17, false);
		break;
	case 5:
		LCDDR2 &= 0x6F;
		LCDDR2 |= writeReg(SCC_X_0, LCDDR2, true);
		LCDDR7 = writeReg(SCC_X_1, LCDDR7, true);
		LCDDR12 = writeReg(SCC_X_2, LCDDR12, true);
		LCDDR17 = writeReg(SCC_X_3, LCDDR17, true);
		break;
	default:
		ENABLE;
		return;
	}
	ENABLE;
	return;
}


/* A function for writing to a register, specifically the registers for 
   lighting up areas of the display. **/
int writeReg(int num, int reg, bool shift){
	if(!shift){
		reg &= 0xF0;
		reg |= num;
	}
	else{
		reg &= 0x0F;
		reg |= (num<<4);
	}
	return reg;
}

void printAt(dediWrite *self) {
	int *num1 = &self->p.freq;
	int *num2 = &self->q.freq;
	//writeChar( *num1 % 10 + '0', 2);
	writeChar( (*num1 % 100) / 10 + '0', 0);
	writeChar( (*num2 % 100) / 10 + '0', 4);
	writeChar( *num1 % 10 + '0', 1);
	writeChar( *num2 % 10 + '0', 5);
}