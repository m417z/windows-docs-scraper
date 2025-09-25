# _D3DKMT_DESTROYALLOCATION2 structure

## Description

The **D3DKMT_DESTROYALLOCATION2** structure describes parameters for releasing allocations with [D3DKMTDestroyAllocation2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroyallocation2).

## Members

### `hDevice` [in]

A **D3DKMT_HANDLE** data type that represents a kernel-mode handle to the device that the resource, allocations, or both are associated with.

### `hResource` [in]

A **D3DKMT_HANDLE** data type that represents a kernel-mode handle to the resource that is associated with the allocations when releasing a resource. If a resource handle is specified, all of the allocations that are associated with it are automatically released.

### `phAllocationList` [in]

An array of **D3DKMT_HANDLE** data types that represent kernel-mode handles to the allocations. If any allocation in the list is associated with a resource, all of the allocations in the list must also be associated with the same resource. If the OpenGL installable client driver sets the handle in the **hResource** member to a non-**NULL** value, the installable client driver must set **phAllocationList** to **NULL**.

### `AllocationCount` [in]

The number of allocations in the array that **phAllocationList** specifies. If the OpenGL installable client driver sets the handle in the **hResource** member to a non-**NULL** value, the **AllocationCount** member is ignored by the OpenGL runtime.

### `Flags` [in]

A [D3DDDICB_DESTROYALLOCATION2FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_destroyallocation2flags) structure that contains additional details about the operation.

## See also

[D3DDDICB_DESTROYALLOCATION2FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_destroyallocation2flags)

[D3DKMTDestroyAllocation2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtdestroyallocation2)