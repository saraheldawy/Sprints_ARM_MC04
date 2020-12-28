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
    uint32 VECACT   	:8;
    uint32          	:3;
    uint32 RETBASE  	:1;
    uint32 VECPEND  	:8;
    uint32          	:2;
    uint32 ISRPEND  	:1;
    uint32 ISRPRE   	:1;
    uint32          	:1;
    uint32 PENDSTCLR	:1;
    uint32 PENDSTSET	:1;
    uint32 UNPENDSV 	:1;
    uint32 PENDSV   	:1;
    uint32          	:2;
    uint32 NMISET   	:1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct
{
	uint32 VECTRESET	:1;
	uint32 VECTCLRACT	:1;  
	uint32 SYSRESREQ	:1;
	uint32 				:5;
	uint32 PRIGROUP		:3;
	uint32 				:4;
	uint32 ENDIANESS	:1;
	uint32 VECTKEY		:16;	
}APINT_BF;
typedef union
{
	uint32 		R;
	APINT_BF 	B;
}APINT_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000

#define EN0									   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define EN1									   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2									   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3									   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4									   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))
#define DIS0								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define DIS1								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define DIS2								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define DIS3								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define DIS4								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))
#define PEND0								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))
#define PEND1								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))
#define PEND2								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))
#define PEND3								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))
#define PEND4								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))
#define UNPEND0								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))
#define UNPEND1								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x284))
#define UNPEND2								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x288))
#define UNPEND3								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C))
#define UNPEND4								   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x290))
#define ACTIVE0							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))
#define ACTIVE1							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304))
#define ACTIVE2							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308))
#define ACTIVE3							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C))
#define ACTIVE4							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310))
#define PRI0							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define PRI1							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define PRI2							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define PRI3							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define PRI4							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define PRI5							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define PRI6							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define PRI7							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
#define PRI8							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define PRI9							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define PRI10							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define PRI11							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
#define PRI12							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define PRI13							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define PRI14							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define PRI15							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
#define PRI16							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define PRI17							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define PRI18							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define PRI19							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
#define PRI20							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
#define PRI21							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
#define PRI22							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
#define PRI23							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C))
#define PRI24							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
#define PRI25							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
#define PRI26							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
#define PRI27							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C))
#define PRI28							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
#define PRI29							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
#define PRI30							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
#define PRI31							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C))
#define PRI32							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
#define PRI33							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
#define PRI34							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))
#define SWTRIG							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))


#define ACTLR							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008))
#define CPUID							   	   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00))
#define INTCTRL                                ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define VTABLE                                 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))
#define APINT                                  ((volatile APINT_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define SYSCTRL                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10))
#define CFGCTRL                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14))
#define SYSPRI1                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define SYSHNDCTRL                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define FAULTSTAT                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD28))
#define HFAULTSTAT                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD2C))
#define MMADDR                                 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD34))
#define FAULTADDR                              *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD38))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/