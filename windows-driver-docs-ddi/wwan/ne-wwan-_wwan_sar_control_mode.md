# _WWAN_SAR_CONTROL_MODE enumeration

## Description

The **WWAN_SAR_CONTROL_MODE** enumeration specifies how the SAR back off mechanism is controlled.

## Constants

### `WwanSarControlModeDevice`

The SAR back off mechanism is controlled by the modem device directly.

### `WwanSarControlModeOS`

The SAR back off mechanism is controlled and managed by the operating system.

## Remarks

This enumeration is used in the [**WWAN_SAR_CONFIG_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_config_info) structure and the [**WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_config) structure.

## See also

[MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support)

[OID_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-config)

[**WWAN_SAR_CONFIG_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_config_info)

[**WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_config)