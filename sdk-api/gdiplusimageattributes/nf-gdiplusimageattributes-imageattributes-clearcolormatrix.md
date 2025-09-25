# ImageAttributes::ClearColorMatrix

## Description

The **ImageAttributes::ClearColorMatrix** method clears the color-adjustment matrix for a specified category.

## Parameters

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the color-adjustment matrix is cleared. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify a color-adjustment matrix for the default category, a different color-adjustment matrix for the bitmap category, and still a different color-adjustment matrix for the pen category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the pen category, then the default settings apply to the pen category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a color-adjustment matrix and a gamma value for the default category. If you set a color-adjustment matrix for the pen category by calling [ImageAttributes::SetColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrix), then the default color-adjustment matrix will not apply to pens. If you later clear the pen color-adjustment matrix by calling **ImageAttributes::ClearColorMatrix**, the pen category will not revert to the default adjustment matrix; rather, the pen category will have no adjustment matrix. Similarly, the pen category will not revert to the default gamma value; rather, the pen category will have no gamma value.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolormatrices)

[ImageAttributes::SetColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrices)

[ImageAttributes::SetColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrix)

[ImageAttributes::SetToIdentity](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-settoidentity)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)