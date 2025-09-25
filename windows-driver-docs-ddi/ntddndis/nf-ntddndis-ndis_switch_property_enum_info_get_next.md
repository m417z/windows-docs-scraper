# NDIS_SWITCH_PROPERTY_ENUM_INFO_GET_NEXT macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PROPERTY_ENUM_INFO_GET_NEXT** macro to access the next [**NDIS_SWITCH_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_info) element that follows an **NDIS_SWITCH_PROPERTY_ENUM_INFO** structure in the array that is specified by an [**NDIS_SWITCH_PROPERTY_ENUM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_parameters) structure.

## Parameters

### `_SwitchEnumInfo_`

A pointer to an **NDIS_SWITCH_PROPERTY_ENUM_INFO** structure.

## Return value

The **NDIS_SWITCH_PROPERTY_ENUM_INFO_GET_NEXT** macro returns a pointer to the next [**NDIS_SWITCH_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_info) element in the array. If the *\_SwitchEnumInfo\_* parameter is the last element in the array, the macro returns **NULL**.

## Remarks

## See also

[**NDIS_SWITCH_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_info)

[**NDIS_SWITCH_PROPERTY_ENUM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_parameters)