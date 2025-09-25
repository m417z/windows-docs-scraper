## Description

Creates a GDI-compatible handle of a device context for this surface.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the handle of the device context for this surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_DCALREADYCREATED
* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDSURFACETYPE
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

**GetDC** uses an internal version of the [IDirectDrawSurface7::Lock](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-lock) method to lock the surface. The surface remains locked until the [IDirectDrawSurface7::ReleaseDC](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-releasedc) method is called.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

