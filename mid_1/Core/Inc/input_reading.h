/*
 * input_reading.h
 *
 *  Created on: Nov 15, 2022
 *      Author: Admin
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
#include "main.h"
#include "scheduler.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
void isB0Nor();
void isB1Nor();
void isB2Nor();

extern int ac_flagB0;
extern int ac_flagB1;
extern int ac_flagB2;

//extern int KeyRegB10 ;
//extern int KeyRegB11 ;
//extern int KeyRegB12 ;
//extern int KeyRegB13 ;
//
extern int KeyRegB20 ;
extern int KeyRegB21 ;
extern int KeyRegB22 ;
extern int KeyRegB23 ;

#endif /* INC_INPUT_READING_H_ */
