# NDIS_PD_QUERY_COUNTER callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*NdisPDQueryCounter* function to query the current values stored in a counter object.

**Note** You must declare the function by using the **NDIS_PD_QUERY_COUNTER** type. For more
information, see the following Examples section.

## Parameters

### `CounterHandle` [in]

A counter handle that the miniport driver allocated in its [NdisPDAllocateCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_counter) function.

### `CounterValue` [out]

The miniport returns a pointer to a [NDIS_PD_COUNTER_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_counter_value) structure that contains the values stored in the counter object.

## Return value

This callback function does not return a value.

## See also

[NDIS_PD_COUNTER_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_counter_value)