# PGET_SCATTER_GATHER_LIST callback function

## Description

The **GetScatterGatherList** routine prepares the system for a DMA scatter/gather operation on behalf of the target device object, through either the system DMA controller or a bus-master adapter.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `DeviceObject` [in]

Pointer to the device object that represents the target device for the DMA operation.

### `Mdl` [in]

Pointer to the MDL that describes the buffer at *MdlAddress* in the current IRP.

### `CurrentVa` [in]

Pointer to the current virtual address in the MDL for the buffer to be mapped for a DMA transfer operation.

### `Length` [in]

Specifies the length, in bytes, to be mapped.

### `ExecutionRoutine` [in]

Pointer to a driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine, which is called at DISPATCH_LEVEL when the system DMA controller or bus-master adapter is available.

### `Context` [in]

Pointer to the driver-determined context passed to the driver's *AdapterListControl* routine when it is called.

### `WriteToDevice` [in]

Indicates the direction of the DMA transfer: **TRUE** for a transfer from the buffer to the device, and **FALSE** otherwise.

## Return value

This routine can return one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation succeeded. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine could not allocate sufficient memory or the number of map registers required for the transfer is larger than the value returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter). |
| **STATUS_BUFFER_TOO_SMALL** | The buffer is too small for the requested transfer. |

## Remarks

The **GetScatterGatherList** routine dynamically allocates a buffer to hold the scatter/gather list. For possible NTSTATUS values if the buffer allocation fails, see the return value.

**GetScatterGatherList**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

As soon as the appropriate DMA channel and any necessary map registers are available, **GetScatterGatherList** creates a scatter/gather list, initializes the map registers, and then calls the driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine to carry out the I/O operation.

**GetScatterGatherList** combines the actions of the [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel) and [MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer) routines for drivers that perform scatter/gather DMA. **GetScatterGatherList** determines how many map registers are required for the transfer, allocates the map registers, maps the buffers for DMA, and fills in the scatter/gather list. It then calls the supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine, passing a pointer to the scatter/gather list in *ScatterGather*. The driver should retain this pointer for use when calling [PutScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_scatter_gather_list). Note that **GetScatterGatherList** does not have the queuing restrictions that apply to **AllocateAdapterChannel**.

In its *AdapterListControl* routine, the driver should perform the I/O. On return from the driver-supplied routine, **GetScatterGatherList** keeps the map registers but frees the DMA adapter structure. The driver must call **PutScatterGatherList** (which flushes the buffers) before it can access the data in the buffer.

This routine can handle chained MDLs, provided that the total number of map registers required by all chained MDLs does not exceed the number of map registers that are available.

## See also

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[PutScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_scatter_gather_list)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)