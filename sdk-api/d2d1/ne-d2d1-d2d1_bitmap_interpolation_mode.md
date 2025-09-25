# D2D1_BITMAP_INTERPOLATION_MODE enumeration

## Description

Specifies the algorithm that is used when images are scaled or rotated.

**Note** Starting in Windows 8, more interpolations modes are available. See [D2D1_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/d2d1_1/ne-d2d1_1-d2d1_interpolation_mode) for more info.

## Constants

### `D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR`

Use the exact color of the nearest bitmap pixel to the current rendering pixel.

### `D2D1_BITMAP_INTERPOLATION_MODE_LINEAR`

Interpolate a color from the four bitmap pixels that are the nearest to the rendering pixel.

### `D2D1_BITMAP_INTERPOLATION_MODE_FORCE_DWORD:0xffffffff`

## Remarks

To stretch an image, each pixel in the original image must be mapped to a group of pixels in the larger image. To shrink an image, groups of pixels in the original image must be mapped to single pixels in the smaller image. The effectiveness of the algorithms that perform these mappings determines the quality of a scaled image. Algorithms that produce higher-quality scaled images tend to require more processing time. **D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR** provides faster but lower-quality interpolation, while **D2D1_BITMAP_INTERPOLATION_MODE_LINEAR** provides higher-quality interpolation.