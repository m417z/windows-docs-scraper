# _D3DDDICB_DEALLOCATE2 structure

## Description

The **D3DDDICB_DEALLOCATE2** structure describes parameters for releasing allocations with [pfnDeallocate2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocate2cb)

## Members

### `hResource` [in]

A handle to a resource whose associated allocations must be released. If the user-mode display driver uses the array that is specified by **HandleList** to specify the allocations to release, it sets **hResource** to **NULL**.

### `NumAllocations` [in]

The number of allocations in the **HandleList** array. If the user-mode display driver sets the handle in the **hResource** member to non-**NULL**, **NumAllocations** is ignored by the Direct3D runtime.

### `HandleList` [in]

An array of **D3DKMT_HANDLE** data types that represent kernel-mode handles to the allocations. The Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns these handles. Therefore, the user-mode display driver uses these handles to release the allocations.

If the user-mode display driver sets the handle in the **hResource** member to non-**NULL**, **HandleList** is ignored by the Direct3D runtime.

### `Flags` [in]

A [D3DDDICB_DESTROYALLOCATION2FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_destroyallocation2flags) structure that contains additional details about the operation.

## See also

[D3DDDICB_DESTROYALLOCATION2FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_destroyallocation2flags)

[pfnDeallocate2Cb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocate2cb)