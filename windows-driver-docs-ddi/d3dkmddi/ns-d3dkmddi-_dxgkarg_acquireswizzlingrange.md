# _DXGKARG_ACQUIRESWIZZLINGRANGE structure

## Description

The DXGKARG_ACQUIRESWIZZLINGRANGE structure describes parameters for making an allocation accessible through a CPU aperture.

## Members

### `hAllocation` [in]

A handle to the allocation that the display miniport driver assigned and that is returned through its [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function.

### `PrivateDriverData` [in]

A UINT value of private data that the user-mode display driver sends when it calls the Microsoft Direct3D runtime's [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function. The private data should be an index that lets the display miniport driver determine the accessible part of the allocation (for example, the MIP level). This member should not contain a pointer.

### `RangeId` [in]

The zero-based identifier of the swizzling range that the [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function programs.

### `SegmentId` [in]

The identifier of a segment in which the allocation is currently paged.

### `RangeSize` [in]

The size, in bytes, of the range to acquire. This range size is identical to the size of the allocation that [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) acquires a range for. The driver can modify the value in **RangeSize** when the **UseAlternateVA** bit-field flag is specified in the **Flags** member of the [D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags) structure in a call to the [pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb) function. If the **UseAlternateVA** flag is not specified, the driver cannot change **RangeSize**.

### `CPUTranslatedAddress` [in/out]

The base physical address where the CPU should map the allocation. The display miniport driver must set this information when a call to its [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function succeeds.

## See also

[D3DDDICB_LOCKFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddicb_lockflags)

[DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[pfnLockCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockcb)