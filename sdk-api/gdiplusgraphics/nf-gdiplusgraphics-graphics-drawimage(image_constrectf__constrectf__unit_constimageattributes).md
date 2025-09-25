# Graphics::DrawImage(IN Image,IN const RectF &,IN const RectF &,IN Unit,IN const ImageAttributes)

## Description

The **Graphics::DrawImage** method draws a specified portion of an image at a specified location.

## Parameters

### `image` [in]

Type: **[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)***

Pointer to an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object that specifies the image to be drawn.

### `destRect` [in, ref]

Type: **[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Rectangle, measured in pixels, that specifies the bounds of the rendered image. The portion of the image specified by *sourceRect* is scaled to fill the rectangle specified by *destRect*.

### `sourceRect` [in, ref]

Type: **[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)**

Rectangle that specifies the portion of the image to be drawn.

### `srcUnit` [in]

Type: **[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)**

Element of the [Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit) enumeration that specifies the unit of measure for the source rectangle.

### `imageAttributes` [in]

Type: **[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)***

Optional. Pointer to an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object that specifies color adjustments to be applied when the image is rendered. The default value is **NULL**.

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