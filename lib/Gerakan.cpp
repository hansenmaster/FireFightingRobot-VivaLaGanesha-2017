#include "mbed.h"
#include "ObjectVariabel.h"
#include "Gerakan.h"

void KoreksiArahIR() {
	if(JarakKanan<=JarakKiri){
		if(JarakSRKanan>JarakSBKanan){
			while(JarakSRKanan>(2*JarakKanan)){
				PutarKanan(150);
				wait(0.1);
			}
		}

		else {// Serong Kiri >> Serong Belakang
			while(JarakSBKanan>(2*JarakKanan)){
				PutarKiri(150);
				wait(0.1);
			}
		}
	}

	else{//kiri dekat
		if(JarakSRKiri>JarakSBKiri){
			while(JarakSRKiri>(2*JarakKiri)){
				PutarKiri(150);
				wait(0.1);
			}
		}
		else {// Serong Kiri >> Serong Belakang
			while(JarakSBKiri>(2*JarakKiri)){
				PutarKanan(150);
				wait(0.1);
			}
		}
	}
}

void PutarSampaiArah(char ArahTujuan, char ArahPutar, int Toleransi) {
	if (ArahPutar == AUTO) {
		int sudut = kompas.readBearing();
		int threshold;
		switch (ArahTujuan) {
		case TIMUR:
			threshold = THTimur; break;
		case BARAT:
			threshold = THBarat; break;
		case SELATAN:
			threshold = THSelatan; break;
		case UTARA:
			threshold = THUtara; break;
		}
		threshold -= sudut;
		threshold += 3600;
		threshold %= 3600;
		if (threshold < 1800)
			ArahPutar = KANAN;
		else
			ArahPutar = KIRI;
	}
	GetArah(Toleransi);
	while (ARAH != ArahTujuan){
		if (ArahPutar == KANAN) {
			PutarKanan(130);
		} else {
			PutarKiri(130);
		}
		wait(0.1);
		GetArah(Toleransi);
	}
	QuickStop();
	wait(0.2);
}

void PutarSampaiArahIR(char ArahTujuan, char ArahPutar, int Toleransi) {
	PutarSampaiArah(ArahTujuan,ArahPutar,Toleransi);
	KoreksiArahIR();
}

void PutarBalik() {
	GetArah(400);
	char arah = ARAH;
	ResetArah();
	switch (arah) {
	case UTARA:
		PutarSampaiArahIR(SELATAN); break;
	case SELATAN:
		PutarSampaiArahIR(UTARA); break;
	case TIMUR:
		PutarSampaiArahIR(BARAT); break;
	case BARAT:
		PutarSampaiArahIR(TIMUR); break;
	}
}

void HindarFurnitureWallApi(char ArahPutar) {
	char KananKiri;
	 if (!TombolDepanKiri || !TombolDepanKanan){
		DisplayClear();
		if(TombolDepanKanan){
			KananKiri=true;
			DisplayLCD("KANAN");
		}
		else{
			KananKiri = false;
			DisplayLCD("KIRI");
		}
		QuickStop();
//		wait(3);
		LCD.printf("FURNITURE %d %d",TombolDepanKiri, TombolDepanKanan);
		QuickStop();
		wait(0.1);
		for (int i = 0; i < 3 && JarakBelakang > 8; ++i) {
		   MundurLurus(15);
		   wait(0.1);
		}

			if(JarakPingDepan<10){
				DisplayLCD("KENA DEKAT");
				QuickStop();
//				wait(3);
				while(JarakPingDepan<15){
					DisplayLCD("MENJAUHI TIANG");
					if (ArahPutar== KANAN){
						do{
							GeserKanan(30);
							wait(0.1);
						}while(JarakPingDepan<15);
					}
					else {
						do{
							GeserKiri(30);
							wait(0.1);
						}while(JarakPingDepan<15);
					}
				}
			}
			else{
				DisplayLCD("KENA JAUH");
				QuickStop();
//				wait(3);
				DisplayLCD("MENDEKATI TIANG");
				if (ArahPutar== KANAN){
					if(KananKiri){
						do{
							GeserKanan(30);
							wait(0.1);
						}while(JarakPingDepan>13);
					}

				}
				else {
					if(!KananKiri){
						do{
							GeserKiri(30);
							wait(0.1);
						}while(JarakPingDepan>13);
					}
				}
				while(JarakPingDepan<15){
					DisplayLCD("MENJAUHI TIANG");
					if (ArahPutar== KANAN){
						do{
							GeserKanan(30);
							wait(0.1);
						}while(JarakPingDepan<15);
					}
					else {
						do{
							GeserKiri(30);
							wait(0.1);
						}while(JarakPingDepan<15);
					}
				}
			}



		DisplayLCD("GESER LAGI");
		for(int i =0; i<8;i++){
			if (ArahPutar== KANAN){
				GeserKanan(30);
				wait(0.1);
			}
			else {
				GeserKiri(30);
				wait(0.1);
			}
		}
		MajuLurus(30);
		wait(0.5);
		QuickStop();

	}
}


