# _D3DDDICB_RECLAIMALLOCATIONS3 structure

## Description

D3DDDICB_RECLAIMALLOCATIONS3 is used with pfnReclaimAllocations3Cb to describe video memory resources, previously offered for reuse by the driver, that are to be reclaimed.

## Members

### `PagingQueue`

The paging queue, supplied by the user-mode driver, to page in the allocation list.

### `NumAllocations`

The number of allocations in **HandleList**.

### `pResources`

An array of Direct3D runtime resource handles.

### `HandleList`

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations.

### `pResults`

Required array of values specifying whether the surface is valid, discarded, or list commitment.

### `PagingFenceValue`

The paging fence to synchronize against before submitting work to the GPU, which references any of the resources or allocations in the provided arrays.

## Remarks

## See also