/*
 * output_display.h
 *
 *  Created on: Nov 14, 2022
 *      Author: Admin
 */

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_
#include "fsm_mid.h"
void display7SEG(int num);
void updateClockBuffer(int num ,int num_a);
void updateClockBuffer2(int num);
void update7SEG(int index);
void scan_led7seg();
extern int value_led_set[6];
extern int counter;
extern int counter2;
#endif /* INC_OUTPUT_DISPLAY_H_ */
