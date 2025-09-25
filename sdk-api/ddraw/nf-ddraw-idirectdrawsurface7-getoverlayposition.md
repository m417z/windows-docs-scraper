# IDirectDrawSurface7::GetOverlayPosition

## Description

Retrieves the display coordinates of this surface. This method is used on a visible, active overlay surface (that is, a surface that has the DDSCAPS_OVERLAY flag set).

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the x- display coordinate of this surface if the call succeeds.

### `unnamedParam2` [out]

A pointer to a variable that receives the y-display coordinate of this surface if the call succeeds.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDPOSITION
* DDERR_NOOVERLAYDEST
* DDERR_NOTAOVERLAYSURFACE
* DDERR_OVERLAYNOTVISIBLE
* DDERR_SURFACELOST

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)