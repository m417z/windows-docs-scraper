# GetMapMode function

## Description

The **GetMapMode** function retrieves the current mapping mode.

## Parameters

### `hdc` [in]

A handle to the device context.

## Return value

If the function succeeds, the return value specifies the mapping mode.

If the function fails, the return value is zero.

## Remarks

The following are the various mapping modes.

| Mode | Description |
| --- | --- |
| MM_ANISOTROPIC | Logical units are mapped to arbitrary units with arbitrarily scaled axes. Use the [SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex) and [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) functions to specify the units, orientation, and scaling required. |
| MM_HIENGLISH | Each logical unit is mapped to 0.001 inch. Positive x is to the right; positive y is up. |
| MM_HIMETRIC | Each logical unit is mapped to 0.01 millimeter. Positive x is to the right; positive y is up. |
| MM_ISOTROPIC | Logical units are mapped to arbitrary units with equally scaled axes; that is, one unit along the x-axis is equal to one unit along the y-axis. Use the [SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex) and [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) functions to specify the units and the orientation of the axes. Graphics device interface makes adjustments as necessary to ensure the x and y units remain the same size. (When the windows extent is set, the viewport will be adjusted to keep the units isotropic). |
| MM_LOENGLISH | Each logical unit is mapped to 0.01 inch. Positive x is to the right; positive y is up. |
| MM_LOMETRIC | Each logical unit is mapped to 0.1 millimeter. Positive x is to the right; positive y is up. |
| MM_TEXT | Each logical unit is mapped to one device pixel. Positive x is to the right; positive y is down. |
| MM_TWIPS | Each logical unit is mapped to one twentieth of a printer's point (1/1440 inch, also called a "twip"). Positive x is to the right; positive y is up. |

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[SetMapMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmapmode)

[SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex)

[SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex)