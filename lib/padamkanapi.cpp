// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : padamkanapi.cpp
// author/editor : Babang
// created on : 28 Maret 2016
// Desc : Algoritma inti, prosedur pemadaman api di setiap ruangan

#include "padamkanapi.h"
#include <ctime>

//void GetArah(int THRESHOLD){ //x adalah total garis dilalui //masih perlu cari konstanta jauh, dekat yang tepat
//    int sudut =kompas.readBearing();
////    int barat =2700;
////    int utara =1800;
////    int selatan=0;
////    int timur=900;
////    int toleransi =150;
//    if (sudut < THTimur + THRESHOLD && sudut > THTimur - THRESHOLD) //menghadap timur
//    {
//        ARAH=TIMUR;
//    }
//    else if (sudut < THBarat + THRESHOLD && sudut > THBarat - THRESHOLD)//menghadap barat
//    {
//        ARAH=BARAT;
//    }
//    else if (sudut < THUtara + THRESHOLD && sudut > THUtara - THRESHOLD)//menghadap utara
//    {
//    	ARAH=UTARA;
//    }
//    else if (sudut < THSelatan + THRESHOLD  || sudut > 3600 + THSelatan -THRESHOLD)//menghadap selatan
//    {
//    	ARAH=SELATAN;
//    }
//}
void GetArahMax(){
	ResetArah();
	int batasUT, batasTS, batasSB, batasBU;
	int sudut = (kompas.readBearing() + errorSudut )%3600; //300
	int perantaraUtaraBarat = THUtara; //3100
	int perantaraUtaraTimur = THUtara; //3100
	if(sudut>3599){
		sudut=sudut-3599;
	}
	else if(sudut<0){
		sudut+=3599;
	}
	if(THUtara <2000){//Jebol ke 0
		perantaraUtaraBarat = THUtara+3600;
	}
	else {
		perantaraUtaraTimur = 3600 - THUtara; // 500
	}
	batasUT = (perantaraUtaraTimur+THTimur)/2;  //450
	batasTS = (THTimur+THSelatan)/2;
	batasSB = (THSelatan+THBarat)/2;
	batasBU = (perantaraUtaraBarat+THBarat)/2;

	if(sudut > batasUT && sudut <= batasTS)
	{
		ARAH = TIMUR;
	}
	else if (sudut >batasTS && sudut <= batasSB)
	{
		ARAH = SELATAN;
	}
	else if (sudut > batasSB && sudut <= batasBU)
	{
		ARAH = BARAT;
	}
	else
	{
		ARAH = UTARA;
	}
}

void GetArah(int THRESHOLD){ //x adalah total garis dilalui //masih perlu cari konstanta jauh, dekat yang tepat
    int toleransi=0;
	int sudut =(kompas.readBearing() + errorSudut )%3600+toleransi;
	if(sudut>3599){
		sudut=sudut-3599;
	}
	else if(sudut<0){
		sudut+=3599;
	}
//    int barat =2700;
//    int utara =1800;
//    int selatan=0;
//    int timur=900;
//    int toleransi =150;
    if (sudut < THTimur + THRESHOLD && sudut > THTimur - THRESHOLD) //menghadap timur//400
    {
        ARAH=TIMUR;
    }
    else if (sudut < THBarat + THRESHOLD && sudut > THBarat - THRESHOLD)//menghadap barat
    {
        ARAH=BARAT;
    }
    else if (sudut < THSelatan + THRESHOLD  && sudut > THSelatan - THRESHOLD)//menghadap selatan
	{
		ARAH=SELATAN;
//	}
//    else if (sudut < (THUtara + THRESHOLD) % 3600 || sudut > (THUtara - THRESHOLD + 3600) % 3600)//menghadap utara
//    {
//    		ARAH=UTARA;
    } else {
    	int th = (THUtara > 1800) ? (THUtara - 3600) : THUtara;//-500
    	int s = (sudut > 1800) ? (sudut - 3600) : sudut;//-420

    	if (s < (th + THRESHOLD) && (s > (th - THRESHOLD))) {
    		ARAH = UTARA;
    	}
    }
    ARAHTIANG = ARAH;

}



//int NilaiApiTengah() {
//	int temp_total = 0, n = 0;
//	for (int i = 1; i <= 2; ++i) {
//		temp_total += tpa_4.getTemp(i+1);
//		n++;
//	}
//	for (int i = 1; i <= 8; ++i) {
//		temp_total += tpa_2.getTemp(i+1);
//		n++;
//	}
//	for (int i = 1; i <= 2; ++i) {
//		temp_total += tpa_6.getTemp(i+1);
//		n++;
//	}
//	return temp_total / n;
//}

int NilaiApiTengah() {
	int temp_total = 0, n = 0;
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_0.getTemp(i+1);
		n++;
	}
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_6.getTemp(i+1);
		n++;
	}
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_2.getTemp(i+1);
		n++;
	}
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_4.getTemp(i+1);
		n++;
	}
	return temp_total / n;
}

int NilaiApiTengahKiriAtas() {
	int temp_total = 0, n = 0;
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_0.getTemp(i);
		n++;
	}
	return temp_total / n;
}

int NilaiApiTengahKiriBawah() {
	int temp_total = 0, n = 0;
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_4.getTemp(i);
		n++;
	}
	return temp_total / n;
}

int NilaiApiTengahKiri() {
	int t_atas = NilaiApiTengahKiriAtas();
	int t_bawah = NilaiApiTengahKiriBawah();
	return (t_atas > t_bawah) ? t_atas : t_bawah;
}

int NilaiApiTengahKananAtas() {
	int temp_total = 0, n = 0;
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_6.getTemp(i+1);
		n++;
	}
	return temp_total / n;
}

int NilaiApiTengahKananBawah() {
	int temp_total = 0, n = 0;
	for (int i = 6; i <= 8; ++i) {
		temp_total += tpa_2.getTemp(i+1);
		n++;
	}
	return temp_total / n;
}

int NilaiApiTengahKanan() {
	int t_atas = NilaiApiTengahKananAtas();
	int t_bawah = NilaiApiTengahKananBawah();
	return (t_atas > t_bawah) ? t_atas : t_bawah;
}

//int NilaiApiKiri() {
//	int temp_total = 0, n = 0;
//	for (int i = 1; i <= 5; ++i) {
//		temp_total += tpa_0.getTemp(i+1);
//		n++;
//	}
//	return temp_total / n;
//}
//
//int NilaiApiKanan() {
//	int temp_total = 0, n = 0;
//	for (int i = 1; i <= 5; ++i) {
//		temp_total += tpa_6.getTemp(i+1);
//		n++;
//	}
////	for (int i = 1; i <= 5; ++i) {
////		temp_total += tpa_2.getTemp(i+1);
////		n++;
////	}
//	return temp_total / n;
//}

int MaxApiKiri() {
	int max = tpa_0.getTemp(2);
	for(int i = 2; i <= 5;i++){
		if(tpa_0.getTemp(i+1)>max){
			max = tpa_0.getTemp(i+1);
		}
	}
	for(int i = 1; i <= 5;i++){
		if(tpa_4.getTemp(i+1)>max){
			max = tpa_4.getTemp(i+1);
		}
	}
	return max;
}
int MaxApiKanan() {
	int max = tpa_6.getTemp(2);
	for (int i = 2; i <= 5; i++){
		if (tpa_6.getTemp(i+1) > max){
			max = tpa_6.getTemp(i+1);
		}
	}
	for (int i = 2; i <= 5; i++){
		if (tpa_2.getTemp(i+1) > max){
			max = tpa_2.getTemp(i+1);
		}
	}
	return max;
}

int MaxApiTengah() {
	int max = tpa_0.getTemp(7);
	for(int i = 7; i <= 8;i++){
		if (tpa_0.getTemp(i+1) > max){
			max = tpa_0.getTemp(i+1);
		}
	}
	for (int i = 6; i <= 8; i++){
		if (tpa_2.getTemp(i+1) > max){
			max = tpa_2.getTemp(i+1);
		}
	}
	for (int i = 6; i <= 8; i++){
		if (tpa_4.getTemp(i+1) > max){
			max = tpa_4.getTemp(i+1);
		}
	}
	for (int i = 6; i <= 8; i++){
		if (tpa_6.getTemp(i+1) > max){
			max = tpa_6.getTemp(i+1);
		}
	}
	return max;
}
//bool ApiSekitar(int temp_th) {
//	bool ada_api = false;
//	for (int i = 1; i <= 8 && !ada_api; ++i)
//		ada_api |= (tpa_4.getTemp(i+1) > temp_th);
//	for (int i = 1; i <= 8 && !ada_api; ++i)
//		ada_api |= (tpa_6.getTemp(i+1) > temp_th);
//	return ada_api;
//}

bool ApiUjungKanan(int temp_th) {
	bool ada_api =false;
	for (int i = 1; i <= 8 && !ada_api; ++i)
	ada_api |= (tpa_8.getTemp(i+1) > temp_th);
	return ada_api;
}

