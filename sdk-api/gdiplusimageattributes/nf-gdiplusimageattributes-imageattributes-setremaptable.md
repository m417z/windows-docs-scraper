# ImageAttributes::SetRemapTable

## Description

The **ImageAttributes::SetRemapTable** method sets the color-remap table for a specified category.

## Parameters

### `mapSize` [in]

Type: **UINT**

**INT** that specifies the number of elements in the *map* array.

### `map` [in]

Type: **const [ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap)***

Pointer to an array of [ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap) structures that defines the color map.

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the color-remap table is set. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

A color-remap table is an array of [ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap) structures. Each **ColorMap** structure has two [Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color) objects: one that specifies an old color and one that specifies a corresponding new color. During rendering, any color that matches one of the old colors in the remap table is changed to the corresponding new color.

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify a color remap for the default category, a color-remap table for the bitmap category, and still a different color-remap table for the pen category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the pen category, then the default settings apply to the pen category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a collection of adjustment settings for the default category. If you set the color-remap table for the pen category by passing [ColorAdjustTypePen](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the **ImageAttributes::SetRemapTable** method, then none of the default adjustment settings will apply to pens.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object based on a .bmp file and then draws the image. The code creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object and sets its default remap table so that red is converted to blue. Then the code draws the image again using the color adjustment specified by the remap table.

```cpp

VOID Example_SetRemapTable(HDC hdc)
{
   Graphics graphics(hdc);

   // Create an Image object based on a .bmp file.
   // The image has one red stripe and one green stripe.
   Image image(L"RedGreenStripes.bmp");

   // Create an ImageAttributes object and set its remap table.
   ImageAttributes imageAtt;
   ColorMap cMap;
   cMap.oldColor = Color(255, 255, 0, 0);  // red
   cMap.newColor = Color(255, 0, 0, 255);  // blue
   imageAtt.SetRemapTable(12, &cMap,
      ColorAdjustTypeDefault);

   // Draw the image with no color adjustment.
   graphics.DrawImage(&image, 10, 10, image.GetWidth(), image.GetHeight());

   // Draw the image with red converted to blue.
   graphics.DrawImage(&image,
      Rect(100, 10, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),           // source rect
      UnitPixel,
      &imageAtt);
}
				
```

The following illustration shows the output of the preceding code.

![Illustration showing a rectangle with red and green regions, then the same rectangle with the red region replaced with blue](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributessetremaptable.png)

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorMap](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormap)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearRemapTable](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearremaptable)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)