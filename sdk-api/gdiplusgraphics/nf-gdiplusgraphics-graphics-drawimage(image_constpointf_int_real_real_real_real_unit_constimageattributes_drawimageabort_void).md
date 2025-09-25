# Graphics::DrawImage(IN Image,IN const PointF,IN INT,IN REAL,IN REAL,IN REAL,IN REAL,IN Unit,IN const ImageAttributes,IN DrawImageAbort,IN VOID)

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

### `srcx` [in]

Type: **REAL**

Real number that specifies the x-coordinate of the upper-left corner of the portion of the source image to be drawn.

### `srcy` [in]

Type: **REAL**

Real number that specifies the y-coordinate of the upper-left corner of the portion of the source image to be drawn.

### `srcwidth` [in]

Type: **REAL**

Real number that specifies the width of the portion of the source image to be drawn.

### `srcheight` [in]

Type: **REAL**

Real number that specifies the height of the portion of the source image to be drawn.

### `srcUnit` [in]

Type: **[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)**

Element of the [Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit) enumeration that specifies the unit of measure for the image. The default value is **UnitPixel**.

### `imageAttributes` [in]

Type: **[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)***

Pointer to an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object that specifies the color and size attributes of the image to be drawn. The default value is **NULL**.

### `callback` [in]

Type: **DrawImageAbort**

Callback method used to cancel the drawing in progress. The default value is **NULL**.

### `callbackData` [in]

Type: **VOID***

Pointer to additional data used by the method specified by the
*callback* parameter. The default value is **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The value of the
*count* parameter must equal 3 to specify the coordinates of the upper-left corner, upper-right corner, and lower-left corner of the parallelogram. The coordinate of the lower-right corner is calculated using the three given coordinates, the width, and the height of the image. The portion of the source image to be drawn is scaled to fit the parallelogram.

#### Examples

The following example draws the original source image and then draws a portion of the image in a specified parallelogram.

```cpp
VOID Example_DrawImage4(HDC hdc)

{

   Graphics graphics(hdc);

   // Create an Image object.
   Image image(L"pattern.png");

   // Draw the original source image.
   graphics.DrawImage(&image, 10, 10);

   // Define the portion of the image to draw.
   REAL srcX = 70.0f;
   REAL srcY = 20.0f;
   REAL srcWidth = 100.0f;
   REAL srcHeight = 100.0f;

   // Create an array of Point objects that specify the destination of the cropped image.
   PointF destPoints[3] = {
   PointF(230.0f, 30.0f),
   PointF(350.0f, 50.0f),
   PointF(275.0f, 120.0f)};

   Point* pdestPoints = destPoints;

   // Create an ImageAttributes object that specifies a recoloring from red to blue.
   ImageAttributes remapAttributes;
   ColorMap redToBlue;
   redToBlue.oldColor = Color(255, 255, 0, 0);
   redToBlue.newColor = Color(255, 0, 0, 255);
   remapAttributes.SetRemapTable(1, &redToBlue);

   // Draw the cropped image.
   graphics.DrawImage(
   &image,
   pdestPoints,
   3,
   srcX,
   srcY,
   srcWidth,
   srcHeight,
   UnitPixel,
   &remapAttributes,
   NULL,
   NULL);
}
```

The following illustration shows the output of the preceding code.

![Illustration showing a multicolored checkerboard pattern, then an enlarged, two-toned subset of that pattern, sheared to a parallelogram](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/images/drawimage2.png)

## See also

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[SetRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setremaptable)

[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)