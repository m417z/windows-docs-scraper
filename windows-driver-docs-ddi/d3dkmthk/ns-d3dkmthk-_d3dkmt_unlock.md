# _D3DKMT_UNLOCK structure

## Description

The D3DKMT_UNLOCK structure describes allocations to unlock.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device that the allocation is associated with.

### `NumAllocations` [in]

The number of allocations in the array that **phAllocations** specifies.

### `phAllocations` [in]

An array of D3DKMT_HANDLE data types that represent kernel-mode handles to the allocations to unlock.

## See also

[D3DKMTUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtunlock)