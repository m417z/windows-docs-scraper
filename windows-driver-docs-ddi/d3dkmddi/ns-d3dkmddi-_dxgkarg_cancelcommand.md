# _DXGKARG_CANCELCOMMAND structure

## Description

Specifies internal resources that are cleaned up by the [DxgkDdiCancelCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelcommand) function after a command is removed from the hardware queue.

## Members

### `hContext` [in]

If the driver is multiple-engine aware (that is, the driver supports context creation), a handle to the device context that the cancel request originated from.

For some paging operations, **hContext** is **NULL** (for example, paging operations that evict the content of the entire frame buffer during power management). Paging operations are indicated by the **Paging** bit-field flag in the **Flags** member.

### `pDmaBuffer` [out]

A pointer to the start of the DMA buffer, which is aligned on 4 KB.

### `DmaBufferSize` [in]

The size, in bytes, of the DMA buffer that **pDmaBuffer** points to.

### `DmaBufferSubmissionStartOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer that **pDmaBuffer** specifies to the start of the portion of the DMA buffer that requires canceling. The offset that is received at patch time matches the offset that is received at submission time.

### `DmaBufferSubmissionEndOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer that **pDmaBuffer** specifies to the end of the portion of the DMA buffer that requires canceling.

### `pDmaBufferPrivateData` [in]

A pointer to the driver-resident private data that is associated with the DMA buffer that **pDmaBuffer** points to.

### `DmaBufferPrivateDataSize` [in]

The size, in bytes, of the private driver data at **pDmaBufferPrivateData**.

Note that **DmaBufferPrivateDataSize** represents the entire length of the private driver data buffer; however, the portion that is associated with the current cancellation request might be smaller.

### `DmaBufferPrivateDataSubmissionStartOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer private data that **pDmaBufferPrivateData** specifies to the start of the portion of the private data that is associated with the current cancellation request.

### `DmaBufferPrivateDataSubmissionEndOffset` [in]

The offset, in bytes, from the beginning of the DMA buffer private data that **pDmaBufferPrivateData** specifies to the end of the portion of the private data that is associated with the current cancellation request.

### `pAllocationList` [in]

A pointer to an array of [DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist) structures for the list of allocations that is associated with the DMA buffer that **pDmaBuffer** points to.

### `AllocationListSize` [in]

The number of elements in the array that **pAllocationList** specifies.

Note that **AllocationListSize** represents the total size of the allocation list; however, the portion of the allocation list that is associated with the current cancellation request might be smaller.

### `pPatchLocationList` [in]

A pointer to an array of [D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist) structures for the list of patch locations that is associated with the DMA buffer that **pDmaBuffer** points to.

Note that the array can begin with an element that is before the range that is used to patch the DMA buffer.

### `PatchLocationListSize` [in]

The number of elements in the array that **pPatchLocationList** specifies.

Note that **PatchLocationListSize** represents the total size of the patch-location list; however, the range that the driver must process is typically smaller.

### `PatchLocationListSubmissionStart` [in]

The index of the first element in the patch-location list that **pPatchLocationList** specifies that must be processed.

### `PatchLocationListSubmissionLength` [in]

The number of elements in the patch-location list that **pPatchLocationList** specifies that must be processed.

### `DmaBufferVirtualAddress`

### `DmaBufferUmdPrivateDataSize`

## See also

[D3DDDI_PATCHLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_patchlocationlist)

[DXGK_ALLOCATIONLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationlist)

[DxgkDdiCancelCommand](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelcommand)

[DxgkDdiCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcontext)