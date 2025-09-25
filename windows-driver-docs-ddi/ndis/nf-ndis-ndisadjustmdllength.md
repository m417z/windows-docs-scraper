# NdisAdjustMdlLength macro

## Description

The
**NdisAdjustMdlLength** function modifies the length of the data that is associated with an MDL.

## Parameters

### `_Mdl` [in]

A pointer to a memory descriptor list (MDL).

### `_Length` [in]

The number of bytes of data that the MDL describes.

## Remarks

The
**NdisAdjustMdlLength** function modifies the
**ByteCount** member of an MDL that was allocated by calling the
[NdisAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatemdl) function.

The caller of
**NdisAdjustMdlLength** can pass only an MDL descriptor that the caller allocated. It cannot pass an
MDL descriptor that another driver allocated.

For example, the driver of a bus-master DMA NIC calls
**NdisAdjustMdlLength** with MDL descriptors that it allocated to specify receive MDLs in its shared
memory block. Before such a driver indicates received data, it calls
**NdisAdjustMdlLength** to make the MDL descriptor that it will include in the receive indication match
the size of the received data if it is less than the size of the NIC's receive buffer.

The length that is passed to
**NdisAdjustMdlLength** cannot be larger than the length that was passed to
[NdisAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatemdl) when the MDL descriptor
was allocated.

The caller of
**NdisAdjustMdlLength** must restore the length to its original value before it frees the MDL
descriptor with
[NdisFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreemdl).

Callers of
**NdisAdjustMdlLength** can run at any IRQL, but typically run at IRQL <= DISPATCH_LEVEL.

## See also

[NdisAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatemdl)

[NdisFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreemdl)