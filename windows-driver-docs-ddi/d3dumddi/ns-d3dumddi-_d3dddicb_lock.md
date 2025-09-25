# _D3DDDICB_LOCK structure

## Description

The D3DDDICB_LOCK structure describes parameters for locking an allocation.

## Members

### `hAllocation` [in/out]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the allocation. The Microsoft Direct3D runtime's [pfnAllocateCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_allocatecb) function returns this handle. Therefore, the user-mode display driver should use this handle to lock the allocation.

If the **Discard** bit-field flag is set in the **Flags** member, the video memory manager creates a new instance of the allocation and returns a new handle that represents the new instance.

### `PrivateDriverData` [in]

Private data (for example, MIP level) that is sent from the user-mode display driver to the display miniport driver's [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function.

### `NumPages` [in]

The number of pages in the page list that is pointed to by **pPages**.

### `pPages` [in]

An array of pages to lock. Each page in the array is described by an integer offset. Zero means the first page in the surface, one means the second, and so on.

### `pData` [out]

A pointer to the memory that is returned from the display miniport driver and memory manager. When locking a memory page list, the pointer that is returned is a pointer to the first memory page.

### `Flags` [in]

A [D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags) structure that identifies, in bit-field flags, how to lock the allocation.

Note that specifying some flags together is invalid and that some flags depend on other flags. For more information about specifying these flags, see the Remarks section of [D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags).

### `GpuVirtualAddress`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

## See also

[D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags)

[DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)