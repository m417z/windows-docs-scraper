# DDOPENSURFACEIN structure

## Description

The DDOPENSURFACEIN structure contains the DirectDrawSurface object information.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw object to which the surface handle is associated.

### `dwSurfaceHandle`

Specifies the DirectDrawSurface handle passed down from user mode.

### `pfnSurfaceClose`

Points to a [pfnSurfaceClose](https://learn.microsoft.com/windows/desktop/api/ddkmapi/nc-ddkmapi-lpdd_notifycallback) callback function that is called when the surface becomes unusable.

### `pContext`

Contains a value that is passed if the **pfnSurfaceClose** callback function is ever called.

## See also

[DD_DXAPI_OPENSURFACE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550711(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)