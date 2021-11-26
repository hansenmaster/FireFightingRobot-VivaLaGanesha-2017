// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Backhome.cpp
// author/editor : Babang
// created on : 12 April 2016
// Desc : Algoritma inti, mencari jalan pulang

#include "mbed.h"
#include "backhome.h"
#include "ObjectVariabel.h"

//void R1AtoHome(){
//	MajuLurus(40);
//	wait(1.2);
//	do{
//		GetArah(100);
//		PutarKanan(120);
//		wait(0.1);
//	}while (ARAH!=UTARA);
//	QuickStop();
//	wait(0.2);
//	PutarKiri(250);
//	wait(0.2);
//	QuickStop();
//	wait(0.2);
//	MajuLurus(40);
//	wait(2);
//	QuickStop();
//	wait(0.2);
//	do{
//		GetArah(KompasToleransiKecil);
//		wallKiri2(17,45,25);
//		wait(0.1);
//	}while(ARAH!=BARAT);
//	QuickStop();
//	wait(0.2);
//	do{
//		GetArah(KompasToleransiKecil);
//		PutarKanan(150);
//		wait(0.1);
//	}while(ARAH!=TIMUR);
//	QuickStop();
//	wait(0.2);
//	PutarKiri(200);
//	wait(0.4);
//	QuickStop();
//	wait(0.3);
//	do{
//		wallKiri(18,45,25);
//		wait(0.1);
//	}while(GarisDepan==HITAM||GarisBelakang==HITAM);
//	QuickStop();
//	wait(0.5);
//	Mode = SELESAI;
//}
//
//void R1BtoHome(){
////	PutarKanan(200);
////	wait(0.3);
//	QuickStop();
//	PutarKiri(200);
//	wait(0.1);
//	QuickStop();
//	wait(0.5);
//	do{
//		MajuLurus(40);
//		wait(0.1);
//	}while(JarakDepan>11);
//	QuickStop();
//	wait(0.5);
//	do{
//		GetArah(KompasToleransiKecil);
//		PutarKanan(150);
//		wait(0.1);
//	}while (ARAH!=UTARA);
//	QuickStop();
//	wait(0.5);
//	do{
//		GetArah(KompasToleransiKecil);
//		wallKiri2(18,45,25);
//		wait(0.1);
//	}while(ARAH!=BARAT);
//	QuickStop();
//	wait(0.5);
//	do{
//		GetArah(KompasToleransiKecil);
//		PutarKanan(150);
//		wait(0.1);
//		}while (ARAH!=TIMUR);
//	QuickStop();
//	PutarKiri(250);
//	wait(0.3);
//	QuickStop();
//	do{
//		wallKiri2(18,45,25);
//		wait(0.1);
//	}while(GarisDepan==HITAM||GarisBelakang==HITAM);
//	QuickStop();
//	wait(0.5);
//	Mode = SELESAI;
//
//}
//
//void R1CtoHome(){
//	MajuLurus(40);
//	wait(0.4);
//	if(JarakKiri>60){
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKiri(18,45,25);
//			wait(0.1);
//		}while(ARAH!=BARAT);
//		QuickStop();
//		wait(0.2);
//		if(JarakDepan<60){
//			do {
//				GetArah(KompasToleransiKecil);
//				PutarKanan(250);
//				wait(0.1);
//			} while (ARAH!=TIMUR);
//
//			do {
//				GetArah(KompasToleransiKecil);
//				wallKiri(18,45,25);
//				wait(0.1);
//			} while (ARAH!=UTARA);
//
//			do {
//				wallKanan(18,45,25);
//				wait(0.1);
//			} while (GarisDepan==HITAM||GarisBelakang==HITAM);
//
//		}else{
//
//			do{
//				wallKiri(18,45,25);
//				wait(0.1);
//			}while(JarakKiri<50);
//
//			do{
//				GetArah(KompasToleransiKecil);
//				MajuBelokKanan(30);
//				wait(0.1);
//			}while(ARAH!=UTARA);
//			MajuLurus(30);
//			wait(1);
//			do {
//				wallKanan(18,45,25);
//				wait(0.1);
//			} while (GarisDepan==HITAM||GarisBelakang==HITAM);
//
//		}
//	}else{
//		do {
//			wallKanan(18,45,25);
//			wait(0.1);
//		} while (GarisDepan==HITAM||GarisBelakang==HITAM);
//	}
//
//	QuickStop();
//	wait(0.5);
//	Mode = SELESAI;
//}
//
//void R2toHome(){
////	cari pegangan kiri
//	GeserKiri(40);
//	wait(0.3);
//	QuickStop();
//	wait(0.5);
//	PutarKiri(250);
//	wait(0.5);
//	QuickStop();
//	wait(0.5);
//	do{
//		GetArah(KompasToleransiKecil);
//		wallKiri(18,45,20);
//		wait(0.1);
//	}while(ARAH!=BARAT);
//	wait(0.2);
////	if(JarakDepan<40){
//	QuickStop();
//	wait(0.5);
//	do{
//		GetArah(KompasToleransiKecil);
//		PutarKanan(220);
//		wait(0.1);
//	}while(ARAH!=TIMUR);
//	QuickStop();
//	wait(0.5);
//	PutarKiri(200);
//	wait(0.4);
//	QuickStop();
//	wait(0.5);
//
////	wait(0.2);
////	do {
////		GetArah(KompasToleransiKecil);
////		wallKiri(18,45,25);
////		wait(0.4);
////	} while (ARAH!=UTARA);
//
//	do {
//		wallKiri2(18,45,20);
//		wait(0.1);
//	} while (GarisDepan==HITAM||GarisBelakang==HITAM);
//	QuickStop();
//	wait(0.5);
//	Mode = SELESAI;
//}
//
//
//void R3toHome(){
//	MajuLurus(30);
//	wait(0.5);
//	QuickStop();
//	wait(0.3);
//	PutarKiri(250);
//	wait(0.3);
//	do{
//		wallKiri2(18,45,25);
//		wait(0.1);
//	}while(GarisDepan==HITAM||GarisBelakang==HITAM);
//	QuickStop();
//	wait(0.5);
//	Mode = SELESAI;
//}
//
//void R4AtoHome(){
//	do {
//		MajuLurus(30);
//		wait(0.1);
//	} while (JarakDepan>15);
////	ngecek sebelah kanan apa ada boneka
//	do {
//	PutarKanan(50);
//	GetArah(80);
//	wait(0.1);
//	} while (ARAH!=BARAT);
////	kalo gada boneka
//	if (JarakDepan>15) {
//		MajuLurus(40);
//		wait(2);
//		QuickStop();
//		wait(0.1);
//		PutarKanan(220);
//		wait(0.1);
//		QuickStop();
//		wait(0.1);
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKanan(18,45,25);
//			wait(0.1);
//		}while(ARAH!=UTARA);
//		wallKanan(18,45,25);
//		wait(1);
//		do{
//			wallKiri(17,45,25);
//			wait(0.1);
//		}while(GarisDepan==HITAM||GarisBelakang==HITAM);
//		QuickStop();
//		wait(0.5);
//	} else {
////		jika ada boneka dihadapannya
//		do {
//			PutarKiri(80);
//			wait(0.1);
//			GetArah(120);
//		} while (ARAH!=TIMUR);
//		QuickStop();
//		wait(0.1);
//		MajuLurus(30);
//		wait(2);
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKiri(18,45,25);
//			wait(0.1);
//		}while(ARAH!=BARAT);
//		do{
//			wallKanan(18,45,25);
//			wait(0.1);
//		}while(GarisDepan==HITAM||GarisBelakang==HITAM);
//	}
//	QuickStop();
//	wait(0.5);
//	Mode = SELESAI;
//}
//
//void R4BtoHome(){
//	do{
//		MajuLurus(35);
//		wait(0.1);
//	}while(JarakDepan>14);
//	//MajuLurus(40);
//	//wait(0.4);
//	QuickStop();
//	wait(0.2);
//	do{
//		PutarKiri(40);
//		wait(0.1);
//		GetArah(80);
//	}while(ARAH!=BARAT);
//	//putarKiri90();
//	QuickStop();
//	wait(0.2);
//	if(JarakDepan>40){
//		do{
//			wallKanan(18,45,20);
//			wait(0.1);
//		}while(GarisDepan==HITAM||GarisBelakang==HITAM);
//		QuickStop();
//		wait(0.5);
//		Mode = SELESAI;
//	}
//	else{//ada anjing deket home
//		putar180();
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKiri(18,45,20);
//			wait(0.1);
//		}while(ARAH!=SELATAN);
//		MajuLurus(35);
//		wait(2);
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKanan(18,45,20);
//			wait(0.1);
//		}while(ARAH!=UTARA);
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKiri(18,45,20);
//			wait(0.1);
//		}while(GarisDepan==HITAM||GarisBelakang==HITAM);
//}
//
//
////	if(JarakDepan>11){
////		do{
////			MajuLurus(25);
////			wait(0.1);
////		}while(JarakDepan>11);
////	}
////	do{
////		wallKanan(18,45,25);
////		wait(0.1);
////	}while(GarisDepan==HITAM||GarisBelakang==HITAM);
////	QuickStop();
////	wait(0.5);
//	QuickStop();
//	wait(0.5);
//
//	Mode = SELESAI;
//}


