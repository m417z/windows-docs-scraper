# IDirectDrawSurface7::EnumAttachedSurfaces

## Description

Enumerates all the surfaces that are attached to this surface.

## Parameters

### `unnamedParam1` [in]

Address of the application-defined structure that is passed to the enumeration member every time that it is called.

### `unnamedParam2` [in]

Address of the [EnumSurfacesCallback7](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback7) function to be called for each surface that is attached to this surface.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_SURFACELOST

## Remarks

**EnumAttachedSurfaces** enumerates only those surfaces that are directly attached to this surface. For example, in a flipping chain of three or more surfaces, only one surface is enumerated because each surface is attached only to the next surface in the flipping chain. In such a configuration, you can call **EnumAttachedSurfaces** on each successive surface to walk the entire flipping chain.

**EnumAttachedSurfaces** differs from its counterparts in previous interface versions in that it accepts a pointer to an [EnumSurfacesCallback7](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback7) function, rather than an [EnumSurfacesCallback](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback) or [EnumSurfacesCallback2](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback2) function.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)