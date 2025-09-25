# Bitmap::Bitmap(IN INT,IN INT,IN PixelFormat)

## Description

Creates a **Bitmap::Bitmap** object of a specified size and pixel format. The pixel data must be provided after the **Bitmap::Bitmap** object is constructed.

## Parameters

### `width` [in]

Type: **INT**

Integer that specifies the width, in pixels, of the bitmap.

### `height` [in]

Type: **INT**

Integer that specifies the height, in pixels, of the bitmap.

### `format` [in]

Type: **PixelFormat**

Optional. Integer that specifies the pixel format of the bitmap. The
**PixelFormat** data type and constants that represent various pixel formats are defined in Gdipluspixelformats.h. For more information about pixel format constants, see [Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants). The default value is PixelFormat32bppARGB.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)