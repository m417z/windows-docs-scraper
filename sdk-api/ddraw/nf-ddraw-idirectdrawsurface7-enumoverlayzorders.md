# IDirectDrawSurface7::EnumOverlayZOrders

## Description

Enumerates the overlay surfaces on the specified destination. You can enumerate the overlays in front-to-back or back-to-front order.

## Parameters

### `unnamedParam1` [in]

A value that can be set to one of the following flags:

#### DDENUMOVERLAYZ_BACKTOFRONT

Enumerates overlays back to front.

#### DDENUMOVERLAYZ_FRONTTOBACK

Enumerates overlays front to back.

### `unnamedParam2` [in]

Address of the user-defined structure to be passed to the callback function for each overlay surface.

### `unnamedParam3` [in]

Address of the [EnumSurfacesCallback7](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback7) callback function to be called for each surface to be overlaid on this surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

**EnumOverlayZOrders** differs from its counterparts in previous interface versions in that it accepts a pointer to an [EnumSurfacesCallback7](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback7) function, rather than an [EnumSurfacesCallback](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback) or [EnumSurfacesCallback2](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback2) function.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)