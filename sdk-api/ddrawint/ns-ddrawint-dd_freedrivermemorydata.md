# DD_FREEDRIVERMEMORYDATA structure

## Description

The DD_FREEDRIVERMEMORYDATA structure contains the details of the free request.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to the [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure representing the surface that Microsoft DirectDraw is attempting to allocate.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdFreeDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_freedrivermemory) callback. A return code of DD_OK indicates that the driver succeeded in freeing some space; otherwise, the driver should set this to be DDERR_OUTOFMEMORY. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `FreeDriverMemory`

Used by the DirectDraw API and should not be filled in by the driver.

## See also

[DdFreeDriverMemory](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_freedrivermemory)