bool ApiUjungKiri(int temp_th) { // mengecek apakah tpa kiri sudah ada yang lebih dari temp_th
	bool ada_api=false;
	for (int i = 1; i <= 8 && !ada_api; ++i)
	ada_api |= (tpa_A.getTemp(i+1) > temp_th);
	return ada_api;
}
bool ApiUjung(int temp_th){ // memberikan nilai apakah tpa ujung mendeteksi api dan apakah
	PernahUjungKiri = false; // di kiri atau di kanan
	PernahUjungKanan = false;
	bool yes=false;
	yes = ApiUjungKanan(temp_th)||ApiUjungKiri(temp_th);
	if(ApiUjungKanan(temp_th)){
		PernahUjungKanan = true;
	}
	else if(ApiUjungKiri(temp_th)){
		PernahUjungKiri = true;
	}
	return yes;
}
void ArahkanKeApi(int temp_th){ // mengarahkan api di tengah dengan melihat posisi awal api
	if (PernahUjungKanan){ 		// apakah di kiri atau kanan
		DisplayLCD("Kanan");
		while(!ApiSekitarTengah(temp_th-10)){
			PutarKanan(50);
			wait(0.1);
		}
		PernahUjungKanan = false;
	}
	else if(PernahUjungKiri){
		DisplayLCD("Kiri");
		while(!ApiSekitarTengah(temp_th-10)){
			PutarKiri(50);
			wait(0.1);
		}
		PernahUjungKiri=false;
	}
}

bool ApiSekitar(int temp_th) {
	bool ada_api = false;
	for (int i = 1; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_0.getTemp(i+1) > temp_th);
	for (int i = 1; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_2.getTemp(i+1) > temp_th);
	for (int i = 1; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_4.getTemp(i+1) > temp_th);
	for (int i = 1; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_6.getTemp(i+1) > temp_th);
	return ada_api;
}


bool ApiSekitarTengah(int temp_th) {
	//memeriksa api di daerah tpa 6 & 4 (tengah) apakah nilainya pernah melebihi temp_th
	bool ada_api = false;
	for (int i = 6; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_0.getTemp(i+1) > temp_th);
	for (int i = 6; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_2.getTemp(i+1) > temp_th);
	for (int i = 6; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_4.getTemp(i+1) > temp_th);
	for (int i = 6; i <= 8 && !ada_api; ++i)
		ada_api |= (tpa_6.getTemp(i+1) > temp_th);
	return ada_api;
}

//bool ApiSekitarTengah(int temp_th) {
//	//memeriksa api di daerah tpa 6 & 4 (tengah)
//	//Perubahan: api di tengah merupakan indeks 1 & 2 TPA 6 & TPA 4
//	bool ada_api = false;
//	for (int i = 1; i <= 2 && !ada_api; ++i)
//		ada_api |= (tpa_6.getTemp(i+1) > temp_th);
//	for (int i = 1; i <= 2 && !ada_api; ++i)
//		ada_api |= (tpa_4.getTemp(i+1) > temp_th);
//
////	for (int i = 1; i <= 8 && !ada_api; ++i)
////		ada_api |= (tpa_2.getTemp(i+1) > temp_th);
//	return ada_api;
//}

//void DekatiApi(int temp_th)
//{
//	bool arah;
//	if(JarakKanan<JarakKiri)
//	{
//		arah = 0;//kanan
//	}else {
//		arah = 1;//kiri
//	}
//}

//void putarkeApi(int temp_th) {
	// Kanan positif, kiri negatif
	// Kanan true, kiri false
//	int count = 0;	// Count sudah ke kiri/kanan brp kali
//	bool arah_gerak, arah_wall;
//	int batas_kanan, batas_kiri;

	//pilih arah_gerak
//	arah_wall = (JarakKanan < JarakKiri);
//	arah_gerak = arah_wall;
//	if (arah_wall){	// Kanan
//		batas_kanan = 8;
//		batas_kiri = -1;
//	} else {	// Kiri
//		batas_kanan = 1;
//		batas_kiri = -8;
//	}
//
//	do {
//		//di ujung kiri/kanan
//		if((count == batas_kanan) || (count == batas_kiri)) {
//			arah_gerak = !arah_gerak;
//			// Geser batas
//			if (count == batas_kanan && arah_wall) {	// Wall kanan, ujung kanan
//				batas_kanan++;
//			} else if (count == batas_kiri && arah_wall) {	// Wall kanan, ujung kiri
//				PutarKanan(50);
//				wait(0.2);
//				count++;
//				batas_kiri++;
//			} else if (count == batas_kanan && !arah_wall) {	// Wall kiri, ujung kanan
//				PutarKiri(50);
//				wait(0.2);
//				count--;
//				batas_kanan--;
//			} else {	// Wall kiri, ujung kiri
//				batas_kiri--;
//			}
//		}
//
//		//setiap selesai kiri +kanan , maju wallKanan
//		if (ApiSekitarTengah(70)){
//			if (arah_wall){
//				DisplayLCD("Wall Kanan");
//				wallKananApi(11,25,10);
//			} else {
//				DisplayLCD("Wall Kiri");
//				MajuLurus(25);
//				//wallKiriApi(11,25,10);
//			}
//			wait(0.4);
//			count = 0;
//			arah_gerak = arah_wall;
//		}
//		QuickStop();
//		wait(0.2);
//
//		//putar kiri/kanan
//		if (arah_gerak){
//			PutarKanan(50);
//			count++;
//		} else {
//			PutarKiri(50);
//			count--;
//		}
//		wait(0.2);
//	} while (!ApiSekitarTengah(temp_th));
//}

//void putarkeApi(int temp_th)
//{
//	int cnt=0;
//	bool arah;
//	//pilih arah
//	if(JarakKanan<JarakKiri){
//		arah = 0;//kanan
//	}else {
//		arah = 1;//kiri
//	}
//	int cntkk=0;
//	do{
//		//di ujung kiri/kanan
//		if((cnt==8)||(cnt==(-1))){
//			arah = !arah;
//			cntkk++;
//		}
//		//setiap selesai kiri +kanan , maju wallKanan
//		if((cntkk%2==0)&&(cntkk!=0)){
//			wallKananApi(13,25,10);
//			wait(0.5);
//			cntkk=0;
//		}
//		QuickStop();
//		wait(0.2);
//		//putar kiri/kanan
//		if(!arah){
//			PutarKanan(50);
//			wait(0.1);
//			cnt++;
//		}else{
//			PutarKiri(50);
//			wait(0.1);
//			cnt--;
//		}
//		wait(0.1);
//	}while(!ApiSekitarTengah(temp_th));
//}
//
//void putarKeApi(int temp_th) {
//	int count = 0;
//	int count_kiri_kanan = 0;
//	int batas_kanan, batas_kiri;
//	bool arah_gerak, arah_wall;
//
//	//pilih arah_gerak
//	arah_wall = JarakKanan < JarakKiri;
//	arah_gerak = arah_wall;
//	if (arah_wall){	// Kanan
//		batas_kanan = 8;
//		batas_kiri = -1;
//	} else {	// Kiri
//		batas_kanan = 1;
//		batas_kiri = -8;
//	}
//
//	do {
//		//di ujung kiri/kanan
//		if((count == batas_kanan) || (count == batas_kiri)) {
//			arah_gerak = !arah_gerak;
//			// Geser batas
//			if (count == batas_kanan && arah_wall) {	// Wall kanan, ujung kanan
//				batas_kanan++;
//			} else if (count == batas_kiri && arah_wall) {	// Wall kanan, ujung kiri
//				PutarKanan(50);
//				wait(0.2);
//				count++;
//				batas_kiri++;
//			} else if (count == batas_kanan && !arah_wall) {	// Wall kiri, ujung kanan
//				PutarKiri(50);
//				wait(0.2);
//				count--;
//				batas_kanan--;
//			} else {	// Wall kiri, ujung kiri
//				batas_kiri--;
//			}
//		}
//		if (ApiSekitarTengah(temp_th - 20)) {
//			count_kiri_kanan += 2;
//		}
//		//setiap selesai kiri +kanan , maju wallKanan
//		if ((count_kiri_kanan % 2 == 0) && (count_kiri_kanan != 0)){
//			MajuLurus(20);
//			wait(0.4);
//			count_kiri_kanan = 1;
//			count = 0;
//			arah_gerak = arah_wall;
//		}
//		QuickStop();
//		wait(0.2);
//		if(count_kiri_kanan == 0){
//			//putar kiri/kanan
//			if (arah_gerak){
//				count++;
//				PutarKanan(50);
//			} else {
//				count--;
//				PutarKiri(50);
//			}
//			wait(0.2);
//		}
//	} while(count_kiri_kanan != 1);
//
//	DisplayLCD("Maju ke api");
//	do {
//		int t_tengah = NilaiApiTengah();
//		int t_kiri = NilaiApiKiri();
//		int t_kanan = NilaiApiKanan();
//
//		if (t_tengah > t_kiri && t_tengah > t_kanan) {
//			MajuLurus(15);
//			wait(0.2);
//		} else if (t_kiri > t_tengah && t_kiri > t_kanan) {
//			PutarKiri(30);
//		} else {
//			PutarKanan(30);
//		}
//		wait(0.1);
//	} while(!ApiSekitarTengah(temp_th));
//}

//void putarKeApi(int temp_th) {
//	if (MaxApiKanan() > MaxApiKiri()) {
//		PutarKanan(70);
//		wait(0.3);
//		QuickStop();
//		wait(0.1);
//	} else if (MaxApiKiri() > MaxApiKanan()) {
//		PutarKiri(70);
//		wait(0.3);
//		QuickStop();
//		wait(0.1);
//	}
//
//	// Pilih arah
//	int batas_kanan, batas_kiri;
//	bool arah = (JarakKanan > JarakKiri);
//	bool arah_wall = arah;
//	if (arah) {	// Kanan
//		batas_kanan = 8;
//		batas_kiri = -1;
//	} else {	// Kiri
//		batas_kanan = 1;
//		batas_kiri = -8;
//	}
//
//	bool furniture = false;
//	do {
//		int count = 0;
//		int count_kiri_kanan = 0;
//		do {
//			// Detect furniture
//			clock_t start = clock();
//			HindarFurniture();
//			clock_t end = clock();
//			furniture = ((end - start) * CLOCKS_PER_SEC > 1);
//			if (furniture) {
//				if (JarakKiri < JarakKanan) {
//					do {
//						wallKiriApi(11,25,10);
//						wait(0.1);
//					} while (!ApiSekitar(0.8 * temp_th));
//				} else {
//					do {
//						wallKananApi(11,25,10);
//						wait(0.1);
//					} while (!ApiSekitar(0.8 * temp_th));
//				}
//			}
//
//			// Di ujung kiri/kanan
//			if ((count == batas_kanan) || (count == batas_kiri)) {
//				arah = !arah;
//				// count_kiri_kanan++;
//			}
//			if (ApiSekitarTengah(temp_th * 0.5)) {
//				count_kiri_kanan += 2;
//			}
//			//setiap selesai kiri+kanan , maju
//			if ((count_kiri_kanan % 2 == 0) && (count_kiri_kanan != 0)) {
////				MajuLurus(30);
////				wait(0.5);
//				count_kiri_kanan = 1;
//	//			count = 0;
//	//			arah = 0;
//			}
//			QuickStop();
//			wait(0.2);
//			if (JarakKiri<8){
//				GeserKanan(30);
//				wait(0.2);
//				QuickStop();
//				PutarKiri(50);
//				wait(0.2);
//				QuickStop();
//			}
//			if (JarakKanan < 8){
//				GeserKiri(30);
//				wait(0.2);
//				QuickStop();
//				PutarKanan(50);
//				wait(0.2);
//				QuickStop();
//			}
//			if (count_kiri_kanan == 0) {
//				//putar kiri/kanan
//				if (arah) {
//					PutarKanan(50);
//					wait(0.1);
//					count++;
//				} else {
//					PutarKiri(50);
//					wait(0.1);
//					count--;
//				}
//				wait(0.1);
//			}
//		} while (count_kiri_kanan != 1);
//
//		do {
//			// Detect furniture
////			clock_t start = clock();
////			HindarFurniture();
////			clock_t end = clock();
////			furniture = ((end - start) * CLOCKS_PER_SEC > 1);
////			if (furniture || JarakDepan < 10) {
////				if (arah_wall) {
////					do {
////						wallKiriApi(11,25,10);
////						wait(0.1);
////					} while (!ApiSekitar(0.8 * temp_th));
////				} else {
////					do {
////						wallKananApi(11,25,10);
////						wait(0.1);
////					} while (!ApiSekitar(0.8 * temp_th));
////				}
////			}
//
//			if (JarakDepan < 10) {
//				if (arah_wall) {
//					do {
//							wallKiriApi(11,25,10);
//							wait(0.1);
//						} while (!ApiSekitar(0.8 * temp_th));
//					} else {
//						do {
//							wallKananApi(11,25,10);
//							wait(0.1);
//						} while (!ApiSekitar(0.8 * temp_th));
//					}
//			}
//
//			int t_tengah = MaxApiTengah();//NilaiApiTengah();
//			int t_kiri = MaxApiKiri();//NilaiApiKiri();
//			int t_kanan = MaxApiKanan();//NilaiApiKanan();
//
//			if (t_tengah > t_kiri && t_tengah > t_kanan) {
//					MajuLurus(15);
//					wait(0.1);
//			} else if (t_kiri > t_tengah && t_kiri > t_kanan) {
//				if(JarakKiri == 7){
//					GeserKanan(30);
//					wait(0.1);
//					PutarKiri(40);
//					wait(0.1);
//				}
//				PutarKiri(40);
//
//			} else /*t_kiri > t_tengah && t_kiri > t_kanan*/ {
//				if (JarakKanan == 7){
//					GeserKiri(30);
//					wait(0.1);
//					PutarKanan(40);
//					wait(0.1);
//				}
//				PutarKanan(40);
//			}
//			wait(0.1);
//		} while (!ApiSekitarTengah(temp_th));
//	} while (!ApiSekitarTengah(temp_th));
//}
void putarKeApi(int temp_th) {
	DisplayLCD("PUTAR_API");
	if (MaxApiKanan() > MaxApiKiri()) {
//		while(!ApiSekitarTengah(70)){
			PutarKanan(70);
			wait(0.1);
//		}
	}
	else if (MaxApiKiri() > MaxApiKanan()) {
//		while(!ApiSekitarTengah(70)){
			PutarKiri(70);
			wait(0.1);
	}
	QuickStop();
	wait(0.1);

	int count = 0;

		do {
			HindarFurnitureApi2();

			int t_tengah = MaxApiTengah();//NilaiApiTengah();
			int t_kiri = MaxApiKiri();//NilaiApiKiri();
			int t_kanan = MaxApiKanan();//NilaiApiKanan();
			if(t_tengah>100){ // jika api sudah besar, tetapi jaraknya masih terlalu jauh
				if(JarakPingDepan<16){
					return;
				}
			}

			if(ApiUjung(70)){ //jika api terdeteksi di ujung, arahkan ke tengah
					ArahkanKeApi(60);
			}

//			LCD.printf("%d %d %d ", t_kiri, t_tengah, t_kanan);

			if (t_tengah > t_kiri && t_tengah > t_kanan) {

					MajuLurus(15);
					wait(0.1);
			} else if (t_kiri > t_tengah && t_kiri > t_kanan) {

				if(JarakKiri == 7){
					GeserKanan(30);
					wait(0.1);
					PutarKiri(40);
					wait(0.1);
				}
				PutarKiri(50);
				wait(0.1);
				while(!ApiSekitar(50)&& count < 10){
					PutarKiri(40);
					wait(0.1);
					if (ApiUjung(60)){
						ArahkanKeApi(70);
					}
					count ++;
				}
				if (count == 9){
					count = 0;
					do {
						PutarKanan(40);
						wait(0.1);
						count ++;
					}while (count <10&&!ApiSekitar(50));
				}


			} else /*t_kiri > t_tengah && t_kiri > t_kanan*/ {
				count = 0;
				if (JarakKanan == 7){
					GeserKiri(30);
					wait(0.1);
					PutarKanan(40);
					wait(0.1);
				}
				PutarKanan(50);
				wait(0.1);
				while(!ApiSekitar(50) && count <10){
					PutarKanan(40);
					wait(0.1);
					if (ApiUjung(60)){
						ArahkanKeApi(70);
					}
					count ++;
				}
				if (count == 9){
					count = 0;
					do {
						PutarKiri(40);
						wait(0.1);
						count ++;
					}while (count <10&&!ApiSekitar(50));
				}

			}
			wait(0.1);
			LCD.cls();
		} while (!ApiSekitarTengah(temp_th));
}
void putarKeApi2(int temp_th) {
	if (MaxApiKanan() > MaxApiKiri()) {
		PutarKanan(70);
		wait(0.3);
		QuickStop();
		wait(0.1);
	} else if (MaxApiKiri() > MaxApiKanan()) {
		PutarKiri(70);
		wait(0.3);
		QuickStop();
		wait(0.1);
	}

	// Pilih arah
	int batas_kanan, batas_kiri;
	bool arah = (JarakKanan > JarakKiri);
	bool arah_wall = arah;
	if (arah) {	// Kanan
		batas_kanan = 8;
		batas_kiri = -1;
	} else {	// Kiri
		batas_kanan = 1;
		batas_kiri = -8;
	}

	bool furniture = false;
	do {
		int count = 0;
		int count_kiri_kanan = 0;
		do {
			// Detect furniture
			clock_t start = clock();
			HindarFurniture();
			clock_t end = clock();
			furniture = ((end - start) * CLOCKS_PER_SEC > 1);
			if (furniture) {
				if (JarakKiri < JarakKanan) {
					do {
						wallKiriApi(11,25,10);
						wait(0.1);
					} while (!ApiSekitar(0.8 * temp_th));
				} else {
					do {
						wallKananApi(11,25,10);
						wait(0.1);
					} while (!ApiSekitar(0.8 * temp_th));
				}
			}

			// Di ujung kiri/kanan
			if ((count == batas_kanan) || (count == batas_kiri)) {
				arah = !arah;
				// count_kiri_kanan++;
			}
			if (ApiSekitarTengah(temp_th * 0.5)) {
				count_kiri_kanan += 2;
			}
			//setiap selesai kiri+kanan , maju
			if ((count_kiri_kanan % 2 == 0) && (count_kiri_kanan != 0)) {
//				MajuLurus(30);
//				wait(0.5);
				count_kiri_kanan = 1;
	//			count = 0;
	//			arah = 0;
			}
			QuickStop();
			wait(0.2);
			if (JarakKiri<8){
				GeserKanan(30);
				wait(0.2);
				QuickStop();
				PutarKiri(50);
				wait(0.2);
				QuickStop();
			}
			if (JarakKanan < 8){
				GeserKiri(30);
				wait(0.2);
				QuickStop();
				PutarKanan(50);
				wait(0.2);
				QuickStop();
			}
			if (count_kiri_kanan == 0) {
				//putar kiri/kanan
				if (arah) {
					PutarKanan(50);
					wait(0.1);
					count++;
				} else {
					PutarKiri(50);
					wait(0.1);
					count--;
				}
				wait(0.1);
			}
		} while (count_kiri_kanan != 1);

		do {
			// Detect furniture
//			clock_t start = clock();
//			HindarFurniture();
//			clock_t end = clock();
//			furniture = ((end - start) * CLOCKS_PER_SEC > 1);
//			if (furniture || JarakDepan < 10) {
//				if (arah_wall) {
//					do {
//						wallKiriApi(11,25,10);
//						wait(0.1);
//					} while (!ApiSekitar(0.8 * temp_th));
//				} else {
//					do {
//						wallKananApi(11,25,10);
//						wait(0.1);
//					} while (!ApiSekitar(0.8 * temp_th));
//				}
//			}

			if (JarakDepan < 10) {
				if (arah_wall) {
					do {
							wallKiriApi(11,25,10);
							wait(0.1);
						} while (!ApiSekitar(0.8 * temp_th));
					} else {
						do {
							wallKananApi(11,25,10);
							wait(0.1);
						} while (!ApiSekitar(0.8 * temp_th));
					}
			}

			int t_tengah = MaxApiTengah();//NilaiApiTengah();
			int t_kiri = MaxApiKiri();//NilaiApiKiri();
			int t_kanan = MaxApiKanan();//NilaiApiKanan();

			if (t_tengah > t_kiri && t_tengah > t_kanan) {
					MajuLurus(15);
					wait(0.1);
			} else if (t_kiri > t_tengah && t_kiri > t_kanan) {
				if(JarakKiri == 7){
					GeserKanan(30);
					wait(0.1);
					PutarKiri(40);
					wait(0.1);
				}
				PutarKiri(40);

			} else /*t_kiri > t_tengah && t_kiri > t_kanan*/ {
				if (JarakKanan == 7){
					GeserKiri(30);
					wait(0.1);
					PutarKanan(40);
					wait(0.1);
				}
				PutarKanan(40);
			}
			wait(0.1);
		} while (!ApiSekitarTengah(temp_th));
	} while (!ApiSekitarTengah(temp_th));
}

char ApiSekitar2(int temp_th){
	//int temp_th=50;
	if(tpa_0.getTemp(2)>temp_th||tpa_0.getTemp(3)>temp_th||tpa_0.getTemp(4)>temp_th||tpa_0.getTemp(5)>temp_th||tpa_0.getTemp(6)>temp_th||tpa_0.getTemp(7)>temp_th)
	{
		return 1;
	}
	else if(tpa_2.getTemp(1)>temp_th||tpa_2.getTemp(2)>temp_th||tpa_2.getTemp(3)>temp_th||tpa_2.getTemp(4)>temp_th||tpa_2.getTemp(5)>temp_th||tpa_2.getTemp(6)>temp_th||tpa_2.getTemp(7)>temp_th||tpa_2.getTemp(8)>temp_th)
	{
		return 1;
	}
	else {
		return 0;
		}
}


void PutarApi(int Nkiri, int Nkanan)
{
	while(ApiTengah()==0)
	{
		for(int i=0;i<Nkiri;i++)
		{
			PutarKiri(120);
			wait(0.1);
			if(ApiTengah()==1){
				break;
			}

		}
		for(int i=0;i<Nkanan;i++)
		{
			PutarKanan(120);
			wait(0.1);
			if(ApiTengah()==1){
				break;
			}

		}

	}
	QuickStop();
	wait(0.5);
}

void PutarApiKanan(int Nkanan, int Nkiri)
{
	while(ApiTengah()==0)
	{
		for(int i=0;i<Nkanan;i++)
		{
			PutarKanan(120);
			wait(0.1);
			if(ApiTengah()==1){
				break;
			}

		}
		for(int i=0;i<Nkiri;i++)
		{
			PutarKiri(120);
			wait(0.1);
			if(ApiTengah()==1){
				break;
			}

		}

	}
	QuickStop();
	wait(0.5);
}

void CekApiLagi()
{
	ENKipas = 1;
	wait(1);
	while(UV2.Flag==1)
	{
		ENKipas = 0;
		TengokKananBawah(150);
		TengokKiriBawah(150);
		TengokKiriBawah(0);
		ENKipas=1;
		wait(0.1);
		TengokKanan(0);
		QuickStop();
		wait(1);
	}
}



//void JelajahApi() //jika ada furniture menutupi lilin
//{
//
//	if(Posisi==R1){
//		if(Pintu==MasukR1A){
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKanan(200);
//				wait(0.1);
//			}while(ARAH!=TIMUR);
//			QuickStop();
//			wait(0.1);
//			for(int i=0;i<15;i++){
//				wallKanan(16,45,25);
//				wait(0.1);
//			}
//			do{
//				wallKanan(16,45,25);
//				wait(0.1);
//			}while(JarakDepan>=45&&ApiSekitar(50)==0);
//			PutarApiKanan(10,35);
//			do{
//				ENKipas=0;
//				wait(1);
//				if(UV2.Flag==0){
//					CekApiLagi();
//				}
//				wait(1);
//			}while(UV2.Flag==1);
//			ENKipas=1;
//			LEDPadamkanApi = 0;
//			QuickStop();
//			wait(0.5);
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKiri(200);
//				wait(0.1);
//			}while(ARAH!=BARAT);
//			PutarKiri(100);
//			wait(0.5);
//			QuickStop();
//			wait(0.5);
//			do{
//				wallKiri(17,45,25);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//		}
//		else{//MasukR1B
//			MajuLurus(35);
//			wait(0.8);
//			QuickStop();
//			wait(0.1);
//			do{
//				GetArah(KompasToleransiKecil);
//				wallKanan3(16,45,25);
//				wait(0.1);
//			}while(ARAH!=TIMUR&&ApiSekitar(50)==0);
//
//			if(ARAH==TIMUR){
//				do{
//					GetArah(KompasToleransiKecil);
//					wallKanan3(16,45,25);
//					wait(0.1);
//				}while(ApiSekitar2(50)==0&&JarakDepan>45);
//				QuickStop();
//				if(ApiSekitar2(50)==1){
//					PutarApiKanan(15,45);
//				}
//				else{
//					PutarKanan(280);
//					wait(0.7);
//					QuickStop();
//					wait(0.1);
//					do{//depan sudah dekat
//						GetArah(KompasToleransiKecil);
//						PutarKiri(220);
//						wait(0.1);
//					}while(ApiTengah()==0);
//				}
//				QuickStop();
//				do{
//					ENKipas=0;
//					wait(1);
//					if(UV2.Flag==0){
//						CekApiLagi();
//					}
//					wait(1);
//				}while(UV2.Flag==1);
//				ENKipas=1;
//				QuickStop();
//				wait(0.1);
//				LEDPadamkanApi = 0;
//				do{
//					GetArah(KompasToleransiKecil);
//					PutarKiri(150);
//					wait(0.1);
//				}while(ARAH!=BARAT);
//				QuickStop();
//				wait(0.5);
//				do{
//					wallKiri2(16,45,25);
//					wait(0.1);
//				}while(GarisBelakang==HITAM);
//				QuickStop();
//				wait(0.1);
//
//			}else{
////				ketemu api
//				PutarApiKanan(15,35);
//				do{
//					ENKipas=0;
//					wait(1);
//					if(UV2.Flag==0){
//						CekApiLagi();
//					}
//					wait(1);
//				}while(UV2.Flag==1);
//				ENKipas=1;
//				QuickStop();
//				wait(0.1);
//				LEDPadamkanApi = 0;
//				do{
//					GetArah(KompasToleransiKecil);
//					PutarKiri(140);
//					wait(0.1);
//				}while(ARAH!=BARAT);
//				QuickStop();
//				wait(0.5);
//				do{
//					GeserKiri(40);
//					wait(0.1);
//				}while(JarakKanan>15);
//				//
//				do{
//					wallKanan(18,45,25);
//					wait(0.1);
//				}while(GarisBelakang==HITAM);
//				QuickStop();
//				wait(0.1);
//			}
//
//		}
//	}
//	if(Posisi==R3||Posisi==R2){
//		if(Posisi==R3){
//		GeserKanan(40);
//		wait(0.4);
//		QuickStop();
//		wait(0.1);
//		PutarKiri(150);
//		wait(0.2);
//		QuickStop();
//		wait(0.1);
//		}
//		MajuLurus(30);
//		wait(0.6);
//
//		if(Posisi==R3){
//			do{
//				GetArah(KompasToleransiKecil);
//				wallKanan3(16,45,25);
//				wait(0.1);
//			}while(ApiSekitar(50)==0&&ARAH!=BARAT);
//			QuickStop();
//			wait(0.1);
//			GetArah(KompasToleransiKecil);
//			if(ARAH==BARAT){
//				PutarKanan(250);
//				wait(0.3);
//			}
//		}
//
//		else if(Posisi==R2){
//			//wallkiri aja
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKiri(180);
//				wait(0.1);
//			}while(ARAH!=BARAT);
//			QuickStop();
//			wait(0.1);
//
//			do{
//				GetArah(KompasToleransiKecil);
//				wallKiri(17,45,20);
//				wait(0.1);
//			}while(ApiSekitar(55)==0&&ARAH!=TIMUR);
//			QuickStop();
//			wait(0.1);
//			}
//			PutarApi(10,40);
//			do{
//				ENKipas=0;
//				wait(1);
//				if(UV2.Flag == 0){
//					CekApiLagi();
//				}
//				wait(1);
//			}while(UV2.Flag==1);
//			ENKipas=1;
//			LEDPadamkanApi = 0;
//			QuickStop();
//			wait(0.5);
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKanan(110);
//				wait(0.1);
//			}while(ARAH!=SELATAN);
//			QuickStop();
//			wait(0.5);
//			if(JarakDepan>13){
//				do{
//					MajuLurus(30);
//					wait(0.1);
//				}while(JarakDepan>13);
//			}
//
//
//
////			//wallkanan?
////			PutarKiri(230);
////			wait(0.9);
////			QuickStop();
////			wait(0.1);
////			MajuLurus(35);
////			wait(0.2);
////			do{
////				GetArah(KompasToleransiKecil);
////				wallKanan3(18,45,25);
////				wait(0.1);
////			}while(ApiSekitar(50)==0&&ARAH!=BARAT);
////			QuickStop();
////			wait(0.1);
////			GetArah(KompasToleransiKecil);
////			if(ARAH==BARAT){
////				PutarKanan(250);
////				wait(0.5);
////			}
////
////		}
////		PutarApiKanan(10,40);
////		do{
////			ENKipas=0;
////			wait(1);
////			if(UV2.Flag == 0){
////				CekApiLagi();
////			}
////			wait(1);
////		}while(UV2.Flag==1);
////		ENKipas=1;
////		LEDPadamkanApi = 0;
////		QuickStop();
////		wait(0.5);
////		do{
////			GetArah(KompasToleransiKecil);
////			PutarKanan(150);
////			wait(0.1);
////		}while(ARAH!=SELATAN);
////		QuickStop();
////		wait(0.5);
////		PutarKiri(250);
////		wait(0.3);
////		QuickStop();
////		wait(0.5);
//		if(Posisi==R3){
//			do{
//				wallKiri2(16,45,25);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//
//		}
//		else if(Posisi==R2){
//			do{
//				wallKiri2(16,45,20);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//
//		}
//	}
//}

