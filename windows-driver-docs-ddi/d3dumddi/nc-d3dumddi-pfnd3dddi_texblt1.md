# PFND3DDDI_TEXBLT1 callback function

## Description

Performs a bit-block transfer (bitblt) operation from a source texture to a destination texture, including all of the sublevels of the source texture. Implemented by Windows Display Driver Model (WDDM) 1.2 or later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDIARG_TEXBLT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_texblt1) structure that defines the parameters for the texture bitblt operation.

## Return value

Returns S_OK or an appropriate error result if the texture bitblt operation is not successfully performed.

## Remarks

The Microsoft Direct3D runtime calls the user-mode display driver's *TexBlt* function to inform the driver to perform a bitblt operation from a source texture to a destination texture. A texture can also be a cubic environment map. The driver should copy the rectangle that is specified by the **SrcRect** member of the [D3DDDIARG_TEXBLT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_texblt) structure in the source texture to the location that is specified by the **DstPoint** member of D3DDDIARG_TEXBLT in the destination texture. The destination and source textures are identified by the **hDstResource** and **hSrcResource** handles of D3DDDIARG_TEXBLT, respectively.

For MIP-mapped textures, the driver must also copy all of the MIP-map sublevels that are present in the source texture. The source and destination textures might possibly contain different numbers of MIP-map levels. In this situation, the driver should copy the common levels. For example, if a 256x256 source texture has eight MIP-map levels, and if the destination is a 64x64 texture with six levels, the driver should copy the six corresponding levels from the source. Note that the dimensions of the top MIP level of the destination texture is always less than or equal to the dimensions of the top MIP level of the source texture.

The source and destination handles always refer to the top-level surfaces and never to any MIP-map sublevel.

To copy an arbitrary level of a MIP-map texture, the runtime calls the driver's [Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt) function instead.

The pixel formats of the source and destination textures are identical and, in general, the specified bitblt operation is safe to perform.

## See also

[Blt](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_blt)

[D3DDDIARG_TEXBLT1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_texblt1)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)