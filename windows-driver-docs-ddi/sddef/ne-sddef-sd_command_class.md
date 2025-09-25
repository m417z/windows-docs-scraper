# SD_COMMAND_CLASS enumeration

## Description

The SD_COMMAND_CLASS enumeration lists the classes of Secure Digital (SD) card commands.

## Constants

### `SDCC_STANDARD`

Indicates an SD card command from the standard command set. This command set includes command codes 0 to 63.

### `SDCC_APP_CMD`

Indicates an SD command from the application command set. This command set includes command codes 0 to 63, preceded by the application command escape code 55.

SD card drivers should not issue CMD55 (APP_CMD) commands through the SD bus interface. The bus driver will automatically issue the CMD55 command on behalf of the SD card driver when the command class is SDCC_APP_CMD.

## See also

[**SDCMD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ns-sddef-_sdcmd_descriptor)