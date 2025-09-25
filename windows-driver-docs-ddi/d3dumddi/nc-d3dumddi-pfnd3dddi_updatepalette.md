# PFND3DDDI_UPDATEPALETTE callback function

## Description

The *UpdatePalette* function updates a texture palette.

## Parameters

### `hDevice` [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_UPDATEPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_updatepalette) structure that describes parameters for the palette-update operation.

### `unnamedParam3`

*pPaletteData* [in]

An array of PALETTEENTRY structures to update. For more information about PALETTEENTRY, see the Microsoft Windows SDK documentation.

## Return value

*UpdatePalette* returns S_OK or an appropriate error result if the texture palette is not successfully updated.

## Remarks

The palette data in the array that is specified by *pPaletteData* consists of one UINT value for each palette entry (PALETTEENTRY structure). The palette entry is in ARGB format, with 8 bits for each of the four channels.

The user-mode display driver uses the following members of the [D3DDDIARG_UPDATEPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_updatepalette) structure that is pointed to by *pData* to update the texture palette:

* The **PaletteHandle** member specifies the handle to the palette that is associated with the surface.
* The **StartIndex** member specifies the index of the entry in the array at *pPaletteData* where the update should start.
* The **NumEntries** member specifies the number of entries in the array at *pPaletteData* to update.

## See also

[D3DDDIARG_UPDATEPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_updatepalette)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)