# NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_GET_PROPERTY macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_GET_PROPERTY** macro to access the port property buffer that is specified by an [**NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) structure.

## Parameters

### `_PortEnumInfo_`

A pointer to an **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO** structure.

## Return value

The **NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_GET_PROPERTY** macro returns a pointer to the port property buffer.

## Remarks

## See also

[**NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info)