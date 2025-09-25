# DMA_APPEND_HANDLER callback function

## Description

**Note** The NetDMA interface is not supported
in Windows 8 and later.

The *ProviderAppendDma* function appends a linked list of DMA descriptors to the last descriptor on a DMA channel.

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

*ProviderAppendDma* returns one of the following status values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_UNSUCCESSFUL** | The operation failed for unspecified reasons. |

## Remarks

The NetDMA interface calls a DMA provider driver's
*ProviderAppendDma* function to append a linked list of DMA descriptors after the last descriptor on
a DMA channel. The NetDMA interface can call
*ProviderAppendDma* any number of times after a DMA transfer is started. However, the NetDMA
interface must call the
[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler) function after a channel
reset or abort, or after the DMA channel is first allocated.

**Note** In NetDMA 2.0 and later versions, the linked list of descriptors is not
NULL-terminated. The
**NextDescriptor** member in the last descriptor in the linked list specifies the physical address of
the
[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor) structure that will be
used in the subsequent call to the
**ProviderAppendDma** function. A NetDMA 2.0
provider driver can cache the address in
**NextDescriptor** and use this address as the beginning of the linked list for the next Append
operation.

The NetDMA interface sets the
**NextDescriptor** member of the last descriptor to the beginning of the new chain of descriptors
before calling
*ProviderAppendDma*.

If the current descriptor in an active transfer is the last descriptor, the DMA engine must reread the
last descriptor. The
**NextDescriptor** member in the last
[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor) structure should have
a new address, and the DMA engine should continue with the next descriptor. If the current descriptor is
not the last descriptor, the DMA engine can continue processing DMA descriptors with no additional
tasks.

NetDMA calls
*ProviderAppendDma* at IRQL <= DISPATCH_LEVEL.

## See also

[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler)