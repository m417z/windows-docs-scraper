# _WWAN_MODEM_CONFIG_STATE enumeration

## Description

The **WWAN_MODEM_CONFIG_STATE** enumeration lists definitions used by the modem to inform the OS about its modem configuration state.

## Constants

### `WwanModemConfigStateUnknown`

The modem configuration state is currently not available.

### `WwanModemConfigStatePending`

The modem is currently selecting the best suitable configuration file that matches the UICC info.

### `WwanModemConfigStateCompleted`

The modem has completed its configuration and modem subcomponents are aware of the new configuration.

### `WwanModemConfigStateMax`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[WWAN_MODEM_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_config_info)