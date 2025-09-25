# _DXGKARG_RELEASESWIZZLINGRANGE structure

## Description

The DXGKARG_RELEASESWIZZLINGRANGE structure describes parameters for releasing a swizzling range.

## Members

### `hAllocation` [in]

A handle to the allocation that the display miniport driver assigns and that is returned through the driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function.

### `PrivateDriverData` [in]

The 32 bits of private data that the user-mode display driver sent when the display miniport driver's [DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange) function was called to acquire the swizzling range.

### `RangeId` [in]

The zero-based identifier of the swizzling range that the [DxgkDdiReleaseSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_releaseswizzlingrange) function releases.

## See also

[DxgkDdiAcquireSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_acquireswizzlingrange)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiReleaseSwizzlingRange](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_releaseswizzlingrange)