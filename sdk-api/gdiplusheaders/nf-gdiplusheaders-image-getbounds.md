# Image::GetBounds

## Description

The **Image::GetBounds** method gets the bounding rectangle for this image.

## Parameters

### `srcRect` [out]

Type: **[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)***

Pointer to a [RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf) object that receives the bounding rectangle.

### `srcUnit` [out]

Type: **[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)***

Pointer to a variable that receives an element of the [Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit) enumeration that indicates the unit of measure for the bounding rectangle.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns Ok, which is an element of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the method fails, it returns one of the other elements of the
[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The bounding rectangle for a metafile does not necessarily have (0, 0) as its upper-left corner. The coordinates of the upper-left corner can be negative or positive, depending on the drawing commands that were issued during the recording of the metafile. For example, suppose a metafile consists of a single ellipse that was recorded with the following statement:

`DrawEllipse(&pen, 200, 100, 80, 40);`

Then the bounding rectangle for the metafile will enclose that one ellipse. The upper-left corner of the bounding rectangle will not be (0, 0); rather, it will be a point near (200, 100).

#### Examples

The following example creates an
[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a metafile and then draws the image. Next, the code calls the **Image::GetBounds** method to get the bounding rectangle for the image. The code makes two attempts to display 75 percent of the image. The first attempt fails because it specifies (0, 0) for the upper-left corner of the source rectangle. The second attempt succeeds because it uses the
**X** and
**Y** data members returned by **Image::GetBounds** to specify the upper-left corner of the source rectangle.

```cpp
VOID Example_GetBounds(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"SampleMetafile2.emf");
   graphics.DrawImage(&image, 0, 0);

   // Get the bounding rectangle for the image (metafile).
   RectF boundsRect;
   Unit unit;
   image.GetBounds(&boundsRect, &unit);

   // Attempt to draw 75 percent of the image.
   // Less than 75 percent of the image will be visible because the
   // upper-left corner of the image's bounding rectangle is not (0, 0).
   RectF dstRect(250.0f, 0.0f, 100.0f, 50.0f);
   graphics.DrawImage(
      &image,
      dstRect,                  // destination rectangle
      0.0f, 0.0f,               // upper-left corner of source rectangle
      0.75f*boundsRect.Width,   // width of source rectangle
      boundsRect.Height,        // height of source rectangle
      UnitPixel);

   // Draw 75 percent of the image.
   dstRect.Y = 80.0f;
   graphics.DrawImage(
      &image,
      dstRect,                       // destination rectangle
      boundsRect.X, boundsRect.Y,    // upper-left corner of source rectangle
      0.75f*boundsRect.Width,        // width of source rectangle
      boundsRect.Height,             // height of source rectangle
      UnitPixel);
}
```

The preceding code, along with a particular file, SampleMetafile2.emf, produced the following output. Note that the first attempt (upper-right) to draw 75 percent of the image shows only about 30 percent of the image.

![Screen shot showing parts of three an ellipses: all of the first one, 30% of the second, and 75% of the third ](https://learn.microsoft.com/windows/win32/api/gdiplusheaders/images/imagegetbounds1.png)

## See also

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[Image::GetHeight](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getheight)

[Image::GetWidth](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-getwidth)

[Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-images-bitmaps-and-metafiles-about)

[RectF](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/nl-gdiplustypes-rectf)

[Unit](https://learn.microsoft.com/windows/desktop/api/gdiplusenums/ne-gdiplusenums-unit)

[Using Images, Bitmaps, and Metafiles](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-using-images-bitmaps-and-metafiles-use)