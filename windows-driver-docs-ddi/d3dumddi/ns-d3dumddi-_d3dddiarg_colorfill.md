# _D3DDDIARG_COLORFILL structure

## Description

The D3DDDIARG_COLORFILL structure describes the parameters of a color-fill operation.

## Members

### `hResource` [in]

A handle to the resource.

### `SubResourceIndex` [in]

The zero-based index into the resource, which is specified by the handle in the **hResource** member. This index indicates the subresource, or surface, on which a rectangular area is color-filled.

### `DstRect` [in]

A [RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl) structure that indicates the upper-left and lower-right points of a rectangle on the surface to color fill.

### `Color`

A D3DCOLOR data type for the A8R8G8B8 fill color.

### `Flags` [in]

A [D3DDDI_COLORFILLFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_colorfillflags) structure that identifies the type of color-fill operation to perform.

## See also

[ColorFill](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_colorfill)

[D3DDDI_COLORFILLFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_colorfillflags)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)