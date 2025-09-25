# DMA_ABORT_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
*ProviderAbortDma* function cancels any DMA transfers that are associated with a DMA channel.

## Parameters

### `ProviderChannelContext` [in]

A pointer that identifies a DMA channel's context area. The DMA provider returned this handle to
NetDMA at the location that is specified in the
*pProviderChannelContext* parameter of the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

## Return value

*ProviderAbortDma* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The
*ProviderAbortDma* function is an optional function for NetDMA providers. The NetDMA interface can
call a DMA provider driver's
*ProviderAbortDma* function, if any, to abort all DMA transfers that have been scheduled on a DMA
channel.

In
*ProviderAbortDma*, the DMA provider should terminate the transfer immediately without completing
the transfer of the data that is associated with the current DMA descriptor. If completion status reporting is enabled, the DMA engine writes the
**NetDmaTransferStatusHalted** status in the address that is specified in the
**CompletionVirtualAddress** and
**CompletionPhysicalAddress** members in the
[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters) structure.

After the abort operation completes, the DMA channel must be ready for the NetDMA interface to call
the
[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler) function. The NetDMA
interface will not call the
[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler) function until after
the transfer is restarted.

NetDMA calls
*ProviderAbortDma* at IRQL <= DISPATCH_LEVEL.

## See also

[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler)

[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler)