## Description

The *EnumSurfacesCallback7* function is an application-defined callback function for the [IDirectDrawSurface7::EnumAttachedSurfaces](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-enumattachedsurfaces) and [IDirectDrawSurface7::EnumOverlayZOrders](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-enumoverlayzorders) methods.

## Parameters

### `unnamedParam1` [in]

A pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface of the attached surface.

### `unnamedParam2` [in]

A pointer to a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that describes the attached surface.

### `unnamedParam3` [in]

A pointer to an application-defined structure to be passed to the callback function each time that the function is called.

## Return value

The callback function returns DDENUMRET_OK to continue the enumeration.

It returns DDENUMRET_CANCEL to stop the enumeration.

## Remarks

You can use the LPDDENUMSURFACESCALLBACK7 data type to declare a variable that can contain a pointer to this callback function.