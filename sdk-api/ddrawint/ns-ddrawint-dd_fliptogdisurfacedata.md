# DD_FLIPTOGDISURFACEDATA structure

## Description

The DD_FLIPTOGDISURFACEDATA structure contains the GDI surface notification information.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `dwToGDI`

Indicates that Microsoft DirectDraw is flipping to a GDI surface when **TRUE**; indicates that DirectDraw is flipping from a GDI surface when **FALSE**.

### `dwReserved`

Reserved for system use and should be ignored by the driver.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdFlipToGDISurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_fliptogdisurface) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `FlipToGDISurface`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdFlipToGDISurface](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_fliptogdisurface)