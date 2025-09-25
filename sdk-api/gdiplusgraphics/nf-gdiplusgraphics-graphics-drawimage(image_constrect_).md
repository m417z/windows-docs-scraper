# Graphics::DrawImage(IN Image,IN const Rect &)

## Description

The **Graphics::DrawImage** method draws an image.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that specifies the source image.

### `rect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that bounds the drawing area for the image.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The image is scaled to fit the rectangle.

#### Examples

The following example draws the source image, the rectangle that bounds the resized image, and then draws the resized image to fit the rectangle.

```cpp
VOID Example_DrawImage9(HDC hdc)

{
   Graphics graphics(hdc);

   // Create an Image object.
   Image image(L"climber.jpg");

   // Create a Pen object.
   Pen pen (Color(255, 255, 0, 0), 2);

   // Draw the original source image.
   graphics.DrawImage(&image, 10, 10);

   // Create a Rect object that specifies the destination of the image.
   Rect destRect(200, 50, 150, 75);

   // Draw the rectangle that bounds the image.
   graphics.DrawRectangle(&pen, destRect);

   // Draw the image.
   graphics.DrawImage(&image, destRect);
}
```

The following illustration shows the output of the preceding code.

![Illustration showing two versions of the same image; the second is slightly narrower than the first, much shorter, and outlined in red](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/images/drawimage6.png)

## See also

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)

[Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)