#ifndef GERAKAN_H
#define GERAKAN_H

#include "mbed.h"
#include "ObjectVariabel.h"

#define KANAN				1	// arah putaran
#define KIRI 				2
#define AUTO				0
#define SAMPINGPINTU		0
#define DEPANPINTU          1

extern float maxJarakDepan();
extern void KoreksiArahIR();
extern void PutarSampaiArah(char ArahTujuan, char ArahPutar = 0, int Toleransi = 100);
extern void PutarSampaiArahIR(char ArahTujuan, char ArahPutar = 0, int Toleransi = 100);
extern void PutarBalik();
extern void HindarFurniture(char ArahPutar = 0);
extern void HindarFurnitureApi();
extern void HindarFurnitureApi2();
extern void HindarFurnitureWallApi(char ArahPutar);


extern float avgJarakDepan();

#endif
