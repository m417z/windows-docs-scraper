# NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_GET_PROPERTY macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_GET_PROPERTY** macro to access the port property buffer inside an [**NDIS_SWITCH_PORT_PROPERTY_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure.

## Parameters

### `_PortParameters_`

A pointer to an **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS** structure.

## Return value

The **NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_GET_PROPERTY** macro returns a pointer to the port property buffer inside an [**NDIS_SWITCH_PORT_PROPERTY_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters) structure.

## Remarks

## See also

[**NDIS_SWITCH_PORT_PROPERTY_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_property_parameters)