#include "STDtypes.h"
#include "MEMMAP.h"
#include "UTILS.h"
#include "ADC_INTER.h"
u8 busyflag;



void ADC_init(ADC_VREF_t VREF,ADC_Prescaler_t Scaler)
{
	switch(VREF)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_VCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
		
	}
	
	SET_BIT(ADCSRA,ADEN);
	
	ADCSRA&=0xF8;
	Scaler&=0x07;
	ADCSRA|=Scaler;
	
	
}


u16 ADC_Read(ADC_Channel_t ch)
{
	/* select channel */
	ADMUX&=0xE0;
	ADMUX |=ch;
	/* start Conversion */
	SET_BIT(ADCSRA,ADSC);
	/* wait until ADC end conversion */
   while(GET_BIT(ADCSRA,ADSC));
   /* read register */
   return ADC;  // bring value from ADC and add pointer called value pointed to short value that's mean bing ADCL AND ADCH VALUES 
 		
}
void ADC_startconversion(ADC_Channel_t CH)
{
		/* select channel */
		ADMUX&=0xE0;
		ADMUX |=CH;
		/* start Conversion */ 
		SET_BIT(ADCSRA,ADSC);
		/* wait until ADC end conversion */
	    busyflag=1;
}
u16 ADC_GETRead(void)
{
	 while(GET_BIT(ADCSRA,ADSC));
	 /* read register */
	 return ADC;  // bring value from ADC and add pointer called value pointed to short value that's mean bing ADCL AND ADCH VALUES	
}

u8  ADC_GETReadperiodic(u16 *pdata)
{
	 if ( GET_BIT(ADCSRA,ADSC) )
	 {
		 return 0;
	 }
	 else
	 {
		 *pdata=ADC;
		 busyflag=0;
		 return 1;
	 }
	
}


u16 ADC_Readvoit(ADC_Channel_t channel)
{
	u16 adc=ADC_Read(channel);
	u16 volt=((u32)5000 * adc)/1024;
	
}

u16 ADC_GETReadnoblock(void)
{
	return ADC;
}

