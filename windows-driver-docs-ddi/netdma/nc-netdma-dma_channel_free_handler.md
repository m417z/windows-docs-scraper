# DMA_CHANNEL_FREE_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
*ProviderFreeDmaChannel* function frees a DMA channel that the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function previously allocated.

## Parameters

### `ProviderChannelContext` [in]

A pointer that identifies a DMA channel's context area. The DMA provider returned this handle to
NetDMA at the location that is specified in the
*pProviderChannelContext* parameter of the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

## Remarks

The NetDMA interface calls a DMA provider driver's
*ProviderFreeDmaChannel* function to free a DMA channel. Before the NetDMA interface calls
*ProviderFreeDmaChannel*, it ensures that there are no outstanding DMA operations on this
channel.

After the NetDMA interface calls
*ProviderFreeDmaChannel*, it does not call any
*ProviderXxx* functions for the freed channel.

The NetDMA interface frees all of the allocated DMA channels before it returns from the
[NetDmaProviderStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstop) function.

NetDMA calls
*ProviderFreeDmaChannel* at IRQL <= DISPATCH_LEVEL.

## See also

[NetDmaProviderStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nf-netdma-netdmaproviderstop)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)