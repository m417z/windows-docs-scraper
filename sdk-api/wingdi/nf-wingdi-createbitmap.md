## Description

The **CreateBitmap** function creates a bitmap with the specified width, height, and color format (color planes and bits-per-pixel).

## Parameters

### `nWidth` [in]

The bitmap width, in pixels.

### `nHeight` [in]

The bitmap height, in pixels.

### `nPlanes` [in]

The number of color planes used by the device.

### `nBitCount` [in]

The number of bits required to identify the color of a single pixel.

### `lpBits` [in]

A pointer to an array of color data used to set the colors in a rectangle of pixels. Each scan line in the rectangle must be word aligned (scan lines that are not word aligned must be padded with zeros). The buffer size expected, *cj*, can be calculated using the formula:

```cpp
cj = (((nWidth * nPlanes * nBitCount + 15) >> 4) << 1) * nHeight;
```

If this parameter is **NULL**, then the contents of the new bitmap are undefined.

## Return value

If the function succeeds, the return value is a handle to a bitmap.

If the function fails, the return value is **NULL**.

This function can return the following value.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_BITMAP** | The calculated size of the bitmap is less than zero. |

## Remarks

The **CreateBitmap** function creates a device-dependent bitmap.

After a bitmap is created, it can be selected into a device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function. However, the bitmap can only be selected into a device context if the bitmap and the DC have the same format.

The **CreateBitmap** function can be used to create color bitmaps. However, for performance reasons applications should use **CreateBitmap** to create monochrome bitmaps and [CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap) to create color bitmaps. Whenever a color bitmap returned from **CreateBitmap** is selected into a device context, the system checks that the bitmap matches the format of the device context it is being selected into. Because **CreateCompatibleBitmap** takes a device context, it returns a bitmap that has the same format as the specified device context. Thus, subsequent calls to [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) are faster with a color bitmap from **CreateCompatibleBitmap** than with a color bitmap returned from **CreateBitmap**.

If the bitmap is monochrome, zeros represent the foreground color and ones represent the background color for the destination device context.

If an application sets the *nWidth* or *nHeight* parameters to zero, **CreateBitmap** returns the handle to a 1-by-1 pixel, monochrome bitmap.

When you no longer need the bitmap, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateBitmapIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmapindirect)

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GetBitmapBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbitmapbits)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetBitmapBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbitmapbits)