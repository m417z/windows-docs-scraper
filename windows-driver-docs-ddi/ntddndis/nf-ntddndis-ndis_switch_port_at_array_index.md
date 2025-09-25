# NDIS_SWITCH_PORT_AT_ARRAY_INDEX macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PORT_AT_ARRAY_INDEX** macro to access an [**NDIS_SWITCH_PORT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters) element inside an [**NDIS_SWITCH_PORT_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array) structure.

## Parameters

### `_PortArray_`

A pointer to an **NDIS_SWITCH_PORT_ARRAY** structure.

### `_Index_`

A USHORT value that specifies the zero-based index of the **NDIS_SWITCH_PORT_PARAMETERS** element inside the **NDIS_SWITCH_PORT_ARRAY**.

> [!NOTE]
> This value must be less than the value of the **NumElements** member of the **NDIS_SWITCH_PORT_ARRAY** structure.

## Return value

The **NDIS_SWITCH_PORT_AT_ARRAY_INDEX** macro returns a pointer to the specified [**NDIS_SWITCH_PORT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters) element inside the [**NDIS_SWITCH_PORT_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array).

## Remarks

## See also

[**NDIS_SWITCH_PORT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_parameters)

[**NDIS_SWITCH_PORT_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_switch_port_array)