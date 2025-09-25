# _D3DDDICB_UNLOCK structure

## Description

The D3DDDICB_UNLOCK structure describes allocations to unlock.

## Members

### `NumAllocations` [in]

The number of allocations in the array that is specified by **phAllocations**.

### `phAllocations` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations. The Microsoft Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns these handles. Therefore, the user-mode display driver uses these handles to unlock the allocations.

## See also

[pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb)

[pfnUnlockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockcb)