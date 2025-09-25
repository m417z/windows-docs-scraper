# CreateBitmapIndirect function

## Description

The **CreateBitmapIndirect** function creates a bitmap with the specified width, height, and color format (color planes and bits-per-pixel).

## Parameters

### `pbm` [in]

A pointer to a [BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap) structure that contains information about the bitmap. If an application sets the **bmWidth** or **bmHeight** members to zero, **CreateBitmapIndirect** returns the handle to a 1-by-1 pixel, monochrome bitmap.

## Return value

If the function succeeds, the return value is a handle to the bitmap.

If the function fails, the return value is **NULL**.

This function can return the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the input parameters is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The bitmap is too big for memory to be allocated. |

## Remarks

The **CreateBitmapIndirect** function creates a device-dependent bitmap.

After a bitmap is created, it can be selected into a device context by calling the [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) function. However, the bitmap can only be selected into a device context if the bitmap and the DC have the same format.

While the **CreateBitmapIndirect** function can be used to create color bitmaps, for performance reasons applications should use **CreateBitmapIndirect** to create monochrome bitmaps and [CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap) to create color bitmaps. Whenever a color bitmap from **CreateBitmapIndirect** is selected into a device context, the system must ensure that the bitmap matches the format of the device context it is being selected into. Because **CreateCompatibleBitmap** takes a device context, it returns a bitmap that has the same format as the specified device context. Thus, subsequent calls to [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) are faster with a color bitmap from **CreateCompatibleBitmap** than with a color bitmap returned from **CreateBitmapIndirect**.

If the bitmap is monochrome, zeros represent the foreground color and ones represent the background color for the destination device context.

When you no longer need the bitmap, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

## See also

[BITMAP](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmap)

[BitBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-bitblt)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createbitmap)

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[CreateDIBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdibitmap)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)