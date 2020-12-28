/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "IntCtrl.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCtrl_Init(void)
{
	uint8 numOfGpPri = NUM_OF_GROUP_PRI;
	uint8 i = 0;
	uint8 PriValue = 0;
	volatile uint32 * CurrentPRI = &PRI0; /*initially*/
	uint8 IRQ_Num = 0;
	IntCtrl_InterruptType IntName;
	uint8 GroupPri;
	uint8 SubGroupPri;
	/*Enable/Disable Global Interrupt*/
	#if(ENABLE_GLOBAL_INTERRUPT == 1)
		__asm
			(
				"CPSIE i \n"
			);
	#else
		__asm
			(
				"CPSID i \n"
			);
	#endif
	
	/*Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT->B.VECTKEY =0xFA05;
	switch(numOfGpPri)
	{
		case 1:
			APINT->B.PRIGROUP = 0x7;
			break;
		case 2:
			APINT->B.PRIGROUP = 0x6;
			break;
		case 4:
			APINT->B.PRIGROUP = 0x5;
			break;
		case 8:
			APINT->B.PRIGROUP = 0x0;
			break;
		/*if the user entered invalid number then the default will be 8 GP and 1 SubGP*/
		default:
			APINT->B.PRIGROUP = 0x0;
			break;
	}
	
	for(i=0; i<NUM_OF_ACTIVE_INTERRUPT; i++)
	{
		IntName = IntCtrl_Cfg_UserArray[i].IntCtrl_Name;
		GroupPri = IntCtrl_Cfg_UserArray[i].IntCtrl_GroupPri;
		SubGroupPri = IntCtrl_Cfg_UserArray[i].IntCtrl_SubGroupPri;
		/*check for valid Group and Sub-Group Priorities*/
		if((numOfGpPri == 8)) 
		{
			if(GroupPri > 7)
			{
				SubGroupPri = 0;
				GroupPri = 7;
			}
			PriValue = (GroupPri << 5);
		}
		else if(numOfGpPri == 4)
		{
			if(GroupPri > 3)
			{
				GroupPri = 3;
			}
			if(SubGroupPri > 1)
			{
				SubGroupPri = 1;
			}
			PriValue = (GroupPri << 6)|(SubGroupPri << 5);
		}
		else if(numOfGpPri == 2) 
		{
			if(GroupPri > 1)
			{
				GroupPri = 1;
			}
			if(SubGroupPri > 3)
			{
				SubGroupPri = 3;
			}
			PriValue = (GroupPri << 7)|(SubGroupPri << 5);
		}
		else if(numOfGpPri == 1)
		{
			if(SubGroupPri > 7)
			{
				SubGroupPri = 7;
				GroupPri = 0;
			}
			PriValue = (SubGroupPri << 5);
		}
		else
		{
			/*INVALID Number of Group priority */
		}
		
		if(IntName < 16)
		{
			/*Set Priority for Exceptions and Faults*/
			/*Enable System Exceptions and Faults*/
			switch(IntName)
			{
				case IntCtrl_USAGE_FAULT:
					SETBIT(SYSHNDCTRL,18);
					break;
				case IntCtrl_BUS_FAULT:
					SETBIT(SYSHNDCTRL,17);
					break;
				case IntCtrl_MEM_MANAGE:
					SETBIT(SYSHNDCTRL,16);
					break;
				default:
					break;
			}
			
		}
		
		else
		{
			IRQ_Num = (uint8)IntName - 16; /*get the interrupt request number "IRQ" */
			/*Set interrupt Priority*/
			if((IRQ_Num >= 0) && (IRQ_Num < 4))
			{
				CurrentPRI = &PRI0;
			}
			else if((IRQ_Num >= 4) && (IRQ_Num < 8))
			{
				CurrentPRI = &PRI1;
			}
			else if((IRQ_Num >= 8) && (IRQ_Num < 12))
			{
				CurrentPRI = &PRI2;
			}
			else if((IRQ_Num >= 12) && (IRQ_Num < 16))
			{
				CurrentPRI = &PRI3;
			}
			else if((IRQ_Num >= 16) && (IRQ_Num < 20))
			{
				CurrentPRI = &PRI4;
			}
			else if((IRQ_Num >= 20) && (IRQ_Num < 24))
			{
				CurrentPRI = &PRI5;
			}
			else if((IRQ_Num >= 24) && (IRQ_Num < 28))
			{
				CurrentPRI = &PRI6;
			}
			else if((IRQ_Num >= 28) && (IRQ_Num < 32))
			{
				CurrentPRI = &PRI7;
			}
			else if((IRQ_Num >= 32) && (IRQ_Num < 36))
			{
				CurrentPRI = &PRI8;
			}
			else if((IRQ_Num >= 36) && (IRQ_Num < 40))
			{
				CurrentPRI = &PRI9;
			}
			else if((IRQ_Num >= 40) && (IRQ_Num < 44))
			{
				CurrentPRI = &PRI10;
			}
			else if((IRQ_Num >= 44) && (IRQ_Num < 48))
			{
				CurrentPRI = &PRI11;
			}
			else if((IRQ_Num >= 48) && (IRQ_Num < 52))
			{
				CurrentPRI = &PRI12;
			}
			else if((IRQ_Num >= 52) && (IRQ_Num < 56))
			{
				CurrentPRI = &PRI13;
			}
			else if((IRQ_Num >= 56) && (IRQ_Num < 60))
			{
				CurrentPRI = &PRI14;
			}
			else if((IRQ_Num >= 60) && (IRQ_Num < 64))
			{
				CurrentPRI = &PRI15;
			}
			else if((IRQ_Num >= 64) && (IRQ_Num < 68))
			{
				CurrentPRI = &PRI16;
			}
			else if((IRQ_Num >= 68) && (IRQ_Num < 72))
			{
				CurrentPRI = &PRI17;
			}
			else if((IRQ_Num >= 72) && (IRQ_Num < 76))
			{
				CurrentPRI = &PRI18;
			}
			else if((IRQ_Num >= 76) && (IRQ_Num < 80))
			{
				CurrentPRI = &PRI19;
			}
			else if((IRQ_Num >= 80) && (IRQ_Num < 84))
			{
				CurrentPRI = &PRI20;
			}
			else if((IRQ_Num >= 84) && (IRQ_Num < 88))
			{
				CurrentPRI = &PRI21;
			}
			else if((IRQ_Num >= 88) && (IRQ_Num < 92))
			{
				CurrentPRI = &PRI22;
			}
			else if((IRQ_Num >= 92) && (IRQ_Num < 96))
			{
				CurrentPRI = &PRI23;
			}
			else if((IRQ_Num >= 96) && (IRQ_Num < 100))
			{
				CurrentPRI = &PRI24;
			}
			else if((IRQ_Num >= 100) && (IRQ_Num < 104))
			{
				CurrentPRI = &PRI25;
			}
			else if((IRQ_Num >= 104) && (IRQ_Num < 108))
			{
				CurrentPRI = &PRI26;
			}
			else if((IRQ_Num >= 108) && (IRQ_Num < 112))
			{
				CurrentPRI = &PRI27;
			}
			else if((IRQ_Num >= 112) && (IRQ_Num < 116))
			{
				CurrentPRI = &PRI28;
			}
			else if((IRQ_Num >= 116) && (IRQ_Num < 120))
			{
				CurrentPRI = &PRI29;
			}
			else if((IRQ_Num >= 120) && (IRQ_Num < 124))
			{
				CurrentPRI = &PRI30;
			}
			else if((IRQ_Num >= 124) && (IRQ_Num < 128))
			{
				CurrentPRI = &PRI31;
			}
			else if((IRQ_Num >= 128) && (IRQ_Num < 132))
			{
				CurrentPRI = &PRI32;
			}
			else if((IRQ_Num >= 132) && (IRQ_Num < 136))
			{
				CurrentPRI = &PRI33;
			}
			else if((IRQ_Num >= 136) && (IRQ_Num < 138))
			{
				CurrentPRI = &PRI34;
			}
			else
			{
				/*INVALID IRQ_Num*/
			}
			switch (IRQ_Num % 4)
			{
				case 0:
					*(CurrentPRI) = *(CurrentPRI) | (PriValue);
					break;
				case 1:
					*(CurrentPRI) = *(CurrentPRI) | (PriValue << 8);
					break;
				case 2:
					*(CurrentPRI) = *(CurrentPRI) | (PriValue << 16);
					break;
				case 3:
					*(CurrentPRI) = *(CurrentPRI) | (PriValue << 24);
					break;
				default:
					break;
			}
			
			/*Enable Interrupts*/
			if((IRQ_Num >= 0) || (IRQ_Num < 32))
			{
				SETBIT(EN0,IRQ_Num);
			}
			else if ((IRQ_Num >= 32)||(IRQ_Num < 64))
			{
				SETBIT(EN1,IRQ_Num);
			}
			else if ((IRQ_Num >= 64)||(IRQ_Num < 96))
			{
				SETBIT(EN2,IRQ_Num);
			}
			else if ((IRQ_Num >= 96)||(IRQ_Num < 128))
			{
				SETBIT(EN3,IRQ_Num);
			}
			else
			{
				/*INVALID IRQ_Num*/
			}
		}
		
		
	}

	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/