# SetMapMode function

## Description

The **SetMapMode** function sets the mapping mode of the specified device context. The mapping mode defines the unit of measure used to transform page-space units into device-space units, and also defines the orientation of the device's x and y axes.

## Parameters

### `hdc` [in]

A handle to the device context.

### `iMode` [in]

The new mapping mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MM_ANISOTROPIC** | Logical units are mapped to arbitrary units with arbitrarily scaled axes. Use the [SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex) and [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) functions to specify the units, orientation, and scaling. |
| **MM_HIENGLISH** | Each logical unit is mapped to 0.001 inch. Positive x is to the right; positive y is up. |
| **MM_HIMETRIC** | Each logical unit is mapped to 0.01 millimeter. Positive x is to the right; positive y is up. |
| **MM_ISOTROPIC** | Logical units are mapped to arbitrary units with equally scaled axes; that is, one unit along the x-axis is equal to one unit along the y-axis. Use the [SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex) and [SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex) functions to specify the units and the orientation of the axes. Graphics device interface (GDI) makes adjustments as necessary to ensure the x and y units remain the same size (When the window extent is set, the viewport will be adjusted to keep the units isotropic). |
| **MM_LOENGLISH** | Each logical unit is mapped to 0.01 inch. Positive x is to the right; positive y is up. |
| **MM_LOMETRIC** | Each logical unit is mapped to 0.1 millimeter. Positive x is to the right; positive y is up. |
| **MM_TEXT** | Each logical unit is mapped to one device pixel. Positive x is to the right; positive y is down. |
| **MM_TWIPS** | Each logical unit is mapped to one twentieth of a printer's point (1/1440 inch, also called a twip). Positive x is to the right; positive y is up. |

## Return value

If the function succeeds, the return value identifies the previous mapping mode.

If the function fails, the return value is zero.

## Remarks

The MM_TEXT mode allows applications to work in device pixels, whose size varies from device to device.

The MM_HIENGLISH, MM_HIMETRIC, MM_LOENGLISH, MM_LOMETRIC, and MM_TWIPS modes are useful for applications drawing in physically meaningful units (such as inches or millimeters).

The MM_ISOTROPIC mode ensures a 1:1 aspect ratio.

The MM_ANISOTROPIC mode allows the x-coordinates and y-coordinates to be adjusted independently.

#### Examples

For an example, see [Using Coordinate Spaces and Transformations](https://learn.microsoft.com/windows/desktop/gdi/using-coordinate-spaces-and-transformations).

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetMapMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getmapmode)

[SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex)

[SetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportorgex)

[SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex)

[SetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindoworgex)