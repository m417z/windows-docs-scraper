## Description

The *DdGetScanLine* callback function returns the number of the current physical scan line.

## Parameters

### `unnamedParam1`

Points to a [DD_GETSCANLINEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getscanlinedata) structure in which the driver returns the number of the current scan line.

## Return value

*DdGetScanLine* returns one of the following callback codes:

## Remarks

If the monitor is not in vertical blank, the driver should write the scan line value in the **dwScanLine** member of the [DD_GETSCANLINEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getscanlinedata) structure at *pGetScanLine*. The number must be in the range [0, *n*], where scan line 0 is the first visible scan line and scan line *n* is the last visible scan line on the screen. The driver should then set DD_OK in the **ddRVal** member of **DD_GETSCANLINEDATA** and return DDHAL_DRIVER_HANDLED.

The scan line is indeterminate if a vertical blank is in progress. In this situation, the driver should set **ddRVal** to DDERR_VERTICALBLANKINPROGRESS and return DDHAL_DRIVER_HANDLED.

## See also

[DD_GETSCANLINEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_getscanlinedata)