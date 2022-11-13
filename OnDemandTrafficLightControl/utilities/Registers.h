/*
 * Registers.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Amr Mohamed
 */

#ifndef UTILITIES_REGISTERS_H_
#define UTILITIES_REGISTERS_H_

/**********************************************************************************************
 *
 *                                   Addressing DIO Registers
 *                                                                                            *
 **********************************************************************************************/


/* Port D */
#define PIND     *((volatile uint8*) (0x30))
#define DDRD     *((volatile uint8*) (0x31))
#define PORTD    *((volatile uint8*) (0x32))

/* Port C */
#define PINC     *((volatile uint8*) (0x33))
#define DDRC     *((volatile uint8*) (0x34))
#define PORTC    *((volatile uint8*) (0x35))

/* Port B */
#define PINB     *((volatile uint8*) (0x36))
#define DDRB     *((volatile uint8*) (0x37))
#define PORTB    *((volatile uint8*) (0x38))

/* Port A */
#define PINA     *((volatile uint8*) (0x39))
#define DDRA     *((volatile uint8*) (0x3A))
#define PORTA    *((volatile uint8*) (0x3B))


/**********************************************************************************************
 *
 *                                   Addressing Timer0 Registers
 *                                                                                             *
 **********************************************************************************************/

#define TCCR0      *((volatile uint8*) (0x53))
#define TCNT0      *((volatile uint8*) (0x52))
#define TIMSK      *((volatile uint8*) (0x59))
#define TIFR       *((volatile uint8*) (0x58))
#define OCR0       *((volatile uint8*) (0x5C))

/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/**********************************************************************************************
 *
 *                           Addressing External Interrupts Registers
 *                                                                                             *
 **********************************************************************************************/

#define SREG    *((volatile uint8*) (0x5F))
#define GICR    *((volatile uint8*) (0x5B))
#define GIFR    *((volatile uint8*) (0x5A))
#define MCUCR   *((volatile uint8*) (0x55))
#define MCUCSR  *((volatile uint8*) (0x54))

/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* MCUCSR */
#define JTD     7
#define ISC2    6
/*********************************************************************************************
 *
 *                                     INTERRUPT VECTORS
 *                                                                                            *
 **********************************************************************************************/
#define RESET_vect               __vector_0
#define INT0_vect                __vector_1
#define INT1_vect                __vector_2
#define INT2_vect                __vector_3
#define TIMER0_OVF_vect		     __vector_11
#define TIMER0_COMP_vect         __vector_10

/*************************  ISR FUNCTION MACRO DEFINITION ***********************/

#define ISR(INT_vect)    void INT_vect (void)__attribute__((signal,used)); \
	                     void INT_vect (void)


#endif /* UTILITIES_REGISTERS_H_ */
