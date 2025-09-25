# D3DDDICB_EVICT structure

## Description

**D3DKMT_EVICT** is used with [pfnEvictCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_evictcb) to subtract one from the residency reference count.

Once this count reaches zero, it will remove the allocation from the device residency list.

## Members

### `NumAllocations` [in]

Number of allocation handles in the **AllocationList** array.

### `AllocationList` [in]

An array of **NumAllocations** allocation handles to mark for eviction. All allocations must be created on **hDevice**.

### `Flags` [in]

Specifies eviction behavior as documented in [D3DDDI_EVICT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_evict_flags).

### `NumBytesToTrim` [out]

When non-zero, specifies how much the application should evict in order to meet its current memory budget.

## See also

[D3DDDI_EVICT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_evict_flags)

[pfnEvictCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_evictcb)