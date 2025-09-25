# NDIS_SWITCH_PORT_DESTINATION_AT_ARRAY_INDEX macro

## Description

Hyper-V extensible switch extensions use the **NDIS_SWITCH_PORT_DESTINATION_AT_ARRAY_INDEX** macro to access an [**NDIS_SWITCH_PORT_DESTINATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) element inside an [**NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array) structure.

## Parameters

### `_DestArray_`

A pointer to an **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure.

### `_Index_`

A USHORT value that specifies the zero-based index of the **NDIS_SWITCH_PORT_DESTINATION** element inside the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY**.

> [!NOTE]
> This value must be less than the value of the **NumElements** member of the **NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY** structure.

## Return value

The **NDIS_SWITCH_PORT_DESTINATION_AT_ARRAY_INDEX** macro returns a pointer to the specified [**NDIS_SWITCH_PORT_DESTINATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination) element inside the [**NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array).

## Remarks

## See also

[**NDIS_SWITCH_PORT_DESTINATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_port_destination)

[**NDIS_SWITCH_FORWARDING_DESTINATION_ARRAY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_destination_array)