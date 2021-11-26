#include "InversKinematic.h"

int  updatetimer;
Timer    t;
//Ticker   timer;
//Serial PC(USBTX, USBRX);
/*-------------[Constant Variables]-----------*/
int  CoxaPin[6]          =   {RFCoxaPin,RMCoxaPin,RRCoxaPin,LFCoxaPin,LMCoxaPin,LRCoxaPin};
int  FemurPin[6]         =   {RFFemurPin,RMFemurPin,RRFemurPin,LFFemurPin,LMFemurPin,LRFemurPin};
int TibiaPin[6]         =    {RFTibiaPin,RMTibiaPin,RRTibiaPin,LFTibiaPin,LMTibiaPin,LRTibiaPin};
float OffsetX[6]           =   {RFOffsetX,RMOffsetX,RROffsetX,LFOffsetX,LMOffsetX,LROffsetX};
float OffsetZ[6]          =    {RFOffsetZ,RMOffsetZ,RROffsetZ,LFOffsetZ,LMOffsetZ,LROffsetZ};
int CoxaAngleOffset[6]  =    {RFCoxaAngleOffset,RMCoxaAngleOffset,RRCoxaAngleOffset,LFCoxaAngleOffset,LMCoxaAngleOffset,LRCoxaAngleOffset};
int CoxaAngleMin[6]     =    {RFCoxaAngleMin,RMCoxaAngleMin,RRCoxaAngleMin,LFCoxaAngleMin,LMCoxaAngleMin,LRCoxaAngleMin};
int CoxaAngleMax[6]     =    {RFCoxaAngleMax,RMCoxaAngleMax,RRCoxaAngleMax,LFCoxaAngleMax,LMCoxaAngleMax,LRCoxaAngleMax};
int FemurAngleMin[6]    =    {RFFemurAngleMin,RMFemurAngleMin,RRFemurAngleMin,LFFemurAngleMin,LMFemurAngleMin,LRFemurAngleMin};
int FemurAngleMax[6]    =    {RFFemurAngleMax,RMFemurAngleMax,RRFemurAngleMax,LFFemurAngleMax,LMFemurAngleMax,LRFemurAngleMax};
int TibiaAngleMin[6]    =    {RFTibiaAngleMin,RMTibiaAngleMin,RRTibiaAngleMin,LFTibiaAngleMin,LMTibiaAngleMin,LRTibiaAngleMin};
int TibiaAngleMax[6]    =    {RFTibiaAngleMax,RMTibiaAngleMax,RRTibiaAngleMax,LFTibiaAngleMax,LMTibiaAngleMax,LRTibiaAngleMax};
/*--------[POSISI SUDUT SEBENARNYA]-----------------*/
int CoxaAngle[6];                //sudut coxa
int FemurAngle[6];           //sudut femur
int TibiaAngle[6];           //sudut tibia
int LegPosX[6];              //posisi end of effector terhadapa sumbu-X
int LegPosY[6];                  //posisi end of effector terhadapa sumbu-Y
int LegPosZ[6];                  //posisi end of effector terhadapa sumbu-Z
float BodyHeight           = 45;   //tinggi badan relatif terhadap tanah
int LegRadius           = 90;    //jangkauan kaki diukur dari posisi tengah badan
int NormCoxaAngle       = 50;    //sudut coxa awal
/*------------------[INVERSE KINEMATICS]----------------------*/
float             BodyPosX=0;
float             BodyPosY=0;
float             BodyPosZ=0;
float             BodyRotX=0;       //Pitch
float             BodyRotY=0;       //Yaw
float             BodyRotZ=0;       //Roll
float             InBodyPosX;
float             InBodyPosY;
float             InBodyPosZ;
float             InBodyRotX = 0;       //Pitch
float             InBodyRotY = 0;       //Yaw
float             InBodyRotZ = 0;       //Roll
float             PrevBodyPosX=0;
float             PrevBodyPosY=0;
float             PrevBodyPosZ=0;
float             PrevBodyRotX=0;       //Pitch
float             PrevBodyRotY=0;       //Yaw
float             PrevBodyRotZ=0;       //Roll
unsigned char instatic_movement=0;

float Rot_X   = 0;
float Rot_Y   = 0;
float Rot_Z   = 0;
float Shift_X = 0;
float Shift_Z = 0;

float             BodyIKPosX;
float             BodyIKPosY;
float             BodyIKPosZ;
float             BodyShift;
float             RollPitchYawAngle;

unsigned char done=0;
/*-------------------------[GAIT]------------------------------*/
unsigned char  GaitType;

int            LegLiftHeight        = 20;
int            TravelLengthX;
int            TravelLengthZ;
int            TravelRotation;
int            TravelLength;
unsigned char  NrLiftedPos;
unsigned char  TLDivFactor;
unsigned char  StepsInGait;
bool           HalfLiftHeigth;
unsigned char  GaitStep;
unsigned char  GaitLegNr[6];
bool           GaitInMotion;
bool           LastLeg;
int            GaitPosX[6];
int            GaitPosY[6];
int            GaitPosZ[6];
int            GaitRotY[6];
char           GaitSequencerOn       = FALSE;
char           Ready                 = FALSE;

float InTravelLengthZ =0;
float InTravelLengthX =0;
float InTravelRotation=0;


/*SSC*/
char           AllServosFree         = TRUE;
char           DirectSSCControl      = FALSE;
/*-----------------------TIMING-------------------------------*/
unsigned int   GaitTravelTime        = MinGaitTravelTime;
unsigned int   FrameTime             = 10;
unsigned int   SpeedServo            ;

unsigned char   state = 0;
unsigned char   state_static = 1;
unsigned char   first = 1;
float           iter  = 0;
float           iter2 = 0;
unsigned char   stop=0;
unsigned char   stop2=0;
unsigned char   seq=0;

/*---------------------[SERIAL COMMAND]-----------------------*/
unsigned char   CurrSerialCommand       = 0;
unsigned char   PrevSerialCommand1      = 0;
unsigned char   PrevSerialCommand2      = 0;
/*----------------[DIFFERENTIAL STEERING]----------------------*/
int             DiffSteerTravelLength;
int             DiffSteerTravelRotation;
int             LeftLegsToRightLegsDistance;
int             TurnPercentage;


int elapsedtime;
void SetGlobalSpeed(int perseninput);
void attime();
/*-----------------[GAIT CALCULATION]--------------------------*/
void _interrupt(){
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n\r", FemurAngle[0], FemurAngle[1], FemurAngle[2], TibiaAngle[0], TibiaAngle[1], TibiaAngle[2], LegPosX[3], LegPosX[5]);
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\n\r", Warna.Depan, Warna.Belakang, Warna.ratio[0], GarisDepan, GarisBelakang, GarisKetemu);
	//PC.printf("\t%d\t%d\t%d\t%d\n\r", ArahSekarang, Kompas.ReadBearing(),Kompas.IsArahSama(ArahSekarang,900));
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n\r",  Warna.SetPoint[0], Warna.SetPoint[1], Warna.Depan, Warna.Belakang, Warna.TransisiDepan, Warna.TransisiBelakang, GarisKetemu, Warna.TransisiKetemu);
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n\r", Warna.Depan, Warna.Belakang, Warna.Merah[0], Warna.Merah[1], Warna.ratio[0], Warna.ratio[1], Warna.TransisiKetemu, GarisKetemu);
	//PC.printf("\t%d\t%d\t%d\n\r", Warna.SetPoint[0], Warna.State[0], Warna.Depan);
	//PC.printf("\t%d\t%d\n\r", Warna.Depan, Warna.Belakang);
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n\r", Warna.Merah[0],Warna.Biru[0], Warna.ratio[0], Warna.SetPoint[0],Warna.WarnaSekarang[0],Warna.TransisiDepan,Warna.state_set[0],Warna.SetDulu[0]);
	//PC.printf("%d\n\r", Kompas.ReadBearing());
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d||\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d||\t%d\t%d\t%d\n\r", TPA.Data[0],TPA.Data[1],TPA.Data[2],TPA.Data[3],TPA.Data[4],TPA.Data[5],TPA.Data[6],TPA.Data[7], TPAx.Data[0],TPAx.Data[1],TPAx.Data[2],TPAx.Data[3],TPAx.Data[4],TPAx.Data[5],TPAx.Data[6],TPAx.Data[7], UVTron.Counter, LilinKetemuStatis, Pinger.Depan);
	//PC.printf("%d %d %d %d %d %d %d %d\n\r", TPA.Data[0], TPA.Data[1], TPA.Data[2], TPA.Data[3], TPA.Data[4], TPA.Data[5], TPA.Data[6], TPA.Data[7]);
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\n\r", Pinger.Merah[0],Pinger.Hijau[0], Pinger.Biru[0], Pinger.Merah[1],Pinger.Hijau[1], Pinger.Biru[1]);
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\n\r", Pinger.Merah[0],Pinger.Hijau[0], Pinger.Biru[0], Pinger.Merah[1],Pinger.Hijau[1], Pinger.Biru[1]);
	//PC.printf("%3d-%3d-%3d-%3d-%3d-%3d-%3d-%3d || %3d-%3d-%3d-%3d-%3d\n\r", Pinger.SrKiri, Pinger.Depan, Pinger.SrKanan,Pinger.Kanan, Pinger.BlKanan,Pinger.Belakang,Pinger.BlKiri,Pinger.Kiri, bacaADC2.read_u16(), ADCInfraredBawah, DiffSteerTravelRotation, TravelLengthZ, TravelRotation);
	//PC.printf("%3d-%3d-%3d\n\r", Pinger.JarakPing[5], Pinnger.JarakPing[6], Pinger.JarakPing[7]);
	//PC.printf("\t%d\t%d\t%d\t%d\n\r", bacaADC2.read_u16(), Pinger.SrKanan, Pinger.Kanan);
	//PC.printf("%3d-%3d-%3d-%3d-%3d-%3d-%3d-%3d \n\r", Pinger.SrKiri, Pinger.Depan, Pinger.SrKanan,Pinger.Kanan, Pinger.BlKanan,Pinger.Belakang,Pinger.BlKiri,Pinger.Kiri);
	//PC.printf("%3d\n\r", ADCInfraredBawah);
	//PC.printf("\t%3d\t%d\n\r", Warna.SetPointPutih[0], Warna.SetPoint[0]);
	// PC.printf("\t%d\t%d\t%d\t%d||\t%d\t%d\t%d\t%d||\t%d\t%d\n\r", Warna.Merah[0], Warna.Biru[0], Warna.ratio[0], Warna.Depan, Warna.Merah[1], Warna.Biru[1], Warna.ratio[1], Warna.Belakang, Pinger.Depan, ADCInfraredBawah);
	//PC.printf("\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d||\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d||\t%d||\t%d||\t%d\n\r", TPA.Data[0], TPA.Data[1], TPA.Data[2], TPA.Data[3], TPA.Data[4], TPA.Data[5], TPA.Data[6], TPA.Data[7], TPAx.Data[0], TPAx.Data[1], TPAx.Data[2], TPAx.Data[3], TPAx.Data[4], TPAx.Data[5], TPAx.Data[6], TPAx.Data[7], UVTron.Counter, TPA.Ambient(), TPAx.Ambient());
}
void GaitCalculation (unsigned char GaitCurrentLegNr)
{
    GaitInMotion = ((TravelLengthX != 0) || (TravelLengthZ != 0) || (TravelRotation != 0));

    if ( ((GaitInMotion==TRUE) && ((NrLiftedPos==1)||(NrLiftedPos==3)) && (GaitStep==GaitLegNr[GaitCurrentLegNr])) || ((GaitInMotion==FALSE) && (GaitStep==GaitLegNr[GaitCurrentLegNr]) && ((abs(GaitPosX[GaitCurrentLegNr])>2)||(abs(GaitPosZ[GaitCurrentLegNr])>2)||(abs(GaitRotY[GaitCurrentLegNr])>2))) )   //Up
    {
        GaitPosX[GaitCurrentLegNr] = 0;
        GaitPosY[GaitCurrentLegNr] = -LegLiftHeight;
        GaitPosZ[GaitCurrentLegNr] = 0;
        GaitRotY[GaitCurrentLegNr] = 0;
    }
    else
    {
        if ( (((NrLiftedPos==2) && (GaitStep==GaitLegNr[GaitCurrentLegNr])) || ((NrLiftedPos==3) && ((GaitStep==(GaitLegNr[GaitCurrentLegNr]-1)) || (GaitStep==(GaitLegNr[GaitCurrentLegNr]+(StepsInGait-1)))))) && (GaitInMotion==TRUE) )
        {
            GaitPosX[GaitCurrentLegNr] = -TravelLengthX/2;
            if (HalfLiftHeigth==FALSE)
            {
                GaitPosY[GaitCurrentLegNr] = -LegLiftHeight;
            }
            else
            {
                GaitPosY[GaitCurrentLegNr] = -LegLiftHeight/2;
            }
            GaitPosZ[GaitCurrentLegNr] = -TravelLengthZ/2;
            GaitRotY[GaitCurrentLegNr] = -TravelRotation/2;
        }
        else
        {
            if ( (NrLiftedPos>=2) && ((GaitStep==(GaitLegNr[GaitCurrentLegNr]+1)) || (GaitStep==(GaitLegNr[GaitCurrentLegNr]-(StepsInGait-1)))) && (GaitInMotion==TRUE) )
            {
                GaitPosX[GaitCurrentLegNr] = TravelLengthX/2;
                if (HalfLiftHeigth==FALSE)
                {
                    GaitPosY[GaitCurrentLegNr] = -LegLiftHeight;
                }
                else
                {
                    GaitPosY[GaitCurrentLegNr] = -LegLiftHeight/2;
                }
                GaitPosZ[GaitCurrentLegNr] = TravelLengthZ/2;
                GaitRotY[GaitCurrentLegNr] = TravelRotation/2;
            }
            else
            {
                if ( ((GaitStep==(GaitLegNr[GaitCurrentLegNr]+NrLiftedPos)) || (GaitStep==(GaitLegNr[GaitCurrentLegNr]-(StepsInGait-NrLiftedPos)))) && (GaitPosY[GaitCurrentLegNr]<0) )
                {
                    GaitPosX[GaitCurrentLegNr] = TravelLengthX/2;
                    GaitPosZ[GaitCurrentLegNr] = TravelLengthZ/2;
                    GaitRotY[GaitCurrentLegNr] = TravelRotation/2;
                    GaitPosY[GaitCurrentLegNr] = 0;
                }
                else
                {
                    GaitPosX[GaitCurrentLegNr] = GaitPosX[GaitCurrentLegNr] - (TravelLengthX/TLDivFactor);
                    GaitPosY[GaitCurrentLegNr] = 0;
                    GaitPosZ[GaitCurrentLegNr] = GaitPosZ[GaitCurrentLegNr] - (TravelLengthZ/TLDivFactor);
                    GaitRotY[GaitCurrentLegNr] = GaitRotY[GaitCurrentLegNr] - (TravelRotation/TLDivFactor);
                }
            }
        }
    }
    
    if (LastLeg==1)
    {
        GaitStep = GaitStep+1;
        if (GaitStep>StepsInGait)
        {
            GaitStep = 1;
        }
    }
}

