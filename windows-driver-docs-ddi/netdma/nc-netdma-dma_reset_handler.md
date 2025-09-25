# DMA_RESET_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
*ProviderResetChannel* function resets a DMA channel to the initial state that existed after the DMA
channel was allocated.

## Parameters

### `ProviderChannelContext` [in]

A pointer that identifies a DMA channel's context area. The DMA provider returned this handle to
NetDMA at the location that is specified in the
*pProviderChannelContext* parameter of the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

## Return value

*ProviderResetChannel* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The
*ProviderResetChannel* function is an optional function for NetDMA providers. The NetDMA interface
calls the DMA provider driver's
*ProviderResetChannel* function, if any, to reset a DMA channel.

In
*ProviderResetChannel*, the NetDMA provider should terminate any active transfer immediately without
completing the transfer of the data that is associated with the current DMA descriptor. If completion status reporting is enabled, the DMA engine writes the
**NetDmaTransferStatusHalted** status in the address that is specified in the
**CompletionVirtualAddress** and
**CompletionPhysicalAddress** members in the
[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters) structure.

After the reset operation is complete, the DMA channel must be in the initial state that existed after
the channel was allocated. After the NetDMA interface calls
*ProviderResetChannel*, the DMA provider cannot access any of the previously submitted DMA
descriptors. The DMA channel must be ready for the NetDMA interface to call the
[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler) function.

NetDMA calls
*ProviderResetChannel* at IRQL <= DISPATCH_LEVEL.

## See also

[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler)