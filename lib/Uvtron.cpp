#include "Uvtron.h"

Uvtron::Uvtron(PinName a) : _a(a)
{
		Counter=0;
		PrevCounter=0;
		NextCounter=0;
		Flag=0;
		_a.mode(PullUp);
		_a.rise(this, &Uvtron::Count);
}

void Uvtron::Count()
{
		Counter++;
}

void Uvtron::Read()
{
	
		PrevCounter = NextCounter;
		NextCounter = Counter;

	
	if(NextCounter>(PrevCounter)&&Flag==0)
	{
			Flag=1;
			Counter=0;
	}
	else if (NextCounter==PrevCounter&&Flag==1)
	{
			Flag=0;
	}
}

void Uvtron::UVScan()
{
		PrevCounter = NextCounter;
		NextCounter = Counter;
	
		if((NextCounter>PrevCounter) && (FlagScan==0)){
						FlagScan = 1;
						Counter = 0;
		}
		else{
				//FlagScan = 0;
		}
}



