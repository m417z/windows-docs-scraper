# Bitmap::Clone(Rect&,PixelFormat)

## Description

The **Bitmap::Clone** method creates a new [Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object by copying a portion of this bitmap.

## Parameters

### `rect`

Reference to a rectangle that specifies the portion of this bitmap to be copied.

### `format`

Integer that specifies the pixel format of the new bitmap.
The **PixelFormat** data type and constants that represent various pixel formats are defined in Gdipluspixelformats.h.
For more information about pixel format constants, see [Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants).

## Return value

Type: Bitmap*

This method returns a pointer to the new Bitmap object.

## Remarks

#### Examples

The following example creates a Bitmap object from an image file, clones the upper-left portion of the image, and then draws the cloned image.

```cpp
VOID Example_Clone(HDC hdc)
{
   Graphics graphics(hdc);

   // Create a Bitmap object from a JPEG file.
   Bitmap bitmap(L"Climber.jpg");

   // Clone a portion of the bitmap.
   Bitmap* clone = bitmap.Clone(Rect(0, 0, 100, 100), PixelFormatDontCare);

   // Draw the clone.
   graphics.DrawImage(clone, 0, 0);

   delete clone;
}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Clone](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-clone(inconstrectf__inpixelformat))

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image Pixel Format Constants](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-constant-image-pixel-format-constants)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)