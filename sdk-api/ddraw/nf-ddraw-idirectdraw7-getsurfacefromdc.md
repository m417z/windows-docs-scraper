# IDirectDraw7::GetSurfaceFromDC

## Description

Retrieves the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for a surface, based on its GDI device context handle.

## Parameters

### `unnamedParam1` [in]

Handle of a display device context.

### `unnamedParam2` [out]

Address of a variable to be filled with a pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the surface if the call succeeds.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_GENERIC
* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY
* DDERR_NOTFOUND

## Remarks

This method succeeds only for device context handles that identify surfaces already associated with the DirectDraw object.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)