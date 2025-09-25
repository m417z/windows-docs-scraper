# IDirectDrawSurface7::SetSurfaceDesc

## Description

Sets the characteristics of an existing surface.

## Parameters

### `unnamedParam1` [in]

A pointer to a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that contains the new surface characteristics.

### `unnamedParam2` [in]

Currently not used and must be set to 0.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDPARAMS
* DDERR_INVALIDOBJECT
* DDERR_SURFACELOST
* DDERR_SURFACEBUSY
* DDERR_INVALIDSURFACETYPE
* DDERR_INVALIDPIXELFORMAT
* DDERR_INVALIDCAPS
* DDERR_UNSUPPORTED
* DDERR_GENERIC

## Remarks

Currently, you can use **SetSurfaceDesc** only to set the surface data and pixel format that is used by an explicit system-memory surface. This is useful because it allows a surface to use data from a previously allocated buffer without copying. The new surface memory is allocated by the client application, and therefore the client application must also deallocate it.

The DirectDrawSurface object does not deallocate surface memory that it did not allocate. Therefore, when the surface memory is no longer needed, you must deallocate it. However, when you call **SetSurfaceDesc**, DirectDraw frees the original surface memory that it implicitly allocated when it created the surface.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)