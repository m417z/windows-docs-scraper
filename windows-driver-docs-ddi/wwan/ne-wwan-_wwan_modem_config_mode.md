# _WWAN_MODEM_CONFIG_MODE enumeration

## Description

The **WWAN_MODEM_CONFIG_MODE** enumeration lists modem configuration modes.

## Constants

### `WwanModemConfigModeUnknown`

The modem configuration mode is currently not available.

### `WwanModemConfigModeModemCentric`

The modem configuration mode is modem centric. The modem is responsible for the selection process of configuration based on UICC info or any other vendor-specified algorithm.

### `WwanModemConfigModeHostCentric`

The modem configuration mode is host centric. The host will inform the modem which configuration file the modem will use.

### `WwanModemConfigModeMax`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The modem configuration mode shall not change during runtime. If a change is detected, it will be ignored by the OS.

## See also

[WWAN_MODEM_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_config_info)