# NetDmaInterruptDpc function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaInterruptDpc** function notifies the NetDMA interface that a DMA transfer deferred procedure call
(DPC) has completed on a DMA channel.

## Parameters

### `NetDmaChannelHandle` [in]

A handle that identifies the DMA channel. The DMA provider driver received this handle from NetDMA
in a call to the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

### `DmaDescriptor` [in, optional]

A pointer to the last DMA descriptor that was processed.

## Return value

None.

## Remarks

DMA providers call the
**NetDmaInterruptDpc** function in their DPC handler.

## See also

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)