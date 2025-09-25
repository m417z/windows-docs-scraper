# ID2D1BitmapBrush::SetInterpolationMode

## Description

Specifies the interpolation mode used when the brush bitmap is scaled or rotated.

## Parameters

### `interpolationMode`

Type: **[D2D1_BITMAP_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode)**

The interpolation mode used when the brush bitmap is scaled or rotated.

## Remarks

This method sets the interpolation mode for a bitmap, which is an enum value that is specified in the [D2D1_BITMAP_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode) enumeration type. D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR represents nearest neighbor filtering. It looks up the nearest bitmap pixel to the current rendering pixel and chooses its exact color. D2D1_BITMAP_INTERPOLATION_MODE_LINEAR represents linear filtering, and interpolates a color from the four nearest bitmap pixels.

The interpolation mode of a bitmap also affects subpixel translations. In a subpixel translation, bilinear interpolation positions the bitmap more precisely to the application requests, but blurs the bitmap in the process.

## See also

[ID2D1BitmapBrush](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1bitmapbrush)

[ID2D1BitmapBrush::GetInterpolationMode](https://learn.microsoft.com/windows/win32/api/d2d1/nf-d2d1-id2d1bitmapbrush-getinterpolationmode)