## Description

Obtains status about a bit block transfer (bitblt) operation.

## Parameters

### `unnamedParam1` [in]

A value that can be set to one of the following flags.

#### DDGBS_CANBLT

Inquires whether a bitblt that involves this surface can occur immediately, and returns DD_OK if the bitblt can be completed.

#### DDGBS_ISBLTDONE

Inquires whether the bitblt is done, and returns DD_OK if the last bitblt on this surface has completed.

## Return value

If the method succeeds, a bitbltter is present, and the return value is DD_OK.

If it fails, the method returns DDERR_WASSTILLDRAWING if the bitbltter is busy, DDERR_NOBLTHW if there is no bitbltter, or one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOBLTHW
* DDERR_SURFACEBUSY
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED
* DDERR_WASSTILLDRAWING

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)