
#ifndef MOTOR_INTER_H_
#define MOTOR_INTER_H_



typedef enum 
{
	M1,
	M2,
	M3,
	M4
}MOTOR_T;

void Motor_CW(MOTOR_T);
void Motor_CCW(MOTOR_T);
void Motor_Stop(MOTOR_T);




#endif /* MOTOR_INTER_H_ */