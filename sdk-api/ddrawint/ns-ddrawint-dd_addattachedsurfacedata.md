# DD_ADDATTACHEDSURFACEDATA structure

## Description

The DD_ADDATTACHEDSURFACEDATA structure contains information necessary to attach a surface to another surface.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that represents the surface to which another surface is being attached.

### `lpSurfAttached`

Points to a DD_SURFACE_LOCAL structure that represents the surface to be attached.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdAddAttachedSurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_addattachedsurface) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `AddAttachedSurface`

Unused on Microsoft Windows 2000 and later.

## See also

[DdAddAttachedSurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_addattachedsurface)