 // Continuously send pings and read the sensor
 #include "mbed.h"
 #include "Ping.h"
 Serial pc(USBTX,USBRX);
 Ping Pinger(PC_6);
 
 int main() {
     int range;
 
     while(1) {
  
        Pinger.Send();    
        wait_ms(30);
        range = Pinger.Read_cm()/2;
        pc.printf("Jarak = %d\n",range);
        wait(0.5);
     }
 }
