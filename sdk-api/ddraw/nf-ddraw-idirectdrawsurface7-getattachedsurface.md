# IDirectDrawSurface7::GetAttachedSurface

## Description

Obtains the attached surface that has the specified capabilities, and increments the reference count of the retrieved interface.

## Parameters

### `unnamedParam1` [in]

A pointer to a [DDSCAPS2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550292(v=vs.85)) structure that indicates the hardware capabilities of the attached surface.

### `unnamedParam2` [out]

A pointer to a variable to receive a pointer to the retrieved surface's [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface. The retrieved surface is the one that matches the description, according to the *lpDDSCaps* parameter.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTFOUND
* DDERR_SURFACELOST

## Remarks

Attachments are used to connect multiple DirectDrawSurface objects into complex structures, like the complex structures required to support 3-D page flipping with z-buffers. **GetAttachedSurface** fails if more than one surface is attached that matches the capabilities requested. In this case, the application must use the [IDirectDrawSurface7::EnumAttachedSurfaces](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-enumattachedsurfaces) method to obtain the attached surfaces.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)