void HindarFurnitureWallApiSimple(char ArahPutar) {
	bool KananKiri;
	 if (!TombolDepanKiri || !TombolDepanKanan){
		DisplayClear();
		LCD.printf("FURNITURE %d %d",TombolDepanKiri, TombolDepanKanan);
		QuickStop();
		wait(0.1);


		if(JarakSRKiri)


		if(JarakPingDepan>13){
			DisplayLCD("MENDEKATI TIANG");
			if (ArahPutar== KANAN){
				do{
					GeserKanan(30);
					wait(0.1);
				}while(JarakPingDepan>13);
			}
			else {
				do{
					GeserKiri(30);
					wait(0.1);
				}while(JarakPingDepan>13);

			}
		}
		while(JarakPingDepan<15){
			DisplayLCD("MENJAUHI TIANG");
			if (ArahPutar== KANAN){
				do{
					GeserKanan(30);
					wait(0.1);
				}while(JarakPingDepan<15);
			}
			else {
				do{
					GeserKiri(30);
					wait(0.1);
				}while(JarakPingDepan<15);
			}
		}
		DisplayLCD("GESER LAGI");
		for(int i =0; i<10;i++){
			if (ArahPutar== KANAN){
				GeserKanan(30);
				wait(0.1);
			}
			else {
				GeserKiri(30);
				wait(0.1);
			}
		}
		MajuLurus(30);
		wait(0.5);
		QuickStop();
	 }
}

void HindarFurniture(char ArahPutar) {
	 if (!TombolDepanKiri || !TombolDepanKanan){
		DisplayClear();
		LCD.printf("FURNITURE %d %d",TombolDepanKiri, TombolDepanKanan);
		QuickStop();
		wait(0.1);
		for (int i = 0; i < 3 && JarakBelakang > 8; ++i) {
		   MundurLurus(15);
		   wait(0.1);
		}
		QuickStop();
		if (ArahPutar == 0) {
			if (JarakKanan > JarakKiri) {
				ArahPutar = KANAN;
			} else {
				ArahPutar = KIRI;
		   }
		}

		if (ArahPutar == KANAN) {
			PutarKanan(120);
			wait(0.7);

		} else {
		   PutarKiri(120);
		   wait(0.7);
		}
		  QuickStop();
		  wait(0.1);
	 }
}





void HindarFurnitureApi() {
	if (!TombolDepanKiri || !TombolDepanKanan){
		DisplayClear();
//		LCD.printf("FURNITURE %d %d",TombolDepanKiri, TombolDepanKanan);
		LCD.printf("FURNITURE API");
		QuickStop();
		wait(0.1);
		for (int i = 0; i < 3 && JarakBelakang > 8; ++i) {
			MundurLurus(15);
			wait(0.1);
		}
		QuickStop();
		unsigned char ArahPutar;

		if (JarakKanan > JarakKiri) {
			ArahPutar = KANAN;
		} else {
			ArahPutar = KIRI;
		}

		if (ArahPutar == KANAN) {
			PutarKanan(120);
			wait(0.7);
			do {
				wallKiriApi(12,25,10);
				wait(0.1);
			} while(!ApiSekitar(60)&&!ApiUjungKiri(60));
		} else {
			PutarKiri(120);
			wait(0.7);
			do {
				wallKananApi(12,25,10);
				wait(0.1);
			} while(!ApiSekitar(60)&&!ApiUjungKanan(60));
		}
		QuickStop();
		wait(0.1);

	}
}

