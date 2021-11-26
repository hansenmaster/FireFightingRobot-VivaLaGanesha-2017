// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Display.h
// author/editor : Babang
// created on : 09 Maret 2016
// Desc : Tampilan pda LCD dan Serial PC


#include "Display.h"

void DisplayClear()
{
    LCD.cls();
}

void DisplaySound()
{
    if (Suara==0)
    {
        LCD.locate(6,0);
        LCD.printf("S");    
    }
    else
    {
        LCD.locate(6,0);
        LCD.printf("O"); 
    }
}


void DisplayGaris(){
//	LCD.locate(0,1);
//	if(GarisDepan==PUTIH){
//		LCD.printf("P");
//	}else if(GarisDepan == HITAM){
//		LCD.printf("H");
//	}
//	LCD.locate(2,1);
//	if(GarisBelakang==PUTIH){
//		LCD.printf("P");
//	}else if(GarisBelakang == HITAM){
//		LCD.printf("H");
//	}
//	LCD.locate (4,1);
//	LCD.printf("%d",kompas.readBearing());
//
}

void DisplayPADAMKANAPI(){
	LCD.locate(1,0);
	LCD.printf("PADAMKAN API");
}

void DisplayBACKHOME(){
	LCD.locate(1,0);
	LCD.printf("BACKHOME");
}
void DisplayFINISH(){
	DisplayClear();
	LCD.locate(1,0);
	LCD.printf("MISSION SUCCESS");
}

void DisplayPintu(){
	LCD.locate(8,0);
	DisplayClear();
	const char* temp;
	switch(pintu.back()){
		case MasukR1A:
//			LCD.printf("MR1A");
			temp = "MR1A";
//			PC.printf("MR1A|");
			break;
		case MasukR1B:
//			LCD.printf("MR1B");
			temp = "MR1B";
//			PC.printf("MR1B|");
			break;
		case MasukR1C:
//			LCD.printf("MR1C");
			temp = "MR1C";
//			PC.printf("MR1C|");
			break;
		case MasukR2:
//			LCD.printf("MR2 ");
			temp = "MR2 ";
//			PC.printf("MR2 |");
			break;
		case MasukR3:
//			LCD.printf("MR3 ");
			temp = "MR3 ";
//			PC.printf("MR3 |");
			break;
		case MasukR4A:
//			LCD.printf("MR4A");
			temp = "MR4A";
//			PC.printf("MR4A|");
			break;
		case MasukR4B:
//			LCD.printf("MR4B");
			temp = "MR4B";
//			PC.printf("MR4B|");
			break;

		case KeluarR1A:
//			LCD.printf("KR1A");
			temp = "KR1A";
//			PC.printf("KR1A|");
			break;
		case KeluarR1B:
//			LCD.printf("KR1B");
			temp = "KR1B";
//			PC.printf("KR1B|");
			break;
		case KeluarR1C:
//			LCD.printf("KR1C");
			temp = "KR1C";
//			PC.printf("KR1C|");
			break;
		case KeluarR2:
//			LCD.printf("KR2 ");
			temp = "KR2 ";
//			PC.printf("KR2 |");
			break;
		case KeluarR3:
//			LCD.printf("KR3 ");
			temp = "KR3 ";
//			PC.printf("KR3 |");
			break;
		case KeluarR4A:
//			LCD.printf("KR4A");
			temp = "KR4A";
//			PC.printf("KR4A|");
			break;
		case KeluarR4B:
//			LCD.printf("KR4B");
			temp = "KR4B";
//			PC.printf("KR4B|");
			break;
		default:
//			LCD.printf("????");
			temp = "????";
//			PC.printf("????|");
			break;
	}
	LCD.printf(temp);
	PC.printf(temp);
}

void DisplayPosisi(){
	LCD.locate(0,1);
	if(Posisi == R1){
		LCD.printf("Ruang 1");
	}
	else if (Posisi == R2) {
		LCD.printf("Ruang 2");
	}
	else if (Posisi == R3) {
		LCD.printf("Ruang 3");
	}
	else if (Posisi == R4) {
		LCD.printf("Ruang 4");
	}
	else if (Posisi == LORONGBARAT) {
		LCD.printf("LORONGBARAT");
	}
	else if (Posisi == LORONGTIMUR) {
		LCD.printf("LORONGTIMUR");
	}
}

void DisplayKompas(){
	LCD.locate(15,0);
	GetArahMax();
	//GetArah(KompasToleransiBesar);
	if(ARAH==UTARA){
		LCD.printf("U");
	}else if(ARAH==BARAT){
		LCD.printf("B");
	}else if(ARAH==SELATAN){
		LCD.printf("S");
	}else if(ARAH==TIMUR){
		LCD.printf("T");
	}
//	LCD.locate(11,0);
//	LCD.printf((char*)kompas.readBearing());
}

void DisplayTombolDepan(){
	PC.printf("\tTombol Depan: %d %d",TombolDepanKiri, TombolDepanKanan);
}

void DisplaySETAWAL(){
    DisplayClear();
    LCD.locate(0,0);
    LCD.printf("SETAWAL");
}

void DisplayINIT(){
    DisplayClear();
    LCD.locate(0,0);
    LCD.printf("INISIALISASI");
    LCD.locate(0,1);
    LCD.printf("SOUND-nya DONG");
}

void DisplayDEBUG(){
    DisplayClear();
    LCD.locate(0,0);
    LCD.printf("DEBUG");
}

void DisplayMULAI(){
    DisplayClear();
    LCD.locate(0,0);
    LCD.printf("MULAI");
}

