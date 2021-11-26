/**
 * @author Aaron Berk
 *
 * @section LICENSE
 *
 * Copyright (c) 2010 ARM Limited
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * CMPS10 digital compass module.
 *
 * Datasheet:
 *
 * http://www.robot-electronics.co.uk/htm/cmps3tech.htm
 */

#ifndef CMPS10_H
#define CMPS10_H

/**
 * Includes
 */
#include "mbed.h"

/**
 * Defines
 */
#define CMPS10_DEFAULT_I2C_ADDRESS 0xC0

//-----------
// Registers
//-----------
#define SOFTWARE_REVISION_REG    0x0
#define COMPASS_BEARING_WORD_REG 0x2

/**
 * CMPS10 digital compass module.
 */
class CMPS10 {
	public:
		/**
		 * Constructor.
		 *
		 * @param sda mbed pin to use for I2C SDA
		 * @param scl mbed pin to use for I2C SCL
		 * @param address I2C address of this device.
		 */
		CMPS10(PinName sda, PinName scl, int address);

		/**
		 * Reads the software revision register [register 0] on the device.
		 *
		 * @return The contents of the software revision register as a byte.
		 */
		char readSoftwareRevision(void);

		/**
		 * Reads the current bearing of the compass.
		 *
		 * @return The current bearing of the compass as a value between 0 and 3599,
		 *         representing 0 - 359.9 degrees.
		 */
		int readBearing(void);

		void Kalibrasi(void);
		void Reset(void);

	private:
		I2C* i2c;
		int  i2cAddress;
};

#endif /* CMPS10_H */
