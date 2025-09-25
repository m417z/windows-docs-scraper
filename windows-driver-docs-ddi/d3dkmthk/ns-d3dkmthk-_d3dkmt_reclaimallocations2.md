# _D3DKMT_RECLAIMALLOCATIONS2 structure

## Description

**D3DKMT_RECLAIMALLOCATIONS2** describes video memory resources that are to be reclaimed and that the driver previously offered for reuse. Used with the [D3DKMTReclaimAllocations2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtreclaimallocations2) function.

## Members

### `hPagingQueue` [in]

A handle to the device that created the allocations.

### `NumAllocations` [in]

The number of items in the **pResources**, **HandleList**, or **pDiscarded** members, whichever is not **NULL**.

### `pResources` [in]

An array of **D3DKMT_HANDLE** data types that represent Direct3D runtime resource handles.

### `HandleList` [in]

An array of **D3DKMT_HANDLE** data types that represent kernel-mode handles to the allocations that are to be reclaimed.

If **HandleList** is not **NULL**, the **pResources** member must be **NULL**.

### `pResults` [in]

Required array of values specifying whether the surface is valid, discarded, or list commitment.

### `pDiscarded` [out]

Optional array of boolean variables specifying whether each resource or allocation was discarded.

*pResults*

[out] Pointer to an array of [D3DDDI_RECLAIM_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_reclaim_result) enumerations that represent results, specifying whether each resource or allocation is OK, discarded, or has no commitment.

*pResults* is valid only if the DXGKDDI_INTERFACE_VERSION and D3D_UMD_INTERFACE_VERSION are greater than or equal to DXGKDDI_INTERFACE_VERSION_WDDM2_1 and D3D_UMD_INTERFACE_VERSION_WDDM2_1, respectively.

### `PagingFenceValue`

The paging fence to synchronize against before submitting work to the GPU which references any of the resources or allocations in the provided arrays.