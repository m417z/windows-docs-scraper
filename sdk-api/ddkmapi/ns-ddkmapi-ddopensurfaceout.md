# DDOPENSURFACEOUT structure

## Description

The DDOPENSURFACEOUT structure contains a new DirectDrawSurface handle, if the **ddRVal** member of DDOPENSURFACEOUT is set to DD_OK. This new handle must be used on all subsequent calls that require a DirectDrawSurface handle.

## Members

### `ddRVal`

Specifies the location in which Microsoft DirectDraw writes the return value of the [DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi) function for [DD_DXAPI_OPENSURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550711(v=vs.85)) operations. A return code of DD_OK indicates success.

### `hSurface`

Handle to the new DirectDrawSurface object.

## See also

[DD_DXAPI_OPENSURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550711(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)