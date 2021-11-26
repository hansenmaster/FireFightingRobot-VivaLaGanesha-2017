// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Jelajah.cpp
// author/editor : Babang
// created on : 27 Maret 2016
// Desc : Algoritma inti, jelajah seluruh ruangan untuk mencari api

#include "mbed.h"
#include "Jelajah.h"
#include "ObjectVariabel.h"


//void UpdatePintu(){ //x adalah total garis dilalui //masih perlu cari konstanta jauh, dekat yang tepat
//    int dekat =25;
//    int jauh = 55;
////    int sudut =kompas.readBearing();
////    int barat =2700;
////    int utara =1800;
////    int selatan=0;
////    int timur=900;
////    int toleransi =449;
//    GetArah(KompasToleransiBesar);
//    if (ARAH == TIMUR) //menghadap timur
//    {
//    	if(PrevRoom==R2&&JarakSRKanan<35){
//    	    Pintu = MasukR1A;
//		}else if(PrevRoom==R2&&JarakSRKanan>35){
//			Pintu = MasukR1B;
//		}
//        if ( JarakKanan < dekat && JarakKiri > 41 && JarakKiri < 70) //kiri dekat, kanan agakdekat
//        {
////            masuk[1] =1; // kiri [42,65]   kanan [0,25] depan[65,90]
//            Pintu = MasukR1A;
//        }
//        else if ( JarakKiri < 40 && JarakKanan > 15 && JarakKanan < 70) // Kanan dekat, Kiri agak dekat
//        {
//        	Pintu = MasukR1B;
//        }
//        else if ( JarakKanan < dekat && JarakKiri > 70 ) //kanan dekat, kiri jauh
//        {
////            keluar[2] = 1;     // kiri >100 , kanan[0,25]
//            Pintu = KeluarR2;
//        }
//        if(PrevRoom==R2&&JarakKanan<25){
//			Pintu = MasukR1A;
//		}else if(PrevRoom==R2&&JarakKiri<25){
//			Pintu = MasukR1B;
//		}
//    }
//    else if (ARAH == BARAT)//menghadap barat
//    {
//        if ( JarakKiri < dekat && JarakDepan >65 && JarakBelakang>40 ) //kiri dekat, kanan jauh
//        {
////            keluar[1] =1; // kanan >85 kiri <25 depan>65
//            Pintu = KeluarR1A;
//        }
////        alternatif masuk R2 : kiri dekat depan aga dekat
//        else if ( JarakKiri < dekat && JarakKanan < 80 ) //kiri dekat, kanan agakdekat
//		{
////			masuk[2] =1; //kiri<25 kanan <85 depan<65
//			Pintu = MasukR2;
//		}
////        alternatif keluar R1B
//        else if (JarakDepan < 31 && JarakBelakang >40) // depan dekat
//		{
//			Pintu = KeluarR1B;
//		}
//    }
//    else if (ARAH == UTARA)//menghadap utara
//    {
//
//
////    	if ( JarakKanan < dekat && JarakDepan > 70 && JarakKiri <23 )//kanan dekat, depan jauh, kiri jauh
////        {
//////            keluar[1] =1; //Depan >70 kanan<25 kiri >70
////            Pintu = KeluarR1C;
////        }
////        else if(JarakKanan < dekat && JarakDepan < 70 && JarakKiri > 23)
////        {
////        	Pintu = KeluarR1C;
////        }
////        else if ( JarakKiri >70 && JarakKanan>40 && JarakKanan<75 ) // kiri jauh kanan agakjauh
////        {
//////            keluar[4] =1; //kanan >55  kiri>70
////            Pintu = KeluarR4B;
//        }
//    	//if ( JarakKiri < 30 && JarakDepan > 45 && JarakDepan < 80)// kiri dekat, depan agakdekat
//		if(PrevRoom==HOME)
//		{
////            masuk[3] =1; //kiri<25  depan >45
//			Pintu = MasukR3;
//		}
//		else if (PrevRoom==R1)//( JarakKiri < dekat && JarakDepan < 35 && JarakKanan <55 )
//		{
////            masuk[4] =1; //kiri<25 kanan <55 depan <45
//			Pintu = MasukR4A;
//		}
//
//    else if (ARAH == SELATAN)//menghadap selatan
//    {
////    	alternatif keluar R3
//    	if (JarakKanan < dekat && JarakDepan < 30 ) //kanan dekat, depan dekat
//		{
////			keluar[3]=1; // kanan  dekat
//			Pintu = KeluarR3;
//		}
//        else if (PrevRoom==R1)//(JarakKiri<dekat && JarakKanan>dekat && JarakKanan<50)//kiri dekat, kanan dekat, belakang dekat
//        {
////            masuk[4] =1;
//            Pintu = MasukR4B;
//        }
//        else if (JarakKiri<dekat && JarakKanan>55)//kiri dekat, kanan jauh
//        {
////            masuk[1] =1; // kanan >55
//            Pintu = MasukR1C;
//        }
//        else if(JarakDepan<35 && JarakKanan >70)//depan dekat, kanan jauh
//        {
////            keluar[4] =1; // depan <35 kanan >70
//            Pintu = KeluarR4A;
//        }
//    }
//}

//void UpdatePosisi(){
//	UpdatePintu();
//	wait(0.1);
//	switch(Pintu){
////	jika case nya masuk, maka masuknya pada salah satu ruangan
//		case MasukR1A :
//			Posisi = R1;
//			break;
//		case MasukR1B :
//			Posisi = R1;
//			break;
//		case MasukR1C :
//			Posisi = R1;
//			break;
//		case MasukR2 :
//			Posisi = R2;
//			if(PrevRoom==R2){
//				Posisi = R1;
//			}else{
//				PrevRoom = R2;
//			}
//			break;
//		case MasukR3 :
//			Posisi = R3;
//			if(PrevRoom==R3){
//				Posisi = R2;
//			}else{
//				PrevRoom = R3;
//			}
//
//			break;
//		case MasukR4A :
//			Posisi = R4;
//			break;
//		case MasukR4B :
//			Posisi = R4;
//			break;
////		jika ketemunya keluar ruangan, maka akan dilimpahkan pada lorong
//		case KeluarR1A:
//			Posisi = LORONGBARAT;
//			PrevRoom = R1;
//			break;
//		case KeluarR1B:
//			Posisi = LORONGBARAT;
//			PrevRoom = R1;
//			break;
//		case KeluarR1C:
//			Posisi = LORONGTIMUR;
//			PrevRoom = R1;
//			break;
//		case KeluarR2:
//			Posisi = LORONGBARAT;
//			PrevRoom = R2;
//			break;
//		case KeluarR3:
//			Posisi = LORONGBARAT;
//			PrevRoom = R3;
//			break;
//		case KeluarR4A:
//			Posisi = LORONGBARAT;
//			PrevRoom = R4;
//			break;
//		case KeluarR4B:
//			Posisi = LORONGBARAT;
//			PrevRoom = R4;
//			break;
//
//	}
//	DisplayPosisi();
//}

//void JelajahHOME(){
//	Posisi = LORONGBARAT;
//	DisplayPosisi();
//
//
//	int AwalKompas = kompas.readBearing();
//	int ArahBatasAwal = 550;
//
////	if(AwalKompas<THBarat&&AwalKompas>ArahBatasAwal){
////		do {
////			GetArah(KompasToleransiBesar);
////			PutarKiri(220);
////			wait(0.1);
////		} while (ARAH!=BARAT);
////	}else if(AwalKompas<ArahBatasAwal||AwalKompas>THSelatan){
////		do {
////			GetArah(KompasToleransiBesar);
////			PutarKanan(220);
////			wait(0.1);
////		} while (ARAH!=SELATAN);
////	}
//	do{
//		GetArah(KompasToleransiKecil);
//		PutarKanan(150);
//		wait(0.1);
//	}while(ARAH!=SELATAN);
//	QuickStop();
//	wait(0.1);
////	MajuLurus(35);
////	wait(2);
////	do {
////		wallKanan2A(18,45,30);
////		wait(0.1);
////	} while (GarisBelakang == PUTIH || GarisDepan == PUTIH);
//
//	wait(0.1);
////            wall kanan hingga ketemu garis
//	do{
//		GetArah(KompasToleransiKecil);
//		wallKanan(18,40,30);
//		wait(0.1);
//	}while(ARAH!=BARAT);
//
//	do{
//		GetArah(KompasToleransiKecil);
//		wallKanan2A(18,40,30);
//		wait(0.1);
//	}while(GarisBelakang==HITAM);
//
//	QuickStop();
//	wait(0.1);
//	PrevRoom=HOME;
////            mengenali ruangan mana yang dimassuki
//	UpdatePosisi();
//}

//void JelajahR3(){
//	DisplayPosisi();
//	wait(0.3);
//	MajuLurus(40);
//	wait(0.7);
//	QuickStop();
//	wait(0.2);
////        	ngecek ada api gak
//	if(UV2.Flag==1)
//	{
////            	ada api, keluar dari fungsi ini
//		Mode=PADAMKANAPI;
////		break;
//	}
//	else{
////            	gada api, lanjutkan jelajah
////		PutarKiri(150);
////		wait(0.2);
//		do{
//			MundurLurus(55);
//			wait(0.1);
//		}while(JarakBelakang>18);
//		QuickStop();
//		putarKanan90();
//		Posisi=LORONGBARAT;
//	}
//}

//void JelajahR2(){
//	DisplayPosisi();
//	if(UV2.Flag==1)
//	{
//		Mode=PADAMKANAPI;
////		break;
//	}
////        	ngecek api,
//	for(int i=0; i<10;i++){
//		wallKiri(18,45,20);
//		wait(0.1);
//	}
////	MajuLurus(40);
////	wait(0.7);
//	TengokKiri(200);
//	QuickStop();
//	wait(0.5);
//	if(UV2.Flag==1||Mode==PADAMKANAPI)
//	{
//		Mode=PADAMKANAPI;
//		TengokKanan(0);
////		break;
//	}
//	else{
////		GeserKiri(40);
////		wait(0.2);
//		TengokKanan(0);
////		PutarKiri(200);
////		wait(0.1);
//		QuickStop();
//		wait(0.1);
//		MundurLurus(45);
//		wait(2.4);
//		do {
//			GetArah(250);
//			PutarKanan(140);
//			wait(0.1);
//		} while (ARAH!=TIMUR);
//		QuickStop();
//		wait(0.1);
//		Posisi=LORONGBARAT;
//	}
//	QuickStop();
//	wait(0.1);
//	PrevRoom=R2;
//}

//void JelajahR1(){
////	masuk ruang 1
////	int sum;
//	DisplayPosisi();
//	wait(0.3);
//	UpdatePosisi();
////	cek awal ada api
//	if(UV2.Flag==1)
//	{
//		Mode=PADAMKANAPI;
//	}
////	cek kiri ada api
//	if(Pintu==MasukR1B){
//		TengokKiri(150);
//		QuickStop();
//		if(UV2.Flag==1||Mode == PADAMKANAPI)
//		{
//			Mode=PADAMKANAPI;
//		}
//	}
//
////	cek kanan ada api
//	if(Pintu==MasukR1A){
//		TengokKanan(180);
//		QuickStop();
//		if(UV2.Flag==1||Mode == PADAMKANAPI)
//		{
//			Mode=PADAMKANAPI;
//		}
//	}
//
////	balikin ke posisi semula
//	TengokKiri(0);
//	QuickStop();
//
//
////	maju masuk ruangan biar uvtron kebaca
//	if(Pintu==MasukR1A){
////		masuk R1A
//		for(char i=0;i<7;i++){
//			wallKanan(18,40,25);
//			wait(0.1);
//		}
//	}else{
////		masuk R1B
//		MajuLurus(35);
//		wait(1);
//		UpdatePintu();
//	}
//	QuickStop();
//	wait(0.5);
//
////cek rentang tertentu
////
//	if(UV2.Flag==1||Mode == PADAMKANAPI){
//		Mode = PADAMKANAPI;
//		Posisi = R1;
//	}else{
////		masuk case ini jika sebelumnya tidak deteksi api
////		kalo ga ada api, lanjutkan keluar ruangan ke KeluarR1C
//
//		if(Pintu==MasukR1B){
////		keluar pintu jika masuk dari R1B
//			do{
//				wallKiri2B(18,40,25);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//		}
//		else{
////			keluar kalo masuk dari R1A
//			do{
//				wallKanan(19,40,25);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//
//		}
//
//		QuickStop();
//		wait(0.1);
//
//		//ngelurusin badan biar depannya kebaca
////		if(Pintu==MasukR1B){
////			if(kompas.readBearing()<=THUtara){
////				do{
////					GetArah(25);
////					PutarKiri(100);
////					wait(0.1);
////				}while(ARAH!=UTARA);
////			}else if(kompas.readBearing()>=THUtara+50){
////				do{
////					GetArah(25);
////					PutarKanan(100);
////					wait(0.1);
////				}while(ARAH!=UTARA);
////			}
////			QuickStop();
////			wait(0.1);
////		//	ketengahin badan, di pintu
////			if(JarakKanan>12){
////				GeserKiri(30);
////				wait(0.2);
////			}else{
////				GeserKanan(30);
////				wait(0.2);
////			}
////			QuickStop();
////			wait(0.3);
//
//
//		PrevRoom==R1;
//		Pintu=KeluarR1C;
//		Posisi = LORONGTIMUR;
//
//	}
//}
//void JelajahR4(){
//	DisplayPosisi();
//	wait(0.1);
//	if(UV2.Flag==1)
//	{
////		kalo ada api
//		Mode=PADAMKANAPI;
//	}
//	else{
////		kalo gaaada api, lanjutkan jelajah
//		MundurLurus(60);
//		wait(1);
//		putarKanan90();
//		Posisi=LORONGBARAT;
//	}
//}
//
//void JelajahLORONGBARAT(){
//	DisplayPosisi();
////	jelajah di lorong
//	if(PrevRoom==R3){
////		kalo habis dari ruangan 3
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKanan(18,45,20);
//			wait(0.1);
//		}while(ARAH!=SELATAN);
//
//		do{
//			wallKanan2(18,45,20);
//			wait(0.1);
//		}while(GarisBelakang==HITAM);
//	}
//	else if(PrevRoom==R2){
////		habis dari ruangan 2
//		do{
//			wallKanan2(18,45,20);
//			wait(0.1);
//		}while(GarisBelakang==HITAM);
//	}else {
////		selain setelah ruangan 2 dan 3
//		do{
//			wallKanan(18,45,20);
//			wait(0.1);
//		}while(GarisBelakang==HITAM);
//
//	}
////	ketika diruangan, harus berhenti sebentar untuk ngecek api
//	QuickStop();
//	wait(0.1);
//	UpdatePosisi();
//	wait(1);
//}
//
//void JelajahLORONGTIMUR(){
////	menampilkan posisi
//	DisplayPosisi();
////	maju dulu, cek depannya apa ada boneka
//	for(int i=0;i<12;i++){
//		wallKanan(18,45,20);
//		wait(0.1);
//	}
////	MajuLurus(40);
////	wait(1.2);
//	QuickStop();
//	wait(0.1);
////	if else jika depan ada boneka
//	if(JarakDepan<70){
////		ada boneka didepan, belok kekiri
//		do{
//			PutarKiri(150);
//			wait(0.1);
//			GetArah(KompasToleransiKecil);
//		}while(ARAH!=BARAT);
//		QuickStop();
//		wait(0.1);
////		maju biar ada pegangan wallKanan
//		MajuLurus(35);
//		wait(0.5);
//		do{
//			GetArah(KompasToleransiKecil);
//			wallKanan(18,45,20);
//			wait(0.1);
//		}while(ARAH!=TIMUR&&GarisBelakang==HITAM);
//		if(GarisBelakang==PUTIH){
//			// do nothing
//
//		}else{
////		wallKanan sampai masuk ruangan
//			do{
//				wallKanan2(18,45,20);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//		}
//
//	}
//	else{
////		jika didepan tidak ada boneka, cek sebelah kiri
//		do{
//			GetArah(85);
//			PutarKiri(150);
//			wait(0.1);
//		}while(ARAH!=BARAT);
//		QuickStop();
//		wait(0.1);
//		PutarKanan(200);
//		wait(0.5);
//		QuickStop();
//		wait(0.1);
//
//		if(JarakDepan<50){
////			jika didepannya ada boneka
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKanan(150);
//				wait(0.1);
//			}while(ARAH!=UTARA);
//			QuickStop();
//			wait(0.1);
////			wallKiri sampai masuk ruangan
//			do {
//				GetArah(KompasToleransiKecil);
//				wallKiri2(18,45,20);
//				wait(0.1);
//			} while (ARAH!=BARAT);
//
//			do {
//				GetArah(KompasToleransiKecil);
//				wallKiriA(18,45,20);
//				wait(0.1);
//			} while (ARAH!=SELATAN);
//			QuickStop();
//			wait(0.1);
////			jika depan jauh , masih dilorong
//			if(JarakDepan>50){
//				do {
//					wallKiri2(18,45,20);
//					wait(0.1);
//				} while (GarisBelakang==HITAM);
//			}
//		}
//		else{
////			jika didepan dan dikiri tidak ada boneka
////			putar kanan, wallKiri ikuti  dinding, nanti cek di sebelah kiri apa ada ruangan
//			do{
//				GetArah(100);
//				PutarKanan(200);
//				wait(0.05);
//			}while(ARAH!=UTARA);
//			PutarKiri(200);
//			wait(0.1);
//			QuickStop();
//			wait(0.1);
//			for(int i=0;i<25;i++){
//				wallKanan(18,45,20);
//				wait(0.1);
//			}
//
////			wallKanan agar tidak ketabrak boneka
////			wallKanan dengan mengecek didepannya apa ada boneka
//			do{
//				wallKanan(18,45,20);
//				wait(0.1);
//			}while(JarakDepan>14);
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKiri(150);
//				wait(0.1);
//			}while(ARAH!=BARAT);
//			QuickStop();
//			wait(0.1);
//
//			if(JarakDepan>55){
////				boneka jauh, kemungkinan ada boneka
//				do{
//					wallKanan(18,45,20);
//					wait(0.1);
//				}while(JarakBelakang<=40);
////				kalo dikirinya ada ruangan
//				if(JarakKiri>30||JarakSRKiri>35){
////					masuk ruangan
//					do{
//						wallKiri2(18,45,20);
//						wait(0.1);
//					}while(GarisBelakang==HITAM);
//				}
//				else{
////					kalo di kiri gada ruangan, putar 180 lalu cari ruangan selanjutnya
//					putar180();
//					do{
//						GetArah(KompasToleransiKecil);
//						wallKanan(18,45,20);
//						wait(0.1);
//					}while(ARAH!=BARAT);
//					do{
//						wallKanan2(18,45,20);
//						wait(0.1);
//					}while(GarisBelakang==HITAM);
//				}
//			}else{
//				do{
//					GetArah(KompasToleransiKecil);
//					PutarKiri(220);
//					wait(0.1);
//				}while(ARAH!=SELATAN);
//				QuickStop();
//				wait(0.1);
//				MajuLurus(35);
//				wait(0.3);
//				do{
//					wallKanan(18,45,20);
//					wait(0.1);
//				}while(GarisBelakang==HITAM);
//			}
//
////			jika keluar karena didepan ada boneka
//
//		}
//	}
//	GetArah(KompasToleransiKecil);
//	if(ARAH==UTARA){
//		Pintu==MasukR4A;
//	}
//	else{
//		Pintu==MasukR4B;
//	}
//	QuickStop();
//	wait(0.5);
////	UpdatePosisi();
////	UpdatePosisi();
//	Posisi = R4;
//}

//void JelajahPosisi(){
//
//    switch(Posisi){
//        case HOME:
//        	PrevRoom = HOME;
//        	JelajahHOME();
//            break;
//
//        case R3:
//        	JelajahR3();
//            break;
//
//        case R2:
//        	JelajahR2();
//            break;
//
//        case R1:
//        	JelajahR1();
//            break;
//
//        case R4:
//        	JelajahR4();
//            break;
//
//        case LORONGTIMUR:   //keluar ruang 1
//        	PrevRoom==R1;
//        	JelajahLORONGTIMUR();
//            break;
//
//        case LORONGBARAT:   //keluar semua ruang kecuali r1
//        	JelajahLORONGBARAT();
//            break;
//
//    }
//}

//void Latihan(){
//	PrevRoom = R2;
//	do{
//		wallKanan2(18,45,20);
//		wait(0.1);
//	}while(GarisBelakang==HITAM);
//	QuickStop();
//	wait(0.1);
//	JelajahR1();

//}

//void LatihanLorongTimur(){
//	PrevRoom = R1;
//	do{
//		wallKanan(19,40,20);
//		wait(0.1);
//	}while(GarisBelakang==HITAM);
//	QuickStop();
//	wait(0.1);
//	JelajahLORONGTIMUR();
//}



//void keluarRuangan() {
//	const int Batas = 15;
//
//	// Hadap ke timur
//	PutarSampaiArah(TIMUR,KANAN);
//
//	// Dua2nya dekat atau dua2nya jauh
//	if (!(!(JarakKiri <= Batas) != !(JarakKanan <= Batas))) {	// XOR
//		if (JarakDepan > Batas && JarakBelakang > Batas) {	// Dua2nya jauh
//			// Maju sampai kiri/kanan ada yg dekat
//			do {
//				MajuLurus(100);
//				wait(0.1);
//			} while (JarakKiri > Batas && JarakKanan > Batas);
//		} else if (JarakDepan <= Batas && JarakBelakang <= Batas) {	// Dua2nya dekat
//			// Maju sampai depan/blkg ada yg jauh
//			do {
//				GeserKiri(100);
//				wait(0.1);
//			} while (JarakDepan <= Batas && JarakBelakang <= Batas);
//
//			// Kalau kiri/kanan ga ada yg dkt putar utara
//			if (JarakKiri > Batas && JarakKanan > Batas) {
//				PutarSampaiArah(UTARA,KIRI);
//			}
//		} else {
//			// Putar utara
//			PutarSampaiArah(UTARA,KIRI);
//		}
//	}
//
//	if (JarakKiri < JarakKanan) {
//		// Wall following kiri
//		do {
//			wallKiri(13,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//	} else /* JarakKiri >= JarakKanan */ {
//		// Wall following kanan
//		do {
//			wallKanan(13,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//	}
//
//	// Cari ruang home dan pintu keluar
//	GetArah(KompasToleransiBesar);
//	switch (ARAH) {
//		case UTARA: {
//			if (JarakKanan <= 50) {
//				HomeRoom = R3;
//				keluar[0] = KeluarR3;
//			} else {
//				HomeRoom = R4;
//				keluar[0] = KeluarR4A;
//			}
//			break;
//		}
//		case SELATAN: 	HomeRoom = R4; keluar[0] = KeluarR4B; break;
//		case TIMUR: {
//			HomeRoom = R1;
//			if (JarakKiri <= 40) {
//				keluar[0] = KeluarR1A;
//			} else {
//				keluar[0] = KeluarR1B;
//			}
//			break;
//		}
//		case BARAT:		HomeRoom = R2; keluar[0] = KeluarR2; break;
//	}
//}

int TotalPutih()
{
	JumlahPutih=0;
	if(GarisBelakangKanan!=HITAM){
		JumlahPutih++;
	}
	if(GarisBelakangKiri!=HITAM){
		JumlahPutih++;
	}
	if(GarisDepanKanan != HITAM){
		JumlahPutih++;
	}
	if(GarisDepanKiri != HITAM){
		JumlahPutih++;
	}
	if(GarisTengah !=HITAM){
		JumlahPutih++;
	}
	return JumlahPutih;
}

int TotalHitam(){
	int JumlahHitam=0;
		if(GarisBelakangKanan == HITAM){
			JumlahHitam++;
		}
		if(GarisBelakangKiri == HITAM){
			JumlahHitam++;
		}
		if(GarisDepanKanan == HITAM){
			JumlahHitam++;
		}
		if(GarisDepanKiri == HITAM){
			JumlahHitam++;
		}
		if(GarisTengah==HITAM){
			JumlahHitam++;
		}

		return JumlahHitam;
}


void keluarRuangan(bool keluar_home) {
	/********* NOTES *********/
	/* Keluar ruangan harus ditambah pembacaan tombol depan
	 * buat robot supaya ga keterusan nabrak FURNITURE
	 **/
	DisplayLCD("KelRuang");
	InOut = true;
	if (JarakDepan < 20 && JarakBelakang < 20 ) {
		DisplayLCD("DEPAN/BLKG DEKAT");
		// Depan belakang dekat; diapit furnitur
		if (JarakKanan <= JarakKiri) {
			do {
				GeserKanan(30);
				wait(0.1);
			} while(JarakKanan > 8);
		} else {   //Jarak Kiri < Jarak Kanan
			do {
				GeserKiri(30);
				wait(0.1);
			} while(JarakKiri > 8);
		}
		PutarSampaiArahIR(TIMUR);
	} else if (JarakKanan < 15 && JarakKiri < 15) {
		// Kanan kiri dekat; diapit furniture
		if (JarakDepan < 15)
			PutarBalik();
		do { // Maju sampai melewati furniture
			MajuLurus(25);
			wait(0.1);
		} while (JarakKanan < 25 && JarakKiri < 25);
		// wall following sampai aman rotasi
		if (JarakKanan <= JarakKiri){
			for(int i = 0;i<=4;i++){
				wallKananSlow(14,25,10);
				wait(0.1);
			}
		} else { // Kiri < kanan
			for(int i = 0;i<=4;i++){
				wallKiriSlow(14,25,10);
				wait(0.1);
			}
		}
		PutarSampaiArahIR(TIMUR);
	}
	keluarNormal(keluar_home);
	InOut = false;
	QuickStop();
	wait(0.1);
	Pemetaan();
}

