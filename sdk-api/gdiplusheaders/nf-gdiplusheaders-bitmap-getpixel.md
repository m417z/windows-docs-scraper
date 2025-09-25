# Bitmap::GetPixel

## Description

The **Bitmap::GetPixel** method gets the color of a specified pixel in this bitmap.

## Parameters

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate (column) of the pixel.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate (row) of the pixel.

### `color` [out]

Type: **[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)***

Pointer to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that receives the color of the specified pixel.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

Depending on the format of the bitmap, **Bitmap::GetPixel** might not return the same value as was set by [Bitmap::SetPixel](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-setpixel). For example, if you call **Bitmap::SetPixel** on a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object whose pixel format is 32bppPARGB, the pixel's RGB components are premultiplied. A subsequent call to **Bitmap::GetPixel** might return a different value because of rounding. Also, if you call **Bitmap::SetPixel** on a
**Bitmap** object whose color depth is 16 bits per pixel, information could be lost during the conversion from 32 to 16 bits, and a subsequent call to **Bitmap::GetPixel** might return a different value.

#### Examples

The following example creates a
[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap) object based on a JPEG file. The code calls the **Bitmap::GetPixel** method to obtain the color of a pixel in the bitmap and then fills a rectangle with the retrieved color.

```cpp
VOID Example_GetPixel(HDC hdc)

{

   Graphics graphics(hdc);

   // Create a Bitmap object from a JPEG file.
   Bitmap myBitmap(L"Climber.jpg");

   // Get the value of a pixel from myBitmap.
   Color pixelColor;
   myBitmap.GetPixel(25, 25, &pixelColor);

   // Fill a rectangle with the pixel color.
   SolidBrush brush(pixelColor);
   graphics.FillRectangle(&brush, Rect(0, 0, 100, 100));
}
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Bitmap::LockBits](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-lockbits)

[Bitmap::SetPixel](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-bitmap-setpixel)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)