# InterpolationMode enumeration

## Description

The **InterpolationMode** enumeration specifies the algorithm that is used when images are scaled or rotated. This enumeration is used by the [Graphics::GetInterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getinterpolationmode) and [Graphics::SetInterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setinterpolationmode) methods of the
[Graphics](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nl-gdiplusgraphics-graphics) class.

## Constants

### `InterpolationModeInvalid`

Used internally

### `InterpolationModeDefault`

Specifies the default interpolation mode.

### `InterpolationModeLowQuality`

Specifies a low-quality mode.

### `InterpolationModeHighQuality`

Specifies a high-quality mode.

### `InterpolationModeBilinear`

Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size.

### `InterpolationModeBicubic`

Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size.

### `InterpolationModeNearestNeighbor`

Specifies nearest-neighbor interpolation.

### `InterpolationModeHighQualityBilinear`

Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking.

### `InterpolationModeHighQualityBicubic`

Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images.

## See also

[Graphics::GetInterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-getinterpolationmode)

[Graphics::SetInterpolationMode](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-setinterpolationmode)