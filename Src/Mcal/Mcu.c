/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Mcu_ConfigType* LocalConfigPtr = NULL_PTR ;
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
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType * ConfigPtr)        
* \Description     : Initialize local configuration pointe                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Mcu_ConfigType   Pointer to the configuration structure                 
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
{
	/*set the Local Configuration Pointer*/
	LocalConfigPtr = ConfigPtr;
}
/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)        
* \Description     : Get the Reset Caues                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                 
* \Parameters (out): Mcu_RawResetType                                                      
* \Return value:   : Mcu_RawResetType EXT_RESET             
                                      MCU_POR_RESET		
                                      MCU_BORWN_OUT_RESET 
                                      MCU_WD0_RESET       
                                      MCU_SW_RESET        
                                      MCU_WD1_RESET       
                                      MOSC_FAIL_RESET     
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
	Mcu_RawResetType Mcu_ResetCause = 0x0;
	switch (RESC)
	{
		case 0x1:
		Mcu_ResetCause = EXT_RESET;
		break;
		case 0x2:
		Mcu_ResetCause = MCU_POR_RESET;
		break;
		case 0x4:
		Mcu_ResetCause = MCU_BORWN_OUT_RESET;
		break;
		case 0x8:
		Mcu_ResetCause = MCU_WD0_RESET;
		break;
		case 0x10:
		Mcu_ResetCause = MCU_SW_RESET;
		break;
		case 0x20:
		Mcu_ResetCause = MCU_WD1_RESET;
		break;
		case 0x10000:
		Mcu_ResetCause = MOSC_FAIL_RESET;
		break;
		default:
		/*More than one reset happened without clearing the register*/
		/*Clear all the register*/
		RESC = 0x0;
		break;
	}
	CLRBIT(RESC,Mcu_ResetCause);
	return Mcu_ResetCause;
}
/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)        
* \Description     : Perform Software System Reset                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): Std_ReturnType                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Mcu_PerformReset(void)
{
	/*set SYSRESREQ in APINT*/
	APINT = (APINT_VECTKEY)|(0x1<<2);
	
}
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)       
* \Description     : choose the Clock Configuration Type                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Mcu_ClockType   Configured clockType                     
* \Parameters (out): Std_ReturnType                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{
	return E_OK;
}
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock(void)       
* \Description     : Set Corresponding Pripheral Clock                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void)
{
	uint8 RegIndex = 0x0;
	uint8 BitOffset = 0x0;
	uint8 i = 0;
	for(i = 0; i < NUM_OF_ACTIVATED_PRIPHERALS; i++)
	{
		/*As the Mcu_ClockGatesCfgType enum is aligned at 8*/
		RegIndex = (LocalConfigPtr->Mcu_ClockGates_Ptr[i]) / 8;
		BitOffset = (LocalConfigPtr->Mcu_ClockGates_Ptr[i]) % 8;
		SETBIT(RCGC_PRIPH(RegIndex),BitOffset);
	}
	return E_OK;
}
/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)        
* \Description     : Get PLL State (the user should pool on until lock before distribute the Pripherals clock)                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): Mcu_PllStatusType                                                      
* \Return value:   : Mcu_PllStatusType  MCU_PLL_STATE_LOCKED
										MCU_PLL_STATE_UNLOCKED
*                                                                    
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
	uint8 PllStateVal = GETBIT(PLLSTAT,0);
	return PllStateVal;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/