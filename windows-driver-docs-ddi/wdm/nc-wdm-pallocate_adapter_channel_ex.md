# PALLOCATE_ADAPTER_CHANNEL_EX callback function

## Description

The **AllocateAdapterChannelEx** routine allocates the resources that are needed to perform a DMA transfer, and then calls the driver-supplied [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine to initiate the DMA transfer.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `DeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This structure is the physical device object (PDO) that represents the target device for the requested DMA operation.

### `DmaTransferContext` [in]

A pointer to an initialized DMA transfer context. This context was initialized by a previous call to the [InitializeDmaTransferContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context) routine. This context must be unique across all adapter allocation requests. To cancel a pending allocation request, the caller must supply the DMA transfer context for the request to the [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) routine.

### `NumberOfMapRegisters` [in]

The number of map registers to use in the DMA transfer. The calling driver should set this value to the lesser of the number of map registers needed to satisfy the current transfer request, and the number of available map registers. The driver previously called the [GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info) routine to obtain the number of map registers needed for the transfer, and called the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine to obtain the number of available map registers.

### `Flags` [in]

 The adapter channel allocation flags. The following flag is supported.

| Flag | Meaning |
| --- | --- |
| **DMA_SYNCHRONOUS_CALLBACK** | The **AllocateAdapterChannelEx** routine is called synchronously. If this flag is set, and the required DMA resources are not immediately available, the call fails and returns STATUS_INSUFFICIENT_RESOURCES. |

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set, the *ExecutionRoutine* parameter is optional and can be NULL. For more information about this flag, see the Remarks section.

### `ExecutionRoutine` [in, optional]

A pointer to the driver-supplied [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine that initiates the DMA transfer for the driver. The I/O manager calls the *AdapterControl* routine after the required resources are allocated for the adapter object. After the *AdapterControl* routine returns, the I/O manager automatically frees the adapter object. The I/O manager might additionally free the resources that were allocated for this object, depending on the value returned by this routine.

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set, the *ExecutionRoutine* is optional and can be **NULL**. In this case, the caller can use the resources allocated by **AllocateAdapterChannelEx**, and later free these resources by calling the [FreeAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object) routine. For more information, see the Remarks section.

### `ExecutionContext` [in, optional]

The driver-determined, adapter-control context. This context is passed to the [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine as the *Context* parameter.

### `MapRegisterBase` [out, optional]

A pointer to a variable into which the routine writes a handle to the allocated map registers. The caller can supply this handle as a parameter to the [FlushAdapterBuffersEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex), [FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers), [FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers), or [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex) routine.

If the **DMA_SYNCHRONOUS_CALLBACK** flag is set, *MapRegisterBase* must be a valid, non-**NULL** pointer. If the *ExecutionRoutine* parameter is non-**NULL**, *MapRegisterBase* must be **NULL**. The call fails if *MapRegisterBase* is non-**NULL** and the **DMA_SYNCHRONOUS_CALLBACK** flag is not set, or if *MapRegisterBase* and *ExecutionRoutine* are both **NULL**.

## Return value

**AllocateAdapterChannelEx** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETERS** | The routine failed due to invalid parameter values passed by the caller. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine failed to allocate resources required for the DMA transfer. |

## Remarks

**AllocateAdapterChannelEx** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

**AllocateAdapterChannelEx** allocates the resources that are required to perform a DMA operation. These resources include DMA channels and map registers. After all required resources are allocated for use by the DMA adapter, **AllocateAdapterChannelEx** calls the caller-supplied [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine to initiate the DMA operation.

By default, **AllocateAdapterChannelEx** returns asynchronously, without waiting for the requested resource allocation to complete. After this return, the caller can, if necessary, cancel the pending allocation request by calling the [CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel) routine.

If the calling driver sets the **DMA_SYNCHRONOUS_CALLBACK** flag, the **AllocateAdapterChannelEx** routine behaves as follows:

* If the requested DMA resources are not immediately available, **AllocateAdapterChannelEx** does not wait for resources and does not call the [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine. Instead, **AllocateAdapterChannelEx** fails and returns STATUS_INSUFFICIENT_RESOURCES.
* The driver is not required to supply an [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine if the **DMA_SYNCHRONOUS_CALLBACK** flag is set.
* If the driver supplies an [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine, the **DMA_SYNCHRONOUS_CALLBACK** flag indicates that this routine is to be called in the context of the calling thread, before **AllocateAdapterChannelEx** returns.
* If the driver does not supply an [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine, the driver can use the allocated resources after **AllocateAdapterChannelEx** returns. In this case, the driver must call [FreeAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object) after it finishes using the allocated resources.

**AllocateAdapterChannelEx** is an extended version of the [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel) routine. The following features are available only in the extended version:

## See also

[AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control)

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[FlushAdapterBuffersEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex)

[FreeAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object)

[FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers)

[GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info)

[InitializeDmaTransferContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex)