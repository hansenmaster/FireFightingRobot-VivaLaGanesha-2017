#ifndef MY_TPA_H
#define MY_TPA_H
#define TPA_addr_x 0xD2
#define TPA_addr_y 0xD0
#include "mbed.h"

class TPA81{
public:
    TPA81(PinName mysda, PinName myscl, char TPA_addr);
    void setAddress(char inAddr);
    int getTempAt();
    int getTemp(short i);

    // Untuk Lomba
    int Data[8];
    void Read();
    unsigned char IsAdaApi();
    unsigned int TingkatPanas();
        unsigned int Ambient();
        
protected:
    int _aTemp;
    int _temp[8];
    I2C _TPA;
    char _addr;
    char _cmd[2];
    float _delay;
};

#endif

