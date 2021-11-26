/* mbed AX-12+ Servo Library
 *
 * Copyright (c) 2010, cstyles (http://mbed.org)
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
 */

#include "AX12.h"
#include "mbed.h"

AX12::AX12 (PinName tx, PinName rx, int ID, int baud) : _ax12(tx,rx) 
{
    _baud = baud;
    _ID = ID;
    _ax12.baud(_baud);
}

int AX12::ABS(float x){
	if(x<0){
		return -x;
	}
	else {
		return x;
	}
}

// Set the mode of the servo
//  0 = Positional (0-300 degrees)
//  1 = Rotational -1 to 1 speed
int AX12::SetMode(int mode) 
{
    if (mode == 1) 
    { // set CR
        SetCWLimit(0);
        SetCCWLimit(0);
        SetCRSpeed(0.0);
    } 
    else 
    {
        SetCWLimit(0);
        SetCCWLimit(300);
        SetCRSpeed(0.0);
    }
    return(0);
}

// if flag[0] is set, were blocking
// if flag[1] is set, we're registering
// they are mutually exclusive operations
int AX12::SetGoal(int degrees, int flags) 
{
    char reg_flag = 0;
    char data[2];

    // set the flag is only the register bit is set in the flag
    if (flags == 0x2) 
    {
        reg_flag = 1;
    }

    // 1023 / 300 * degrees
    short goal = (1023 * degrees) / 300;

    data[0] = goal & 0xff; // bottom 8 bits
    data[1] = goal >> 8;   // top 8 bits

    // write the packet, return the error code
    int rVal = write(_ID, AX12_REG_GOAL_POSITION, 2, data, reg_flag);

    if (flags == 1) 
    {
        // block until it comes to a halt
        while (isMoving()) 
        {

        }
    }
    return(rVal);
}

void AX12::MultSetGoal(int degrees1, float speed1, 
                        int degrees2, float speed2, 
                        int degrees3, float speed3, 
                        int degrees4, float speed4, 
                        int degrees5, float speed5, 
                        int degrees6, float speed6, 
                        int degrees7, float speed7, 
                        int degrees8, float speed8, 
                        int degrees9, float speed9, 
                        int degrees10, float speed10, 
                        int degrees11, float speed11,
                        int degrees12, float speed12, 
                        int degrees13, float speed13, 
                        int degrees14, float speed14, 
                        int degrees15, float speed15, 
                        int degrees16, float speed16, 
                        int degrees17, float speed17, 
                        int degrees18, float speed18)
{
    char total_ID = 18;
    char length_data = 4;
    char data[(total_ID*length_data) + 1];

    int goal;
    int goal_speed;

    int alamat;

    int degrees[19];
    float speed[19];
   
    // assignment value from parameter to array

    degrees[1] = degrees1; 
    degrees[2] = degrees2; 
    degrees[3] = degrees3; 
    degrees[4] = degrees4; 
    degrees[5] = degrees5; 
    degrees[6] = degrees6; 
    degrees[7] = degrees7; 
    degrees[8] = degrees8; 
    degrees[9] = degrees9; 
    degrees[10] = degrees10;
    degrees[11] = degrees11;
    degrees[12] = degrees12;
    degrees[13] = degrees13;
    degrees[14] = degrees14;
    degrees[15] = degrees15;
    degrees[16] = degrees16;
    degrees[17] = degrees17;
    degrees[18] = degrees18;
    
    speed[1] = speed1; 
    speed[2] = speed2; 
    speed[3] = speed3; 
    speed[4] = speed4; 
    speed[5] = speed5; 
    speed[6] = speed6; 
    speed[7] = speed7; 
    speed[8] = speed8; 
    speed[9] = speed9; 
    speed[10] = speed10;
    speed[11] = speed11;
    speed[12] = speed12;
    speed[13] = speed13;
    speed[14] = speed14;
    speed[15] = speed15;
    speed[16] = speed16;
    speed[17] = speed17;
    speed[18] = speed18;

/*
    for (char k=1; k<=total_ID; k++)
    {
        degrees[k] = degrees1;
        speed[k] = speed1;
    }
*/

    for (int i=1; i<=total_ID; i++)
    {
        alamat = length_data*(i-1);

        goal = (1023 * degrees[i]) / 300;

        data[alamat+1] = goal & 0xff; // bottom 8 bits
        data[alamat+2] = goal >> 8;   // top 8 bits

        goal_speed = (0x3ff * ABS(speed[i]));

        // Set direction KANAN if we have a negative speed
        if (speed[i] < 0) 
        {
            goal_speed |= (0x1 << 10);
        }

        data[alamat+3] = goal_speed & 0xff; // bottom 8 bits
        data[alamat+4] = goal_speed >> 8;   // top 8 bits
    }

    // Write
    sync_write(data);

    return;
}

