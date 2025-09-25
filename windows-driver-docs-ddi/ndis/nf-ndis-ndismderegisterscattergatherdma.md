# NdisMDeregisterScatterGatherDma function

## Description

> [!CAUTION]
> For ARM and ARM64 processors, we strongly recommend that NDIS driver writers use WDF DMA or WDM DMA instead of NDIS Scatter/Gather DMA.
>
> For more information about WDF DMA, see [Handling DMA Operations in KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-dma-operations-in-kmdf-drivers).
>
> For more information about WDM DMA, see the DMA-related child topics of [Managing Input/Output for Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-input-output-for-drivers).

Bus-master miniport drivers call
**NdisMDeregisterScatterGatherDma** to release DMA resources that were allocated with the
[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma) function.

## Parameters

### `NdisMiniportDmaHandle` [in]

A handle to a context area that NDIS uses to manage a DMA resource. The caller obtained this
handle by calling the
**NdisMRegisterScatterGatherDma** function.

## Remarks

An NDIS miniport driver calls
**NdisMDeregisterScatterGatherDma** from its
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function to release the
DMA resources it allocated and initialized in a previous call to
**NdisMRegisterScatterGatherDma**.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NDIS Scatter/Gather DMA](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-scatter-gather-dma)

[NdisMRegisterScatterGatherDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterscattergatherdma)