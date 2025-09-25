# ImageAttributes::SetThreshold

## Description

The **ImageAttributes::SetThreshold** method sets the threshold (transparency range) for a specified category.

## Parameters

### `threshold` [in]

Type: **REAL**

**REAL** number that specifies the threshold value.

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the color threshold is set. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

The threshold is a value from 0 through 1 that specifies a cutoff point for each color component. For example, suppose the threshold is set to 0.7, and suppose you are rendering a color whose red, green, and blue components are 230, 50, and 220. The red component, 230, is greater than 0.7×255, so the red component will be changed to 255 (full intensity). The green component, 50, is less than 0.7×255, so the green component will be changed to 0. The blue component, 220, is greater than 0.7×255, so the blue component will be changed to 255.

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify a threshold for the default category, a threshold for the bitmap category, and still a different threshold for the pen category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the pen category, then the default settings apply to the pen category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a collection of adjustment settings for the default category. If you set the threshold for the pen category by passing [ColorAdjustTypePen](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the **ImageAttributes::SetThreshold** method, then none of the default adjustment settings will apply to pens.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a .bmp file. The code also creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object and sets its bitmap threshold value to 0.6. Then the code draws the image twice: once with no color adjustment and once with the adjustment specified by the threshold.

```cpp

VOID Example_SetThreshold(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an Image object based on a .bmp file.
   // The image has one stripe with RGB components (160, 0, 0)
   // and one stripe with RGB components (0, 140, 0).
   Image image(L"RedGreenThreshold.bmp");

   // Create an ImageAttributes object, and set its bitmap threshold to 0.6.
   ImageAttributes imAtt;
   imAtt.SetThreshold(0.6f, ColorAdjustTypeBitmap);

   // Draw the image with no color adjustment.
   graphics.DrawImage(&image, 10, 10, image.GetWidth(), image.GetHeight());

   // Draw the image with the threshold applied.
   // 160 > 0.6*255, so the red stripe will be changed to full intensity.
   // 140 < 0.6*255, so the green stripe will be changed to zero intensity.
   graphics.DrawImage(&image,
      Rect(100, 10, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),           // source rect
      UnitPixel,
      &imAtt);
}
				
```

The following illustration shows the output of the preceding code. Note that the red was converted to maximum intensity, and the green was converted to zero intensity.

![Illustration showing a rectangle with maroon and green regions, then the same rectangle but rendered in red and black](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributessetthreshold.png)

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearColorKey](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolorkey)

[ImageAttributes::ClearThreshold](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearthreshold)

[ImageAttributes::SetColorKey](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolorkey)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)