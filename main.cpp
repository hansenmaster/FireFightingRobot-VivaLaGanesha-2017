// VIVA LA GANESHA 17 Goes to Trinity
// Jagalah Kebersihan dan kerapihan codingan
// File name : main.cpp
// author/editor : Hansen EL14 /Babang EL13
// edited on : 23 November 2016
// Desc : pengetesan seluruh library

#include "mbed.h"
#include "ObjectVariabel.h"
 
// jangan lupa tambahkan 4 Ticker
// ticker untuk servo
Ticker      timer;
// ticker untuk sensor jarak Infrared
Ticker      _IR;
// pembaca keadaan tombol dan led
Ticker      tombol;
Ticker		ping;
 
int main() {
	//int batasPutih =8000;
//	int sudutNow;
    Mode = SETAWAL;
    // nyala bentar kipasnya dan LED
	ENKipas = 0;
	LEDPadamkanApi = 1;
	wait(0.1);
	//ENKipas = 1;
	LEDPadamkanApi = 0;
//	posisi awal
	Posisi = HOME;
    while (true) {
         
        switch(Mode){
            case SETAWAL:

                DisplaySETAWAL();
//                interrupt untuk infrared dan sensor garis
                _IR.attach_us(&IF, &Infrared::update_ADC, 20*us_ms);
                wait(0.1);
                // mengatur servo
                GaitSelect(4);
                SetBodyHeight(65);
                SetLegLiftHeight(18);
//                GetReady(70,350);
                GetReady(55,350);
                wait(0.1);
                HadapNormal();
                SetGlobalSpeed(45);
                SetTravelSpeed(50);
                timer.attach(&attime,0.001*FrameTime);
                // pengaturan servo selesai

                //pengecekan semua LED, extinguisher, motor
                tombol.attach_us(&CekTombol, 100*us_ms);
                // mode ini selesai, langsung pindah state
                InOut = true;
                ping.attach_us(&UpdatePing, 100*us_ms);
               // Pintu = KeluarR4A;
                Mode = DEBUG;
                wait(0.1);
                break;
            case INISIASI:
            	wait(0.1);
                DisplayINIT();
                while(!Suara);
                while(Suara);

                // mulai jika sudah ada suara
                if (Suara == 0){
                	LEDBiru = 1;
                	wait (0.3);
                	if (Suara == 0)

                		wait (0.3);
                		if (Suara == 0)
                		Mode = JELAJAH;
                }
//                if (TombolReset == 0)
//                	Mode = JELAJAH;
//                wait(7);
//                Mode = MULAI;
                break;
            case MULAI:
            	//wait(0.5);
                DisplayMULAI();
 //               tombol.attach_us(&CekTombol, 100*us_ms);
                while (!Suara)
                	wait(0.1);
                while (Suara);
                Mode = DEBUG;
                wait(0.2);
                break;
            case JELAJAH:
//            	ENKipas=1;
//            	wait(10);
            	//QuickStop();
            	//wait(2);
            	//LorongTimurkeR4();
//            	dor {
//					wallKananApi(11,25,10);
//					wait(0.1);
//				} while (!ApiSekitar(75));
//            	QuickStop();
//            	wait(1);
//            	putarkeApiCoba(140);
//            	ENKipas=1;
//            	while (UV2.Flag==1){
//            		for(int ii=1;ii<=2;ii++){
//						TengokKanan(ii*30);
//						wait(0.01);
//					}
//					for(int ii=1;ii<=2;ii++){
//						TengokKiri(ii*30);
//						wait(0.01);
//					}
//					HadapNormal();
//            	}
//            	ENKipas=1;
//				wait(10);

            	//wait(2);
                DisplayJELAJAH();
                //wait(0.1);
                SetTravelSpeed(40);
                //PadamkanApiR3();
                //PadamkanApiR1();
                //PutarSampaiArah(UTARA,KANAN,KompasToleransiKecil);
               //MajuLurus(40);
               // wait(0.1);
                LEDBiru = 0;
                keluarRuangan(true);
                CariRuangan();
                QuickStop();
                wait(0.1);
                break;
            case PADAMKANAPI:
            	DisplayPADAMKANAPI();
            	PadamkanApi();
            	wait(0.1);
            	Mode=BACKHOME;
                break;
            case BACKHOME:
            	DisplayBACKHOME();
            	LEDPadamkanApi = 0;
            	backHome();
                break;
            case SELESAI:
            	DisplayFINISH();
            	wait(0.1);
                break;
            case DEBUG:
//            	update ruangan
            	//wait(0.2);
//            	UpdatePintu();
//            	if(GarisDepan == HITAM && GarisBelakang == PUTIH){
//            		UpdatePintu();
//            	}
//do{

//} while(TombolKalKompas==1);
  //          	kompas.Kalibrasi();


            	//if(TombolKalKompas == 0){
            		//ENKipas = 0;
				//	kompas.Kalibrasi();
				//}
            	//else if (TombolKalKompas == 1){
            	//	ENKipas = 1;
            	//}
//                DisplayClear();
//                DisplayPintu();


                DisplayDEBUG();
                DisplaySound();
                LCD.locate(0,1);
                LCD.printf("%d",kompas.readBearing());
//                LCD.printf("%d %d %d %d ", TombolKalKompas, ApiUjungKiri(90),ApiUjungKanan(90),ApiUjung(90));
                LCD.locate (9,1);
                if(UV2.Flag){
                	LCD.printf("API");
                }
                else{
                	LCD.printf("NOT_API");
                }

                DisplayKompas();
                //DisplayGaris();
                DisplayTotal_PC();
                //TombolDepanKanan = _switch_depan_kanan.read();
                //PC.printf("Tombol depan : %d",TombolDepanKanan);

                wait(1);
                //Mode = DEBUG;
                break;
            case BACKUP:
                break;
            case KALIBRASI:
            	DisplayLCD("Kalibrasi");
 //               tombol.attach_us(&CekTombol, 100*us_ms);
            	while (TombolKalKompas == 0);
                while (TombolKalKompas == 1);
                kompas.Reset();
                kompas.Kalibrasi();
                Mode = DEBUG;
                wait(0.2);
                break;
            case COBA:
            	LEDBiru = 1;
            	LEDPadamkanApi = 1;
            	wait(3);
				ResetArah();
				DisplayLCD("Ke TIMUR");
				PutarSampaiArah(TIMUR);
				QuickStop();
				wait(5);

            	ResetArah();
            	DisplayLCD("Ke SELATAN");
            	PutarSampaiArah(SELATAN);
            	QuickStop();
            	wait(5);

				ResetArah();
				DisplayLCD("Ke UTARA");
				PutarSampaiArah(UTARA);
				QuickStop();
				wait(5);

            	ResetArah();
            	DisplayLCD("Ke BARAT");
				PutarSampaiArah(BARAT);
				QuickStop();
				wait(5);

//            	do {
//            		PutarKanan(150);
//            		wait(0.1);
//            		GetArah(150);
//            	}while (ARAH!= UTARA);
//            	DisplayLCD("udah UTARA");
            	wait(3);
            	//ENKipas = 1;

//            	LorongTimurkeR4();
//            	QuickStop();
//            	do {
//            				wallKiriSlow(15,25,10);
//            				wait(0.1);
//            	} while (GarisTengah == HITAM);
//
//            	pintu.push_back(MasukR4A);
//
//            	CariApiR4A();
//
//            	Mode = PADAMKANAPI;





//            	DisplayLCD("COBA");
//            	//LorongTimurkeR4();
//            	ENKipas=1;
//            	wait(5);
//            	ENKipas=0;
//            	wait(5);
//            	UpdatePing();
            	//PC.printf("Jarak ping depan: %d\r\n", JarakPingDepan);
            	//wait(0.5);
//            	//DisplayLCD("MAJU LURUS");
//            	//MajuLurus(30);
//            	//wait(5);
//            	//QuickStop();
//            	//wait(0.1);
//            	DisplayLCD("Wall ROOM");
//            	for(int i =1; i<200;i++){
//                	wallKananSlow(14,25,10);
//                	wait(0.1);
//            	}
//            	QuickStop();
//            	wait(0.1);
//            	DisplayLCD("Wall LORONG");
//            	for(int i =1; i<200;i++){
//                	wallKananSlow(14,25,10);
//                	wait(0.1);
//            	}
////            	wallKanan(18,25,10);
////            	wait(20);
//            	QuickStop();
//            	            	wait(0.1);
//            	DisplayLCD("50");
//            	TengokBawah(50);
//            	wait(1);
//            	HadapNormal();
//            	wait(2);
//
//            	DisplayLCD("60");
//				TengokBawah(60);
//				wait(1);
//				HadapNormal();
//				wait(2);
//
//            	DisplayLCD("70");
//				TengokBawah(70);
//				wait(1);
//				HadapNormal();
//				wait(2);
        }
         
    }
}
