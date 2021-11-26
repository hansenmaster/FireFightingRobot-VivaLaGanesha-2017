// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : wallfollowing.cpp
// author/editor : Babang
// created on : 10 Maret 2016
// Desc : Mengatur gerakan dasar dan wallfollow

#ifndef WALLFOLLOWING_H
#define WALLFOLLOWING_H
#include "mbed.h"
#include "ObjectVariabel.h"

extern void wallKananSlow(int SetPointJarak, int Kp,int Kd);
extern void wallKanan(int SetPointJarak, int Kp,int Kd);
extern void wallKananApi(int SetPointJarak, int Kp,int Kd);
extern void wallKiriApi(int SetPointJarak, int Kp,int Kd);
extern void wallKananCepat(int SetPointJarak, int Kp,int Kd);
extern void wallKiri(int SetPointJarak, int Kp,int Kd);
extern void wallKiriA(int SetPointJarak, int Kp,int Kd);
extern void wallKanan2A(int SetPointJarak, int Kp,int Kd);
extern void wallKiri2(int SetPointJarak, int Kp,int Kd);
extern void wallKiriSlow(int SetPointJarak, int Kp,int Kd);
extern void wallKiri2B(int SetPointJarak, int Kp,int Kd);
extern void wallKiri3(int SetPointJarak, int Kp,int Kd);
extern void wallKanan2(int SetPointJarak, int Kp,int Kd);
extern void wallKanan3(int SetPointJarak, int Kp,int Kd);
extern void wallKiri();
extern void putar180();
extern void putarKanan90();
extern void putarKiri90();


#endif


