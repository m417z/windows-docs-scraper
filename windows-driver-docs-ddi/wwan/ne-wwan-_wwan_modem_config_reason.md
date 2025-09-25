# _WWAN_MODEM_CONFIG_REASON enumeration

## Description

The **WWAN_MODEM_CONFIG_REASON** enumeration lists definitions for reasons why a modem's configuration state change was triggered.

## Constants

### `WwanModemConfigReasonNone`

Default value that can be used if other optional reasons are not supported.

### `WwanModemConfigReasonSIMDetected`

Required. A SIM card was detected by a modem.

### `WwanModemConfigReasonNOSIM`

Optional. There is no SIM card.

### `WwanModemConfigReasonIMSIReset`

Optional. A SIM card was reset with new IMSI programmed into it.

### `WwanModemConfigReasonActivationFailure`

Optional. Activation of a new configuration failed.

### `WwanModemConfigReasonConfigFileUpdate`

Optional. A new configuration file was updated by the host.

### `WwanModemConfigReasonModemReset`

Optional. The modem reset and configuration was not lost.

### `WwanModemConfigReasonModemRecovery`

Required. The modem reset and configuration was restored to default.

### `WwanModemConfigReasonMax`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## See also

[WWAN_MODEM_CONFIG_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_modem_config_info)