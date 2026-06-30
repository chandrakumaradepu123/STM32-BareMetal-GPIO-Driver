/*
 * GPIO_Driver.c
 *
 *  Created on: Apr 13, 2026
 *      Author: chandrakumar.A
 */

#include "GPIO_Driver.h"

void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t En_Dis)
{
	if(En_Dis == ENABLE)
	{
		if(pGPIOx == GPIOA) GPIOA_Clk_En();
		else if(pGPIOx == GPIOB) GPIOB_Clk_En();
		else if(pGPIOx == GPIOC) GPIOC_Clk_En();
		else if(pGPIOx == GPIOD) GPIOD_Clk_En();
		else if(pGPIOx == GPIOE) GPIOE_Clk_En();
		else if(pGPIOx == GPIOF) GPIOF_Clk_En();
		else if(pGPIOx == GPIOG) GPIOG_Clk_En();
		else if(pGPIOx == GPIOH) GPIOH_Clk_En();
		else if(pGPIOx == GPIOI) GPIOI_Clk_En();
	}
	else if(En_Dis == DISABLE)
	{
		if(pGPIOx == GPIOA) GPIOA_Clk_DI();
		else if(pGPIOx == GPIOB) GPIOB_Clk_DI();
		else if(pGPIOx == GPIOC) GPIOC_Clk_DI();
		else if(pGPIOx == GPIOD) GPIOD_Clk_DI();
		else if(pGPIOx == GPIOE) GPIOE_Clk_DI();
		else if(pGPIOx == GPIOF) GPIOF_Clk_DI();
		else if(pGPIOx == GPIOG) GPIOG_Clk_DI();
		else if(pGPIOx == GPIOH) GPIOH_Clk_DI();
		else if(pGPIOx == GPIOI) GPIOI_Clk_DI();
	}
}

void GPIO_Init(GPIO_RegDef_t *pGPIOX,
		uint8_t Pin_Number,
		uint8_t Pin_Mode,
		uint8_t Pin_Speed,
		uint8_t Pull_Up_Ctrl,
		uint8_t Pin_OPtype,
		uint8_t Pin_Alt_Fun_Mode)
{
	// Set the mode
	pGPIOX->MODER &= ~(3 <<(2*Pin_Number));	// Clearing the bit fields 3 means -> in binaray will return 11 it occupies 2 bits
	pGPIOX->MODER |= (Pin_Mode << (2*Pin_Number)); 		// each Pin has to set 2 bits for Moder

	// Set the Speed
	pGPIOX->OSPEEDR &= ~(3 <<(2*Pin_Number));	// Clearing the bit fields 3 means -> in binaray will return 11 it occupies 2 bits
	pGPIOX->OSPEEDR |= (Pin_Speed << (2*Pin_Number)); 	// each Pin has to set 2 bits for OSpeeder

	// Set the Pullup/Down control registers
	pGPIOX->PUPDR &= ~(3 <<(2*Pin_Number));	// Clearing the bit fields 3 means -> in binaray will return 11 it occupies 2 bits
	pGPIOX->PUPDR |= (Pull_Up_Ctrl << (2*Pin_Number)); 		// each Pin has to set 2 bits for Pin pull-up/Down

	// Set the gpio port output type register
	pGPIOX->PUPDR &= ~(1 <<2*Pin_Number);	// Clearing the bit fields 1
	pGPIOX->PUPDR |= (Pin_OPtype << Pin_Number); 		// each Pin has to set 2 bits for Pin pull-up/Down

	// Set the Alternate function of the GPIO Pin
	if(Pin_Number <=7)
	{ // alternate function low register
		pGPIOX->AFRL  &= ~(15 <<4*Pin_Number);	// Clearing the bit fields 4
		pGPIOX->AFRL |= (Pin_Alt_Fun_Mode << (4*Pin_Number));
	}
	else
	{ // alternate function High register
		pGPIOX->AFRH  &= ~(15 <<4*Pin_Number);	// Clearing the bit fields 4
		pGPIOX->AFRH |= (Pin_Alt_Fun_Mode << (4*Pin_Number));
	}
}

// 1st we have to send the port name
//  check the rcc rgister map section 6.3.26 from UM.

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	// reset the port cofigurations
	if(pGPIOx == GPIOA) RCC->AHB1RSTR |= (1<<0);
	else if(pGPIOx == GPIOB) RCC->AHB1RSTR |= (1<<1);
	else if(pGPIOx == GPIOC) RCC->AHB1RSTR |= (1<<2);
	else if(pGPIOx == GPIOD) RCC->AHB1RSTR |= (1<<3);
	else if(pGPIOx == GPIOE) RCC->AHB1RSTR |= (1<<4);
	else if(pGPIOx == GPIOF) RCC->AHB1RSTR |= (1<<5);
	else if(pGPIOx == GPIOG) RCC->AHB1RSTR |= (1<<6);
	else if(pGPIOx == GPIOH) RCC->AHB1RSTR |= (1<<7);
	else if(pGPIOx == GPIOI) RCC->AHB1RSTR |= (1<<8);
}

// here, we are needed the return type because i want to know if the pin is set to 0 or 1
uint8_t GPIO_ReadFromIn_Pin(GPIO_RegDef_t *pGPIOx, uint8_t Pin_Number)
{	// check the section 8.4.5, 8.4.6
	uint8_t value;
	value = (((pGPIOx->IDR)>> Pin_Number) & 0x00000001);
	return value;
}

// here we are using uint16_t to read the All 16 bit values each port has 16 pins
uint16_t GPIO_ReadFromIn_Port(GPIO_RegDef_t *pGPIOx)
{
	uint16_t Value;
	Value = pGPIOx->IDR ;
	return Value;
}

void GPIO_WriteToOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t Pin_Number, uint8_t value)
{
	if(value == 1)
	{
		pGPIOx->ODR |= (value << Pin_Number);
	}
	else if (value == 0)
	{
		pGPIOx->ODR &= ~(value << Pin_Number);
	}
}

void GPIO_WriteToOut_Port(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

// toggling the output pin of the selected port
void GPIO_ToggleOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t Pin_Number)
{
	 pGPIOx->ODR = pGPIOx->ODR ^ (1 << Pin_Number);
}





