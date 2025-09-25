# DD_SETOVERLAYPOSITIONDATA structure

## Description

The DD_SETOVERLAYPOSITIONDATA structure contains information necessary to change the display coordinates of an overlay surface.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSrcSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that represents the Microsoft DirectDraw overlay surface.

### `lpDDDestSurface`

Points to a DD_SURFACE_LOCAL structure representing the surface that is being overlaid.

### `lXPos`

Specifies the x-coordinate of the upper left corner of the overlay, in pixels.

### `lYPos`

Specifies the y coordinate of the upper left corner of the overlay, in pixels.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdSetOverlayPosition](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setoverlayposition) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `SetOverlayPosition`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdSetOverlayPosition](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setoverlayposition)