void wallTerdekatStart(){
	DisplayLCD("wallSTART");
	if(JarakKanan<=JarakKiri){
		LeftRight = 1; //kanan
		if(JarakKanan>9){
			GeserKanan(30);
			wait(0.3);
		}
//		while(JarakSRKanan>20){
//			PutarKanan(120);
//			wait(0.1);
//		}
		do{
			wallKananSlow(14,25,10);
			wait(0.05);
		}while(GarisBelakangKanan==HITAM);

	}
	else{
		LeftRight = 0; //kiri
		if(JarakKiri>9){
			GeserKiri(30);
			wait(0.3);
		}
//		while(JarakSRKiri>25){
//			PutarKiri(120);
//			wait(0.1);
//		}
		do{
			wallKiriSlow(14,25,10);
			wait(0.05);
		}while(GarisBelakangKanan==HITAM);
	}
}

void wallHome(){
//	if (!sudahGeser){
		if(JarakKanan<=JarakKiri){
				LeftRight = 1; //kanan
			}
			else {
				LeftRight = 0; //kiri
			}
			if(TotalHitam()==5){
				DisplayLCD("HITAM SEMUA");
				if(LeftRight){//kanan dekat
					do{
						wallKananSlow(14,25,10);
						wait(0.05);
					}while(TotalHitam()>=5);
				}
				else{//kiri
					do{
						wallKiriSlow(14,25,10);
						wait(0.05);
					}while(TotalHitam()>=5);
				}
			}
		//ga item semua. masih kena lingkaran home
				DisplayLCD("ADA PUTIH");
				if(LeftRight){//kanan dekat
					do{
						GeserKanan(30);
						wait(0.1);
					}while(JarakKanan>11);
					QuickStop();
					wait(0.1);
					do{
						wallKananSlow(14,25,10);
						wait(0.05);
					}while(TotalHitam()!=5);
				}
				else{//kiri
					do{
						GeserKiri(30);
						wait(0.1);
					}while(JarakKiri>11);
					QuickStop();
					wait(0.1);
					do{
						wallKiriSlow(14,25,10);
						wait(0.05);
					}while(TotalHitam()!=5);
				}



	DisplayLCD("WALL DEKAT");
	wallTerdekat3();
}

//void wallTerdekatAntiHome(){
//	wallTerdekatStart();
//	do{
//		DisplayLCD("Wall Anti HOME");
//
//		while(TotalPutih()>=1){
//			LCD.locate(4,1);
//			DisplayLCD("putih banyak");
//			QuickStop();
//			wait(0.1);
//			if(!LeftRight){//kiri
//				DisplayLCD("Lanjut KIRI");
//				for(int i=1;i<=2;i++){
//					wallKiriSlow(14,25,10);
//					wait(0.1);
//				}
//			}
//			else{
//				DisplayLCD("Lanjut KANAN");
//				for(int i=1;i<=2;i++){
//					wallKananSlow(14,25,10);
//					wait(0.1);
//				}
//			}
//		}
//
//
//
//		//else{ //putih dikit
//			if(!LeftRight){//kiri
//				DisplayLCD("KIRI NEXT");
//				for(int i=1;i<=2;i++){
//					wallKiriSlow(14,25,10);
//					wait(0.1);
//				}
//			}
//			else{
//				DisplayLCD("KANAN NEXT");
//				for(int i=1;i<=2;i++){
//					wallKananSlow(14,25,10);
//					wait(0.1);
//				}
//			}
//	//	}
//			QuickStop();
//	//	}
//		//while(GarisBelakangKanan!=HITAM){
//
//				//wait(4);
//	}while(GarisBelakangKanan!=HITAM);
//
//
//}

void wallTerdekat(){
	if(JarakKanan<=JarakKiri){
		if(JarakKanan>9){
			GeserKanan(30);
			wait(0.3);
		}
//		while(JarakSRKanan>20){
//			PutarKanan(120);
//			wait(0.1);
//		}
		do{
			wallKananSlow(14,25,10);
			wait(0.05);
		}while(GarisTengah==HITAM);

	}
	else{
		if(JarakKiri>9){
			GeserKiri(30);
			wait(0.3);
		}
//		while(JarakSRKiri>25){
//			PutarKiri(120);
//			wait(0.1);
//		}
		do{
			wallKiriSlow(14,25,10);
			wait(0.05);
		}while(GarisTengah==HITAM);
	}
}

//void wallTerdekat2(){
//	if(JarakKanan<=JarakKiri){
//		if(JarakKanan>9){
//			GeserKanan(30);
//			wait(0.3);
//		}
////		while(JarakSRKanan>20){
////			PutarKanan(120);
////			wait(0.1);
////		}
//		do{
//			wallKananSlow(14,25,10);
//			wait(0.05);
//			if(GarisTengah==PUTIH){
//
//				if((GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH ) && !(GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH)){
//					GeserKanan(30);
//					wait(0.2);
////					QuickStop();
////					MundurLurus(30);
////					wait(0.2);
//				}else if((GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH) && !(GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH)){
//					GeserKiri(30);
//					wait(0.2);
////					QuickStop();
////					MundurLurus(30);
////					wait(0.2);
//				}
//				QuickStop();
//				wait(0.2);
//			}
//		}while(GarisTengah==HITAM || ((GarisBelakangKanan!=GarisDepanKiri)||(GarisBelakangKiri!=GarisDepanKanan)));
//
//	}
//	else{
//		if(JarakKiri>9){
//			GeserKiri(30);
//			wait(0.3);
//		}
////		while(JarakSRKiri>25){
////			PutarKiri(120);
////			wait(0.1);
////		}
//		do{
//			wallKiriSlow(14,25,10);
//			wait(0.05);
//			if(GarisTengah==PUTIH){
//
//				if((GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH ) && !(GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKanan(30);
//					wait(0.2);
//					QuickStop();
//				}else if((GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH) && !(GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKiri(30);
//					wait(0.2);
//					QuickStop();
//				}
//			}
//		}while(GarisTengah==HITAM || ((GarisBelakangKanan!=GarisDepanKiri)||(GarisBelakangKiri!=GarisDepanKanan)));
//	}
//	DisplayLCD("KELUARRR");
//}

void wallTerdekat3(){
	if(JarakKanan<=JarakKiri){
		if(JarakKanan>9){
			GeserKanan(30);
			wait(0.3);
		}
//		while(JarakSRKanan>20){
//			PutarKanan(120);
//			wait(0.1);
//		}
		do{
			wallKananSlow(14,25,10);
			wait(0.05);
		}while(GarisTengah==HITAM||totalADC()<BatasGaris);//(GarisTengah==HITAM || TotalHitam()<=3);

	}
	else{
		if(JarakKiri>9){
			GeserKiri(30);
			wait(0.3);
		}
//		while(JarakSRKiri>25){
//			PutarKiri(120);
//			wait(0.1);
//		}
		do{
			wallKiriSlow(14,25,10);
			wait(0.05);
		}while(GarisTengah==HITAM||totalADC()<BatasGaris);//(GarisTengah==HITAM || TotalHitam()<=3);
	}
	DisplayLCD("KELUARRR");
}

//void wallTerdekat2(){
//	if(JarakKanan<=JarakKiri){
//		if(JarakKanan>9){
//			GeserKanan(30);
//			wait(0.3);
//		}
////		while(JarakSRKanan>20){
////			PutarKanan(120);
////			wait(0.1);
////		}
//		do{
//			wallKananSlow(14,25,10);
//			wait(0.05);
//			if(GarisTengah==PUTIH){
//
//				if((GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH ) && !(GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH)){
//					GeserKanan(30);
//					wait(0.2);
//					QuickStop();
//					MundurLurus(30);
//					wait(0.2);
//				}else if((GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH) && !(GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH)){
//					GeserKiri(30);
//					wait(0.2);
//					QuickStop();
//					MundurLurus(30);
//					wait(0.2);
//				}
//				QuickStop();
//				wait(0.2);
//			}
//		}while(!IsGaris());//(GarisTengah==HITAM || TotalHitam()<=3);
//
//	}
//	else{
//		if(JarakKiri>9){
//			GeserKiri(30);
//			wait(0.3);
//		}
////		while(JarakSRKiri>25){
////			PutarKiri(120);
////			wait(0.1);
////		}
//		do{
//			wallKiriSlow(14,25,10);
//			wait(0.05);
//			if(GarisTengah==PUTIH){
//
//				if((GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH ) && !(GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKanan(30);
//					wait(0.2);
//					QuickStop();
//				}else if((GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH) && !(GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKiri(30);
//					wait(0.2);
//					QuickStop();
//				}
//			}
//		}while(!IsGaris());//(GarisTengah==HITAM || TotalHitam()<=3);
//	}
//	DisplayLCD("KELUARRR");
//}
//bool IsGaris()
//{
//	if(GarisTengah==PUTIH){
//		if(TotalPutih()<=1){
//			return true;
//		}
//		else if(TotalPutih()>3){
//			return false;
//		}
//		else{
//			if((GarisBelakangKanan==PUTIH&&GarisDepanKiri==PUTIH)||(GarisBelakangKiri==PUTIH&&GarisDepanKanan==PUTIH)){
//				return true;
//			}
//			else{
//					return false;
//				}
//			}
//
//
//	}
//	else{
//		return false;
//	}
//}

bool IsGaris()
{
	if(GarisTengah==PUTIH){
		if(TotalPutih()<=2){
			return true;
		}
		else
			return false;
		}

}
//void wallTerdekat2(){
//	if(JarakKanan<=JarakKiri){
//		if(JarakKanan>9){
//			GeserKanan(30);
//			wait(0.3);
//		}
////		while(JarakSRKanan>20){
////			PutarKanan(120);
////			wait(0.1);
////		}
//		do{
//			wallKananSlow(14,25,10);
//			wait(0.05);
//			if(GarisTengah==PUTIH){
//
//				if((GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH ) && !(GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKanan(30);
//					wait(0.2);
//					QuickStop();
//				}else if((GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH) && !(GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKiri(30);
//					wait(0.2);
//					QuickStop();
//				}
//			}
//		}while(GarisTengah==HITAM || TotalHitam()<=3);
//
//	}
//	else{
//		if(JarakKiri>9){
//			GeserKiri(30);
//			wait(0.3);
//		}
////		while(JarakSRKiri>25){
////			PutarKiri(120);
////			wait(0.1);
////		}
//		do{
//			wallKiriSlow(14,25,10);
//			wait(0.05);
//			if(GarisTengah==PUTIH){
//
//				if((GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH ) && !(GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKanan(30);
//					wait(0.2);
//					QuickStop();
//				}else if((GarisBelakangKiri==PUTIH || GarisDepanKiri == PUTIH) && !(GarisBelakangKanan==PUTIH || GarisDepanKanan == PUTIH)){
//					DisplayLCD("HOME");
//					GeserKiri(30);
//					wait(0.2);
//					QuickStop();
//				}
//			}
//		}while(GarisTengah==HITAM || TotalHitam()<=3);
//	}
//	DisplayLCD("KELUARRR");
//}

void keluarNormal(bool keluar_home){

	DisplayLCD("KelNormal");
	PutarSampaiArahIR(TIMUR,AUTO,100);
	ResetArah();
	if (avgJarakDepan() < 60) {	// Jarak tidak jauh banget
		DisplayLCD("Depan <60");
		LCD.cls();
		LCD.printf("%d",avgJarakDepan());
		QuickStop();
		wait(0.1);
		if (JarakBelakang < 15) {
			if (JarakKanan <= JarakKiri){
				DisplayLCD("Ke UTARA");
				PutarSampaiArah(UTARA);
			} else { // kiri < Kanan
				PutarSampaiArah(SELATAN);
				DisplayLCD("ke SELATAN");
			}
		}


		QuickStop();
		wait(0.1);
	}
	if (keluar_home)
		wallTerdekat();
	else
		wallTerdekat();
	lurusGaris();
}

void lurusGaris(){
	if (GarisDepanKiri == PUTIH || GarisBelakangKanan == PUTIH){
		PutarKiri(60);
		wait(0.4);
	} else if (GarisDepanKanan == PUTIH || GarisBelakangKiri == PUTIH){
		PutarKanan(60);
		wait(0.4);
	}
}
void ResetArah () {
	ARAH = NONE;
}


