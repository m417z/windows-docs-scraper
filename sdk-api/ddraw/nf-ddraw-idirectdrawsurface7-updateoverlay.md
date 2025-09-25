# IDirectDrawSurface7::UpdateOverlay

## Description

Repositions or modifies the visual attributes of an overlay surface. These surfaces must have the DDSCAPS_OVERLAY flag set.

## Parameters

### `unnamedParam1` [in]

A pointer to a **RECT** structure that defines the x, y, width, and height of the region on the source surface being used as the overlay. This parameter can be NULL to hide an overlay or to indicate that the entire overlay surface is to be used and that the overlay surface conforms to any boundary and size-alignment restrictions imposed by the device driver.

### `unnamedParam2` [in]

A pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the DirectDrawSurface object that is being overlaid.

### `unnamedParam3` [in]

A pointer to a **RECT** structure that defines the width, x, and height, y, of the region on the destination surface that the overlay should be moved to. This parameter can be NULL to hide the overlay.

### `unnamedParam4` [in]

A combination of the following flags that determine the overlay update:

#### DDOVER_ADDDIRTYRECT

Adds a dirty rectangle to an emulated overlay surface.

#### DDOVER_ALPHADEST

Obsolete.

#### DDOVER_ALPHADESTCONSTOVERRIDE

Uses the **dwAlphaDestConst** member of the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure as the destination alpha channel for this overlay.

#### DDOVER_ALPHADESTNEG

Indicates that the destination surface becomes more transparent as the alpha value increases (0 is opaque).

#### DDOVER_ALPHADESTSURFACEOVERRIDE

Uses the **lpDDSAlphaDest** member of the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure as the alpha channel destination for this overlay.

#### DDOVER_ALPHAEDGEBLEND

Uses the **dwAlphaEdgeBlend** member of the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure as the alpha channel for the edges of the image that border the color key colors.

#### DDOVER_ALPHASRC

Uses either the alpha information in pixel format or the alpha channel surface attached to the source surface as the source alpha channel for this overlay.

#### DDOVER_ALPHASRCCONSTOVERRIDE

Uses the **dwAlphaSrcConst** member of the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure as the source alpha channel for this overlay.

#### DDOVER_ALPHASRCNEG

Indicates that the source surface becomes more transparent as the alpha value increases (0 is opaque).

#### DDOVER_ALPHASRCSURFACEOVERRIDE

Uses the **lpDDSAlphaSrc** member of the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure as the alpha channel source for this overlay.

#### DDOVER_ARGBSCALEFACTORS

New for DirectX 7.0. Indicates that the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure contains valid ARGB scaling factors.

#### DDOVER_AUTOFLIP

Automatically flips to the next surface in the flipping chain each time that a video port VSYNC occurs.

#### DDOVER_BOB

Displays each field of the interlaced video stream individually without causing any artifacts to display.

#### DDOVER_BOBHARDWARE

Bob operations are performed by using hardware, rather than by using software or being emulated. This flag must be used with the DDOVER_BOB flag.

#### DDOVER_DDFX

Uses the overlay FX flags in the *lpDDOverlayFx* parameter to define special overlay effects.

#### DDOVER_DEGRADEARGBSCALING

New for DirectX 7.0. ARGB scaling factors can be degraded to fit driver capabilities.

#### DDOVER_HIDE

Turns off this overlay.

#### DDOVER_INTERLEAVED

The surface memory is composed of interleaved fields.

#### DDOVER_KEYDEST

Uses the color key associated with the destination surface.

#### DDOVER_KEYDESTOVERRIDE

Uses the **dckDestColorkey** member of the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure as the color key for the destination surface.

#### DDOVER_KEYSRC

Uses the color key associated with the source surface.

#### DDOVER_KEYSRCOVERRIDE

Uses the **dckSrcColorkey** member of the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure as the color key for the source surface.

#### DDOVER_OVERRIDEBOBWEAVE

Bob and weave decisions should not be overridden by other interfaces.

#### DDOVER_REFRESHALL

Redraws the entire surface on an emulated overlayed surface.

#### DDOVER_REFRESHDIRTYRECTS

Redraws all dirty rectangles on an emulated overlayed surface.

#### DDOVER_SHOW

Turns on this overlay.

### `unnamedParam5` [in]

A pointer to the [DDOVERLAYFX](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddoverlayfx) structure that describes the effects to be used. Can be NULL if the DDOVER_DDFX flag is not specified.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_DEVICEDOESNTOWNSURFACE
* DDERR_GENERIC
* DDERR_HEIGHTALIGN
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDRECT
* DDERR_INVALIDSURFACETYPE
* DDERR_NOSTRETCHHW
* DDERR_NOTAOVERLAYSURFACE
* DDERR_OUTOFCAPS
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_XALIGN

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)