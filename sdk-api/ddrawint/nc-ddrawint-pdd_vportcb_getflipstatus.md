## Description

The *DdVideoPortGetFlipStatus* callback function determines whether the most recently requested flip on a surface has occurred.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTFLIPSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportflipstatusdata) structure that contains the information required for the driver to determine a surface's flip status.

## Return value

*DdVideoPortGetFlipStatus* returns one of the following callback codes:

## Remarks

DirectDraw drivers that support VPE must implement *DdVideoPortGetFlipStatus*.

The driver should set the **ddRVal** member of the [DD_GETVPORTFLIPSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportflipstatusdata) structure at *lpGetFlipStatus* to DDERR_WASSTILLDRAWING and return DDHAL_DRIVER_HANDLED if a flip is currently in progress; otherwise the driver should set **ddRVal** to DD_OK and return DDHAL_DRIVER_HANDLED.

If the driver sets **ddRVal** to DDERR_WASSTILLDRAWING, DirectDraw will fail locks and blits on that surface.

## See also

[DD_GETVPORTFLIPSTATUSDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportflipstatusdata)