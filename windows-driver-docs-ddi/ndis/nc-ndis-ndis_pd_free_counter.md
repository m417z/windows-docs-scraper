# NDIS_PD_FREE_COUNTER callback function

## Description

The PacketDirect (PD) platform calls a PD-capable miniport driver's
*NdisPDFreeCounter* function to free a counter object.

**Note** You must declare the function by using the **NDIS_PD_FREE_COUNTER** type. For more
information, see the following Examples section.

## Parameters

### `CounterHandle` [in]

A counter handle that the miniport driver allocated in its [NdisPDAllocateCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_counter) function.

## Return value

This callback function does not return a value.

## See also

[NdisPDAllocateCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_counter)