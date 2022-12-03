/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include <stdint.h>
#include "input_reading.h"
#define sch_max 40
extern uint8_t index_task;
typedef struct {
	void ( *pTask)(void);
		// Delay (ticks) until the function will (next) be run
		uint32_t Delay;
		// Interval (ticks) between subsequent runs.
		uint32_t Period;
		// Incremented (by scheduler) when task is due to execute
		uint8_t RunMe;//tương đương flag
		//This is a hint to solve the question below.
		uint32_t TaskID;
}sTasks;

void SCH_Init(void);
void SCH_Add_Task(void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void laplai(uint8_t abc,void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD, uint8_t index);
void sch_one_shot_button(void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD);
void SCH_Delete_Task(uint32_t abc);
#endif /* INC_SCHEDULER_H_ */