void Pemetaan() {
	GetArahMax();
	//GetArah(374);
	char arah = ARAH;
	ResetArah();
	PutarSampaiArah(arah);
	if (InOut) {	// Di dalam
		switch (ARAH) {
		case TIMUR:
			pintu.push_back(MasukR2);
			break;
		case BARAT:
			if (JarakSRKiri<= 30) {
				pintu.push_back(MasukR1B);
			} else {
				pintu.push_back(MasukR1A);
			}
			break;
		case UTARA:
			if (JarakDepan <= 51) {
				pintu.push_back(MasukR4B);
			} else {
				pintu.push_back(MasukR1C);
			}
			break;
		case SELATAN:
			if (JarakDepan <= 51) {
				pintu.push_back(MasukR4A);
			} else {
				pintu.push_back(MasukR3);
			}
			break;
		}
	} else {	// Di luar
		switch (ARAH) {
		case BARAT:
			pintu.push_back(KeluarR2);
			break;
		case TIMUR:
//			if(JarakSRKiri<15 && JarakDepan<=40){
//				PutarKanan
//			}
//			do{
//				GeserKanan(30);
//				wait(0.1);
//			}while(JarakKiri<12);
			MajuLurus(25);
			wait(0.3);
			QuickStop();
			if (JarakSRKiri > 25) {
				pintu.push_back(KeluarR1B);
			} else {
				pintu.push_back(KeluarR1A);
			}
			break;
		case UTARA:
			MajuLurus(30);
			wait(0.7);
			QuickStop();
//			if (JarakSRKanan <= 35) {
			if (JarakKanan <= 33) {
				pintu.push_back(KeluarR3);
			} else {
				pintu.push_back(KeluarR4A);
			}
			break;
		case SELATAN:
			MajuLurus(30);
			wait(0.8);
			QuickStop();
			if (JarakKanan >= 20) {
				pintu.push_back(KeluarR4B);
			} else {
				pintu.push_back(KeluarR1C);
			}
			break;
		}
	}
	DisplayPintu();
	QuickStop();
	wait(0.1);
}

void CariRuangan() {
	DisplayLCD("CariRuang");
	switch (pintu.back()) {
	case KeluarR1A:	// fall through
	case KeluarR1B:
		JelajahR1(); break;
	case KeluarR1C:
		JelajahR1C(); break;
	case KeluarR2:
		JelajahR2(); break;
	case KeluarR3:
		JelajahR3(); break;
	case KeluarR4A:
		JelajahR4A(); break;
	case KeluarR4B:
		JelajahR4B(); break;
	}
}

void JelajahR1 () {
	R1keR2();
	if (CariApiR2()) return;

	R2keR3();
	if (CariApiR3()) return;

	R3keR4();
	if (pintu.back() == MasukR4A) {
		if (CariApiR4A()) return;
	} else if (pintu.back() == MasukR4B) {
		if (CariApiR4B()) return;
	}
}

//void JelajahR1C () {
//	R1CkeR4();
//	if (pintu.back() == MasukR4A) {
//		if (CariApiR4A()) return;
//
//		R4AkeR2();
//		if (CariApiR2()) return;
//
//		R2keR3();
//		if (CariApiR3()) return;
//	} else if (pintu.back() == MasukR4B) {
//		if (CariApiR4B()) return;
//
//		while (JarakDepan > 13) {
//			MajuLurus(35);
//			wait(0.1);
//		}
//		PutarSampaiArah(TIMUR);
//		if (JarakDepan > 45) {
//			R4BkeR3();
//			if (CariApiR3()) return;
//
//			R3keR2();
//			if (CariApiR2()) return;
//		} else {
//			PosisiBoneka = SELATAN;
//
//			R4BkeR2();
//			if (CariApiR2()) return;
//
//			R2keR3();
//			if (CariApiR3()) return;
//		}
//	}
//}
void JelajahR1C () {
	PutarSampaiArah(SELATAN);
	lurusGaris();
	QuickStop();
	wait(0.2);

	while (JarakKanan>8){
		GeserKanan(30);
		wait(0.1);

	}
	QuickStop();

	MajuLurus(35);
	wait (0.7);
	ResetArah();
	PutarSampaiArah(UTARA);
	do {
	wallKiriSlow(14, 25, 10);
	wait(0.1);
	}while (GarisTengah==HITAM);


	do {
		GeserKanan(30);
		wait(0.1);
	} while (JarakKiri > 13);

	do {
		wallKananSlow(14,25,10);
		wait(0.1);
	} while (GarisTengah == HITAM);

	JelajahR1();


}
void JelajahR2 () {
	R2keR1();
	if (pintu.back() == MasukR1A) {
		if (CariApiR1A()) return;
	} else if (pintu.back() == MasukR1B) {
		if (CariApiR1B()) return;
	}

	R1keR3();
	if (CariApiR3()) return;

	R3keR4();
	if (pintu.back() == MasukR4A) {
		if (CariApiR4A()) return;
	} else if (pintu.back() == MasukR4B) {
		if (CariApiR4B()) return;
	}
}

void JelajahR3 () {
	R3keR2();
	if (CariApiR2()) return;

	R2keR1();
	if (pintu.back() == MasukR1A) {
		if (CariApiR1A()) return;
	} else if (pintu.back() == MasukR1B) {
		if (CariApiR1B()) return;
	}

	R1keR4();
	if (pintu.back() == MasukR4A) {
		if (CariApiR4A()) return;
	} else if (pintu.back() == MasukR4B) {
		if (CariApiR4B()) return;
	}
}

void JelajahR4A () {
	R4AkeR2();
	if (CariApiR2()) return;

	R2keR1();
	if (pintu.back() == MasukR1A) {
		if (CariApiR1A()) return;
	} else if (pintu.back() == MasukR1B) {
		if (CariApiR1B()) return;
	}

	R1keR3();
	if (CariApiR3()) return;
}

//void JelajahR4B () {
//	int totalDepan = 0;
//	while (JarakDepan > 13) {
//		MajuLurus(35);
//		wait(0.1);
//	}
//	PutarSampaiArahIR(TIMUR);
//	for(int i=0; i<2;i++){
//			PutarKiri(100);
//			wait(0.1);
//			totalDepan +=JarakDepan;
//		}
//		QuickStop();
//		PutarKanan(50);
//		wait(0.1);
//		for(int i=0; i<2;i++){
//			PutarKanan(100);
//			wait(0.1);
//			totalDepan +=JarakDepan;
//		}
//		totalDepan /=4;
//
//
//		LCD.locate(0,1);
//		LCD.printf("%2d",totalDepan);
//		QuickStop();
//		wait(0.5);
//	if (totalDepan >60) {	// Tidak ada boneka
//		R4BkeR3();
//		if (CariApiR3()) return;
//
//		R3keR2();
//		if (CariApiR2()) return;
//
//		R2keR1();
//		if (pintu.back() == MasukR1A) {
//			if (CariApiR1A()) return;
//		} else if (pintu.back() == MasukR1B) {
//			if (CariApiR1B()) return;
//		}
//	} else {	// Ada boneka
//		PosisiBoneka = SELATAN;
//
//		R4BkeR1C();
//		if (CariApiR1C()) return;
//
//		R1keR2();
//
//
//		if (CariApiR2()) return;
//
//		R2keR3();
//		if (CariApiR3()) return;
//	}
//}

void JelajahR4B () {
	int totalDepan = 0;
	while (JarakDepan > 13) {
		MajuLurus(35);
		wait(0.1);
	}
	PutarSampaiArahIR(TIMUR);
	for(int i=0; i<2;i++){
			PutarKiri(100);
			wait(0.1);
			totalDepan +=JarakDepan;
		}
		QuickStop();
		PutarKanan(50);
		wait(0.1);
		for(int i=0; i<2;i++){
			PutarKanan(100);
			wait(0.1);
			totalDepan +=JarakDepan;
		}
		totalDepan /=4;


//		LCD.locate(0,1);
//		LCD.printf("%2d",totalDepan);
		QuickStop();
		wait(0.5);
	if (totalDepan >60) {	// Tidak ada boneka
		R4BkeR3();
		if (CariApiR3()) return;

		R3keR2();
		if (CariApiR2()) return;

		R2keR1();
		if (pintu.back() == MasukR1A) {
			if (CariApiR1A()) return;
		} else if (pintu.back() == MasukR1B) {
			if (CariApiR1B()) return;
		}
	} else {	// Ada boneka
		PosisiBoneka = SELATAN;

		R4BkeR1C();
		if (CariApiR1C()) return;

		R1CkeR2();


		if (CariApiR2()) return;

		R2keR3();
		if (CariApiR3()) return;
	}
}

void R1keR2() {
	DisplayLCD("R1>R2");
	for (int i = 1; i <= 13; i++){
		wallKiri2(14,25,10);
		wait(0.1);
	}

	// Wall kiri sampai masuk R2
	do {
		wallKiri2(14,25,10);
		wait(0.1);
	} while (GarisTengah == HITAM);

	// Masuk R2
	lurusGaris();
	pintu.push_back(MasukR2);
	DisplayPintu();
}

void R1keR3 () {
	DisplayLCD("R1>R3");

	// Ke lorong timur
	R1keLorongTimur();

	// Wall kiri sampai masuk R3
	do {
		wallKiriSlow(14,25,10);
		wait(0.05);
	} while (GarisTengah == HITAM);

	// Masuk R3
	lurusGaris();
	Pemetaan();
	DisplayPintu();
}

void R1keR4 () {
	DisplayLCD("R1>R4");

	// Ke lorong timur
	R1keLorongTimur();

	// Putar ke barat (balik arah 180 derajat)
	PutarSampaiArah(BARAT,KANAN);

	// Ke R4
	LorongTimurkeR4();
}

//void R1CkeR4() {
//	DisplayLCD("R1C>R4");
//
//	PutarSampaiArahIR(SELATAN); // menghadap selatan
//	QuickStop();
//	wait(0.1);
//
//	DisplayLCD("geserKiri"); // jauhin dari tembok sedikit
//	while(JarakKanan<11) {
//		GeserKiri(30);
//		wait(0.1);
//	}
//	QuickStop();
//
//	DisplayLCD("Cek Boneka");
//	if (avgJarakDepan() < 65) { // jika didepan ada boneka
//		// Boneka di lorong barat R4
//		DisplayLCD("depan boneka");
//		PosisiBoneka = BARAT;
//
//		// Wall kiri sampai timur
//		do {    // masuk ke lorong tengah untuk menghindari boneka
//			wallKiri2(15,25,10);
//			wait(0.1);
//			GetArah(150);
//		} while (ARAH != TIMUR || JarakKanan > 20);
////		PutarSampaiArah(TIMUR); // arahkan ke timur
////
////		MajuLurus(20);
////		wait(0.4);
////		QuickStop();
////		wait(0.1);
////		// Geser kanan utk wall kanan
////		do { // deketin ke kanan untuk siap siap wall kanan
////			GeserKanan(30);
////			wait(0.1);
////		} while (JarakKanan > 8);
//
//		// Wall kanan sampai masuk
//		DisplayLCD("wallsampai R4");
//		do {
//			wallKananSlow(16,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//	} else { // saat keluar R1C, tetapi didepan tidak ada boneka, maka jalan terus
//		DisplayLCD("AJG!Selatan");
//		// Cek R4B
//		do {
//			wallKanan(16,25,10); // wall kanan selagi jarak kirinya masih jauh
//			wait(0.1); // dilakukan untuk mencari tembok sebelah kiri terdekat
//		} while (JarakKiri > 20);
//		MajuLurus(30); // maju lurus untuk memastikan sudah ada tembok kiri
//		wait(0.3);
//		QuickStop();
//
//		while(JarakKiri>9){ // rapatkan ke dinding kiri
//			GeserKiri(30);
//			wait(0.1);
//		}
//
//		QuickStop();
//
//		DisplayLCD("CariPintu"); // wall kiri sampai ruangan ketemu atau ada boneka di
//		do {					// bagian paling selatan
//			wallKiri2(15,25,10);
//			wait(0.1);
//		} while (!(GarisTengah == PUTIH || JarakDepan < 13));
//
//		QuickStop();
//		wait(2);
//		GetArah(250);
//		if (ARAH!=UTARA){   // berhenti karena kemungkinannya ada 2, yaitu jumpa garis R4A
//							// atau jumpa boneka di bagian selatan
//							// jika arah yang dimaksud adalah selatan(artinya jumpa garis R4A),
//							// tidak masalah karena langsung keluar if conditional
//							// dan langsung memetakan ruang
//			DisplayLCD("BUKAN R4B");
//			ResetArah();
//			GetArah(250);
//			if (ARAH==TIMUR){ // jika dia berhenti karena jumpa boneka di selatan
//				// Boneka di selatan R4
//				PosisiBoneka = SELATAN;
//
//						// R4A
//				do { // mundur lurus, balik arah kemudian wal kanan sampai ketemu garis di R4A
//					MundurLurus(30);
//					wait(0.1);
//				} while (JarakDepan < 20);
//				PutarSampaiArah(BARAT);
//				do {
//					wallKananSlow(15,25,10);
//					wait(0.1);
//				} while (GarisTengah == HITAM);
//
//			}
//		}
//
//
//
//	}
//	lurusGaris();
//	InOut = true;
//	Pemetaan();
//	DisplayPintu();
//	wait(0.1);
//}

//void R1CkeR4() {
//	DisplayLCD("R1C>R4");
//
//	PutarSampaiArahIR(SELATAN); // menghadap selatan
//	QuickStop();
//	wait(0.1);
//
//	DisplayLCD("geserKiri"); // jauhin dari tembok sedikit
//	while(JarakKanan<10) {
//		GeserKiri(30);
//		wait(0.1);
//	}
//	QuickStop();
//
//	DisplayLCD("Cek Boneka");
//	if (avgJarakDepan() < 70) { // jika didepan ada boneka
//		// Boneka di lorong barat R4
//		DisplayLCD("depan boneka");
//		PosisiBoneka = BARAT;
//		MundurLurus(30);
//		wait(0.3);
//
//		// Wall kiri sampai timur
//		do {    // masuk ke lorong tengah untuk menghindari boneka
//			wallKiri2(15,25,10);
//			wait(0.1);
//			GetArah(150);
//		} while (ARAH != TIMUR || JarakKanan > 20);
////		PutarSampaiArah(TIMUR); // arahkan ke timur
////
////		MajuLurus(20);
////		wait(0.4);
////		QuickStop();
////		wait(0.1);
////		// Geser kanan utk wall kanan
////		do { // deketin ke kanan untuk siap siap wall kanan
////			GeserKanan(30);
////			wait(0.1);
////		} while (JarakKanan > 8);
//
//		// Wall kanan sampai masuk
//		DisplayLCD("wallsampai R4");
//		do {
//			wallKananSlow(16,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//	} else { // saat keluar R1C, tetapi didepan tidak ada boneka, maka jalan terus
//		DisplayLCD("AJG!Selatan");
//		// Cek R4B
//		do{
//			GeserKanan(30);
//			wait(0.1);
//		}while (JarakKanan > 9);
//
////		do {
////			wallKanan(16,25,10); // wall kanan selagi jarak kirinya masih jauh
////			wait(0.1); // dilakukan untuk mencari tembok sebelah kiri terdekat
////		} while (JarakKiri > 40);
//
//		for (int i=0; i<20; i++){
//			wallKanan(16,25,10);
//			wait(0.1);
//		}
//		MajuLurus(30); // maju lurus untuk memastikan sudah ada tembok kiri
//		wait(0.3);
//		QuickStop();
//
//		while(JarakKiri>9){ // rapatkan ke dinding kiri
//			GeserKiri(30);
//			wait(0.1);
//		}
//
//		QuickStop();
//
//		DisplayLCD("CariPintu"); // wall kiri sampai ruangan ketemu atau ada boneka di
////		do {					// bagian paling selatan
////			wallKiri2(15,25,10);
////			wait(0.1);
////		} while (!(GarisTengah == PUTIH || JarakDepan < 13));
//		do {					// bagian paling selatan
//			wallKiri2(15,25,10);
//			wait(0.1);
//			GetArah(150);
//		} while (ARAH!=TIMUR);
//		ResetArah();
//		PutarSampaiArahIR(TIMUR);
//		if(JarakSRKiri < 35){
//			DisplayLCD("Bukan R4B");
//			do{
//				GeserKanan(30);
//				wait(0.1);
//			}while(JarakKanan>14);
//			do{
//				MajuLurus(30);
//				wait(0.1);
//			}while(JarakBelakang<64);
//
//			if(avgJarakDepan()<70){
//				DisplayLCD("BONEKA");
//				PosisiBoneka = SELATAN;
//				// R4A
//				do { // mundur lurus, balik arah kemudian wal kanan sampai ketemu garis di R4A
//					MundurLurus(30);
//					wait(0.1);
//				} while (JarakDepan < 20);
//				PutarSampaiArah(BARAT);
//				do {
//					wallKananSlow(15,25,10);
//					wait(0.1);
//				} while (GarisTengah == HITAM);
//			}
//			else{
//				DisplayLCD("R4A");
//				do{
//					wallKiriSlow(15,25,10);
//					wait(0.1);
//				}while(GarisTengah == HITAM);
//
//			}
//		}
//		else{
//			DisplayLCD("R4B");
//			MajuLurus(20);
//			wait(0.2);
//			QuickStop();
//			do{
//				wallKiriSlow(15,25,10);
//				wait(0.1);
//			}while(GarisTengah == HITAM);
//		}
//	}
//	lurusGaris();
//	InOut = true;
//	Pemetaan();
//	DisplayPintu();
//	wait(0.1);
//}
//
////void R1CkeR2(){
////	MajuLurus(30); // memastikan tidak kena garis
////	wait(1);
////
////	ResetArah();
////	DisplayLCD("CARI TIMUR");
////	PutarSampaiArah(TIMUR,AUTO,100);
////
////	DisplayLCD("CARI DINDING");
////	do {
////		MajuLurus(30); //mencari dinding untuk wall
////		wait(0.5);
////	}while (JarakKiri>30);
////
////	DisplayLCD("CARI UTARA");
////	do {
////		wallKiri(16,25,10);
////		wait(0.1);
////		GetArah(350);
////	}while (!(JarakKanan<20 && ARAH == UTARA));
////
////	DisplayLCD("DEKAT->KANAN");
////	while(JarakKanan>10){
////		GeserKanan(30);
////		wait(0.1);
////	}
////
////	DisplayLCD("CARI GARIS");
////	do {
////		wallKanan(16,25,10);
////		wait (0.1);
////	}while (GarisTengah == HITAM);
////
////
////	DisplayLCD("MASUK R2");
////	InOut = true;
////	lurusGaris();
////	pintu.push_back(MasukR2);
////	DisplayPintu();
////}
//
//void R1CkeR2(){
//	DisplayLCD("R1C ke R2");
//	do{
//		GeserKiri(30);
//		wait(0.1);
//	}while(JarakKanan<12);
//	for(int i =0; i<5;i++){
//		wallKiri(16,25,10);
//		wait(0.1);
//	}
//	DisplayLCD("Wall Kiri");
//	ResetArah();
//		do {
//			wallKiri2B(15,25,10);
//			wait(0.1);
//			GetArah(200);
//		} while (ARAH != UTARA || JarakKanan > 24);
//
//		if (ARAH == UTARA) {
//			DisplayLCD("UTARA");
//		} else {
//			DisplayLCD("Kanan Dekat");
//		}
//
//		PutarSampaiArah(UTARA);
//		PutarKanan(100);
//		wait(0.3);
//		QuickStop();
//		wait(0.1);
//		do {
//			GeserKanan(40);
//			wait(0.1);
//		} while(JarakKanan > 8 && JarakSRKanan > 11);
//
//		do {
//			wallKanan(16,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//
//	DisplayLCD("MASUK R2");
//	InOut = true;
//	lurusGaris();
//	pintu.push_back(MasukR2);
//	DisplayPintu();
//}

//void R1CkeR4() {
//	DisplayLCD("R1C>R4");
//
//	PutarSampaiArahIR(SELATAN); // menghadap selatan
//	QuickStop();
//	wait(0.1);
//
//	DisplayLCD("geserKiri"); // jauhin dari tembok sedikit
//	while(JarakKanan<10) {
//		GeserKiri(30);
//		wait(0.1);
//	}
//	QuickStop();

//	DisplayLCD("Cek Boneka");
//	if (avgJarakDepan() < 70) { // jika didepan ada boneka
//		// Boneka di lorong barat R4
//		DisplayLCD("depan boneka");
//		PosisiBoneka = BARAT;
//		MundurLurus(30);
//		wait(0.3);
//
//		// Wall kiri sampai timur
//		do {    // masuk ke lorong tengah untuk menghindari boneka
//			wallKiri2(15,25,10);
//			wait(0.1);
//			GetArah(150);
//		} while (ARAH != TIMUR || JarakKanan > 20);
////		PutarSampaiArah(TIMUR); // arahkan ke timur
////
////		MajuLurus(20);
////		wait(0.4);
////		QuickStop();
////		wait(0.1);
////		// Geser kanan utk wall kanan
////		do { // deketin ke kanan untuk siap siap wall kanan
////			GeserKanan(30);
////			wait(0.1);
////		} while (JarakKanan > 8);
//
//		// Wall kanan sampai masuk
//		DisplayLCD("wallsampai R4");
//		do {
//			wallKananSlow(16,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//	} else { // saat keluar R1C, tetapi didepan tidak ada boneka, maka jalan terus
//		DisplayLCD("AJG!Selatan");
//		// Cek R4B
//		do{
//			GeserKanan(30);
//			wait(0.1);
//		}while (JarakKanan > 9);
//
////		do {
////			wallKanan(16,25,10); // wall kanan selagi jarak kirinya masih jauh
////			wait(0.1); // dilakukan untuk mencari tembok sebelah kiri terdekat
////		} while (JarakKiri > 40);
//
//		for (int i=0; i<20; i++){
//			wallKanan(16,25,10);
//			wait(0.1);
//		}
//		MajuLurus(30); // maju lurus untuk memastikan sudah ada tembok kiri
//		wait(0.3);
//		QuickStop();
//
//		while(JarakKiri>9){ // rapatkan ke dinding kiri
//			GeserKiri(30);
//			wait(0.1);
//		}
//
//		QuickStop();
//
//		DisplayLCD("CariPintu"); // wall kiri sampai ruangan ketemu atau ada boneka di
////		do {					// bagian paling selatan
////			wallKiri2(15,25,10);
////			wait(0.1);
////		} while (!(GarisTengah == PUTIH || JarakDepan < 13));
//		do {					// bagian paling selatan
//			wallKiri2(15,25,10);
//			wait(0.1);
//			GetArah(150);
//		} while (ARAH!=TIMUR);
//		ResetArah();
//		PutarSampaiArahIR(TIMUR);
//		if(JarakSRKiri < 35){
//			DisplayLCD("Bukan R4B");
//			do{
//				GeserKanan(30);
//				wait(0.1);
//			}while(JarakKanan>14);
//			do{
//				MajuLurus(30);
//				wait(0.1);
//			}while(JarakBelakang<64);
//
//			if(avgJarakDepan()<70){
//				DisplayLCD("BONEKA");
//				PosisiBoneka = SELATAN;
//				// R4A
//				do { // mundur lurus, balik arah kemudian wal kanan sampai ketemu garis di R4A
//					MundurLurus(30);
//					wait(0.1);
//				} while (JarakDepan < 20);
//				PutarSampaiArah(BARAT);
//				do {
//					wallKananSlow(15,25,10);
//					wait(0.1);
//				} while (GarisTengah == HITAM);
//			}
//			else{
//				DisplayLCD("R4A");
//				do{
//					wallKiriSlow(15,25,10);
//					wait(0.1);
//				}while(GarisTengah == HITAM);
//
//			}
//		}
//		else{
//			DisplayLCD("R4B");
//			MajuLurus(20);
//			wait(0.2);
//			QuickStop();
//			do{
//				wallKiriSlow(15,25,10);
//				wait(0.1);
//			}while(GarisTengah == HITAM);
//		}
//	}
//	lurusGaris();
//	InOut = true;
//	Pemetaan();
//	DisplayPintu();
//	wait(0.1);
//}


void R1CkeR4() {
	DisplayLCD("R1C>R4");

	PutarSampaiArahIR(SELATAN); // menghadap selatan
	QuickStop();
	wait(0.1);

	for (int i=0; i<10; i++){
		wallKanan(16,25,10);
		wait(0.1);
	}
	ResetArah();
	PutarSampaiArahIR(SELATAN); // menghadap selatan
		QuickStop();
		wait(0.1);

		DisplayLCD("geserKiri"); // jauhin dari tembok sedikit
		while(JarakKanan<10) {
			GeserKiri(30);
			wait(0.1);
		}
		QuickStop();


	DisplayLCD("Cek Boneka");
	if (avgJarakDepan() < 50) { // jika didepan ada boneka
		// Boneka di lorong barat R4
		DisplayLCD("depan boneka");
		PosisiBoneka = BARAT;
		ResetArah();
		PutarSampaiArah(TIMUR);

		DisplayLCD("wallsampai R4");
		do {
			wallKanan(16,25,10);
			wait(0.1);
		} while (GarisTengah == HITAM);

	} else { // saat keluar R1C, tetapi didepan tidak ada boneka, maka jalan terus
		DisplayLCD("AJG!Selatan");
		// Cek R4B
		do{
			GeserKanan(30);
			wait(0.1);
		}while (JarakKanan > 9);

//		do {
//			wallKanan(16,25,10); // wall kanan selagi jarak kirinya masih jauh
//			wait(0.1); // dilakukan untuk mencari tembok sebelah kiri terdekat
//		} while (JarakKiri > 40);

		MajuLurus(30); // maju lurus untuk memastikan sudah ada tembok kiri
		wait(0.7);
		QuickStop();

		while(JarakKiri>9){ // rapatkan ke dinding kiri
			GeserKiri(30);
			wait(0.1);
		}

		QuickStop();

		DisplayLCD("CariPintu"); // wall kiri sampai ruangan ketemu atau ada boneka di
//		do {					// bagian paling selatan
//			wallKiri2(15,25,10);
//			wait(0.1);
//		} while (!(GarisTengah == PUTIH || JarakDepan < 13));
		do {					// bagian paling selatan
			wallKiri2(15,25,10);
			wait(0.1);
			GetArah(150);
		} while (ARAH!=TIMUR);
		ResetArah();
		PutarSampaiArahIR(TIMUR);
		if(JarakSRKiri < 35){
			DisplayLCD("Bukan R4B");
			do{
				GeserKanan(30);
				wait(0.1);
			}while(JarakKanan>14);
			do{
				MajuLurus(30);
				wait(0.1);
			}while(JarakBelakang<64);

			if(avgJarakDepan()<50){
				DisplayLCD("BONEKA");
				PosisiBoneka = SELATAN;
				// R4A
				do { // mundur lurus, balik arah kemudian wal kanan sampai ketemu garis di R4A
					MundurLurus(30);
					wait(0.1);
				} while (JarakDepan < 20);
				PutarSampaiArah(BARAT);
				do {
					wallKananSlow(15,25,10);
					wait(0.1);
				} while (GarisTengah == HITAM);
			}
			else{
				DisplayLCD("R4A");
				do{
					wallKiriSlow(15,25,10);
					wait(0.1);
				}while(GarisTengah == HITAM);

			}
		}
		else{
			DisplayLCD("R4B");
			MajuLurus(20);
			wait(0.2);
			QuickStop();
			do{
				wallKiriSlow(15,25,10);
				wait(0.1);
			}while(GarisTengah == HITAM);
		}
	}
	lurusGaris();
	InOut = true;
	Pemetaan();
	DisplayPintu();
	wait(0.1);
}

