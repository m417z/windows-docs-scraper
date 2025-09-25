# _D3D12DDICB_RECLAIMALLOCATIONS2 structure

## Description

Describes video memory resources that are to be reclaimed and that the driver previously offered for reuse.

## Members

### `NumAllocations` [in]

 The number of items in **pDiscarded** and whichever of **pResources** or **HandleList** is non-NULL.

### `HandleList` [in]

 An array of allocation handles. If non-NULL, **pResources** must be NULL.

### `pDiscarded` [out]

Optional array of boolean values specifying whether each resource or allocation was discarded.

### `PagingFenceValue` [out]

The paging fence to synchronize against before submitting work to the GPU which references any of the resources or allocations in the provided arrays.