// Set continuous rotation speed from -1 to 1
int AX12::SetCRSpeed(float speed) 
{
    // bit 10     = direction, 0 = KIRI, 1=KANAN
    // bits 9-0   = Speed
    char data[2];

    int goal = (0x3ff * ABS(speed));

    // Set direction KANAN if we have a negative speed
    if (speed < 0) 
    {
        goal |= (0x1 << 10);
    }

    data[0] = goal & 0xff; // bottom 8 bits
    data[1] = goal >> 8;   // top 8 bits

    // write the packet, return the error code
    int rVal = write(_ID, AX12_REG_MOVING_SPEED, 2, data);

    return(rVal);
}

int AX12::SetCWLimit (int degrees) 
{
    char data[2];

    // 1023 / 300 * degrees
    short limit = (1023 * degrees) / 300;

    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits

    // write the packet, return the error code
    return (write(_ID, AX12_REG_CW_LIMIT, 2, data));
}

int AX12::SetCCWLimit (int degrees) 
{
    char data[2];

    // 1023 / 300 * degrees
    short limit = (1023 * degrees) / 300;

    data[0] = limit & 0xff; // bottom 8 bits
    data[1] = limit >> 8;   // top 8 bits

    // write the packet, return the error code
    return (write(_ID, AX12_REG_CCW_LIMIT, 2, data));
}

void AX12::ControlID (int ID) 
{
    _ID = ID; // NANTI DICOBA APAKAH _ID ITU MAKSUDNYA ADALAH AX12_REG_ID

    return;
}

int AX12::SetID (int CurrentID, int NewID) 
{
    char data[1];
    data[0] = NewID;

    return (write(CurrentID, AX12_REG_ID, 1, data));
}

int AX12::SetBaud (int baud) 
{
    char data[1];
    data[0] = baud;

    return (write(0xFE, AX12_REG_BAUD, 1, data));
}

// return 1 is the servo is still in flight
int AX12::isMoving(void) 
{
    char data[1];
    read(_ID,AX12_REG_MOVING,1,data);
    return(data[0]);
}

void AX12::trigger(void) 
{
    char TxBuf[16];
    char sum = 0;

    TxBuf[0] = 0xFF;
    TxBuf[1] = 0xFF;

    // ID - Broadcast
    TxBuf[2] = 0xFE;
    sum += TxBuf[2];

    // Length
    TxBuf[3] = 0x02;
    sum += TxBuf[3];

    // Instruction - ACTION
    TxBuf[4] = 0x04;
    sum += TxBuf[4];

    // Checksum
    TxBuf[5] = 0xFF - sum;

    // Transmit the packet in one burst with no pausing
    for (int i = 0; i < 6 ; i++) {
        _ax12.putc(TxBuf[i]);
    }

    // This is a broadcast packet, so there will be no reply
    return;
}

float AX12::GetPosition(void) 
{
    char data[2];

    //int ErrorCode = read(_ID, AX12_REG_POSITION, 2, data);
	int ErrorCode = read(3, AX12_REG_POSITION, 2, data);
    short position = data[0] + (data[1] << 8);
    float angle = (position * 300)/1024;

    return (angle);
}

float AX12::GetTemp (void) 
{
    char data[1];
    int ErrorCode = read(_ID, AX12_REG_TEMP, 1, data);
    float temp = data[0];
    return(temp);
}

float AX12::GetVolts (void) 
{
    char data[1];
    int ErrorCode = read(_ID, AX12_REG_VOLTS, 1, data);
    float volts = data[0]/10.0;
    return(volts);
}

int AX12::read(int ID, int start, int bytes, char* data) 
{
    char PacketLength = 0x4;
    char TxBuf[16];
    char sum = 0;
    char Status[16];

    Status[4] = 0xFE; // return code

    // Build the TxPacket first in RAM, then we'll send in one go

    TxBuf[0] = 0xff;
    TxBuf[1] = 0xff;

    // ID
    TxBuf[2] = ID;
    sum += TxBuf[2];

    // Packet Length
    TxBuf[3] = PacketLength;    // Length = 4 ; 2 + 1 (start) = 1 (bytes)
    sum += TxBuf[3];            // Accululate the packet sum

    // Instruction - Read
    TxBuf[4] = 0x2;
    sum += TxBuf[4];

    // Start Address
    TxBuf[5] = start;
    sum += TxBuf[5];

    // Bytes to read
    TxBuf[6] = bytes;
    sum += TxBuf[6];

    // Checksum
    TxBuf[7] = 0xFF - sum;

    // Transmit the packet in one burst with no pausing
    for (int i = 0; i<8 ; i++) 
    {
        _ax12.putc(TxBuf[i]);
    }

    // Wait for the bytes to be transmitted
    wait (0.00002);

    // Skip if the read was to the broadcast address
    if (_ID != 0xFE) 
    {
        // response packet is always 6 + bytes
        // 0xFF, 0xFF, ID, Length Error, Param(s) Checksum
        // timeout is a little more than the time to transmit
        // the packet back, i.e. (6+bytes)*10 bit periods

        int timeout = 0;
        int plen = 0;
        while ((timeout < ((6+bytes)*10)) && (plen<(6+bytes))) 
        {
            if (_ax12.readable()) 
            {
                Status[plen] = _ax12.getc();
                plen++;
                timeout = 0;
            }

            // wait for the bit period
            wait (1.0/_baud);
            timeout++;
        }

        if (timeout == ((6+bytes)*10) ) 
        {
            return(-1);
        }

        // Copy the data from Status into data for return
        for (int i=0; i < Status[3]-2 ; i++) 
        {
            data[i] = Status[5+i];
        }
    } 

    // if (ID!=0xFE)
    return(Status[4]);
}

int AX12::write(int ID, int start, int bytes, char* data, int flag) {
// 0xff, 0xff, ID, Length, Intruction(write), Address, Param(s), Checksum

    char TxBuf[16];
    char sum = 0;
    char Status[6];

    // Build the TxPacket first in RAM, then we'll send in one go

    TxBuf[0] = 0xff;
    TxBuf[1] = 0xff;

    // ID
    TxBuf[2] = ID;
    sum += TxBuf[2];

    // packet Length
    TxBuf[3] = 3+bytes;
    sum += TxBuf[3];

    // Instruction
    if (flag == 1) 
    {
        TxBuf[4]=0x04;
        sum += TxBuf[4];
    } 
    else 
    {
        TxBuf[4]=0x03;
        sum += TxBuf[4];
    }

    // Start Address
    TxBuf[5] = start;
    sum += TxBuf[5];

    // data
    for (int i = 0; i < bytes; i++) {
        TxBuf[6+i] = data[i];
        sum += TxBuf[6+i];
    }

    // checksum
    TxBuf[6+bytes] = 0xFF - sum;

    // Transmit the packet in one burst with no pausing
    for (int i = 0; i < (7 + bytes) ; i++) 
    {
        _ax12.putc(TxBuf[i]);
    }

    // Wait for data to transmit
    wait (0.00002);

    // make sure we have a valid return
    Status[4]=0x00;

    // we'll only get a reply if it was not broadcast
    if (_ID!=0xFE) 
    {
        // response packet is always 6 bytes
        // 0xFF, 0xFF, ID, Length Error, Param(s) Checksum
        // timeout is a little more than the time to transmit
        // the packet back, i.e. 60 bit periods, round up to 100
        int timeout = 0;
        int plen = 0;
        while ((timeout < 100) && (plen<6)) {
            if (_ax12.readable()) 
            {
                Status[plen] = _ax12.getc();
                plen++;
                timeout = 0;
            }

            // wait for the bit period
            wait (1.0/_baud);
            timeout++;
        }

        // Build the TxPacket first in RAM, then we'll send in one go
    }
    return(Status[4]); // return error code
}

int AX12::sync_write(char* data) 
{
// 0xff, 0xff, ID, Length, Intruction(write), Address, Param(s), Checksum

    char sum = 0;
    char Status[6];
    char start_reg = 0x1E;
    char length_data = 4;
    char total_ID = 18;
    char TxBuf[(total_ID*(length_data+1)) + 8];
    
    int pra_alamat, alamat;

    // Set ID
    char ID[total_ID+1];
    
    for (int k = 1; k <= total_ID; k++) {
        ID[k] = k;
    }

    TxBuf[0] = 0xFF;
    TxBuf[1] = 0xFF;

    // ID
    TxBuf[2] = 0xFE;
    sum += TxBuf[2];

    // packet Length
    TxBuf[3] = ((length_data+1) * total_ID) + 4;
    sum += TxBuf[3];

    // Instruction
    TxBuf[4]=0x83;
    sum += TxBuf[4];

    // Start Address
    TxBuf[5] = start_reg;
    sum += TxBuf[5];

    // Length of Data to Write
    TxBuf[6] = length_data;
    sum += TxBuf[6];

    for (short int j = 1; j <= total_ID; j++) {
        pra_alamat = length_data*(j-1);
        alamat = 6 + j + pra_alamat;
    
        TxBuf[alamat] = ID[j];
        sum += TxBuf[alamat];

        for (short int i = 1; i <= length_data; i++) {
            TxBuf[alamat+i] = data[pra_alamat+i];
            sum += TxBuf[alamat+i];
        }
    }

    // checksum
    TxBuf[((total_ID*(length_data+1)) + 7)] = 0xFF - (sum & 0xFF);

    // Transmit the packet in one burst with no pausing
    for (int i = 0; i <= ((total_ID*(length_data+1)) + 7) ; i++) 
    {
        _ax12.putc(TxBuf[i]);
    }

    // Wait for data to transmit
    wait (0.00002);

    // make sure we have a valid return
    Status[4]=0x00;

    return(Status[4]); // return error code
}

