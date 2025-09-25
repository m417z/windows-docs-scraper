# ImageAttributes::ClearColorKey

## Description

The **ImageAttributes::ClearColorKey** method clears the color key (transparency range) for a specified category.

## Parameters

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the color key is cleared. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify one color key for the default category, a different color key for the bitmap category, and still a different color key for the pen category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the pen category, then the default settings apply to the pen category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a default color key that makes any color with a red component from 200 through 255 transparent and you specify a default gamma value of 1.8. If you set the color key of the pen category by calling [ImageAttributes::SetColorKey](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolorkey), then the default color key and the default gamma value will not apply to pens. If you later clear the pen color key by calling **ImageAttributes::ClearColorKey**, the pen category will not revert to the default color key; rather, the pen category will have no color key. Similarly, the pen category will not revert to the default gamma value; rather, the pen category will have no gamma value.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object from a .emf file. The code also creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The first call to [ImageAttributes::SetColorKey](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolorkey) sets the default color key of the
**ImageAttributes** object so that colors with a red component from 80 through 120 are transparent. The second call to **ImageAttributes::SetColorKey** sets the pen color key of the **ImageAttributes** object so that all colors with a red component from 135 through 175 are transparent.

The code calls [DrawImage](https://learn.microsoft.com/previous-versions/ms536045(v=vs.85)) once to draw the image with no color adjustment. Then the code calls **DrawImage** three more times, each time passing the address of the [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object and the address of the [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The second time the image is drawn (after the call that sets the default color key), all of the red from 80 through 120 is transparent. The third time the image is drawn (after the call that sets the pen color key), all of the red from 135 through 175 that is drawn with a pen is transparent. Also, all of the red from 80 through 120 that is not drawn with a pen is transparent. The fourth time the image is drawn (after the call to **ImageAttributes::ClearColorKey**), none of the red drawn with a pen is transparent. Also, all of the red from 80 through 120 that is not drawn with a pen is transparent.

```cpp

VOID Example_SetClearColorKey(HDC hdc)
{
   Graphics graphics(hdc);

   Image image(L"TestMetafile5.emf");
   ImageAttributes imAtt;

   // Draw the image (metafile) using no color adjustment.
   graphics.DrawImage(
      &image,
      Rect(0, 0, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),        // source rect
      UnitPixel);

   // Set the default color key.
   imAtt.SetColorKey(
      Color(0, 80, 0, 0),
      Color(255, 120, 255, 255),
      ColorAdjustTypeDefault);

   // Draw the image (metafile) using default color adjustment.
   // Colors with red components from 80 through 120 are transparent.
   graphics.DrawImage(
      &image,
      Rect(0, 100, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel,
      &imAtt);

   // Set the pen color key.
   imAtt.SetColorKey(
      Color(0, 135, 0, 0),
      Color(255, 175, 255, 255),
      ColorAdjustTypePen);

   // Draw the image (metafile) using default and pen adjustment.
   // Colors drawn with a pen that have red components from 135 through 175
   // are transparent. Colors not drawn with a pen that have red components
   // from 80 to 120 are transparent.
   graphics.DrawImage(
      &image,
      Rect(0, 200, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel,
      &imAtt);

   // Clear the pen color key.
   imAtt.ClearColorKey(ColorAdjustTypePen);

   // Draw the image (metafile) using only default color adjustment.
   // No colors drawn with a pen are transparent. Colors not drawn with
   // a pen that have red components from 80 to 120 are transparent.
   graphics.DrawImage(
      &image,
      Rect(0, 300, image.GetWidth(), image.GetHeight()),  // dest rect
      0, 0, image.GetWidth(), image.GetHeight(),          // source rect
      UnitPixel,
      &imAtt);
}
				
```

The preceding code, along with a particular file, TestMetafile5.png, produced the following output. The bars in the left column were drawn with a pen, and the bars in the right column were filled with a brush. The default color key applies to the bars filled with a brush. The color key that applies to the bars drawn with a pen varies according to the [ImageAttributes::SetColorKey](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolorkey) and **ImageAttributes::ClearColorKey** calls.

![Illustration showing bars in four rows of two columns each; the last two have unequal numbers of bars in each row](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributesclearcolorkey.png)

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearThreshold](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearthreshold)

[ImageAttributes::SetColorKey](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolorkey)

[ImageAttributes::SetThreshold](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setthreshold)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)