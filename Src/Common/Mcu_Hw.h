/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint32	MOCDIS		:1;
	uint32				:3;
	uint32	OSCSRC		:2;
	uint32	XTAL		:5;
	uint32	BYPASS		:1;
	uint32				:1;
	uint32	PWRDN		:1;
	uint32				:3;
	uint32	PWMDIV		:3;
	uint32	USEPWMDIV	:1;
	uint32				:1;
	uint32	USESYSDIV	:1;
	uint32	SYSDIV		:4;
	uint32	ACG			:1;
	uint32				:4;
	
}RCC_BF;
typedef struct
{
	uint32				:4;
	uint32	OSCSRC2		:3;
	uint32				:4;
	uint32	BYPASS2		:1;
	uint32				:1;
	uint32	PWRDN2		:1;
	uint32	USBPWRDN	:1;
	uint32				:7;
	uint32	SYSDIV2LSB	:1;
	uint32	SYSDIV2		:6;
	uint32				:1;
	uint32	DIV400		:1;
	uint32	USERCC2		:1;
	
}RCC2_BF;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/***************************************** Interrupt Controller Registers ********************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             			0xE000E000
#define ENx_BASE_ADDRESS								0xE000E100
#define DISx_BASE_ADDRESS								0xE000E180
#define PENDx_BASE_ADDRESS								0xE000E200	
#define UNPENDx_BASE_ADDRESS							0xE000E280	
#define ACTIVEx_BASE_ADDRESS							0xE000E300	
#define PRIx_BASE_ADDRESS								0xE000E400
#define APINT_VECTKEY 									0x05FA0000

#define EN(n)											*((volatile uint32*)(ENx_BASE_ADDRESS+0x4*(n)))
#define DIS(n)								  	 		*((volatile uint32*)(DISx_BASE_ADDRESS+0x4*(n)))
#define PEND(n)								 	  		*((volatile uint32*)(PENDx_BASE_ADDRESS+0x4*(n)))
#define UNPEND(n)								 	  	*((volatile uint32*)(UNPENDx_BASE_ADDRESS+0x4*(n)))
#define ACTIVE(n)								 	  	*((volatile uint32*)(ACTIVE_BASE_ADDRESS+0x4*(n)))
#define PRI(n)											*((volatile uint32*)(PRIx_BASE_ADDRESS+0x4*n))
#define SWTRIG											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))
	
#define ACTLR											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008))
#define CPUID											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00))
#define INTCTRL											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define VTABLE 											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))
#define APINT  											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define SYSCTRL											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10))
#define CFGCTRL											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14))
#define SYSPRI1											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3                                			*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define SYSHNDCTRL										*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define FAULTSTAT 										*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD28))
#define HFAULTSTAT										*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD2C))
#define MMADDR    										*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD34))
#define FAULTADDR 										*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD38))

/*************************************************** MCU Registers ***************************************************/
#define SYS_CTRL_BASE_ADDRESS							0X400FE000
#define RCGC_PERPH_BASE_ADDRESS							0x400FE600

#define RESC											*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x05C))
#define RCC												*((volatile RCC_BF*)(SYS_CTRL_BASE_ADDRESS+0x060))
#define RCC2											*((volatile RCC2_BF*)(SYS_CTRL_BASE_ADDRESS+0x070))
#define PLLFREQ0										*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x160))
#define PLLFREQ1										*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x164))
#define PLLSTAT											*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x168))
#define RCGC_PRIPH(n)									*((volatile uint32*)(RCGC_PERPH_BASE_ADDRESS+0x4*(n)))
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/