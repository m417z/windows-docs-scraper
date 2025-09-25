# SetPixelV function

## Description

The **SetPixelV** function sets the pixel at the specified coordinates to the closest approximation of the specified color. The point must be in the clipping region and the visible part of the device surface.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The x-coordinate, in logical units, of the point to be set.

### `y` [in]

The y-coordinate, in logical units, of the point to be set.

### `color` [in]

The color to be used to paint the point. To create a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) color value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Not all devices support the **SetPixelV** function. For more information, see the description of the RC_BITBLT capability in the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function.

**SetPixelV** is faster than [SetPixel](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixel) because it does not need to return the color value of the point actually painted.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SetPixel](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixel)