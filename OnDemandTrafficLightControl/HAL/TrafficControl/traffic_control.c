/*
 * traffic_control.c
 *
 *  Created on: Oct 18, 2022
 *      Author: Amr Mohamed
 */

#include"traffic_control.h"


/**************************************************************************************************************
 *
 *                                      GLOBAL VARIABLES DEFINITIONS
 *
 **************************************************************************************************************/
/*External interrupt configuration*/
ExInterrupt_Config interrupt_config = {External_Interrupt_0_P, RISING_EDGE};
/*Timer0 configurations*/
Timer0_ConfigType timer_config = {NORMAL_MODE,TIMER_INTIAL_VALUE,F_CPU_1024,0,0,interrupt};
/* this global variable is responsible for the state of the car lights for the TrafficControl Module */
Traffic_State car_state = green;
/* this global variable is responsible for counting seconds for the timer Module */
uint8 g_timer = 0;
/* this global variable is responsible for counting the number of overflows for the timer Module */
uint8 g_sec = 0;
/* this global variable is responsible for counting the number of blinks for the yellow LED */
uint8 g_yellow = 0;
/*this global variable is responsible for counting the number presses*/
uint8 g_press = 0;

/**************************************************************************************************************
 *
 *                                      FUNCTION DEFINITIONS
 *
 **************************************************************************************************************/
error_state Traffic_init()
{
	Interrupt_GlobalEnable(ON);
	Timer0_OVF_setCallBack(&TIMER_counter);
	BUTTON_init(BUTTONPORT, 2);
	ExInterrupt_init(&interrupt_config);
	ExInterrupt_CallBack(EXT_INT0, &Traffic_pedestrianMode);
	LED_init(CARSPORT, CARSREDPIN);
	LED_init(CARSPORT, CARSYELLOWPIN);
	LED_init(CARSPORT, CARSGREENPIN);
	LED_init(PEDSPORT, CARSREDPIN);
	LED_init(PEDSPORT, CARSYELLOWPIN);
	LED_init(PEDSPORT, CARSGREENPIN);
	return OK;
}


error_state Traffic_normalMode()
{
	switch(car_state)
	{
	/*#####################################################################*/
	case green:
		CARSGREEN_on();
		PEDSRED_on();
		Traffic_timerDelay(SWITCHINGTIME);
		CARSGREEN_off();
		PEDSRED_off();
		car_state = greentored;
		break;
		/*#####################################################################*/
	case greentored:
		YELLOW_blinks();
		car_state = red;
		break;
	case red:
		CARSRED_on();
		PEDSGREEN_on();
		Traffic_timerDelay(SWITCHINGTIME);
		CARSRED_off();
		PEDSGREEN_off();
		car_state = redtogreen;
		g_press = 0;
		break;
	case redtogreen:
		YELLOW_blinks();
		if( car_state == greentored)
		{
			car_state = red;
		}
		else
		{
			car_state = green;
		}

		break;
		/*#####################################################################*/
	default:
		YELLOW_blinks();
	}
	return OK;

}

void Traffic_pedestrianMode()
{
	ExInterrupt_DeInit(USEDEXINTERRUPT);
	++g_press;
	if(g_press == 1)
	{
		switch(car_state)
		{
		/*#####################################################################*/
		case green:
			g_timer = SWITCHINGTIME;
			car_state = greentored;
			break;
			/*#####################################################################*/
		case greentored:
			g_yellow = 0;
			car_state = greentored;
			break;
		case red:

			break;
		case redtogreen:
			g_yellow = 0;
			car_state = greentored;
			break;
			/*#####################################################################*/
		}
		ExInterrupt_init(&interrupt_config);
	}
}

error_state CARSRED_on()
{
	LED_on(CARSPORT, CARSREDPIN);

	return OK;
}


error_state CARSGREEN_on()
{
	LED_on(CARSPORT, CARSGREENPIN);


	return OK;
}

error_state PEDSRED_on()
{
	LED_on(PEDSPORT, PEDSREDPIN);

	return OK;
}

error_state YELLOW_blinks()
{
	while(g_yellow < SWITCHINGTIME )
	{
		LED_toggle(PEDSPORT, PEDSYELLOWPIN);
		LED_toggle(CARSPORT, CARSYELLOWPIN);
		Traffic_timerDelay(1);
		++g_yellow;
	}
	LED_off(PEDSPORT, PEDSYELLOWPIN);
	LED_off(CARSPORT, CARSYELLOWPIN);
	g_yellow = 0;
	return OK;
}

error_state PEDSGREEN_on()
{
	LED_on(PEDSPORT, PEDSGREENPIN);

	return OK;
}

error_state CARSRED_off()
{
	LED_off(CARSPORT, CARSREDPIN);

	return OK;
}

error_state CARSGREEN_off()
{
	LED_off(CARSPORT, CARSGREENPIN);

	return OK;
}

error_state PEDSRED_off()
{
	LED_off(PEDSPORT, PEDSREDPIN);

	return OK;
}

error_state PEDSGREEN_off()
{
	LED_off(PEDSPORT, PEDSGREENPIN);

	return OK;
}



void TIMER_counter(void)
{
	/********************************************************************************************************************************
	 * [Function Name] : TIMER_counter
	 * [Description] : This function is responsible for incrementing Timer Seconds and Overflows its passed to the ISR of the timer
	 *                 Through a pointer to function in the function Timer0_OVF_setCallBack.
	 * [Args]        : The function takes no arguments .
	 * [Returns]     : The function returns void .
	 *
	 *********************************************************************************************************************************/
	g_sec++;
	if(g_sec == 4)
	{
		g_timer++;
		g_sec = 0;
	}
}

error_state Traffic_timerDelay(uint8 a_time)
{
	/********************************************************************************************************************************
	 * [Function Name] : Traffic_timerDelay
	 * [Description] : This function is responsible for counting seconds using the TIMER0 MODULE in AVR MCP
	 * [Args]        :
	 *
	 * [in]            a_time
	 *
	 *
	 * [Returns]     : The function returns void.
	 *
	 *
	 *********************************************************************************************************************************/
	Timer0_init(&timer_config);
	while(g_timer != a_time){}
	Timer0_DeInit();
	g_sec = 0;
	g_timer = 0 ;
	return OK;
}


