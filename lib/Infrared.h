// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Infrared.h
// author/editor : Babang
// created on : 09 Feb 2016
// Desc : infrared library header
//  Kita Menggunakan 6 PIN ADC yang kemudian kita baca sekaligus pada fungsi update_ADC
// Fungsi update_ADC ini adalah rutin yang harus dipanggil setiap saat

// contoh penggunaan :

// #include "mbed.h"
// #include "ObjectVariabel.h"

// Ticker t;

// int main(){
// 	t.attach_us();
// 	while(1){
// 		PC.printf("%f\n", JarakDepan);
// 	}
// }


#ifndef INFRARED_H
#define INFRARED_H

#include "mbed.h"
// konstanta kalibrasi
#define a_samping		5000000
#define b_samping		1.229
#define a_depan			10000000
#define b_depan			1.297

class Infrared
{
public:
	// constructor
	Infrared(PinName a, PinName b, PinName c, PinName d, PinName e, PinName f, PinName g, PinName h);
	// Interrupted function
	void update_ADC(void);

private:
	// Analog classes untuk setiap infrared
	AnalogIn _ADC_A, _ADC_B, _ADC_C, _ADC_D, _ADC_E, _ADC_F, _ADC_G, _ADC_H;
	// variabel 16 bit per Infrared
	uint16_t IR_0, IR_1, IR_2, IR_3, IR_4, IR_5, IR_6, IR_7;
	// variabel untuk perhitungan Call_samping dan Call_depan
	float side_distance, front_distance;
	// convert 16bit to cm
	// Setiap perhitungan memiliki ke linieran didaerah tertentu
	// untuk jarak yang dekat, gunakan Call_samping
	float Call_samping(uint16_t x);
	// untuk jarak yang lebih jauh gunakan Call_depan
	float Call_depan(uint16_t x);
};

#endif
