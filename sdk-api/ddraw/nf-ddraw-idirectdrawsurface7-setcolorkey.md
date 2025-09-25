# IDirectDrawSurface7::SetColorKey

## Description

Sets the color key value for the DirectDrawSurface object if the hardware supports color keys on a per-surface basis.

## Parameters

### `unnamedParam1` [in]

A value that can be set to one of the following flags to specify the requested color key:

#### DDCKEY_COLORSPACE

The structure contains a color space. Not set if the structure contains a single color key.

#### DDCKEY_DESTBLT

A color key or color space to be used as a destination color key for bit block transfer (bitblt) operations.

#### DDCKEY_DESTOVERLAY

A color key or color space to be used as a destination color key for overlay operations.

#### DDCKEY_SRCBLT

A color key or color space to be used as a source color key for bitblt operations.

#### DDCKEY_SRCOVERLAY

A color key or color space to be used as a source color key for overlay operations.

### `unnamedParam2` [in]

A pointer to a [DDCOLORKEY](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcolorkey) structure that contains the new color key values for the DirectDrawSurface object. This value can be NULL to remove a previously set color key.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDSURFACETYPE
* DDERR_NOOVERLAYHW
* DDERR_NOTAOVERLAYSURFACE
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

For transparent bitblt operations and overlays, set destination color on the destination surface and source color on the source surface.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)