## Description

Retrieves the DirectDrawSurface object that currently represents the surface memory that GDI is treating as the primary surface.

## Parameters

### `unnamedParam1` [out]

Address of a variable to be filled with a pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the surface that currently controls the GDI's primary surface memory.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTFOUND

## Remarks

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)