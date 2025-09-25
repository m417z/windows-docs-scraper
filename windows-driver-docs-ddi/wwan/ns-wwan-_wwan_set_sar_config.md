# _WWAN_SET_SAR_CONFIG structure

## Description

The **WWAN_SET_SAR_CONFIG** structure describes Specific Absorption Rate (SAR) information that a mobile broadband (MB) modem should use to set its SAR configuration.

## Members

### `SarMode`

A [**WWAN_SAR_CONTROL_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_control_mode) value that specifies how the SAR back off mechanism should be controlled.

### `SarBackoffStatus`

A [**WWAN_SAR_BACKOFF_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_backoff_state) value that specifies the state of SAR backoff for the modem's antennas.

### `SarConfigIndexListHeader`

A [**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) structure that represents a list of SAR configurations that the modem supports. The **ElementType** member in the **WWAN_LIST_HEADER** should be set to **WwanStructSarConfig**. The **ElementCount** member in the **WWAN_LIST_HEADER** should be set to the number of SAR configurations that follow the **WWAN_LIST_HEADER** structure.

## Remarks

This structure is used in the [**NDIS_WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_sar_config) structure.

## See also

[MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support)

[OID_WWAN_SAR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sar-config)

[**NDIS_WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_sar_config)

[**WWAN_SAR_CONTROL_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_control_mode)

[**WWAN_SAR_BACKOFF_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_sar_backoff_state)

[**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)