# _DXGKARG_RENDERGDI structure

## Description

The **DXGKARG_RENDERGDI** structure is used when submitting Windows Graphics Device Interface (GDI) commands for contexts that support virtual addressing.

## Members

### `pCommand`

A pointer to the start of the command buffer.

### `CommandLength`

The size, in bytes, of the command buffer that **pCommand** points to.

### `pDmaBuffer`

A pointer to the start of the DMA buffer, which is aligned on 4 KB.

### `DmaBufferGpuVirtualAddress`

A **D3DGPU_VIRTUAL_ADDRESS** data type that indicates the virtual address where the DMA buffer was paged in. If the physical address is zero, the DMA buffer is not correctly paged in.

### `DmaSize`

The size, in bytes, of the DMA buffer that **pDmaBuffer** points to.

### `pDmaBufferPrivateData`

A pointer to a driver-resident private data structure that is used for generating the DMA buffer that **pDmaBuffer** points to.

### `DmaBufferPrivateDataSize`

The number of bytes that remain in the private data structure that **pDmaBufferPrivateData** points to for the current operation.

### `pAllocationList`

An array of [DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist) structures for the list of allocations that the DMA buffer references. Each allocation that is referenced should appear once for optimal performance.

### `AllocationListSize`

The available number of elements in the array that **pAllocationList** specifies, which represents the number of allocation specifications to send through DMA to the graphics hardware.

### `MultipassOffset`

A value that specifies the progress of the rendering operation.