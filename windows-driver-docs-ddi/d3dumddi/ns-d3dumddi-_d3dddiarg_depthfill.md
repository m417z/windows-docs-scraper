# _D3DDDIARG_DEPTHFILL structure

## Description

The D3DDDIARG_DEPTHFILL structure describes the parameters of a depth-fill operation.

## Members

### `hResource` [in]

A handle to the resource.

### `SubResourceIndex` [in]

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource, or buffer, on which a rectangular area is depth-filled.

### `DstRect` [in]

A [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that indicates the upper-left and lower-right points of a rectangle on the buffer to depth fill.

### `Depth`

A pixel value that is specified in native format for the fill depth.

## See also

[DepthFill](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_depthfill)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)