/*
 * Timer.h
 *
 * Created: 8/24/2023 11:43:43 PM
 *  Author: Azza Saeed
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#define TCNT0 *((volatile UINT8_t*)0x52)

void timer0_overflow_init_interrupt(void);
void timer_CTC_init_interrupt(void);
void timer_wave_fastPWM(void);


#endif /* TIMER_H_ */