


#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

#include "GREEN_LED_Private.h"
#include "YELLOW_LED_Private.h"
#include "RED_LED_Private.h"
#include "LCD_Private.h"



#define FIVE_SEC	4000
#define TEN_SEC	    9000
#define SEV_SEC	    6000
#define ONE_SEC     1000

typedef enum{
	green=0,
	yellow,
	red
}Current_State;

typedef enum{
	green_st=0,
	yellow_st,
	red_st
}Prev_State;

ERROR_STATE app_init(void);

ERROR_STATE app_main(void);

ERROR_STATE LCD_Page(void);

ERROR_STATE Check_State(void);

ERROR_STATE Green_Task(void);

ERROR_STATE Yellow_Task(void);

ERROR_STATE Red_Task(void);

void delay_secs(UINT32_t delay);


#endif /* APP_INTERFACE_H_ */