/*
 * timer0.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Amr Mohamed
 */

#ifndef MCAL_TIMERS_TIMER0_H_
#define MCAL_TIMERS_TIMER0_H_

#include"../../utilities/std_types.h"
#include"../../utilities/common_macros.h"
#include"../../utilities/micro_config.h"
#include"../../utilities/Registers.h"


#define NULL    ((void*)0)




typedef enum
{
	  NO_CLOCK
	, F_CPU_CLOCK
	, F_CPU_8
	, F_CPU_64
	, F_CPU_256
	, F_CPU_1024

}Timer0_Clock;


typedef enum
{
	  NORMAL_MODE
	, CTC_MODE
	, PWM_MODE

}Timer0_Mode;

typedef enum
{
	  interrupt=0
	, polling
}operation;


typedef struct
{
	 Timer0_Mode Mode;
	 uint8 InitialValue;
	 Timer0_Clock Clock;
	 uint8 CompareValue;
	 uint8 DutyCycle;
	 operation Op;           // Polling or Interrupt
}Timer0_ConfigType;




error_state Timer0_init(const Timer0_ConfigType * Config_Ptr);

void Timer0_OVF_setCallBack(void(*a_ptr)(void));

void Timer0_CMP_setCallBack(void(*a_ptr)(void));

error_state Timer0_DeInit(void);



#endif /* MCAL_TIMERS_TIMER0_H_ */
