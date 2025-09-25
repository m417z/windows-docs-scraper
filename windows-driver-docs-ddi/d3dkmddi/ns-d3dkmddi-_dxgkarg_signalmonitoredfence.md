# _DXGKARG_SIGNALMONITOREDFENCE structure

## Description

Arguments used by the [DXGKDDI_SIGNALMONITOREDFENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_signalmonitoredfence) callback function to add a GPU instruction to signal the paging monitored fence object to the DMA buffer.

## Members

### `KernelSubmissionType`

Describes what type of kernel submission is being performed. This information can be used by the driver to choose the right synchronization class, and to ensure fence write instruction is generated in the format compatible with the buffer type being used.

### `pDmaBuffer`

A pointer to the start of the DMA buffer, which is aligned on 4 KB.

### `DmaBufferGpuVirtualAddress`

A **D3DGPU_VIRTUAL_ADDRESS** data type that indicates the virtual address where the DMA buffer was paged in. If the physical address is zero, the DMA buffer is not correctly paged in.

### `DmaSize`

The size, in bytes, of the DMA buffer that *pDmaBuffer* points to.

### `pDmaBufferPrivateData`

A pointer to a driver-resident private data structure that is used for generating the DMA buffer that *pDmaBuffer* points to.

### `DmaBufferPrivateDataSize`

The number of bytes that remain in the private data structure that *pDmaBufferPrivateData* points to for the current operation.

### `MultipassOffset`

A value that specifies the progress of the rendering operation.

### `MonitoredFenceGpuVa`

GPU VA of the monitored fence value to be updated.

### `MonitoredFenceValue`

Fence value to write from the DMA buffer being built.

### `MonitoredFenceCpuVa`

Kernel mode CPU VA of the monitored fence value to be updated.

### `hHwQueue`

Handle to the hardware queue that the DMA buffer will be submitted to.

## Remarks

## See also