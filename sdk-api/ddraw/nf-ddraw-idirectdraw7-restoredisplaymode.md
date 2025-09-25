# IDirectDraw7::RestoreDisplayMode

## Description

Resets the mode of the display device hardware for the primary surface to what it was before the [IDirectDraw7::SetDisplayMode](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-setdisplaymode) method was called. Exclusive-level access is required to use this method.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_LOCKEDSURFACES
* DDERR_NOEXCLUSIVEMODE

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)