# ColorMatrixFlags enumeration

## Description

The **ColorMatrixFlags** enumeration specifies the types of images and colors that will be affected by the color and grayscale adjustment settings of an
[ImageAttributes](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nl-gdiplusimageattributes-imageattributes) object.

## Constants

### `ColorMatrixFlagsDefault:0`

Specifies that all color values (including grays) are adjusted by the same color-adjustment matrix.

### `ColorMatrixFlagsSkipGrays:1`

Specifies that colors are adjusted but gray shades are not adjusted. A gray shade is any color that has the same value for its red, green, and blue components.

### `ColorMatrixFlagsAltGray:2`

Specifies that colors are adjusted by one matrix and gray shades are adjusted by another matrix.

## See also

[ImageAttributes::ClearColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolormatrices)

[ImageAttributes::ClearColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-clearcolormatrix)

[ImageAttributes::SetColorMatrices](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrices)

[ImageAttributes::SetColorMatrix](https://learn.microsoft.com/windows/desktop/api/gdiplusimageattributes/nf-gdiplusimageattributes-imageattributes-setcolormatrix)