# PREAD_DMA_COUNTER callback function

## Description

The **ReadDmaCounter** routine returns the number of bytes remaining to be transferred during the current subordinate DMA operation.

## Parameters

### `DmaAdapter` [in]

Pointer to the adapter object previously returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) representing the system DMA controller channel currently in use.

## Return value

**ReadDmaCounter** returns the number of bytes remaining to be transferred in the current DMA operation.

## Remarks

**ReadDmaCounter**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

**ReadDmaCounter** can be called only by drivers of subordinate DMA devices. Usually, the caller is the driver of a subordinate device that uses a system DMA controller's autoinitialize mode.

## See also

[AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer)