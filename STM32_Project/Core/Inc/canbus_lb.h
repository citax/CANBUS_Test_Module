/*******************************************************************************
 * @File        : canbus_lb.h
 * @Created_on  : 18 March 2024
 * @Author      : Ahmet Citak
 * @Email       : ahmet.cittak@gmail.com
 * @About       : Embedded Software Engineer

 ******************************************************************************/

#ifndef INC_CANBUS_LB_H_
#define INC_CANBUS_LB_H_

/***************************** Private Includes *******************************/

#include "stm32f4xx_hal.h"


/************************ Defining Constants **********************************/

#define CAN_Filter_Mask_ID_High				0
#define CAN_Filter_ID_High					0
#define CAN_TX_ID							0x030


/********************** Defining Enums and Structs ****************************/


/********************** Defining Function Protypes ****************************/

void Can_Init(void);
void Can_Interrupt(void);
void Uart_Init(void);
void Uart_Interrupt(void);

#endif /* INC_CANBUS_LB_H_ */
