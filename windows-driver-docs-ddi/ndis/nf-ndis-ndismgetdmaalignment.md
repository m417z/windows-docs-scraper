# NdisMGetDmaAlignment function

## Description

The
**NdisMGetDmaAlignment** function returns the alignment requirements of the DMA system for a NIC.

## Parameters

### `MiniportAdapterHandle` [in]

An NDIS handle that identifies the miniport adapter for the NIC. This handle was originally passed
to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

## Return value

Returns a value that specifies the alignment requirements of the DMA system. The miniport driver
uses this value to round up the size of a receive buffer to a cache-line size or a multiple of that size
when it allocates such a buffer.

## Remarks

**Note** A miniport driver must have already called [NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) or [NdisMRegisterDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterdmachannel) to initialize a
scatter/gather DMA channel before calling **NdisMGetDmaAlignment**.

A miniport driver can call the
**NdisMGetDmaAlignment** function to determine alignment requirements for DMA buffers that it
allocates. A miniport driver might require increasing the returned value because of additional hardware
device restrictions.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)