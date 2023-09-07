#include <stdio.h>

#include "APP_Interface.h"

volatile UINT8_t counter_green=10;
volatile UINT8_t counter_yellow=5;
volatile UINT8_t counter_red=7;
Current_State cur_state=green;
Prev_State Prev;
UINT8_t Break_Delay = 1;

ERROR_STATE app_init(void){
		ERROR_STATE state_error = SUCCESS;
		LCD_Initialize();
		RED_LED_Initializ();
		GREEN_LED_Initializ();
		YELLOW_LED_Initializ();
		return state_error;
}

ERROR_STATE app_main(){
		ERROR_STATE state_error = SUCCESS;
		cur_state=green;
		counter_green=10;
	    counter_yellow=5;
		counter_red=7;
		LCD_Page();
		Check_State();
		return state_error;
}
ERROR_STATE LCD_Page(void){
	ERROR_STATE state_error = SUCCESS;
	LCD_LINE_position(LCD_LINE1,3);
	LCD_Write_String("Traffic Light");
	return state_error;
}

ERROR_STATE Check_State(void){
	ERROR_STATE state_error = SUCCESS;
	if(cur_state==green)
	{
		Green_Task();
	}else{
	state_error=FAIL;		
	}
	if(Prev==green_st){
		Yellow_Task();
	}else{
	state_error=FAIL;
    }
	if(Prev==yellow_st){
		Red_Task();
	}else{
	state_error=FAIL;
     }
	//if( Prev==red_st){
		//Green_Task();
	//}else{
		//state_error=FAIL;
	//}
	return state_error;
}

ERROR_STATE Green_Task(void){
	ERROR_STATE state_error = SUCCESS;
	cur_state=green;
	LCD_LINE_position(LCD_LINE2,2);
	LCD_Write_String("remaining 10 sec   ");
	delay_secs(ONE_SEC);
    LCD_LINE_position(LCD_LINE3,2);
	LCD_Write_String("Green led is on    ");
	LCD_LINE_position(LCD_LINE2,2);
	LCD_Write_String("                      ");
	if(Prev==red_st)
	{
		RED_LED_OFF();
	}
	GREEN_LED_ON();
	Prev=green_st;
	delay_secs(TEN_SEC);
	
	return state_error;
}

ERROR_STATE Yellow_Task(void){
	ERROR_STATE state_error = SUCCESS;
	cur_state=yellow;
	LCD_LINE_position(LCD_LINE2,2);
	LCD_Write_String("remaining 5 sec");
	delay_secs(ONE_SEC);
	LCD_LINE_position(LCD_LINE3,2);
	LCD_Write_String("Yellow led is on");
	LCD_LINE_position(LCD_LINE2,2);
	LCD_Write_String("                       ");

	if(Prev==green_st)
	{
		GREEN_LED_OFF();
	}
	YELLOW_LED_ON();
	Prev=yellow_st;
	delay_secs(FIVE_SEC);
	
	return state_error;
}
ERROR_STATE Red_Task(void){
	ERROR_STATE state_error = SUCCESS;
	cur_state=red;
	LCD_LINE_position(LCD_LINE2,2);
	LCD_Write_String("remaining 7 sec   ");
	delay_secs(ONE_SEC);
	LCD_LINE_position(LCD_LINE3,2);
	LCD_Write_String("Red led is on   ");
	LCD_LINE_position(LCD_LINE2,2);
	LCD_Write_String("                      ");

	if(Prev==yellow_st)
	{
		YELLOW_LED_OFF();
	}
	RED_LED_ON();
	Prev=red_st;
	delay_secs(SEV_SEC);

	return state_error;
}

void delay_secs(UINT32_t delay)
{
	for (UINT16_t i = 0; i < delay; i++) {
		// Each iteration of this loop introduces a delay of about 1ms using _delay_us
		_delay_us(1000);  // Delay for 1000 microseconds (1ms)
		if(!Break_Delay)
		break;
	}
}

