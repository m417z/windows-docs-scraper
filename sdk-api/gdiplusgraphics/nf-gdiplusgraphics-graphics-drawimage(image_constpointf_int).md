# Graphics::DrawImage(IN Image,IN const PointF,IN INT)

## Description

The **Graphics::DrawImage** method draws an image.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that specifies the source image.

### `destPoints` [in]

Type: **const [PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf)***

Pointer to an array of
[PointF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-pointf) objects that specify the area, in a parallelogram, in which to draw the image.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*destPoints* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The value of the
*count* parameter must equal 3 to specify the coordinates of the upper-left corner, upper-right corner, and lower-left corner of the parallelogram. The coordinate of the lower-right corner is calculated using the three given coordinates, the width, and the height of the image. The image is scaled to fit the parallelogram.

#### Examples

The following example draws an image.

```cpp
VOID Example_DrawImage3(HDC hdc)

{
   Graphics graphics(hdc);

   // Create an Image object.
   Image image(L"climber.jpg");

   // Create an array of PointF objects that specify the destination of the image.
   PointF destPoints[3] = {
   PointF(30.0f, 30.0f),
   PointF(250.0f, 50.0f),
   PointF(175.0f, 120.0f)};

   PointF* pdestPoints = destPoints;

   // Draw the image.
   graphics.DrawImage(&image, pdestPoints, 3);
}
```

The following illustration shows the output of the preceding code.

![Illustration showing a previously-rectangular image that has been sheared to a parallelogram](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/images/drawimage1.png)

## See also

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)