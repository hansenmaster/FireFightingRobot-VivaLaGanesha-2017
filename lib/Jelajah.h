// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Jelajah.h
// author/editor : Babang
// created on : 27 Maret 2016
// Desc : Algoritma inti, jelajah seluruh ruangan untuk mencari api

#ifndef JELAJAH_H
#define JELAJAH_H
#include "mbed.h"
#include "ObjectVariabel.h"
#include "Gerakan.h"

//extern void UpdatePintu();
//extern void UpdatePosisi();
//extern void JelajahPosisi();
//extern void UpdateArah();
//extern void JelajahHOME();
//extern void JelajahR3();
//extern void JelajahR2();
//extern void JelajahR1();
//extern void JelajahR4();
//extern void JelajahLORONGBARAT();
//extern void JelajahLORONGTIMUR();

extern void keluarRuangan(bool keluar_home);
extern void keluarNormal(bool keluar_home);
extern void wallTerdekat();
extern void wallTerdekat2();
extern void wallTerdekat3();
extern void wallTerdekatStart();
extern void wallTerdekatAntiHome();
extern void wallHome();
extern void lurusGaris();
extern void Pemetaan();
extern void ResetArah ();
extern void CariRuangan();
extern void JelajahR1 ();
extern void JelajahR1C ();
extern void JelajahR2 ();
extern void JelajahR3 ();
extern void JelajahR4A ();
extern void JelajahR4B ();
extern int TotalPutih();
extern int TotalHitam();
extern bool IsGaris();

extern void R1keR2();
extern void R1keR3();
extern void R1keR4();
extern void R1CkeR4();
extern void R1CkeR2();
extern void R2keR1 ();
extern void R2keR3 ();
extern void R2keR4 ();
extern void R3keR1 ();
extern void R3keR2 ();
extern void R3keR4 ();
extern void R4AkeR1 ();
extern void R4AkeR2 ();
extern void R4AkeR3 ();
extern void R4BkeR1 ();
extern void R4BkeR1C ();
extern void R4BkeR2 ();
extern void R4BkeR3 ();
extern void R1keLorongTimur();
extern void LorongTimurkeR4();
extern void R4AkeLorongUtara();
extern void R4BkeLorongUtara();
extern void R4BkeLorongTimur();


extern bool CariApiR1A ();
extern bool CariApiR1B ();
extern bool CariApiR1C ();
extern bool CariApiR2 ();
extern bool CariApiR3 ();
extern bool CariApiR4A ();
extern bool CariApiR4B ();
extern bool LeftRight;
//extern unsigned char LetakApi;


//extern void Latihan();
//extern void LatihanLorongTimur();





#endif

