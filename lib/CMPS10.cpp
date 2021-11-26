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

/**
 * Includes
 */
#include "CMPS10.h"
#include "ObjectVariabel.h"
#include "mbed.h"
CMPS10::CMPS10(PinName sda, PinName scl, int address) {

    i2c = new I2C(sda, scl);
    //Compass designed to work at 100KHz. See datasheet for details.
    i2c->frequency(100000);
    i2cAddress = address;

}

char CMPS10::readSoftwareRevision(void){

    char registerNumber   = SOFTWARE_REVISION_REG;
    char registerContents = 0;

    //First, send the number of register we wish to read,
    //in this case, command register, number 0.
    i2c->write(i2cAddress, &registerNumber, 1);
    
    //Now, read one byte, which will be the contents of the command register.
    i2c->read(i2cAddress, &registerContents, 1);
    
    return registerContents;
    
}

int CMPS10::readBearing(void){

    char registerNumber = COMPASS_BEARING_WORD_REG;
    char registerContents[2] = {0x00, 0x00};
    
    //First, send the number of register we wish to read,
    //in this case, register numbers 2, 3, which hold the
    //compass bearing as a 16-bit word.
    i2c->write(i2cAddress, &registerNumber, 1);
    
    //Now read two bytes which will be the contents of
    //these registers.
    i2c->read(i2cAddress, registerContents, 2);
    
    //Register 2 [read first], was the high byte, followed by
    //register 3 [read second], which was the low byte.
    int bearing = ((int)registerContents[0] << 8) | ((int)registerContents[1]);
    
    return bearing;
    
}
void CMPS10::Kalibrasi(void)
{
    char data[2];
    //char cmd[2];
    //int bearing_raw;
    //float bearing;
    const int addr = 0xC0;  // define the I2C Address
    data[0] = 22;
    //Serial Serial(USBTX, USBRX);

    //Serial.baud(9600);

    LCD.printf("Kalibrasi Kompas");
    PC.printf("Kalibrasi Kompas");
    data[1] = 0xF0;
    i2c->write(addr,data,2,false);
    wait(2);

    // kalibrasi kompas ketika Tombol Biru (Tombol Kalibrasi kompas) ditekan
    // tahap satu
    do
    {
        LCD.cls();
        LCD.locate(0,0);
        LCD.printf("Arahkan ke:");
        LCD.locate(0,1);
        LCD.printf("North 0");
    }while(TombolKalKompas==1);
    data[1] = 0xF5;
    i2c->write(addr,data,2,false);
    wait(1);

    // tahap dua
    do
    {
        LCD.cls();
        LCD.locate(0,0);
        LCD.printf("Arahkan ke:");
        LCD.locate(0,1);
        LCD.printf("West (+270)");
        //Serial.puts("Press enter to continue.\r\n");
        //Serial.getc();
    }while(TombolKalKompas==1);
    i2c->write(addr,data,2,false);
    wait(1);

    // tahap tiga
    do
    {
        LCD.cls();
        LCD.locate(0,0);
        LCD.printf("Arahkan ke:");
        LCD.locate(0,1);
        LCD.printf("South (+180)");
        //Serial.puts("Press enter to continue.\r\n");
        //Serial.getc();
    }while(TombolKalKompas==1);
    i2c->write(addr,data,2,false);
    wait(1);

    // tahap empat
    do
    {
        LCD.cls();
        LCD.locate(0,0);
        LCD.printf("Arahkan ke:");
        LCD.locate(0,1);
        LCD.printf("East (+90)");
        //Serial.puts("Press enter to continue.\r\n");
        //Serial.getc();
    }while(TombolKalKompas==1);
    i2c->write(addr,data,2,false);
    wait(1);

    // kalibrasi selesai
    // while(TombolKalKompa==1) {
    //     cmd[0] = 0x2;
    //     i2c->write(addr,cmd,1,true);
    //     i2c->read(addr,data,2,false);

    //     bearing_raw = (data[0] << 8) + data[1];
    //     bearing = bearing_raw;
    //     LCD.cls();
    //     LCD.locate(0,0);
    //     LCD.printf("Bearing:");
    //     LCD.locate(0,1);
    //     LCD.printf("%f", bearing);

    //     wait(0.640);

    // }
}
//void CMPS10::Kalibrasi(void)
//{
//    char data[2];
//    //char cmd[2];
//    //int bearing_raw;
//    const int addr = 0xC0;  // define the I2C Address
//    data[0] = 0; // command register
//    data[1] = 0xF0;
//    i2c->write(addr,data,2);
//    wait_ms(100);
//    data[1] = 0xF5;
//    i2c->write(addr,data,2);
//    wait_ms(100);
//    data[1] = 0xF7;
//    i2c->write(addr,data,2);
//    wait_ms(100);
//    do{
//
//        }while(TombolKalKompas == 1);
//    data[1] = 0xF8;
//    i2c->write(addr,data,2,false);
//    wait_ms(50);
//}

//
void CMPS10::Reset(void)
{ //0x20,0x2A,0x60
    char data[2];
    //char cmd[2];
    //int bearing_raw;
    const int addr = 0xC0;  // define the I2C Address
    data[0] = 0; // command register
    data[1] = 0x20;
    i2c->write(addr,data,2);
    wait_ms(20);
    data[1] = 0x2A;
    i2c->write(addr,data,2);
    wait_ms(20);
    data[1] = 0x60;
    i2c->write(addr,data,2);
    wait_ms(20);
}


