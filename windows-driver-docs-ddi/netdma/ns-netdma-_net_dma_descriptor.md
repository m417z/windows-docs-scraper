# _NET_DMA_DESCRIPTOR structure

## Description

**Note** The NetDMA interface is not supported in Windows 8 and later.

The NET_DMA_DESCRIPTOR structure specifies the DMA transfer information for each entry in a linked
list of DMA descriptors.

## Members

### `TransferSize`

The size, in bytes, of the memory block that is associated with this DMA descriptor.

NetDMA 2.0 and later provider drivers use the
**DCAContext32**,
**DCAContext16**, and
**DCAContext8** members of the union with
**TransferSize** to support
[Direct Cache Access
(DCA)](https://learn.microsoft.com/windows-hardware/drivers/network/direct-cache-access--dca-).

### `DCAContext32`

A 32 bit DCA context.

### `DCAContext32.DCAContext`

A DCA context.

### `DCAContext16`

A 16 bit DCA context.

### `DCAContext16.DCAContext`

A DCA context.

### `DCAContext16.Reserved`

Reserved bits.

### `DCAContext8`

An 8 bit DCA context.

### `DCAContext8.DCAContext`

A DCA context.

### `DCAContext8.Reserved`

Reserved bits.

### `ControlFlags`

A set of flags that specify the operations that the DMA engine should perform for this DMA
descriptor. This member must contain one or more of the following values (combined with a bitwise OR
operation):

| Unless otherwise noted, descriptions apply to when the bit is set. | Meaning |
| --- | --- |
| **NET_DMA_SOURCE_PAGE_BREAK** | A NetDMA version 2.0 or later provider starts the copy from the source physical address that is specified in the **SourceAddress** member and when it reaches the end of the first page, it continues the copy from the physical address that is specified in the **NextSourceAddress** member. |
| **NET_DMA_DESTINATION_PAGE_BREAK** | A NetDMA version 2.0 or later provider starts the copy to the destination physical address that is specified in the **DestinationAddress** member and when it reaches the end of the first page, it continues the copy to the physical address that is specified in the **NextDestinationAddress** member. |
| **NET_DMA_OP_TYPE_CONTEXT_CHANGE** | The DMA engine should identify the descriptor as a *context change* descriptor.<br><br>The NetDMA interface submits a context change descriptor to DCA-capable NetDMA providers to set the DCA target processor of the destination data for all of the DMA transfers on a NetDMA channel. The NetDMA interface uses the **DCAContext8** member in a context change descriptor to specify the 8-bit advanced programmable interrupt controller (APIC) identifier of the target processor for the channel.<br><br>A DCA-capable NetDMA provider must keep the DCA affinity of a DMA channel with a processor as long as it has not received a new context change descriptor.<br><br>The NetDMA interface submits a context change descriptor one time after the channel has been allocated and again when NetDMA detects that the DMA provider might have lost the hardware context (for example, after a suspend and resume operation). |
| **NET_DMA_DESTINATION_DCA_ENABLE** | If the DMA operation type is a standard DMA transfer, the DMA engine should send a DCA hint for the destination data to the DCA target processor that has been assigned to the DMA channel.<br><br>To set the DCA target processor of a DMA channel, the NetDMA interface previously submitted a context change descriptor to that channel. |
| **NET_DMA_INTERRUPT_ON_COMPLETION** | The DMA engine should generate an interrupt for the associated DMA channel after it processes this DMA descriptor.<br><br>When this bit is cleared, the DMA engine does not generate an interrupt. |
| **NET_DMA_SOURCE_NO_SNOOP** | The source address should not be snooped.<br><br>When this bit is cleared, the source address is in coherent memory space, and each CPU cache line must be snooped. The DMA client must verify that snooping of CPU caches is not required for proper DMA operation. |
| **NET_DMA_DESTINATION_NO_SNOOP** | The destination address should not be snooped.<br><br>When this bit is cleared, the destination address is in coherent memory space, and each CPU cache line must be snooped. The DMA client must verify that snooping of CPU caches is not required for proper DMA operation. |
| **NET_DMA_STATUS_UPDATE_ON_COMPLETION** | The **CompletionVirtualAddress** and **CompletionPhysicalAddress** members in the [NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters) structure reference a completion status value. The DMA engine updates the completion status value when it completes the processing of this descriptor.<br><br>The completion status value is a 64-bit-wide combination of the physical address of the most recent DMA descriptor that the DMA engine processed, and additional status information.<br><br>When this bit is cleared, the DMA engine does not use **CompletionVirtualAddress** or **CompletionPhysicalAddress**. |
| **NET_DMA_SERIALIZE_TRANSFER** | The DMA engine guarantees that all writes for this descriptor, including data and completion status, are complete before it reads the data for the next descriptor.<br><br>When this bit is cleared, the DMA engine can start processing the next descriptor before it completes the processing of this descriptor. |
| **NET_DMA_NULL_TRANSFER** | A DMA transfer is not required for this descriptor. The DMA engine is not required to check the **TransferSize**, **SourceAddress**, or **DestinationAddress** members.<br><br>When this bit is cleared, a DMA transfer might be required or it might be a zero-length transfer. The DMA engine must check the **TransferSize**, **SourceAddress**, or **DestinationAddress** members.<br><br>**Note** If this bit is set or cleared, the NetDMA client must always ensure that the descriptor defines valid transfer parameters. |

The following bitmasks identify the remaining bits in the
**ControlFlags** member:

| Value | Meaning |
| --- | --- |
| **NET_DMA_OP_TYPE_MASK** | A bit mask that specifies bits that are reserved for a DMA operation type. The NetDMA interface sets these bits to zero. |
| **NET_DMA_RESERVED_MASK** | A bit mask that specifies bits that are reserved for future applications. The NetDMA interface sets these bits to zero. |

### `SourceAddress`

The physical address of a memory block that is a source for the DMA transfer.

### `DestinationAddress`

The physical address of a memory block that is a destination for the DMA transfer.

### `NextDescriptor`

The physical address of the next NET_DMA_DESCRIPTOR structure in the linked list of descriptors.
If this descriptor is the last descriptor in the list,
**NextDescriptor** is **NULL**.

### `Reserved1`

A ULONG64 value that is reserved for the DMA engine or the DMA provider driver to use. NetDMA 2.0
and later provider drivers use the
**NextSourceAddress** member of the union with
**Reserved1** to support
[Source and Destination Page
Break](https://learn.microsoft.com/windows-hardware/drivers/network/source-and-destination-page-break).

### `NextSourceAddress`

The physical address of the second page of source address that is used in source page
break.

### `Reserved2`

A ULONG64 value that is reserved for use the DMA engine or the DMA provider driver to use. NetDMA
2.0 and later provider drivers use the
**NextDestinationAddress** member of the union with
**Reserved2** to support
[Source and Destination Page
Break](https://learn.microsoft.com/windows-hardware/drivers/network/source-and-destination-page-break).

### `NextDestinationAddress`

The physical address of the second page of destination address that is used in destination page
break.

### `UserContext1`

A ULONG64 value that is reserved for the NetDMA interface to use.

### `UserContext2`

A ULONG64 value that is reserved for the NetDMA interface to use.

## Remarks

The NET_DMA_DESCRIPTOR structure specifies the source, destination, and control information for a
single DMA transfer in a linked list of DMA descriptors.

To start a DMA transfer, the NetDMA interface supplies the physical address of a NET_DMA_DESCRIPTOR
structure at the
*DescriptorPhysicalAddress* parameter of the DMA provider driver's
[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler) function. The
*DescriptorVirtualAddress* parameter contains the virtual address of the descriptor.

The
**NextDescriptor** member of a NET_DMA_DESCRIPTOR structure contains the physical address of the next
NET_DMA_DESCRIPTOR structure in the linked list of descriptors.

The NetDMA interface calls a DMA provider driver's
[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler) function to append a
linked list of DMA descriptors after the last descriptor on a DMA channel.

## See also

[NET_DMA_CHANNEL_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_channel_parameters)

[ProviderAppendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_append_handler)

[ProviderStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_start_handler)