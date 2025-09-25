# PINITIALIZE_DMA_TRANSFER_CONTEXT callback function

## Description

The **InitializeDmaTransferContext** routine initializes an opaque DMA transfer context that is used to track pending allocations of DMA resources.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `DmaTransferContext` [out]

A pointer to a caller-allocated buffer into which **InitializeDmaTransferContext** writes the initial values for the DMA transfer context. This context is opaque to the caller. The caller must allocate a buffer that is large enough to contain the DMA transfer context. The size, in bytes, of this context is specified by the **DMA_TRANSFER_CONTEXT_SIZE_V1** constant in the Wdm.h header file.

## Return value

**InitializeDmaTransferContext** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETERS** | This routine failed due to invalid parameter values passed by the caller. |

## Remarks

**InitializeDmaTransferContext** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

An initialized DMA transfer context must be supplied as a parameter to the [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex), [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), or [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex) routine. Each of these routines writes information about the requested DMA resource allocation to the DMA transfer context. This information is opaque to the caller. To cancel a pending allocation request, the caller must supply the DMA transfer context for the request to the [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) routine.

The DMA transfer context that is supplied to **AllocateAdapterChannelEx**, **GetScatterGatherListEx**, or **BuildScatterGatherListEx** must be unique across all adapter allocation requests.

## See also

[AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

[CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)