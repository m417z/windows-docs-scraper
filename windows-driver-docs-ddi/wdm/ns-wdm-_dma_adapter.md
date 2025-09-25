## Description

The **DMA_ADAPTER** structure describes a system-defined interface to a DMA controller for a given device. A driver calls [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) to obtain this structure.

## Members

### `Version`

Specifies the version of this structure. Version 3 of the **DMA_ADAPTER** structure is available starting with Windows 8. For versions 1 and 2 of this structure, this member is set to the value 1. For more information, see the following Remarks section.

### `Size`

Specifies the size, in bytes, of this structure.

### `DmaOperations`

Pointer to a [**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) structure that contains pointers to DMA adapter functions. The version of the **DMA_OPERATIONS** structure that this member points to is determined by the version of the **DMA_ADAPTER** structure. Thus, for version 1 of the **DMA_ADAPTER** structure, *DmaOperations* points to version 1 of the **DMA_OPERATIONS** structure, and so on. For more information about structure versions, see the following Remarks section.

## Remarks

Drivers for devices that use DMA to transfer data use this structure to obtain the addresses of functions that enable use of a DMA controller. Usually, drivers obtain this structure by calling the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine. Drivers can also obtain this structure by querying for the [**BUS_INTERFACE_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard) interface.

When the **IoGetDmaAdapter** routine returns a pointer to version 1 or version 2 of the **DMA_ADAPTER** structure, this routine always sets the **Version** member of this structure to 1. Thus, the caller cannot use the **Version** member to distinguish between versions 1 and 2 of the **DMA_ADAPTER** structure. For more information about how to determine the version of a **DMA_ADAPTER** structure that is returned by this routine, see [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

## See also

[**BUS_INTERFACE_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_bus_interface_standard)

[**DMA_OPERATIONS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)