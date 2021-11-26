// Bismillah
// Jagalah Kebersihan dan kerapihan codingan
// File name : wallfollowing.cpp
// author/editor : Babang
// created on : 10 Maret 2016
// Desc : Mengatur gerakan dasar dan wallfollow

#include "wallfollowing.h"
#include "ObjectVariabel.h"

void putar180()
{
    PutarKanan(300);
    wait(1.7);
    Stop();
}

void putarKanan90()
{
    PutarKanan(300);
    wait(1.0);
    Stop();
}

void putarKiri90()
{
    PutarKiri(300);
    wait(1.0);
    Stop();
}

void wallKananSlow(int SetPointJarak, int Kp,int Kd){
    unsigned char threshold = 30;
	//Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 17;
    unsigned char KananDekat = 23;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

    HindarFurniture(KIRI);
//    if(JarakPingDepan<=15){
//        if(JarakPingDepan+10<JarakDepan){
//        	DisplayLCD("FURNITURE");
//        	QuickStop();
//        	wait(1);
//        	for (int i = 0; i < 10 && JarakBelakang > 8; ++i) {
//				MundurLurus(35);
//				wait(0.1);
//			}
//        	QuickStop();
//        	PutarKiri(120);
//        	wait(1);
////        	GetArah(400);
////        	ResetArah();
////        	PutarSampaiArah(ARAHTIANG);
////        	while(JarakKiri>9){
////        		GeserKiri(40);
////        		wait(0.1);
////        	}
////        	do{
////        		wallKiriSlow(14,25,10);
////        		wait(0.1);
////        	}while(GarisTengah==HITAM);
//        	QuickStop();
//        	wait(0.1);
//        }
//    }
        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
        {
            //SetGlobalSpeed(45);
            //SetTravelSpeed(55);
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKanan(50);
            if(JarakKanan>11)
            {
            	MajuBelokKanan(50);
            }
            else
            {
                MajuLurus(40);
            }
        }
        else // dinding kanan masih terdeteksi
        {
        	if(JarakKanan>9){
        		GeserKanan(30);
        		wait(0.2);
        		if (JarakSRKanan < JarakKanan && JarakSBKanan < JarakKanan) {
					PutarKiri(100);
					wait(0.1);
				}
        	}
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                //SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                //SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kiri)
            {
                //SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        //SetGlobalSpeed(40);
        //SetTravelSpeed(50);
    	PutarKiri(200);
    	wait(0.1);
    	do{
    		PutarKiri(150);
    		wait(0.1);
    	}while(JarakSRKanan<11);
    	if(JarakKanan>9){
    		GeserKanan(30);
    		wait(0.2);
    	}

    }
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}



void wallKananApi(int SetPointJarak, int Kp,int Kd){
    unsigned char threshold = 30;
	//Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 17;
    unsigned char KananDekat = 16;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }
    HindarFurnitureWallApi(KIRI);
  //  HindarFurniture(KIRI);
//    if(JarakPingDepan<=15){
//		if(JarakPingDepan+10<JarakDepan){
//			DisplayLCD("FURNITURE");
//			QuickStop();
//			wait(1);
//			for (int i = 0; i < 10 && JarakBelakang > 8; ++i) {
//				MundurLurus(35);
//				wait(0.1);
//			}
//			QuickStop();
//			PutarKiri(120);
//			wait(1);
////        	GetArah(400);
////        	ResetArah();
////        	PutarSampaiArah(ARAHTIANG);
////        	while(JarakKiri>9){
////        		GeserKiri(40);
////        		wait(0.1);
////        	}
////        	do{
////        		wallKiriSlow(14,25,10);
////        		wait(0.1);
////        	}while(GarisTengah==HITAM);
//			QuickStop();
//			wait(0.1);
//		}
//	}

    SetGlobalSpeed(35);
    SetTravelSpeed(40);
        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
    	if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
        {
            //SetGlobalSpeed(45);
            //SetTravelSpeed(55);
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKanan(50);
            if(JarakKanan>11)
            {
            	MajuBelokKanan(50);
            }
            else
            {
                PutarKanan(30);
                wait(0.2);
            	MajuLurus(40);
            }
        }
        else // dinding kanan masih terdeteksi
        {
        	if(JarakKanan>8){
        		GeserKanan(30);
        		wait(0.2);
        	}
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                //SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(30);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                //SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kiri)
            {
                //SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
	{
		SetGlobalSpeed(40);
		//SetTravelSpeed(50);
		PutarKiri(80);
		wait(0.1);
		if(!ApiSekitar(60))
		{
				PutarKiri(80);
				wait(0.1);
//            if(JarakKanan>8){
//    			GeserKanan(30);
//    			wait(0.2);
//    		}
		}

	}
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}

void wallKiriApi(int SetPointJarak, int Kp,int Kd){
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKiri;
    int DerivativeErrorJarak    = PrevJarakSRKiri - JarakSRKiri;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
    unsigned char threshold = 30;
    //Parameter Wall Following
    unsigned char DepanDekat = 16;
    unsigned char KiriDekat = 16;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }
    SetGlobalSpeed(35);
    SetTravelSpeed(40);
    HindarFurnitureWallApi(KANAN);
    //HindarFurniture(KANAN);

//    if(JarakPingDepan<=15){
//    	if(JarakPingDepan+10<JarakDepan){
//    		DisplayLCD("FURNITURE");
//    		QuickStop();
//    		wait(1);
//        	for (int i = 0; i < 10 && JarakBelakang > 8; ++i) {
//				MundurLurus(35);
//				wait(0.1);
//			}
//        	QuickStop();
//        	PutarKanan(120);
//        	wait(1);
////    		GetArah(400);
////
////    		ResetArah();
////    		PutarSampaiArah(ARAHTIANG);
////    		while(JarakKanan>9){
////    			GeserKanan(40);
////    			wait(0.1);
////    		}
////    		do{
////    			wallKananSlow(14,25,10);
////    			wait(0.1);
////    		}while(GarisTengah==HITAM);
//    		QuickStop();
//    		wait(0.1);
//    	}
//    }

        //WallFollow
//    if(JarakKiri>9){
//		GeserKiri(30);
//		wait(0.2);
//	}
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
    	if(JarakSRKiri > KiriDekat )//artinya di kiri ada belokan
        {
            //SetGlobalSpeed(40);
            //SetTravelSpeed(50);
            if(JarakKiri>11)
            {
            MajuBelokKiri(50);
            }
            else
            {   PutarKiri(30);
            	wait(0.2);
                MajuLurus(40);
            }
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKiri(50);
        }
        else // dinding kiri masih terdeteksi
        {
        	if(JarakKiri>9){
				GeserKiri(30);
				wait(0.2);
			}
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {

                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                //SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kanan)
            {
                SetGlobalSpeed(45);
                //SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        //SetTravelSpeed(50);
    	PutarKanan(80);
    	wait(0.1);
    	if(!ApiSekitar(60))
    	{
        		PutarKanan(80);
        		wait(0.1);
//            if(JarakKiri>8){
//    			GeserKiri(30);
//    			wait(0.2);
//    		}
    	}

    }

}


void wallKiriSlow(int SetPointJarak, int Kp,int Kd){
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKiri;
    int DerivativeErrorJarak    = PrevJarakSRKiri - JarakSRKiri;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
    unsigned char threshold = 30;
    //Parameter Wall Following
    unsigned char DepanDekat = 16;
    unsigned char KiriDekat = 23;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

    HindarFurniture(KANAN);
//    if(JarakPingDepan<=15){
//    	if(JarakPingDepan+10<JarakDepan){
//    		DisplayLCD("FURNITURE");
//    		QuickStop();
//    		wait(1);
//        	for (int i = 0; i < 10 && JarakBelakang > 8; ++i) {
//				MundurLurus(35);
//				wait(0.1);
//			}
//        	QuickStop();
//        	PutarKanan(120);
//        	wait(1);
////    		GetArah(400);
////
////    		ResetArah();
////    		PutarSampaiArah(ARAHTIANG);
////    		while(JarakKanan>9){
////    			GeserKanan(40);
////    			wait(0.1);
////    		}
////    		do{
////    			wallKananSlow(14,25,10);
////    			wait(0.1);
////    		}while(GarisTengah==HITAM);
//    		QuickStop();
//    		wait(0.1);
//    	}
//    }

        //WallFollow
        if(JarakDepan > DepanDekat)//artinya depannya jauh
        {
            if(JarakSRKiri > KiriDekat )//artinya di kiri ada belokan
            {
                SetGlobalSpeed(40);
                //SetTravelSpeed(50);
                if(JarakKiri>13)
                {
                MajuBelokKiri(55);
                }
                else
                {
                    MajuLurus(40);
                }
                //      timer.attach(&attime,0.001*FrameTime);
                //MajuBelokKiri(50);
            }
            else // dinding kiri masih terdeteksi
            {
            	if(JarakKiri>9){
    				GeserKiri(30);
    				wait(0.2);
    				if (JarakSRKiri < JarakKiri && JarakSBKiri < JarakKiri) {
    					PutarKanan(100);
    					wait(0.2);
    				}
    			}
                //cek orientasi robot relatif terhadap set point
                if(PersenBelok == 0)//robot lurus
                {
                    SetGlobalSpeed(45);
                    SetTravelSpeed(55);
                    //          timer.attach(&attime,0.001*FrameTime);
                    MajuLurus(40);
                }
                else if(PersenBelok > 0)//ada penyimpangan ke kanan
                {
                    SetGlobalSpeed(45);
                    //SetTravelSpeed(55);
                    //      timer.attach(&attime,0.001*FrameTime);
                    MajuBelokKanan((unsigned char)PersenBelok);
                }
                else  //persen belok < 0 (ada penyimpangan ke kanan)
                {
                    SetGlobalSpeed(45);
                    //SetTravelSpeed(55);
                    //  timer.attach(&attime,0.001*FrameTime);
                    MajuBelokKiri((unsigned char)(-PersenBelok));
                }
            }
        }
        else    //jika depannya dekat
        {
            SetGlobalSpeed(40);
            //SetTravelSpeed(50);

        	PutarKanan(200);
        	wait(0.1);
        	do{
        		PutarKanan(150);
        		wait(0.1);
        	} while(JarakSRKiri<11);

            if(JarakKiri>9){
    			GeserKiri(30);
    			wait(0.2);
    		}
        }



}

void wallKanan(int SetPointJarak, int Kp,int Kd){
    unsigned char threshold = 30;
	//Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 14;
    unsigned char KananDekat = 23;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
        {
            SetGlobalSpeed(45);
            SetTravelSpeed(55);
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKanan(50);
            if(JarakKanan>11)
            {
            	MajuBelokKanan(50);
            }
            else
            {
                MajuLurus(40);
            }
        }
        else // dinding kanan masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kiri)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKiri(200);
        wait(1);
    }
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}
void wallKananCepat(int SetPointJarak, int Kp,int Kd){
    unsigned char threshold = 30;
	//Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 16;
    unsigned char KananDekat = 23;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
        {
            SetGlobalSpeed(45);
            SetTravelSpeed(55);
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKanan(50);
            if(JarakKanan>11)
            {
            	MajuBelokKanan(51);
            }
            else
            {
                MajuLurus(40);
            }
        }
        else // dinding kanan masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kiri)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKiri(200);
        wait(1);
    }
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}
void wallKanan2A(int SetPointJarak, int Kp,int Kd){ //kanan jauh agak lambat
    unsigned char threshold = 30;
	//Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 13;
    unsigned char KananDekat = 17;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
        {
            SetGlobalSpeed(45);
            SetTravelSpeed(55);
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKanan(50);
            if(JarakKanan>11)
            {
            	MajuBelokKanan(41);
            }
            else
            {
                MajuLurus(40);
            }
        }
        else // dinding kanan masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kiri)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKiri(200);
        wait(1);
    }
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}

void wallKanan2(int SetPointJarak, int Kp,int Kd){ //maju belok kanankecil
    unsigned char threshold = 30;
	//Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 13;
    unsigned char KananDekat = 17;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
        {
            SetGlobalSpeed(45);
            SetTravelSpeed(55);
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKanan(50);
            if(JarakKanan>11)
            {
            	MajuBelokKanan(39);
            }
            else
            {
                MajuLurus(40);
            }
        }
        else // dinding kanan masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kiri)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKiri(210);
        wait(1);
    }
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}

void wallKanan3(int SetPointJarak, int Kp,int Kd){ //maju belok Depan mentok
    unsigned char threshold = 30;
	//Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 10;
    unsigned char KananDekat = 15;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
        {
            SetGlobalSpeed(45);
            SetTravelSpeed(55);
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKanan(50);
            if(JarakKanan>11)
            {
            	MajuBelokKanan(40);
            }
            else
            {
                MajuLurus(40);
            }
        }
        else // dinding kanan masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kiri)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKiri(200);
        wait(1);
    }
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}



//void wallKanan(int SetPointJarak, int Kp,int Kd)
////nilai PING belum dikalibrasi, pake asumsi dulu
//{
//	int ErrorJarak              = SetPointJarak - JarakSRKanan;
//	int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
//	int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
//	//Parameter Wall Following
//	unsigned char DepanDekat = 11;
//	unsigned char KananDekat = 18;
//
//    //pembatasan nilai
//    if(PersenBelok > 30)
//    {
//        PersenBelok = 30;
//    }
//    if(PersenBelok < -30)
//    {
//        PersenBelok = -30;
//    }
//
//    if(JarakDepan > DepanDekat)//artinya depannya jauh
//    {
//        if(JarakSRKanan > KananDekat )//artinya di kanan ada belokan
//        {
//             MajuBelokKanan(30);
//        }
//        else // dinding kanan masih terdeteksi
//        {
//            //cek orientasi robot relatif terhadap set point
//            if(PersenBelok == 0)//robot lurus
//            {
//                MajuLurus(50);
//            }
//            else if(PersenBelok > 0)//ada penyimpangan ke kanan
//            {
//                MajuBelokKiri((unsigned char)PersenBelok);
//            }
//            else  //persen belok < 0 (ada penyimpangan ke kiri)
//            {
//                MajuBelokKanan((unsigned char)(-PersenBelok));
//            }
//        }
//    }
//    else    //jika depannya dekat
//    {
//         //cek lagi keadaannya
//         if(JarakKiri > 30)//di
//         {
//            PutarKiri(250); //putar kiri 90 derajat
//			wait(0.5);
//         }
//         if(JarakSRKanan>KananDekat)
//         {
//            do
//            {
//                PutarKanan(250); //putar kanan 180 derajat
//
//            }
//            while(JarakDepan<=20);
//
//         }
//
//         else
//         {
//            do
//            {
//                PutarKiri(250); // putar kiri 180 derajat
//
//            }
//            while(JarakDepan<=15);
//         }
//
//    }
//    PrevJarakSRKanan = JarakSRKanan;
//
//
//}


