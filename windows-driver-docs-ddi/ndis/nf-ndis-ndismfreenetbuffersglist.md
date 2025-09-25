# NdisMFreeNetBufferSGList function

## Description

> [!CAUTION]
> For ARM and ARM64 processors, we strongly recommend that NDIS driver writers use WDF DMA or WDM DMA instead of NDIS Scatter/Gather DMA.
>
> For more information about WDF DMA, see [Handling DMA Operations in KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-dma-operations-in-kmdf-drivers).
>
> For more information about WDM DMA, see the DMA-related child topics of [Managing Input/Output for Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-input-output-for-drivers).

Bus-master miniport drivers call the
**NdisMFreeNetBufferSGList** function to free scatter/gather list resources that were allocated by
calling the
[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist) function.

## Parameters

### `NdisMiniportDmaHandle` [in]

A handle to a context area that NDIS uses to manage a DMA resource. The caller obtained this
handle by calling the
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) function.

### `pSGL` [in]

A pointer to a miniport driver scatter/gather list buffer.

### `NetBuffer` [in]

A pointer to the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure associated with the
specified scatter/gather list buffer.

## Remarks

Bus-master miniport drivers must call the
**NdisMFreeNetBufferSGList** function to free a scatter/gather list. A miniport driver typically calls
**NdisMFreeNetBufferSGList** from its
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function
while it is handling a send complete interrupt or at any time that the driver no longer requires the
scatter/gather list. Do not call
**NdisMFreeNetBufferSGList** while the driver or hardware is still accessing the memory that is
described by the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure that is associated with the
scatter/gather list.

Miniport drivers can free the buffer that was specified in the
*ScatterGatherListBuffer* parameter of the
[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist) function after
**NdisMFreeNetBufferSGList** returns.

Before accessing received data, miniport drivers must call **NdisMFreeNetBufferSGList** to flush the memory cache.

## See also

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[NDIS Scatter/Gather DMA](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-scatter-gather-dma)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NdisMAllocateNetBufferSGList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismallocatenetbuffersglist)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)