void DisplayJELAJAH(){
    DisplayClear();
    LCD.locate(0,0);
    LCD.printf("JELAJAH");
}

void DisplayLCD(const char* input) {
	DisplayClear();
	wait(0.1);
	LCD.locate(0,0);
	LCD.printf(input);
}

void DisplaySound_PC()
{
	PC.printf(" SOUND: ");
	if (Suara==0)
	{
	   PC.printf("YES ");
	}
	else
	 {
	   PC.printf("NO ");
	 }
}


void DisplayPing_PC()
{
	PC.printf("\t PING = %d",JarakPingDepan);
}
void DisplayGaris_PC(){
   // PC.printf("G1: %d |Gr2: %d|", ADCGarisDepan, ADCGarisBelakang);
}

void DisplayTombol_PC(){
    PC.printf(" RESET: %d\tLED: %d\t\tKALIBRASI: %d\tENKIPAS: %d", TombolReset, LEDAtas, TombolKalKompas, motor1.read());
}   

void DisplayRoom_PC(){
    int i;
    for (i=1;i<5;i++)
    {
        PC.printf("Masuk\t: %d %d\n",i,masuk[i]);
        PC.printf("Keluar\t: %d %d\n",i,keluar[i]);
        wait(0.5);
    }
}
void DisplayTPA81_PC(){
    PC.printf("TPAX: ");
    for (unsigned char i=0; i<8; i++){
        PC.printf("%d ", tpa_0.getTemp(i+1));
    }
    PC.printf("|");
    PC.printf("TPAY: ");
    for (unsigned char i=0; i<8; i++){
        PC.printf("%d ", tpa_2.getTemp(i+1));
    }
    PC.printf("|");
}

void DisplayOnlyTPA81_PC(){
	PC.printf(" ========== TPA ========\n");
    PC.printf(" TPA_0 : ");
    for (unsigned char i=1; i<=8; i++){
        PC.printf("%d ", tpa_0.getTemp(i+1));
    }
    PC.printf("\n");
    PC.printf(" TPA_2 : ");
    for (unsigned char i=1; i<=8; i++){
        PC.printf("%d ", tpa_2.getTemp(i+1));
    }
    PC.printf("\n");
    PC.printf(" TPA_4 : ");
    for (unsigned char i=1; i<=8; i++){
        PC.printf("%d ", tpa_4.getTemp(i+1));
    }
    PC.printf("\n");
    PC.printf(" TPA_6 : ");
    for (unsigned char i=1; i<=8; i++){
        PC.printf("%d ", tpa_6.getTemp(i+1));
    }
    PC.printf("\n");
    PC.printf(" TPA_8 : ");
    for (unsigned char i=1; i<=8; i++){
        PC.printf("%d ", tpa_8.getTemp(i+1));
    }
    PC.printf("\n");
    PC.printf(" TPA_A : ");
    for (unsigned char i=1; i<=8; i++){
        PC.printf("%d ", tpa_A.getTemp(i+1));
    }
    PC.printf("\n\n");
}

void DisplayUV_PC(){
    PC.printf("\tUVTRON: %d %d", UV1.Flag, UV2.Flag);
}

void DisplayCMPS_PC(){
    PC.printf("\tKOMPAS: %d", kompas.readBearing());
}

void DisplayEnter(){
    PC.printf("\n");
}

void DisplayNextData_PC(){
	PC.printf("\n##################################################\n\n\n");
}

void DisplayOnlyIR_PC(){
	PC.printf(" \n========INFRARED========\n"
			"         %d\n\n"
			"    %d        %d\n\n"
			" %d               %d\n\n"
			"    %d        %d\n\n"
			"         %d\n"
			, JarakDepan, JarakSRKiri, JarakSRKanan, JarakKiri, JarakKanan, JarakSBKiri, JarakSBKanan, JarakBelakang);
}
void DisplayOnlyGaris_PC(){
//    PC.printf("\n========Garis=========\n"
//    		"\t%d\n\n"
//    		"%d\t%d\t%d\n\n"
//    		"\t%d\n", ADCGarisDepan, ADCGarisTengahKiri, ADCGarisTengah ,ADCGarisTengahKanan,ADCGarisBelakang);
}
void DisplayIR_Garis(){
	PC.printf("\n||===== INFRARED =======||======== GARIS =========\n"
				"||         %d\t\t||  %d    \t    %d\n"
				"\n"
				"||    %d        %d\t||  \t    %d\n"
				"\n"
				"|| %d               %d\t||  %d    \t    %d\n"
				"\n"
				"||    %d        %d\t||\n"
				"\n"
				"||         %d\t\t||\n\n"
			, JarakDepan,ADCGarisDepanKiri,ADCGarisDepanKanan,
			JarakSRKiri, JarakSRKanan, ADCGarisTengah,
			JarakKiri, JarakKanan, ADCGarisBelakangKiri,ADCGarisBelakangKanan,
			JarakSBKiri, JarakSBKanan,
			JarakBelakang);
	PC.printf("\f");
}
void DisplayADC_PC(){
	PC.printf("\nADC = %d",totalADC());
}

void DisplayTotal_PC(){
	PC.printf("\n##################################################");
    DisplayIR_Garis();
    DisplayOnlyTPA81_PC();
    DisplaySound_PC();
    DisplayCMPS_PC();
    DisplayUV_PC();
    DisplayTombolDepan();
    DisplayEnter();
    DisplayTombol_PC();
    //PC.printf("\t");
    //DisplayPintu();
    DisplayPing_PC();
    DisplayADC_PC();
    DisplayNextData_PC();
}

