# Bitmap::LockBits

## Description

The **Bitmap::LockBits** method locks a rectangular portion of this bitmap and provides a temporary buffer that you can use to read or write pixel data in a specified format. Any pixel data that you write to the buffer is copied to the
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object when you call [Bitmap::UnlockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-unlockbits).

## Parameters

### `rect` [in]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)***

Pointer to a rectangle that specifies the portion of the bitmap to be locked.

### `flags` [in]

Type: **UINT**

Set of flags that specify whether the locked portion of the bitmap is available for reading or for writing and whether the caller has already allocated a buffer. Individual flags are defined in the [ImageLockMode](https://learn.microsoft.com/windows/desktop/api/gdiplusimaging/ne-gdiplusimaging-imagelockmode) enumeration.

### `format` [in]

Type: **PixelFormat**

Integer that specifies the format of the pixel data in the temporary buffer. The pixel format of the temporary buffer does not have to be the same as the pixel format of this
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object. The
**PixelFormat** data type and constants that represent various pixel formats are defined in Gdipluspixelformats.h. For more information about pixel format constants, see [Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants). GDI+ version 1.0 does not support processing of 16-bits-per-channel images, so you should not set this parameter equal to PixelFormat48bppRGB, PixelFormat64bppARGB, or PixelFormat64bppPARGB.

### `lockedBitmapData` [in, out]

Type: **[BitmapData](https://learn.microsoft.com/previous-versions/ms534421(v=vs.85))***

Pointer to a [BitmapData](https://learn.microsoft.com/previous-versions/ms534421(v=vs.85)) object. If the ImageLockModeUserInputBuf flag of the
*flags* parameter is cleared, then
*lockedBitmapData* serves only as an output parameter. In that case, the
**Scan0** data member of the **BitmapData** object receives a pointer to a temporary buffer, which is filled with the values of the requested pixels. The other data members of the **BitmapData** object receive attributes (width, height, format, and stride) of the pixel data in the temporary buffer. If the pixel data is stored bottom-up, the
**Stride** data member is negative. If the pixel data is stored top-down, the
**Stride** data member is positive. If the ImageLockModeUserInputBuf flag of the
*flags* parameter is set, then
*lockedBitmapData* serves as an input parameter (and possibly as an output parameter). In that case, the caller must allocate a buffer for the pixel data that will be read or written. The caller also must create a **BitmapData** object, set the
**Scan0** data member of that **BitmapData** object to the address of the buffer, and set the other data members of the **BitmapData** object to specify the attributes (width, height, format, and stride) of the buffer.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the
**Status** enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap::UnlockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-unlockbits)

[BitmapData](https://learn.microsoft.com/previous-versions/ms534421(v=vs.85))

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants)

[ImageLockMode](https://learn.microsoft.com/windows/desktop/api/gdiplusimaging/ne-gdiplusimaging-imagelockmode)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)