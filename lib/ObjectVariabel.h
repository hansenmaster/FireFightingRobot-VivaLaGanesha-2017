// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : ObjectVariabel.h
// author/editor : Babang
// created on : 18 Feb 2016
// Desc : deklarasi seluruh object di seluruh library
#ifndef OBJECTVARIABEL_H
#define OBJECTVARIABEL_H

// Include seluruh library yang akan dipakai disini
#include "mbed.h"
#include "TextLCD.h"
#include "Infrared.h"
#include "TPA81.h"
#include "AX12.h"
#include "Uvtron.h"
#include "InversKinematic.h"
#include "CMPS10.h"
#include "wallfollowing.h"
#include "Display.h"
#include "Garis.h"
#include "Jelajah.h"
#include "padamkanapi.h"
#include "backhome.h"
#include "Gerakan.h"
#include "Ping.h"
#include <vector>

// Membuat objek extern
// Pastikan semua objek yang ada pada ObjectVariabel.cpp dibuat extern.nya
extern DigitalOut led;

extern AX12 Servo;
extern Serial PC;
extern TextLCD LCD;
extern Infrared IF;
extern Uvtron UV1;
extern Uvtron UV2;
extern TPA81 tpa_0;
extern TPA81 tpa_2;
extern TPA81 tpa_4;
extern TPA81 tpa_6;
extern TPA81 tpa_8;
extern TPA81 tpa_A;
extern DigitalOut motor1;
extern DigitalOut motor2;
extern CMPS10 kompas;
extern DigitalIn tombolRST;
extern DigitalIn tombolKAL;
extern DigitalOut _LED;
extern DigitalOut _LEDSound;
extern DigitalIn _suara;
extern DigitalIn _switch_depan_kiri;
extern DigitalIn _switch_depan_kanan;
extern AnalogIn _GrsDepanKiri;
extern AnalogIn _GrsBelakangKiri;
extern AnalogIn _GrsMid;
extern AnalogIn _GrsBelakangKanan;
extern AnalogIn _GrsDepanKanan;
extern Ping PingDepan;

// variabel untuk konversi us ke ms, rada gapenting emang :P
#define us_ms		1000

// Proses pembuatan variabel extern

// Blok variabel jarak
// didapatkan dari pembacaan Infrared
// digunakan pada Infrared.h
// Jarak dalam satuan cm
extern uint16_t 	JarakDepan;
extern uint16_t 	JarakSRKanan;
extern uint16_t 	JarakKanan;
extern uint16_t 	JarakSRKiri;
extern uint16_t 	JarakKiri;
extern uint16_t 	JarakBelakang;
extern uint16_t 	JarakSBKiri;
extern uint16_t 	JarakSBKanan;
// variabel yang menyimpan nilai bacaan Infrared yang lama
extern uint16_t 	PrevJarakDepan;
extern uint16_t 	PrevJarakSRKanan;
extern uint16_t 	PrevJarakKanan;
extern uint16_t 	PrevJarakSRKiri;
extern uint16_t 	PrevJarakKiri;
extern uint16_t 	PrevJarakBelakang;

//variabel ping
extern uint16_t 	JarakPingDepan;

//blok variabel kondisi tombol dan LED atas dan Sound activator
//digunakan untuk mengetahui tombol mana yang sedang aktif
//fungsi nya berada pada ObjectVariabel
extern unsigned char TombolReset;
extern unsigned char TombolKalKompas;
extern unsigned char LEDAtas;
extern unsigned char LEDBiru;
extern unsigned char ENKipas;
extern unsigned char ENExtinguisher;
extern unsigned char Suara;
extern unsigned char TombolDepanKiri;
extern unsigned char TombolDepanKanan;
extern unsigned char CounterLED;
extern unsigned char LEDPadamkanApi;
extern unsigned char BatasApi;
// fungsi untuk tombol
extern void CekTombol();
extern void UpdatePing();

// variabel untuk mengatur state yang sedang dijalani
// digunakan pada fungsi main
extern unsigned char Mode;
#define SETAWAL 	20
#define INISIASI 	21
#define MULAI 		22
#define JELAJAH 	23
#define PADAMKANAPI 24
#define BACKHOME 	25
#define SELESAI 	26
#define BACKUP 		27
#define DEBUG		28
#define KALIBRASI	29
#define COBA		30

