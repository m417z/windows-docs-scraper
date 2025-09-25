# PFREE_MAP_REGISTERS callback function

## Description

The **FreeMapRegisters** routine releases a set of map registers that were saved from a call to [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel).

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `MapRegisterBase` [in]

Specifies the map registers allocated for the DMA operation. The system passes this value to the driver's [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) routine.

### `NumberOfMapRegisters` [in]

Specifies the number of map registers to be released. This value must match the number specified in an earlier call to [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel).

## Remarks

**FreeMapRegisters**
is not a system routine that can be called directly by name. This routine is only callable by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

When the driver of a bus-master device has completed the current packet-based DMA transfer request, it calls **FreeMapRegisters** to release the map registers previously allocated by a call to [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel) and retained because its *AdapterControl* routine returned **DeallocateObjectKeepRegisters**. The driver must call **FreeMapRegisters** after calling [FlushAdapterBuffers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pflush_adapter_buffers).

## See also

[AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransfer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer)