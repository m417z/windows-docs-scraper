# NDIS_SWITCH_PROPERTY_CUSTOM_GET_BUFFER macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PROPERTY_CUSTOM_GET_BUFFER** macro to access the custom extensible switch property buffer inside an [**NDIS_SWITCH_PROPERTY_CUSTOM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_custom) structure.

## Parameters

### `_SwitchPropertyCustom_`

A pointer to an **NDIS_SWITCH_PROPERTY_CUSTOM** structure.

## Return value

The **NDIS_SWITCH_PROPERTY_CUSTOM_GET_BUFFER** macro returns a pointer to the custom extensible switch property buffer inside an [**NDIS_SWITCH_PROPERTY_CUSTOM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_custom) structure.

## Remarks

## See also

[**NDIS_SWITCH_PROPERTY_CUSTOM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_custom)