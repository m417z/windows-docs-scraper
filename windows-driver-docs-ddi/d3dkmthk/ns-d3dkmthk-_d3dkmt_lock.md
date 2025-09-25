# _D3DKMT_LOCK structure

## Description

The D3DKMT_LOCK structure describes parameters for locking an allocation.

## Members

### `hDevice` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the device that the allocation is associated with.

### `hAllocation` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the allocation to lock.

### `PrivateDriverData` [in]

A UINT value that specifies 32 bits of private data (for example, MIP level) that is sent from the OpenGL ICD to the display miniport driver's [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function.

### `NumPages` [in]

The number of pages in the page list that **pPages** specifies.

### `pPages` [in]

An array of pages to lock. Each page in the array is described by an integer offset. Zero means the first page in the surface, one means the second, and so on.

### `pData` [out]

A pointer to the memory that is returned from the display miniport driver and memory manager. When locking a memory page list, the pointer that is returned is a pointer to the first memory page.

### `Flags` [in]

A [D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags) structure that identifies, in bit-field flags, how to lock the allocation.

Note that specifying some flags together is invalid and that some flags depend on other flags. For more information about these combinations, see the Remarks section of [D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags).

### `GpuVirtualAddress`

This member is reserved and should be set to zero.

This member is available beginning with Windows 7.

## See also

[D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags)

[D3DKMTLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtlock)

[DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange)