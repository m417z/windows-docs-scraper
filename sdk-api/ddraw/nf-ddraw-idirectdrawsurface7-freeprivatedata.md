## Description

Frees the specified private data that is associated with this surface.

## Parameters

### `unnamedParam1` [in]

Reference to (C++) or address of (C) the globally unique identifier that identifies the private data to be freed.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTFOUND

## Remarks

DirectDraw calls this method automatically when a surface is released.

If the private data was set by using the DDSPD_IUNKNOWNPOINTER flag, **FreePrivateData** calls the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the associated interface.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)