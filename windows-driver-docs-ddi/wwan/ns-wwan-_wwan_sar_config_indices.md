# _WWAN_SAR_CONFIG_INDICES structure

## Description

The **WWAN_SAR_CONFIG_INDICES** structure represents a Specific Absorption Rate (SAR) configuration for a mobile broadband (MBB) modem.

## Members

### `SarAntennaIndex`

A **ULONG** value specifying the antenna, or executor, for this SAR configuration.

### `SarBackoffIndex`

A **ULONG** value specifying the SAR back off index for the antenna indicated by **SarAntennaIndex**.

## Remarks

A list of **WWAN_SAR_CONFIG_INDICES** follows the **SarConfigIndexListHeader** member of either the [**WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_config) structure or the [**WWAN_SAR_CONFIG_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_config_info) structure.

## See also

[**WWAN_SET_SAR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sar_config)

[**WWAN_SAR_CONFIG_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_config_info)