//void BackHome(){
//
//	switch (Pintu) {
//		case KeluarR1A:
//			UpdatePintu();
//			R1AtoHome();
//			break;
//		case KeluarR1B:
//			UpdatePintu();
//			R1BtoHome();
//			break;
//		case KeluarR1C:
//			UpdatePintu();
//			R1CtoHome();
//			break;
//		case KeluarR2:
//			R2toHome();
//			break;
//		case KeluarR3:
//			UpdatePintu();
//			R3toHome();
//			break;
//		case KeluarR4A:
//			R4AtoHome();
//			break;
//		case KeluarR4B:
//			R4BtoHome();
//			break;
//		default:
//			break;
//	}
//}

void backHome() {
	MundurLurus(25);
	wait(1);
	QuickStop();
	PutarBalik();
	keluarRuangan(false);
	QuickStop();

	switch (pintu.back()) {
	case KeluarR1A: // fall through
	case KeluarR1B:	// fall through
		ResetArah();
		GetArahMax();
		if(ARAH==SELATAN){
			MundurLurus(30);
			wait(1);
			PutarBalik();
			wallTerdekat();
		}
		switch (pintu.front()) {
		case KeluarR2:
			R1keR2(); break;
		case KeluarR3:
			R1keR3(); break;
		case KeluarR4A:	// fall through
		case KeluarR4B:
			R1keR4(); break;
		}
		break;
	case KeluarR1C:
		switch (pintu.front()) {
		case KeluarR2:
			R1keR2(); break;
		case KeluarR3:
			R1keR3(); break;
		case KeluarR4A:	// fall through
		case KeluarR4B:
			R1CkeR4(); break;
		}
		break;
	case KeluarR2:
		switch (pintu.front()) {
		case KeluarR1A:	// fall through
		case KeluarR1B:	// fall through
		case KeluarR1C:
			R2keR1(); break;
		case KeluarR3:
			R2keR3(); break;
		case KeluarR4A:	// fall through
		case KeluarR4B:
			R2keR4(); break;
		}
		break;
	case KeluarR3:
		switch (pintu.front()) {
		case KeluarR1A:	// fall through
		case KeluarR1B:	// fall through
		case KeluarR1C:
			R3keR1(); break;
		case KeluarR2:
			R3keR2(); break;
		case KeluarR4A:	// fall through
		case KeluarR4B:
			R3keR4(); break;
		}
		break;
	case KeluarR4A:
		switch (pintu.front()) {
		case KeluarR1A:	// fall through
		case KeluarR1B:	// fall through
		case KeluarR1C:
			R4AkeR1(); break;
		case KeluarR2:
			R4AkeR2(); break;
		case KeluarR3:
			R4AkeR3(); break;
		}
		break;
	case KeluarR4B:
		int totalDepan =0;
		ResetArah();
		PutarSampaiArah(SELATAN);
		while (JarakDepan > 13) {
			MajuLurus(30);
			wait(0.1);
		}


		ResetArah();
			PutarSampaiArahIR(TIMUR,AUTO);
			do{
				GeserKiri(30);
				wait(0.1);
			}while(JarakKiri<14);
			KoreksiArahIR();
			//PutarSampaiArahIR(BARAT,AUTO);
			for(int i=0; i<2;i++){
				PutarKiri(100);
				wait(0.1);
				totalDepan +=JarakDepan;
			}
			QuickStop();
			PutarKanan(200);
			wait(0.1);
			for(int i=0; i<2;i++){
				PutarKanan(100);
				wait(0.1);
				QuickStop();
				wait(0.1);
				totalDepan +=JarakDepan;
			}
			totalDepan /=4;


			LCD.locate(0,1);
			LCD.printf("%2d",totalDepan);
			QuickStop();
			wait(0.5);


		if (totalDepan > 40) {	// Tidak ada boneka
			switch (pintu.front()) {
			case KeluarR1A:	// fall through
			case KeluarR1B:	// fall through
			case KeluarR1C:
				R4BkeR1(); break;
			case KeluarR2:
				R4BkeR2(); break;
			case KeluarR3:
				R4BkeR3(); break;
			}
		} else {	// Ada boneka
			switch (pintu.front()) {
			case KeluarR1A:	// fall through
			case KeluarR1B:	// fall through
			case KeluarR1C:
				R4BkeR1C(); break;
			case KeluarR2:
				R4BkeR2(); break;
			case KeluarR3:
				R4BkeR3(); break;
			}
		}
		break;
	}

	MajuLurus(30);
	wait(2);
	QuickStop();
	wait(1000);
}