//void PadamkanApiR3(){
//	LEDPadamkanApi = 1;
//	GeserKanan(40);
//	wait(0.2);
//	QuickStop();
//	PutarKiri(250);
//	wait(0.5);
//	QuickStop();
//	wait(0.5);
//	do{
//		GetArah(KompasToleransiKecil);
//		PutarKanan(120);
//		wait(0.1);
//	}while(ApiTengah()==0&&ARAH!=TIMUR);
//	QuickStop();
//	wait(0.1);
//	GetArah(KompasToleransiKecil);
//	if(ARAH!=TIMUR){
//		PutarKiri(130);
//		wait(0.1);
//		QuickStop();
//		do{
//			ENKipas=0;
//			wait(1);
//			if(UV2.Flag==0){
//				CekApiLagi();
//			}
//			wait(1);
//		}while(UV2.Flag==1);
//		ENKipas=1;
//		QuickStop();
//		wait(2);
//		LEDPadamkanApi = 0;
//		do{
//			PutarKanan(150);
//			wait(0.4);
//			GetArah(KompasToleransiKecil);
//		}while(ARAH!=SELATAN);
//
//		do{
//			wallKanan(18,45,20);
//			wait(0.1);
//		}while(GarisBelakang==HITAM);
//
//	}
//	else{
//		JelajahApi();
//	}
//	QuickStop();
//	wait(0.1);
//	Pintu=KeluarR3;
//	Mode =BACKHOME;
//}

//void PadamkanApiR2(){
//	LEDPadamkanApi = 1;
//	GeserKiri(40);
//	wait(0.4);
//	QuickStop();
//	wait(0.3);
//	PutarKiri(210);
//	wait(0.5);
//	QuickStop();
//	do{
//		PutarKanan(100);
//		wait(0.1);
//		GetArah(KompasToleransiKecil);
//	}while(ApiTengah()==0&&ARAH!=UTARA);
//	QuickStop();
//	wait(0.5);
//	GetArah(KompasToleransiKecil);
//	if(ARAH!=UTARA)
//	{
//		PutarKiri(120);
//		wait(0.1);
//		QuickStop();
//		do{
//			ENKipas=0;
//			wait(1);
//			if(UV2.Flag==0){
//				CekApiLagi();
//			}
//			wait(1);
//		}while(UV2.Flag==1);
//		ENKipas=1;
//		QuickStop();
//		LEDPadamkanApi = 0;
//		do{
//			GetArah(KompasToleransiKecil);
//			PutarKanan(100);
//			wait(0.1);
//		}while(ARAH!=TIMUR);
//
//		do{
//			wallKanan(18,45,20);
//			wait(0.1);
//		}while(GarisBelakang==HITAM);
//
//	}
//	else{
//		JelajahApi();
//	}
//	QuickStop();
//	wait(0.5);
//	Pintu=KeluarR2;
//	Mode =BACKHOME;
//}

//void PadamkanApiR1(){
////        	cari pintunya di bagian mana
//	LEDPadamkanApi = 1;
//	UpdatePintu();
//	wait(0.1);
//	if(Pintu==MasukR1A)
//	{
////            	jika kondisi di pintu Masuk R1 A
//		PutarKanan(280);
//		wait(0.4);
//		do{
//			GetArah(KompasToleransiKecil);
//			PutarKiri(100);
//			wait(0.1);
//		}while(ApiTengah()==0&&ARAH!=BARAT);
//		QuickStop();
//		wait(0.1);
//		GetArah(KompasToleransiKecil);
//		if(ARAH!=BARAT){
////			menemukan api
//			PutarKanan(100);
//			wait(0.1);
//			QuickStop();
//			do{
//				ENKipas=0;
//				wait(1);
//				if (UV2.Flag == 0) {
//					CekApiLagi();;
//				}
//				wait(1);
//			}while(UV2.Flag==1);
//			ENKipas=1;
//			QuickStop();
//			wait(2);
//			LEDPadamkanApi = 0;
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKanan(150);
//				wait(0.1);
//			}while(ARAH!=BARAT);
//			QuickStop();
//			wait(0.5);
//			do{
//				wallKiri2(18,45,20);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//
//		}
//		else {
////			ga nemu apinya
//			JelajahApi();
//		}
//		QuickStop();
//		wait(0.5);
//		Mode = BACKHOME;
//		Pintu = KeluarR1A;
//	}
//	else
////		kalo ga nemu, paksa ke R1B
//	{
////            	jika masuk dari pintu 1B
//		PutarKiri(280);
//		wait(0.3);
//		do{
//			PutarKanan(110);
//			wait(0.1);
//			GetArah(KompasToleransiKecil);
////					ulangi hingga ketemu api atau tidak ketemu samsek
//		}while(ApiTengah()==0&& ARAH!=SELATAN);
////				jika ga nemu, lanjut dekati lilin dgn wallkanan
//		GetArah(KompasToleransiKecil);
//		if(ApiTengah()==0)
//		{
//			JelajahApi();
//		}
//		else {
////					api ditemukan dari titik awal pada ruangan
//			QuickStop();
//			wait(0.1);
////					matikan api
//			do{
//				ENKipas=0;
//				wait(1);
//				if(UV2.Flag==0){
//					CekApiLagi();
//				}
//				wait(1);
//			}while(UV2.Flag==1);
//			ENKipas=1;
//			QuickStop();
//			wait(2);
//			LEDPadamkanApi = 0;
//
//			do{
//				GetArah(KompasToleransiKecil);
//				PutarKiri(200);
//				wait(0.1);
//			}while(ARAH!=BARAT);
//			QuickStop();
//			wait(0.3);
//			PutarKanan(250);
//			wait(0.2);
//			QuickStop();
//			do{	wallKanan(18,45,20);
//				wait(0.1);
//			}while(GarisBelakang==HITAM);
//			QuickStop();
//			wait(0.5);
//
//		}
//		Pintu = KeluarR1B;
//		Mode = BACKHOME;
//	}
//}

//void PadamkanApiR4(){
//	LEDPadamkanApi = 1;
//	QuickStop();
//	wait(0.1);
//	GetArah(KompasToleransiBesar);
//	if(ARAH==UTARA){
//		Pintu=MasukR4A;
//	}
//	else{
//		Pintu=MasukR4B;
//	}
//	if(Pintu==MasukR4A){
//		do{
//			wallKiri(17,45,20);
//			wait(0.1);
//		}while(JarakDepan>13);
//		QuickStop();
//		wait(0.1);
//
//	}
//	else{//r1B
//		do {
//			wallKiri(17,45,20);
//			wait(0.1);
//		} while (JarakDepan>15);
//		QuickStop();
//		wait(0.1);
//		PutarKiri(200);
//		wait(1);
//
//	}
//	do{
//		PutarKanan(110);
//		wait(0.1);
//	}while(ApiTengah()==0);
//	if(Pintu==MasukR4A){
//		MajuLurus(35);
//		wait(1);
//		PutarApi(5,25);
//	}
//	QuickStop();
//	wait(0.1);
//	do{
//		ENKipas=0;
//		wait(1);
//		if(UV2.Flag==0){
//			CekApiLagi();
//		}
//		wait(1);
//	}while(UV2.Flag==1);
//	ENKipas=1;
//	QuickStop();
//	LEDPadamkanApi = 0;
//	QuickStop();
//	wait(0.1);
//	if(Pintu==MasukR4A){
//		do{
//			PutarKiri(50);
//			wait(0.1);
//			GetArah(80);
//		}while(ARAH!=UTARA);
//		QuickStop();
//		wait(0.1);
//
////		PutarKanan(200);
////		wait(0.2);
//		do{
//			MajuLurus(30);
//			wait(0.1);
//		}while(JarakDepan>15);
//		QuickStop();
//		wait(0.1);
//
//		do{
//			wallKanan(20,45,20);
//			wait(0.1);
//		}while (GarisBelakang==HITAM);
//		QuickStop();
//		wait(0.1);
//
//		if(kompas.readBearing()<THSelatan-50){
//			do{
//				PutarKiri(30);
//				GetArah(70);
//			}while(ARAH!=SELATAN);
//		}
//		else if(kompas.readBearing()>THSelatan+50){
//			do{
//				PutarKanan(30);
//				GetArah(70);
//			}while(ARAH!=SELATAN);
//		}
//
//		DisplayBACKHOME();
//		wait(0.1);
//		R4AtoHome();
//	}
//	else if(Pintu==MasukR4B){
//		do{
//			GetArah(80);
//			PutarKanan(50);
//			wait(0.1);
//		}while(ARAH!=UTARA);
////		PutarKiri(200);
////		wait(0.8);
//		QuickStop();
//		wait(0.1);
//		do{
//			GeserKanan(40);
//			wait(0.1);
//		}while(JarakKanan<20);
//		do {
//			MajuLurus(30);
//			wait(0.1);
//		} while (GarisBelakang==HITAM);
//		QuickStop();
//		wait(0.1);
//		if(kompas.readBearing()<THUtara-50){
//			do{
//				PutarKiri(40);
//				GetArah(70);
//			}while(ARAH!=UTARA);
//		}
//		else if(kompas.readBearing()>THUtara+50){
//			do{
//				PutarKanan(40);
//				GetArah(70);
//			}while(ARAH!=UTARA);
//		}
//		DisplayBACKHOME();
//		wait(0.1);
//		R4BtoHome();
//	}


