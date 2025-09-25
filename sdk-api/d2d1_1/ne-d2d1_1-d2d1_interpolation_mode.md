# D2D1_INTERPOLATION_MODE enumeration

## Description

This is used to specify the quality of image scaling with [ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode)) and with the [2D affine transform effect](https://learn.microsoft.com/windows/desktop/Direct2D/2d-affine-transform).

## Constants

### `D2D1_INTERPOLATION_MODE_NEAREST_NEIGHBOR`

Samples the nearest single point and uses that exact color. This mode uses less processing time, but outputs the lowest quality image.

### `D2D1_INTERPOLATION_MODE_LINEAR`

Uses a four point sample and linear interpolation. This mode uses more processing time than the nearest neighbor mode, but outputs a higher quality image.

### `D2D1_INTERPOLATION_MODE_CUBIC`

Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time, but outputs a higher quality image.

### `D2D1_INTERPOLATION_MODE_MULTI_SAMPLE_LINEAR`

Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is good for scaling down by small amounts on images with few pixels.

### `D2D1_INTERPOLATION_MODE_ANISOTROPIC`

Uses anisotropic filtering to sample a pattern according to the transformed shape of the bitmap.

### `D2D1_INTERPOLATION_MODE_HIGH_QUALITY_CUBIC`

Uses a variable size high quality cubic kernel to perform a pre-downscale the image if downscaling is involved in the transform matrix. Then uses the cubic interpolation mode for the final output.

### `D2D1_INTERPOLATION_MODE_FORCE_DWORD:0xffffffff`

## See also

[ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-drawimage(id2d1effect_constd2d1_point_2f_constd2d1_rect_f_d2d1_interpolation_mode_d2d1_composite_mode))