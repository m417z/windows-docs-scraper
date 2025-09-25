# DD_UNLOCKDATA structure

## Description

The DD_UNLOCKDATA structure contains information necessary to do an unlock as defined by Microsoft DirectDraw parameter structures.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that describes the surface--in the case of [UnlockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570106(v=vs.85)), a buffer--to be unlocked.

### `ddRVal`

Specifies the location in which the driver writes the return value of either the [DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock) or [UnlockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570106(v=vs.85)) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `Unlock`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdUnlock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_unlock)

[UnlockD3DBuffer](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff570106(v=vs.85))