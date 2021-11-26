#ifndef INVERSKINEMATIC_H
#define INVERSKINEMATIC_H

#include "mbed.h"
#include "ObjectVariabel.h"
#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;

//----------------DEFINITION---------------*/
#define TRUE    1
#define FALSE   0
#define ON      1
#define OFF     0

//definisi indeks setiap kaki
#define RF          0   //Right Front
#define RM          1   //Right Middle
#define RR          2   //Right Rear
#define LF          3   //Left Front
#define LM          4   //Left Middle
#define LR          5   //Left Rear
/*------------[SERVO IDs]----------*/
#define Coxa  100
#define Femur 102
#define Tibia 101

#define RFCoxaPin       4
#define RFFemurPin      5
#define RFTibiaPin              6
    
#define RMCoxaPin       10
#define RMFemurPin      11
#define RMTibiaPin              12

#define RRCoxaPin       16
#define RRFemurPin      17
#define RRTibiaPin              18
            
#define LFCoxaPin       1
#define LFFemurPin      2
#define LFTibiaPin              3
    
#define LMCoxaPin       7
#define LMFemurPin      8
#define LMTibiaPin              9
            
#define LRCoxaPin       13
#define LRFemurPin      14
#define LRTibiaPin              15


//dimensi robot dalam mm
#define CoxaLength	42
#define FemurLength 30
#define TibiaLength 110
#define offsettibia 50 //dikurang dalem
#define offsetfemur 50 //ditambah turun
//offset X,Y,Z dalam kerangka koordinat pusat badan robot
//offset X,Y,Z dalam kerangka koordinat pusat badan robot
#define RFOffsetX   -32  
#define RFOffsetZ   -73
#define RFOffsetY   -37 

#define RMOffsetX   -32  
#define RMOffsetZ 	0
#define RMOffsetY   -37

#define RROffsetX   -32  
#define RROffsetZ  	73
#define RROffsetY  	-37 

#define LFOffsetX  	32   
#define LFOffsetZ   -73
#define LFOffsetY   -37
 
#define LMOffsetX  	32  
#define LMOffsetZ 	0
#define LMOffsetY   -37
 
#define LROffsetX  	32   
#define LROffsetZ  	73
#define LROffsetY   -37  

#define RFCoxaAngleOffset		-450
#define RMCoxaAngleOffset		0
#define RRCoxaAngleOffset		450
#define LFCoxaAngleOffset		-450
#define LMCoxaAngleOffset		0
#define LRCoxaAngleOffset		450

/*--------[MIN/MAX ANGLE]-------------------*/
//angle dalam derajat*10
#define RFCoxaAngleMin      -450        
#define RFCoxaAngleMax      200
#define RFFemurAngleMin     -900
#define RFFemurAngleMax     900
#define RFTibiaAngleMin     -800
#define RFTibiaAngleMax     900

#define RMCoxaAngleMin      -250        
#define RMCoxaAngleMax      250
#define RMFemurAngleMin     -900
#define RMFemurAngleMax     900
#define RMTibiaAngleMin     -800
#define RMTibiaAngleMax     900

#define RRCoxaAngleMin      -200        
#define RRCoxaAngleMax      450
#define RRFemurAngleMin     -900
#define RRFemurAngleMax     900
#define RRTibiaAngleMin     -800
#define RRTibiaAngleMax     900

#define LFCoxaAngleMin      -450        
#define LFCoxaAngleMax      200
#define LFFemurAngleMin     -900
#define LFFemurAngleMax     900
#define LFTibiaAngleMin     -800
#define LFTibiaAngleMax     900

#define LMCoxaAngleMin      -250        
#define LMCoxaAngleMax      250
#define LMFemurAngleMin     -900
#define LMFemurAngleMax     900
#define LMTibiaAngleMin     -800
#define LMTibiaAngleMax     900

#define LRCoxaAngleMin      -200        
#define LRCoxaAngleMax      450
#define LRFemurAngleMin     -900
#define LRFemurAngleMax     900
#define LRTibiaAngleMin     -800
#define LRTibiaAngleMax     900

/*--------------[GAIT TIMING]---------------*/
#define MinGaitTravelTime       70
#define ApproxCalculationDelay  1
//extern Serial PC;
extern int 	updatetimer;
extern Timer 	t;
extern Ticker 	timer;
void 	attime(); 		// Realisasinya ada di paling bawah
/*-------------[Constant Variables]-----------*/
extern int	CoxaPin[6]			;
extern int	FemurPin[6]        ;
extern int TibiaPin[6]         ;
extern float OffsetX[6]        	;
extern float OffsetZ[6]          ;
extern int CoxaAngleOffset[6]  ;
extern int CoxaAngleMin[6]     ;
extern int CoxaAngleMax[6]     ;
extern int FemurAngleMin[6]    ;
extern int FemurAngleMax[6]    ;
extern int TibiaAngleMin[6]    ;
extern int TibiaAngleMax[6]    ;
/*--------[POSISI SUDUT SEBENARNYA]-----------------*/
extern int CoxaAngle[6];				//sudut coxa    
extern int FemurAngle[6];  			//sudut femur
extern int TibiaAngle[6];      		//sudut tibia
extern int LegPosX[6];         		//posisi end of effector terhadapa sumbu-X
extern int LegPosY[6];					//posisi end of effector terhadapa sumbu-Y
extern int LegPosZ[6];					//posisi end of effector terhadapa sumbu-Z
extern float BodyHeight			;	//tinggi badan relatif terhadap tanah 
extern int LegRadius          ;	//jangkauan kaki diukur dari posisi tengah badan
extern int NormCoxaAngle       ;	//sudut coxa awal
/*------------------[INVERSE KINEMATICS]----------------------*/
extern float        BodyPosX;       
extern float        BodyPosY;       
extern float        BodyPosZ;       
extern float        BodyRotX;       //Pitch
extern float        BodyRotY;       //Yaw
extern float        BodyRotZ;       //Roll
extern float        InBodyPosX;       
extern float        InBodyPosY;       
extern float        InBodyPosZ;       
extern float        InBodyRotX;       //Pitch
extern float        InBodyRotY;       //Yaw
extern float        InBodyRotZ;       //Roll	
extern float        PrevBodyPosX;       
extern float        PrevBodyPosY;       
extern float        PrevBodyPosZ;       
extern float        PrevBodyRotX;       //Pitch
extern float        PrevBodyRotY;       //Yaw
extern float        PrevBodyRotZ;       //Roll	
extern float 			 Rot_X  ;
extern float 			 Rot_Y  ;
extern float 			 Rot_Z  ;	
extern float 			 Shift_X;
extern float 			 Shift_Z;	
extern float        BodyIKPosX;     
extern float        BodyIKPosY;     
extern float        BodyIKPosZ;     
extern float        BodyShift;
extern float        RollPitchYawAngle;  

extern unsigned char done;
/*-------------------------[GAIT]------------------------------*/
extern unsigned char  GaitType;               

extern int            LegLiftHeight        ;       
extern int            TravelLengthX;          
extern int            TravelLengthZ;          
extern int            TravelRotation;        
extern int            TravelLength;
extern unsigned char  NrLiftedPos;            
extern unsigned char  TLDivFactor;            
extern unsigned char  StepsInGait;            
extern bool           HalfLiftHeigth;             
extern unsigned char  GaitStep;               
extern unsigned char  GaitLegNr[6];           
extern bool           GaitInMotion;           
extern bool           LastLeg;                
extern int            GaitPosX[6];            
extern int            GaitPosY[6];
extern int            GaitPosZ[6];
extern int            GaitRotY[6];            
extern char           GaitSequencerOn     	;
extern char           Ready               	;

extern float InTravelLengthZ;
extern float InTravelLengthX;
extern float InTravelRotation;

/*SSC*/
extern char           AllServosFree       	;
extern char           DirectSSCControl    	;
/*-----------------------TIMING-------------------------------*/
extern unsigned int   GaitTravelTime      	;
extern unsigned int   FrameTime           	; 
extern unsigned int   SpeedServo			;

extern unsigned char   state ;
extern unsigned char   state_static ;
extern unsigned char   first;
extern float           iter ;
extern float           iter2;
extern unsigned char   stop;
extern unsigned char   stop2;
extern unsigned char   seq;
/*---------------------[SERIAL COMMAND]-----------------------*/
extern unsigned char   CurrSerialCommand       ;
extern unsigned char   PrevSerialCommand1      ;
extern unsigned char   PrevSerialCommand2      ;
/*----------------[DIFFERENTIAL STEERING]----------------------*/
extern int             DiffSteerTravelLength;
extern int             DiffSteerTravelRotation;
extern int             LeftLegsToRightLegsDistance;
extern int             TurnPercentage;

extern int elapsedtime;
/*-----------------[GAIT CALCULATION]--------------------------*/
void GaitCalculation (unsigned char GaitCurrentLegNr);

/*--------------------[GAIT SEQUENCER]-------------------*/
void StartSequencer(void);
void StopSequencer(void);
void GaitSequencer (void);

