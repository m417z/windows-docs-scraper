## Description

The **BuildScatterGatherList** routine prepares the system for a DMA operation, using a driver-supplied buffer to build the scatter/gather list.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `DeviceObject` [in]

Pointer to the device object that represents the target device for the DMA operation.

### `Mdl` [in]

Pointer to the MDL that describes the buffer specified by the **MdlAddress** member of the current IRP.

### `CurrentVa` [in]

Pointer to the current virtual address in the MDL for the buffer to be mapped for a DMA transfer operation.

### `Length` [in]

Specifies the length, in bytes, of the buffer to be mapped.

### `ExecutionRoutine` [in]

Pointer to a driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine, which is called at IRQL = DISPATCH_LEVEL when the system DMA controller or bus-master adapter is available.

### `Context` [in]

Pointer to the driver-determined context passed to *ExecutionRoutine* when it is called.

### `WriteToDevice` [in]

Indicates the direction of the DMA transfer: **TRUE** for a transfer from the buffer to the device, and **FALSE** otherwise.

### `ScatterGatherBuffer` [in]

Pointer to the caller-supplied buffer that the routine fills with a [SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure.

### `ScatterGatherLength` [in]

Specifies the size, in bytes, of the buffer passed in the *ScatterGatherBuffer* parameter.

## Return value

**BuildScatterGatherList** returns one of the following values:

| Return code | Description |
|---|---|
| **STATUS_SUCCESS** | The operation is completed successfully. |
| **STATUS_INSUFFICIENT_RESOURCES** | The system has insufficient map registers available for the transfer. |
| **STATUS_BUFFER_TOO_SMALL** | The specified *Length* is too big to fit within the buffer. |

## Remarks

**BuildScatterGatherList** is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION2. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

**BuildScatterGatherList** performs the same operation as [GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list), except that it uses the buffer supplied in the *ScatterGatherBuffer* parameter to hold the scatter/gather list that it creates. In contrast, **GetScatterGatherList** dynamically allocates a buffer to hold the scatter/gather list. If insufficient memory is available to allocate the buffer, **GetScatterGatherList** can fail with a STATUS_INSUFFICIENT_RESOURCES error. Drivers that must avoid this scenario can preallocate a buffer to hold the scatter/gather list, and use **BuildScatterGatherList** instead.

A driver can use the [CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size) routine to determine the size of buffer to allocate to hold the scatter/gather list.

The driver should retain the pointer to the scatter/gather list in *ScatterGatherBuffer* for use when the driver calls [PutScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_scatter_gather_list). The driver must call **PutScatterGatherList** (which flushes the list) before it can access the data in the list.

## See also

[BuildMdlFromScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_mdl_from_scatter_gather_list)

[CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size)

[**DEVICE_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[PutScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_scatter_gather_list)

[**SCATTER_GATHER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)