void GaitGeneratorCurve(void)
{
        unsigned char i;

        //float InTravelLengthZ,InTravelLengthX,InTravelRotation;

        if(seq==1)
        {
          switch(state)
          {
                case 0:
                            if(first==1 && stop2==0)//semua kaki ke posisi 1
                            {
                                for(i=0;i<6;i++)
                                {
                                    GaitPosY[i]=0;
                                    GaitPosZ[i]=iter*(TravelLengthZ/2);//jumlah iterasi 25 kali
                                    GaitPosX[i]=iter*(TravelLengthX/2);
                                    GaitRotY[i]=iter*(TravelRotation/2);


                                }
                            }else if(first==0 && stop2==0){
                                for(i=0;i<6;i=i+2)
                                {
                                    //tripod 1 ke p1
                                    GaitPosY[i]=0;
                                    GaitPosZ[i]=iter*(TravelLengthZ/2);
                                    GaitPosX[i]=iter*(TravelLengthX/2);
                                    GaitRotY[i]=iter*(TravelRotation/2);
                                    //tripod 2 ke p4
                                    GaitPosY[i+1]= -((3*((iter*0.5)+0.5)*pow(1-((iter*0.5)+0.5),2)*LegLiftHeight)+(3*pow(((iter*0.5)+0.5),2)*(1-((iter*0.5)+0.5))*LegLiftHeight));//iter = 0.5
                                    GaitPosZ[i+1]=pow((1-(((iter*0.5)+0.5))),3)*(TravelLengthZ/2)+3*((iter*0.5)+0.5)*pow((1-((iter*0.5)+0.5)),2)*(TravelLengthZ/2)+3*pow(((iter*0.5)+0.5),2)*(1-((iter*0.5)+0.5))*(-TravelLengthZ/2)+pow(((iter*0.5)+0.5),3)*(-TravelLengthZ/2);
                                    GaitPosX[i+1]=pow((1-(((iter*0.5)+0.5))),3)*(TravelLengthX/2)+3*((iter*0.5)+0.5)*pow((1-((iter*0.5)+0.5)),2)*(TravelLengthX/2)+3*pow(((iter*0.5)+0.5),2)*(1-((iter*0.5)+0.5))*(-TravelLengthX/2)+pow(((iter*0.5)+0.5),3)*(-TravelLengthX/2);
                                    GaitRotY[i+1]=pow((1-(((iter*0.5)+0.5))),3)*(TravelRotation/2)+3*((iter*0.5)+0.5)*pow((1-((iter*0.5)+0.5)),2)*(TravelRotation/2)+3*pow(((iter*0.5)+0.5),2)*(1-((iter*0.5)+0.5))*(-TravelRotation/2)+pow(((iter*0.5)+0.5),3)*(-TravelRotation/2);
                                }
                            }
                            else if(stop2==1)//stop2==1
                            {
                                for (i=0;i<6; i=i+2)
                                {
                                    //tripod 2 langsung ke posisi po dari p2'
                                    //GaitPosY[i+1]=-(1-iter)*LegLiftHeight;
                                    //iterasi dimulai dari 0.5 sampai 1 tetapi nyatanya di case ini iterasi dimulai dari 0
                                    GaitPosY[i+1]=-(3*(0.5+(iter/2))*pow(1-(0.5+(iter/2)),2)*LegLiftHeight+3*pow((0.5+(iter/2)),2)*(1-(0.5+(iter/2)))*LegLiftHeight);//iter = 0.5
                                    GaitPosZ[i+1]=pow((1-(0.5+(iter/2))),3)*(TravelLengthZ/2)+3*(0.5+(iter/2))*pow((1-(0.5+(iter/2))),2)*(TravelLengthZ/2);
                                    GaitPosX[i+1]=pow((1-(0.5+(iter/2))),3)*(TravelLengthX/2)+3*(0.5+(iter/2))*pow((1-(0.5+(iter/2))),2)*(TravelLengthX/2);
                                    GaitRotY[i+1]=pow((1-(0.5+(iter/2))),3)*(TravelRotation/2)+3*(0.5+(iter/2))*pow((1-(0.5+(iter/2))),2)*(TravelRotation/2);


                                }
                                if(iter>=1-0.04)
                                {
                                    seq=0;
                                    state=0;
                                    iter=0;
                                    stop2=0;
                                    first=1;
                                    //LegLiftHeight=0;
                                    TravelLengthZ = 0;
                                    TravelLengthX = 0;
                                    TravelRotation= 0;
                                }
                            }



                            iter = iter+0.04;
                            if(iter >= 1){
                                state=1;iter=0;
                            }else{
                                state=0;}
                            break;
                case 1:
                            if(first==1)//
                            {
                                for(i=0;i<6;i=i+2)
                                {
                                    //Tripod 1 leg 0,2,4 ke p26 jumlah iterasi = 25 kali
                                    GaitPosY[i]=-(3*iter*pow((1-iter),2)*LegLiftHeight+3*pow(iter,2)*(1-iter)*LegLiftHeight);
                                    GaitPosZ[i]=pow((1-iter),3)*(TravelLengthZ/2)+3*iter*pow((1-iter),2)*(TravelLengthZ/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthZ/2)+pow(iter,3)*(-TravelLengthZ/2);
                                    GaitPosX[i]=pow((1-iter),3)*(TravelLengthX/2)+3*iter*pow((1-iter),2)*(TravelLengthX/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthX/2)+pow(iter,3)*(-TravelLengthX/2);
                                    GaitRotY[i]=pow((1-iter),3)*(TravelRotation/2)+3*iter*pow((1-iter),2)*(TravelRotation/2)+3*pow(iter,2)*(1-iter)*(-TravelRotation/2)+pow(iter,3)*(-TravelRotation/2);
                                    //tripod 2 leg 1,3,5 tetap di p1

                                }
                            }else{
                                for(i=0;i<6;i=i+2)
                                {
                                    GaitPosY[i+1]=-(3*(iter/2)*pow(1-(iter/2),2)*LegLiftHeight+3*pow((iter/2),2)*(1-(iter/2))*LegLiftHeight);//iter = 0.5
                                    //tripod 1 ke p2
                                    GaitPosY[i]=-(3*iter*pow((1-iter),2)*LegLiftHeight+3*pow(iter,2)*(1-iter)*LegLiftHeight);
                                    GaitPosZ[i]=pow((1-iter),3)*(TravelLengthZ/2)+3*iter*pow((1-iter),2)*(TravelLengthZ/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthZ/2)+pow(iter,3)*(-TravelLengthZ/2);
                                    GaitPosX[i]=pow((1-iter),3)*(TravelLengthX/2)+3*iter*pow((1-iter),2)*(TravelLengthX/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthX/2)+pow(iter,3)*(-TravelLengthX/2);
                                    GaitRotY[i]=pow((1-iter),3)*(TravelRotation/2)+3*iter*pow((1-iter),2)*(TravelRotation/2)+3*pow(iter,2)*(1-iter)*(-TravelRotation/2)+pow(iter,3)*(-TravelRotation/2);
                                    //tripod 2 ke p0
                                    GaitPosY[i+1]=0;
                                    GaitPosZ[i+1]=(1-(iter*2))*(-TravelLengthZ/2);
                                    GaitPosX[i+1]=(1-(iter*2))*(-TravelLengthX/2);
                                    GaitRotY[i+1]=(1-(iter*2))*(-TravelRotation/2);
                                }
                            }

                            iter = iter+0.02;
                            if(iter >= 0.5){
                                state=2;
                            }else{
                                state=1;}
                            break;

                case 2:
                            if(first==1){
                                for(i=0;i<6;i=i+2)
                                {
                                    //tripod 1 ke p4 jumlah iterasi 25 kali
                                    GaitPosY[i]=-(3*iter*pow((1-iter),2)*LegLiftHeight+3*pow(iter,2)*(1-iter)*LegLiftHeight);
                                    GaitPosZ[i]=pow((1-iter),3)*(TravelLengthZ/2)+3*iter*pow((1-iter),2)*(TravelLengthZ/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthZ/2)+pow(iter,3)*(-TravelLengthZ/2);
                                    GaitPosX[i]=pow((1-iter),3)*(TravelLengthX/2)+3*iter*pow((1-iter),2)*(TravelLengthX/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthX/2)+pow(iter,3)*(-TravelLengthX/2);
                                    GaitRotY[i]=pow((1-iter),3)*(TravelRotation/2)+3*iter*pow((1-iter),2)*(TravelRotation/2)+3*pow(iter,2)*(1-iter)*(-TravelRotation/2)+pow(iter,3)*(-TravelRotation/2);
                                    //tripod 2 tetap di p1


                                }
                            }else{
                                for(i=0;i<6;i=i+2)
                                {
                                    //tripod 1 ke p4
                                    GaitPosY[i]=-(3*iter*pow((1-iter),2)*LegLiftHeight+3*pow(iter,2)*(1-iter)*LegLiftHeight);
                                    GaitPosZ[i]=pow((1-iter),3)*(TravelLengthZ/2)+3*iter*pow((1-iter),2)*(TravelLengthZ/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthZ/2)+pow(iter,3)*(-TravelLengthZ/2);
                                    GaitPosX[i]=pow((1-iter),3)*(TravelLengthX/2)+3*iter*pow((1-iter),2)*(TravelLengthX/2)+3*pow(iter,2)*(1-iter)*(-TravelLengthX/2)+pow(iter,3)*(-TravelLengthX/2);
                                    GaitRotY[i]=pow((1-iter),3)*(TravelRotation/2)+3*iter*pow((1-iter),2)*(TravelRotation/2)+3*pow(iter,2)*(1-iter)*(-TravelRotation/2)+pow(iter,3)*(-TravelRotation/2);
                                    //tripod 2 ke p1
                                    GaitPosY[i+1]=0;
                                    GaitPosZ[i+1]=(iter-0.5)*2*(TravelLengthZ/2);
                                    GaitPosX[i+1]=(iter-0.5)*2*(TravelLengthX/2);
                                    GaitRotY[i+1]=(iter-0.5)*2*(TravelRotation/2);
                                }
                            }

                            iter = iter+0.02;
                            if(iter >= 1){
                                state= 3;iter = 0;
                            }else{
                                state=2;}

                            break;

                case 3:
                            for(i=0;i<6;i=i+2)
                            {
                                //tripod 1 ke posisi p0 jumlah iterasi 25 kali
                                GaitPosY[i]=0;
                                GaitPosZ[i]=(1-iter)*(-TravelLengthZ/2);
                                GaitPosX[i]=(1-iter)*(-TravelLengthX/2);
                                GaitRotY[i]=(1-iter)*(-TravelRotation/2);

                                if(stop==1){
                                //tripod 2 ke posisis p2' jika stop bernilai 1
                                    GaitPosY[i+1]=-(3*(iter/2)*pow(1-(iter/2),2)*LegLiftHeight+3*pow((iter/2),2)*(1-(iter/2))*LegLiftHeight);//iter = 0.5
                                    GaitPosZ[i+1]=pow((1-(iter/2)),3)*(TravelLengthZ/2)+3*iter*0.5*pow((1-iter*0.5),2)*(TravelLengthZ/2);
                                    GaitPosX[i+1]=pow((1-(iter/2)),3)*(TravelLengthX/2)+3*iter*0.5*pow((1-iter*0.5),2)*(TravelLengthX/2);
                                    GaitRotY[i+1]=pow((1-(iter/2)),3)*(TravelRotation/2)+3*iter*0.5*pow((1-iter*0.5),2)*(TravelRotation/2);


                                }
                                //tripod 2 ke posisi p2
                                else{
                                    GaitPosY[i+1]=-(3*(iter/2)*pow(1-(iter/2),2)*LegLiftHeight+3*pow((iter/2),2)*(1-(iter/2))*LegLiftHeight);//iter = 0.5
                                    GaitPosZ[i+1]=pow((1-(iter/2)),3)*(TravelLengthZ/2)+3*iter*0.5*pow((1-iter*0.5),2)*(TravelLengthZ/2)+3*pow(iter*0.5,2)*(1-iter*0.5)*(-TravelLengthZ/2)+pow(iter*0.5,3)*(-TravelLengthZ/2);
                                    GaitPosX[i+1]=pow((1-(iter/2)),3)*(TravelLengthX/2)+3*iter*0.5*pow((1-iter*0.5),2)*(TravelLengthX/2)+3*pow(iter*0.5,2)*(1-iter*0.5)*(-TravelLengthX/2)+pow(iter*0.5,3)*(-TravelLengthX/2);
                                    GaitRotY[i+1]=pow((1-(iter/2)),3)*(TravelRotation/2)+3*iter*0.5*pow((1-iter*0.5),2)*(TravelRotation/2)+3*pow(iter*0.5,2)*(1-iter*0.5)*(-TravelRotation/2)+pow(iter*0.5,3)*(-TravelRotation/2);


                                }



                                //

                            }


                            iter = iter+0.04;
                            if(iter >= 1){
                                if(stop==1)
                                {
                                    stop2=1;
                                }
                                state=0;iter=0;first=0;
                            }else{
                                state=3;}

                            break;
          }
        }
}

