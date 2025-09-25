# ImageAttributes::SetColorKey

## Description

The **ImageAttributes::SetColorKey** method sets the color key (transparency range) for a specified category.

## Parameters

### `colorLow` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the low color-key value.

### `colorHigh` [in, ref]

Type: **const [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)**

Reference to a [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) object that specifies the high color-key value.

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the color key is set. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

This method sets the high and low color-key values so that arange of colors can be made transparent. Any color that has each of its three components (red, green, blue) between the corresponding components of the high and low color keys is made transparent.

An
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify a color key for the default category, a different color key for the bitmap category, and still a different color key for the pen category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the pen category, then the default settings apply to the pen category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a collection of adjustment settings for the default category. If you set the color key for the pen category by passing [ColorAdjustTypePen](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the **ImageAttributes::SetColorKey** method, then none of the default adjustment settings will apply to pens.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object from a .bmp file. The code also creates an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The call to **ImageAttributes::SetColorKey** sets the bitmap color key of the
**ImageAttributes** object so that any color that satisfies all three of the following conditions is made transparent:

* The red component is in the range 100 through 250.
* The green component is in the range 95 through 245.
* The blue component is in the range 30 through 60.

```cpp

VOID Example_SetColorKey(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an Image object based on a BMP file.
   // The image has three horizontal stripes.
   // The color of the top stripe has RGB components (90, 90, 20).
   // The color of the middle stripe has RGB components (150, 150, 150).
   // The color of the bottom stripe has RGB components (130, 130, 40).
   Image image(L"ColorKeyTest.bmp");

   // Create an ImageAttributes object, and set its color key.
   ImageAttributes imAtt;
   imAtt.SetColorKey(
      Color(100, 95, 30),
      Color(250, 245, 60),
      ColorAdjustTypeBitmap);

   // Draw the image. Apply the color key.
   // The bottom stripe of the image will be transparent because
   // 100 <= 130 <= 250 and
   // 95  <= 130 <= 245 and
   // 30  <= 40  <= 60.
   graphics.DrawImage(
      &image,
      Rect(20, 20, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel,
      &imAtt);
}
				
```

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearColorKey](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolorkey)

[ImageAttributes::ClearThreshold](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearthreshold)

[ImageAttributes::SetThreshold](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setthreshold)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)