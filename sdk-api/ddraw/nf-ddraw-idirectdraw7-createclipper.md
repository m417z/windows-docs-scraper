# IDirectDraw7::CreateClipper

## Description

Creates a DirectDrawClipper object.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

### `unnamedParam2` [out]

Address of a variable to be set to a valid [IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper) interface pointer if the call succeeds.

### `unnamedParam3` [in]

Allows for future compatibility with COM aggregation features. Currently this method returns an error if this parameter is not NULL.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOCOOPERATIVELEVELSET
* DDERR_OUTOFMEMORY

## Remarks

The DirectDrawClipper object can be attached to a DirectDrawSurface and used during [IDirectDrawSurface7::Blt](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-blt), [IDirectDrawSurface7::BltBatch](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-bltbatch), and [IDirectDrawSurface7::UpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-updateoverlay) operations.

To create a DirectDrawClipper object that is not owned by a specific DirectDraw object, use the [DirectDrawCreateClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-directdrawcreateclipper) function.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)