# PFND3DDDI_SETTEXTURE callback function

## Description

The *SetTexture* function inserts a texture at a particular stage in a multiple-texture group.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*hTexture* [in]

A handle to the texture to insert.

### `unnamedParam3`

## Return value

*SetTexture* returns S_OK or an appropriate error result if the texture is not successfully inserted.

## See also

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)