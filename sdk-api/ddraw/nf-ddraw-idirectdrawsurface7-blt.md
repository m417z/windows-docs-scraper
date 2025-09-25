# IDirectDrawSurface7::Blt

## Description

Performs a bit block transfer (bitblt). This method does not support z-buffering or alpha blending during bitblt operations.

## Parameters

### `unnamedParam1` [in]

A pointer to a **RECT** structure that defines the upper-left and lower-right points of the rectangle to bitblt to on the destination surface. If this parameter is NULL, the entire destination surface is used.

### `unnamedParam2` [in]

A pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the DirectDrawSurface object that is the source of the bitblt.

### `unnamedParam3` [in]

A pointer to a **RECT** structure that defines the upper-left and lower-right points of the rectangle to bitblt from on the source surface. If this parameter is NULL, the entire source surface is used.

### `unnamedParam4` [in]

A combination of flags that determine the valid members of the associated [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure, specify color-key information, or request special behavior from the method. The following flags are defined:

**Validation flags**

#### DDBLT_COLORFILL

Uses the **dwFillColor** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the RGB color that fills the destination rectangle on the destination surface.

#### DDBLT_DDFX

Uses the **dwDDFX** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure to specify the effects to use for this bitblt.

#### DDBLT_DDROPS

Uses the **dwDDROP** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure to specify the raster operations (ROPS) that are not part of the Win32 API.

#### DDBLT_DEPTHFILL

Uses the **dwFillDepth** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the depth value with which to fill the destination rectangle on the destination z-buffer surface.

#### DDBLT_KEYDESTOVERRIDE

Uses the **ddckDestColorkey** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the color key for the destination surface.

#### DDBLT_KEYSRCOVERRIDE

Uses the **ddckSrcColorkey** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the color key for the source surface.

#### DDBLT_ROP

Uses the **dwROP** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure for the ROP for this bitblt. These ROPs are the same as those defined in the Win32 API.

#### DDBLT_ROTATIONANGLE

Uses the **dwRotationAngle** member of the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure as the rotation angle (specified in 1/100s of a degree) for the surface.

**Color key flags**

#### DDBLT_KEYDEST

Uses the color key that is associated with the destination surface.

#### DDBLT_KEYSRC

Uses the color key that is associated with the source surface.

**Behavior flags**

#### DDBLT_ASYNC

Performs this bitblt asynchronously through the first in, first out (FIFO) hardware in the order received. If no room is available in the FIFO hardware, the call fails.

#### DDBLT_DONOTWAIT

Returns without bitbltting and also returns DDERR_WASSTILLDRAWING if the bitbltter is busy.

#### DDBLT_WAIT

Postpones the DDERR_WASSTILLDRAWING return value if the bitbltter is busy, and returns as soon as the bitblt can be set up or another error occurs.

**Obsolete and unsupported flags**

#### All DDBLT_ALPHA flag values

Not currently implemented.

#### All DDBLT_ZBUFFER flag values

This method does not currently support z-aware bitblt operations. None of the flags beginning with "DDBLT_ZBUFFER" are supported.

### `unnamedParam5` [in]

A pointer to the [DDBLTFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltfx) structure for the bitblt.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDCLIPLIST
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDRECT
* DDERR_NOALPHAHW
* DDERR_NOBLTHW
* DDERR_NOCLIPLIST
* DDERR_NODDROPSHW
* DDERR_NOMIRRORHW
* DDERR_NORASTEROPHW
* DDERR_NOROTATIONHW
* DDERR_NOSTRETCHHW
* DDERR_NOZBUFFERHW
* DDERR_SURFACEBUSY
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

**Blt** can perform synchronous or asynchronous bitblts (the latter is the default behavior). These bitblts can occur from display memory to display memory, from display memory to system memory, from system memory to display memory, or from system memory to system memory. The bitblts can be performed by using source color keys and destination color keys. Arbitrary stretching or shrinking is performed if the source and destination rectangles are not the same size.

Typically, **Blt** returns immediately with an error if the bitbltter is busy and the bitblt could not be set up. Specify the DDBLT_WAIT flag to request a synchronous bitblt. When you include the DDBLT_WAIT flag, **Blt** waits until the bitblt can be set up or another error occurs before it returns.

RECT structures are defined so that the right and bottom members are exclusive—therefore, right minus left equals the width of the rectangle, not 1 less than the width.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)