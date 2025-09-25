# D2D1_YCBCR_PROP enumeration

## Description

Identifiers for properties of the [YCbCr effect](https://learn.microsoft.com/windows/desktop/Direct2D/ycbcr-effect).

## Constants

### `D2D1_YCBCR_PROP_CHROMA_SUBSAMPLING:0`

Specifies the chroma subsampling of the input chroma image.

The type is [D2D1_YCBCR_CHROMA_SUBSAMPLING](https://learn.microsoft.com/windows/desktop/api/d2d1effects_1/ne-d2d1effects_1-d2d1_ycbcr_chroma_subsampling).

The default value is D2D1_YCBCR_CHROMA_SUBSAMPLING_AUTO.

### `D2D1_YCBCR_PROP_TRANSFORM_MATRIX:1`

A 3x2 Matrix specifying the axis-aligned affine transform of the image. Axis aligned transforms include Scale, Flips, and 90 degree rotations.

The type is [D2D1_MATRIX_3X2_F](https://learn.microsoft.com/windows/desktop/Direct2D/d2d1-matrix-3x2-f).

The default value is Matrix3x2F::Identity().

### `D2D1_YCBCR_PROP_INTERPOLATION_MODE:2`

The interpolation mode.

The type is [D2D1_YCBCR_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1effects_1/ne-d2d1effects_1-d2d1_ycbcr_interpolation_mode).

### `D2D1_YCBCR_PROP_FORCE_DWORD:0xffffffff`