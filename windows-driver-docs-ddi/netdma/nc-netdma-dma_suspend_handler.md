# DMA_SUSPEND_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
*ProviderSuspendDma* function suspends the DMA transfers that are currently in progress on a DMA
channel.

## Parameters

### `ProviderChannelContext` [in]

A pointer that identifies a DMA channel's context area. The DMA provider returned this handle to
NetDMA at the location that is specified in the
*pProviderChannelContext* parameter of the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

### `pLastDescriptor` [out]

A pointer to a variable that contains the physical address of the last successfully processed DMA
descriptor. The DMA provider provides this address before returning from
*ProviderSuspendDma*.

## Return value

*ProviderSuspendDma* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The
*ProviderSuspendDma* function is an optional function for NetDMA providers. The NetDMA interface can
call the
*ProviderSuspendDma* function, if any, to temporarily suspend any DMA transfers that are in progress
on a DMA channel.

The DMA provider completes the transfer of the current DMA descriptor before it returns from
*ProviderSuspendDma*. If completion status reporting is enabled, the DMA engine writes the
**NetDmaTransferStatusSuspend** status in the address that is specified in the
**CompletionVirtualAddress** and
**CompletionPhysicalAddress** members in the
[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters) structure.

While the DMA transfers are suspended, the NetDMA interface can modify the DMA descriptor linked list
(for example, to insert or delete descriptors).

The NetDMA interface calls the
[ProviderResumeDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_resume_handler) function to resume DMA
operations that were suspended by calling
*ProviderSuspendDma*.

NetDMA calls
*ProviderSuspendDma* at IRQL <= DISPATCH_LEVEL.

## See also

[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderResumeDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_resume_handler)