/*
 * output_display.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Admin
 */
#include "output_display.h"

int value_led_set[6]={0,7,0,5,0,2};
int counter =1;
int counter2 =1;
void updateClockBuffer(int num, int num_a){

	 led_buffer[2] = num_a / 10;
	 led_buffer[3] =  num_a % 10;

	 led_buffer[0] = num / 10;
	 led_buffer[1] = num % 10;


 }
void display7SEG(int num){
if (num == 0)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, LED7_6_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 1)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_1_Pin|LED7_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_3_Pin |LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 2)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_3_Pin|LED7_4_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_2_Pin|LED7_5_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 3)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_4_Pin|LED7_5_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 4)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_1_Pin|LED7_2_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, LED7_4_Pin|LED7_0_Pin|LED7_3_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 5)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_2_Pin|LED7_5_Pin|LED7_3_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_4_Pin|LED7_1_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 6)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_2_Pin|LED7_5_Pin|LED7_4_Pin|LED7_3_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  		  HAL_GPIO_WritePin(GPIOB, LED7_1_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 7)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 8)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 9)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin
		                            |LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB,
		                            LED7_4_Pin, GPIO_PIN_SET);
	  }
}
void update7SEG(int index){
    switch (index){
        case 0:
            //Display the first 7SEG with led_buffer[0]
        	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);
        	display7SEG(led_buffer[0]);
            break;
        case 1:
            //Display the second 7SEG with led_buffer[1]
        	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin, GPIO_PIN_SET);
        	display7SEG(led_buffer[1]);
            break;
        case 2:
            //Display the third 7SEG with led_buffer[2]
        	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin,GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN0_Pin|EN3_Pin, GPIO_PIN_SET);
        	display7SEG(led_buffer[2]);
            break;
        case 3:
            //Display the forth 7SEG with led_buffer[3]
        	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin,GPIO_PIN_RESET);
        	HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN0_Pin, GPIO_PIN_SET);
        	display7SEG(led_buffer[3]);
            break;
        default:
            break;
    }
}
void scan_led7seg(){

	if(Timer1_flag == 1){
		Settimer1(31);


		update7SEG(num);
		num++;
		if(num >3){num =0;}
								 }
}
void updateClockBuffer2(int counter){

	 led_buffer[2] = counter / 10;
	 led_buffer[3] = counter % 10;

	 led_buffer[0] = 0;
	 led_buffer[1] = mode;

//	 led_buffer[2] = 0;
//	 led_buffer[3] = mode;

 }
