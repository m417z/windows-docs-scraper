# PFLUSH_ADAPTER_BUFFERS_EX callback function

## Description

The **FlushAdapterBuffersEx** routine flushes any data that remains in the data cache at the end of a DMA transfer operation performed by a system DMA controller or bus-master device.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's system DMA channel or bus-master device. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `Mdl` [in]

A pointer to the MDL chain that describes the pages of memory that are to be flushed. Set this parameter to point to the MDL chain that was used for the DMA transfer. For more information, see the description of the *Mdl* parameter in [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex), or [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex).

### `MapRegisterBase` [in]

A handle to the map registers that were previously allocated for the adapter object.

### `Offset` [in]

The starting offset relative to the start of the MDL chain to use for the flush operation. Set this parameter to the value that was used as the starting offset for the DMA transfer. For more information, see the description of the *Offset* parameter in [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex), or [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex).

### `Length` [in]

The number of bytes of data to flush. Set this parameter to the value that was used as the transfer length for the DMA transfer. For more information, see the description of the *Length* parameter in [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex), or [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex).

### `WriteToDevice` [in]

The direction of the DMA transfer. Set this parameter to the value that was used as the transfer direction for the DMA transfer. For more information, see the description of the *WriteToDevice* parameter in [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex), or [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex).

## Return value

**FlushAdapterBuffersEx** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETERS** | The routine failed due to invalid parameter values passed by the caller. |

## Remarks

**FlushAdapterBuffersEx** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

**FlushAdapterBuffersEx** enables processor cache coherency in hardware platforms that do not implement hardware-enforced cache coherency (bus snooping). In addition, for a system DMA transfer, **FlushAdapterBuffersEx** flushes any data that remains in the system DMA controller's internal cache.

The driver that initiates a scatter/gather DMA transfer must ensure that all of the transferred data is flushed from the cache after the transfer completes. The driver should call **FlushAdapterBuffersEx** before the driver completes the IRP that requested the DMA transfer, and before the driver frees the map registers. For more information, see [Flushing Cached Data during DMA Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/flushing-cached-data-during-dma-operations).

**FlushAdapterBuffersEx** is an extended version of the [FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers) routine. **FlushAdapterBuffersEx** can flush an entire scatter/gather list in one call. In contrast, to use **FlushAdapterBuffers** to flush a scatter/gather list requires a separate call for each MDL in the MDL chain.

**FlushAdapterBuffersEx** can be used in place of **FlushAdapterBuffers** to flush the buffer for a one-packet DMA transfer. In this case, the MDL chain that the *Mdl* parameter points to contains only one MDL. A benefit of using **FlushAdapterBuffersEx** in this way is that the caller can specify an offset into the MDL.

If **FlushAdapterBuffersEx** is called before the DMA transfer operation finishes, this call might cancel the transfer before it can finish or might cause undefined behavior.

## See also

[BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex)