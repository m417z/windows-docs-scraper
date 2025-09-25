# Bitmap::Bitmap(INT,INT,INT,PixelFormat,BYTE)

## Description

Creates a **Bitmap::Bitmap** object based on an array of bytes along with size and format information.

## Parameters

### `width` [in]

Type: **INT**

Integer that specifies the width, in pixels, of the bitmap.

### `height` [in]

Type: **INT**

Integer that specifies the height, in pixels, of the bitmap.

### `stride` [in]

Type: **INT**

Integer that specifies the byte offset between the beginning of one scan line and the next. This is usually (but not necessarily) the number of bytes in the pixel format (for example, 2 for 16 bits per pixel) multiplied by the width of the bitmap. The value passed to this parameter must be a multiple of four.

### `format` [in]

Type: **PixelFormat**

Integer that specifies the pixel format of the bitmap. The
**PixelFormat** data type and constants that represent various pixel formats are defined in Gdipluspixelformats.h. For more information about pixel format constants, see [Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants).

### `scan0` [in]

Type: **BYTE***

Pointer to an array of bytes that contains the pixel data. The caller is responsible for allocating and freeing the block of memory pointed to by this parameter.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap Constructors](https://msdn.microsoft.com/9b246a76-e8c0-41b2-9bb2-0df06ebc5563)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)