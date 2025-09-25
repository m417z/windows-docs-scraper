# _D3DKMDT_GRAPHICS_RENDERING_FORMAT structure

## Description

The D3DKMDT_GRAPHICS_RENDERING_FORMAT structure contains information about a primary rendering surface.

## Members

### `PrimSurfSize`

A D3DKMDT_2DREGION structure that holds the size (number of pixels, both horizontal and vertical) of the surface.

### `VisibleRegionSize`

A D3DKMDT_2DREGION structure that holds the size of the visible portion of the surface.

### `Stride`

The offset, in bytes, between one scan line and the next scan line in the surface.

### `PixelFormat`

A value from the D3DDDIFORMAT enumeration that indicates the pixel format of the surface.

### `ColorBasis`

A value from the D3DKMDT_COLOR_BASIS enumeration that indicates the color basis used to encode the content of the surface.

### `PixelValueAccessMode`

A value from the D3DKMDT_PIXEL_VALUE_ACCESS_MODE enumeration that indicates the type of data (for example, direct color values or palette indexes) that are stored in the surface.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)