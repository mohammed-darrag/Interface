#include "STDtypes.h"
#include "sensors_inter.h"
u16 temparr[10];
u16 tempfilter;
u16 tempunfilter;
u8 flag;

void temp_init(void)
{
	u8 i=0;
	tempfilter=sensors_readtemp();
	
}

void temp_runnable(void)
{
	static u8 i=0;
	u16 j,sum=0,temp=0;
    temparr[i]=sensors_readtemp();
	tempunfilter=temparr[i];
	i++;
	
	if(i==10)
	{
		
		i=0;
		flag=1;
		
	}
	if (flag==1)
	{
		for (j=0;j<10;j++)
		{
			sum+=temparr[j];
		}
		tempfilter=sum/10;
		
	}
}

u16 temp_getfilter_value(void)
{
	
return tempfilter;

}

u16 temp_getunfilter_value(void)
{
	
	return tempunfilter;

}