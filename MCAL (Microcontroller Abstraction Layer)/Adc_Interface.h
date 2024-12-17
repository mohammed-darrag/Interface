
#ifndef ADC_INTER_H_
#define ADC_INTER_H_

typedef enum
{
	VREF_AREF,
	VREF_VCC,
	VREF_256
	
}ADC_VREF_t;

typedef enum
{
	ADC_scaler_2=1,
	ADC_scaler_4,
	ADC_scaler_6,
	ADC_scaler_8,
	ADC_scaler_16,
	ADC_scaler_32,
	ADC_scaler_64,
	ADC_scaler_128,
	
}ADC_Prescaler_t;


typedef enum
{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7

}ADC_Channel_t;


void ADC_init(ADC_VREF_t VREF,ADC_Prescaler_t Scaler);
u16 ADC_Read(ADC_Channel_t channel);
void ADC_startconversion(ADC_Channel_t CH);// 1:
u16 ADC_GETRead(void);//                      2:  these three funcation modification for u16 ADC_Read(ADC_Channel_t channel);
u8  ADC_GETReadperiodic(u16 *pdata);//        3:
u16 ADC_Readvoit(ADC_Channel_t channel);
u16 ADC_GETReadnoblock(void);








#endif /* ADC_INTER_H_ */