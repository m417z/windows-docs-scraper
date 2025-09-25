# SetPixel function

## Description

The **SetPixel** function sets the pixel at the specified coordinates to the specified color.

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

If the function succeeds, the return value is the RGB value that the function sets the pixel to. This value may differ from the color specified by *crColor*; that occurs when an exact match for the specified color cannot be found.

If the function fails, the return value is -1.

This can be the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the input parameters is invalid. |

## Remarks

The function fails if the pixel coordinates lie outside of the current clipping region.

Not all devices support the **SetPixel** function. For more information, see [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps).

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetPixel](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpixel)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)

[SetPixelV](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixelv)