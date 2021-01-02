#include "IntCtrl.h"
#include "Mcu.h"
int main(void)
{
	/*MCU_Initializations*/
	Mcu_Init(&Mcu_ConfigTypeStruct);
	Mcu_InitClock(ACTIVE_CLOCK_CONFIG_MODE);
	if(Mcu_ConfigTypeStruct.Mcu_ClockSettingsCfg_Ptr[ACTIVE_CLOCK_CONFIG_MODE].Mcu_PllState == PLL_ENABLED)
	{
		while(Mcu_GetPllStatus() != MCU_PLL_STATE_LOCKED);
	}
	else
	{
		/*DO NOTHING*/
	}
	Mcu_DistributePllClock();
	IntCtrl_Init();
	while(1);
	return 0;
}