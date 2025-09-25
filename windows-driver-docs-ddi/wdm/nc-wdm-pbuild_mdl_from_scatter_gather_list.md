## Description

The **BuildMdlFromScatterGatherList** routine builds an MDL from a scatter/gather list allocated by the system.

This routine is reserved for system use.

## Parameters

### `DmaAdapter` [in]

Pointer to the [**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `ScatterGather` [in]

Pointer to the [**SCATTER_GATHER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure passed to the driver's [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine.

### `OriginalMdl` [in]

Pointer to the original MDL that the driver used to build the scatter/gather list.

### `TargetMdl` [out]

Pointer to a variable the routine uses to return the MDL created to hold the buffer described by the scatter/gather list. The value returned can be the same as *OriginalMdl*.

## Return value

**BuildMdlFromScatterGatherList** returns one of the following status codes:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The operation succeeded. |
| **STATUS_INVALID_PARAMETER** | The *OriginalMdl* parameter is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is not enough memory available to allocate a new MDL. |
| **STATUS_NONE_MAPPED** | The system has already created a new MDL for the memory locations in the scatter/gather list. (This only happens if the routine is called twice on the same scatter/gather list.) |

## Remarks

**BuildMdlFromScatterGatherList** is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a [**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION2. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

When a driver creates a scatter/gather list to write to a device, the system can make a copy of the data to be written, and use that copy to perform the DMA operation. Use this routine to access the memory locations in the scatter/gather list, regardless of whether those locations are a copy.

## See also

[BuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list)

[**DEVICE_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[**SCATTER_GATHER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)