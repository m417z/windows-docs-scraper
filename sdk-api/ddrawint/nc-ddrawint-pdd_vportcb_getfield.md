## Description

The **DdVideoPortGetField** callback function determines whether the current field of an interlaced signal is even or odd.

## Parameters

### `unnamedParam1`

Points to a [DD_GETVPORTFIELDDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportfielddata) structure that contains the information required for the driver to determine whether the current field is even or odd.

## Return value

**DdVideoPortGetField** returns one of the following callback codes:

## Remarks

DirectDraw drivers that set the DDVPCAPS_READBACKFIELD flag in the **dwCaps** member of the [DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps) structure must implement **DdVideoPortGetField**.

The driver should determine whether the current field is even or odd and write **TRUE** or **FALSE** in the **bField** member of the DD_GETVPORTFIELDDATA structure at **lpGetField**, accordingly. If the query cannot be performed because the hardware video port is disabled, the driver should return DDHAL_DRIVER_HANDLED and set DDERR_VIDEONOTACTIVE in the **ddRVal** member of DD_GETVPORTFIELDDATA.

## See also

[DDVIDEOPORTCAPS](https://learn.microsoft.com/windows/desktop/api/dvp/ns-dvp-ddvideoportcaps)

[DD_GETVPORTFIELDDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getvportfielddata)