//void R1CkeR2(){
//	MajuLurus(30); // memastikan tidak kena garis
//	wait(1);
//
//	ResetArah();
//	DisplayLCD("CARI TIMUR");
//	PutarSampaiArah(TIMUR,AUTO,100);
//
//	DisplayLCD("CARI DINDING");
//	do {
//		MajuLurus(30); //mencari dinding untuk wall
//		wait(0.5);
//	}while (JarakKiri>30);
//
//	DisplayLCD("CARI UTARA");
//	do {
//		wallKiri(16,25,10);
//		wait(0.1);
//		GetArah(350);
//	}while (!(JarakKanan<20 && ARAH == UTARA));
//
//	DisplayLCD("DEKAT->KANAN");
//	while(JarakKanan>10){
//		GeserKanan(30);
//		wait(0.1);
//	}
//
//	DisplayLCD("CARI GARIS");
//	do {
//		wallKanan(16,25,10);
//		wait (0.1);
//	}while (GarisTengah == HITAM);
//
//
//	DisplayLCD("MASUK R2");
//	InOut = true;
//	lurusGaris();
//	pintu.push_back(MasukR2);
//	DisplayPintu();
//}

void R1CkeR2(){
	DisplayLCD("R1C ke R2");
	do{
		GeserKiri(30);
		wait(0.1);
	}while(JarakKanan<12);
	for(int i =0; i<5;i++){
		wallKiri(16,25,10);
		wait(0.1);
	}
	DisplayLCD("Wall Kiri");
	ResetArah();
		do {
			wallKiri2B(15,25,10);
			wait(0.1);
			GetArah(200);
		} while (ARAH != UTARA || JarakKanan > 24);

		if (ARAH == UTARA) {
			DisplayLCD("UTARA");
		} else {
			DisplayLCD("Kanan Dekat");
		}

		PutarSampaiArah(UTARA);
		PutarKanan(100);
		wait(0.3);
		QuickStop();
		wait(0.1);
		do {
			GeserKanan(40);
			wait(0.1);
		} while(JarakKanan > 8 && JarakSRKanan > 11);

		do {
			wallKanan(16,25,10);
			wait(0.1);
		} while (GarisTengah == HITAM);

	DisplayLCD("MASUK R2");
	InOut = true;
	lurusGaris();
	pintu.push_back(MasukR2);
	DisplayPintu();
}

void R2keR1 () {
	DisplayLCD("WKBlmSel");
	// Penanda apakah pernah selatan untuk memudahkan pemetaan pintu
	bool PernahSelatan = false;

	// Maju sampai tidak ketemu garis
	MajuLurus(30);
	wait(0.5);
	while(JarakKanan>12){
		GeserKanan(30);
		wait(0.1);
	}
	// Wall sampai selatan sedikit atau ketemu garis
	do {
		wallKanan(15,25,10);
		wait(0.1);
		GetArah(150);
	} while (ARAH != SELATAN && GarisTengah == HITAM);
	QuickStop();
	wait(0.1);

	// Kalau belum ketemu garis, berarti R1B, lanjut wall following
	if (ARAH == SELATAN ) {
		PernahSelatan = true;
		DisplayLCD("WKSdhSel");
		PutarSampaiArah(SELATAN,AUTO,100);
		do {
			wallKananSlow(15,25,10);
			wait(0.05);
		} while (GarisTengah == HITAM);
	}
	DisplayLCD("MskR1");

	// Masuk R1
	PutarSampaiArah(BARAT,AUTO);
	lurusGaris();
	// Pemetaan: kalau R2>R1 pernah selatan berarti R1B
	if (PernahSelatan) {
		pintu.push_back(MasukR1B);
	} else {
		pintu.push_back(MasukR1A);
	}
	DisplayPintu();
}

void R2keR3 () {
	DisplayLCD("R2>R3");

	while(JarakKanan<9){
		GeserKiri(30);
		wait(0.1);
	}
	QuickStop();
	wait(0.1);
	// Wall sampai ketemu garis
	for (int i = 0; i < 30; ++i) {
		wallKiri2(16,25,10);
		wait(0.1);
	}
	do {
		wallKiri2(15,25,10);
		wait(0.1);
	} while (GarisTengah == HITAM);

	// Masuk pintu
	InOut = true;
	lurusGaris();
	pintu.push_back(MasukR3);
	DisplayPintu();
}

void R2keR4 () {
	do {
		wallKiri2(14,25,10);
		wait(0.1);
		GetArah(250);
	} while (ARAH != TIMUR || JarakKanan > 25);

	// Putar ke barat
	PutarSampaiArah(BARAT,KANAN);

	LorongTimurkeR4();
}

void R3keR1 () {
	DisplayLCD("R3>R1");

	 //Wall kanan sampai arah barat
	do {
		wallKanan(16,25,10);
		wait(0.1);
		GetArah(250);
	} while (ARAH != BARAT);
	do {
		wallKanan(16,25,10);
		wait(0.1);
		GetArah(100);
	} while (GarisTengah==HITAM);
	QuickStop();
	wait(0.1);
	PutarBalik();
	for(int i=0;i <5;i++){
		wallKananSlow(15,25,10);
		wait(0.1);
	}
	R2keR1();
}

//void R3keR1 () {
//	DisplayLCD("R3>R1");
//
//	 //Wall kanan sampai arah barat
//	do {
//		wallKanan(16,25,10);
//		wait(0.1);
//		GetArah(250);
//	} while (ARAH != BARAT);
//	do {
//		wallKanan(16,25,10);
//		wait(0.1);
//		GetArah(100);
//	} while (ARAH != UTARA || JarakKanan>20);
//	QuickStop();
//	ResetArah();
//	PutarSampaiArah(UTARA);
//	do {
//		MajuLurus(30);
//		wait(0.1);
//	} while (JarakDepan > 8);
//	PutarSampaiArahIR(BARAT);
//
//	R2keR1();
//}

void R3keR2 () {
	DisplayLCD("R3>R2");
	ResetArah();
	PutarSampaiArah(UTARA);
	while(JarakKanan>12){
		GeserKanan(30);
		wait(0.1);
	}
	// Wall kanan sampai arah barat
	do {
		wallKanan(15,25,10);
		wait(0.1);
		GetArah(300);
	} while (ARAH != BARAT);

	// Wall kanan sampai ketemu garis
	do {
		wallKanan(16,25,10);
		wait(0.1);
	} while (GarisTengah == HITAM);

	// Masuk R2
	InOut = true;
	lurusGaris();
	pintu.push_back(MasukR2);
	DisplayPintu();
}

void R3keR4 () {
	DisplayLCD("R3>R4");
	// R3>R4 sama dengan LorongTimur>R4
	LorongTimurkeR4();
}

//void R4AkeR1 () {
//	DisplayLCD("R4A>R1");
//
//	R4AkeR2();
//	MajuLurus(30);
//	wait(0.5);
//
//	PutarBalik();
//	do {
//		MajuLurus(30);
//		wait(0.1);
//	}while (GarisTengah == HITAM);
//
//	MajuLurus(30);
//	wait(0.5);
//	R2keR1();
//}

void R4AkeR1 () {
	DisplayLCD("R4A>R1");

//	R4AkeR2();
//	R4AkeLorongUtara();
	while (JarakDepan > 11) {
			MajuLurus(30);
			wait(0.1);
		}

		// Belok ke lorong utara
		PutarSampaiArah(TIMUR);
		DisplayLCD("Wall Kiri");
		do {
			wallKiri2(15,25,10);
			wait(0.1);
//			GetArah(250);
		} while (GarisTengah == HITAM);

//		if (ARAH == UTARA) {
//			DisplayLCD("UTARA");
//		} else {
//			DisplayLCD("Kanan Dekat");
//		}
//
//		PutarSampaiArah(UTARA);
//		PutarKanan(100);
//		wait(0.3);
//		QuickStop();
//		wait(0.1);
//		do {
//			GeserKanan(40);
//			wait(0.1);
//		} while(JarakKanan > 8 && JarakSRKanan > 11);
//
//	do {
//		wallKanan(16,25,10);
//		wait(0.1);
//	} while (GarisTengah == HITAM);
//
//	// Masuk R2
//	lurusGaris();
//	pintu.push_back(MasukR2);
//	DisplayPintu();




//	MajuLurus(30);
//	wait(0.5);
//
//	PutarBalik();
//	do {
//		MajuLurus(30);
//		wait(0.1);
//	}while (GarisTengah == HITAM);

//	MajuLurus(30);
//	wait(0.5);
//	R2keR1();
}
void R4AkeR2 () {
	DisplayLCD("R4A>R2");

	R4AkeLorongUtara();
	do {
		wallKanan(16,25,10);
		wait(0.1);
	} while (GarisTengah == HITAM);

	// Masuk R2
	lurusGaris();
	pintu.push_back(MasukR2);
	DisplayPintu();
}

void R4AkeR3 () {
	R4AkeLorongUtara();
	PutarSampaiArah(SELATAN);
	R2keR3();
}

void R4BkeR1 () {
	R4BkeLorongTimur();
	PutarSampaiArah(BARAT);
	R3keR1();
}

void R4BkeR1C () {
	// Ke R1
	DisplayLCD("R4B ke R1C");
	PutarSampaiArahIR(BARAT);
	do {
		wallKiri(16,25,10);
		wait(0.1);
	} while (GarisTengah == HITAM);

	// Msk R1
	lurusGaris();
	pintu.push_back(MasukR1C);
	DisplayPintu();
}

void R4BkeR2() {
	if (PosisiBoneka == SELATAN) {
		// Wall ke lorong utara R4
		R4BkeLorongUtara();

		// Wall sampai ketemu garis
		do {
			wallKanan(16,25,10);
			wait(0.1);
		} while (GarisTengah == HITAM);
	} else {
		R4BkeLorongTimur();
		PutarSampaiArah(BARAT);
		R3keR2();
	}

	// Masuk R2
	lurusGaris();
	pintu.push_back(MasukR2);
	DisplayPintu();
}

void R4BkeR3 () {
	DisplayLCD("R4B>R3");

	if (PosisiBoneka != SELATAN) {
		R4BkeLorongTimur();
		do {
			wallKanan(17,25,10);
			wait(0.1);
		} while (GarisTengah == HITAM);
	} else {
		R4BkeLorongUtara();
		PutarSampaiArah(SELATAN);
		// Wall sampai ketemu garis
		do {
			wallKiri2(17,25,10);
			wait(0.1);
		} while (GarisTengah == HITAM);
	}

	lurusGaris();
	pintu.push_back(MasukR3);
	DisplayPintu();
}

void R1keLorongTimur () {
	if (pintu.back() == KeluarR1B) { // jika baru keluar dari pintu B
		DisplayLCD("KELUAR_BBB");
		do {
			MajuLurus(30); // maju lurus sampai serong kirinya dekat
			wait(0.1);
		} while (JarakSRKiri > 17 && JarakDepan>17);
		PutarSampaiArah(SELATAN,KANAN); // kemudian mengarahkan ke selatan
	} else { // pintu keluar R1A
		DisplayLCD("KELUAR_A");
		do{
			GeserKanan(30);
			wait(0.1);
		}while(JarakKiri<11);
		int sudutPutar = kompas.readBearing();
		PutarKanan(100);
		wait(0.2);

//		do {
//			wallKanan(16,25,10); // wall kanan sebelum mengarah ke selatan
//			wait(0.1);
//			GetArah(150);
//		} while(ARAH != SELATAN);
		do {
			wallKanan(16,25,10); // wall kanan sebelum mengarah ke selatan
			wait(0.1);
			GetArah(250);
		} while(!(ARAH == SELATAN && JarakKiri < 25));
//		do {
//			wallKanan(16,25,10); // wall kanan terus sampai bagian kirinya dekat,
//			wait(0.1);			 // atau kondisi robot tidak berada di depan R2
//		} while (JarakKiri > 20);
		MajuLurus(30);
		wait(0.4);
	}
	do {
		GeserKiri(30);
		wait (0.2);
	}while (JarakKiri>12);

	do {// jika sudah keluar dari R1B atau R1A, maka wall kiri sampai robot baru masuk
		wallKiri2(14,25,10); // ke lorong timur(menghadap timur dan jarak kanan< 25
		wait(0.1);
		GetArah(250);
	} while (!(ARAH == TIMUR && JarakKanan < 25));
}

