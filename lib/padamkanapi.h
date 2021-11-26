// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : padamkanapi.h
// author/editor : Babang
// created on : 28 Maret 2016
// Desc : Algoritma inti, prosedur pemadaman api di setiap ruangan

#ifndef PADAMKANAPI_H
#define PADAMKANAPI_H

#include "mbed.h"
#include "ObjectVariabel.h"



extern void CariApi();
extern char ApiTengah();
extern void GetArah(int THRESHOLD);
extern void GetArahMax();
extern bool ApiUjungKanan(int temp_th);
extern bool ApiUjungKiri(int temp_th);
extern bool ApiUjung(int temp_th);
extern void PadamkanApi();
extern void PadamkanApiR3();
extern void PadamkanApiR2();
extern void PadamkanApiR1A();
extern void PadamkanApiR1B();
extern void PadamkanApiR1C();
extern void PadamkanApiR4A();
extern void PadamkanApiR4B();
extern void ArahkanKeApi(int temp_th);
extern void putarKeApi(int temp_th);
extern void putarKeApi2(int temp_th);
extern bool ApiSekitar(int temp_th);
extern bool ApiSekitarTengah(int temp_th);
extern void PutarApi(int Nkiri, int Nkanan);
extern void matikanApi();
extern void matikanApiRepeat(int x);

#endif
