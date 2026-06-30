/*
 * stm32f407xx.h
 *
 *  Created on: Apr 13, 2026
 *      Author: chandrakumar.A
 */

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#include "stdint.h"

// Some other Defines
#define ENABLE		1
#define DISABLE		0


// Defining the base address of Busses
#define AHB1_BASE_ADDR	0x40020000U
#define AHB2_BASE_ADDR	0x50000000U
#define AHB3_BASE_ADDR	0xA0000000U
#define APB1_BASE_ADDR	0x40000000U
#define APB2_BASE_ADDR	0x40010000U


// Define the based address of the GpioPorts
// ALL GPIO PORTS ARE DIRECTLY CONNECTED TO AHB1 BUS ONLY.
//SO WILL WRITE THE BASE ADDRESS = AHB1 BASE ADDR + OFFSET ADDRESS OF SELECTED PORT
#define GPIOA_BASE_ADDR	  (AHB1_BASE_ADDR + (0x0000))
#define GPIOB_BASE_ADDR	  (AHB1_BASE_ADDR + (0x0400))
#define GPIOC_BASE_ADDR	  (AHB1_BASE_ADDR + (0x0800))
#define GPIOD_BASE_ADDR	  (AHB1_BASE_ADDR + (0x0C00))
#define GPIOE_BASE_ADDR	  (AHB1_BASE_ADDR + (0x1000))
#define GPIOF_BASE_ADDR	  (AHB1_BASE_ADDR + (0x1400))
#define GPIOG_BASE_ADDR	  (AHB1_BASE_ADDR + (0x1800))
#define GPIOH_BASE_ADDR	  (AHB1_BASE_ADDR + (0x1C00))
#define GPIOI_BASE_ADDR	  (AHB1_BASE_ADDR + (0x2000))

// Reset & clock Control (RCC) Rgister based address defined
// RCC IS CONNECTED WITH AHB1 BUS DIRECTLY
#define   RCC_BASE_ADDR	 (AHB1_BASE_ADDR + (0x3800))

// GPIO REGISTER DEFINATION AS A SINGLE STRUCTURE
typedef struct
{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
//	uint32_t AFR[2];
	uint32_t AFRL;
	uint32_t AFRH;

}GPIO_RegDef_t;

// RCC Register mapping as a structure
typedef struct
{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t RESERVED2;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED6[2];
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
	uint32_t PLLSAICFGR;
	uint32_t DCKCFGR;
	uint32_t CKGATENR;
	uint32_t DCKCFGR2;
} RCC_RegDef_t;


//Pointer to hold base address of RefDef struct
#define GPIOA	(GPIO_RegDef_t*)GPIOA_BASE_ADDR
#define GPIOB	(GPIO_RegDef_t*)GPIOB_BASE_ADDR
#define GPIOC	(GPIO_RegDef_t*)GPIOC_BASE_ADDR
#define GPIOD	(GPIO_RegDef_t*)GPIOD_BASE_ADDR
#define GPIOE	(GPIO_RegDef_t*)GPIOE_BASE_ADDR
#define GPIOF	(GPIO_RegDef_t*)GPIOF_BASE_ADDR
#define GPIOG	(GPIO_RegDef_t*)GPIOG_BASE_ADDR
#define GPIOH	(GPIO_RegDef_t*)GPIOH_BASE_ADDR
#define GPIOI	(GPIO_RegDef_t*)GPIOI_BASE_ADDR

//Pointers for RCC Base Address
#define RCC  	((RCC_RegDef_t*) RCC_BASE_ADDR)

// Clock Enable and Disable macros for GPIO ports

#define GPIOA_Clk_En()	(RCC->AHB1ENR |= (1<<0))
#define GPIOB_Clk_En()	(RCC->AHB1ENR |= (1<<1))
#define GPIOC_Clk_En()	(RCC->AHB1ENR |= (1<<2))
#define GPIOD_Clk_En()	(RCC->AHB1ENR |= (1<<3))
#define GPIOE_Clk_En()	(RCC->AHB1ENR |= (1<<4))
#define GPIOF_Clk_En()	(RCC->AHB1ENR |= (1<<5))
#define GPIOG_Clk_En()	(RCC->AHB1ENR |= (1<<6))
#define GPIOH_Clk_En()	(RCC->AHB1ENR |= (1<<7))
#define GPIOI_Clk_En()	(RCC->AHB1ENR |= (1<<8))

#define GPIOA_Clk_DI() (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_Clk_DI() (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_Clk_DI() (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_Clk_DI() (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_Clk_DI() (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_Clk_DI() (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_Clk_DI() (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_Clk_DI() (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_Clk_DI() (RCC->AHB1ENR &= ~(1<<8))




#endif /* STM32F407XX_H_ */
