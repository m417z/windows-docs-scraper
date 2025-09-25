# ImageAttributes::SetColorMatrix

## Description

The **ImageAttributes::SetColorMatrix** method sets the color-adjustment matrix for a specified category.

## Parameters

### `colorMatrix` [in]

Type: **const [ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix)***

Pointer to a 5×5 color-adjustment matrix.

### `mode` [in]

Type: **[ColorMatrixFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-colormatrixflags)**

Element of the [ColorMatrixFlags](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-colormatrixflags) enumeration that specifies the type of image and color that will be affected by the color-adjustment matrix.

### `type` [in, optional]

Type: **[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)**

Element of the [ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) enumeration that specifies the category for which the color-adjustment matrix is set. The default value is [ColorAdjustTypeDefault](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype).

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the method succeeds, it returns [Ok](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status), which is an element of the **Status** enumeration.

If the method fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

An [ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object maintains color and grayscale settings for five adjustment categories: default, bitmap, brush, pen, and text. For example, you can specify a color-adjustment matrix for the default category, a different color-adjustment matrix for the bitmap category, and still a different color-adjustment matrix for the pen category.

The default color- and grayscale-adjustment settings apply to all categories that don't have adjustment settings of their own. For example, if you never specify any adjustment settings for the pen category, then the default settings apply to the pen category.

As soon as you specify a color- or grayscale-adjustment setting for a certain category, the default adjustment settings no longer apply to that category. For example, suppose you specify a collection of adjustment settings for the default category. If you set the color-adjustment matrix for the pen category by passing [ColorAdjustTypePen](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype) to the **ImageAttributes::SetColorMatrix** method, then none of the default adjustment settings will apply to pens.

## See also

[Bitmap](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-bitmap)

[Color](https://learn.microsoft.com/windows/desktop/api/gdipluscolor/nl-gdipluscolor-color)

[ColorAdjustType](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ne-gdipluscolormatrix-coloradjusttype)

[ColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdipluscolormatrix/ns-gdipluscolormatrix-colormatrix)

[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image)

[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes)

[ImageAttributes::ClearColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolormatrices)

[ImageAttributes::ClearColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolormatrix)

[ImageAttributes::SetColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrices)

[ImageAttributes::SetToIdentity](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-settoidentity)

[Metafile](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-metafile)

[Recoloring](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-recoloring-use)