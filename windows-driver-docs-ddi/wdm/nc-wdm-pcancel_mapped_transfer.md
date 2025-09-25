# PCANCEL_MAPPED_TRANSFER callback function

## Description

The **CancelMappedTransfer** routine cancels a system DMA transfer that is currently mapped to an adapter.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that is waiting for the pending DMA transfer to complete. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine, and the caller passed this pointer to the [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex) call that set up the map registers for the DMA transfer.

### `DmaTransferContext` [in]

A pointer to a DMA transfer context. This parameter value must be the same DMA transfer context that was passed to the [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex) call that requested the adapter channel allocation.

## Return value

**CancelMappedTransfer** returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

**CancelMappedTransfer** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

This routine marks the associated transfer context as canceled, which prevents any further transfers under this context. After a transfer is canceled, its completion routine is called, but the status for the transfer might be set to **DmaCancelled**.

Regardless of whether a system DMA transfer is canceled or completed, the [FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers) or [FlushAdapterBuffersEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex) routine must always be called to flush any data that remains in the system DMA controller's internal cache at the end of a DMA transfer operation. After the transfer is canceled or completed, the **FlushAdapterBuffers*Xxx*** call must occur before either the DMA channel is released or the [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex) routine is called to set up the map registers for a new DMA transfer.

## See also

[AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[FlushAdapterBuffersEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex)

[InitializeDmaTransferContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex)