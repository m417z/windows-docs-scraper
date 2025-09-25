# Bitmap::SetPixel

## Description

The **Bitmap::SetPixel** method sets the color of a specified pixel in this bitmap.

## Parameters

### `x` [in]

Type: **INT**

**int** that specifies the x-coordinate (column) of the pixel.

### `y` [in]

Type: **INT**

**int** that specifies the y-coordinate (row) of the pixel.

### `color` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the color to set.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Depending on the format of the bitmap, [Bitmap::GetPixel](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-getpixel) might not return the same value as was set by **Bitmap::SetPixel**. For example, if you call **Bitmap::SetPixel** on a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object whose pixel format is 32bppPARGB, the RGB components are premultiplied. A subsequent call to **Bitmap::GetPixel** might return a different value because of rounding. Also, if you call **Bitmap::SetPixel** on a
**Bitmap** whose color depth is 16 bits per pixel, information could be lost in the conversion from 32 to 16 bits, and a subsequent call to **Bitmap::GetPixel** might return a different value.

#### Examples

The following example creates a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object based on a JPEG file. The code draws the bitmap once unaltered. Then the code calls the **Bitmap::SetPixel** method to create a checkered pattern of black pixels in the bitmap and draws the altered bitmap.

```cpp
VOID Example_SetPixel(HDC hdc)

{
   Graphics graphics(hdc);

   // Create a Bitmap object from a JPEG file.
   Bitmap myBitmap(L"Climber.jpg");

   // Draw the bitmap.
   graphics.DrawImage(&myBitmap, 0, 0);

   // Create a checkered pattern with black pixels.
   for (UINT row = 0; row < myBitmap.GetWidth(); row += 2)
   {
      for (UINT col = 0; col < myBitmap.GetHeight(); col += 2)
      {
         myBitmap.SetPixel(row, col, Color(255, 0, 0, 0));
      }
   }

   // Draw the altered bitmap.
   graphics.DrawImage(&myBitmap, 200, 0);
}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap::GetPixel](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-getpixel)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)