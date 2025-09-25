# FloodFill function

## Description

The **FloodFill** function fills an area of the display surface with the current brush. The area is assumed to be bounded as specified by the *color* parameter.

**Note** The **FloodFill** function is included only for compatibility with 16-bit versions of Windows. Applications should use the [ExtFloodFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extfloodfill) function with FLOODFILLBORDER specified.

## Parameters

### `hdc` [in]

A handle to a device context.

### `x` [in]

The x-coordinate, in logical units, of the point where filling is to start.

### `y` [in]

The y-coordinate, in logical units, of the point where filling is to start.

### `color` [in]

The color of the boundary or the area to be filled. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The following are reasons this function might fail:

* The fill could not be completed.
* The given point has the boundary color specified by the *color* parameter.
* The given point lies outside the current clipping region, that is, it is not visible on the device.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[ExtFloodFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extfloodfill)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)