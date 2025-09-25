# PMAP_TRANSFER_EX callback function

## Description

The **MapTransferEx** routine sets up map registers to map the physical addresses in a scatter/gather list to the logical addresses that are required to do a DMA transfer.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `Mdl` [in]

A pointer to an MDL chain that describes the physical page layout for a collection of locked-down buffers in virtual memory. The scatter/gather list for the DMA transfer will use the region of this memory that is specified by the *Offset* and *Length* parameters. For more information about MDL chains, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

### `MapRegisterBase` [in]

A handle to the map registers that are allocated for the adapter object. The caller previously obtained this handle from the [AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex) routine.

### `Offset` [in]

A byte offset from the start of the memory that is described by the MDL chain. This offset specifies the start of the I/O data buffer that is used for the DMA transfer. If a scatter/gather list is supplied to the caller, this offset determines the starting address of the first buffer fragment in the list. If the MDLs in the MDL chain describe a total of N bytes of memory, valid values of *Offset* are in the range 0 to N–1. For more information, see Remarks.

### `DeviceOffset` [in]

The byte offset of the target device's data register or FIFO from the device's base address. This parameter applies to devices that have multiple FIFOs that can be accessed by a system DMA controller. This parameter is used only for system DMA transfers. For bus-master transfers, set this parameter to zero.

### `Length` [in, out]

A pointer to a variable that contains the length, in bytes, of the I/O data buffer that is used for the DMA transfer. On entry, this variable contains the length requested by the calling driver. Before returning, the routine writes the actual length of the mapped buffer to this variable. The value of **Length* on return from **MapTransferEx** indicates how many bytes were mapped. If the number of map registers and the scatter/gather buffer size are sufficient to map the entire length requested by the caller, the input and output values of **Length* are identical. If the MDLs in the MDL chain describe a total of N bytes of memory, valid values of **Length* are in the range 0 to N–*Offset*.

### `WriteToDevice` [in]

The direction of the DMA transfer. Set this parameter to **TRUE** for a write operation, which transfers data to the device from memory. Set this parameter to **FALSE** for a read operation, which transfers data from the device to memory.

### `ScatterGatherBuffer` [out, optional]

A pointer to a caller-allocated buffer into which the routine writes the scatter/gather list for the DMA transfer. This list begins with a [SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure, which is immediately followed by a **SCATTER_GATHER_ELEMENT** array. For a driver that uses a bus-master DMA device, *ScatterGatherBuffer* is a required parameter. For a driver that uses a system DMA controller, the *ScatterGatherBuffer* parameter is optional and can be **NULL**. For more information, see Remarks.

### `ScatterGatherBufferLength` [in]

The size, in bytes, of the buffer that the *ScatterGatherBuffer* parameter points to. The allocated buffer size must be large enough to contain the scatter/gather list, plus internal data that the operating system stores in this buffer. To determine the required buffer size, call the [GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info) or [CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size) routine. If *ScatterGatherBuffer* is **NULL**, set *ScatterGatherBufferLength* to zero.

### `DmaCompletionRoutine` [in, optional]

A pointer to a caller-supplied [DmaCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-dma_completion_routine) routine to be called when the DMA transfer completes. This routine is called if the target device uses a system DMA controller that generates a DMA-completion interrupt. The *DmaCompletionRoutine* routine is called at DISPATCH_LEVEL after the DMA transfer completes. For a system DMA adapter, this parameter is optional and can be **NULL**. For a bus-master adapter, set this parameter to **NULL**.

### `CompletionContext` [in, optional]

The driver-determined context for the *DmaCompletionRoutine* routine. This context is supplied as the *CompletionContext* parameter to the *DmaCompletionRoutine* routine. If the *DmaCompletionRoutine* parameter is **NULL**, set *CompletionContext* to **NULL**.

## Return value

**MapTransferEx** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETERS** | The routine failed due to invalid parameter values passed by the caller. |
| **STATUS_BUFFER_TOO_SMALL** | The caller-supplied buffer in *ScatterGatherBuffer* is too small to contain the scatter/gather list. |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine failed to allocate resources required for the DMA transfer. |
| **STATUS_CANCELLED** | This transfer was canceled. |

## Remarks

**MapTransferEx** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

For a transfer that uses a system DMA controller, the caller can, as an option, supply a [DmaCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-dma_completion_routine) callback routine that is called when the transfer finishes. The operating system schedules this callback in response to the DMA completion interrupt from the system DMA controller.

The number of map registers that can be set up by **MapTransferEx** cannot exceed the maximum that the driver obtained from [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

The *Mdl*, *Offset*, and *Length* parameters describe the I/O data buffer for the requested DMA transfer. The number of allocated map registers might not be sufficient to map all of the memory in this buffer, or the scatter/gather buffer pointed to by *ScatterGatherBuffer* might not be large enough to describe the entire buffer. **MapTransferEx** writes an output value to **Length* to tell the driver how much of the buffer memory for the requested DMA transfer was mapped by the routine. The routine writes a scatter/gather list to the buffer pointed to by *ScatterGatherBuffer*. This list describes the buffer fragments that were successfully mapped by the routine.

If a call to **MapTransferEx** is successful, **MapTransferEx** writes the **Length* output value before it returns. If the caller specifies a *DmaCompletionRoutine*, the updated **Length* output value is always written before the *DmaCompletionRoutine* runs. For more information, see [Multiple calls to MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-maptransferex-routine).

The *Offset* parameter specifies the starting offset in the MDL chain that describes the memory in the I/O data buffer. For example, assume that the MDL chain contains two MDLs, MDL₁ and MDL₂, and that MDL₁ describes N₁ bytes of memory, and MDL₂ describes N₂ bytes. If *Offset* = N, where N₁ < N < N₁ + N₂, the buffer contains none of the memory described by MDL₁, and starts at an offset of N - N₁ bytes in the memory described by MDL₂.

If the transfer uses a system DMA controller, the caller can set *ScatterGatherBuffer* = NULL, in which case **MapTransferEx** uses an internally allocated, default buffer to hold the scatter/gather list. The default buffer is guaranteed to be large enough to contain a scatter/gather list of at least one element. If the default buffer is used for a scatter/gather transfer of many elements, many calls to **MapTransferEx** might be required complete the transfer. If the DMA controller hardware supports scatter/gather transfers, the use of the default buffer might degrade performance.

If *ScatterGatherBuffer* is non-NULL and *ScatterGatherBufferSize* specifies a size that is too small to contain a scatter/gather list of at least one element, **MapTransferEx** fails and returns STATUS_INVALID_PARAMETER.

**MapTransferEx** is an extended version of the [MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer) routine. The extended version has these advantages:

* **MapTransferEx** can process all of the buffer fragments in an MDL chain in one call, but **MapTransfer** can process only one physically contiguous buffer fragment per call.
* **MapTransferEx** can generate an entire scatter/gather list in one call, but **MapTransfer** can generate only one scatter/gather list element per call.
* **MapTransferEx** can map all of the buffer fragments in a scatter/gather list in one call, but **MapTransfer** can map only one physically contiguous buffer fragment per call.
* **MapTransferEx** requires only the starting offset for the entire scatter/gather list, but **MapTransfer** requires a starting virtual address for each physically contiguous buffer fragment.
* A **MapTransferEx** call can map a buffer that extends through one or more MDLs, but a **MapTransfer** call can map only one physically contiguous buffer fragment in the memory that is described by an MDL.
* For a system DMA transfer, **MapTransferEx** enables the caller to supply a *DmaCompletionRoutine* callback routine to receive notification after the transfer completes, but **MapTransfer** does not provide a way to notify the caller when a DMA transfer completes.

Each successful call to **MapTransferEx** must be followed by a corresponding call to the [FlushAdapterBuffersEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex) routine. The **FlushAdapterBuffersEx** call that follows a **MapTransferEx** call must occur before the next **MapTransferEx** call occurs. The **FlushAdapterBuffersEx** call is required even if a call to the [CancelMappedTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_mapped_transfer) routine succeeds in canceling the mapped transfer requested by the preceding **MapTransferEx** call.

For more information, see [Using the MapTransferEx Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-maptransferex-routine).

## See also

[AllocateAdapterChannelEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel_ex)

[CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size)

[CancelMappedTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcancel_mapped_transfer)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[DmaCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-dma_completion_routine)

[FlushAdapterBuffersEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers_ex)

[GetDmaTransferInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_transfer_info)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list)