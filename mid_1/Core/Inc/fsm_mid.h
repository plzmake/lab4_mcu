/*
 * fsm_mid.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef INC_FSM_MID_H_
#define INC_FSM_MID_H_

#include "main.h"
#include "software_timer.h"
#include "output_display.h"
#include "input_reading.h"




extern int KeyRegdec0 ;
extern int KeyRegdec1 ;
extern int KeyRegdec2 ;
extern int KeyRegdec3 ;


extern int num ;
extern int mode ;

#define B0 2
#define mode1   1
#define mode2   2
#define mode3	3
#define mode4 	4
#define mode0 	5
#define time_out		8

void isIncNor();
void isDecNor();
void long_press_dec();
void long_press_inc();
void timer_out();


extern int led_buffer[4] ;

extern int TimeOutForKeyPress;
extern int TimeForKeyPress1;
extern int TimeForKeyPress2;
extern int frist_buttonset[3];
void fsm_automatic_run();
void blinking_LEDs();
#endif /* INC_FSM_MID_H_ */
