# DDBLTBATCH structure

## Description

The DDBLTBATCH structure passes bit block transfer (bitblt) operations to the [IDirectDrawSurface7::BltBatch](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-bltbatch) method.

## Members

### `lprDest`

Address of a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that defines the destination for the bitblt.

### `lpDDSSrc`

Address of a DirectDrawSurface object to be the source of the bitblt.

### `lprSrc`

Address of a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that defines the source rectangle of the bitblt.

### `dwFlags`

Optional control flags. The following values are defined:

#### DDBLT_ALPHADEST

Uses either the alpha information in pixel format or the alpha channel surface attached to the destination surface as the alpha channel for this bitblt.

#### DDBLT_ALPHADESTCONSTOVERRIDE

Uses the **dwAlphaDestConst** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the alpha channel for the destination surface for this bitblt.

#### DDBLT_ALPHADESTNEG

The destination surface becomes more transparent as the alpha value increases (0 is opaque).

#### DDBLT_ALPHADESTSURFACEOVERRIDE

Uses the **lpDDSAlphaDest** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the alpha channel for the destination surface for this bitblt.

#### DDBLT_ALPHAEDGEBLEND

Uses the **dwAlphaEdgeBlend** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the alpha channel for the edges of the image that border the color key colors.

#### DDBLT_ALPHASRC

Uses either the alpha information in pixel format or the alpha channel surface attached to the source surface as the alpha channel for this bitblt.

#### DDBLT_ALPHASRCCONSTOVERRIDE

Uses the **dwAlphaSrcConst** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the source alpha channel for this bitblt.

#### DDBLT_ALPHASRCNEG

The source surface becomes more transparent as the alpha value increases (0 is opaque).

#### DDBLT_ALPHASRCSURFACEOVERRIDE

Uses the **lpDDSAlphaSrc** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the alpha channel source for this bitblt.

#### DDBLT_ASYNC

Performs this bitblt asynchronously through the first in, first out (FIFO) hardware in the order received. If no room is available in the FIFO hardware, the call fails.

#### DDBLT_COLORFILL

Uses the **dwFillColor** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the RGB color that fills the destination rectangle on the destination surface.

#### DDBLT_DDFX

Uses the **dwDDFX** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure to specify the effects to use for this bitblt.

#### DDBLT_DDROPS

Uses the **dwDDROP** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure to specify the raster operations (ROPS) that are not part of the Win32 API.

#### DDBLT_KEYDEST

Uses the color key that is associated with the destination surface.

#### DDBLT_KEYDESTOVERRIDE

Uses the **ddckDestColorkey** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the color key for the destination surface.

#### DDBLT_KEYSRC

Uses the color key that is associated with the source surface.

#### DDBLT_KEYSRCOVERRIDE

Uses the **ddckSrcColorkey** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the color key for the source surface.

#### DDBLT_ROP

Uses the **dwROP** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure for the ROP for this bitblt. These ROPs are the same as those defined in the Win32 API.

#### DDBLT_ROTATIONANGLE

Uses the **dwRotationAngle** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the rotation angle (specified in 1/100s of a degree) for the surface.

#### DDBLT_ZBUFFER

Performs a z-buffered bitblt, using the z-buffers that are attached to the source and destination surfaces and the **dwZBufferOpCode** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the z-buffer opcode.

#### DDBLT_ZBUFFERDESTCONSTOVERRIDE

Performs a z-buffered bitblt, using the **dwZDestConst** and **dwZBufferOpCode** members of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the z-buffer and z-buffer opcode, respectively, for the destination.

#### DDBLT_ZBUFFERDESTOVERRIDE

Performs a z-buffered bitblt, using the **lpDDSZBufferDest** and **dwZBufferOpCode** members of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the z-buffer and z-buffer opcode, respectively, for the destination.

#### DDBLT_ZBUFFERSRCCONSTOVERRIDE

Performs a z-buffered bitblt, using the **dwZSrcConst** and **dwZBufferOpCode** members of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the z-buffer and z-buffer opcode, respectively, for the source.

#### DDBLT_ZBUFFERSRCOVERRIDE

Performs a z-buffered bitblt, using the **lpDDSZBufferSrc** and **dwZBufferOpCode** members of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the z-buffer and z-buffer opcode, respectively, for the source.

### `lpDDBltFx`

Address of a [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure that specifies additional bitblt effects.