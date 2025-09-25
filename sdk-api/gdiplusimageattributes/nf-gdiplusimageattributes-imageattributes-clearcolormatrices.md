# ImageAttributes::ClearColorMatrices

## Description

The **ImageAttributes::ClearColorMatrices** method clears the color-adjustment matrix and the grayscale-adjustment matrix for a specified category.

## Parameters

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the adjustment matrices are cleared. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify a pair (color and grayscale) of adjustment matrices for the default category, a different pair of adjustment matrices for the bitmap category, and still a different pair of adjustment matrices for the pen category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the pen category, then the default settings apply to the pen category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a pair (color and grayscale) of adjustment matrices and a gamma value for the default category. If you set a pair of adjustment matrices for the pen category by calling [ImageAttributes::SetColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrices), then the default adjustment matrices will not apply to pens. If you later clear the pen adjustment matrices by calling **ImageAttributes::ClearColorMatrices**, the pen category will not revert to the default adjustment matrices; rather, the pen category will have no adjustment matrices. Similarly, the pen category will not revert to the default gamma value; rather, the pen category will have no gamma value.

#### Examples

The following example creates an [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object from a .emf file. The code also creates an [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The first call to [ImageAttributes::SetColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrices) sets the default color-adjustment matrix and the default grayscale-adjustment matrix of the **ImageAttributes** object. The second call to **ImageAttributes::SetColorMatrices** sets the pen color-adjustment matrix and the pen grayscale-adjustment matrix of the **ImageAttributes** object. The four matrices perform as follows:

* Default color: multiplies the red component by 1.5.
* Default grayscale: multiplies the green component by 1.5.
* Pen color: multiplies the blue component by 1.5.
* Pen grayscale: multiplies red, green, and blue components by 1.5.

The code calls [DrawImage](https://learn.microsoft.com/previous-versions/ms536037(v=vs.85)) once to draw the image with no color adjustment. Then the code calls **DrawImage** three more times, each time passing the address of the [Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object and the address of the [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object. The second time the image is drawn (after the call that sets the default matrices), all the colors have their red components increased by 50 percent, and all the grays have their green components increased by 50 percent. The third time the image is drawn (after the call that sets the pen matrices), all the colors drawn by a pen have their blue components increased by 50 percent, and all the grays drawn by a pen have their red, green, and blue components increased by 50 percent. The fourth time the image is drawn (after the call to **ImageAttributes::ClearColorMatrices**), no adjustments are applied to colors and grays drawn by a pen.

```cpp

VOID Example_SetClearColorMatrices(HDC hdc)
{
   Graphics graphics(hdc);

   Image            image(L"TestMetafile6.emf");
   ImageAttributes  imAtt;
   RectF            rect;
   Unit             unit;

   image.GetBounds(&rect, &unit);

   ColorMatrix defaultColorMatrix = {  // Multiply red component by 1.5.
      1.5f,  0.0f,  0.0f,  0.0f,  0.0f,
      0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
      0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  0.0f,  1.0f};

   ColorMatrix defaultGrayMatrix = {  // Multiply green component by 1.5.
      1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
      0.0f,  1.5f,  0.0f,  0.0f,  0.0f,
      0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  0.0f,  1.0f};

   ColorMatrix penColorMatrix = {     // Multiply blue component by 1.5.
      1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
      0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
      0.0f,  0.0f,  1.5f,  0.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  0.0f,  1.0f};

   ColorMatrix penGrayMatrix = {      // Multiply all components by 1.5.
      1.5f,  0.0f,  0.0f,  0.0f,  0.0f,
      0.0f,  1.5f,  0.0f,  0.0f,  0.0f,
      0.0f,  0.0f,  1.5f,  0.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  1.0f,  0.0f,
      0.0f,  0.0f,  0.0f,  0.0f,  1.0f};

   // Set the default color- and grayscale-adjustment matrices.
   imAtt.SetColorMatrices(
      &defaultColorMatrix,
      &defaultGrayMatrix,
      ColorMatrixFlagsAltGray,
      ColorAdjustTypeDefault);

   graphics.DrawImage(&image, 10.0f, 10.0f, rect.Width, rect.Height);

   graphics.DrawImage(
      &image,
      RectF(10.0f, 50.0f, rect.Width, rect.Height),  // destination rectangle
      rect.X, rect.Y,                // upper-left corner of source rectangle
      rect.Width,                    // width of source rectangle
      rect.Height,                   // height of source rectangle
      UnitPixel,
      &imAtt);

   // Set the pen color- and grayscale-adjustment matrices.
   imAtt.SetColorMatrices(
      &penColorMatrix,
      &penGrayMatrix,
      ColorMatrixFlagsAltGray,
      ColorAdjustTypePen);

   graphics.DrawImage(
      &image,
      RectF(10.0f, 90.0f, rect.Width, rect.Height),  // destination rectangle
      rect.X, rect.Y,                // upper-left corner of source rectangle
      rect.Width,                    // width of source rectangle
      rect.Height,                   // height of source rectangle
      UnitPixel,
      &imAtt);

   imAtt.ClearColorMatrices(ColorAdjustTypePen);

   graphics.DrawImage(
      &image,
      RectF(10.0f, 130.0f, rect.Width, rect.Height),  // destination rectangle
      rect.X, rect.Y,                // upper-left corner of source rectangle
      rect.Width,                    // width of source rectangle
      rect.Height,                   // height of source rectangle
      UnitPixel,
      &imAtt);
}
				
```

The following illustration shows the output of the preceding code.

![Illustration showing four rows of four ellipses each; the ones drawn with a pen vary in color more than the filled ones](https://learn.microsoft.com/windows/win32/api/gdiplusimageattributes/images/imageattributesclearcolormatrices.png)

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolormatrix)

[ImageAttributes::SetColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrices)

[ImageAttributes::SetColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrix)

[ImageAttributes::SetToIdentity](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-settoidentity)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)