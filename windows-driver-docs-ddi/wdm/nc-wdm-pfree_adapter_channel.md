# PFREE_ADAPTER_CHANNEL callback function

## Description

The **FreeAdapterChannel** routine releases the system DMA controller when a driver has completed all DMA operations necessary to satisfy the current IRP.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

## Remarks

**FreeAdapterChannel**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

After a driver has transferred all the data and called [FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers), it calls **FreeAdapterChannel** to release the system DMA controller that was previously allocated with a call to **AllocateAdapterChannel**.

**FreeAdapterChannel** frees any map registers that were allocated by an earlier call to **AllocateAdapterChannel**. A driver calls this routine only if its [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine returns **KeepObject**.

## See also

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer)