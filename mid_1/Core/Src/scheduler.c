/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */
#include "scheduler.h"
sTasks SCH_tasks_G[sch_max];
uint8_t index_task = 0;

void laplai(uint8_t abc,void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD ,uint8_t index){
	SCH_tasks_G[abc].pTask = pFunction;
			SCH_tasks_G[abc].Delay = DELAY;
			SCH_tasks_G[abc].Period = PERIOD;
			SCH_tasks_G[abc].RunMe = 0;
			SCH_tasks_G[abc].TaskID =index;
}
void SCH_Add_Task(void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD){
	uint32_t DELAY_1 = DELAY /10;
	uint32_t PERIOD_1 = PERIOD /10;
	if(index_task < sch_max){
		SCH_tasks_G[index_task].pTask = pFunction;
		SCH_tasks_G[index_task].Delay = DELAY_1;
		SCH_tasks_G[index_task].Period = PERIOD_1;
		SCH_tasks_G[index_task].RunMe = 0;
		SCH_tasks_G[index_task].TaskID =index_task;
		index_task++;
	}
}
void SCH_Update(void){// đặt ở 10ms mới chạy 1 lần
	for (int i = 0;i < index_task; i++ ){
		if(SCH_tasks_G[i].Delay > 0){
			SCH_tasks_G[i].Delay--;
		}else{
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe +=1;
		}
	}
}
void SCH_Dispatch_Tasks(void){ // đăt ở while (1)
	for (int i = 0; i < index_task; i++ ){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if (SCH_tasks_G[i].Period == 0)
			    {
			       SCH_Delete_Task(i);
			    }
		}
	}
}
void SCH_Delete_Task(uint32_t abc){
	if((index_task > 0)&&(abc < sch_max)){
		if ((abc == 0)&&(index_task == 1)) {
			laplai(0, 0x0000, 0, 0, 0);

		}else if (abc == (index_task-1)){
			laplai(abc, 0x0000, 0, 0, 0);

		} else {

			for ( int i = abc; i < (index_task-1) ;i++){
				SCH_tasks_G[i].pTask = SCH_tasks_G[i + 1].pTask;
				SCH_tasks_G[i].Delay = SCH_tasks_G[i + 1].Delay;
				SCH_tasks_G[i].Period = SCH_tasks_G[i + 1].Period;
				SCH_tasks_G[i].RunMe = SCH_tasks_G[i + 1].RunMe;

			}
			laplai((index_task-1), 0x0000, 0, 0, 0);
		}
		index_task--;
	}

}
void sch_one_shot_button(void (*pFunction)(),uint32_t DELAY, uint32_t PERIOD){
  	 	 	 	 	 	KeyRegB20 = KeyRegB21;
   			  			KeyRegB21 = KeyRegB22;
   			  			KeyRegB22 = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin);
   			  			if ((KeyRegB20 == KeyRegB21)&&(KeyRegB21 == KeyRegB22)){
   			  			if (KeyRegB22 != KeyRegB23){
   			  					  KeyRegB23 = KeyRegB22;

   			  			if (KeyRegB22 == PRESSED_STATE){
   			  				//TimeForKeyPress2 = 100;
   			  				//ac_flagB2 =1;// CODE chức năng sau khi nhấn trên 30s
   			  				// nút nhấn thứ 2
   			  			SCH_Add_Task(pFunction, DELAY,  PERIOD);

   			  				}}
   			  			else{
   			  					//TimeForKeyPress2 --;
   			  					        if (SCH_tasks_G[index_task].Delay == 0){
   			  					          KeyRegB23 = NORMAL_STATE;
   			  					        }
   			  				}

   			  			}
 }


