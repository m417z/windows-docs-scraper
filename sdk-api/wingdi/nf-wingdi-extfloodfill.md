# ExtFloodFill function

## Description

The **ExtFloodFill** function fills an area of the display surface with the current brush.

## Parameters

### `hdc` [in]

A handle to a device context.

### `x` [in]

The x-coordinate, in logical units, of the point where filling is to start.

### `y` [in]

The y-coordinate, in logical units, of the point where filling is to start.

### `color` [in]

The color of the boundary or of the area to be filled. The interpretation of *color* depends on the value of the *fuFillType* parameter. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `type` [in]

The type of fill operation to be performed. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **FLOODFILLBORDER** | The fill area is bounded by the color specified by the *color* parameter. This style is identical to the filling performed by the [FloodFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-floodfill) function. |
| **FLOODFILLSURFACE** | The fill area is defined by the color that is specified by *color*. Filling continues outward in all directions as long as the color is encountered. This style is useful for filling areas with multicolored boundaries. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The following are some of the reasons this function might fail:

* The filling could not be completed.
* The specified point has the boundary color specified by the *color* parameter (if FLOODFILLBORDER was requested).
* The specified point does not have the color specified by *color* (if FLOODFILLSURFACE was requested).
* The point is outside the clipping region, that is, it is not visible on the device.

If the *fuFillType* parameter is FLOODFILLBORDER, the system assumes that the area to be filled is completely bounded by the color specified by the *color* parameter. The function begins filling at the point specified by the *nXStart* and *nYStart* parameters and continues in all directions until it reaches the boundary.

If *fuFillType* is FLOODFILLSURFACE, the system assumes that the area to be filled is a single color. The function begins to fill the area at the point specified by *nXStart* and *nYStart* and continues in all directions, filling all adjacent regions containing the color specified by *color*.

Only memory device contexts and devices that support raster-display operations support the **ExtFloodFill** function. To determine whether a device supports this technology, use the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function.

#### Examples

For an example, see "Adding Lines and Graphs to a Menu" in [Using Menus](https://learn.microsoft.com/windows/desktop/menurc/using-menus).

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[FloodFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-floodfill)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)