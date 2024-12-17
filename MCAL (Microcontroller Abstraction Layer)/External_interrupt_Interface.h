


#ifndef EXTERN_INTER_H_
#define EXTERN_INTER_H_



typedef enum
{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}TriggerEdge_type;

typedef enum
{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
	
}ExInterruptsource_type;

void EXI_Init(void);

#define GLOBAL_ENABLE   sei
void EXI_Enable(ExInterruptsource_type interrupt);
void EXI_Disable(ExInterruptsource_type interrupt);
void EXI_TriggerEdge(ExInterruptsource_type interrupt,TriggerEdge_type Edge);
void EXI_setcallback(ExInterruptsource_type interrupt,void(*localptr)(void));






#endif /* EXTERN_INTER_H_ */