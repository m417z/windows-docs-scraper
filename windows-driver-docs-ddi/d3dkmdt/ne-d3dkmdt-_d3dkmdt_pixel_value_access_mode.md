# _D3DKMDT_PIXEL_VALUE_ACCESS_MODE enumeration

## Description

The D3DKMDT_PIXEL_VALUE_ACCESS_MODE enumeration is used to indicate the way color values or palette indices are stored in the primary surface of a video present source.

## Constants

### `D3DKMDT_PVAM_UNINITIALIZED`

Indicates that a variable of type D3DKMDT_PIXEL_VALUE_ACCESS_MODE has not yet been assigned a meaningful value.

### `D3DKMDT_PVAM_DIRECT`

Indicates that colors are stored directly in the primary surface.

### `D3DKMDT_PVAM_PRESETPALETTE`

Indicates that palette indices are stored in the primary surface. Colors are stored in a palette that is specific to the display adapter. The operating system can query the display miniport driver for the palette.

### `D3DKMDT_PVAM_SETTABLEPALETTE`

Indicates that palette indices are stored in the primary surface. Colors are stored in a palette that the operating system can set dynamically by calling the display miniport driver.

## Remarks

The **Format.Graphics** member of the [D3DKMDT_VIDPN_SOURCE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_source_mode) structure is a [D3DKMDT_GRAPHICS_RENDERING_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_graphics_rendering_format) structure. The **PixelValueAccessMode** member of the D3DKMDT_GRAPHICS_RENDERING_FORMAT structure is a D3DKMDT_PIXEL_VALUE_ACCESS_MODE value.

## See also

[VidPn Source Mode Set Interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/)