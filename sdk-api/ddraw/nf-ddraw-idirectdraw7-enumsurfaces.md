# IDirectDraw7::EnumSurfaces

## Description

Enumerates all the existing or possible surfaces that meet the specified surface description.

## Parameters

### `unnamedParam1` [in]

A combination of one search type flag and one matching flag. The search type flag determines how the method searches for matching surfaces; you can search for surfaces that can be created using the description in the *lpDDSD2* parameter or for existing surfaces that already match that description. The matching flag determines whether the method enumerates all surfaces, only those that match, or only those that do not match the description in the *lpDDSD2* parameter.

**Search type flags**

#### DDENUMSURFACES_CANBECREATED

Enumerates the first surface that can be created and meets the search criterion. This flag can be used only with the DDENUMSURFACES_MATCH flag.

#### DDENUMSURFACES_DOESEXIST

Enumerates the already existing surfaces that meet the search criterion.

**Matching flags**

#### DDENUMSURFACES_ALL

Enumerates all surfaces that meet the search criterion. This flag can be used only with the DDENUMSURFACES_DOESEXIST search type flag.

#### DDENUMSURFACES_MATCH

Searches for any surface that matches the surface description.

#### DDENUMSURFACES_NOMATCH

Searches for any surface that does not match the surface description.

### `unnamedParam2` [in]

Address of a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that defines the surface of interest. This parameter can be NULL if *dwFlags* includes the DDENUMSURFACES_ALL flag.

### `unnamedParam3` [in]

Address of an application-defined structure to be passed to each enumeration member.

### `unnamedParam4` [in]

Address of the [EnumSurfacesCallback7](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback7) function that the enumeration procedure calls every time a match is found.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS

## Remarks

If the DDENUMSURFACES_CANBECREATED flag is set, this method attempts to temporarily create a surface that meets the search criterion.

When you use the DDENUMSURFACES_DOESEXIST flag, an enumerated surface's reference count is incremented—if you are not going to use the surface, be sure to use [IDirectDrawSurface7::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release it after each enumeration. If you will be using the surface, release it when it is no longer needed.

This method differs from its counterparts in previous interface versions in that it accepts a pointer to an [EnumSurfacesCallback7](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback7) function, rather than an [EnumSurfacesCallback](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback) or [EnumSurfacesCallback2](https://learn.microsoft.com/windows/desktop/api/ddraw/nc-ddraw-lpddenumsurfacescallback2) function.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)