//void LorongTimurkeR4 () {
//	// Wall kiri sampai selatan
//	while(JarakKanan<10){ // atur posisi sehingga tidak terlalu dekat dengan dinding kanan
//		GeserKiri(30);
//		wait(0.1);
//	}
//	do { // wall kiri sampai robot mengarah ke selatan
//		wallKiri2(14,25,10);
//		wait(0.1);
//		GetArah(250);
//	} while (ARAH != SELATAN);
//
//	// Wall kiri sampai barat
//	do {
//		wallKiriSlow(14,25,10);
//		wait(0.1);
//		GetArah(200);
//	} while (ARAH != BARAT);
//
//	// Koreksi arah
//	ResetArah();
//	PutarSampaiArahIR(BARAT,AUTO);
//
//	do { // atur posisi robot sehingga tidak terlalu dekat ke dinding kiri
//		GeserKanan(30);
//		wait(0.1);
//	} while (JarakKiri < 14);
//	KoreksiArahIR();
//	//PutarSampaiArahIR(BARAT,AUTO);
//
////	float totalDepan = avgJarakDepan();
////	LCD.locate(0,1);
////	LCD.printf("%2d",totalDepan); // menampilkan berapa jarak depan yang terbaca
////	QuickStop();
////	wait(0.5);
//
//	if (avgJarakDepan()> 70) { // jika depannya jauh atau bisa dibilang tidak ada boneka
//		DisplayLCD("Depan Jauhhh");
//
//		// Tidak ada boneka
//		// Mendekat tembok agar tdk osilasi
//		do {
//			GeserKiri(30);
//			wait(0.1);
//		} while (JarakKiri > 9);
//
//		// Wall kiri sampai jarak kanannya dekat, artinya ketemu bagian dari ruangan R4
//		do {
//			wallKiri(16,25,10);
//			wait(0.1);
//		} while (JarakKanan > 20);
//		MajuLurus(25);
//		wait(0.3);
//
//		//wall kiri selama jarak kanannya dekat, yang artinya ad dua kemungkinan
//		// sudah di depan ruang R4B atau di ujung barat lapangan
//		do {
//			wallKiri(16,25,10);
//			wait(0.1);
//		} while (JarakKanan < 40);
//
//		// Koreksi arah, baca depan sebelum mengecek jarak depan
//		PutarSampaiArahIR(BARAT);
//		QuickStop();
//		wait(0.1);
//
//		if (JarakDepan > 50) {
//			// Depan jauh: R4B
//			// Mundur sampai kanan dekat untuk wall kanan
//			do {
//				MundurLurus(30);
//				wait(0.1);
//			} while (JarakKanan > 30);
//			QuickStop();
//			wait(0.1);
//			MundurLurus(30);
//			wait(0.2);
//
//			// Geser kanan untuk wall kanan
//			do {
//				GeserKanan(30);
//				wait(0.1);
//			} while (JarakKanan > 8);
//			QuickStop();
//			wait(0.3);
//
//			// Wall kanan sampai masuk
//			do {
//				wallKanan(15,25,10);
//				//wallKanan2(15,25,10);
//				wait(0.1);
//			} while (GarisTengah == HITAM);
//		} else {
//			// Depan dekat: R4A
//			// Putar balik
//			PutarSampaiArah(TIMUR,AUTO);
//
//			// Wall kanan sampai kiri dekat
//			do {
//				wallKanan(16,25,10);
//				wait(0.1);
//			} while (JarakKiri > 20);
//			MajuLurus(25);
//			wait(0.5);
//			// Wall kiri sampai masuk ruangan
//			do {
//				wallKiri2(15,25,10);
//				wait(0.1);
//			} while (GarisTengah == HITAM);
//		}
//	} else { // boneka ada di selatan(pos.1)
//		DisplayLCD("Depan Dekat");
//		// Boneka di selatan
//		PosisiBoneka = SELATAN;
//
//		// Putar ke utara
//		PutarSampaiArahIR(UTARA);
//
//		// Wall kanan sampai kiri dekat
//		do {
//			wallKanan(16,25,10);
//			wait(0.1);
//		} while (JarakKiri > 20);
//
//		// Wall kiri sampai masuk
//		do {
//			wallKiri2(15,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//	}
//
//	// Masuk R4
//	lurusGaris();
//	InOut= TRUE;
//	Pemetaan();
//	DisplayPintu();
//}

void LorongTimurkeR4 () {
	// Wall kiri sampai selatan
	while(JarakKanan<10){ // atur posisi sehingga tidak terlalu dekat dengan dinding kanan
		GeserKiri(30);
		wait(0.1);
	}
	do { // wall kiri sampai robot mengarah ke selatan
		wallKiri2(14,25,10);
		wait(0.1);
		GetArah(250);
	} while (ARAH != SELATAN);

	// Wall kiri sampai barat
	do {
		wallKiriSlow(13,25,10);
		wait(0.1);
		GetArah(150);
	} while (!(JarakDepan < 15 &&JarakSRKiri < 17 && JarakKiri < 12)&& ARAH !=BARAT);
	DisplayLCD("sudahPOJOK");

	// Koreksi arah
	ResetArah();
	PutarSampaiArahIR(BARAT,AUTO);
	while (JarakBelakang>15){
		MundurLurus(30);
		wait(0.1);
	}
	ResetArah();
	PutarSampaiArahIR(BARAT,AUTO);

	int jlh= 0 , jumlahDepan = 0;


	do { // atur posisi robot sehingga tidak terlalu dekat ke dinding kiri
		GeserKanan(30);
		jumlahDepan += JarakDepan;
		jlh++;
		wait(0.2);
	} while (JarakKiri < 22);
	KoreksiArahIR();
	//PutarSampaiArahIR(BARAT,AUTO);

	LCD.printf("\n%d", jumlahDepan/jlh);
	QuickStop();
//	wait(3);

	if ((jumlahDepan/jlh)> 40) { // jika depannya jauh atau bisa dibilang tidak ada boneka
		DisplayLCD("Depan Jauhhh");

		// Tidak ada boneka
		// Mendekat tembok agar tdk osilasi
		do {
			GeserKiri(30);
			wait(0.1);
		} while (JarakKiri > 9);

		// Wall kiri sampai jarak kanannya dekat, artinya ketemu bagian dari ruangan R4
		do {
			wallKiri(16,25,10);
			wait(0.1);
		} while (JarakKanan > 20);
		MajuLurus(25);
		wait(0.3);

		//wall kiri selama jarak kanannya dekat, yang artinya ad dua kemungkinan
		// sudah di depan ruang R4B atau di ujung barat lapangan
		do {
			wallKiri(16,25,10);
			wait(0.1);
		} while (JarakKanan < 40);

		// Koreksi arah, baca depan sebelum mengecek jarak depan
		PutarSampaiArahIR(BARAT);
		QuickStop();
		wait(0.1);

		if (JarakDepan > 50) {
			// Depan jauh: R4B
			// Mundur sampai kanan dekat untuk wall kanan
			pintu.push_back(MasukR4B);

			do {
				MundurLurus(30);
				wait(0.1);
			} while (JarakKanan > 30);
			QuickStop();
			wait(0.1);
			MundurLurus(30);
			wait(0.2);

			// Geser kanan untuk wall kanan
			do {
				GeserKanan(30);
				wait(0.1);
			} while (JarakKanan > 8);
			QuickStop();
			wait(0.3);

			// Wall kanan sampai masuk
			do {
				wallKanan(15,25,10);
				//wallKanan2(15,25,10);
				wait(0.1);
			} while (GarisTengah == HITAM);
		} else {
			// Depan dekat: R4A
			// Putar balik
			pintu.push_back(MasukR4A);

			PutarSampaiArah(TIMUR,AUTO);

			// Wall kanan sampai kiri dekat
			do {
				wallKanan(16,25,10);
				wait(0.1);
			} while (JarakKiri > 20);
			MajuLurus(25);
			wait(0.5);
			// Wall kiri sampai masuk ruangan
			do {
				wallKiri2(15,25,10);
				wait(0.1);
			} while (GarisTengah == HITAM);
		}
	} else { // boneka ada di selatan(pos.1)
		DisplayLCD("Depan Dekat");
		// Boneka di selatan
		PosisiBoneka = SELATAN;
		bool PernahTimur = false;
		bool PernahGaris = false ;
		// Wall kanan sampai kiri dekat
		PutarSampaiArahIR(UTARA);
		do {
			wallKanan(16,25,10);
			wait(0.1);
		} while (JarakKiri > 20);
		MajuLurus(30);
		wait(0.2);

		DisplayLCD("SEBELUM TIMUR/4A");
		// Wall kiri sampai masuk
		do {
			wallKiri2(15,25,10);
			wait(0.1);
			GetArah(100);
			if (ARAH==TIMUR){
				PernahTimur = true;
				DisplayLCD("PERNAH TIMUR");
			}
//			if (GARIS == PUTIH) {
//				PernahGaris = true ;
//			}
		} while (ARAH != TIMUR && GarisTengah == HITAM);

//		if (PernahGaris || totalADC() > 280000) {

			if (PernahTimur){
				pintu.push_back(MasukR4B);
				DisplayLCD("SUDAH TIMUR/4B");
				do {
					wallKiri2(15,25,10);
					wait(0.1);
				} while (GarisTengah == HITAM);
				DisplayLCD("R4B");
				ResetArah();
				PutarSampaiArah(UTARA);
			}else {
				pintu.push_back(MasukR4A);
				DisplayLCD("R4A");
				ResetArah();
				PutarSampaiArah(SELATAN);
			}
//		}

	}
	// Masuk R4
	lurusGaris();
	InOut= TRUE;
	DisplayPintu();

}
void R4AkeLorongUtara () {
	// Maju ke tembok
	while (JarakDepan > 11) {
		MajuLurus(30);
		wait(0.1);
	}

	// Belok ke lorong utara
	PutarSampaiArah(TIMUR);
	DisplayLCD("Wall Kiri");
	do {
		wallKiri2B(15,25,10);
		wait(0.1);
		GetArah(250);
	} while (ARAH != UTARA || JarakKanan > 24);

	if (ARAH == UTARA) {
		DisplayLCD("UTARA");
	} else {
		DisplayLCD("Kanan Dekat");
	}

	PutarSampaiArah(UTARA);
	PutarKanan(100);
	wait(0.3);
	QuickStop();
	wait(0.1);
	do {
		GeserKanan(40);
		wait(0.1);
	} while(JarakKanan > 8 && JarakSRKanan > 11);
}

void R4BkeLorongUtara () {
	PutarSampaiArah(BARAT);
	do {
		wallKiri(16,25,10);
		wait(0.1);
		GetArah(150);
	} while (ARAH != UTARA || JarakKanan > 22);
	MajuLurus(30);
	wait(0.2);
	do {
		wallKanan(18,25,10);
		wait(0.1);
		GetArah(150);
	} while (ARAH != TIMUR || JarakKiri > 22);
//	for (int i = 0; i < 15; ++i) {
//		wallKanan(18,25,10);
//		wait(0.1);
//	}
	while (JarakKiri >= 8) {
		GeserKiri(30);
		wait(0.1);
	}
	do {
		wallKiri2B(15,25,10);
		wait(0.1);
		GetArah(250);
	} while (ARAH != UTARA || JarakKanan > 24);

	if (ARAH == UTARA) {
		DisplayLCD("UTARA");
	} else {
		DisplayLCD("Kanan Dekat");
	}

	PutarSampaiArah(UTARA);
	PutarKanan(100);
	wait(0.3);
	QuickStop();
	wait(0.1);
	do {
		GeserKanan(40);
		wait(0.1);
	} while (JarakKanan > 8 && JarakSRKanan > 11);
}

void R4BkeLorongTimur () {
	PutarSampaiArahIR(TIMUR);
	do {
		wallKanan(16,25,10);
		wait(0.1);
		GetArah(150);
	} while (ARAH != UTARA);
	do {
		wallKanan(16,25,10);
		wait(0.1);
		GetArah(250);
	} while (ARAH != TIMUR|| JarakKiri > 25);
	MajuLurus(30);
	wait(0.3);


}

bool CariApiR1A () {
	DisplayLCD("CariApiR1A");
	InOut = true;

	KoreksiArahIR();
	while (JarakKanan >= 9) {
		GeserKanan(30);
		wait(0.1);
	}
	QuickStop();
	wait(0.1);
	for(int i=1;i<=13;i++){
		wallKanan(16,25,10);
		wait(0.1);
	}

	QuickStop();
	wait(0.1);
	bool found = false;
		do{
			GeserKiri(30);
			wait(0.1);
			found = (UV2.Flag);
		}while(JarakKanan<25 && !found);
		if (!found){
			do {
				PutarKiri(120);
				wait(0.1);
				GetArah(150);
				found = (UV2.Flag);
	//			if (found) {
	//				QuickStop();
	//				wait(1);
	//				found &= (UV2.Flag);
	//			}
			} while (ARAH!=SELATAN && !found);
		}

	if (found) {
		Mode = PADAMKANAPI;
		DisplayLCD("ApiFound");
		ResetArah();
		PutarSampaiArahIR(BARAT);
		while (JarakKanan > 8 && JarakSRKanan > 11) {
			GeserKanan(30);
			wait(0.1);
		}
		return true;
	} else {
		PutarSampaiArah(TIMUR);
		do{
			GeserKiri(30);
			wait(0.1);
		}while(JarakKiri>11);
		wallTerdekat();
		InOut = false;
		pintu.push_back(KeluarR1A);
		return false;
	}
}