/*-----------------------------[BODY INVERSE KINEMATICS]-----------------------------*/
void BodyIK (float PosX, float PosZ, float PosY, float RotationY, unsigned char BodyIKIndex);

/*------------------------------[LEG INVERSE KINEMATICS]-----------------------------*/
void LegIK (float IKFeetPosX, float IKFeetPosY, float IKFeetPosZ, unsigned char LegIKIndex);
void IKCalculation (void);

/*-----------------------------[CHECK ANGLES]---------------------------*/
void CheckAngles (void);
void ServoDriver (unsigned int persen_kecepatan);

/*-------------------[DO DYNAMIC MOVEMENT]------------------------*/
void DoDynamicMovement (void);

/*-------------------[DO STATIC MOVEMENT]-----------------------*/
void DoStaticMovement (void);

void DoStaticMovementParam(float RotX,float RotY,float RotZ,float ShiftX,float ShiftZ);

/*------------------------[GAIT SELECT]------------------------*/
void GaitSelect (unsigned char Type);

//[SET BODY HEIGHT]
void SetBodyHeight (int BodyHeightInput);

//--------------------------------------------------------------------
//[SET LEG LIFT HEIGHT]
void SetLegLiftHeight (int LegLiftHeightInput);

//--------------------------------------------------------------------
//[SET FRAME TIME]
void SetFrameTime (unsigned int FrameTimeInput);

//--------------------------------------------------------------------
//[GET READY]
void GetReady (int LegRadiusInput, int NormCoxaAngleInput);

//--------------------------------------------------------------------
//[SET TRAVEL SPEED]
void SetTravelSpeed (unsigned int TravelSpeedPercentage);

//--------------------------------------------------------------------
//[TRAVEL LENGTH CHECK]
void TravelLengthCheck (void);

//--------------------------------------------------------------------
//[MAJU LURUS]
void MajuLurus (int TravelLengthInput);

//--------------------------------------------------------------------
//[MUNDUR LURUS]
void MundurLurus (int TravelLengthInput);

//--------------------------------------------------------------------
//[GESER KANAN]
void GeserKanan (int TravelLengthInput);

//--------------------------------------------------------------------
//[GESER KIRI]
void GeserKiri (int TravelLengthInput);        

//--------------------------------------------------------------------
//[MAJU SERONG KANAN]
void MajuSerongKanan (int TravelLengthInput);

//--------------------------------------------------------------------
//[MAJU SERONG KIRI]
void MajuSerongKiri (int TravelLengthInput);

//--------------------------------------------------------------------
//[MUNDUR SERONG KANAN]
void MundurSerongKanan (int TravelLengthInput);

//--------------------------------------------------------------------
//[MUNDUR SERONG KIRI]
void MundurSerongKiri (int TravelLengthInput); 

//--------------------------------------------------------------------
//[TRAVEL ROTATION CHECK]
void TravelRotationCheck (void);

//--------------------------------------------------------------------
//[PUTAR KANAN]
void PutarKanan (int TravelRotationInput);

//--------------------------------------------------------------------
//[PUTAR KIRI]
void PutarKiri (int TravelRotationInput);

//--------------------------------------------------------------------
//[TURN PERCENTAGE CHECK]
void TurnPercentageCheck (void);

//--------------------------------------------------------------------
//[DIFFERENTIAL STEERING]
void DifferentialSteering (int DiffSteerTurnPercentageInput);

//--------------------------------------------------------------------
//[MAJU BELOK KANAN]
void MajuBelokKanan (int TurnPercentageInput);

//--------------------------------------------------------------------
//[MAJU BELOK KIRI]
void MajuBelokKiri (int TurnPercentageInput);

//--------------------------------------------------------------------
//[MUNDUR BELOK KANAN]
void MundurBelokKanan (int TurnPercentageInput);

//--------------------------------------------------------------------
//[MUNDUR BELOK KIRI]
void MundurBelokKiri (int TurnPercentageInput);

//--------------------------------------------------------------------
//[LINGKAR KANAN DEPAN]
void LingkarKananDepan (int TurnPercentageInput);

//--------------------------------------------------------------------
//[LINGKAR KIRI DEPAN]
void LingkarKiriDepan (int TurnPercentageInput);

//--------------------------------------------------------------------
//[LINGKAR KANAN BELAKANG]
void LingkarKananBelakang (int TurnPercentageInput);

//--------------------------------------------------------------------
//[LINGKAR KIRI BELAKANG]
void LingkarKiriBelakang (int TurnPercentageInput);

//--------------------------------------------------------------------
//[STOP]
void Stop (void);

//--------------------------------------------------------------------
//[QUICKSTOP]
void QuickStop (void);

//--------------------------------------------------------------------
//[ROLL-PITCH-YAW ANGLE CHECK]
void RollPitchYawAngleCheck (void);

//--------------------------------------------------------------------
//[TENGOK KANAN]
void TengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[TENGOK KIRI]
void TengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING DEPAN] = [TENGOK BAWAH]
void MiringDepan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING BELAKANG] = [TENGOK ATAS]
void MiringBelakang (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[TENGOK ATAS]
void TengokAtas (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[TENGOK BAWAH]
void TengokBawah (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN]
void MiringKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI]
void MiringKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN DEPAN]
void MiringKananDepan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI DEPAN]
void MiringKiriDepan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN BELAKANG]
void MiringKananBelakang (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI BELAKANG]
void MiringKiriBelakang (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING DEPAN TENGOK KANAN] = [TENGOK KANAN BAWAH]
void MiringDepanTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[TENGOK KANAN BAWAH]
void TengokKananBawah (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING DEPAN TENGOK KIRI] = [TENGOK KIRI BAWAH]
void MiringDepanTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[TENGOK KIRI BAWAH]
void TengokKiriBawah (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING BELAKANG TENGOK KANAN] = [TENGOK KANAN ATAS]
void MiringBelakangTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[TENGOK KANAN ATAS]
void TengokKananAtas (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING BELAKANG TENGOK KIRI] = [TENGOK KIRI ATAS]
void MiringBelakangTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[TENGOK KIRI ATAS]
void TengokKiriAtas (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN TENGOK KANAN]
void MiringKananTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN TENGOK KIRI]
void MiringKananTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI TENGOK KANAN]
void MiringKiriTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI TENGOK KIRI]
void MiringKiriTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN DEPAN TENGOK KANAN]
void MiringKananDepanTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN DEPAN TENGOK KIRI]
void MiringKananDepanTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI DEPAN TENGOK KANAN]
void MiringKiriDepanTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI DEPAN TENGOK KIRI]
void MiringKiriDepanTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN BELAKANG TENGOK KANAN]
void MiringKananBelakangTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KANAN BELAKANG TENGOK KIRI]
void MiringKananBelakangTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI BELAKANG TENGOK KANAN]
void MiringKiriBelakangTengokKanan (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[MIRING KIRI BELAKANG TENGOK KIRI]
void MiringKiriBelakangTengokKiri (int RollPitchYawAngleInput);

//--------------------------------------------------------------------
//[HADAP NORMAL]
void HadapNormal (void);

//--------------------------------------------------------------------
//[BODY SHIFT CHECK]
void BodyShiftCheck (void);

//--------------------------------------------------------------------
//[LENGGOK DEPAN]
void LenggokDepan (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK BELAKANG]
void LenggokBelakang (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN]
void LenggokKanan (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI]
void LenggokKiri (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN DEPAN]
void LenggokKananDepan (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI DEPAN]
void LenggokKiriDepan (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN BELAKANG]
void LenggokKananBelakang (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI BELAKANG]
void LenggokKiriBelakang (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK ATAS]
void LenggokAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK BAWAH]
void LenggokBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK DEPAN ATAS]
void LenggokDepanAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK BELAKANG ATAS]
void LenggokBelakangAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN ATAS]
void LenggokKananAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI ATAS]
void LenggokKiriAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN DEPAN ATAS]
void LenggokKananDepanAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI DEPAN ATAS]
void LenggokKiriDepanAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN BELAKANG ATAS]
void LenggokKananBelakangAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI BELAKANG ATAS]
void LenggokKiriBelakangAtas (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK DEPAN BAWAH]
void LenggokDepanBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK BELAKANG BAWAH]
void LenggokBelakangBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN BAWAH]
void LenggokKananBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI BAWAH]
void LenggokKiriBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN DEPAN BAWAH]
void LenggokKananDepanBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI DEPAN BAWAH]
void LenggokKiriDepanBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KANAN BELAKANG BAWAH]
void LenggokKananBelakangBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[LENGGOK KIRI BELAKANG BAWAH]
void LenggokKiriBelakangBawah (int BodyShiftInput);

//--------------------------------------------------------------------
//[BERDIRI TENGAH]
void BerdiriTengah (void);

void UpdateGaitTravelTime (void);

void AktifkanModeSetengahTurun();

void AktifkanModeStandard();

void kalibrasiservo(int input);

void SetGlobalSpeed(int input);

void attime();

void Berdiri();

#endif

