# PFND3DDDI_SETPALETTE callback function

## Description

The *SetPalette* function associates a palette with a texture.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_SETPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpalette) structure that describes the parameters for the set-palette operation.

## Return value

*SetPalette* returns S_OK or an appropriate error result if the palette is not successfully associated with the texture.

## Remarks

The user-mode display driver uses the members in the [D3DDDIARG_SETPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpalette) structure that is pointed to by *pData* to map an association between a palette handle and a surface handle and to specify the characteristics of the palette.

## See also

[D3DDDIARG_SETPALETTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_setpalette)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)