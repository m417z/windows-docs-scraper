# Bitmap::Clone(IN INT,IN INT,IN INT,IN INT,IN PixelFormat)

## Description

The **Bitmap::Clone** method creates a new
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object by copying a portion of this bitmap.

## Parameters

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the rectangle that specifies the portion of this bitmap to copy.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the rectangle that specifies the portion of this bitmap to copy.

### `width` [in]

Type: **INT**

Integer that specifies the width of the rectangle that specifies the portion of this bitmap to copy.

### `height` [in]

Type: **INT**

Integer that specifies the height of the rectangle that specifies the portion of this image to copy.

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

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)