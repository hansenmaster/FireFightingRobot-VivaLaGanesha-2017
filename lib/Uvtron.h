#ifndef UVTRON_H
#define UVTRON_H

#include "mbed.h"

class Uvtron {
public:
	// Constructor
	Uvtron(PinName a);

	unsigned int Counter, PrevCounter, NextCounter;
	unsigned char Flag;
	unsigned char FlagScan;

	void Count();
	void Read();
	void UVScan();

private:
	InterruptIn _a;
  unsigned char i;
};

#endif

