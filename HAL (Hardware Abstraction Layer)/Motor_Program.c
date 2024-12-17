#include "STDtypes.h"
#include "DIO_Inter.h"
#include "MOTOR_CFG.h"
#include "MOTOR_INTER.h"


void Motor_CW(MOTOR_T motor)
{
	switch(motor)
	{
		case M1:
		DIO_writepin(M1_IN1,HIGH);
		DIO_writepin(M1_IN2,LOW);
		break;
		case M2:
		DIO_writepin(M2_IN1,HIGH);
		DIO_writepin(M2_IN2,LOW);
		break;
	}
	
}

void Motor_CCW(MOTOR_T motor)
{
	switch(motor)
	{
		case M1:
		DIO_writepin(M1_IN1,LOW);
		DIO_writepin(M1_IN2,HIGH);
		break;
		case M2:
		DIO_writepin(M2_IN1,LOW);
		DIO_writepin(M2_IN2,HIGH);
		break;
	}
	
}

void Motor_Stop(MOTOR_T motor)
{
	switch(motor)
	{
		case M1:
		DIO_writepin(M1_IN1,LOW);
		DIO_writepin(M1_IN2,LOW);
		break;
		case M2:
		DIO_writepin(M2_IN1,LOW);
		DIO_writepin(M2_IN2,LOW);
		break;
	}
	
}