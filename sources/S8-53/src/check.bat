rem cppcheck . -j4 --force --enable=all -UBOARD_TE207 -UHAL_CAN_MODULE_ENABLED -UHAL_CRC_MODULE_ENABLED -UHAL_CRYP_MODULE_ENABLED -U__cplusplus -UHAL_DCMI_MODULE_ENABLED -UHAL_I2C_MODULE_ENABLED -UHAL_I2S_MODULE_ENABLED -UHAL_IWDG_MODULE_ENABLED -UHAL_PCCARD_MODULE_ENABLED -UHAL_HASH_MODULE_ENABLED -UHAL_IRDA_MODULE_ENABLED -UHAL_SD_MODULE_ENABLED -UHAL_RNG_MODULE_ENABLED -UHAL_SMARTCARD_MODULE_ENABLED -UHAL_USART_MODULE_ENABLED -UHAL_WWDG_MODULE_ENABLED -USTM32F205xx -UHAL_NAND_MODULE_ENABLED -USTM32F215xx -USTM32F217xx -UWIN32 -UUSE_FULL_ASSERT -UUSE_RTOS=1 -U_WANT_SNAN -U__SUPPORT_SNAN__ -U__ARMVFP__ -U__ICCARM__ -U__CC_ARM -U__NO_EMBEDDED_ASM -U_WIN32 --suppress=variableScope --includes-file=includes.txt 2> err.txt

cppcheck . -j4 --force --enable=all -UBOARD_TE207 -UHAL_CAN_MODULE_ENABLED -UHAL_CRC_MODULE_ENABLED -UHAL_CRYP_MODULE_ENABLED -U__cplusplus -UHAL_DCMI_MODULE_ENABLED -UHAL_I2C_MODULE_ENABLED -UHAL_I2S_MODULE_ENABLED -UHAL_IWDG_MODULE_ENABLED -UHAL_PCCARD_MODULE_ENABLED -UHAL_HASH_MODULE_ENABLED -UHAL_IRDA_MODULE_ENABLED -UHAL_SD_MODULE_ENABLED -UHAL_RNG_MODULE_ENABLED -UHAL_SMARTCARD_MODULE_ENABLED -UHAL_USART_MODULE_ENABLED -UHAL_WWDG_MODULE_ENABLED -USTM32F205xx -UHAL_NAND_MODULE_ENABLED -USTM32F215xx -USTM32F217xx -UWIN32 -UUSE_FULL_ASSERT -UUSE_RTOS=1 -U_WANT_SNAN -U__SUPPORT_SNAN__ -U__ARMVFP__ -U__ICCARM__ -U__CC_ARM -U__NO_EMBEDDED_ASM -U_WIN32 -Ubool --suppress=variableScope 2> err.txt

rem --check-config вывести иноформацию о ненайденных заголовочных файлах
rem --includes-file=includes.txt в файле includes.txt - информация о местах, в которых следует искать включаемые файлы