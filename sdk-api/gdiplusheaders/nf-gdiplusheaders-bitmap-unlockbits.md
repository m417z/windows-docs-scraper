# Bitmap::UnlockBits

## Description

The **Bitmap::UnlockBits** method unlocks a portion of this bitmap that was previously locked by a call to [Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits).

## Parameters

### `lockedBitmapData` [in]

Type: **[BitmapData](https://learn.microsoft.com/previous-versions/ms534421(v=vs.85))***

Pointer to a
[BitmapData](https://learn.microsoft.com/previous-versions/ms534421(v=vs.85)) object that was previously passed to [Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

[Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits) and **Bitmap::UnlockBits** must be used as a pair. A call to the **Bitmap::LockBits** method of a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object establishes a temporary buffer that you can use to read or write pixel data in a specified format. After you write to the temporary buffer, a call to **Bitmap::UnlockBits** copies the pixel data in the buffer to the
**Bitmap** object. If the pixel format of the temporary buffer is different from the pixel format of the
**Bitmap** object, the pixel data is converted appropriately.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)