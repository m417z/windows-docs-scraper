# D3D12DDIARG_PRESENT_0001 structure

## Description

## Members

### `phSurfacesToPresent`

A array of surface handles to display or to release.

### `SurfacesToPresent`

The surfaces to display or to release.

### `hDstResource`

A handle to the destination resource to display to.

### `DstSubResourceIndex`

The zero-based index into the destination resource, which is specified by the handle in the *hDstResource* member. This index indicates the subresource or surface to display to.

### `Flags`

Identifies, in bit-field flags, how to display.

### `FlipInterval`

Indicates the flip interval. That is, if the flip occurs after zero, one, two, three, or four vertical syncs.

### `VidPnSourceID`

### `pDirtyRects`

A pointer to an array of dirty rectangles, that indicate the portion of the overlay plane that has changed.

### `DirtyRects`

The number of dirty rectangles in the array pointed to by *pDirtyRects*.

### `PrivateDriverDataSize`

Private driver data size in bytes.

### `pPrivateDriverData`

Private driver data.

### `OptimizeForComposition`

DWM is involved in composition.

## Remarks

## See also