// Blok variabel garis
// didapatkan dari pembacaan garis
// digunakan pada Garis.h
extern uint16_t    ADCGarisDepanKiri;
extern uint16_t    ADCGarisBelakangKiri;
extern uint16_t    ADCGarisTengah;
extern uint16_t    ADCGarisBelakangKanan;
extern uint16_t    ADCGarisDepanKanan;
extern unsigned char GarisDepanKanan;
extern unsigned char GarisBelakangKiri;
extern unsigned char GarisTengah;
extern unsigned char GarisDepanKiri;
extern unsigned char GarisBelakangKanan;

//keadaan garis depan (apa putih, hitam, abu2
//threshold untuk adc depan
//threshold ADC Putih High (batas atas)
#define BatasGaris			180000
#define BatasPutih			20000

#define TH_Putih_H_D		25000
#define TH_Putih_L_D		0 // 27000
#define TH_Abu_H_D			0
#define TH_Abu_L_D			0
#define TH_Hitam_H_D		65536
#define TH_Hitam_L_D		30000
//threshold untuk adc belakang
#define TH_Putih_H_B		15000
#define TH_Putih_L_B		0
#define TH_Abu_H_B			0
#define TH_Abu_L_B			0
#define TH_Hitam_H_B		65536
#define TH_Hitam_L_B		30000
//definisi dari warna
#define PUTIH				46
#define HITAM				47
#define ABU					48

//identifikasi pintu
extern unsigned char masuk[5];
extern unsigned char keluar[5];
extern vector<unsigned char> pintu;
//extern unsigned char Pintu;
//extern unsigned char HomeRoom;
extern int JumlahPutih;

//detail pintu yang mungkin
#define MasukR3				70
#define KeluarR3			71
#define MasukR2				72
#define KeluarR2			73
#define MasukR1A			74 // pintu 1A : Timur, tembok ke dinding dalam
#define KeluarR1A			75 // pintu 1A : Barat, tembok ke dinding dalam
#define MasukR1B			76 // pintu 1B : Timur, tembok ke dinding luar
#define KeluarR1B			77 // pintu 1B : Timur, tembok ke dinding luar
#define MasukR1C			78 // pintu 1C : Utara-Selatan
#define KeluarR1C			79 // pintu 1C : Utara-Selatan
#define MasukR4A			80 // pintu 4A : Ruang 4 hadap Selatan
#define KeluarR4A			81 // pintu 4A : Ruang 4 hadap selatan
#define MasukR4B			82 // pintu 4B : Ruang 4 hadap utara
#define KeluarR4B			83 // pintu 4B : Ruang 4 hadap Utara
//identifikasi ruangan
extern unsigned char Posisi;
//detail posisi yang mungkin
#define R1					50
#define R2					51
#define R3					52
#define R4					53
#define LORONGTIMUR			54
#define LORONGBARAT			55
#define HOME				56
//variabel
extern unsigned char ARAHTIANG;
extern unsigned char ARAH;
//detail arah yang mungkin
#define UTARA 				90
#define BARAT 				91
#define SELATAN 			92
#define TIMUR 				93
#define NONE				94
// threshold arah
#define THUtara				0//291//101//97//182//27
#define THTimur				900//935//905//840//934//817
#define THSelatan			1800//1713//1854//1796//1876//1895
#define THBarat				2700//2659//2630//2633//2705//2675
// pilihan toleransi
#define KompasToleransiBesar			350
#define KompasToleransiKecil			150

#define errorSudut     		500

extern bool InOut;	// true dlm ruangan, false luar
extern bool apiDekat;	// Khusus R1B
extern int PosisiBoneka;	// 1: lorong antara R1-R4, 2: lorong barat R4, 3: lorong selatan R4, 0: undefined
extern bool furniture;

extern bool PernahUjungKanan;
extern bool PernahUjungKiri;

extern unsigned char ArahWall ;

extern unsigned char sudut_putar;

extern unsigned char LetakApi;

#endif
