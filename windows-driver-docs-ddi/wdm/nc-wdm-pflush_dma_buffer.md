## Description

The callback routine flushes any data remaining in the memory region described by an MDL.

## Parameters

### `DmaAdapter:` [in]

A pointer to a DMA_ADAPTER structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `Mdl:` [in]

A pointer to the MDL that describes the buffer previously passed in the driver's call to [*MapTransfer*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer).

### `ReadOperation:` [in]

Specifies TRUE if the flush is being performed for a read operation, and FALSE for a write operation. For more information, see the following Remarks section.

## Return value

Returns STATUS_SUCCESS if the call is successful. Otherwise, returns an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

## See also

[Flushing Cached Data during DMA Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/flushing-cached-data-during-dma-operations)