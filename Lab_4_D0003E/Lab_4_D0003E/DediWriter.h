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
#define ENABLE cli()
#define DISABLE sei()
#ifndef DEDIWRITER_H_
#define DEDIWRITER_H_

void writeChar(char ch, int pos);
int writeReg(int num, int reg, bool shift);



#endif /* DEDIWRITER_H_ */