## Description

Retrieves the DirectDrawClipper object that is associated with this surface, and increments the reference count of the returned clipper.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable to receive a pointer to the clipper's [IDirectDrawClipper](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawclipper) interface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOCLIPPERATTACHED

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)