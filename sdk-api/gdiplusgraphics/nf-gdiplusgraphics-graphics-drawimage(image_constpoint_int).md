# Graphics::DrawImage(IN Image,IN const Point,IN INT)

## Description

The **Graphics::DrawImage** method draws an image.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that specifies the source image.

### `destPoints` [in]

Type: **const [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)***

Pointer to an array of [Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point) objects that specify the area, in a parallelogram, in which to draw the image.

### `count` [in]

Type: **INT**

Integer that specifies the number of elements in the
*destPoints* array.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns **InvalidParameter**.

## Remarks

The value of the
*count* parameter must equal 3 to specify the three corners of the parallelogram. The fourth corner of the parallelogram is calculated using the vectors of the first and second coordinates and the first and third coordinates. The image is scaled to fit the parallelogram.

#### Examples

The following example draws an image.

```cpp
VOID Example_DrawImage(HDC hdc)

{

   Graphics graphics(hdc);

   // Create an Image object.
   Image image(L"climber.jpg");

   // Create an array of Point objects that specify the destination of the image.
   Point destPoints[3] = {
   Point(30, 30),
   Point(250, 50),
   Point(175, 120)};

   Point* pdestPoints = destPoints;

   // Draw the image.
   graphics.DrawImage(&image, pdestPoints, 3);
}
```

The following illustration shows the output of the preceding code.

![Illustration showing a previously-rectangular image that is now sheared to a parallelogram](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/images/drawimage1.png)

## See also

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)