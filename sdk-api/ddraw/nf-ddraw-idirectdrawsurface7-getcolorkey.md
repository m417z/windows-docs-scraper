# IDirectDrawSurface7::GetColorKey

## Description

Retrieves the color key value for this surface.

## Parameters

### `unnamedParam1` [in]

A value that can be set to one of the following flags to specify the color key to retrieve:

#### DDCKEY_DESTBLT

A color key or color space to be used as a destination color key for bit block transfer (bitblt) operations.

#### DDCKEY_DESTOVERLAY

A color key or color space to be used as a destination color key for overlay operations.

#### DDCKEY_SRCBLT

A color key or color space to be used as a source color key for bitblt operations.

#### DDCKEY_SRCOVERLAY

A color key or color space to be used as a source color key for overlay operations.

### `unnamedParam2` [out]

A pointer to a [DDCOLORKEY](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddcolorkey) structure that receives the current values for the specified color key of the DirectDrawSurface object.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOCOLORKEY
* DDERR_NOCOLORKEYHW
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)