## Description

The **GetScatterGatherListEx** routine allocates the resources that are required for a DMA transfer, builds a scatter/gather list, and calls the driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine to initiate the DMA transfer.

> [!CAUTION]
> Do not call this routine for a system DMA device.

## Parameters

### `DmaAdapter` [in]

A pointer to a [**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's bus-master DMA device. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `DeviceObject` [in]

A pointer to a [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This structure is the physical device object (PDO) that represents the target device for the requested DMA operation.

### `DmaTransferContext` [in]

A pointer to an initialized DMA transfer context. This context was initialized by a previous call to the [InitializeDmaTransferContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context) routine. This context must be unique across all adapter allocation requests. To cancel a pending allocation request, the caller must supply the DMA transfer context for the request to the [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) routine.

### `Mdl` [in]

A pointer to an MDL chain that describes the physical page layout for a collection of locked-down buffers in virtual memory. The scatter/gather list for the DMA transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters. For more information about MDL chains, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

### `Offset` [in]

The starting offset for the scatter/gather DMA transfer. This parameter is a byte offset from the start of the buffer in the first MDL in the MDL chain. If the MDLs in the MDL chain specify a total of N bytes of buffer space, valid values of *Offset* are in the range 0 to N–1.

### `Length` [in]

The length, in bytes, of the DMA transfer. If the MDL chain specifies a total of N bytes of buffer space, valid values of *Length* are in the range 1 to N–*Offset*.

### `Flags` [in]

The adapter channel allocation flags. The following flag is supported:

| Flag | Meaning |
|---|---|
| DMA_SYNCHRONOUS_CALLBACK | The **GetScatterGatherListEx** routine is called synchronously. If this flag is set, and the required DMA resources are not immediately available, the call fails and returns STATUS_INSUFFICIENT_RESOURCES. |

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set, the *ExecutionRoutine* parameter is optional and can be NULL. If this flag is not set, *ExecutionRoutine* must be a valid, non-**NULL** pointer. For more information about this flag, see the Remarks section.

### `ExecutionRoutine` [in, optional]

A pointer to the driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine that initiates the DMA transfer for the driver. The I/O manager calls the *AdapterListControl* routine after the required resources are allocated for the adapter object. After the *AdapterListControl* routine returns, the I/O manager automatically frees the adapter object and the resources that were allocated for this object.

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set, the *ExecutionRoutine* parameter is optional and can be NULL. If this parameter is NULL, the caller can use the resources allocated by **GetScatterGatherListEx** to perform the DMA transfer after **GetScatterGatherListEx** returns. For more information, see the Remarks section.

### `Context` [in, optional]

The driver-determined, adapter-control context. This context is passed to the [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine as the *Context* parameter.

### `WriteToDevice` [in]

The direction of the DMA transfer. Set this parameter to TRUE for a write operation, which transfers data from memory to the device. Set this parameter to FALSE for a read operation, which transfers data from the device to memory.

### `DmaCompletionRoutine` [in, optional]

Not used. Set to **NULL**.

### `CompletionContext` [in, optional]

Not used. Set to **NULL**.

### `ScatterGatherList` [out, optional]

A pointer to a variable into which the routine writes a pointer to the allocated scatter/gather list. This parameter points to a [**SCATTER_GATHER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure. The routine allocates this structure and the **SCATTER_GATHER_ELEMENT** array that it points to.

The *ScatterGatherList* parameter is optional and can be NULL if the *ExecutionRoutine* parameter is non-NULL.

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set and the *ExecutionRoutine* parameter is **NULL**, *ScatterGatherList* must be a valid, non-**NULL** pointer. If *ExecutionRoutine* is non-**NULL**, *ScatterGatherList* is optional and can be **NULL** if the calling driver does not require the scatter/gather list. The **GetScatterGatherListEx** call fails if the **DMA_SYNCHRONOUS_CALLBACK** flag is set and *ScatterGatherList* and *ExecutionRoutine* are both **NULL**, or if the **DMA_SYNCHRONOUS_CALLBACK** flag is not set and *ExecutionRoutine* is **NULL**.

## Return value

**GetScatterGatherListEx** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETERS** | The routine failed due to invalid parameter values passed by the caller. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine failed to allocate resources required for the DMA transfer. |

## Remarks

**GetScatterGatherListEx** is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a [**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

Use **GetScatterGatherListEx** only for bus-master adapters. Do not use this routine for a system DMA adapter.

The driver of a bus-master device can use **GetScatterGatherListEx** to combine the operations performed by the [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex) and [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex) routines into a one call. **GetScatterGatherListEx** performs the following operations:

1. Allocates the resources that are required for the DMA transfer.

1. Builds a scatter/gather list based on the values of the *Mdl*, *Offset*, and *Length* parameters.

1. Calls the driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine and supplies the scatter/gather list to this routine as a parameter.

The allocated resources are automatically released after the *AdapterListControl* routine returns. If **GetScatterGatherListEx** is called synchronously (that is, if the **DMA_SYNCHRONOUS_CALLBACK** flag is set), the *AdapterListControl* routine can be omitted. In this case, the caller uses the allocated resources to initiate the DMA transfer after **GetScatterGatherListEx** returns. The caller must explicitly release these resources.

By default, **GetScatterGatherListEx** returns asynchronously, without waiting for the requested resource allocation to complete. After this return, the caller can, if necessary, cancel the pending allocation request by calling the [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) routine.

If the calling driver sets the **DMA_SYNCHRONOUS_CALLBACK** flag, the **GetScatterGatherListEx** routine behaves as follows:

- If the requested resources are not immediately available, **GetScatterGatherListEx** does not wait for resources, does not build a scatter/gather list, and does not call the *AdapterListControl* routine. Instead, **GetScatterGatherListEx** fails and returns STATUS_INSUFFICIENT_RESOURCES.

- The driver is not required to supply an *AdapterListControl* routine if the **DMA_SYNCHRONOUS_CALLBACK** flag is set.

- If the driver supplies an *AdapterListControl* routine, the **DMA_SYNCHRONOUS_CALLBACK** flag indicates that this routine is to be called in the context of the calling thread, before **GetScatterGatherListEx** returns.

- If the driver does not supply an *AdapterListControl* routine, the driver can use the allocated resources and scatter/gather list after **GetScatterGatherListEx** returns. In this case, the driver must supply a valid, non-NULL *ScatterGatherList* pointer. In addition, after the driver initiates the DMA transfer, the driver must call the [FreeAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object) routine to free the resources that **GetScatterGatherListEx** allocated for the adapter object.

**GetScatterGatherListEx** is an extended version of the [GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list) routine. The following features are available only in the extended version:

**GetScatterGatherListEx** is similar to the [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex) routine, except that **GetScatterGatherListEx** automatically allocates the buffer for the scatter/gather list.

## See also

[AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control)

[AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

[CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel)

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DmaCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-dma_completion_routine)

[FreeAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_channel)

[GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list)

[InitializeDmaTransferContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex)

[**SCATTER_GATHER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)