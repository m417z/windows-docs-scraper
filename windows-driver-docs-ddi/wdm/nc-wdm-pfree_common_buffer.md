# PFREE_COMMON_BUFFER callback function

## Description

The **FreeCommonBuffer** routine frees a common buffer allocated by [AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer), along with all resources the buffer uses.

## Parameters

### `DmaAdapter` [in]

Pointer to the [DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) structure returned by [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) that represents the bus-master adapter or DMA controller.

### `Length` [in]

Specifies the number of bytes to deallocate.

### `LogicalAddress` [in]

Specifies the logical address of the allocated memory range.

### `VirtualAddress` [in]

Pointer to the corresponding virtual address of the allocated memory range.

### `CacheEnabled` [in]

Indicates whether the allocated memory is cached.

## Remarks

**FreeCommonBuffer**
is not a system routine that can be called directly by name. This routine is callable only by pointer from the address returned in a
[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)
structure. Drivers obtain the address of this routine by calling [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter).

To release a common buffer, a driver calls **FreeCommonBuffer** to unmap both its logical and virtual addresses. The parameters passed to **FreeCommonBuffer** must match exactly those passed to and returned from [AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer). A driver cannot free part of an allocated common buffer.

## See also

[AllocateCommonBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_common_buffer)

[DMA_ADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter)

[DMA_OPERATIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_operations)

[IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter)