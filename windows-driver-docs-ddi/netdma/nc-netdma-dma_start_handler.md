# DMA_START_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The *ProviderStartDma* function starts a DMA transfer on the specified DMA channel.

## Parameters

### `ProviderChannelContext` [in]

A pointer that identifies a DMA channel's context area. The DMA provider returned this handle to
NetDMA at the location that is specified in the
*pProviderChannelContext* parameter of the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

### `DescriptorVirtualAddress` [in]

A pointer to the virtual address of the first
[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor) structure in a linked
list of DMA descriptors. The corresponding physical address is specified at the
*DescriptorPhysicalAddress* parameter.

### `DescriptorPhysicalAddress` [in]

A pointer to the physical address of the first DMA descriptor in a linked list of DMA descriptors.
The corresponding virtual address is specified at the
*DescriptorVirtualAddress* parameter.

### `DescriptorCount` [in]

The number of DMA descriptors at
*DescriptorVirtualAddress* .

**Note** NetDMA provider drivers prior to NetDMA version 2.0 can ignore the
*DescriptorCount* parameter. For NetDMA 2.0 and later versions, this parameter is the count of
descriptors in the DMA operation.

## Return value

*ProviderStartDma* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_RESOURCES** | The operation failed because of insufficient resources. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The NetDMA interface calls a DMA provider driver's
*ProviderStartDma* function to start a DMA transfer. The NetDMA interface can call
*ProviderStartDma* at any time after a DMA channel is allocated. The NetDMA interface must call
*ProviderStartDma* after it calls the
[ProviderAbortDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_abort_handler),
[ProviderResetChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_reset_handler), or
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function for a DMA channel.

The source of the DMA transfer is a linked list of DMA descriptors. The
**NextDescriptor** member of the
[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor) structure at the
*DescriptorVirtualAddress* parameter contains the physical address of the next NET_DMA_DESCRIPTOR
structure in the linked list.

**Note** In NetDMA 2.0 and later versions, the linked list of descriptors is not
NULL-terminated. The
**NextDescriptor** member in the last descriptor in the linked list specifies the physical address of
the
[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor) structure that will be
used in the subsequent call to the
[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler) function. A NetDMA 2.0
provider driver can cache the address in
**NextDescriptor** and use this address as the beginning of the linked list for the next Append
operation.

To perform the start operation, the DMA provider must disregard the existing DMA descriptor list, if
any, after it completes any processing on the current descriptor. The DMA provider must ignore the
**NextDescriptor** member in the current NET_DMA_DESCRIPTOR structure and load the descriptor that
*ProviderStartDma* specifies.

After
*ProviderStartDma* starts the initial DMA transfer, the NetDMA interface can call the
[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler) function to append
additional data to the transfer.

NetDMA calls
*ProviderStartDma* at IRQL <= DISPATCH_LEVEL.

## See also

[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor)

[ProviderAbortDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_abort_handler)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler)

[ProviderResetChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_reset_handler)