/*--------------------[GAIT SEQUENCER]-------------------*/
void StartSequencer(void)
{
    //intinya menghidupkan interupt
    GaitSequencerOn = TRUE;
}

void StopSequencer(void)
{
    //intinya mematikan interupt
    GaitSequencerOn = FALSE;
}

void GaitSequencer (void)
{
    unsigned char LegIndex;

    LastLeg = FALSE;
    for (LegIndex = 0; LegIndex <6; LegIndex++)
    {
        if (LegIndex == 5)
        {
            LastLeg = TRUE;
        }
        GaitCalculation (LegIndex);
    }

    if ( (GaitInMotion==FALSE)&&(GaitPosX[RF]==0)&&(GaitPosX[RM]==0)&&(GaitPosX[RR]==0)&&(GaitPosX[LF]==0)&&(GaitPosX[LM]==0)&&(GaitPosX[LR]==0)
                              &&(GaitPosY[RF]==0)&&(GaitPosY[RM]==0)&&(GaitPosY[RR]==0)&&(GaitPosY[LF]==0)&&(GaitPosY[LM]==0)&&(GaitPosY[LR]==0)
                              &&(GaitPosZ[RF]==0)&&(GaitPosZ[RM]==0)&&(GaitPosZ[RR]==0)&&(GaitPosZ[LF]==0)&&(GaitPosZ[LM]==0)&&(GaitPosZ[LR]==0)
                              &&(GaitRotY[RF]==0)&&(GaitRotY[RM]==0)&&(GaitRotY[RR]==0)&&(GaitRotY[LF]==0)&&(GaitRotY[LM]==0)&&(GaitRotY[LR]==0) )
    {
            StopSequencer();
            GaitStep = 1;
    }
}

//gait generator
void GaitGenerator1(void)
{
    unsigned char i;
		unsigned char gait_speed;
		gait_speed =10;

    switch(state)
    {
        case 0: //semua ujung kaki ke posisi 1
								SetGlobalSpeed(gait_speed);
								timer.attach_us(&attime,2000000);

                if(first==1)
                {
                    for(i=0;i<6;i++)
                    {
                        GaitPosY[i]=0;
                        GaitPosZ[i]=0;
                        GaitPosX[i]=0;
                        GaitRotY[i]=0;
                    }
                }
                else
                {
                    for(i=0;i<6;i=i+2)
                    {
                        //tripod 1 ke posisi 4
                        GaitPosY[i]=-LegLiftHeight;
                        GaitPosZ[i]=0;
                        GaitPosX[i]=0;
                        GaitRotY[i]=0;
                        //tripod 2 ke posisi 1
                        GaitPosY[i+1]=0;
                        GaitPosZ[i+1]=0;
                        GaitPosX[i+1]=0;
                        GaitRotY[i+1]=0;
                    }
                }
								state =1;
                break;
        case 1:
								SetGlobalSpeed(gait_speed);
								timer.attach_us(&attime,2000000);
                if(first==1)
                {
                    for(i=0;i<6;i++)
                    {
                        //semua ujung kaki ke posisi 2
                        GaitPosY[i]=0;
                        GaitPosZ[i]=TravelLengthZ/2;
                        GaitPosX[i]=TravelLengthX/2;
                        GaitRotY[i]=TravelRotation/2;
                    }
                }
                else
                {
                    for(i=0;i<6;i=i+2)
                    {
                    //tripod 1 ke posisi 5
                    GaitPosY[i]=-LegLiftHeight/2;
                    GaitPosZ[i]=-TravelLengthZ/2;
                    GaitPosX[i]=-TravelLengthX/2;
                    GaitRotY[i]=-TravelRotation/2;
                    //tripod 2 ke posisi 2
                    GaitPosY[i+1]=0;
                    GaitPosZ[i+1]=TravelLengthZ/2;
                    GaitPosX[i+1]=TravelLengthX/2;
                    GaitRotY[i+1]=TravelRotation/2;
                    }
                }
                state = 2;
                break;
        case 2:
                //jika masih pertama maka tripod 1 tetap di posisi 2 dan
                //tripod 2 ke posisi 3
								SetGlobalSpeed(gait_speed);
								timer.attach_us(&attime,2000000);
                if(first==1)
                {

                    for (i = 0; i < 6; i=i+2)
                    {
                        //tripod 1 tetap di posisi 2

                        //tripod 2 ke posisi 3
                        GaitPosY[i+1]=-LegLiftHeight/2;
                        GaitPosZ[i+1]=TravelLengthZ/2;
                        GaitPosX[i+1]=TravelLengthX/2;
                        GaitRotY[i+1]=TravelRotation/2;
                    }
                }
                else
                {
                    for(i=0;i<6;i=i+2)
                    {
                        //tripod 1 ke posisi 6
                        GaitPosY[i]=0;
                        GaitPosZ[i]=-TravelLengthZ/2;
                        GaitPosX[i]=-TravelLengthX/2;
                        GaitRotY[i]=-TravelRotation/2;
                        //tripod 2 ke posisi 3
                        GaitPosY[i+1]=-LegLiftHeight/2;
                        GaitPosZ[i+1]=TravelLengthZ/2;
                        GaitPosX[i+1]=TravelLengthX/2;
                        GaitRotY[i+1]=TravelRotation/2;

                    }
                }
                state = 3;
                break;
        case 3:
								SetGlobalSpeed(gait_speed);
								timer.attach_us(&attime,2000000);
                if(first==1)
                {
                    for(i=0;i<6;i=i+2)
                    {
                        //tripod 1 tetap di posisi 2

                        //tripod 2 ke posisi 4
                        GaitPosY[i+1]=-LegLiftHeight;
                        GaitPosZ[i+1]=0;
                        GaitPosX[i+1]=0;
                        GaitRotY[i+1]=0;
                    }
                }
                else
                {
                    for(i=0;i<6;i=i+2)
                    {
                         //tripod 1 ke posisi 1
                        GaitPosY[i]=0;
                        GaitPosZ[i]=0;
                        GaitPosX[i]=0;
                        GaitRotY[i]=0;
                        //tripod 2 ke posisi 4
                        GaitPosY[i+1]=-LegLiftHeight;
                        GaitPosZ[i+1]=0;
                        GaitPosX[i+1]=0;
                        GaitRotY[i+1]=0;
                    }
                }
                state=4;
                break;
        case 4:
								SetGlobalSpeed(gait_speed);
								timer.attach_us(&attime,2000000);
                if(first==1)
                {
                    for(i=0;i<6;i=i+2)
                    {
                        //tripod 1 tetap di posisi 2

                        //tripod 2 ke posisi 5
                        GaitPosY[i+1]=-LegLiftHeight/2;
                        GaitPosZ[i+1]=-TravelLengthZ/2;
                        GaitPosX[i+1]=-TravelLengthX/2;
                        GaitRotY[i+1]=-TravelRotation/2;
                    }
                }
                else
                {
                    for(i=0;i<6;i=i+2)
                    {
                        //tripod 1 ke posisi 2
                        GaitPosY[i]=0;
                        GaitPosZ[i]=TravelLengthZ/2;
                        GaitPosX[i]=TravelLengthX/2;
                        GaitRotY[i]=TravelRotation/2;

                       //tripod 2 ke posisi 5
                        GaitPosY[i+1]=-LegLiftHeight/2;
                        GaitPosZ[i+1]=-TravelLengthZ/2;
                        GaitPosX[i+1]=-TravelLengthX/2;
                        GaitRotY[i+1]=-TravelRotation/2;
                    }
                }
                state=5;
                break;
        case 5:
								SetGlobalSpeed(gait_speed);
								timer.attach_us(&attime,2000000);
                for(i=0;i<6;i=i+2)
                {
                     //tripod 1 ke posisi 3
                    GaitPosY[i]=-LegLiftHeight;
                    GaitPosZ[i]=TravelLengthZ/2;
                    GaitPosX[i]=TravelLengthX/2;
                    GaitRotY[i]=TravelRotation/2;
                    //tripod 2 ke posisi 6
                    GaitPosY[i+1]=0;
                    GaitPosZ[i+1]=-TravelLengthZ/2;
                    GaitPosX[i+1]=-TravelLengthX/2;
                    GaitRotY[i+1]=-TravelRotation/2;
                }
                state=0;
                first=0;
                break;
    }
}



/*-----------------------------[BODY INVERSE KINEMATICS]-----------------------------*/
void BodyIK (float PosX, float PosZ, float PosY, float RotationY, unsigned char BodyIKIndex)
{
    //Alfa  (A) = X-Rotation (Pitch)
    //Beta  (B) = Z-Rotation (Roll)
    //Gamma (G) = Y-Rotation (Yaw)
    float 	SinA;
    float   CosA;
    float   SinB;
    float   CosB;
    float   SinG;
    float   CosG;

    int     TotalX;
    int     TotalY;
    int     TotalZ;

    TotalZ = OffsetZ[BodyIKIndex] + PosZ;
    TotalX = OffsetX[BodyIKIndex] + PosX;
    TotalY = PosY;

    SinA = sin((float)(     BodyRotX     )/572.96);
    CosA = cos((float)(     BodyRotX     )/572.96);
    SinB = sin((float)(     BodyRotZ     )/572.96);
    CosB = cos((float)(     BodyRotZ     )/572.96);
    SinG = sin((float)(BodyRotY+RotationY)/572.96);
    CosG = cos((float)(BodyRotY+RotationY)/572.96);

    BodyIKPosX = TotalX - (int)( (float)(TotalX)*CosG*CosB                                  - (float)(TotalZ)*CosB*SinG      + (float)(TotalY)*SinB      );
    BodyIKPosZ = TotalZ - (int)( (float)(TotalX)*CosA*SinG + (float)(TotalX)*CosG*SinB*SinA + (float)(TotalZ)*CosG*CosA - (float)(TotalZ)*SinG*SinB*SinA - (float)(TotalY)*CosB*SinA );
    BodyIKPosY = TotalY - (int)( (float)(TotalX)*SinG*SinA - (float)(TotalX)*CosG*CosA*SinB + (float)(TotalZ)*CosG*SinA + (float)(TotalZ)*CosA*SinG*SinB + (float)(TotalY)*CosB*CosA );
}

/*------------------------------[LEG INVERSE KINEMATICS]-----------------------------*/
void LegIK (float IKFeetPosX, float IKFeetPosY, float IKFeetPosZ, unsigned char LegIKIndex)
{
    int 	IKFemurLengthSquare;
    int     IKTibiaLengthSquare;
    int     IKFeetPosXZMinusCoxaLength;
    float   IKFeetToFemurJointDistance;
    float   IKFeetToFemurJointDistanceSquare;
    float   IKFemurAngleTemp1;
    float   IKFemurAngleTemp2;

    IKFemurLengthSquare = FemurLength*FemurLength;
    IKTibiaLengthSquare = TibiaLength*TibiaLength;
    IKFeetPosXZMinusCoxaLength = (int)(sqrt((float)((IKFeetPosX*IKFeetPosX)+(IKFeetPosZ*IKFeetPosZ)))) - CoxaLength;
    IKFeetToFemurJointDistance = (sqrt((float)((IKFeetPosXZMinusCoxaLength*IKFeetPosXZMinusCoxaLength)+(IKFeetPosY*IKFeetPosY))));
    IKFeetToFemurJointDistanceSquare = IKFeetToFemurJointDistance*IKFeetToFemurJointDistance;
    IKFemurAngleTemp1 = (atan2((float)IKFeetPosY,(float)IKFeetPosXZMinusCoxaLength));
    IKFemurAngleTemp2 = (acos(((float)(IKFemurLengthSquare-IKTibiaLengthSquare)+IKFeetToFemurJointDistanceSquare) / ((float)(2*FemurLength)*IKFeetToFemurJointDistance)));
    FemurAngle[LegIKIndex] = (int)((IKFemurAngleTemp1-IKFemurAngleTemp2)*572.96);
    TibiaAngle[LegIKIndex] = (int)(((acos(((float)(IKFemurLengthSquare+IKTibiaLengthSquare)-IKFeetToFemurJointDistanceSquare) / ((float)(2*FemurLength*TibiaLength)))))*572.96) - 900;
    CoxaAngle[LegIKIndex]  = (int)((atan2((float)(IKFeetPosZ),(float)(IKFeetPosX)))*572.96) - CoxaAngleOffset[LegIKIndex];
}

void IKCalculation (void)
{
    unsigned char LegIndex;

    for (LegIndex = 0; LegIndex < 3; LegIndex++)
    {
        BodyIK (-LegPosX[LegIndex]+BodyPosX+GaitPosX[LegIndex], LegPosZ[LegIndex]+BodyPosZ+GaitPosZ[LegIndex], LegPosY[LegIndex]+BodyPosY+GaitPosY[LegIndex], GaitRotY[LegIndex], LegIndex);
        LegIK (LegPosX[LegIndex]-BodyPosX+BodyIKPosX-GaitPosX[LegIndex], LegPosY[LegIndex]+BodyPosY-BodyIKPosY+GaitPosY[LegIndex], LegPosZ[LegIndex]+BodyPosZ-BodyIKPosZ+GaitPosZ[LegIndex], LegIndex);
    }
    for (LegIndex = 3; LegIndex < 6; LegIndex++)
    {
        BodyIK (LegPosX[LegIndex]-BodyPosX+GaitPosX[LegIndex], LegPosZ[LegIndex]+BodyPosZ+GaitPosZ[LegIndex], LegPosY[LegIndex]+BodyPosY+GaitPosY[LegIndex], GaitRotY[LegIndex], LegIndex);
        LegIK (LegPosX[LegIndex]+BodyPosX-BodyIKPosX+GaitPosX[LegIndex], LegPosY[LegIndex]+BodyPosY-BodyIKPosY+GaitPosY[LegIndex], LegPosZ[LegIndex]+BodyPosZ-BodyIKPosZ+GaitPosZ[LegIndex], LegIndex);
    }
}

/*-----------------------------[CHECK ANGLES]---------------------------*/
void CheckAngles (void)
{

}

void ServoDriver (unsigned int persen_kecepatan)
{
	float speed_servo ;
    unsigned char /*LegIndex,*/i;
    int     Posisi[19];
    float   Speed[19];
    speed_servo = persen_kecepatan*0.01;
    //int param[36];
    //LF
    Posisi[1] = (1500+CoxaAngle[3])/10;
    Posisi[2] = ((1500-FemurAngle[3])-offsetfemur)/10;
    Posisi[3] = ((1500+TibiaAngle[3])+offsettibia+50)/10;
    //RF
    Posisi[4] = (1500-CoxaAngle[0]-50)/10; //ditambah maju
    Posisi[5] = ((FemurAngle[0]+1500)+offsetfemur)/10;
    Posisi[6] = ((-TibiaAngle[0]+1500)-offsettibia-20-50)/10;
    //LM
    Posisi[7] = (1500+CoxaAngle[4]+50)/10;//ditambah mundur
    Posisi[8] = ((1500-FemurAngle[4])-offsetfemur)/10;
    Posisi[9] = ((1500+TibiaAngle[4])+offsettibia+40+20)/10;
    //RM
    Posisi[10] =(1550-CoxaAngle[1]-50)/10;
    Posisi[11] =((FemurAngle[1]+1500+20)+offsetfemur)/10;
    Posisi[12] =((-TibiaAngle[1]+1500+10)-offsettibia-20-20)/10;
    //lR
    Posisi[13] =(1500+CoxaAngle[5]-25)/10; // (1500+CoxaAngle[5])/10;
    Posisi[14] =((1500-FemurAngle[5]))/10;
    Posisi[15] =((1500+TibiaAngle[5])+offsettibia-20+50)/10;
    //RR
    Posisi[16] =(1500-CoxaAngle[2]+25)/10; // (1500-CoxaAngle[2])/10;
    Posisi[17] =((FemurAngle[2]+1500)+offsetfemur)/10;
    Posisi[18] =((-TibiaAngle[2]+1500)-offsettibia-50)/10; //ditambah turun

    for (i = 1; i < 19; i++)
    {
        Speed[i] = speed_servo;
    }

    Servo.MultSetGoal(
                        Posisi[1] ,Speed[1],
                        Posisi[2] ,Speed[2],
                        Posisi[3] ,Speed[3],
                        Posisi[4] ,Speed[4],
                        Posisi[5] ,Speed[5],
                        Posisi[6] ,Speed[6],
                        Posisi[7] ,Speed[7],
                        Posisi[8] ,Speed[8],
                        Posisi[9] ,Speed[9],
                        Posisi[10],Speed[10],
                        Posisi[11],Speed[11],
                        Posisi[12],Speed[12],
                        Posisi[13],Speed[13],
                        Posisi[14],Speed[14],
                        Posisi[15],Speed[15],
                        Posisi[16],Speed[16],
                        Posisi[17],Speed[17],
                        Posisi[18],Speed[18]
                    );
}

/*-------------------[DO DYNAMIC MOVEMENT]------------------------*/
void DoDynamicMovement (void)
{
    if (GaitSequencerOn == FALSE)
    {
        StartSequencer();
    }
		stop=0;
    seq=1;
}

/*-------------------[DO STATIC MOVEMENT]-----------------------*/
void DoStaticMovement (void)
{
	float waktu_tunggu;
	waktu_tunggu = 0.2;
        if (GaitSequencerOn == FALSE)
        {
                IKCalculation();
                ServoDriver(SpeedServo);
                //delay_ms(FrameTime-(unsigned int)ApproxCalculationDelay);
                wait(waktu_tunggu);
        }
}

/*------------------------[GAIT SELECT]------------------------*/
void GaitSelect (unsigned char Type)
{
	GaitType = Type;
    switch (GaitType)
    {
        case 1: //Ripple Gait 6 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 5;
                GaitLegNr[RR] = 3;
                GaitLegNr[LF] = 4;
                GaitLegNr[LM] = 2;
                GaitLegNr[LR] = 6;
                NrLiftedPos = 1;
                TLDivFactor = 4;
                StepsInGait = 6;
                HalfLiftHeigth = FALSE;
                break;

        case 2: //Ripple Gait 12 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 9;
                GaitLegNr[RR] = 5;
                GaitLegNr[LF] = 7;
                GaitLegNr[LM] = 3;
                GaitLegNr[LR] = 11;
                NrLiftedPos = 3;
                TLDivFactor = 8;
                StepsInGait = 12;
                HalfLiftHeigth = TRUE;
                break;

        case 3: //Tripod 4 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 3;
                GaitLegNr[RR] = 1;
                GaitLegNr[LF] = 3;
                GaitLegNr[LM] = 1;
                GaitLegNr[LR] = 3;
                NrLiftedPos = 1;
                TLDivFactor = 2;
                StepsInGait = 4;
                HalfLiftHeigth = FALSE;
                break;

        case 4: //Tripod 6 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 4;
                GaitLegNr[RR] = 1;
                GaitLegNr[LF] = 4;
                GaitLegNr[LM] = 1;
                GaitLegNr[LR] = 4;
                NrLiftedPos = 2;
                TLDivFactor = 4;
                StepsInGait = 6;
                HalfLiftHeigth = FALSE;
                break;

        case 5: //Tripod 8 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 5;
                GaitLegNr[RR] = 1;
                GaitLegNr[LF] = 5;
                GaitLegNr[LM] = 1;
                GaitLegNr[LR] = 5;
                NrLiftedPos = 3;
                TLDivFactor = 4;
                StepsInGait = 8;
                HalfLiftHeigth = FALSE;
                break;

        case 6: //Quadripple 9 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 7;
                GaitLegNr[RR] = 4;
                GaitLegNr[LF] = 5;
                GaitLegNr[LM] = 2;
                GaitLegNr[LR] = 8;
                NrLiftedPos = 2;
                TLDivFactor = 6;
                StepsInGait = 9;
                HalfLiftHeigth = FALSE;
                break;

        case 7: //Wave 12 steps
                GaitLegNr[RF] = 11;
                GaitLegNr[RM] = 9;
                GaitLegNr[RR] = 7;
                GaitLegNr[LF] = 5;
                GaitLegNr[LM] = 3;
                GaitLegNr[LR] = 1;
                NrLiftedPos = 1;
                TLDivFactor = 10;
                StepsInGait = 12;
                HalfLiftHeigth = FALSE;
                break;

        case 8: //Wave 18 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 16;
                GaitLegNr[RR] = 13;
                GaitLegNr[LF] = 10;
                GaitLegNr[LM] = 7;
                GaitLegNr[LR] = 4;
                NrLiftedPos = 2;
                TLDivFactor = 16;
                StepsInGait = 18;
                HalfLiftHeigth = FALSE;
                break;

        default://Tripod 4 steps
                GaitLegNr[RF] = 1;
                GaitLegNr[RM] = 3;
                GaitLegNr[RR] = 1;
                GaitLegNr[LF] = 3;
                GaitLegNr[LM] = 1;
                GaitLegNr[LR] = 3;
                NrLiftedPos = 1;
                TLDivFactor = 2;
                StepsInGait = 4;
                HalfLiftHeigth = FALSE;
    }
}

//[SET BODY HEIGHT]
void SetBodyHeight (int BodyHeightInput)
{
    BodyHeight = BodyHeightInput;
    if (BodyHeightInput<0)
    {
        BodyHeightInput = 0;
    }
    if (BodyHeightInput>100)
    {
        BodyHeightInput = 100;
    }
    BodyPosY = BodyHeight;

    if (Ready==TRUE)
   	{
        DoStaticMovement();
    }
}

//--------------------------------------------------------------------
//[SET LEG LIFT HEIGHT]
void SetLegLiftHeight (int LegLiftHeightInput)
{
    LegLiftHeight = LegLiftHeightInput;
    if (LegLiftHeight<10)
    {
            LegLiftHeight = 10;
    }
    if (LegLiftHeight>(BodyHeight+30))
    {
            LegLiftHeight = (BodyHeight+30);
    }
}

//--------------------------------------------------------------------
//[SET FRAME TIME]
void SetFrameTime (unsigned int FrameTimeInput)
{
    FrameTime = FrameTimeInput;
    if (FrameTime>5000)
    {
            FrameTime = 5000;
    }
}

//--------------------------------------------------------------------
//[GET READY]
void GetReady (int LegRadiusInput, int NormCoxaAngleInput)
{
    StopSequencer();
    LegRadius = LegRadiusInput;
    if (LegRadius<60)
    {
        LegRadius = 60;
    }
    if (LegRadius>150)
    {
        LegRadius = 150;
    }
    NormCoxaAngle = NormCoxaAngleInput;
    if (NormCoxaAngle<300)
    {
        NormCoxaAngle = 300;
    }
    if (NormCoxaAngle>600)
    {
        NormCoxaAngle = 600;
    }
    BodyPosX = 0;
    BodyPosY = 0;
    BodyPosZ = 0;
    BodyRotX = 0;
    BodyRotY = 0;
    BodyRotZ = 0;
    GaitPosX[RF] = 0;
    GaitPosX[RM] = 0;
    GaitPosX[RR] = 0;
    GaitPosX[LF] = 0;
    GaitPosX[LM] = 0;
    GaitPosX[LR] = 0;
    GaitPosY[RF] = 0;
    GaitPosY[RM] = 0;
    GaitPosY[RR] = 0;
    GaitPosY[LF] = 0;
    GaitPosY[LM] = 0;
    GaitPosY[LR] = 0;
    GaitPosZ[RF] = 0;
    GaitPosZ[RM] = 0;
    GaitPosZ[RR] = 0;
    GaitPosZ[LF] = 0;
    GaitPosZ[LM] = 0;
    GaitPosZ[LR] = 0;
    GaitRotY[RF] = 0;
    GaitRotY[RM] = 0;
    GaitRotY[RR] = 0;
    GaitRotY[LF] = 0;
    GaitRotY[LM] = 0;
    GaitRotY[LR] = 0;

    if (AllServosFree == TRUE)
    {
        AllServosFree = FALSE;
	    //Step-1-------------------------------------------
	    CoxaAngle[RF] = 0;
	    CoxaAngle[RM] = 0;
	    CoxaAngle[RR] = 0;
	    CoxaAngle[LF] = 0;
	    CoxaAngle[LM] = 0;
	    CoxaAngle[LR] = 0;
	    FemurAngle[RF] = -100;
	    FemurAngle[RM] = -100;
	    FemurAngle[RR] = -100;
	    FemurAngle[LF] = -100;
	    FemurAngle[LM] = -100;
	    FemurAngle[LR] = -100;
	    TibiaAngle[RF] = -50;
	    TibiaAngle[RM] = -50;
	    TibiaAngle[RR] = -50;
	    TibiaAngle[LF] = -50;
	    TibiaAngle[LM] = -50;
	    TibiaAngle[LR] = -50;
	    ServoDriver(20);
		CheckAngles();

		wait(0.001*900);

    	//Step-2-------------------------------------------
        LegPosX[RF] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
        LegPosY[RF] = 50;
        LegPosZ[RF] = -(int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));

        LegPosX[RM] = LegRadius;
        LegPosY[RM] = 50;
        LegPosZ[RM] = 0;

        LegPosX[RR] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
        LegPosY[RR] = 50;
        LegPosZ[RR] = (int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));

        LegPosX[LF] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
        LegPosY[LF] = 50;
        LegPosZ[LF] = -(int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));

        LegPosX[LM] = LegRadius;
        LegPosY[LM] = 50;
        LegPosZ[LM] = 0;

        LegPosX[LR] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
        LegPosY[LR] = 50;
        LegPosZ[LR] = (int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));
        //DoStaticMovement();
		//CheckAngles();
		//wait(0.05);

        //Step-3-------------------------------------------
        BodyPosY = BodyHeight;
        DoStaticMovement();
		//CheckAngles();
		//wait(1);
    }

    else
    {
        //Step-1-------------------------------------------
        BodyPosY = BodyHeight;
        DoStaticMovement();

        //Step-2-------------------------------------------
        LegPosX[RF] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
            LegPosY[RF] = 0;
            LegPosZ[RF] = -(int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));
        LegPosX[LM] = LegRadius;
            LegPosY[LM] = 0;
            LegPosZ[LM] = 0;
        LegPosX[RR] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
            LegPosY[RR] = 0;
            LegPosZ[RR] = (int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));
        DoStaticMovement();

        //Step-3-------------------------------------------
        LegPosY[RF] = 20;
        LegPosY[LM] = 20;
        LegPosY[RR] = 20;
        DoStaticMovement();

        //Step-4-------------------------------------------
        LegPosX[LF] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
            LegPosY[LF] = 0;
            LegPosZ[LF] = -(int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));
        LegPosX[RM] = LegRadius;
            LegPosY[RM] = 0;
            LegPosZ[RM] = 0;
        LegPosX[LR] = (int)((float)LegRadius*cos((float)NormCoxaAngle/572.96));
            LegPosY[LR] = 0;
            LegPosZ[LR] = (int)((float)LegRadius*sin((float)NormCoxaAngle/572.96));
        DoStaticMovement();

        //Step-5-------------------------------------------
        LegPosY[LF] = 20;
        LegPosY[RM] = 20;
        LegPosY[LR] = 20;
        DoStaticMovement();
    }

    LeftLegsToRightLegsDistance = (((LegPosX[LF]+OffsetX[LF])+(LegPosX[LM]+OffsetX[LM])+(LegPosX[LR]+OffsetX[LR])*2)/3);
    Ready=TRUE;
}

//--------------------------------------------------------------------
//[SET TRAVEL SPEED]
void SetTravelSpeed (unsigned int TravelSpeedPercentage)
{
    if (TravelSpeedPercentage<1)
    {
        TravelSpeedPercentage = 1;
    }
    if (TravelSpeedPercentage>100)
    {
        TravelSpeedPercentage = 100;
    }
    SpeedServo = TravelSpeedPercentage;
}

//--------------------------------------------------------------------
//[TRAVEL LENGTH CHECK]
void TravelLengthCheck (void)
{
    if (TravelLength<0)
    {
       	TravelLength = 0;
    }
    if (TravelLength>100)
    {
        TravelLength = 100;
    }
}

//--------------------------------------------------------------------
//[MAJU LURUS]
void MajuLurus (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = -TravelLength;
    TravelLengthX  = 0;
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MUNDUR LURUS]
void MundurLurus (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = TravelLength;
    TravelLengthX  = 0;
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[GESER KANAN]
void GeserKanan (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = 0;
    TravelLengthX  = -TravelLength;
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[GESER KIRI]
void GeserKiri (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = 0;
    TravelLengthX  = TravelLength;
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MAJU SERONG KANAN]
void MajuSerongKanan (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = -((TravelLength*71)/100);
    TravelLengthX  = -((TravelLength*71)/100);
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MAJU SERONG KIRI]
void MajuSerongKiri (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = -((TravelLength*71)/100);
    TravelLengthX  = ((TravelLength*71)/100);
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MUNDUR SERONG KANAN]
void MundurSerongKanan (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = ((TravelLength*71)/100);
    TravelLengthX  = -((TravelLength*71)/100);
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MUNDUR SERONG KIRI]
void MundurSerongKiri (int TravelLengthInput)
{
    TravelLength = TravelLengthInput;
    TravelLengthCheck();
    TravelLengthZ  = ((TravelLength*71)/100);
    TravelLengthX  = ((TravelLength*71)/100);
    TravelRotation = 0;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[TRAVEL ROTATION CHECK]
void TravelRotationCheck (void)
{
    if (TravelRotation<0)
    {
        TravelRotation = 0;
    }
    if (TravelRotation>300)
    {
        TravelRotation = 300;
    }
}

//--------------------------------------------------------------------
//[PUTAR KANAN]
void PutarKanan (int TravelRotationInput)
{
    TravelRotation = TravelRotationInput;
    TravelRotationCheck();
    TravelLengthZ   = 0;
    TravelLengthX   = 0;
    TravelRotation  = -TravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[PUTAR KIRI]
void PutarKiri (int TravelRotationInput)
{
    TravelRotation = TravelRotationInput;
    TravelRotationCheck();
    TravelLengthZ   = 0;
    TravelLengthX   = 0;
    TravelRotation  = TravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[TURN PERCENTAGE CHECK]
void TurnPercentageCheck (void)
{
    if (TurnPercentage<0)
    {
        TurnPercentage = 0;
    }
    if (TurnPercentage>100)
    {
        TurnPercentage = 100;
    }
}

//--------------------------------------------------------------------
//[DIFFERENTIAL STEERING]
void DifferentialSteering (int DiffSteerTurnPercentageInput)
{
    int MaxTravelLength = 60;               //60mm @ TurnPercentageInput=0% (Straight Forward)
    int TuningConstant  = 100;              //100%

    DiffSteerTravelLength    = (MaxTravelLength*(200-DiffSteerTurnPercentageInput))/200;
    DiffSteerTravelRotation = (int)((TuningConstant*(((long int)MaxTravelLength*(long int)DiffSteerTurnPercentageInput*573)/((long int)LeftLegsToRightLegsDistance*100)))/100);
    if (DiffSteerTravelRotation>300)
    {
        DiffSteerTravelRotation = 300;
    }
}

//--------------------------------------------------------------------
//[MAJU BELOK KANAN]
void MajuBelokKanan (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentage);
    TravelLengthZ   = -DiffSteerTravelLength;
    TravelLengthX   = 0;
    TravelRotation = -DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MAJU BELOK KIRI]
void MajuBelokKiri (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentage);
    TravelLengthZ   = -DiffSteerTravelLength;
    TravelLengthX   = 0;
    TravelRotation = DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MUNDUR BELOK KANAN]
void MundurBelokKanan (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentage);
    TravelLengthZ   = DiffSteerTravelLength;
    TravelLengthX   = 0;
    TravelRotation = DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[MUNDUR BELOK KIRI]
void MundurBelokKiri (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentage);
    TravelLengthZ   = DiffSteerTravelLength;
    TravelLengthX   = 0;
    TravelRotation = -DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[LINGKAR KANAN DEPAN]
void LingkarKananDepan (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentage);
    TravelLengthZ   = 0;
    TravelLengthX   = -DiffSteerTravelLength;
    TravelRotation = DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[LINGKAR KIRI DEPAN]
void LingkarKiriDepan (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentage);
    TravelLengthZ   = 0;
    TravelLengthX   = DiffSteerTravelLength;
    TravelRotation = -DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[LINGKAR KANAN BELAKANG]
void LingkarKananBelakang (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentage);
    TravelLengthZ   = 0;
    TravelLengthX   = -DiffSteerTravelLength;
    TravelRotation = -DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[LINGKAR KIRI BELAKANG]
void LingkarKiriBelakang (int TurnPercentageInput)
{
    TurnPercentage = TurnPercentageInput;
    TurnPercentageCheck();
    DifferentialSteering(TurnPercentageInput);
    TravelLengthZ   = 0;
    TravelLengthX   = DiffSteerTravelLength;
    TravelRotation = DiffSteerTravelRotation;
    DoDynamicMovement();
}

//--------------------------------------------------------------------
//[STOP]
void Stop (void)
{
    TravelLengthZ = 0;
    TravelLengthX = 0;
    TravelRotation = 0;
}

//--------------------------------------------------------------------
//[QUICKSTOP]
void QuickStop (void)
{
    putchar(27);
    TravelLengthZ = 0;
    TravelLengthX = 0;
    TravelRotation = 0;
}

//--------------------------------------------------------------------
//[ROLL-PITCH-YAW ANGLE CHECK]
void RollPitchYawAngleCheck (void)
{
    if (RollPitchYawAngle<0)
    {
        RollPitchYawAngle = 0;
    }
    if (RollPitchYawAngle>250)
    {
        RollPitchYawAngle = 250;
    }
}

//--------------------------------------------------------------------
//[TENGOK KANAN]
void TengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[TENGOK KIRI]
void TengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING DEPAN] = [TENGOK BAWAH]
void MiringDepan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = RollPitchYawAngle;
    BodyRotY = 0;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING BELAKANG] = [TENGOK ATAS]
void MiringBelakang (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = 0;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[TENGOK ATAS]
void TengokAtas (int RollPitchYawAngleInput)
{
    MiringBelakang(RollPitchYawAngleInput);
}

//--------------------------------------------------------------------
//[TENGOK BAWAH]
void TengokBawah (int RollPitchYawAngleInput)
{
    MiringDepan(RollPitchYawAngleInput);
}

//--------------------------------------------------------------------
//[MIRING KANAN]
void MiringKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = 0;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI]
void MiringKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = 0;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KANAN DEPAN]
void MiringKananDepan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = RollPitchYawAngle;
    BodyRotY = 0;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI DEPAN]
void MiringKiriDepan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = RollPitchYawAngle;
    BodyRotY = 0;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KANAN BELAKANG]
void MiringKananBelakang (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = 0;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI BELAKANG]
void MiringKiriBelakang (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = 0;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING DEPAN TENGOK KANAN] = [TENGOK KANAN BAWAH]
void MiringDepanTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 50;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[TENGOK KANAN BAWAH]
void TengokKananBawah (int RollPitchYawAngleInput)
{
    MiringDepanTengokKanan(RollPitchYawAngleInput);
}

//--------------------------------------------------------------------
//[MIRING DEPAN TENGOK KIRI] = [TENGOK KIRI BAWAH]
void MiringDepanTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 50;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[TENGOK KIRI BAWAH]
void TengokKiriBawah (int RollPitchYawAngleInput)
{
    MiringDepanTengokKiri(RollPitchYawAngleInput);
}

//--------------------------------------------------------------------
//[MIRING BELAKANG TENGOK KANAN] = [TENGOK KANAN ATAS]
void MiringBelakangTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[TENGOK KANAN ATAS]
void TengokKananAtas (int RollPitchYawAngleInput)
{
    MiringBelakangTengokKanan(RollPitchYawAngleInput);
}

//--------------------------------------------------------------------
//[MIRING BELAKANG TENGOK KIRI] = [TENGOK KIRI ATAS]
void MiringBelakangTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[TENGOK KIRI ATAS]
void TengokKiriAtas (int RollPitchYawAngleInput)
{
    MiringBelakangTengokKiri(RollPitchYawAngleInput);
}

//--------------------------------------------------------------------
//[MIRING KANAN TENGOK KANAN]
void MiringKananTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KANAN TENGOK KIRI]
void MiringKananTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI TENGOK KANAN]
void MiringKiriTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI TENGOK KIRI]
void MiringKiriTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = 0;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KANAN DEPAN TENGOK KANAN]
void MiringKananDepanTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = RollPitchYawAngle;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KANAN DEPAN TENGOK KIRI]
void MiringKananDepanTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = RollPitchYawAngle;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI DEPAN TENGOK KANAN]
void MiringKiriDepanTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = RollPitchYawAngle;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI DEPAN TENGOK KIRI]
void MiringKiriDepanTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = RollPitchYawAngle;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KANAN BELAKANG TENGOK KANAN]
void MiringKananBelakangTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KANAN BELAKANG TENGOK KIRI]
void MiringKananBelakangTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = -RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI BELAKANG TENGOK KANAN]
void MiringKiriBelakangTengokKanan (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = RollPitchYawAngle;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[MIRING KIRI BELAKANG TENGOK KIRI]
void MiringKiriBelakangTengokKiri (int RollPitchYawAngleInput)
{
    RollPitchYawAngle = RollPitchYawAngleInput;
    RollPitchYawAngleCheck();
    BodyRotX = -RollPitchYawAngle;
    BodyRotY = -RollPitchYawAngle;
    BodyRotZ = RollPitchYawAngle;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[HADAP NORMAL]
void HadapNormal (void)
{
    BodyRotX = 0;
    BodyRotY = 0;
    BodyRotZ = 0;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[BODY SHIFT CHECK]
void BodyShiftCheck (void)
{
    if (BodyShift<0)
    {
        BodyShift = 0;
    }
    if (BodyShift>80)
    {
        BodyShift = 80;
    }
}

//--------------------------------------------------------------------
//[LENGGOK DEPAN]
void LenggokDepan (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = BodyShift;
    BodyPosX = 0;
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK BELAKANG]
void LenggokBelakang (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -BodyShift;
    BodyPosX = 0;
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN]
void LenggokKanan (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = BodyShift;
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI]
void LenggokKiri (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = -BodyShift;
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN DEPAN]
void LenggokKananDepan (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*71)/100);
    BodyPosX = ((BodyShift*71)/100);
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI DEPAN]
void LenggokKiriDepan (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*71)/100);
    BodyPosX = -((BodyShift*71)/100);
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN BELAKANG]
void LenggokKananBelakang (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*71)/100);
    BodyPosX = ((BodyShift*71)/100);
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI BELAKANG]
void LenggokKiriBelakang (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*71)/100);
    BodyPosX = -((BodyShift*71)/100);
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK ATAS]
void LenggokAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = 0;
    BodyPosY = BodyHeight+BodyShift;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK BAWAH]
void LenggokBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = 0;
    BodyPosY = BodyHeight-BodyShift;
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK DEPAN ATAS]
void LenggokDepanAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*71)/100);
    BodyPosX = 0;
    BodyPosY = BodyHeight+((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK BELAKANG ATAS]
void LenggokBelakangAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*71)/100);
    BodyPosX = 0;
    BodyPosY = BodyHeight+((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN ATAS]
void LenggokKananAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = ((BodyShift*71)/100);
    BodyPosY = BodyHeight+((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI ATAS]
void LenggokKiriAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = -((BodyShift*71)/100);
    BodyPosY = BodyHeight+((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN DEPAN ATAS]
void LenggokKananDepanAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*58)/100);
    BodyPosX = ((BodyShift*58)/100);
    BodyPosY = BodyHeight+((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI DEPAN ATAS]
void LenggokKiriDepanAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*58)/100);
    BodyPosX = -((BodyShift*58)/100);
    BodyPosY = BodyHeight+((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN BELAKANG ATAS]
void LenggokKananBelakangAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*58)/100);
    BodyPosX = ((BodyShift*58)/100);
    BodyPosY = BodyHeight+((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI BELAKANG ATAS]
void LenggokKiriBelakangAtas (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*58)/100);
    BodyPosX = -((BodyShift*58)/100);
    BodyPosY = BodyHeight+((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK DEPAN BAWAH]
void LenggokDepanBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*71)/100);
    BodyPosX = 0;
    BodyPosY = BodyHeight-((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK BELAKANG BAWAH]
void LenggokBelakangBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*71)/100);
    BodyPosX = 0;
    BodyPosY = BodyHeight-((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN BAWAH]
void LenggokKananBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = ((BodyShift*71)/100);
    BodyPosY = BodyHeight-((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI BAWAH]
void LenggokKiriBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = 0;
    BodyPosX = -((BodyShift*71)/100);
    BodyPosY = BodyHeight-((BodyShift*71)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN DEPAN BAWAH]
void LenggokKananDepanBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*58)/100);
    BodyPosX = ((BodyShift*58)/100);
    BodyPosY = BodyHeight-((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI DEPAN BAWAH]
void LenggokKiriDepanBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = ((BodyShift*58)/100);
    BodyPosX = -((BodyShift*58)/100);
    BodyPosY = BodyHeight-((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KANAN BELAKANG BAWAH]
void LenggokKananBelakangBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*58)/100);
    BodyPosX = ((BodyShift*58)/100);
    BodyPosY = BodyHeight-((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[LENGGOK KIRI BELAKANG BAWAH]
void LenggokKiriBelakangBawah (int BodyShiftInput)
{
    BodyShift = BodyShiftInput;
    BodyShiftCheck();
    BodyPosZ = -((BodyShift*58)/100);
    BodyPosX = -((BodyShift*58)/100);
    BodyPosY = BodyHeight-((BodyShift*58)/100);
    DoStaticMovement();
}

//--------------------------------------------------------------------
//[BERDIRI TENGAH]
void BerdiriTengah (void)
{
    BodyPosZ = 0;
    BodyPosX = 0;
    BodyPosY = BodyHeight;
    DoStaticMovement();
}

void UpdateGaitTravelTime (void)
{
	//untuk mengubah traveltime
}

void AktifkanModeSetengahTurun()
{
    GaitSelect(5);
    SetBodyHeight(65);
    SetLegLiftHeight(20);
	SetTravelSpeed(100);
	SetFrameTime(80);
	timer.attach(&attime,0.001*FrameTime);
}

void AktifkanModeStandard()
{
	GaitSelect(5);//(5);
    SetBodyHeight(50);
    SetLegLiftHeight(40);
	SetTravelSpeed(100);
	SetFrameTime(25);
	timer.attach(&attime,0.001*FrameTime);

}

void kalibrasiservo(int input)
{
	int inputoffsettibia;
    inputoffsettibia = input/10;
    Servo.MultSetGoal(
                       150,0.2, //LF Coxa
                       145,0.2, //LF Femur
                       150 - inputoffsettibia,0.2, //LF Tibia
                       150,0.2, //RF Coxa
                       150,0.2, //RF  Femur
                       150 + inputoffsettibia,0.2, //RF Tibia
                       150,0.2, //LM Coxa
                       150,0.2, //LM Femur
                       150 - inputoffsettibia,0.2, //LM Tibia
                       150,0.2, //RM Coxa
                       155,0.2, //RM Femur
                       150 + inputoffsettibia,0.2, //RM Tibia
                       150,0.2, //LR Coxa
                       150,0.2, //LR Femur
                       150 - inputoffsettibia,0.2, //LR Tibia
                       150,0.2, //RR Coxa
                       150,0.2, //RR Femur
                       150 + inputoffsettibia,0.2  //RR Tibia
                       );
    wait(3);
}



void SetGlobalSpeed(int input)
{
	//SetTravelSpeed(input);
	FrameTime=(((20*100000)/(684*input)));
}

void attime()
{		//cek sensor uneven floor
		//ADCInfraredBawah = bacaADC2.read_u16();
		//led_counter++;
    //UpdateGaitTravelTime();
    GaitSequencer();
		//GaitGenerator1();
    //GaitGeneratorCurve();
   IKCalculation();
   // CheckAngles();
   ServoDriver(SpeedServo);

//		_interrupt();
//		if(Mode==PADAMKANAPI)
//		{
//				if(led_counter>4)
//				{
//						LED	 = !LED;
//						led_counter = 0;
//				}
//		}
//		else
//		{
//				LED = 0;
//				led_counter=0;
//		}

}

void Berdiri()
{
    GaitSelect(5);
    SetBodyHeight(75);
    SetLegLiftHeight(35);
    SetGlobalSpeed(25);
    GetReady(95,450);
    HadapNormal();
    timer.attach(&attime,0.001*FrameTime);
}

