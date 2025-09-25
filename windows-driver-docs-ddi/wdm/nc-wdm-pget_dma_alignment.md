# PGET_DMA_ALIGNMENT callback function

## Description

The **GetDmaAlignment** routine returns the alignment requirements of the DMA system.

## Parameters

### `DmaAdapter` [in]

A pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

## Return value

**GetDmaAlignment** returns the alignment requirements, in bytes, of the DMA system. The starting address and length of DMA buffers must be a multiple of this value.

## Remarks

**GetDmaAlignment**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

A driver can call this routine to determine alignment requirements for DMA buffers it allocates. The returned value should be used to set the **AlignmentRequirement** field in the device object. A driver may need to increase this value because of additional hardware device restrictions. For more information, see [Initializing a Device Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/initializing-a-device-object).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)