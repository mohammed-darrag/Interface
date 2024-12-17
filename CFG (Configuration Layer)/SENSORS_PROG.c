

#include "STDtypes.h"
#include "ADC_INTER.h"
#include "SENSORS_INTER.h"
#include "SENSORS_CFG.h"


u16 sensors_readtemp(void)
{
	u16 volt =ADC_Readvoit(LM35_CH);
	u16 temp=volt;
	return temp ;
	
}


