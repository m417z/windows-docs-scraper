## Description

The DDBLTFX structure passes raster operations (ROPs), effects, and override information to the [IDirectDrawSurface7::Blt](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-blt) method. This structure is also part of the [DDBLTBATCH](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltbatch) structure that is used with the [IDirectDrawSurface7::BltBatch](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-bltbatch) method.

## Members

### `dwSize`

Size of the structure, in bytes. This member must be initialized before the structure is used.

### `dwDDFX`

Type of FX operations. The following types are defined.

#### DDBLTFX_ARITHSTRETCHY

Uses arithmetic stretching along the y-axis for this bit block transfer (bitblt).

#### DDBLTFX_MIRRORLEFTRIGHT

Turns the surface on its y-axis. This bitblt mirrors the surface from left to right.

#### DDBLTFX_MIRRORUPDOWN

Turns the surface on its x-axis. This bitblt mirrors the surface from top to bottom.

#### DDBLTFX_NOTEARING

Schedules this bitblt to avoid tearing.

#### DDBLTFX_ROTATE180

Rotates the surface 180 degrees clockwise during this bitblt.

#### DDBLTFX_ROTATE270

Rotates the surface 270 degrees clockwise during this bitblt.

#### DDBLTFX_ROTATE90

Rotates the surface 90 degrees clockwise during this bitblt.

#### DDBLTFX_ZBUFFERBASEDEST

Adds the **dwZBufferBaseDest** member to each of the source z-values before comparing them with the destination z-values during this z-bitblt.

#### DDBLTFX_ZBUFFERRANGE

Uses the **dwZBufferLow** and **dwZBufferHigh** members as range values to specify limits to the bits copied from a source surface during this z-bitblt.

### `dwROP`

Win32 raster operations. You can retrieve a list of supported raster operations by calling the [IDirectDraw7::GetCaps](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-getcaps) method.

### `dwDDROP`

DirectDraw raster operations.

### `dwRotationAngle`

Rotation angle for the bitblt.

### `dwZBufferOpCode`

Z-buffer compares.

### `dwZBufferLow`

Low limit of a z-buffer.

### `dwZBufferHigh`

High limit of a z-buffer.

### `dwZBufferBaseDest`

Destination base value of a z-buffer.

### `dwZDestConstBitDepth`

Bit depth of the destination z-constant.

### `DUMMYUNIONNAMEN.dwZDestConst`

### `DUMMYUNIONNAMEN.lpDDSZBufferDest`

### `dwZSrcConstBitDepth`

Bit depth of the source z-constant.

### `DUMMYUNIONNAMEN.dwZSrcConst`

### `DUMMYUNIONNAMEN.lpDDSZBufferSrc`

### `dwAlphaEdgeBlendBitDepth`

Bit depth of the constant for an alpha edge blend.

### `dwAlphaEdgeBlend`

Alpha constant used for edge blending.

### `dwReserved`

Reserved

### `dwAlphaDestConstBitDepth`

Bit depth of the destination alpha constant.

### `DUMMYUNIONNAMEN.dwAlphaDestConst`

### `DUMMYUNIONNAMEN.lpDDSAlphaDest`

### `dwAlphaSrcConstBitDepth`

Bit depth of the source alpha constant.

### `DUMMYUNIONNAMEN.dwAlphaSrcConst`

### `DUMMYUNIONNAMEN.lpDDSAlphaSrc`

### `DUMMYUNIONNAMEN`

### `DUMMYUNIONNAMEN.dwFillColor`

### `DUMMYUNIONNAMEN.dwFillDepth`

### `DUMMYUNIONNAMEN.dwFillPixel`

### `DUMMYUNIONNAMEN.lpDDSPattern`

### `ddckDestColorkey`

Destination color key override.

### `ddckSrcColorkey`

Source color key override.

### `DUMMYUNIONNAMEN(1)`

#### dwZDestConst

Constant used as the z-buffer destination.

#### lpDDSZBufferDest

Surface used as the z-buffer destination.

### `DUMMYUNIONNAMEN(2)`

#### dwZSrcConst

Constant used as the z-buffer destination.

#### lpDDSZBufferSrc

Surface used as the z-buffer source.

### `DUMMYUNIONNAMEN(3)`

#### dwAlphaDestConst

Constant used as the alpha channel destination.

#### lpDDSAlphaDest

Surface used as the alpha channel destination.

### `DUMMYUNIONNAMEN(4)`

#### dwAlphaSrcConst

Constant used as the alpha channel source.

#### lpDDSAlphaSrc

Surface used as the alpha channel source.

### `DUMMYUNIONNAMEN(5)`

#### dwFillColor

Color used to fill a surface when DDBLT_COLORFILL is specified. This value must be a pixel appropriate to the pixel format of the destination surface. For a palettized surface, it would be a palette index, and for a 16-bit RGB surface, it would be a 16-bit pixel value.

#### dwFillDepth

Depth value for the z-buffer.

#### dwFillPixel

Pixel value for RGBA or RGBZ fills. Applications that use RGBZ fills should use this member, not **dwFillColor** or **dwFillDepth**.

#### lpDDSPattern

Surface to use as a pattern. The pattern can be used in certain blit operations that combine a source and a destination.

## Remarks

The unions in this structure have been updated to work with compilers that do not support nameless unions. If your compiler does not support nameless unions, define the NONAMELESSUNION token before including the Ddraw.h header file.