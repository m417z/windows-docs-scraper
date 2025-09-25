# NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_GET_FIRST_INFO macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_GET_FIRST_INFO** macro to access the first [**NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) element that is specified by an [**NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_parameters) structure.

## Parameters

### `_PortEnumParams_`

A pointer to an **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS** structure.

## Return value

The **NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_GET_FIRST_INFO** macro returns a pointer to the first [**NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info) element that is specified by an [**NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_parameters) structure.

## Remarks

## See also

[**NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_info)

[**NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_enum_parameters)