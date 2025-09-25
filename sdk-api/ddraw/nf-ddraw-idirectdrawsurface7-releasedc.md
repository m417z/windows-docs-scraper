## Description

Releases the handle of a device context that was previously obtained by using the [IDirectDrawSurface7::GetDC](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-getdc) method.

## Parameters

### `unnamedParam1` [in]

The handle of a device context that was previously obtained by [IDirectDrawSurface7::GetDC](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-getdc).

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED

## Remarks

**ReleaseDC** also unlocks the surface that was previously locked when the [IDirectDrawSurface7::GetDC](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-getdc) method was called.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)