//void HindarFurnitureApi2( ) {
//	if (!TombolDepanKiri || !TombolDepanKanan){
//		DisplayClear();
////		LCD.printf("FURNITURE %d %d",TombolDepanKiri, TombolDepanKanan);
//		LCD.printf("FURNITURE API2");
//		QuickStop();
//		wait(0.1);
//
//		QuickStop();
//		unsigned char ArahGeser;
//
//		if (JarakKanan > JarakKiri) {
//			ArahGeser = KANAN;
//		} else {
//			ArahGeser = KIRI;
//		}
//
//		if (ArahGeser == KANAN) {
//			GeserKanan(30);
//			wait(0.7);
//			MajuLurus(30);
//			wait(0.3);
//
//			do {
//				PutarKiri(40);
//				wait(0.1);
//			} while(!ApiSekitar(60)&&!ApiUjungKiri(60));
//		} else {
//			GeserKiri(30);
//			wait(0.7);
//			MajuLurus(30);
//			wait(0.3);
//			do {
//				PutarKanan(40);
//				wait(0.1);
//			} while(!ApiSekitar(60)&&!ApiUjungKanan(60));
//		}
//		QuickStop();
//		wait(0.1);
//
//	}
//}

void HindarFurnitureApi2( ) {
	char ArahPutar ;
	if (ArahWall == KIRI){
		ArahPutar = KANAN;
		HindarFurnitureWallApi(KANAN);
	}
	else {
		ArahPutar = KIRI;
		HindarFurnitureWallApi(KIRI);
	}

		if (ArahPutar == KANAN){
			while(!ApiSekitar(60) && !ApiUjung(60)) {
				wallKiriApi(14, 25 , 10);
				wait(0.1);
			}
		}else {
			while(!ApiSekitar(60) && !ApiUjung(60)) {
				wallKananApi(14, 25 , 10);
				wait(0.1);
			}
		}
}


//void HindarFurniture(char ArahPutar) {
//	if (JarakPingDepan <= 12 || !TombolDepanKiri || !TombolDepanKanan){
//		if (JarakPingDepan + 10 < JarakDepan || !TombolDepanKiri || !TombolDepanKanan){
//			DisplayLCD("FURNITURE");
//			QuickStop();
//			wait(1);
//			for (int i = 0; i < 5 && JarakBelakang > 8; ++i) {
//				MundurLurus(35);
//				wait(0.1);
//			}
//			QuickStop();
//			if (ArahPutar == 0) {
//				if (JarakKanan > JarakKiri) {
//					ArahPutar = KANAN;
//				} else {
//					ArahPutar = KIRI;
//				}
//			}
//			if (ArahPutar == KANAN) {
//				PutarKanan(120);
//				wait(1);
//			} else {
//				PutarKiri(120);
//				wait(1);
//			}
//			QuickStop();
//			wait(0.1);
//		}
//	}
//}

float maxJarakDepan(){
	int Max;
	PutarKiri(100);
	wait(0.1);
	Max= JarakDepan;
	QuickStop();
	PutarKiri(100);
	wait(0.1);
	if(JarakDepan>Max){
		Max = JarakDepan;
	}

	QuickStop();
	PutarKanan(200);
	wait(0.1);
	for (int i = 0; i < 2; i++) {
		PutarKanan(100);
		wait(0.1);
		if(JarakDepan>Max){
			Max = JarakDepan;
		}
	}

	QuickStop();
	return Max;
}

float avgJarakDepan() { // menghitung rata2 jarak depan dengan melakukan scanning ke kiri-kanan
	int totalDepan =0; // digunakan untuk memastikan apakah di depan ada boneka atau tidak

	totalDepan +=JarakDepan;
	PutarKiri(100);
	wait(0.1);
	QuickStop();

	totalDepan +=JarakDepan;
	PutarKanan(100);
	wait(0.2);
	QuickStop();

	totalDepan +=JarakDepan;

	return totalDepan / 3;
}
