# DD_GETSCANLINEDATA structure

## Description

The DD_GETSCANLINEDATA structure contains the members required to query and return the number of the current scan line.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `dwScanLine`

Specifies the location in which the driver returns the number of the current scan line. See the Remarks section for more information.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdGetScanLine](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getscanline) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `GetScanLine`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## Remarks

The returned scan line value in **dwScanLine** must be greater than or equal to 0 and less than N, where N is the sum of the number of visible scan lines and the number of scan lines that occur during vertical blank. For example, with a display operating at a resolution of 640x480, that has 12 scan lines during vertical blank, the value returned to **GetScanLine** could range from 0 to 491.

## See also

[DdGetScanLine](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getscanline)