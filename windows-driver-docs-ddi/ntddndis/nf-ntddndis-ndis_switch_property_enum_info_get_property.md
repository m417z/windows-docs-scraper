# NDIS_SWITCH_PROPERTY_ENUM_INFO_GET_PROPERTY macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PROPERTY_ENUM_INFO_GET_PROPERTY** macro to access the extensible switch property buffer that is specified by an [**NDIS_SWITCH_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_info) structure.

## Parameters

### `_SwitchEnumInfo_`

A pointer to an **NDIS_SWITCH_PROPERTY_ENUM_INFO** structure.

## Return value

The **NDIS_SWITCH_PROPERTY_ENUM_INFO_GET_PROPERTY** macro returns a pointer to the extensible switch property buffer.

## Remarks

## See also

[**NDIS_SWITCH_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_property_enum_info)