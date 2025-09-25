# _DXGKARG_FLIPOVERLAY structure

## Description

The DXGKARG_FLIPOVERLAY structure describes a new allocation to display for the overlay.

## Members

### `hSource` [in]

A handle to the source allocation to be displayed.

### `SrcPhysicalAddress` [in]

The physical address, within the segment that **SrcSegmentId** specifies, of the allocation to be displayed.

### `SrcSegmentId` [in]

The identifier of a segment in which the allocation is currently paged.

### `pPrivateDriverData` [in]

A pointer to a block of private data that is passed from the user-mode display driver to the display miniport driver.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the block of private data that **pPrivateDriverData** points to.

## See also

[DxgkDdiFlipOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_flipoverlay)