void wallKiri(int SetPointJarak, int Kp,int Kd){  
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKiri;
    int DerivativeErrorJarak    = PrevJarakSRKiri - JarakSRKiri;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
    unsigned char threshold = 30;
    //Parameter Wall Following
    unsigned char DepanDekat = 13;
    unsigned char KiriDekat = 18;
        
    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }
        
        //WallFollow   
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKiri > KiriDekat )//artinya di kiri ada belokan
        {    
            SetGlobalSpeed(40);
            SetTravelSpeed(50);
            if(JarakKiri>14)
            {
            MajuBelokKiri(34);
            }
            else 
            {
                MajuLurus(40);
            }      
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKiri(50);                       
        }
        else // dinding kiri masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)PersenBelok);            
            }
            else  //persen belok < 0 (ada penyimpangan ke kanan)
            { 
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)(-PersenBelok));     
            }        
        }
    } 
    else    //jika depannya dekat
    {   
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKanan(200);
        wait(1);
    }    

}

void wallKiriA(int SetPointJarak, int Kp,int Kd){
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKiri;
    int DerivativeErrorJarak    = PrevJarakSRKiri - JarakSRKiri;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
    unsigned char threshold = 30;
    //Parameter Wall Following
    unsigned char DepanDekat = 13;
    unsigned char KiriDekat = 18;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKiri > KiriDekat )//artinya di kiri ada belokan
        {
            SetGlobalSpeed(40);
            SetTravelSpeed(50);
            if(JarakKiri>14)
            {
            MajuBelokKiri(38);
            }
            else
            {
                MajuLurus(40);
            }
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKiri(50);
        }
        else // dinding kiri masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kanan)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKanan(200);
        wait(1);
    }

}


void wallKiri2(int SetPointJarak, int Kp,int Kd){ //belok jauh cepat
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKiri;
    int DerivativeErrorJarak    = PrevJarakSRKiri - JarakSRKiri;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
    unsigned char threshold = 40;
    //Parameter Wall Following
    unsigned char DepanDekat = 13;
    unsigned char KiriDekat = 15;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKiri > KiriDekat )//artinya di kiri ada belokan
        {
            SetGlobalSpeed(40);
            SetTravelSpeed(50);
            if(JarakKiri>12)
            {
            MajuBelokKiri(60);
            }
            else
            {
                MajuLurus(40);
            }
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKiri(50);
        }
        else // dinding kiri masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kanan)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKanan(200);
        wait(1);
    }

}

void wallKiri2B(int SetPointJarak, int Kp,int Kd){ //belok jauh cepat
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKiri;
    int DerivativeErrorJarak    = PrevJarakSRKiri - JarakSRKiri;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
    unsigned char threshold = 30;
    //Parameter Wall Following
    unsigned char DepanDekat = 13;
    unsigned char KiriDekat = 15;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKiri > KiriDekat )//artinya di kiri ada belokan
        {
            SetGlobalSpeed(40);
            SetTravelSpeed(50);
            if(JarakKiri>14)
            {
            	MajuBelokKiri(60);
            }
            else
            {
                MajuLurus(40);
            }
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKiri(50);
        }
        else // dinding kiri masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kanan)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKanan(200);
        wait(1);
    }

}

