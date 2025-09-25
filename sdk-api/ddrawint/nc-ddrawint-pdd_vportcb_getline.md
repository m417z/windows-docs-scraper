## Description

The **DdVideoPortGetLine** callback function returns the current line number of the hardware video port.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTLINEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportlinedata) structure that contains the information required for the driver to determine and return the current line number for the specified hardware video port.

## Return value

**DdVideoPortGetLine** returns one of the following callback codes:

## Remarks

Drivers that set the DDVPCAPS_READBACKLINE flag in the **dwCaps** member of the [DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps) structure must implement **DdVideoPortGetLine**.

The driver should write the number of the current video line in the **dwLine** member of the [DD_GETVPORTLINEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportlinedata) structure at *lpGetLine*. The returned line number must be zero-based; that is, the first line of video is line 0, the second line of video is line 1, etc.

If the device is in a vertical blank, the driver should set DDERR_VERTICALBLANKINPROGRESS in the **ddRVal** member of [DD_GETVPORTLINEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportlinedata). If the query cannot be performed because the hardware video port is disabled, the driver should set DDERR_VIDEONOTACTIVE in **ddRVal**. In both of these failed cases, the driver should return DDHAL_DRIVER_HANDLED.

## See also

[DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps)

[DD_GETVPORTLINEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportlinedata)