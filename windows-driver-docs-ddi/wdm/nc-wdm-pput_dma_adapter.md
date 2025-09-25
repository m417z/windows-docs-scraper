# PPUT_DMA_ADAPTER callback function

## Description

The **PutDmaAdapter** routine frees a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure previously allocated by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure to be released.

## Remarks

**PutDmaAdapter**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

**PutDmaAdapter** frees a DMA adapter object previously allocated by **IoGetDmaAdapter**. Drivers should call **PutDmaAdapter** after completing DMA operations and freeing any map registers and common buffer allocated with this adapter object. After **PutDmaAdapter** returns, the driver can no longer use the DMA adapter object.

A driver must call **PutDmaAdapter** when it receives a PnP [IRP_MN_STOP_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-stop-device) request.

## See also

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)