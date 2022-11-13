/*
 * DIO.c
 *
 *  Created on: Oct 10, 2022
 *      Author: Amr Mohamed
 */


#include"DIO.h"

error_state DIO_init(uint8 port, uint8 pin , uint8 direction)
{
	switch(port)
	{
	case PORT_A:
		if(direction == IN)
		{
			CLEAR_BIT(DDRA,pin);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			return ERROR;
		}
		break;
	case PORT_B:
		if(direction == IN)
		{
			CLEAR_BIT(DDRB,pin);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			return ERROR;
		}
		break;
	case PORT_C:
		if(direction == IN)
		{
			CLEAR_BIT(DDRC,pin);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			return ERROR;
		}
		break;
	case PORT_D:
		if(direction == IN)
		{
			CLEAR_BIT(DDRD,pin);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			return ERROR;
		}
		break;
	default:
		return ERROR;
	}
	return OK;
}

error_state DIO_write(uint8 port, uint8 pin , uint8 value)
{
	switch(port)
	{
	case PORT_A:
		if(value == HIGH)
		{
			SET_BIT(PORTA, pin);
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTA, pin);
		}
		else
		{
			return ERROR;
		}
		break;
	case PORT_B:
		if(value == HIGH)
		{
			SET_BIT(PORTB, pin);
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTB, pin);
		}
		else
		{
			return ERROR;
		}
		break;
	case PORT_C:
		if(value == HIGH)
		{
			SET_BIT(PORTC, pin);
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTC, pin);
		}
		else
		{
			return ERROR;
		}
		break;
	case PORT_D:
		if(value == HIGH)
		{
			SET_BIT(PORTD, pin);
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTD, pin);
		}
		else
		{
			return ERROR;
		}
		break;
	default:
		return ERROR;
	}
	return OK;
}
error_state DIO_read(uint8 port, uint8 pin , uint8 *value)
{
	switch(port)
	{
	case PORT_A:
		*value = GET_BIT(PINA,pin);
		break;
	case PORT_B:
		*value = GET_BIT(PINB,pin);
		break;
	case PORT_C:
		*value = GET_BIT(PINC,pin);
		break;
	case PORT_D:
		*value = GET_BIT(PIND,pin);
		break;
	default:
		return ERROR;
	}
	return OK;
}


error_state DIO_toggle( uint8 port, uint8 pin )
{
	switch(port)
		{
		case PORT_A:
			TOGGLE_BIT(PORTA,pin);
			break;
		case PORT_B:
			TOGGLE_BIT(PORTB,pin);
			break;
		case PORT_C:
			TOGGLE_BIT(PORTC,pin);
			break;
		case PORT_D:
			TOGGLE_BIT(PORTD,pin);
			break;
		default:
			return ERROR;
		}
		return OK;
}

