# D2D1_2DAFFINETRANSFORM_PROP enumeration

## Description

Identifiers for properties of the [2D affine transform effect](https://learn.microsoft.com/windows/desktop/Direct2D/2d-affine-transform).

## Constants

### `D2D1_2DAFFINETRANSFORM_PROP_INTERPOLATION_MODE:0`

The interpolation mode used to scale the image. There are 6 scale modes that range in quality and speed.

Type is [D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_2daffinetransform_interpolation_mode).

Default value is D2D1_2DAFFINETRANSFORM_INTERPOLATION_MODE_LINEAR.

### `D2D1_2DAFFINETRANSFORM_PROP_BORDER_MODE:1`

The mode used to calculate the border of the image, soft or hard.

Type is [D2D1_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects/ne-d2d1effects-d2d1_border_mode).

Default value is D2D1_BORDER_MODE_SOFT.

### `D2D1_2DAFFINETRANSFORM_PROP_TRANSFORM_MATRIX:2`

The 3x2 matrix to transform the image using the Direct2D matrix transform.

Type is [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f).

Default value is Matrix3x2F::Identity().

### `D2D1_2DAFFINETRANSFORM_PROP_SHARPNESS:3`

In the high quality cubic interpolation mode, the sharpness level of the scaling filter as a float between 0 and 1. The values are unitless. You can use sharpness to adjust the quality of an image when you scale the image.
The sharpness factor affects the shape of the kernel. The higher the sharpness factor, the smaller the kernel.

**Note** This property affects only the high quality cubic interpolation mode.

Type is FLOAT.

Default value is 1.0f.

### `D2D1_2DAFFINETRANSFORM_PROP_FORCE_DWORD:0xffffffff`