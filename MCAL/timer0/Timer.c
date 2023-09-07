/*
 * Timer.c
 *
 * Created: 8/24/2023 11:43:30 PM
 *  Author: Azza Saeed
 */ 
#include "DIO_Private.h"
#include "Timer.h"
#include "STD_Types.h"
#include <avr/interrupt.h>

void timer0_overflow_init_interrupt(void)
{
	/* select Over mode*/
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/*load a value in TCNT0 */
	TCNT0=220;
	/* select timer clock prescaller 256  */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	/* enable interrupt*/
	
	SET_BIT(TIMSK,TOIE0);
	sei();
}

void timer_CTC_init_interrupt(void)
{
	SET_BIT(DDRB,3);// output pin
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=220;
	SET_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
	/* select timer clock  256 prescaler */
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void timer_wave_fastPWM(void)
{
	/* select fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* select timer clock 64 prescaller   */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode) */
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	OCR0=0;
}
