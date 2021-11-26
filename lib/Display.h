// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : Display.cpp
// author/editor : Babang
// created on : 09 Maret 2016
// Desc : Tampilan pda LCD dan Serial PC

#ifndef DISPLAY_H
#define DISPLAY_H

#include "mbed.h"
#include "ObjectVariabel.h"


// display IR, uvtron, dan suara
void DisplayIR_UV_S();
void DisplayGaris();

//tampilan LCD
// mode
extern void DisplayPADAMKANAPI();
extern void DisplaySETAWAL();
extern void DisplayINIT();
extern void DisplayMULAI();
extern void DisplayJELAJAH();
extern void DisplayBACKHOME();
extern void DisplayDEBUG();
extern void DisplayFINISH();
extern void DisplayKompas();
extern void DisplayTombolDepan();

extern void DisplayClear();
extern void DisplaySound();
extern void DisplayPintu();
extern void DisplayPosisi();

extern void DisplayLCD (const char* input);

//tampilan serial
extern void DisplaySound_PC();
extern void DisplayRoom_PC();
extern void DisplayOnlyGaris_PC();
extern void DisplayGaris_PC();
extern void DisplayTombol_PC();
extern void DisplayOnlyTPA81_PC();
extern void DisplayTPA81_PC();
extern void DisplayOnlyIR_PC();
extern void DisplayUV_PC();
extern void DisplayCMPS_PC();
extern void DisplayEnter();
extern void DisplayIR_GARIS();
extern void DisplayTotal_PC();
extern void DisplayNextData_PC();

#endif