bool CariApiR1B () {
	DisplayLCD("CariApiR1B");
	InOut = true;

	PutarSampaiArah(BARAT,AUTO);
	MajuLurus(35);
	wait(0.8);
	QuickStop();

	PutarSampaiArah(BARAT,AUTO);
	do {
		GeserKiri(30);
		wait(0.1);
	} while (JarakKiri > 8 && JarakSRKiri > 11);

	PutarSampaiArah(BARAT,AUTO);
	MajuLurus(25);
	wait(0.5);

	PutarSampaiArah(BARAT,AUTO);
	do {
		GeserKiri(30);
		wait(0.1);
	} while (JarakKiri > 8);

	PutarSampaiArah(BARAT,AUTO);
//	PutarKiri(150);
//	wait(0.4);
	QuickStop();
	wait(0.1);

	DisplayLCD("ScaningApiR1B");
//	do {
//		PutarKanan(100);
//		wait(0.1);
//
//	} while (!UV2.Flag && kompas.readBearing()<(3600+THUtara-THBarat)/2);

//	PutarSampaiArah(UTARA;)

//	if (ApiSekitarTengah(70)){ //Api dekat, lakukan pemadaman
//		DisplayLCD("Api di depan");
//		Mode = PADAMKANAPI;
//		apiDekat = true;
//		return true;
//	} else { // Hadap barat laut tapi api blm ketemu
//		apiDekat = false;
//	}

	bool found = false;
//	do{
//		GeserKanan(30);
//		wait(0.1);
//	}while(!UV)
	ResetArah();
	sudut_putar = kompas.readBearing();

		do {

			PutarKanan(150);
			wait(0.1);
			GetArah(150);
			found = (UV2.Flag);
//			if (found) {
//				QuickStop();
//				wait(1);
//				found &= (UV2.Flag);
//			}
		} while (ARAH!=UTARA && !found);

	if (found) {

		Mode = PADAMKANAPI;
		DisplayLCD("ApiFound");

//		PutarSampaiArah(UTARA);
//		while (JarakKiri > 8 && JarakSRKiri > 11) {
//			GeserKiri(30);
//			wait(0.1);
//		}
		return true;
	} else {
		DisplayLCD("ApiNotFoundR1B");
		PutarSampaiArah(TIMUR,KANAN);
		wallTerdekat();
		pintu.push_back(KeluarR1B);
		InOut = false;
		return false;
	}
}

//bool CariApiR1C () {
//	DisplayLCD("CariApiR1C");
//	InOut = true;
//
//	KoreksiArahIR();
//	while (JarakKiri >= 8) {
//		GeserKiri(30);
//		wait(0.1);
//	}
//	for(int i = 0; i<8;i++){
//		wallKiri(16,25,10);
//		wait(0.1);
//	}
//	QuickStop();
//
//	do {
//		PutarKanan(150);
//		wait(0.1);
//		GetArah(200);
//	} while (ARAH != SELATAN && UV2.Flag == 0);
//	QuickStop();
//	wait(0.5);
//
//	if (UV2.Flag == 1) {
//		Mode = PADAMKANAPI;
//		DisplayLCD("ApiFound");
//		PutarSampaiArah(UTARA);
//		while (JarakKiri > 8 && JarakSRKiri > 11) {
//			GeserKiri(30);
//			wait(0.1);
//		}
//		return true;
//	} else {
//		// Keluar R1 ke pintu A/B
//		PutarSampaiArahIR(UTARA);
//		do {
//			wallKiriSlow(15,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);
//
//		InOut = false;
//		return false;
//	}
//}

bool CariApiR1C () {
	DisplayLCD("CariApiR1C");
	InOut = true;

	KoreksiArahIR();
	while (JarakKiri >= 8) {
		GeserKiri(30);
		wait(0.1);
	}
	for(int i = 0; i<8;i++){
		wallKiri(16,25,10);
		wait(0.1);
	}
	QuickStop();

	do {
		PutarKanan(150);
		wait(0.1);
		GetArah(200);
	} while (ARAH != SELATAN && UV2.Flag == 0);
	QuickStop();
	wait(0.5);

	if (UV2.Flag == 1) {
		Mode = PADAMKANAPI;
		DisplayLCD("ApiFound");
		PutarSampaiArah(UTARA);
		while (JarakKiri > 8 && JarakSRKiri > 11) {
			GeserKiri(30);
			wait(0.1);
		}
		return true;
	} else {
		// Keluar R1 ke pintu A/B
		PutarSampaiArahIR(SELATAN);
		DisplayLCD("ApiNOTFound");
		QuickStop();
		wait(0.1);
		do {
			wallKanan(15,25,10);
			wait(0.05);
		} while (GarisTengah == HITAM);

		InOut = false;
		return false;
	}
}

bool CariApiR2 () {
	DisplayLCD("CariApiR2");
	InOut = true;

	ResetArah();
	PutarSampaiArah(TIMUR,AUTO);
	while (JarakKiri > 8 && JarakSRKiri > 11) {
		GeserKiri(30);
		wait(0.1);
	}
	MajuLurus(40);
	wait(0.5);
	ResetArah();
	PutarSampaiArah(TIMUR,AUTO);
	do {
		wallKiri2(14,25,10);
		wait(0.1);
		GetArah(150);
	} while (JarakDepan > 35 || ARAH != TIMUR);
	QuickStop();
	wait(0.1);

//	ResetArah();
//	PutarSampaiArah(TIMUR);
//	do {
//		GeserKanan(30);
//		wait(0.1);
//	}while (JarakKiri <35);

	// Cek sampai tenggara
	// Sampai tenggara agar api yang terleteak dekat R1 tidak ikut terbaca dari pintu R2
	DisplayLCD("ScaningApi");
	bool found = false;
	do {
		PutarKanan(150);
		wait(0.1);
		GetArah(150);
		found = (UV2.Flag);
//		if (found) {
//			QuickStop();
//			wait(1);
//			found &= (UV2.Flag);
//		}
	} while (((kompas.readBearing() + errorSudut )%3600) < (THSelatan) && !found);
	QuickStop();
	wait(0.1);
	ResetArah();

	if (found) {
		Mode = PADAMKANAPI;
		DisplayLCD("ApiFound");
		PutarSampaiArahIR(TIMUR);
		while (JarakKiri > 8 && JarakSRKiri > 11) {
			GeserKiri(30);
			wait(0.1);
		}
		return true;
	} else {
		DisplayLCD("ApiNotFound");

		PutarSampaiArahIR(BARAT,KANAN);
		wallTerdekat();
		do {
			wallKananSlow(14,25,10);
			wait(0.1);
		} while (GarisBelakangKanan == HITAM && GarisBelakangKiri == HITAM);
		do {
			wallKanan(18,25,10);
			wait(0.1);
		} while (GarisBelakangKanan != HITAM || GarisBelakangKiri != HITAM);

		InOut = false;
		return false;
	}
}

bool CariApiR3 () {
	DisplayLCD("CariApiR3");
	InOut = true;
	pintu.push_back(MasukR3);
	ResetArah();
	PutarSampaiArahIR(SELATAN);
	while (JarakKiri>8){
		GeserKiri(30);
		wait(0.1);
	}
	QuickStop();

	for (int i = 0; i<=8; i++){
		wallKiriSlow(14,25,10);
		wait(0.1);
	}

	QuickStop();
	PutarSampaiArahIR(SELATAN);

	DisplayLCD("ScaningApiR3");
	bool found = false;
		do {
			PutarKanan(150);
			wait(0.1);
			//GetArah(150);
			found = (UV2.Flag);
//			if (found) {
//				QuickStop();
//				DisplayLCD("Ketemu sekali");
//				wait(1);
//				found &= (UV2.Flag);
//			}
		} while (((kompas.readBearing() + errorSudut )%3600)< (THBarat+THSelatan)/2 && !found);
		QuickStop();
		wait(0.1);
//	do {
//		PutarKanan(150);
//		wait(0.1);
//		GetArah(150);
//	} while (kompas.readBearing() < (THBarat+THSelatan)/2 && UV2.Flag == 0);
//	QuickStop();
//	wait(0.1);
	if (found) {
		Mode = PADAMKANAPI;
		DisplayLCD("ApiFound");

		PutarSampaiArah(SELATAN);
		while (JarakKiri > 8 && JarakSRKiri > 11) {
			GeserKiri(30);
			wait(0.1);
		}
		return true;
	} else {
		DisplayLCD("ApiNotFoundR3");

		//ResetArah();
		PutarSampaiArah(UTARA);
//		wallTerdekat();
//		do {
//			wallKanan(18,25,10);
//			wait(0.1);
//		} while (GarisTengah == HITAM);

		// Keluar sampai bawah tidak deteksi garis
		DisplayLCD("Jalan Sampai LUAR");
		while(JarakKanan>12){
			GeserKanan(30);
			wait(0.1);
		}
		do{
			wallKananSlow(14,25,10);
			wait(0.05);
		}while(GarisTengah==HITAM);
		QuickStop();
		wait(0.1);
		InOut = false;
		return false;
	}
}

bool CariApiR4A () {
	DisplayLCD("CariApiR4A");
	InOut = true;

	ResetArah();
	PutarSampaiArah(SELATAN,AUTO);
	QuickStop();
	wait(0.1);
	MajuLurus(30);
	wait(0.3);
	int jarak_depan_awal = JarakDepan;
	int jarak_belakang_awal = JarakBelakang;
	wait(0.1);
	do {
//		wallKiri(14,25,10);
		MajuLurus(20);
		wait(0.1);
	} while (jarak_depan_awal - JarakDepan < 11);
	ResetArah();
	PutarSampaiArah(SELATAN,AUTO,50);
	QuickStop();
	wait(0.1);

	DisplayLCD("ScaningApi");
	bool found = false;
	do {
		PutarKanan(150);
		wait(0.1);
		GetArah(150);
		found = (UV2.Flag);
		if (found) {
			QuickStop();
			wait(1);
			found &= (UV2.Flag);
		}
	} while (ARAH != BARAT && !found);

	if (found) {
		Mode = PADAMKANAPI;
		DisplayLCD("ApiFound");
		return true;
	} else {
		DisplayLCD("ApiNotFound");

		PutarSampaiArah(UTARA,KANAN);
		wallTerdekat();
		do {
			wallKanan(18,25,10);
			wait(0.1);
		} while (GarisBelakangKanan == HITAM && GarisBelakangKiri == HITAM);
		do {
			wallKanan(18,25,10);
			wait(0.1);
		} while (GarisBelakangKanan != HITAM || GarisBelakangKiri != HITAM);

		InOut = false;
		return false;
	}
}

bool CariApiR4B () {

		DisplayLCD("CariApiR4B");
		InOut = true;

		ResetArah();
		PutarSampaiArah(UTARA,AUTO);
//		MajuLurus(20);
//		wait(0.5);
		QuickStop();
		wait(0.1);
		MajuLurus(20);
		wait(0.5);
		while(JarakKiri>9 && JarakSRKiri > 12){
			GeserKiri(30);
			wait(0.1);
		}

		QuickStop();
		wait(0.1);
		int jarak_depan_awal = JarakDepan;
		int jarak_belakang_awal = JarakBelakang;
		wait(0.1);
		do {
	//		wallKiri(14,25,10);
			MajuLurus(20);
			wait(0.1);
		} while (jarak_depan_awal - JarakDepan > 9);
		//ResetArah();
		//PutarSampaiArah(UTARA,AUTO,50);
		QuickStop();
		wait(0.1);

	wait(0.1);
	DisplayLCD("ScaningApi");
	do {
		PutarKanan(150);
		wait(0.1);
		GetArah(150);
	} while (ARAH != TIMUR && UV2.Flag == 0);

	if (UV2.Flag == 1) {
		Mode = PADAMKANAPI;
		ResetArah();
		PutarSampaiArah(UTARA);
		DisplayLCD("ApiFound");
		return true;
	} else {
		DisplayLCD("ApiNotFound");

		PutarSampaiArah(SELATAN,KANAN);
		wallTerdekat();
		do {
			wallKanan(18,25,10);
			wait(0.1);
		} while (GarisBelakangKanan == HITAM && GarisBelakangKiri == HITAM);
		do {
			wallKanan(18,25,10);
			wait(0.1);
		} while (GarisBelakangKanan != HITAM || GarisBelakangKiri != HITAM);
		QuickStop();
		wait(0.5);

		InOut = false;
		return false;
	}
}
