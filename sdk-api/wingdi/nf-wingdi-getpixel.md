# GetPixel function

## Description

The **GetPixel** function retrieves the red, green, blue (RGB) color value of the pixel at the specified coordinates.

## Parameters

### `hdc` [in]

A handle to the [device context](https://learn.microsoft.com/windows/win32/gdi/device-contexts).

### `x` [in]

The x-coordinate, in logical units, of the pixel to be examined.

### `y` [in]

The y-coordinate, in logical units, of the pixel to be examined.

## Return value

The return value is the [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that specifies the RGB of the pixel. If the pixel is outside of the current clipping region, the return value is CLR_INVALID (0xFFFFFFFF defined in Wingdi.h).

## Remarks

The pixel must be within the boundaries of the current clipping region.

Not all devices support **GetPixel**. An application should call [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) to determine whether a specified device supports this function.

A bitmap must be selected within the device context, otherwise, CLR_INVALID is returned on all pixels.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[SetPixel](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpixel)