/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "fsm_mid.h"
#include "scheduler.h"
extern int Timer1_flag;
extern int flag_dec;
extern int flag_inc;
void Settimer1(int du);
extern int Timer2_flag;
void Settimer2(int du);
void Settimer3(int du);
extern int Timer3_flag;
void TimerRun();
void fsmTimerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */
