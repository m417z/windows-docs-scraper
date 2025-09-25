# IDirectDrawSurface7::BltFast

## Description

Performs a source copy bitblt or transparent bitblt by using a source color key or destination color key.

## Parameters

### `unnamedParam1` [in]

The x-coordinate to bitblt to on the destination surface.

### `unnamedParam2` [in]

The y-coordinate to bitblt to on the destination surface.

### `unnamedParam3` [in]

A pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the DirectDrawSurface object that is the source of the bitblt.

### `unnamedParam4` [in]

A pointer to a **RECT** structure that defines the upper-left and lower-right points of the rectangle to bitblt from on the source surface.

### `unnamedParam5` [in]

Type of transfer. The following transfers are defined:

#### DDBLTFAST_DESTCOLORKEY

A transparent bitblt that uses the destination color key.

#### DDBLTFAST_NOCOLORKEY

A normal copy bitblt with no transparency.

#### DDBLTFAST_SRCCOLORKEY

A transparent bitblt that uses the source color key.

#### DDBLTFAST_WAIT

Postpones the DDERR_WASSTILLDRAWING message if the bitbltter is busy, and returns as soon as the bitblt can be set up or another error occurs.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_EXCEPTION
* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDRECT
* DDERR_NOBLTHW
* DDERR_SURFACEBUSY
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

**BltFast** always attempts an asynchronous blit if it is supported by the hardware.

**BltFast** works only on display memory surfaces and cannot clip when it performs a bitblt operation. If you use this method on a surface with an attached clipper, the call fails, and the method returns DDERR_UNSUPPORTED.

The software implementation of **IDirectDrawSurface7::BltFast** is 10 percent faster than the [IDirectDrawSurface7::Blt](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-blt) method. However, there is no speed difference between the two if display hardware is used.

Typically, **IDirectDrawSurface7::BltFast** returns immediately with an error if the bitbltter is busy and the bitblt cannot be set up. You can use the DDBLTFAST_WAIT flag, however, if you want this method not to return until either the bitblt can be set up or another error occurs.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)