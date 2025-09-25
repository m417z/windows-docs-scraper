# PMAP_TRANSFER callback function

## Description

The **MapTransfer** routine sets up map registers for an adapter object to map a DMA transfer from a locked-down buffer.

## Parameters

### `DmaAdapter` [in]

Pointer to the DMA adapter object returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) and previously passed to [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel) for the current IRP's transfer request.

### `Mdl` [in]

Pointer to one of the following: the MDL that describes the buffer at **MdlAddress** in the current IRP or the MDL that describes the common buffer set up by the driver of a subordinate device (auto-initialize mode).

### `MapRegisterBase` [in]

Specifies the map registers allocated for the DMA operation. The system passes this value to the driver's [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine.

### `CurrentVa` [in]

Pointer to the current virtual address of the data to be transferred for a DMA transfer operation.

### `Length` [in, out]

Specifies the length, in bytes, to be mapped. If the driver indicated that its device was a bus master with scatter/gather support when it called [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter), the value of *Length* on return from **MapTransfer** indicates how many bytes were mapped. Otherwise, the input and output values of *Length* are identical.

### `WriteToDevice` [in]

Indicates the direction of the transfer operation: **TRUE** for a transfer from the locked-down buffer to the device.

## Return value

**MapTransfer** returns the logical address of the region mapped, which the driver of a bus-master adapter can use. Drivers of devices that use a system DMA controller cannot use this value and should ignore it.

## Remarks

**MapTransfer** is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

The *DmaAdapter* must have already been allocated as a result of the driver's preceding call to [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel).

The number of map registers that can be set up cannot exceed the maximum returned when the driver called [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

A driver can get the initial *CurrentVa* for the start of a packet-based DMA transfer by calling [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress). However, the value returned is an index into the *Mdl*, rather than a valid virtual address. If the driver must split a large transfer request into more than one DMA operation, it must update *CurrentVa* and *Length* for each DMA operation.

The driver of a bus-master device with scatter/gather support can use the returned logical address and updated *Length* value to build a scatter/gather list, calling **MapTransfer** repeatedly until it has used all available map registers for the transfer operation. However, such a driver could more simply use the [GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list) routine.

## See also

[ADDRESS_AND_SIZE_TO_SPAN_PAGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-address_and_size_to_span_pages)

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers)

[FreeAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_adapter_channel)

[FreeMapRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pfree_map_registers)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[KeFlushIoBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushiobuffers)

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)