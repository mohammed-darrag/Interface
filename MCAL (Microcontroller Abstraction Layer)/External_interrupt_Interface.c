#include "MEMMAP.h"
#include "STDtypes.h"
#include "UTILS.h"
#include "EXTERN_INTER.h"


/********************************POINTER TO FUNCATION TO BE ACCESS***************************************************/


static void(*INT0_fptr) (void)=NULLPTR;
static void(*INT1_fptr) (void)=NULLPTR;
static void(*INT2_fptr) (void)=NULLPTR;

/**************************************************************ENABLE/DISABLE FUNCATIONS ***************************************/

void EXI_Enable(ExInterruptsource_type interrupt)
{
	switch(interrupt)
	{
		case EX_INT0:
		SET_BIT(GICR,INT0);
		break;
		case EX_INT1:
		SET_BIT(GICR,INT1);
		break;
		
		case EX_INT2:
		SET_BIT(GICR,INT2);
		break;
	}
}

void EXI_Disable(ExInterruptsource_type interrupt)
{
	switch(interrupt)
	{
		case EX_INT0:
		CLR_BIT(GICR,INT0);
		break;
		case EX_INT1:
		CLR_BIT(GICR,INT1);
		break;
		
		case EX_INT2:
		CLR_BIT(GICR,INT2);
		break;
	}
}

void EXI_Init(void)
{
	EXI_TriggerEdge(EX_INT0, FALLING_EDGE);
	EXI_TriggerEdge(EX_INT1, FALLING_EDGE);
	EXI_TriggerEdge(EX_INT2, FALLING_EDGE);
	
}

void EXI_TriggerEdge(ExInterruptsource_type interrupt,TriggerEdge_type Edge)
{
	switch(interrupt)
	{
		case EX_INT0:
		switch(Edge)
		{
			case LOW_LEVEL:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
		}
		
		break;
		case EX_INT1:
		switch(Edge)
		{
			case LOW_LEVEL:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
		}
		
		break;
		case EX_INT2:
		switch(Edge)
		{
			
			case FALLING_EDGE:
			CLR_BIT(MCUCR,ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC2);
			break;
			default:
			CLR_BIT(MCUCR,ISC2);
			
		}
		break;
	}
	
}

/***********************************call back funcation**********************************/

void EXI_setcallback(ExInterruptsource_type interrupt,void(*localptr)(void))
{
	switch(interrupt)
	{
		case  EX_INT0:
		INT0_fptr=localptr;
		break;
		
		case  EX_INT1:
		INT1_fptr=localptr;
		break;
		
		case  EX_INT2:
		INT2_fptr=localptr;
		break;
	}
	
}

/************************************isr**************************************************/

ISR(INT0_vect)
{
	if (INT0_fptr!=NULLPTR)
	{
		INT1_fptr();
	}
	
}


ISR(INT1_vect,ISR_NOBLOCK)
{
	if (INT1_fptr!=NULLPTR)
	{
		INT1_fptr();
	}
}

ISR(INT2_vect)
{
	if (INT2_fptr!=NULLPTR)
	{
		INT2_fptr();
	}
}



