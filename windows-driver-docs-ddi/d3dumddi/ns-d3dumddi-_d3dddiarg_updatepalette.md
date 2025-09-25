# _D3DDDIARG_UPDATEPALETTE structure

## Description

The D3DDDIARG_UPDATEPALETTE structure describes parameters that are used to update a texture palette.

## Members

### `PaletteHandle` [in]

A handle to the palette to be altered.

### `StartIndex` [in]

The index in the palette beyond which data is updated.

### `NumEntries` [in]

The number of PALETTEENTRY structures that are being updated. For more information about PALETTEENTRY, see the Microsoft Windows SDK documentation.

## Remarks

The Microsoft Direct3D runtime passes palette data for updating to the *pPaletteData* parameter in a call to the user-mode display driver's [UpdatePalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updatepalette) function. This palette data is an array of PALETTEENTRY structures.

## See also

[UpdatePalette](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_updatepalette)