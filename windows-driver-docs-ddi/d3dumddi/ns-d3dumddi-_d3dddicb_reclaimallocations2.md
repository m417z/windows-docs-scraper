# _D3DDDICB_RECLAIMALLOCATIONS2 structure

## Description

**D3DDDICB_RECLAIMALLOCATIONS2** is used with [pfnReclaimAllocations2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_reclaimallocations2cb) to describe video memory resources, previously offered for reuse by the driver, that are to be reclaimed.

## Members

### `PagingQueue` [in]

The paging queue, supplied by the user-mode driver, to page in the allocation list.

### `NumAllocations` [in]

 The number of items in **pDiscarded** and whichever of **pResources** or **HandleList** is non-NULL.

### `pResources` [in]

 An array of Direct3D runtime resource handles.

### `HandleList` [in]

 An array of allocation handles. If non-NULL, **pResources** must be NULL.

### `pDiscarded` [out]

Optional array of boolean values specifying whether each resource or allocation was discarded.

### `PagingFenceValue` [out]

The paging fence to synchronize against before submitting work to the GPU which
references any of the resources or allocations in the provided arrays