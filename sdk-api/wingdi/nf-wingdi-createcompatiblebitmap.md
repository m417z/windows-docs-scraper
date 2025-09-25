# CreateCompatibleBitmap function

## Description

The **CreateCompatibleBitmap** function creates a bitmap compatible with the device that is associated with the specified device context.

## Parameters

### `hdc` [in]

A handle to a device context.

### `cx` [in]

The bitmap width, in pixels.

### `cy` [in]

The bitmap height, in pixels.

## Return value

If the function succeeds, the return value is a handle to the compatible bitmap (DDB).

If the function fails, the return value is **NULL**.

## Remarks

The color format of the bitmap created by the **CreateCompatibleBitmap** function matches the color format of the device identified by the *hdc* parameter. This bitmap can be selected into any memory device context that is compatible with the original device.

Because memory device contexts allow both color and monochrome bitmaps, the format of the bitmap returned by the **CreateCompatibleBitmap** function differs when the specified device context is a memory device context. However, a compatible bitmap that was created for a nonmemory device context always possesses the same color format and uses the same color palette as the specified device context.

Note: When a memory device context is created, it initially has a 1-by-1 monochrome bitmap selected into it. If this memory device context is used in **CreateCompatibleBitmap**, the bitmap that is created is a *monochrome* bitmap. To create a color bitmap, use the **HDC** that was used to create the memory device context, as shown in the following code:

```cpp

    HDC memDC = CreateCompatibleDC ( hDC );
    HBITMAP memBM = CreateCompatibleBitmap ( hDC, nWidth, nHeight );
    SelectObject ( memDC, memBM );

```

If an application sets the *nWidth* or *nHeight* parameters to zero, **CreateCompatibleBitmap** returns the handle to a 1-by-1 pixel, monochrome bitmap.

If a DIB section, which is a bitmap created by the [CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection) function, is selected into the device context identified by the *hdc* parameter, **CreateCompatibleBitmap** creates a DIB section.

When you no longer need the bitmap, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

#### Examples

For an example, see [Scaling an Image](https://learn.microsoft.com/windows/desktop/gdi/scaling-an-image).

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateDIBSection](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibsection)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)