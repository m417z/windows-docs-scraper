# IDirectDraw7::CreateSurface

## Description

Creates a DirectDrawSurface object for this DirectDraw object.

## Parameters

### `unnamedParam1` [in]

Address of a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that describes the requested surface. Set any unused members of the **DDSURFACEDESC2** structure to 0 before calling this method. A [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure is a member of **DDSURFACEDESC2**.

### `unnamedParam2` [out]

Address of a variable to be set to a valid [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface pointer if the call succeeds.

### `unnamedParam3` [in]

Allows for future compatibility with COM aggregation features. Currently, this method returns an error if this parameter is not NULL.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INCOMPATIBLEPRIMARY
* DDERR_INVALIDCAPS
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_INVALIDPIXELFORMAT
* DDERR_NOALPHAHW
* DDERR_NOCOOPERATIVELEVELSET
* DDERR_NODIRECTDRAWHW
* DDERR_NOEMULATION
* DDERR_NOEXCLUSIVEMODE
* DDERR_NOFLIPHW
* DDERR_NOMIPMAPHW
* DDERR_NOOVERLAYHW
* DDERR_NOZBUFFERHW
* DDERR_OUTOFMEMORY
* DDERR_OUTOFVIDEOMEMORY
* DDERR_PRIMARYSURFACEALREADYEXISTS
* DDERR_UNSUPPORTEDMODE

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)