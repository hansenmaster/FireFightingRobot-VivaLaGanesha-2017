// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : ObjectVariabel.cpp
// author/editor : Babang
// created on : 18 Feb 2016
// Desc : deklarasi seluruh object di seluruh library. FIXED
// Sebelumnya, sesuaikan dengan PINMAP yang ada di dropbox
#include "ObjectVariabel.h"


// Deklarasi Object Sesuai PINMAP
// Jangan Diubah2 !
// Dummies : rada ga penting, cuman untuk tahu fungsi attime Inversekinematics jalan
DigitalOut led(LED1);

//Inisiasi servo
AX12 Servo (PC_12, PD_2, 1, 1000000); // menggunakan Ticker
//Inisiasi PC Serial
Serial PC(USBTX, USBRX);
//inisiasi LCD
TextLCD LCD(PB_12, PB_3, PB_2, PA_10, PA_12, PA_11);// rs, e, d4-d7
//Inisiasi Infrared dan menggunakan Ticker
Infrared IF(PB_0, PC_1, PC_2, PC_3, PC_0, PA_6, PC_4, PB_1);// IR_0 -> IR_7
//Inisiasi UVTRON1
Uvtron UV1(PB_4);
//Inisiasi UVTRON2
Uvtron UV2(PB_5);
//Inisiasi TPA81 address sesuai TPA81 yang dipakai : (SDA, SCL, ADDRESS)
TPA81 tpa_0(PB_9, PB_8 ,0xD0);
TPA81 tpa_2(PB_9, PB_8 ,0xD2);
TPA81 tpa_4(PB_9, PB_8 ,0xD4);
TPA81 tpa_6(PB_9, PB_8 ,0xD6);
TPA81 tpa_8(PB_9, PB_8 ,0xD8);
TPA81 tpa_A(PB_9, PB_8 ,0xDA);
////Inisiasi motor1
DigitalOut motor1(PB_7);
//DigitalOut motor1(PA_11);
//inisiasi kompas
CMPS10 kompas(PB_9, PB_8, 0xC0);
//inisiasi tombol reset

DigitalOut _LEDSound(PB_6);
//inisiasi tombol kalibrasi kompas
DigitalIn tombolKAL(PC_13, PullUp);
//inisiasi LED atas
DigitalOut _LED(PC_7);
// inisiasi pin Suara
DigitalIn _suara(PA_8);
// tombol depan
DigitalIn _switch_depan_kiri(PC_9, PullUp);
DigitalIn _switch_depan_kanan(PA_5, PullUp);
//insisasi sensor garis depan
//AnalogIn _GrsDepan(PA_0);
////insisasi sensor garis belakang
//AnalogIn _GrsBelakang(PA_1);
////insisasi sensor garis tengah
//AnalogIn _GrsMidTengah(PA_4);
//AnalogIn _GrsMidKanan(PA_7);
//AnalogIn _GrsMidKiri(PA_5);

AnalogIn _GrsDepanKiri(PA_4);//PA_4
AnalogIn _GrsDepanKanan(PC_5);//PA_0
AnalogIn _GrsMid(PA_0);//PC_5
AnalogIn _GrsBelakangKiri(PA_7);
AnalogIn _GrsBelakangKanan(PA_1);

Ping PingDepan(PC_6);

// Deklarasi dan inisiasi variabel global yang akan dipakai
// mohon dikelompokkan, dijelaskan dipakai di library mana saja
// berikan juga deskripsi singkat

// Blok variabel jarak
// didapatkan dari pembacaan Infrared
// digunakan pada Infrared.h
// Jarak dalam satuan cm
uint16_t    JarakDepan;
uint16_t    JarakSRKanan;
uint16_t    JarakKanan;
uint16_t    JarakSRKiri;
uint16_t    JarakKiri;
uint16_t    JarakBelakang;
uint16_t    JarakSBKiri;
uint16_t    JarakSBKanan;
// variabel yang menyimpan nilai bacaan Infrared yang lama
uint16_t    PrevJarakDepan;
uint16_t    PrevJarakSRKanan;
uint16_t    PrevJarakKanan;
uint16_t    PrevJarakSRKiri;
uint16_t    PrevJarakKiri;
uint16_t    PrevJarakBelakang;

// variable ping
uint16_t 	JarakPingDepan;


//blok variabel keadaan tombol
//tombol reset(PB_6), kalibrasi kompas(PC_13), dan keadaan LED atas (PC_7)
//untuk mengakses kipas menyala juga 
unsigned char TombolReset;
unsigned char TombolKalKompas;
unsigned char LEDAtas;
unsigned char LEDBiru;
unsigned char ENKipas;
unsigned char ENExtinguisher;
unsigned char Suara;
unsigned char TombolDepanKiri;
unsigned char TombolDepanKanan;
unsigned char CounterLED = 0;
unsigned char LEDPadamkanApi;
unsigned char BatasApi;
unsigned char sudut_putar;
unsigned char ArahWall ;
unsigned char LetakApi;

//fungsi untuk mengecek keadaan tombol, LED, Kipas
// jangan lupa gunakan Ticker
void CekTombol(){
    //TombolReset = tombolRST.read();
    TombolKalKompas = tombolKAL.read();
    Suara = _suara.read();
    TombolDepanKiri = _switch_depan_kiri.read();
    TombolDepanKanan = _switch_depan_kanan.read();
//    mengubah state jika user mengubah nilai LEDAtas
    if (LEDBiru != _LEDSound.read()) {
        _LEDSound.write(LEDBiru);
    }
    if (LEDAtas != _LED.read()) {
        _LED.write(LEDAtas);
    }
//    mengubah state jika user mengubah nilai ENKipas
    if (ENKipas != motor1.read()) {
        motor1.write(ENKipas);
    }
    // jika keadaannya sedang reset:
//    if (TombolReset == 0) {
//        Mode = SETAWAL;
//    }
//    UV1.Read();
    UV2.Read();
//    PingDepan.Send();
//    wait_ms(30);
//    JarakPingDepan = PingDepan.Read_cm()/2;

}
void UpdatePing(){
	PingDepan.Send();
//	wait_ms(5);
	JarakPingDepan = PingDepan.Read_cm()/2;
}

// variabel untuk mengatur state yang sedang dijalani
// digunakan pada fungsi main
unsigned char Mode;

// Blok variabel garis
// didapatkan dari pembacaan garis
// digunakan pada Garis.h
uint16_t    ADCGarisDepanKiri;
uint16_t    ADCGarisBelakangKiri;
uint16_t    ADCGarisTengah;
uint16_t    ADCGarisDepanKanan;
uint16_t    ADCGarisBelakangKanan;

unsigned char GarisDepanKiri;
unsigned char GarisBelakangKiri;
unsigned char GarisTengah;
unsigned char GarisDepanKanan;
unsigned char GarisBelakangKanan;

//jelajah
unsigned char masuk[5];
unsigned char keluar[5];
vector<unsigned char> pintu;
//unsigned char Pintu;
unsigned char Posisi;
unsigned char ARAH;
unsigned char ARAHTIANG;
//unsigned char HomeRoom;
int JumlahPutih;

bool LeftRight;
bool InOut;
bool apiDekat;
int PosisiBoneka = 0;
bool furniture = false;
bool PernahUjungKanan;
bool PernahUjungKiri;

