# CreateDiscardableBitmap function

## Description

The **CreateDiscardableBitmap** function creates a discardable bitmap that is compatible with the specified device. The bitmap has the same bits-per-pixel format and the same color palette as the device. An application can select this bitmap as the current bitmap for a memory device that is compatible with the specified device.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Applications should use the [CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap) function.

## Parameters

### `hdc` [in]

A handle to a device context.

### `cx` [in]

The width, in pixels, of the bitmap.

### `cy` [in]

The height, in pixels, of the bitmap.

## Return value

If the function succeeds, the return value is a handle to the compatible bitmap (DDB).

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the bitmap, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

## See also

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateCompatibleBitmap](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createcompatiblebitmap)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)