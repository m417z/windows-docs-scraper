# Graphics::DrawImage(IN Image,IN INT,IN INT,IN INT,IN INT,IN INT,IN INT,IN Unit)

## Description

The **Graphics::DrawImage** method draws an image.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that specifies the source image.

### `x` [in]

Type: **INT**

Integer that specifies the x-coordinate of the upper-left corner of the destination position at which to draw the image.

### `y` [in]

Type: **INT**

Integer that specifies the y-coordinate of the upper-left corner of the destination position at which to draw the image.

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

Element of the
[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit) enumeration that specifies the unit of measure for the image. The default value is UnitPixel.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns **Ok**, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## See also

[Drawing, Positioning, and Cloning Images](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-drawing-positioning-and-cloning-images-about)

[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Loading and Displaying Bitmaps](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-loading-and-displaying-bitmaps-use)