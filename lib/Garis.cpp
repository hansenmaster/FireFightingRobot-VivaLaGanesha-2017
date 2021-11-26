// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Garis.h
// author/editor : Babang
// created on : 09 Maret 2016
// Desc : Tampilan pda LCD dan Serial PC


#include "Garis.h"

unsigned char StateGaris = 0;

//fungsi untuk membaca sensor garis
void UpdateSensorGaris(){
    ADCGarisDepanKiri = _GrsDepanKiri.read_u16();
    ADCGarisBelakangKiri = _GrsBelakangKiri.read_u16();
    ADCGarisTengah = _GrsMid.read_u16();
    ADCGarisDepanKanan = _GrsDepanKanan.read_u16();
    ADCGarisBelakangKanan = _GrsBelakangKanan.read_u16();


//    cek garis antara hitam abu-abu atau putih
//    garis depan
    if (ADCGarisBelakangKanan<BatasPutih){
    	GarisBelakangKanan =PUTIH;
    }
    else{
    	GarisBelakangKanan =HITAM;
    }

    if (ADCGarisDepanKanan<BatasPutih){
    	GarisDepanKanan =PUTIH;
    }
    else{
    	GarisDepanKanan =HITAM;
    }

    if (ADCGarisTengah<BatasPutih){
    	GarisTengah =PUTIH;
    }
    else{
    	GarisTengah =HITAM;
    }

    if (ADCGarisBelakangKiri<BatasPutih){
    	GarisBelakangKiri =PUTIH;
    }
    else{
    	GarisBelakangKiri =HITAM;
    }

    if (ADCGarisDepanKiri<BatasPutih){
    	GarisDepanKiri =PUTIH;
    }
    else{
    	GarisDepanKiri =HITAM;
    }
//    jika keduanya putih berarti home
//    if((GarisDepan == PUTIH)&&(GarisBelakang == PUTIH)){
//    	Posisi = HOME;
//    }
}
int totalADC()
{
	return(ADCGarisBelakangKanan+ADCGarisBelakangKiri+ADCGarisDepanKanan+ADCGarisDepanKiri+ADCGarisTengah);
}
