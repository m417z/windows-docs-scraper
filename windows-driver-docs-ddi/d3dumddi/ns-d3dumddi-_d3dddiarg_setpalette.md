# _D3DDDIARG_SETPALETTE structure

## Description

The D3DDDIARG_SETPALETTE structure describes how to associate a palette with a texture.

## Members

### `PaletteHandle` [in]

A handle to the palette to be set up. If the value of **PaletteHandle** is zero, the surface that is specified by **hResource** should be uncoupled from any palette that it might have been associated with previously.

### `PaletteFlags` [in]

A valid bitwise OR of the following flags that specify the attributes of the palette.

| **Flag** | **Meaning** |
|:--|:--|
| D3DDDISETPALETTE_256 (0x00000001) | The palette has 256 entries. |
| D3DDDISETPALETTE_ALLOW256 (0x00000200) | The palette can be fully updated. |
| D3DDDISETPALETTE_ALPHA (0x00002000) | The palette's alpha data channel is valid and should be used. |

### `hResource` [in]

A handle to the surface (texture) with which the palette that is identified by **PaletteHandle** is associated.

## Remarks

The user-mode display driver's [SetPalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpalette) function associates the palette that is specified by the **PaletteHandle** member with the surface that is specified by the **hResource** member and uses the **PaletteFlags** member to specify the characteristics of the palette.

## See also

[SetPalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setpalette)