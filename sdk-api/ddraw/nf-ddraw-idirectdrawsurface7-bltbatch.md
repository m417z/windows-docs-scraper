# IDirectDrawSurface7::BltBatch

## Description

The **IDirectDrawSurface7::BltBatch** method is not currently implemented.

## Parameters

### `unnamedParam1` [in]

A pointer to the first [DDBLTBATCH](https://learn.microsoft.com/windows/desktop/api/ddraw/ns-ddraw-ddbltbatch) structure that defines the parameters for the bitblt operations.

### `unnamedParam2` [in]

Number of bitblt operations to be performed.

### `unnamedParam3` [in]

Currently not used and must be set to 0.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDCLIPLIST
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDRECT
* DDERR_NOALPHAHW
* DDERR_NOBLTHW
* DDERR_NOCLIPLIST
* DDERR_NODDROPSHW
* DDERR_NOMIRRORHW
* DDERR_NORASTEROPHW
* DDERR_NOROTATIONHW
* DDERR_NOSTRETCHHW
* DDERR_NOZBUFFERHW
* DDERR_SURFACEBUSY
* DDERR_SURFACELOST
* DDERR_UNSUPPORTED

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)