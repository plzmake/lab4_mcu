/*
 * fsm_mid.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "fsm_mid.h"



int num =0;
int mode =5;
//statusbut = init;



 int led_buffer[4] = {3,5,7,8};
 int frist_buttonset[3]= {1,1,1};
 int ac_light_led_1[3] ={1,0,0};
 int ac_light_led_2[3] ={1,0,0};
 //có chức năng khi giừ hơn 30ms dc tính là nhấn và sau đó cứ 2s sẽ nhận tiếp



//void getKeyInput(){
//  KeyReg2 = KeyReg1;
//  KeyReg1 = KeyReg0;
//  KeyReg0 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
//  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
//    if (KeyReg2 != KeyReg3){
//      KeyReg3 = KeyReg2;
//
//      if (KeyReg3 == PRESSED_STATE){
//
//        subKeyProcess();
//      }
//    }else{
//       TimeOutForKeyPress --;
//        if (TimeOutForKeyPress == 0){
//          KeyReg3 = NORMAL_STATE;
//        }
//    }
//  }
//}

//void isIncNor(){
//	KeyReginc0 = KeyReginc1;
//			  			KeyReginc1 = KeyReginc2;
//			  			KeyReginc2 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
//			  			if ((KeyReginc0 == KeyReginc1)&&(KeyReginc1 == KeyReginc2)){
//			  			if (KeyReginc2 != KeyReginc3){
//			  					  KeyReginc3 = KeyReginc2;
//
//			  			if (KeyReginc2 == PRESSED_STATE){
//			  					  // counter =0;
//			  				if(statusbut != buttonLonginc){
//			  				statusbut = inc;}
//			  				if(counter == 9){counter = 0;}
//			  				else{counter = counter +1;}
//			  				display7SEG(counter);
//			  				Settimer1(500);
//			  				if(!inc_ac)
//			  				{TimeForKeyPressInc =  300;
//			  				inc_ac =1;}
//			  				}}}
//}
//void isDecNor(){
//	KeyRegdec0 = KeyRegdec1;
//				  			KeyRegdec1 = KeyRegdec2;
//				  			KeyRegdec2 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
//				  			if ((KeyRegdec0 == KeyRegdec1)&&(KeyRegdec1 == KeyRegdec2)){
//				  			if (KeyRegdec2 != KeyRegdec3){
//				  					  KeyRegdec3 = KeyRegdec2;
//
//				  			if (KeyRegdec2 == PRESSED_STATE){
//				  					  if(statusbut != buttonLongdec)
//				  				{statusbut = dec;}
//				  				if(counter == 0){counter = 9;}
//				  				else{counter = counter -1;}
//				  				display7SEG(counter);
//				  				Settimer1(500);
//				  				if(!dec_ac)
//				  					{TimeForKeyPressDec =  300;
//				  					dec_ac =1;}
//				  				}}}
//}
//void long_press_inc(){
//
//
//
//
//	if((inc_ac)&&(flag_inc)){
//
//		flag_inc =0;
//	}
//}
//void long_press_dec(){
//
//
//	if((dec_ac)&&(flag_dec)){
//
//			flag_dec =0;
//		}
//}
//
//void timer_out(){
//	 if(Timer1_flag == 1){
//		 statusbut = time_out;
//		 Settimer1(50);
//		 if(counter == 0){counter = 9;}
//		 else{counter = counter -1;}
//		 display7SEG(counter);
//	 }
// }
void fsm_automatic_run(){
switch (mode) {
case mode0: mode = mode1;
break;
	case mode1:
		//isB0Nor();//hàm biểu thị cho nhấn nút 1



		//tạm thời chưa làm
		frist_buttonset[0] = 1;
		frist_buttonset[1] = 1;
		frist_buttonset[2] = 1;

		if(Timer3_flag == 1){
			Settimer3(150);
			if(counter > 0)
			{counter--;}
			if(counter2 > 0)
						{counter2--;}



			if((ac_light_led_1[0] ==1)&&(counter == 0)){
						counter = value_led_set[0]*10 + value_led_set[1];
						ac_light_led_1[0] = 0;
						ac_light_led_1[1] = 1;
						HAL_GPIO_WritePin(GPIOB, LED0_Pin, GPIO_PIN_SET);
						HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin, GPIO_PIN_RESET);
						}
					else if ((ac_light_led_1[1] ==1)&&(counter == 0)){
									counter = value_led_set[4]*10 + value_led_set[5];
												ac_light_led_1[2] = 1;
												ac_light_led_1[1] = 0;
												HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_SET);
												HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED0_Pin, GPIO_PIN_RESET);
								} else if ((ac_light_led_1[2] ==1)&&(counter == 0)){
									counter = value_led_set[2]*10 + value_led_set[3];
																ac_light_led_1[0] = 1;
																ac_light_led_1[2] = 0;
																HAL_GPIO_WritePin(GPIOB, LED1_Pin, GPIO_PIN_SET);
																HAL_GPIO_WritePin(GPIOB, LED0_Pin|LED2_Pin, GPIO_PIN_RESET);
								}

			if((ac_light_led_2[0] ==1)&&(counter2 == 0)){
									counter2 = value_led_set[4]*10 + value_led_set[5];
									ac_light_led_2[0] = 0;
									ac_light_led_2[1] = 1;
									HAL_GPIO_WritePin(GPIOB, LED5_Pin, GPIO_PIN_SET);
									HAL_GPIO_WritePin(GPIOB, LED3_Pin|LED4_Pin, GPIO_PIN_RESET);
									}
								else if ((ac_light_led_2[1] ==1)&&(counter2 == 0)){
												counter2 = value_led_set[2]*10 + value_led_set[3];
															ac_light_led_2[2] = 1;
															ac_light_led_2[1] = 0;
															HAL_GPIO_WritePin(GPIOB, LED4_Pin, GPIO_PIN_SET);
															HAL_GPIO_WritePin(GPIOB, LED3_Pin|LED5_Pin, GPIO_PIN_RESET);
											} else if ((ac_light_led_2[2] ==1)&&(counter2 == 0)){
												counter2 = value_led_set[0]*10 + value_led_set[1];
																			ac_light_led_2[0] = 1;
																			ac_light_led_2[2] = 0;
																			HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_SET);
																			HAL_GPIO_WritePin(GPIOB, LED4_Pin|LED5_Pin, GPIO_PIN_RESET);
											}

		}
		 updateClockBuffer(counter ,counter2);
		 scan_led7seg();// quét led 7 đoạn
		if(ac_flagB0 == 1){mode = mode2;
		ac_flagB0 =0;}

//		if(first == 1){first = 0;
//		ac_red =1;
//		display = arr_set[0]*10 + arr_set[1];
//		setbuffer_1();
//		}
//
//		else if ((display == 0)&&(two == 1))
//
//					{
//						//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//						two = 0;
//						ac_amber =1;
//						display = arr_set[2]*10+arr_set[3];
//						setbuffer_1();
//
//					}else if ((display == 0)&&(four == 1)){
//						four = 0;
//						ac_green =1;
//						display = arr_set[4]*10+arr_set[5];
//						setbuffer_1();
//					}
//					else if ((display == 0)&&(first == 0)&&(four == 0)&&(two == 0)){
//							first = 1;
//								two =1;
//								four =1;
//					}
//
//		if(Timer2_flag == 1){
//			Settimer2(122);
//
//			if(display > 0){
//			display = display -1;}
//
//
//			setbuffer_1();
//		}
//		if(Timer3_flag == 1){
//									Settimer3_ms(500 , 7999 , 9 );
//									if(ac_red == 1){
//										ac_amber = 0;
//										  ac_green =0;
//									HAL_GPIO_TogglePin(led0_GPIO_Port,led0_Pin);
//									HAL_GPIO_TogglePin(led3_GPIO_Port,led3_Pin);}
//									else if(ac_amber == 1){
//										ac_red = 0 ;
//										 ac_green =0;
//										HAL_GPIO_TogglePin(led1_GPIO_Port,led1_Pin);
//										HAL_GPIO_TogglePin(led4_GPIO_Port,led4_Pin);}
//									else if(ac_green == 1){
//										ac_red = 0 ;
//										ac_amber =0;
//										HAL_GPIO_TogglePin(led2_GPIO_Port,led2_Pin);
//										HAL_GPIO_TogglePin(led5_GPIO_Port,led5_Pin);}
//								}
//
//		scan_led7seg();// hiển thị led_buffer



		break;
	case mode2:

		if( frist_buttonset[0] == 1){
			 frist_buttonset[0] = 0;
			 counter = value_led_set[0]*10 + value_led_set[1];
		}

		if(ac_flagB1 == 1){
			ac_flagB1 = 0;
			if(counter == 99){counter = 1;}
			else{counter = counter +1;}
		}
		updateClockBuffer2(counter);
		if(ac_flagB2 == 1) {
							ac_flagB2 = 0;
							value_led_set[0]= led_buffer[2];
							value_led_set[1] = led_buffer[3];
							}

				 scan_led7seg();
		if(ac_flagB0 == 1){mode = mode3;
		ac_flagB0 =0;}

			break;
	case mode3:

		if( frist_buttonset[1] == 1){
					 frist_buttonset[1] = 0;
					 counter = value_led_set[2]*10 + value_led_set[3];
				}

				if(ac_flagB1 == 1){
					ac_flagB1 = 0;
					if(counter == 99){counter = 1;}
					else{counter = counter +1;}
				}
				updateClockBuffer2(counter);
				if(ac_flagB2 == 1) {
									ac_flagB2 = 0;
									value_led_set[2]= led_buffer[2];
									value_led_set[3] = led_buffer[3];
									}

						 scan_led7seg();
				if(ac_flagB0 == 1){mode = mode4;
				ac_flagB0 =0;}


			break;
	case mode4:

		if( frist_buttonset[2] == 1){
					 frist_buttonset[2] = 0;
					 counter = value_led_set[4]*10 + value_led_set[5];
				}

				if(ac_flagB1 == 1){
					ac_flagB1 = 0;
					if(counter == 99){counter = 1;}
					else{counter = counter +1;}
				}
				updateClockBuffer2(counter);
				if(ac_flagB2 == 1) {
									ac_flagB2 = 0;
									value_led_set[4]= led_buffer[2];
									value_led_set[5] = led_buffer[3];
									}

						 scan_led7seg();
				if(ac_flagB0 == 1){mode = mode1;
				ac_light_led_1[0]=1;
				ac_light_led_2[0]=1;
				counter =0;
				counter2 =0;
				ac_flagB0 =0;}



			break;
	default:
		break;
}
}
void blinking_LEDs(){
	switch (mode) {
		case mode2:
			if(Timer2_flag == 1){
				Settimer2(50);
			HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
			HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
			HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin|LED4_Pin|LED5_Pin, GPIO_PIN_RESET);

			}
			break;
		case mode3:
			if(Timer2_flag == 1){
			Settimer2(50);
			HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
			HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);
			HAL_GPIO_WritePin(GPIOB, LED0_Pin|LED2_Pin|LED3_Pin|LED5_Pin, GPIO_PIN_RESET);}
					break;
		case mode4:
			if(Timer2_flag == 1){
			Settimer2(50);
			HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
			HAL_GPIO_TogglePin(LED5_GPIO_Port,LED5_Pin);
			HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED0_Pin|LED4_Pin|LED3_Pin, GPIO_PIN_RESET);}
					break;
		default:
			break;
	}
}



//int num = 0 ;

