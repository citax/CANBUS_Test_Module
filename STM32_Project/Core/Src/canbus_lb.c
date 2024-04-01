/*******************************************************************************
 * @File        : canbus_lb.c
 * @Created_on  : 18 March 2024
 * @Author      : Ahmet Citak
 * @Email       : ahmet.cittak@gmail.com
 * @About       : Embedded Software Engineer

 ******************************************************************************/

/**************************** Defining Header *********************************/

#include "canbus_lb.h"


/********************** Defining Private Variables ****************************/

CAN_TxHeaderTypeDef CAN_TxHeader;
CAN_RxHeaderTypeDef CAN_RxHeader;
uint8_t CAN_TxData[8];
uint8_t CAN_RxData[8];
uint32_t CAN_TxMailBox;

CAN_FilterTypeDef canfilterconfig;

extern CAN_HandleTypeDef hcan1;				// Change to correct CanBUS line.
CAN_HandleTypeDef* CAN_Handle = &hcan1;

/************************ Defining Private Externs ****************************/

/*******************************************************************************
 * @Function_Name   : Uart_Init
 * @Function_Input  : None
 * @Function_Output : None
 * @Function_Brief  : Uart init func.
 ******************************************************************************/
void Uart_Init(void){

	// ToDo: Uart Init fonksiyonu yazılacak.

}


/*******************************************************************************
 * @Function_Name   : Uart_Interrupt
 * @Function_Input  : None
 * @Function_Output : None
 * @Function_Brief  : Uart interrupt func.
 ******************************************************************************/
void Uart_Interrupt(void){

	// ToDo: Uart interrupt fonksiyonu yazılacak.

}


/*******************************************************************************
 * @Function_Name   : Can_Init
 * @Function_Input  : None
 * @Function_Output : None
 * @Function_Brief  : Can Bus init func.
 ******************************************************************************/

void Can_Init(void){

	canfilterconfig.FilterBank = 0;
	canfilterconfig.FilterMode = CAN_FILTERMODE_IDMASK;
	canfilterconfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	canfilterconfig.FilterIdHigh = CAN_Filter_ID_High;
	canfilterconfig.FilterIdLow = 0;
	canfilterconfig.FilterMaskIdHigh = CAN_Filter_Mask_ID_High;
	canfilterconfig.FilterMaskIdLow = 0;
	canfilterconfig.FilterScale = CAN_FILTERSCALE_32BIT;
	canfilterconfig.FilterActivation = ENABLE;
	canfilterconfig.SlaveStartFilterBank = 14;

	HAL_CAN_ConfigFilter(CAN_Handle,&canfilterconfig);

	CAN_TxHeader.DLC = 8; // Number of bites to be transmitted max- 8
	CAN_TxHeader.IDE = CAN_ID_STD;
	CAN_TxHeader.RTR = CAN_RTR_DATA;
	CAN_TxHeader.StdId = CAN_TX_ID;
	CAN_TxHeader.ExtId = 0x02;
	CAN_TxHeader.TransmitGlobalTime = DISABLE;

	HAL_CAN_Start(CAN_Handle);
	HAL_CAN_ActivateNotification(CAN_Handle,CAN_IT_RX_FIFO0_MSG_PENDING);
}


/*******************************************************************************
 * @Function_Name   : Can_Interrupt
 * @Function_Input  : None
 * @Function_Output : None
 * @Function_Brief  : Can Bus interrupt func.
 ******************************************************************************/

void Can_Interrupt(void){

	HAL_CAN_GetRxMessage(CAN_Handle, CAN_RX_FIFO0, &CAN_RxHeader, CAN_RxData); //Receive CAN bus message to canRX buffer

}


