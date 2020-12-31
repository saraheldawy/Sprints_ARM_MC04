#include "IntCtrl.h"
#include "Mcu.h"
int main(void)
{
	/*MCU_Initializations*/
	Mcu_Init(&Mcu_ConfigTypeStruct);
	//Mcu_InitClock(0);
	//while(Mcu_GetPllStatus() != MCU_PLL_STATE_LOCKED);
	Mcu_DistributePllClock();
	IntCtrl_Init();
	while(1);
	return 0;
}