# DD_DESTROYSURFACEDATA structure

## Description

The DD_DESTROYSURFACEDATA structure contains information necessary to destroy the specified surface--in the case of [DestroyD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552754(v=vs.85)), a command or vertex buffer.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure representing the surface or buffer object to be destroyed.

### `ddRVal`

Specifies the location in which the driver writes the return value of either the [DdDestroySurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_destroysurface) or [DestroyD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552754(v=vs.85)) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `DestroySurface`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdDestroySurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_destroysurface)

[DestroyD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552754(v=vs.85))