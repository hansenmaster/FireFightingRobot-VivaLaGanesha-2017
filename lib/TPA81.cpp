#include "TPA81.h"

TPA81::TPA81(PinName mysda, PinName myscl, char TPA_addr): _TPA(mysda,myscl) {
    _delay = 51;
    _addr = TPA_addr;
}

void TPA81::setAddress(char inAddr) {

}

int TPA81::getTempAt() {
    _cmd[0] = 1;
    _cmd[1] = 1;

    _TPA.write(_addr, _cmd, 2);
    _TPA.read(_addr, _cmd, 1);

    return _cmd[0];
}

int TPA81::getTemp(short i) {
    _cmd[0] = i;
    _cmd[1] = i;

    _TPA.write(_addr, _cmd, 2);
    _TPA.read(_addr, _cmd, 1);

    return _cmd[0];
}

unsigned int TPA81::Ambient(){
        return getTemp(1);
}

void TPA81::Read()
{
    for (short i = 2; i < 10; i++)
    {
        Data[i-2]=getTemp(i)-getTemp(1);
                if(Data[i-2]<0){
                        Data[i-2] = 0;
                }
    }    
        
}

unsigned char TPA81::IsAdaApi()
{
    int i;
    
    Read();
    i=Data[0]+Data[1]+Data[2]+Data[3]+Data[4]+Data[5]+Data[6]+Data[7];
    if (i>400)
        return(1);
    else
        return(0);;
}

unsigned int TPA81::TingkatPanas()
{
    int i;
    
    Read();
    i=Data[0]+Data[1]+Data[2]+Data[3]+Data[4]+Data[5]+Data[6]+Data[7];
    return i;
}

/*unsigned int TPA81::TingkatPanas()
{
    int i;
        unsigned int x;
    
    Read();
    for(i=1;i<9;i++){
                if(Data[i-1]<Data[i]){
                        x = Data[i];
                }
                else{
                        x = Data[i-1];
                }
        }
    return x;
}*/