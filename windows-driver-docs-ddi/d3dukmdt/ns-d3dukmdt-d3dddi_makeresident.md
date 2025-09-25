# D3DDDI_MAKERESIDENT structure

## Description

**D3DDDI_MAKERESIDENT** is used with **MakeResident** ([pfnMakeResidentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_makeresidentcb) or [D3DKMTMakeResident](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtmakeresident)) to instruct the OS to add a resource to the device residency list and increment the residency reference count on this allocation.

## Members

### `hPagingQueue` [in]

Paging queue on the device that created the input allocations. This queue will be used for residency operations.

### `NumAllocations` [in/out]

On input, the number of allocation handles in the **AllocationList** array and allocation priority values in the **PriorityList** array. On output,
the number of allocations successfully made resident.

### `AllocationList` [in]

An array of **NumAllocations** allocation handles to make resident. All allocations must be created on the device **hPagingQueue** is created for.

### `PriorityList` [in]

An array of **NumAllocations** specifying residency priority for each of the input allocations. This value is currently ignored and may be set to **NULL**.

### `Flags` [in]

Specifies memory residency behavior as documented in [D3DDDI_MAKERESIDENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_makeresident_flags).

### `PagingFenceValue` [out]

When **MakeResident** returns **E_PENDING**, this member indicates the paging queue fence value to wait on.

### `NumBytesToTrim` [out]

When **MakeResident** returns **E_OUTOFMEMORY**, this member indicates the number of bytes over budget the application would be if the allocation(s) were made resident.

## See also

[D3DDDI_MAKERESIDENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_makeresident_flags)

[D3DKMTMakeResident](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtmakeresident)

[pfnMakeResidentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_makeresidentcb)