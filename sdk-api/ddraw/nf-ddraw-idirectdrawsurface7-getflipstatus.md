## Description

Retrieves status about whether this surface has finished its flipping process.

## Parameters

### `unnamedParam1` [in]

A value that can be set to one of the following flags:

#### DDGFS_CANFLIP

Inquires whether this surface can be flipped immediately, and returns DD_OK if the flip can be completed.

#### DDGFS_ISFLIPDONE

Inquires whether the flip has finished, and returns DD_OK if the last flip on this surface has completed.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return DDERR_WASSTILLDRAWING if the surface has not finished its flipping process, or one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDSURFACETYPE
* DDERR_SURFACEBUSY
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)