//	QuickStop();
//	wait(0.5);
//	GetArah(KompasToleransiBesar);
//	if(ARAH==UTARA){
//		Pintu==KeluarR4B;
//	}
//	else{
//		Pintu=KeluarR4A;
//	}
//	QuickStop();
//	wait(0.1);
//	Mode =BACKHOME;
//}

//void PadamkanApi()
//{
//	LEDPadamkanApi = 1;
//    switch(Posisi){
//        case R3:
//            PadamkanApiR3();
//            break;
//
//        case R2:
//        	PadamkanApiR2();
//			break;
//
//        case R1:
//        	PadamkanApiR1();
//            break;
//
//        case R4:
//        	PadamkanApiR4();
//            break;
//        default:
//        	PadamkanApiR1();
//        	break;
//
//    }
//}
//void matikanApi() {
//	ENKipas = 1;
//	while (UV2.Flag == 1){
//		for(int i = 1; i <= 2; i++){
//			TengokKananBawah(i*30);
//			//TengokKanan(i*30);
//			wait(0.01);
//		}
//		for(int i = 1; i <= 2; i++){
//			TengokKiriBawah(i*30);
//			//TengokKiri(i*30);
//			wait(0.01);
//		}
//		HadapNormal();
//	}
//	ENKipas = 0;
//	LEDPadamkanApi = 0;
//}

void matikanApiRepeat(int berapaKali) {
	//if(PingDepan>BatasJarakApi) return;
	if (JarakPingDepan>15){ // jika apinya masih terlalu jauh di depan
		return;
	}


	int countKiri = 3;
	int countKanan = 3;
	if (NilaiApiTengahKiri >= NilaiApiTengahKanan) {
		PutarKiri(50); // arahkan ke tengah api
		wait(0.1);
		QuickStop();
	} else {
		PutarKanan(50);
		wait(0.1);
		QuickStop();
	}
	ENKipas = 1; // matikan api

	for (int j = 1; j < berapaKali ; j++){ // kepala geser geser
		for (int i = 1; i <= countKanan; i++){
			TengokKananBawah(i*30);
			wait(0.01);
		}
		for(int i = 1; i <= countKiri; i++){
			TengokKiriBawah(i*30);
			wait(0.01);
		}
		TengokBawah(75);
	}

	HadapNormal(); // kembalikan posisi normal
	ENKipas = 0;
	QuickStop();
	wait(0.1);
}

void sikatLilin(int tempAwal, int countUp, int lamaTiup){
	do {
		int batasApi = tempAwal;
		LCD.cls();
		LCD.printf("%d",batasApi);
		putarKeApi(batasApi);
		if (JarakPingDepan >30){
			tempAwal += 3 ;
		}
		QuickStop();
		wait(0.1);
		matikanApiRepeat(lamaTiup);
		tempAwal += countUp;
		QuickStop();
		wait(0.5);
	} while(UV2.Flag);
//	LEDPadamkanApi = 0;
	QuickStop();
	wait(1);
}




void matikanApi() {
	int countKiri=2;
	int countKanan=2;
	if(NilaiApiTengahKiri>=NilaiApiTengahKanan){
		countKiri = 3;
		PutarKiri(50);
		wait(0.3);
		QuickStop();
	}
	else{
		countKanan = 3;
		PutarKanan(50);
		wait(0.3);
		QuickStop();
	}
	ENKipas = 1;

	while (UV2.Flag == 1){
		for(int i = 1; i <= countKanan; i++){
			TengokKananBawah(i*30);
			//TengokKanan(i*30);
			wait(0.01);
		}
		for(int i = 1; i <= countKiri; i++){
			TengokKiriBawah(i*30);
			//TengokKiri(i*30);
			wait(0.01);
		}
		TengokBawah(65);

	}
	HadapNormal();
	ENKipas = 0;
	LEDPadamkanApi = 0;
}

//void matikanApi() {
//	if(NilaiApiTengahKiri>=NilaiApiTengahKanan){
//			PutarKiri(60);
//			wait(0.2);
//			QuickStop();
//		}
//		else{
//
//			PutarKanan(60);
//			wait(0.2);
//			QuickStop();
//		}
//	ENKipas = 1;
//	while (UV2.Flag == 1){
//		TengokBawah(60);
//	}
//	HadapNormal();
//	ENKipas = 0;
//	LEDPadamkanApi = 0;
//}

//void matikanApiRepeat(int x) {
//
//	int countKiri=1;
//	int countKanan=1;
//	if(NilaiApiTengahKiri>=NilaiApiTengahKanan){
//		countKiri = 4;
//		PutarKiri(50);
//		wait(0.5);
//		QuickStop();
//	}
//	else{
//		countKanan = 4;
//		PutarKanan(50);
//		wait(0.1);
//		QuickStop();
//	}
//	ENKipas = 1;
//
//	for(int j = 1; j<=x; j++){
//		for(int i = 1; i <= countKanan; i++){
//			TengokKananBawah(i*30);
//			//TengokKanan(i*30);
//			wait(0.01);
//		}
//		for(int i = 1; i <= countKiri; i++){
//			TengokKiriBawah(i*30);
//			//TengokKiri(i*30);
//			wait(0.01);
//		}
//			TengokBawah(50);
//	}
//	HadapNormal();
//	ENKipas = 0;
//	wait(0.5);
//	if(UV2.Flag==0){
//		LEDPadamkanApi = 0;
//	}
//
//}
void PadamkanApi() {
	DisplayLCD("PadamkanApi");
	LEDPadamkanApi = 1;
	switch (pintu.back()) {
	case MasukR1A:
		PadamkanApiR1A(); break;
	case MasukR1B:
		PadamkanApiR1B(); break;
	case MasukR1C:
		PadamkanApiR1C(); break;
	case MasukR2:
		PadamkanApiR2(); break;
	case MasukR3:
		PadamkanApiR3(); break;
	case MasukR4A:
		PadamkanApiR4A(); break;
	case MasukR4B:
		PadamkanApiR4B(); break;
	}
}

//void PadamkanApiR1A() {
//	DisplayLCD("Wall s.d. Api");
//	DisplayLCD("Api R1A");
//	//BatasApi =155;
//	PutarSampaiArahIR(BARAT);
//	bool pernahGaris = false;
//	do {
//		wallKananApi(13,25,10);
//		wait(0.1);
//		if (GarisTengah == PUTIH || totalADC()>280000){
//			pernahGaris = true ;
//		}
//	} while (!ApiSekitar(80) && GarisTengah == HITAM && !ApiUjung(90));
//	QuickStop();
//	wait(0.1);
//	if(ApiUjung(90)){
//		DisplayLCD("API UJUNG");
//	}
//	if(ApiSekitar(80)){
//		DisplayLCD("API SEKITAR");
//	}
//
//	if (pernahGaris) {
//		PutarSampaiArah(SELATAN);
//		lurusGaris();
//		QuickStop();
//		wait(0.2);
//
//		while (JarakKanan>8){
//			GeserKanan(30);
//			wait(0.1);
//
//		}
//		QuickStop();
//
//		MajuLurus(35);
//		wait (0.7);
//		ResetArah();
//		PutarSampaiArah(UTARA);
//		do {
//		wallKiriSlow(14, 25, 10);
//		wait(0.1);
//		}while (GarisTengah==HITAM);
//
//
//		do {
//			GeserKanan(30);
//			wait(0.1);
//		} while (JarakKiri > 13);
//
//		do {
//			wallKananApi(11,25,10);
//			wait(0.1);
//		} while (!ApiSekitar(70));
//	}
//
//	DisplayLCD("R1A sekitar api");
//	QuickStop();
//	wait(0.1);
//
//
//
//	//DisplayLCD("R1A mengarah ke api");
//	ArahkanKeApi(70);
//	sikatLilin(143,3,8);
////	putarKeApi(150);//putar ke arah api
////	QuickStop();
////	wait(0.1);
////	//matikanApiRepeat(7);
////	//BatasApi+=5;
////
////		//putarKeApi(150);
////		DisplayLCD("Matikan Api R1A");
////		while(UV2.Flag){
////			matikanApi();
////			wait(0.5);
////		}
//
//
//
//	QuickStop();
//}

