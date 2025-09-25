# PBUILD_SCATTER_GATHER_LIST_EX callback function

## Description

The **BuildScatterGatherListEx** routine allocates the resources that are required for a DMA transfer, builds a scatter/gather list, and calls the driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine to initiate the DMA transfer.

> [!CAUTION]
> Do not call this routine for a system DMA device.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `DeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This structure is the physical device object (PDO) that represents the target device for the requested DMA operation.

### `DmaTransferContext` [in]

A pointer to an initialized DMA transfer context. This context was initialized by a previous call to the [InitializeDmaTransferContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context) routine. This context must be unique across all adapter allocation requests. To cancel a pending allocation request, the caller must supply the DMA transfer context for the request to the [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) routine.

### `Mdl` [in]

A pointer to an MDL chain that describes the physical page layout for a collection of locked-down buffers in virtual memory. The scatter/gather list for the DMA transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters. For more information about MDL chains, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

### `Offset` [in]

The starting offset for the scatter/gather DMA transfer. This parameter is a byte offset from the start of the buffer in the first MDL in the MDL chain. If the MDLs in the MDL chain specify a total of N bytes of buffer space, valid values of *Offset* are in the range 0 to N–1.

### `Length` [in]

The size, in bytes, of the DMA transfer. If the MDL chain specifies a total of N bytes of buffer space, valid values of *Length* are in the range 1 to N–*Offset*.

### `Flags` [in]

The adapter channel allocation flags. The following flag is supported:

| Flag | Meaning |
|---|---|
| DMA_SYNCHRONOUS_CALLBACK | The **BuildScatterGatherListEx** routine is called synchronously. If this flag is set, and the required DMA resources are not immediately available, the call fails and returns STATUS_INSUFFICIENT_RESOURCES. |

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set, the *ExecutionRoutine* parameter is optional and can be **NULL**. If this flag is not set, *ExecutionRoutine* must be a valid, non-**NULL** pointer. For more information about this flag, see the Remarks section.

### `ExecutionRoutine` [in, optional]

A pointer to the driver-supplied [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine that initiates the DMA transfer for the driver. The I/O manager calls the *AdapterListControl* routine after the required resources are allocated for the adapter object. After the *AdapterListControl* routine returns, the I/O manager automatically frees the adapter object and the resources that were allocated for this object.

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set, *ExecutionRoutine* is optional and can be **NULL**. If *ExecutionRoutine* is **NULL**, the caller can use the resources allocated by **BuildScatterGatherListEx**. For more information, see the Remarks section.

### `Context` [in, optional]

The driver-determined, adapter-control context. This context is passed to the [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine as the *Context* parameter.

### `WriteToDevice` [in]

The direction of the DMA transfer. Set this parameter to **TRUE** for a write operation, which transfers data from memory to the device. Set this parameter to **FALSE** for a read operation, which transfers data from the device to memory.

### `ScatterGatherBuffer` [in]

A pointer to a caller-allocated buffer into which the routine writes the scatter/gather list for the DMA transfer. This list begins with a [SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure, which is followed by a **SCATTER_GATHER_ELEMENT** array.

### `ScatterGatherLength` [in]

The size, in bytes, of the buffer passed in the *ScatterGatherBuffer* parameter. The allocated buffer size must be large enough to contain the scatter/gather list, plus internal data that the operating system stores in this buffer. To calculate the required buffer size, call the [GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info) or [CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size) routine.

### `DmaCompletionRoutine` [in, optional]

Not used. Set to **NULL**.

### `CompletionContext` [in, optional]

Not used. Set to **NULL**.

### `ScatterGatherList` [out, optional]

A pointer to a variable into which the routine writes a pointer to the scatter/gather list for the DMA transfer. This list begins with a [SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure, which contains a pointer to a **SCATTER_GATHER_ELEMENT** array. This output pointer always matches the *ScatterGatherBuffer* parameter value.

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set and the *ExecutionRoutine* parameter is **NULL**, *ScatterGatherList* must be a valid, non-**NULL** pointer. If *ExecutionRoutine* is non-**NULL**, *ScatterGatherList* is optional and can be **NULL** if the calling driver does not require the scatter/gather list. The **BuildScatterGatherListEx** call fails if the **DMA_SYNCHRONOUS_CALLBACK** flag is set and *ScatterGatherList* and *ExecutionRoutine* are both **NULL**, or if the **DMA_SYNCHRONOUS_CALLBACK** flag is not set and *ExecutionRoutine* is **NULL**.

## Return value

**BuildScatterGatherListEx** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
|-----------------------------------|------------------------------------------------------------------------------------------------------|
| **STATUS_INVALID_PARAMETERS** | The routine failed due to invalid parameter values passed by the caller. |
| **STATUS_BUFFER_TOO_SMALL** | The caller-supplied buffer in *ScatterGatherBuffer* is too small to contain the scatter/gather list. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine failed to allocate resources required for the DMA transfer. |

## Remarks

**BuildScatterGatherListEx*** is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a*[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

Use **BuildScatterGatherListEx** only for bus-master adapters. Do not use this routine for a system DMA adapter.

**BuildScatterGatherListEx** is similar to the [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex) routine, except that it requires the caller to allocate the buffer for the scatter/gather list.

For example, a driver might preallocate one or more scatter/gather buffers during device initialization. Later, a **BuildScatterGatherListEx** call that uses such a buffer can succeed in conditions of low memory availability that might cause a **GetScatterGatherListEx** call to fail.

By default, **BuildScatterGatherListEx** returns asynchronously, without waiting for the requested resource allocation to complete. After this return, the caller can, if necessary, cancel the pending allocation request by calling the [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) routine.

If the calling driver sets the **DMA_SYNCHRONOUS_CALLBACK** flag, the **BuildScatterGatherListEx** routine behaves as follows:

- If the requested resources are not immediately available, **BuildScatterGatherListEx** does not wait for resources, does not build a scatter/gather list, and does not call the *AdapterListControl* routine. Instead, **BuildScatterGatherListEx** fails and returns STATUS_INSUFFICIENT_RESOURCES.

- The driver is not required to supply an *AdapterListControl* routine if the **DMA_SYNCHRONOUS_CALLBACK** flag is set.

- If the driver supplies an *AdapterListControl* routine, the **DMA_SYNCHRONOUS_CALLBACK** flag indicates that this routine is to be called in the context of the calling thread, before **BuildScatterGatherListEx** returns.

- If the driver does not supply an *AdapterListControl* routine, the driver can use the allocated resources and scatter/gather list after **BuildScatterGatherListEx** returns. In this case, the driver must supply a valid, non-**NULL** *ScatterGatherList* pointer. In addition, after the driver-initiated DMA transfer completes, the driver must call the [FreeAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object) routine to free the resources that **BuildScatterGatherListEx** allocated for the adapter object.

**BuildScatterGatherListEx** is an extended version of the [BuildScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list) routine. The following list summarizes the features that are available only in the extended version:

| Feature | Description |
|---|---|
| Starting offset | The calling driver can specify a starting offset for a scatter/gather DMA transfer instead of starting the transfer at the first buffer address at the start of the MDL chain. |
| Allocation request cancellation | The driver can call [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) to cancel a pending allocation request when the DMA adapter is queued to wait for DMA resources. |
| Synchronous callback | The driver can set the **DMA_SYNCHRONOUS_CALLBACK** flag to request that the driver-supplied *AdapterListControl* routine be called in the calling thread, before **BuildScatterGatherListEx** returns. |

## See also

[AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control)

[AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[DmaCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-dma_completion_routine)

[FreeAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object)

[GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list)

[GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex)

[MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex)