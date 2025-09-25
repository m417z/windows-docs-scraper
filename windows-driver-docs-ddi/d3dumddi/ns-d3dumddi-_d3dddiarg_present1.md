# _D3DDDIARG_PRESENT1 structure

## Description

Describes a resource to display. Used with the [pfnPresent1(D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present1) function by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Members

### `phSrcResources` [in]

An array of non-**NULL** handles and zero-based indices to the source resource to display or to release. **phSrcResources** is always a valid handle for a resource to display.

### `SrcResources` [in]

The number of source resources that are in the array pointed to by **phSrcResources.**

### `hDstResource` [in]

A handle to the destination resource to display to. If **NULL**, the destination is unknown, and the display miniport driver determines the destination just before the hardware command stream is processed.

### `DstSubResourceIndex`

 [in] The zero-based index into the destination resource, which is specified by the handle in the **hDstResource** member. This index indicates the subresource or surface to display to.

### `Flags` [in]

A [D3DDDI_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_presentflags) structure that identifies, in bit-field flags, how to display.

### `FlipInterval` [in]

A [D3DDDI_FLIPINTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

### `Reserved`

This member is reserved and should be set to zero.

### `pDirtyRects` [in]

A pointer to an array of dirty rectangles ([RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)s), relative to the source rectangle **SrcRect**, that indicate the portion of the overlay plane that has changed.

The driver can use this member to perform optimizations, though it's not required to use the dirty rectangle info. However, the driver should never fail a function call based on the provided dirty rectangles.

### `DirtyRects` [in]

The number of dirty rectangles in the array pointed to by **pDirtyRects**.

### `BackBufferMultiplicity`

The number of physical back buffer per logical back buffer.

## See also

[D3DDDI_FLIPINTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-d3dddi_flipinterval_type)

[D3DDDI_PRESENTFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_presentflags)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)

[pfnPresent1(D3D)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present1)

[pfnPresentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentcb)