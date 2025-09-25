# DMA_RESUME_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
*ProviderResumeDma* function resumes the DMA transfers that are currently suspended on a DMA
channel.

## Parameters

### `ProviderChannelContext` [in]

A pointer that identifies a DMA channel's context area. The DMA provider returned this handle to
NetDMA at the location that is specified in the
*pProviderChannelContext* parameter of the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

## Return value

*ProviderResumeDma* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The
*ProviderSuspendDma* function is an optional function for NetDMA providers. The NetDMA interface
calls the
*ProviderResumeDma* function, if any, to resume DMA operations that were suspended by calling the
[ProviderSuspendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_suspend_handler) function. If the DMA
provider driver specifies an entry point for a
*ProviderSuspendDma* function, it must also specify an entry point for a
*ProviderResumeDma* function.

When the DMA engine resumes transfers, the hardware should reload the DMA descriptor that it processed
last to get the new next descriptor.

NetDMA calls
*ProviderResumeDma* at IRQL <= DISPATCH_LEVEL.

## See also

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderSuspendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_suspend_handler)