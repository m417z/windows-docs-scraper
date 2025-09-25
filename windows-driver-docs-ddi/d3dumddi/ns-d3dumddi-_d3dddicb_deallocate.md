# _D3DDDICB_DEALLOCATE structure

## Description

The D3DDDICB_DEALLOCATE structure describes allocations to release.

## Members

### `hResource` [in]

A handle to a resource whose associated allocations must be released. If the user-mode display driver uses the array that is specified by **HandleList** to specify the allocations to release, it sets **hResource** to **NULL**.

### `NumAllocations` [in]

The number of allocations in the **HandleList** array. If the user-mode display driver sets the handle in the **hResource** member to non-**NULL**, **NumAllocations** is ignored by the Microsoft Direct3D runtime.

### `HandleList` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations. The Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns these handles. Therefore, the user-mode display driver uses these handles to release the allocations.

If the user-mode display driver sets the handle in the **hResource** member to non-**NULL**, **HandleList** is ignored by the Direct3D runtime.

## See also

[pfnDeallocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_deallocatecb)