void PadamkanApiR1A() {
	DisplayLCD("Wall s.d. Api");
	DisplayLCD("Api R1A");
	//BatasApi =155;
//	ResetArah();
//	PutarSampaiArahIR(BARAT);
	bool pernahGaris = false;
	do {
		wallKananApi(13,25,10);
		wait(0.1);
		if (GarisTengah == PUTIH || totalADC()<280000){
			pernahGaris = true ;
		}
	} while (!ApiSekitar(70) && GarisTengah == HITAM && !ApiUjung(70));
	QuickStop();
	wait(0.1);
	if(ApiUjung(90)){
		DisplayLCD("API UJUNG");
	}
	if(ApiSekitar(80)){
		DisplayLCD("API SEKITAR");
	}

	if (pernahGaris) {

		DisplayLCD("pernahGARIS");
		QuickStop();
		wait(2);
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
			wallKananApi(11,25,10);
			wait(0.1);
		} while (!ApiSekitar(70));
	}

	DisplayLCD("R1A sekitar api");
	QuickStop();
	wait(0.1);



	//DisplayLCD("R1A mengarah ke api");
	ArahkanKeApi(70);
	sikatLilin(143,3,8);
//	putarKeApi(150);//putar ke arah api
//	QuickStop();
//	wait(0.1);
//	//matikanApiRepeat(7);
//	//BatasApi+=5;
//
//		//putarKeApi(150);
//		DisplayLCD("Matikan Api R1A");
//		while(UV2.Flag){
//			matikanApi();
//			wait(0.5);
//		}



	QuickStop();
}

void PadamkanApiR1B() {
	ArahWall = KANAN;
	DisplayLCD("Wall s.d. Api");
	DisplayLCD("Api R1B");
	unsigned char batas_putar_bawah, batas_putar_atas;

//	PutarSampaiArah(BARAT);
//	do {
//		GeserKiri(30);
//		wait(0.1);
//	} while (JarakKiri > 8);

//	if (!apiDekat) {
//		if (!ApiSekitar(70)) {
			DisplayLCD("MENGARAH UTARA");
			ResetArah();
			PutarSampaiArah(UTARA);

			MajuLurus(40);
			wait(1.2);

//			do {
//				wallKananApi(11,25,10);
//				wait(0.1);
//				GetArah(350);
//			} while (!ApiSekitar(70) && ARAH!=BARAT);
			do {
				wallKananApi(11,25,10);
				wait(0.1);
			} while (!ApiSekitar(70) && !(JarakDepan < 14 &&
					JarakSRKanan < 16 && JarakKanan < 11));

			QuickStop();
			wait(0.5);
			if (!ApiSekitar(70)) {
				DisplayLCD("Pojok");
				ResetArah();
				PutarSampaiArahIR(BARAT);
				do {
					GeserKanan(30);
					wait (0.1);
				} while (JarakKanan>8);
				DisplayLCD("Maju sedikit");
				while(JarakBelakang<28){
					wallKananApi(14,25,10);
					wait(0.1);
				}

				QuickStop();
				PutarKanan(70);
				wait(0.4);
				QuickStop();
				DisplayLCD("Scan api sedikit");
				do {
					PutarKiri(40);
					wait(0.1);

				}while (((kompas.readBearing() + errorSudut )%3600)>(THSelatan+THBarat)/2 && !ApiSekitar(70)&&!ApiUjung(90));

				QuickStop();
				DisplayLCD("api sudut");
				if (!ApiSekitar(70)){
					ResetArah();
					PutarSampaiArahIR(BARAT);
					QuickStop();
					do {
						GeserKanan(30);
						wait(0.1);
					}while (JarakKanan>10);
					do{
						wallKananApi(11,25,10);
						wait (0.1);
					}while (!ApiSekitar(70));
				}

			}



			DisplayLCD("sekitar api");
			QuickStop();
//			wait(2);

//			DisplayLCD("mendekati api");
//			wallKananApi(11,25,10);//mendekati api
//			wait(0.1);
//			QuickStop();
//		}
//	}
	ArahkanKeApi(70);
	sikatLilin(143,3,8);
//	putarKeApi(150);//putar ke arah api
//	QuickStop();
//	wait(0.1);
//
//	DisplayLCD("Matikan Api R1B");
//	while(UV2.Flag){
//		matikanApi();
//		wait(0.5);
//	}
	QuickStop();
}

//void PadamkanApiR1C() {
//	ArahWall = KIRI;
//	DisplayLCD("Wall s.d. Api");
//	DisplayLCD("Api R1C");
//	MundurLurus(40);
//	wait(0.5);
//	KoreksiArahIR();
//	PutarKiri(70);
//	wait(0.3);
//	QuickStop();
//	DisplayLCD("Scan api sedikit");
//	do {
//		PutarKanan(40);
//		wait(0.1);
//	}while (kompas.readBearing()>(THUtara%3600+THTimur)/2 && !ApiSekitar(70)&&!ApiUjung(90));
//	if(!ApiSekitar(70)){
//		do {
//				wallKiriApi(11,25,10);
//				wait(0.1);
//			} while (!ApiSekitar(70) && GarisTengah == HITAM);
//			//PutarSampaiArah(TIMUR);
//
//			if (GarisTengah != HITAM) {
//				PutarSampaiArah(TIMUR);
//				lurusGaris();
//				QuickStop();
//				wait(0.2);
//				MundurLurus(30);
//				wait(2);
//				PutarSampaiArahIR(TIMUR);
//				do {
//					GeserKiri(30);
//					wait(0.1);
//				} while (JarakKiri > 8);
//				PutarSampaiArah(SELATAN);
//				MajuLurus(30);
//				wait(0.5);
//				do {
//					wallKiriApi(11,25,10);
//					wait(0.1);
//				} while (!ApiSekitar(100));
//			}
//
//			DisplayLCD("R1C sekitar api");
//			QuickStop();
//			wait(2);
//
//			DisplayLCD("R1C mendekati api");
//			QuickStop();
//
//	}
//	ArahkanKeApi(70);
//	sikatLilin(130,5,5);
////	DisplayLCD("R1C mengarah ke api");
////	putarKeApi(150);//putar ke arah api
////	QuickStop();
////	wait(0.1);
////
////	DisplayLCD("Matikan Api R1C");
////	while(UV2.Flag){
////		matikanApi();
////		wait(0.5);
////	}
//
//
//	QuickStop();
//}
void PadamkanApiR1C() {
	ArahWall = KIRI;
	DisplayLCD("Wall s.d. Api");
	DisplayLCD("Api R1C");
	MundurLurus(40);
	wait(0.5);
	KoreksiArahIR();
	PutarKiri(70);
	wait(0.3);
	QuickStop();
	DisplayLCD("Scan api sedikit");
	do {
		PutarKanan(40);
		wait(0.1);
	}while (((kompas.readBearing() + errorSudut )%3600) >(THUtara%3600+THTimur)/2 && !ApiSekitar(70)&&!ApiUjung(90));
	if(!ApiSekitar(70)){
		do {
				wallKiriApi(11,25,10);
				wait(0.1);
			} while (!ApiSekitar(70) && GarisTengah == HITAM);
			//PutarSampaiArah(TIMUR);

			if (GarisTengah == PUTIH) {
				PutarSampaiArah(TIMUR);
				lurusGaris();
				QuickStop();
				wait(0.2);
				MajuLurus(30);
				wait(1.5);
				PutarSampaiArahIR(BARAT);
				do {
					GeserKanan(30);
					wait(0.1);
				} while (JarakKanan > 12);

				while (GarisTengah == HITAM) {
					wallKananSlow(14, 25 ,10);
					wait (0.1);
				}
				do {
					GeserKanan(30);
					wait(0.1);
				} while (JarakKanan > 14);

				do {
					wallKiriApi(11,25,10);
					wait(0.1);
				} while (!ApiSekitar(70));
			}

			DisplayLCD("R1C mendekati api");
			QuickStop();

	}
	ArahkanKeApi(70);
	sikatLilin(130,5,5);
//	DisplayLCD("R1C mengarah ke api");
//	putarKeApi(150);//putar ke arah api
//	QuickStop();
//	wait(0.1);
//
//	DisplayLCD("Matikan Api R1C");
//	while(UV2.Flag){
//		matikanApi();
//		wait(0.5);
//	}


	QuickStop();
}


void PadamkanApiR2() {
	ArahWall = KIRI;
	DisplayLCD("Wall s.d. Api");
	DisplayLCD("Api R2");
	PutarSampaiArahIR(TIMUR);
//	MajuLurus(40);
//	wait(1.1);
//	MundurLurus(30);
//	wait(0.6);
	ResetArah();
	do {
		wallKiriApi(13,25,10);
		wait(0.1);
		GetArah(150);
	} while (!ApiSekitar(70)&&!ApiUjung(70) );

	ArahkanKeApi(70);
	DisplayLCD("sekitar api");
	QuickStop();
	wait(0.1);

	DisplayLCD("mendekati api");
	sikatLilin(145,3,6);

	QuickStop();
}

//void PadamkanApiR2() {
//	DisplayLCD("Wall s.d. Api");
//	DisplayLCD("Api R2");
//	PutarSampaiArahIR(TIMUR);
////	MajuLurus(40);
////	wait(1.1);
////	MundurLurus(30);
////	wait(0.6);
//	ResetArah();
//	do {
//		wallKiriSlow(14,25,10);
//		wait(0.1);
//		GetArah(150);
//	} while ((ARAH != BARAT || JarakBelakang<30)&& !ApiSekitar(70)&&!ApiUjung(70) );
//	int sudutNow = kompas.readBearing();
//
//	if(!ApiSekitar(70)||!ApiUjung(70)){
//		DisplayLCD("SCAN LAGI");
//		PutarKiri(70);
//			wait(0.3);
//
//			LCD.printf("PUTARKANAN");
//			do {
//				PutarKanan(40);
//				wait(0.1);
//				//LCD.printf("%d", kompas.readBearing());
//			}while (kompas.readBearing()<sudutNow+300 && !ApiSekitar(70)&&!ApiUjung(70));//
//	}
//	if(kompas.readBearing()>sudutNow+300){
//		ResetArah();
//		PutarSampaiArah(SELATAN);
//
//	do{
//		wallKiriApi(11,25,10);
//		wait(0.1);
//	}while(!ApiSekitar(70)&&!ApiUjung(70));
//	}
//	ArahkanKeApi(70);
//	DisplayLCD("sekitar api");
//	QuickStop();
//	wait(2);
//
//	DisplayLCD("mendekati api");
//	sikatLilin(145,3,6);
////	QuickStop();
////	wait(0.1);
////	putarKeApi(150);//putar ke arah api
////	QuickStop();
////	wait(0.1);
////
////	DisplayLCD("Matikan Api R2");
////	matikanApi();
////	wait(2);
////	if(UV2.Flag==1){
////		matikanApi();
////		wait(1);
////	}
//	//while(UV2.Flag){
////		matikanApi();
////		wait(0.5);
//	//}
//	QuickStop();
//}

//void PadamkanApiR2() {
//	DisplayLCD("Wall s.d. Api");
//	DisplayLCD("Api R2");
//	PutarSampaiArahIR(TIMUR);
////	MajuLurus(40);
////	wait(1.1);
////	MundurLurus(30);
////	wait(0.6);
//	ResetArah();
//	do {
//		wallKiriApi(11,25,10);
//		wait(0.1);
//	} while (!(JarakDepan < 14 &&JarakSRKiri < 17 && JarakKiri < 13));
//	LCD.printf("POJOK");
//	QuickStop();
//	wait(0.1);
//	ResetArah();
//	PutarSampaiArah(SELATAN);
//	while(JarakKiri>9){
//		GeserKiri(30);
//		wait(0.1);
//	}
//	KoreksiArahIR();
//
////    if(JarakKiri>9){
////
////	}
//	MajuLurus(30);
//	wait(0.6);
////	for (int i =1 ; i<=7; i++){
////		wallKiriApi(11,25,10);
////		wait(0.1);
////	}
//
//	ResetArah();
//	PutarSampaiArahIR(SELATAN);
//
//	PutarKiri(70);
//	wait(0.3);
//	LCD.printf("PUTARKANAN");
//	do {
//
//		PutarKanan(40);
//		wait(0.1);
//		LCD.printf("%d", kompas.readBearing());
//	}while (kompas.readBearing()<(THSelatan+THBarat)/2 && !ApiSekitar(70)&&!ApiUjung(70));//
//
//	LCD.cls();
//	if(!kompas.readBearing()<(THSelatan+THBarat)/2){
//		LCD.printf("Sel-Bar");
//		ResetArah();
//		PutarSampaiArah(SELATAN);
//		do{
//			GeserKiri(30);
//			wait(0.1);
//		}while(JarakKiri>9);
//	}else if (ApiSekitar(70)){
//		LCD.printf("tengah");
//	}else if (ApiUjung(90)) {
//		LCD.printf("ujung");
//	}
//
//
//	if(!ApiSekitar(70)){
//		ResetArah();
//		PutarSampaiArah(SELATAN);
//		QuickStop();
//		wait (0.1);
//		do {
//			wallKiriApi(11,25,10);
//			wait(0.1);
//		} while (!ApiSekitar(70)&&!ApiUjung(70));
//
//
//	}
//	ArahkanKeApi(70);
//	DisplayLCD("sekitar api");
//	QuickStop();
//	wait(2);
//
//	DisplayLCD("mendekati api");
//	sikatLilin(145,3,6);
////	QuickStop();
////	wait(0.1);
////	putarKeApi(150);//putar ke arah api
////	QuickStop();
////	wait(0.1);
////
////	DisplayLCD("Matikan Api R2");
////	matikanApi();
////	wait(2);
////	if(UV2.Flag==1){
////		matikanApi();
////		wait(1);
////	}
//	//while(UV2.Flag){
////		matikanApi();
////		wait(0.5);
//	//}
//	QuickStop();
//}

void PadamkanApiR3() {
	ArahWall = KIRI;
	int sudutNow;
	DisplayLCD("Wall s.d. Api");
	DisplayLCD("Api R3");
	ResetArah();
	PutarSampaiArah(SELATAN,50);
	do {
		GeserKiri(30);
		wait(0.1);
	} while (JarakKiri > 8);
	do {
		wallKiriApi(11,25,10);
		wait(0.1);
		GetArah(250);
	} while (!ApiSekitar(70)&&!ApiUjung(90));

//	if(ARAH==BARAT){
//		DisplayLCD("udh BARAT");
//		ResetArah();
//		PutarSampaiArahIR(BARAT);
//		sudutNow = kompas.readBearing();
//		do{
//			MundurLurus(15);
//			wait(0.1);
//		}while(JarakBelakang>13);
//		PutarKiri(70);
//		wait(0.3);
//		QuickStop();
//		do{
//			PutarKanan(40);
//			wait(0.1);
//		}while(kompas.readBearing()<(sudutNow+300) && !ApiSekitar(70) && !ApiUjung(90));
//		QuickStop();
//		wait(0.1);
//
//		if(kompas.readBearing()>=sudutNow+300){
//			PutarSampaiArahIR(BARAT);
//			do {
//				wallKiriApi(11,25,10);
//				wait(0.1);
//				GetArah(250);
//			} while (!ApiSekitar(70)&& !ApiUjung(90));
//		}
//	}
	DisplayLCD("sekitar api");
	QuickStop();
	wait(0.1);
	ArahkanKeApi(60);

	sikatLilin(140,3,8);

//	DisplayLCD("mengarah ke api");
//	putarKeApi(150);//putar ke arah api
//	QuickStop();
//	wait(0.1);
//
//	DisplayLCD("Matikan Api R3");
//	while(UV2.Flag){
//		matikanApi();
//		wait(0.5);
//	}
	QuickStop();
}

void PadamkanApiR4A() {
	// Hadap ke api
	ResetArah();
	PutarSampaiArah(SELATAN,AUTO,100);
	do{
		MajuLurus(25);
		wait(0.1);
	}while(JarakPingDepan>20);
	while (JarakKiri < 18) {
		GeserKanan(30);
		wait(0.1);
	}
//	PutarSampaiArah(TIMUR);
//		int sudutNow = kompas.readBearing();
//		QuickStop();
//		wait(0.1);
//		do{
//			PutarKanan(100);
//			wait(0.1);
//		}while(kompas.readBearing()<sudutNow+300);
		QuickStop();
//		wait(1);
		PutarKiri(120);
		wait(0.5);
		QuickStop();
	wait(0.1);
	while (!ApiSekitar(60)&&!ApiUjung(60)) {
		PutarKanan(50);
		wait(0.1);
	}
	ArahkanKeApi(60);
	sikatLilin(143,3,8);

//	putarKeApi2(150);
//	QuickStop();
//
//	DisplayLCD("Matikan Api R4A");
//	while(UV2.Flag){
//		matikanApi();
//		wait(0.5);
//	}
	QuickStop();
}

void PadamkanApiR4B() {
	// Hadap ke api
	do{
		MajuLurus(25);
		wait(0.1);
	}while(JarakPingDepan>20);
	QuickStop;
	while (JarakKiri < 18) {
		GeserKanan(30);
		wait(0.1);
	}
	QuickStop();
	wait(0.1);
	ResetArah();
	PutarKiri(150);
	wait(0.7);
	QuickStop();

//	PutarSampaiArah(BARAT);
//	int sudutNow = kompas.readBearing();
//	QuickStop();
//	wait(0.1);
//	do{
//		PutarKanan(100);
//		wait(0.1);
//	}while(kompas.readBearing()<sudutNow+300);
	//QuickStop();
	wait(0.5);
	while (!ApiSekitar(60)&&!ApiUjung(60)) {
		PutarKanan(40);
		wait(0.1);
	}
	ArahkanKeApi(50);
	sikatLilin(140,3,8);

	// Bergerak pelan-pelan menuju api
//	while (!ApiSekitarTengah(150)) {
//		int t_tengah = MaxApiTengah();
//		int t_kiri = MaxApiKiri();
//		int t_kanan = MaxApiKanan();
//
//		if (t_tengah > t_kiri && t_tengah > t_kanan) {
//			MajuLurus(25);
//		} else if (t_kiri > t_tengah && t_kiri > t_kanan) {
//			PutarKanan(30);
//		} else {
//			PutarKiri(30);
//		}
//		wait(0.1);
//	}
//	putarKeApi(140);
//	QuickStop();
//	wait(0.1);
//	DisplayLCD("Matikan Api R4B");
//	while(UV2.Flag){
//		matikanApi();
//		wait(0.5);
//	}
	QuickStop();
}
