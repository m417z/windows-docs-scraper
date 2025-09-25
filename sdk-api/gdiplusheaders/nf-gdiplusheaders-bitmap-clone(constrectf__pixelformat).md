# Bitmap::Clone(IN const RectF &,IN PixelFormat)

## Description

The **Bitmap::Clone** method creates a new
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object by copying a portion of this bitmap.

## Parameters

### `rect` [in, ref]

Type: **const [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Reference to a rectangle that specifies the portion of this bitmap to be copied.

### `format` [in]

Type: **PixelFormat**

Integer that specifies the pixel format of the new bitmap. The
**PixelFormat** data type and constants that represent various pixel formats are defined in Gdipluspixelformats.h. For more information about pixel format constants, see [Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants).

## Return value

Type: **[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)***

This method returns a pointer to the new
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Clone](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-clone(inconstrectf__inpixelformat))

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)