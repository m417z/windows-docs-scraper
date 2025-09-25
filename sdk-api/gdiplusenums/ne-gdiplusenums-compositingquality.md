# CompositingQuality enumeration

## Description

The **CompositingQuality** enumeration specifies whether gamma correction is applied when colors are blended with background colors. This enumeration is used by the [Graphics::GetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getcompositingquality) and [Graphics::SetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingquality) methods of the
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) class.

## Constants

### `CompositingQualityInvalid`

### `CompositingQualityDefault`

Specifies that gamma correction is not applied.

### `CompositingQualityHighSpeed`

Specifies that gamma correction is not applied.

### `CompositingQualityHighQuality`

Specifies that gamma correction is applied.

### `CompositingQualityGammaCorrected`

Specifies that gamma correction is applied.

### `CompositingQualityAssumeLinear`

Specifies that gamma correction is not applied.

## Remarks

When you specify that gamma correction should not be applied, the image data to be rendered (blended with the background) is assumed to be in a linear color space with a gamma value of 1.0. As a result, no gamma adjustment is applied to the image data before or after blending the image with the background.

When you specify that gamma correction should be applied, the image data to be rendered (blended with the background) is assumed to be in the sRGB color space with a gamma value of 2.2. To ensure accurate blending, the input image data is transformed into a linear (gamma = 1.0) space before the colors are blended and transformed back into sRGB (gamma = 2.2) space afterward. This mode results in a more accurate blend at the expense of additional processing time.

## See also

[Graphics::GetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getcompositingquality)

[Graphics::SetCompositingQuality](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setcompositingquality)