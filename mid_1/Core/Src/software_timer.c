/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "software_timer.h"

int Timer1_flag =0;
int Timer1_c = 0;
int Timer2_flag =0;
int Timer2_c = 0;
int Timer3_flag =0;
int Timer3_c = 0;
//int flag_dec =0;
//int flag_inc =0;
 void Settimer1(int du)
 {Timer1_c =du;
 Timer1_flag=0;
 }
 void Settimer2(int du)
  {Timer2_c =du;
  Timer2_flag=0;
  }
 void Settimer3(int du)
  {Timer3_c =du;
  Timer3_flag=0;
  }
 void TimerRun(){
// {if((KeyReginc2 == KeyRegdec2)&&(KeyRegreset2 == KeyReginc2)&&(KeyReginc2 == NORMAL_STATE)){
	 if(Timer1_c > 0){
	 		 Timer1_c--;
	 		 if(Timer1_c == 0){
	 			 Timer1_flag = 1;

	 		 }
	 	 }
// }

	 if(Timer2_c > 0){
	 		 Timer2_c--;
	 		 if(Timer2_c == 0){
	 			 Timer2_flag = 1;
	 		 }
	 	 }
	 if(Timer3_c > 0){
	 	 		 Timer3_c--;
	 	 		 if(Timer3_c == 0){
	 	 			 Timer3_flag = 1;
	 	 		 }
	 	 	 }

 }
 ;
// void fsmTimerRun(){
//	 if ((KeyReginc0 == KeyReginc1)&&(KeyReginc1 == KeyReginc2)&&(KeyReginc2 == KeyReginc3)&&(KeyReginc2 == PRESSED_STATE)){
//		 if (TimeForKeyPressInc > 0)
//		 		       {TimeForKeyPressInc --;}
//		 		        if (TimeForKeyPressInc == 0){
//		 		        	TimeForKeyPressInc = 100;
//		 		        	flag_inc =1;
//		 		        	statusbut = buttonLonginc;
//		 		        	KeyReginc3 = NORMAL_STATE;
//		 		        }// inc
// }else{inc_ac =0;}
//	 if ((KeyRegdec0 == KeyRegdec1)&&(KeyRegdec1 == KeyRegdec2)&&(KeyRegdec2 == KeyRegdec3)&&(KeyRegdec2 == PRESSED_STATE)){
//	 		 if (TimeForKeyPressDec > 0)
//	 		 		       {TimeForKeyPressDec --;}
//	 		 		        if (TimeForKeyPressDec == 0){
//	 		 		        	TimeForKeyPressDec =  100;
//	 		 		        	flag_dec =1;
//	 		 		        	KeyRegdec3 = NORMAL_STATE;
//	 		 		        }// inc
//	  }else{dec_ac =0;}
// }

