## Description

Attaches the specified z-buffer surface to this surface.

## Parameters

### `unnamedParam1` [in]

Address of the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the surface to be attached.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_CANNOTATTACHSURFACE
* DDERR_GENERIC
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_SURFACEALREADYATTACHED
* DDERR_SURFACELOST
* DDERR_WASSTILLDRAWING

## Remarks

**AddAttachedSurface** increments the reference count of the surface being attached. You can explicitly unattach the surface and decrement its reference count by using the [IDirectDrawSurface7::DeleteAttachedSurface](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-deleteattachedsurface) method. Unlike complex surfaces that you create with a single call to [IDirectDraw7::CreateSurface](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdraw7-createsurface), surfaces attached with this method are not automatically released. The application must release such surfaces.

You can attach only z-buffer surfaces with this method.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

