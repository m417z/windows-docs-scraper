## Description

The **DMA_OPERATIONS** structure provides a table of pointers to functions that control the operation of a DMA controller.

## Members

### `Size`

The size, in bytes, of this **DMA_OPERATIONS** structure.

### `PutDmaAdapter`

A pointer to a system-defined routine to free a [**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. For more information, see [**PutDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_dma_adapter).

### `AllocateCommonBuffer`

A pointer to a system-defined routine to allocate a physically contiguous DMA buffer. For more information, see [**AllocateCommonBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer).

### `FreeCommonBuffer`

A pointer to a system-defined routine to free a physically contiguous DMA buffer previously allocated by **AllocateCommonBuffer**. For more information, see [**FreeCommonBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_common_buffer).

### `AllocateAdapterChannel`

A pointer to a system-defined routine to allocate a channel for DMA operations. For more information, see [**AllocateAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel).

### `FlushAdapterBuffers`

A pointer to a system-defined routine to flush data from the system or bus-master adapter's internal cache after a DMA operation. For more information, see [**FlushAdapterBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers).

### `FreeAdapterChannel`

A pointer to a system-defined routine to free a channel previously allocated for DMA operations by **AllocateAdapterChannel**. For more information, see [**FreeAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_channel).

### `FreeMapRegisters`

A pointer to a system-defined routine to free map registers allocated for DMA operations. For more information, see [**FreeMapRegisters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers).

### `MapTransfer`

A pointer to a system-defined routine to begin a DMA operation. For more information, see [**MapTransfer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer).

### `GetDmaAlignment`

A pointer to a system-defined routine to obtain the DMA alignment requirements of the controller. For more information, see [**GetDmaAlignment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_alignment).

### `ReadDmaCounter`

A pointer to a system-defined routine to obtain the current transfer count for a DMA operation. For more information, see [**ReadDmaCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pread_dma_counter).

### `GetScatterGatherList`

A pointer to a system-defined routine that allocates map registers and creates a scatter/gather list for DMA. For more information, see [**GetScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list).

### `PutScatterGatherList`

A pointer to a system-defined routine that frees map registers and a scatter/gather list after a DMA operation is complete. For more information, see [**PutScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_scatter_gather_list).

### `CalculateScatterGatherList`

A pointer to a system-defined routine that determines the buffer size needed to hold the scatter/gather list that describes an I/O data buffer. This member is available only in versions 2 and later of **DMA_OPERATIONS**. For more information, see [**CalculateScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size).

### `BuildScatterGatherList`

A pointer to a system-defined routine that allocates map registers and creates a scatter/gather list for DMA in a driver-supplied buffer. This member is available only in versions 2 and later of **DMA_OPERATIONS**. For more information, see [**BuildScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list).

### `BuildMdlFromScatterGatherList`

A pointer to a system-defined routine that builds an MDL corresponding to a scatter/gather list. This member is available only in versions 2 and later of **DMA_OPERATIONS**. For more information, see [**BuildMdlFromScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_mdl_from_scatter_gather_list).

### `GetDmaAdapterInfo`

A pointer to a system-defined routine that describes the capabilities of a bus-master DMA device or a system DMA controller. **GetDmaAdapterInfo** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**GetDmaAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_adapter_info).

### `GetDmaTransferInfo`

A pointer to a system-defined routine that describes the allocation requirements for a scatter/gather list. This routine replaces [**CalculateScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size). **GetDmaTransferInfo** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**GetDmaTransferInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info).

### `InitializeDmaTransferContext`

A pointer to a system-defined routine that initializes an opaque DMA transfer context. The operating system stores the internal status of a DMA transfer in this context. **InitializeDmaTransferContext** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**InitializeDmaTransferContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context).

### `AllocateCommonBufferEx`

A pointer to a system-defined routine that allocates memory for a common buffer and maps this memory so that it can accessed both by the processor and by a DMA device. **AllocateCommonBufferEx** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**AllocateCommonBufferEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_ex).

### `AllocateAdapterChannelEx`

A pointer to a system-defined routine that allocates the resources required for a DMA transfer and then calls the driver-supplied **AdapterControl** routine to initiate the DMA transfer. **AllocateAdapterChannelEx** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**AllocateAdapterChannelEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex).

### `ConfigureAdapterChannel`

A pointer to a system-defined routine enables a custom function that is implemented by the DMA controller. **ConfigureAdapterChannel** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**ConfigureAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pconfigure_adapter_channel).

### `CancelAdapterChannel`

A pointer to a system-defined routine that tries to cancel a pending request to allocate a DMA channel. **CancelAdapterChannel** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**CancelAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel).

### `MapTransferEx`

A pointer to a system-defined routine that sets up map registers to map the physical addresses in a scatter/gather list to the logical addresses that are required to do a DMA transfer. **MapTransferEx** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**MapTransferEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex).

### `GetScatterGatherListEx`

A pointer to a system-defined routine that allocates resources required for a DMA transfer, builds a scatter/gather list, and then calls the driver-supplied [**AdapterListControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_list_control) routine to initiate the DMA transfer. **GetScatterGatherListEx** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**GetScatterGatherListEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex). This routine is a wrapper of **AllocateAdapterChannelEx** and **MapTransferEx**.

### `BuildScatterGatherListEx`

A pointer to a system-defined routine that builds a scatter/gather list in a caller-allocated buffer, and then calls the driver-supplied **AdapterListControl** routine to initiate the DMA transfer. **BuildScatterGatherListEx** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**BuildScatterGatherListEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex).

### `FlushAdapterBuffersEx`

A pointer to a system-defined routine that flushes any data that remains in the system DMA controller's internal cache or in a bus-master adapter's internal cache at the end of a DMA transfer. For a device that uses a system DMA controller, this routine cancels the current DMA transfer on the controller if the transfer is not complete. **FlushAdapterBuffersEx** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**FlushAdapterBuffersEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex).

### `FreeAdapterObject`

A pointer to a system-defined routine that releases the specified adapter object after a driver has completed all DMA operations. **FreeAdapterObject** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**FreeAdapterObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object).

### `CancelMappedTransfer`

A pointer to a system-defined routine that cancels a mapped transfer. **CancelMappedTransfer** is available only in version 3 of **DMA_OPERATIONS**. For more information, see [**CancelMappedTransfer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_mapped_transfer).

### `AllocateDomainCommonBuffer`

A pointer to a [*PALLOCATE_DOMAIN_COMMON_BUFFER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_domain_common_buffer) callback routine to allocate a domain common buffer. This option is available in Windows 10 and later versions.

### `FlushDmaBuffer`

A pointer to a [*PFLUSH_DMA_BUFFER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_dma_buffer) callback function that flushes any data remaining in the cache. This option is available in Windows 10 and later versions.

### `JoinDmaDomain`

A pointer to a [*PJOIN_DMA_DOMAIN*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pjoin_dma_domain) callback function that joins the specified DMA domain. This option is available in Windows 10 and later versions.

### `LeaveDmaDomain`

A pointer to a [*PLEAVE_DMA_DOMAIN*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pleave_dma_domain) callback function that leaves the specified DMA domain. This option is available in Windows 10 and later versions.

### `GetDmaDomain`

A pointer to the [*PGET_DMA_DOMAIN*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_domain) callback function that gets a handle to the DMA domain. This option is available in Windows 10 and later versions.

### `AllocateCommonBufferWithBounds`

A pointer to a [*PALLOCATE_COMMON_BUFFER_WITH_BOUNDS*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_with_bounds) callback function that allocates the memory for a common buffer and maps it so that it can be accessed by a master device and the CPU. The common buffer can be bound by an optional minimum and maximum logical address. This option is available starting in Windows 10, version 1803.

### `AllocateCommonBufferVector`

A pointer to a [*PALLOCATE_COMMON_BUFFER_VECTOR*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_vector) callback function that allocates multiple common buffers as a vector, allowing for efficient batch allocation of DMA-accessible memory regions.

### `GetCommonBufferFromVectorByIndex`

A pointer to a [*PGET_COMMON_BUFFER_FROM_VECTOR_BY_INDEX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_common_buffer_from_vector_by_index) callback function that retrieves the virtual and logical addresses of a specific common buffer from a previously allocated vector by its index.

### `FreeCommonBufferFromVector`

A pointer to a [*PFREE_COMMON_BUFFER_FROM_VECTOR*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_common_buffer_from_vector) callback function that frees a specific common buffer from a vector by its index, allowing for individual buffer deallocation within the vector.

### `FreeCommonBufferVector`

A pointer to a [*PFREE_COMMON_BUFFER_VECTOR*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_common_buffer_vector) callback function that frees an entire common buffer vector and all its associated buffers that were previously allocated by **AllocateCommonBufferVector**.

### `CreateCommonBufferFromMdl`

A pointer to a [*PCREATE_COMMON_BUFFER_FROM_MDL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcreate-common-buffer-from-mdl) callback function that will create a DMA common buffer from an MDL and maps the backing memory so that it can be accessed by a bus-mastering device and the CPU. This optional callback is available starting in Windows Server 2022.

## Remarks

All members of this structure, with the exception of **Size**, are pointers to functions that drivers use to perform DMA operations for their devices. Drivers obtain these pointers by calling the [**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine. The version of the **DMA_OPERATIONS** structure that this routine returns depends on the **Version** member of the [**DEVICE_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description) structure that is passed to **IoGetDmaAdapter** as an input parameter. If **Version** is DEVICE_DESCRIPTION_VERSION or DEVICE_DESCRIPTION_VERSION1, version 1 of this structure is returned. If **Version** is DEVICE_DESCRIPTION_VERSION2, version 2 of this structure is returned. Version 2 of **DMA_OPERATIONS** is available starting with Windows XP. If **Version** is DEVICE_DESCRIPTION_VERSION3, version 3 of this structure is returned. Version 3 of **DMA_OPERATIONS** is available starting with Windows 8.

## See also

[**AllocateAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[**AllocateAdapterChannelEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[**AllocateCommonBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[**AllocateCommonBufferEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer_ex)

[**BuildMdlFromScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_mdl_from_scatter_gather_list)

[**BuildScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list)

[**BuildScatterGatherListEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

[**CalculateScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size)

[**CancelAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_adapter_channel)

[**CancelMappedTransfer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_mapped_transfer)

[**ConfigureAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pconfigure_adapter_channel)

[**DEVICE_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_description)

[**FlushAdapterBuffers**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[**FlushAdapterBuffersEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex)

[**FreeAdapterChannel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_channel)

[**FreeAdapterObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_object)

[**FreeCommonBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_common_buffer)

[**FreeMapRegisters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers)

[**GetDmaAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_adapter_info)

[**GetDmaAlignment**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_alignment)

[**GetDmaTransferInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info)

[**GetScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list)

[**GetScatterGatherListEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list_ex)

[**InitializeDmaTransferContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pinitialize_dma_transfer_context)

[**IoGetDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[**MapTransfer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer)

[**MapTransferEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex)

[**PutDmaAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_dma_adapter)

[**PutScatterGatherList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pput_scatter_gather_list)

[**ReadDmaCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pread_dma_counter)