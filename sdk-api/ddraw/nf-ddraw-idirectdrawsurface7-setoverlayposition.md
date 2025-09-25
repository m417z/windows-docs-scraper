# IDirectDrawSurface7::SetOverlayPosition

## Description

Changes the display coordinates of an overlay surface.

## Parameters

### `unnamedParam1` [in]

The new x- display coordinate of this surface.

### `unnamedParam2` [in]

The new y-display coordinate of this surface.

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
* DDERR_UNSUPPORTED

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)