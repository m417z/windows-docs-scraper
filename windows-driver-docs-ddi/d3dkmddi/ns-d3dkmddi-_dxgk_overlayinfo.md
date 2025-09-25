# _DXGK_OVERLAYINFO structure

## Description

The DXGK_OVERLAYINFO structure describes parameters that are required to create or modify an overlay.

## Members

### `hAllocation` [in]

A handle to the allocation to be displayed on the overlay.

### `PhysicalAddress` [in]

The physical address, within the segment that **SegmentId** specifies, of the allocation to be displayed.

### `SegmentId` [in]

The identifier of a segment in which the allocation is currently paged-in.

### `DstRect` [in]

A [RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect) structure that contains the overlay destination rectangle, in device coordinates.

### `SrcRect` [in]

A RECT structure that contains the overlay source rectangle, in device coordinates.

### `pPrivateDriverData` [in]

A pointer to a block of private data that is passed from the user-mode display driver to the display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the block of private data that **pPrivateDriverData** points to.

## See also

[DXGKARG_CREATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createoverlay)

[DXGKARG_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_updateoverlay)

[DxgkDdiCreateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createoverlay)

[DxgkDdiUpdateOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateoverlay)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)