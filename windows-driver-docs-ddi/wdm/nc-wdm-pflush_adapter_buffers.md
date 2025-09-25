# PFLUSH_ADAPTER_BUFFERS callback function

## Description

The **FlushAdapterBuffers** routine flushes any data remaining in the system DMA controller's internal cache or in a bus-master adapter's internal cache at the end of a DMA transfer operation.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `Mdl` [in]

Pointer to the MDL that describes the buffer previously passed in the driver's call to **MapTransfer**.

### `MapRegisterBase` [in]

Specifies the map registers allocated for the DMA operation. The system passes this value to the driver's [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine.

### `CurrentVa` [in]

Pointer to the current virtual address in the buffer, described by the *Mdl*, where the I/O operation occurred. This value must be the same as the initial *CurrentVa* value passed to [MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer).

### `Length` [in]

Specifies the length, in bytes, of the buffer.

### `WriteToDevice` [in]

Specifies the direction of the DMA transfer operation: **TRUE** for a transfer from a buffer in system memory to the driver's device.

## Return value

**FlushAdapterBuffers** returns **TRUE** if any data remaining in the DMA controller's or bus-master adapter's internal cache has been successfully flushed into system memory or out to the device.

## Remarks

**FlushAdapterBuffers**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

To ensure that a DMA transfer is complete, every driver that performs DMA operations must call **FlushAdapterBuffers** before completing the IRP that requested the DMA transfer and before freeing the map registers.

A driver can get the initial *CurrentVa* for the start of a packet-based DMA transfer by calling [MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress). However, the value returned is an index into the *Mdl*, rather than a valid virtual address. If the driver must split a large transfer request into more than one DMA operation, it must update *CurrentVa* and *Length* for each DMA operation.

## See also

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[KeFlushIoBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keflushiobuffers)

[MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer)

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)