void wallKiri3(int SetPointJarak, int Kp,int Kd){ //depan dekat sekali
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKiri;
    int DerivativeErrorJarak    = PrevJarakSRKiri - JarakSRKiri;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));
    unsigned char threshold = 30;
    //Parameter Wall Following
    unsigned char DepanDekat = 11;
    unsigned char KiriDekat = 18;

    //pembatasan nilai
    if(PersenBelok > threshold)
    {
        PersenBelok = threshold;
    }
    if(PersenBelok < -threshold)
    {
        PersenBelok = -threshold;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKiri > KiriDekat )//artinya di kiri ada belokan
        {
            SetGlobalSpeed(40);
            SetTravelSpeed(50);
            if(JarakKiri>14)
            {
            MajuBelokKiri(40);
            }
            else
            {
                MajuLurus(40);
            }
            //      timer.attach(&attime,0.001*FrameTime);
            //MajuBelokKiri(50);
        }
        else // dinding kiri masih terdeteksi
        {
            //cek orientasi robot relatif terhadap set point
            if(PersenBelok == 0)//robot lurus
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //          timer.attach(&attime,0.001*FrameTime);
                MajuLurus(40);
            }
            else if(PersenBelok > 0)//ada penyimpangan ke kanan
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //      timer.attach(&attime,0.001*FrameTime);
                MajuBelokKanan((unsigned char)PersenBelok);
            }
            else  //persen belok < 0 (ada penyimpangan ke kanan)
            {
                SetGlobalSpeed(45);
                SetTravelSpeed(55);
                //  timer.attach(&attime,0.001*FrameTime);
                MajuBelokKiri((unsigned char)(-PersenBelok));
            }
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKanan(200);
        wait(1);
    }

}


void wallLurus(int SetPointJarak, int Kp,int Kd){
    //Parameter PID
    int ErrorJarak              = SetPointJarak - JarakSRKanan;
    int DerivativeErrorJarak    = PrevJarakSRKanan - JarakSRKanan;
    int PersenBelok             = (((Kp*ErrorJarak)/10)+((Kd*DerivativeErrorJarak)/10));

    //Parameter Wall Following
    unsigned char DepanDekat = 11;
    unsigned char KananDekat = 18;

    //pembatasan nilai
    if(PersenBelok > 100)
    {
        PersenBelok = 100;
    }
    if(PersenBelok < -100)
    {
        PersenBelok = -100;
    }

        //WallFollow
    if(JarakDepan > DepanDekat)//artinya depannya jauh
    {
        if(JarakSRKanan < KananDekat )//artinya di kanan ada belokan
        {
        	//cek orientasi robot relatif terhadap set point
			if(PersenBelok == 0)//robot lurus
			{
				SetGlobalSpeed(45);
				SetTravelSpeed(55);
				//          timer.attach(&attime,0.001*FrameTime);
				MajuLurus(60);
			}
			else if(PersenBelok > 0)//ada penyimpangan ke kanan
			{
				SetGlobalSpeed(45);
				SetTravelSpeed(55);
				//      timer.attach(&attime,0.001*FrameTime);
				MajuBelokKiri((unsigned char)PersenBelok);
			}
			else  //persen belok < 0 (ada penyimpangan ke kiri)
			{
				SetGlobalSpeed(45);
				SetTravelSpeed(55);
				//  timer.attach(&attime,0.001*FrameTime);
				MajuBelokKanan((unsigned char)(-PersenBelok));
			}

        }
        else // dinding kanan masih terdeteksi
        {
        	SetGlobalSpeed(45);
			SetTravelSpeed(55);
			//      timer.attach(&attime,0.001*FrameTime);
			//MajuBelokKanan(50);
			if(JarakKanan>11)
			{
				MajuBelokKanan(60);
			}
			else
			{
				MajuLurus(60);
			}
        }
    }
    else    //jika depannya dekat
    {
        SetGlobalSpeed(40);
        SetTravelSpeed(50);
        PutarKiri(200);
        wait(1);
    }
    PrevJarakKanan = JarakKanan;
    PrevJarakSRKanan = JarakSRKanan;
}
