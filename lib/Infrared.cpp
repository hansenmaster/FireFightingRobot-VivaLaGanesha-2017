// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Infrared.cpp
// author/editor : Babang
// created on : 09 Feb 2016
// Desc : infrared library implementation

#include "mbed.h"
#include "Infrared.h"
#include "ObjectVariabel.h"

// constructor
Infrared::Infrared(PinName a, PinName b, PinName c, PinName d, PinName e, PinName f, PinName g, PinName h):_ADC_A(a), _ADC_B(b), _ADC_C(c), _ADC_D(d), _ADC_E(e), _ADC_F(f), _ADC_G(g), _ADC_H(h){
	// initial state : jika perlu
}

void Infrared::update_ADC(void){
	// previous state
	PrevJarakDepan = JarakDepan;
	//PrevJarakSRKanan = JarakKanan;
	//PrevJarakKanan = JarakKanan;
	PrevJarakSRKiri = JarakSRKiri;
	PrevJarakKiri = JarakKiri;
	PrevJarakBelakang = JarakBelakang;
	// Membaca ADC terlebih dahulu
	// ADC Infrared pertama
	IR_0 = _ADC_A.read_u16();
	// ADC Infrared kedua
	IR_1 = _ADC_B.read_u16();
	// ADC Infrared ketiga
	IR_2 = _ADC_C.read_u16();
	// ADC Infrared keempat
	IR_3 = _ADC_D.read_u16();
	// ADC Infrared kelima
	IR_4 = _ADC_E.read_u16();
	// ADC Infrared keenam
	IR_5 = _ADC_F.read_u16();
	IR_6 = _ADC_G.read_u16();
	IR_7 = _ADC_H.read_u16();

	// mengolah data yang akan dimasukan ke variable global
	// tentukan Infrared yang akan menggunakan fungsi Call_samping maupun Call_depan
	JarakSRKiri 		= 	(int)Call_samping(IR_4);
	JarakKiri 			= 	(int)Call_samping(IR_2);
	JarakBelakang		=	(int)Call_samping(IR_1);
	JarakDepan			= 	(int)Call_samping(IR_3);
	JarakSRKanan		=	(int)Call_samping(IR_5);
	JarakKanan 			=	(int)Call_samping(IR_7);
	JarakSBKanan		=	(int)Call_samping(IR_6);
	JarakSBKiri			=	(int)Call_samping(IR_0);
//	update sensor garis sekalian :) biar satu ticker 
	UpdateSensorGaris();

	// tampilkan LED juga di update counternya disini
	if(CounterLED>=1 && CounterLED<=7){
		CounterLED++;
		LEDAtas = CounterLED&&LEDPadamkanApi;
	}else if(CounterLED>=8 && CounterLED<=14){
		CounterLED++;
		LEDAtas = (!CounterLED)&&(LEDPadamkanApi);
	}else{
		CounterLED = 1;
	}
	//GetArah(100);

}

float Infrared::Call_samping(uint16_t x){
	side_distance = a_samping/pow(x,b_samping)+1;
	return side_distance;
}

float Infrared::Call_depan(uint16_t x){
	front_distance = a_depan/pow(x,b_depan);
	return front_distance;
}
