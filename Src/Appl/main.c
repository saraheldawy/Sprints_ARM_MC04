#include "IntCtrl.h"
#include "Mcu.h"
#include "Port.h"
#include "DIO.h"
int main(void)
{
	/*MCU_Initializations*/
	Mcu_Init(&Mcu_ConfigTypeStruct);
	//Mcu_InitClock(ACTIVE_CLOCK_CONFIG_MODE);
	Mcu_DistributePllClock();
	IntCtrl_Init();
	Port_Init(Port_Config);
	while(1);
	return 0;
}