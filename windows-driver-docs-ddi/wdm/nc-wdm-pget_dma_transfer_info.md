# PGET_DMA_TRANSFER_INFO callback function

## Description

The **GetDmaTransferInfo** routine calculates the allocation requirements for a scatter/gather DMA transfer.

## Parameters

### `DmaAdapter` [in]

A pointer to a [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure. This structure is the adapter object that represents the driver's bus-master DMA device or system DMA channel. The caller obtained this pointer from a previous call to the [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) routine.

### `Mdl` [in]

A pointer to the MDL chain that describes the pages of memory that are to be transferred. For more information, see the Remarks section.

### `Offset` [in]

The starting offset for the scatter/gather DMA transfer. This parameter is a byte offset from the start of the buffer in the first MDL in the MDL chain. If the MDLs in the MDL chain specify a total of N bytes of buffer space, valid values of *Offset* are in the range 0 to N–1.

### `Length` [in]

The length, in bytes, of the DMA transfer. If the MDL chain specifies a total of N bytes of buffer space, valid values of *Length* are in the range 1 to N–*Offset*.

### `WriteOnly` [in]

Indicates whether the transfer is a write-only operation (that is, a transfer to the device from memory). If *WriteOnly* is TRUE, information returned about the transfer might not be valid for a read transaction. This parameter might indicate that additional cache control operations are required at buffer boundaries to enforce cache coherency.

### `TransferInfo` [in, out]

A pointer to a caller-allocated [DMA_TRANSFER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info) structure. The caller must set the **Version** member of the structure to DMA_TRANSFER_INFO_VERSION1 before calling **GetDmaTransferInfo**.

## Return value

**GetDmaTransferInfo** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_SUPPORTED** | The routine does not support the specified version of the **DMA_TRANSFER_INFO_*XXX*** structure. |

## Remarks

**GetDmaTransferInfo** *is not a system routine that can be called directly by name. This routine can be called only by pointer from the address returned in a* [DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations) *structure.* Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) with the **Version** member of the *DeviceDescription* parameter set to DEVICE_DESCRIPTION_VERSION3. If **IoGetDmaAdapter** returns **NULL**, the routine is not available on your platform.

Use **GetDmaTransferInfo** to calculate the size of the scatter/gather buffer to allocate for the [BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex) and [MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex) routines.

**GetDmaTransferInfo** replaces the [CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size) routine and is more convenient to use with **BuildScatterGatherListEx**.

The *Mdl*, *Offset*, and *Length* parameters together specify a collection of physical memory regions to use as a buffer for a scatter/gather DMA transfer. Each physical memory region is typically a page or part of a page. **GetDmaTransferInfo** determines the allocation requirements for this transfer. These requirements include the following:

* The number of elements in the scatter/gather list. Each element is a **SCATTER_GATHER_ELEMENT** structure that describes a physically contiguous block of memory.
* The amount of memory to allocate to hold the specified scatter/gather list. (This memory allocation includes the space required for the scatter/gather list that describes the I/O buffer but not for the I/O buffer itself.)
* The number of map registers required to translate the physical addresses in the scatter/gather list to logical addresses.

For information about the DMA transfer information that is provided by version 1 of the **DMA_TRANSFER_INFO_*XXX*** structure, see [DMA_TRANSFER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info_v1).

An MDL describes the physical memory pages that underlie a locked-down, contiguous block of virtual memory. Typically, these physical memory pages are non-contiguous. An MDL chain is an ordered collection of MDLs that describes memory that can be used to buffer I/O data. Typically, the virtual memory regions described by the MDLs in the chain are non-contiguous. For more information about MDLs and MDL chains, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[BuildScatterGatherListEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pbuild_scatter_gather_list_ex)

[CalculateScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcalculate_scatter_gather_list_size)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[DMA_TRANSFER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info)

[DMA_TRANSFER_INFO_V1](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_transfer_info_v1)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)

[MapTransferEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pmap_transfer_ex)