/*
 * ExInterrupt.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Amr Mohamed
 */

#include"ExInterrupt.h"


static volatile void (*ISR_Funcptr[MAX_INT])(void) = {NULL};

error_state Interrupt_GlobalEnable (bool enable)
{
	switch(enable)
	{
	case ON :

		SET_BIT( SREG , 7 );


		break;

		/********************************/

	case OFF :

		CLEAR_BIT( SREG , 7 );

		break;

	default :
		return ERROR;
	}
	return OK;
}


error_state ExInterrupt_init( ExInterrupt_Config* configrations )
{
	switch( configrations -> Type )
	{
	/*====================================================================================*/
	/********* CHOOSING THE INTERRUPT PERIPHERAL *********/

	case External_Interrupt_0_P:

		/* INT0 Enable */

		SET_BIT( GICR , 6);

		switch( configrations -> EdgeType )
		{
		/********* CHOOSING THE SENSE TYPE *********/
		case RISING_EDGE:

			MCUCR |= ( 1 << ISC01 ) | ( 1 << ISC00 );

			break;

		case FALLING_EDGE:

			MCUCR |= ( 1 << ISC01 );

			break;

		case LOW_LEVEL:

			CLEAR_BIT( MCUCR , ISC01 );
			CLEAR_BIT( MCUCR , ISC00 );

			break;

		case ANY_LOGIC_CHANGE:

			MCUCR |= ( 1 << ISC00 );

			break;
		default:
			return ERROR;

		}
		break;
		/*====================================================================================*/
		/********* CHOOSING THE INTERRUPT PERIPHERAL *********/
		case External_Interrupt_1_P:

			/* INT1 Enable */

			SET_BIT( GICR , 7 );

			switch( configrations -> EdgeType )
			{
			/********* CHOOSING THE SENSE TYPE *********/
			case RISING_EDGE:

				MCUCR |= ( 1 << ISC11 ) | ( 1 << ISC10 );

				break;

			case FALLING_EDGE:

				MCUCR |= ( 1 << ISC11 );

				break;

			case LOW_LEVEL:

				CLEAR_BIT( MCUCR , ISC11 );
				CLEAR_BIT( MCUCR , ISC10 );

				break;

			case ANY_LOGIC_CHANGE:

				MCUCR |= ( 1 << ISC10 );

				break;
			default:
				return ERROR;

			}
			break;
			/*====================================================================================*/
			/********* CHOOSING THE INTERRUPT PERIPHERAL *********/
			case External_Interrupt_2_P:

				/* INT2 Enable */

				SET_BIT( GICR , 5 );

				switch( configrations -> EdgeType )
				{
				/********* CHOOSING THE SENSE TYPE *********/
				case RISING_EDGE:

					MCUCSR |= ( 1 << ISC2 );

					break;

				case FALLING_EDGE:

					MCUCSR &=~ ( 1 << ISC2 );

					break;

				default:
					return ERROR;

				}
				break;
				/*====================================================================================*/
				default:
					return ERROR;

	}
	return OK;
}

error_state ExInterrupt_CallBack( ExInterrupt_VectorType ISR_ID , void(*function_ptr)(void)  )
{
	if(ISR_ID < MAX_INT)
	{
		ISR_Funcptr[ISR_ID] = function_ptr;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

/**********************************************************************************************
 *
 *                                    ISR DEFINITIONS
 *                                                                                             *
 **********************************************************************************************/
ISR(INT0_vect)
{
	if( ISR_Funcptr[ EXT_INT0 ] != NULL )
	{
		(*ISR_Funcptr[ EXT_INT0 ])();
	}
}


ISR(INT1_vect)
{
	if( ISR_Funcptr[ EXT_INT1 ] != NULL )
	{
		ISR_Funcptr[ EXT_INT1 ]();
	}
}

ISR(INT2_vect)
{
	if( ISR_Funcptr[ EXT_INT2 ] != NULL )
	{
		ISR_Funcptr[ EXT_INT2 ]();
	}
}

error_state ExInterrupt_DeInit(ExInterrupt_PeripheralType type)
{
	switch(type)
	{
	case External_Interrupt_0_P:
		CLEAR_BIT( GICR , 6);
		break;
	case External_Interrupt_1_P:
		CLEAR_BIT( GICR , 7);
		break;
	case External_Interrupt_2_P:
		CLEAR_BIT( GICR , 5);
		break;
	default:
		return ERROR;
	}
	return OK;
}
