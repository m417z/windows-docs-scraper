# _NET_DMA_CHANNEL_PARAMETERS structure

## Description

**Note** The NetDMA interface is not supported in Windows 8 and later.

The **NET_DMA_CHANNEL_PARAMETERS** structure specifies the configuration parameters that a DMA provider
driver should use to configure a DMA channel.

## Members

### `Revision`

The revision number of this structure.

For Windows 7 and Windows Server 2008 R2 and later, set this member to
**NET_DMA_CHANNEL_PARAMETERS_REVISION_2**.

For Windows Vista and Windows Server 2008, set this member to
**NET_DMA_CHANNEL_PARAMETERS_REVISION_1**.

### `Size`

The size, in bytes, of this structure. Set this member to
sizeof(**NET_DMA_CHANNEL_PARAMETERS**).

### `Flags`

A set of bits for flags that define DMA channel attributes. Set this member to zero. There are
currently no flags defined.

### `CompletionVirtualAddress`

The virtual address of the memory location where the DMA engine can write the DMA transfer
completion status. This virtual address is associated with the physical address that is specified in the
**CompletionPhysicalAddress** member.

### `CompletionPhysicalAddress`

The physical address of the memory location where the DMA engine can write the DMA transfer
completion status. If the **NET_DMA_STATUS_UPDATE_ON_COMPLETION** flag is not set in the
**ControlFlags** member of the
[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor) structure,
**CompletionPhysicalAddress** is not used. Otherwise, the completion status value at the specified
address is a 64-bit wide combination of the physical address of the most recent DMA descriptor that the
DMA engine processed and additional status information.

The physical address of the DMA descriptor must be aligned to 64-bit boundaries. Therefore, the lower
six bits of the address are available for other information. The DMA engine combines the following
status values with the descriptor address by using a bitwise OR operation:

| Value | Meaning |
| --- | --- |
| **NetDmaTransferStatusActive** | The DMA transfer for the most recent DMA descriptor completed without errors, and the DMA engine has more descriptors to process. |
| **NetDmaTransferStatusIdle** | The DMA transfer for the last DMA descriptor in the linked list of descriptors completed without errors. |
| **NetDmaTransferStatusSuspend** | The DMA transfer for the most recent DMA descriptor completed without errors, and DMA transfers are suspended because the NetDMA interface called the [ProviderSuspendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_suspend_handler) function. The DMA engine will restart the transfer after the NetDMA interface calls the [ProviderResumeDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_resume_handler) function. |
| **NetDmaTransferStatusHalted** | The DMA transfer for the most recent DMA transfer was aborted because of errors or because the NetDMA interface called the [ProviderAbortDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_abort_handler) function. |
| **NetDmaTransferStatusArmed** | The DMA transfer for the first descriptor has not completed and the completed descriptor address is not valid. |

### `ProcessorAffinityMask`

A bitmap that indicates CPUs that are available for use with this DMA channel. Each bit in
**ProcessorAffinityMask** identifies a CPU. For example, setting bit 0 indicates CPU 0 can be used,
setting bit 1 indicates CPU 1 can be used, and so on.

### `ChannelPriority`

A DMA channel priority value that represents the priority for the DMA channel relative to other
DMA channels on the same DMA engine. A lower priority setting indicates a lower priority DMA channel. If
this value indicates a higher priority than the hardware supports, the highest value that the hardware
supports should be used. The Windows Vista NetDMA interface sets this member to zero.

### `CpuNumber`

The CPU number that is associated with the DMA channel. The DMA provider driver sets the value
before it returns from the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function. The DMA engine uses this CPU for interrupt DPCs that are
associated with the DMA channel. If the DMA engine and computer configuration support MSI-X, the
interrupt should also be associated with the indicated CPU number, unless there was no MSI-X interrupt
available for the indicated CPU.

### `ProcessorAffinityMaskEx`

The group number and a bitmap of the CPUs that this DMA channel could be associated with.

## Remarks

Before using a DMA channel, the NetDMA interface calls the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function of the DMA provider driver to allocate and initialize the DMA
channel.

The NetDMA interface supplies a **NET_DMA_CHANNEL_PARAMETERS** structure at the
*ChannelParameters* parameter of
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler).

## See also

[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor)

[ProviderAbortDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_abort_handler)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)

[ProviderResumeDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_resume_handler)

[ProviderSuspendDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_suspend_handler)