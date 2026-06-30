/*
 * GPIO_Driver.h
 *
 *  Created on: Apr 13, 2026
 *      Author: chandrakumar.A
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include "stm32f407xx.h"

// WE HAVE 16 NUMBER OF PIN IN SINGLE PORT
#define GPIO_PIN_0		0
#define GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define GPIO_PIN_7		7
#define GPIO_PIN_8		8
#define GPIO_PIN_9		9
#define GPIO_PIN_10		10
#define GPIO_PIN_11		11
#define GPIO_PIN_12		12
#define GPIO_PIN_13		13
#define GPIO_PIN_14		14
#define GPIO_PIN_15		15


// Pin_Moder Macros-> refer RM: Section 8.4.1 (GPIO port mode register (GPIOx_MODER))
#define GPIO_INPUT		0	//00: Input (reset state)
#define GPIO_OUTPUT		1	//01: General purpose output mode
#define GPIO_ATLFN		2	//10: Alternate function mode
#define GPIO_ANALOG		3	//11: Analog mode

// Pin speeder modes macros -> refer RM: Section 8.4.3 (GPIO port output speed register (GPIOx_OSPEEDR)
#define GPIO_LOW_SPEED		0	//00: Low speed
#define GPIO_MED_SPEED		1	//01: Medium speed
#define GPIO_HIGH_SPEED		2	//10: High speed
#define GPIO_VHIGH_SPEED	3	//11: Very high speed

// Pin Pull-up/Down Control Register macros- > refer RM: Section 8.4.4 (GPIO port pull-up/pull-down register (GPIOx_PUPDR))
#define GPIO_NOPUPD			0	//00: No pull-up, pull-down
#define GPIO_PU				1	//01: Pull-up
#define GPIO_PD				2	//10: Pull-down
#define GPIO_RESERVED		3	//11: Reserved


// Port output type macros - > refer RM: Section 8.4.2 (GPIO port output type register (GPIOx_OTYPER))
#define GPIO_PUSHPULL	0		// 0: Output push-pull (reset state)
#define	GPIO_OPENDR		1		// 1: Output open-drain

// Pin Alternate Function macros -> refer RML Section 8.4.9 & 8.4.10 (GPIO alternate function low register (GPIOx_AFRL) & GPIO alternate function high register (GPIOx_AFRH))
#define GPIO_AF0		0
#define GPIO_AF1		1
#define GPIO_AF2		2
#define GPIO_AF3		3
#define GPIO_AF4		4
#define GPIO_AF5		5
#define GPIO_AF6		6
#define GPIO_AF7		7
#define GPIO_AF8		8
#define GPIO_AF9		9
#define GPIO_AF10		10
#define GPIO_AF11		11
#define GPIO_AF12		12
#define GPIO_AF13		13
#define GPIO_AF14		14
#define GPIO_AF15		15



//Clock Enable or Disable of API

void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t En_Dis);

// GPIO_INITIALIZATION & DEINITIALIZATION
/*
 * GPIO_Pin Number
 * GPIO_Pin MOde
 * GPIO_Pin Speed
 * GPIO_Pin Pull-up/down Control
 * GPIO_Pin Output Type
 * GPIO_Alternate Function Mode
 */

void GPIO_Init(GPIO_RegDef_t *pGPIOX, uint8_t Pin_Number,  uint8_t Pin_Mode, uint8_t Pin_Speed, uint8_t Pull_Up_Ctrl, uint8_t Pin_OPtype, uint8_t Pin_Alt_Fun_Mode );

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

// Read/Write

uint8_t GPIO_ReadFromIn_Pin(GPIO_RegDef_t *pGPIOx, uint8_t Pin_Number);

// here we are using uint16_t to read the All 16 bit values each port has 16 pins
uint16_t GPIO_ReadFromIn_Port(GPIO_RegDef_t *pGPIOx);

void GPIO_WriteToOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t Pin_Number, uint8_t value);
void GPIO_WriteToOut_Port(GPIO_RegDef_t *pGPIOx, uint16_t Value);

void GPIO_ToggleOut_Pin(GPIO_RegDef_t *pGPIOx, uint8_t Pin_Number);


#endif /* GPIO_DRIVER_H_ */
