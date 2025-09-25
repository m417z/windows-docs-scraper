# _WWAN_SAR_CONFIG_INFO structure

## Description

The **WWAN_SAR_CONFIG_INFO** structure describes a modem's current Specific Absorption Rate (SAR) configuration information.

## Members

### `SarMode`

A [**WWAN_SAR_CONTROL_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_control_mode) value that specifies how the SAR back off mechanism is controlled.

### `SarBackoffStatus`

A [**WWAN_SAR_BACKOFF_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_backoff_state) value that specifies the state of SAR backoff for the modem's antennas.

### `SarWifiIntegration`

A [**WWAN_SAR_WIFI_HARDWARE_INTEGRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_wifi_hardware_integration) value that specifies whether Wi-Fi and Cellular are integrated at the hardware level.

### `SarConfigIndexListHeader`

A [**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) structure that represents a list of SAR configurations that the modem supports. The **ElementType** member in the **WWAN_LIST_HEADER** should be set to **WwanStructSarConfig**. The **ElementCount** member in the **WWAN_LIST_HEADER** should be set to the number of [**WWAN_SAR_CONFIG_INDICES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_config_indices) structures that follow the **WWAN_LIST_HEADER** structure.

## Remarks

This structure is used in the [**NDIS_WWAN_SAR_CONFIG_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sar_config_info) structure.

## See also

[MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support)

[OID_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-config)

[**NDIS_WWAN_SAR_CONFIG_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sar_config_info)

[**WWAN_SAR_CONTROL_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_control_mode)

[**WWAN_SAR_BACKOFF_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_backoff_state)

[**WWAN_SAR_WIFI_HARDWARE_INTEGRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_wifi_hardware_integration)

[**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)