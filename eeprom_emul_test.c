#include "eeprom_emul.h"

uint16_t VarValue = 0;
uint16_t VirtAddVarTab[NumbOfVar] = {1, 2, 3};

void EE_Test()
{
	uint16_t result;

	FLASH_Unlock();
	result = EE_Init();
	assert_param(result == FLASH_COMPLETE);

	int i;
	for (i = 0; i < 1000; ++i) {
		result = EE_WriteVariable(1, i);
		assert_param(result == FLASH_COMPLETE);
	}


	result = EE_WriteVariable(1, 0x34);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(2, 0x43);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(2, 0x44);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(3, 0x53);
	assert_param(result == FLASH_COMPLETE);
	result = EE_WriteVariable(3, 0x54);
	assert_param(result == FLASH_COMPLETE);

	uint16_t readData;
	result = EE_ReadVariable(1, &readData);
	assert_param(result == 0);	//variable was found
	assert_param(readData == 0x34);

	result = EE_ReadVariable(2, &readData);
	assert_param(result == 0);
	assert_param(readData == 0x44);

	result = EE_ReadVariable(3, &readData);
	assert_param(result == 0);
	assert_param(readData == 0x54);

}
