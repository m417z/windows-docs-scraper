# Graphics::DrawImage(IN Image,IN const Rect &,IN INT,IN INT,IN INT,IN INT,IN Unit,IN const ImageAttributes,IN DrawImageAbort,IN VOID)

## Description

The **Graphics::DrawImage** method draws an image.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that specifies the source image.

### `destRect` [in, ref]

Type: **const [Rect](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rect)**

Reference to a rectangle that bounds the drawing area for the image.

### `srcx` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the portion of the source image to be drawn.

### `srcy` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the portion of the source image to be drawn.

### `srcwidth` [in]

Type: **INT**

Integer that specifies the width of the portion of the source image to be drawn.

### `srcheight` [in]

Type: **INT**

Integer that specifies the height of the portion of the source image to be drawn.

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

The portion of the source image to be drawn is scaled to fit the rectangle.

#### Examples

The following example draws the original source image and then draws a portion of the image in a specified rectangle.

```cpp
VOID Example_DrawImage5(HDC hdc)

{
   Graphics graphics(hdc);

   // Create an Image object.
   Image image(L"pattern.png");

   // Draw the original source image.
   graphics.DrawImage(&image, 10, 10);

   // Define the portion of the image to draw.
   int srcX = 70;
   int srcY = 20;
   int srcWidth = 100;
   int srcHeight = 100;

   // Create a Rect object that specifies the destination of the image.
   Rect destRect(200, 10, image.GetWidth(), image.GetHeight());

   // Create an ImageAttributes object that specifies a recoloring from red to blue.
   ImageAttributes remapAttributes;
   ColorMap redToBlue;
   redToBlue.oldColor = Color(255, 255, 0, 0);
   redToBlue.newColor = Color(255, 0, 0, 255);
   remapAttributes.SetRemapTable(1, &redToBlue);

   // Draw the resized image.
   graphics.DrawImage(
   &image,
   destRect,
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

![Illustration showing two graphics: a multicolored checkerboard pattern, then a two-toned enlargement from that pattern](https://learn.microsoft.com/windows/win32/api/gdiplusgraphics/images/drawimage3.png)

## See also

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)

[Point](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-point)

[SetRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setremaptable)

[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)