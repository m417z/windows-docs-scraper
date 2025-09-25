# PCANCEL_ADAPTER_CHANNEL callback function

## Description

The **CancelAdapterChannel** routine tries to cancel a pending request to allocate a DMA channel.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that is waiting for the pending resource allocation request to be granted. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine, and the caller passed this pointer to the [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex), [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), or [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex) call that requested the resource allocation.

### `DeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This structure is the physical device object (PDO) that represents the target device for the DMA operation for which the DMA channel was requested.

### `DmaTransferContext` [in]

A pointer to a DMA transfer context. This parameter value must be the same DMA transfer context that was passed to the **AllocateAdapterChannelEx**, **GetScatterGatherListEx**, or **BuildScatterGatherListEx** call that requested the adapter channel allocation.

## Return value

**CancelAdapterChannel** returns **TRUE** if the pending allocation request is successfully canceled. The routine returns **FALSE** if the request could not be canceled (for example, because the DMA channel was allocated before the request could be canceled).

## Remarks

**CancelAdapterChannel** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

**CancelAdapterChannel** tries to cancel a pending allocation request that was made by an asynchronous call to an allocation routine such as [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex), [GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex), or [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex). When called asynchronously, the allocation routine can return while the allocation request is still pending and before the driver-supplied execution routine ([AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) or [AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control)) is called. If **CancelAdapterChannel** successfully cancels the pending allocation request, the resources are not allocated and the execution routine is not called.

If a driver calls **AllocateAdapterChannelEx** to request resources for a driver-supplied *AdapterControl* routine, and then calls **CancelAdapterChannel** to cancel the request, **CancelAdapterChannel** can return one of the following values:

* **TRUE**, if the adapter object is waiting for the requested allocation when the **CancelAdapterChannel** call occurs. In this case, **CancelAdapterChannel** cancels the pending allocation request, and the driver's *AdapterControl* routine is not called.
* **FALSE**, if the *AdapterControl* routine was already called or is about to be called.

Similarly, if a driver calls **GetScatterGatherListEx** or **BuildScatterGatherListEx** to request resources for a driver-supplied *AdapterListControl* routine, and then calls **CancelAdapterChannel** to cancel the request, **CancelAdapterChannel** can return one of the following values:

* **TRUE**, if the adapter object is waiting for the requested allocation when the **CancelAdapterChannel** call occurs. In this case, **CancelAdapterChannel** cancels the pending allocation request, and the driver's *AdapterListControl* routine is not called.
* **FALSE**, if the *AdapterListControl* routine was already called or is about to be called.

**CancelAdapterChannel** can preemptively cancel future channel allocation requests that use the specified DMA transfer context. For example, if the caller supplies the same DMA transfer context to **CancelAdapterChannel** and **AllocateAdapterChannelEx**, and the **CancelAdapterChannel** call is successful and occurs before the **AllocateAdapterChannelEx** call, the allocation requested by the **AllocateAdapterChannelEx** call is automatically canceled.

## See also

[AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control)

[AdapterListControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control)

[AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

[CancelAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[GetScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)