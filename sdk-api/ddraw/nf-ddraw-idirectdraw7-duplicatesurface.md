# IDirectDraw7::DuplicateSurface

## Description

Duplicates a DirectDrawSurface object.

## Parameters

### `unnamedParam1` [in]

Address of the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the surface to be duplicated.

### `unnamedParam2` [out]

Address of a variable to contain an [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface pointer for the newly duplicated DirectDrawSurface object.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_CANTDUPLICATE
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY
* DDERR_SURFACELOST

## Remarks

**DuplicateSurface** creates a new DirectDrawSurface object that points to the same surface memory as an existing DirectDrawSurface object. This duplicate can be used just like the original object. The surface memory is released after the last object referring to it is released. A primary surface, 3-D surface, or implicitly created surface cannot be duplicated.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)