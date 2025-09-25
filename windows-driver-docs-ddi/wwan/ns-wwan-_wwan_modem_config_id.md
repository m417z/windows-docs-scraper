# _WWAN_MODEM_CONFIG_ID structure

## Description

The **WWAN_MODEM_CONFIG_ID** structure represents a unique ID for a modem configuration file.

## Members

### `ConfigIdLen`

A DWORD value indicating the length of **ConfigId**.

### `ConfigId`

A byte array representing the configuration ID. The maximum length of this field is 256 bits, or 32 bytes.

## Remarks

A value of **0** for **ConfigId** is a special value that indicates that the configuration ID is not available.

## See also

[WWAN_MODEM_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_config_info)