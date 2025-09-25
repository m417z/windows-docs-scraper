## Description

The *DdBlt* callback function performs a bit-block transfer.

## Parameters

### `unnamedParam1`

Points to the [DD_BLTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_bltdata) structure that contains the information required for the driver to perform the blit.

## Return value

*DdBlt* returns one of the following callback codes:

## Remarks

*DdBlt* can be optionally implemented in DirectDraw drivers.

Before performing the bit block transfer, the driver should ensure that a flip involving the destination surface is not in progress. If the destination surface is involved in a flip, the driver should set the **ddRVal** member of the DD_BLTDATA structure at *lpBlt* to DDERR_WASSTILLDRAWING and return DDHAL_DRIVER_HANDLED.

The driver should check **dwFlags** to determine the type of blit operation to perform. The driver should not check for flags that are undocumented.

When performing transparent (color keyed) blts, drivers should ignore any unused pixel bits in their comparisons. (For instance in 32bpp modes, the high byte is typically unused. This byte should not be used in the color key comparison.)

## See also

[DD_BLTDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_bltdata)