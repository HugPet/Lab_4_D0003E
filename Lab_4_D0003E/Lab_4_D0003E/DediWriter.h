/*
 * DediWriter.h
 *
 * Created: 2020-02-24 16:09:01
 *  Author: User
 */ 


// .h for a dedicated writer

#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "TinyTimber.h"
#define ENABLE cli()
#define DISABLE sei()
#ifndef DEDIWRITER_H_
#define DEDIWRITER_H_

#define initDediWrite() {initObject(), 0}


struct DediWriter_block{
	Object super;
	int test;
};
typedef struct DediWriter_block dediWrite;



void writeChar(char ch, int pos);
int writeReg(int num, int reg, bool shift);
void writePort(dediWrite *self, int port);


#endif /* DEDIWRITER_H_ */