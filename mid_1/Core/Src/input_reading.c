/*
 * input_reading.c
 *
 *  Created on: Nov 15, 2022
 *      Author: Admin
 */

#include "input_reading.h"
int KeyRegB10 = NORMAL_STATE;
int KeyRegB11 = NORMAL_STATE;
int KeyRegB12 = NORMAL_STATE;
int KeyRegB13 = NORMAL_STATE;

int KeyRegB00 = NORMAL_STATE;
int KeyRegB01 = NORMAL_STATE;
int KeyRegB02 = NORMAL_STATE;
int KeyRegB03 = NORMAL_STATE;

int KeyRegB20 = NORMAL_STATE;
int KeyRegB21 = NORMAL_STATE;
int KeyRegB22 = NORMAL_STATE;
int KeyRegB23 = NORMAL_STATE;


int TimeForKeyPress1 =  100;
int TimeForKeyPress2 =  100;
//int TimeForKeyPressDec =  300;
int TimeOutForKeyPress = 200;
int ac_flagB0 =0;//chỉ khi nút nhấn thứ nhất dc nhấn mới = 1
 int ac_flagB1 =0;
 int ac_flagB2 =0;
 void isB2Nor(){
	 	 	 	 	 	KeyRegB20 = KeyRegB21;
 			  			KeyRegB21 = KeyRegB22;
 			  			KeyRegB22 = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin);
 			  			if ((KeyRegB20 == KeyRegB21)&&(KeyRegB21 == KeyRegB22)){
 			  			if (KeyRegB22 != KeyRegB23){
 			  					  KeyRegB23 = KeyRegB22;

 			  			if (KeyRegB22 == PRESSED_STATE){
 			  				TimeForKeyPress2 = 100;
 			  				ac_flagB2 =1;// CODE chức năng sau khi nhấn trên 30s
 			  				// nút nhấn thứ 2

 			  				}}else{
 			  					TimeForKeyPress2 --;
 			  					        if (TimeForKeyPress2 == 0){
 			  					          KeyRegB23 = NORMAL_STATE;
 			  					        }
 			  				}

 			  			}
 }




 // có chức năng khi giừ hơn 30ms dc tính là nhấn và sau đó cứ 1s sẽ nhận tiếp
 void isB1Nor(){
 	KeyRegB10 = KeyRegB11;
 			  			KeyRegB11 = KeyRegB12;
 			  			KeyRegB12 = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
 			  			if ((KeyRegB10 == KeyRegB11)&&(KeyRegB11 == KeyRegB12)){
 			  			if (KeyRegB12 != KeyRegB13){
 			  					  KeyRegB13 = KeyRegB12;

 			  			if (KeyRegB12 == PRESSED_STATE){
 			  				TimeForKeyPress1 = 100;
 			  				ac_flagB1 =1;// CODE chức năng sau khi nhấn trên 30s
 			  				// nút nhấn thứ 2

 			  				}}else{
 			  					TimeForKeyPress1 --;
 			  					        if (TimeForKeyPress1 == 0){
 			  					          KeyRegB13 = NORMAL_STATE;
 			  					        }
 			  				}

 			  			}
 }
 void isB0Nor(){
 	KeyRegB00 = KeyRegB01;
 			  			KeyRegB01 = KeyRegB02;
 			  			KeyRegB02 = HAL_GPIO_ReadPin(B0_GPIO_Port, B0_Pin);
 			  			if ((KeyRegB00 == KeyRegB01)&&(KeyRegB01 == KeyRegB02)){
 			  			if (KeyRegB02 != KeyRegB03){
 			  					  KeyRegB03 = KeyRegB02;

 			  			if (KeyRegB02 == PRESSED_STATE){
 			  				 TimeOutForKeyPress = 200;
 			  				ac_flagB0 =1;// CODE chức năng sau khi nhấn trên 30s
 			  				// nút nhấn thứ 1

 			  				}}else{
 			  					TimeOutForKeyPress --;
 			  					        if (TimeOutForKeyPress == 0){
 			  					          KeyRegB03 = NORMAL_STATE;
 			  					        }
 			  				}

 			  			}
 }
