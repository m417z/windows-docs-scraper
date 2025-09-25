# NetDmaIsr function

## Description

**Note** The NetDMA interface is not supported

in Windows 8 and later.

The
**NetDmaIsr** function notifies the NetDMA interface that a DMA transfer interrupt has occurred on a DMA
channel.

## Parameters

### `NetDmaChannelHandle` [in]

A handle that identifies the DMA channel. The DMA provider driver received this handle from the
NetDMA interface in a call to the
[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler) function.

### `DmaDescriptor` [in]

The physical address of the DMA descriptor that is associated with the interrupt.

### `pCpuNumber` [out]

The number of the CPU that is associated with the interrupt DPC. The NetDMA interface writes this
CPU number at the provided address before
**NetDmaIsr** returns.

## Return value

None

## Remarks

DMA provider drivers call the
**NetDmaIsr** function in their interrupt service routine (ISR).

If the NET_DMA_INTERRUPT_ON_COMPLETION flag in the
**ControlFlags** member of the
[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor) structure is set, the
DMA engine should generate an interrupt for the DMA channel after it processes the DMA descriptor. When
this flag is cleared, the DMA engine does not generate an interrupt.

**Note** When the ISR is called, the current DMA descriptor might already be different from
the descriptor that triggered the interrupt.

A DMA provider driver should do as little work as possible in its ISR handler. The driver should defer
I/O operations to the interrupt DPC handler.

## See also

[NET_DMA_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/ns-netdma-_net_dma_descriptor)

[ProviderAllocateDmaChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdma/nc-netdma-dma_channel_allocate_handler)