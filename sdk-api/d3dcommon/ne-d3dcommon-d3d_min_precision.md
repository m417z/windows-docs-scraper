# D3D_MIN_PRECISION enumeration

## Description

Values that indicate the minimum desired interpolation precision.

## Constants

### `D3D_MIN_PRECISION_DEFAULT:0`

Default minimum precision, which is 32-bit precision.

### `D3D_MIN_PRECISION_FLOAT_16:1`

Minimum precision is min16float, which is 16-bit floating point.

### `D3D_MIN_PRECISION_FLOAT_2_8:2`

Minimum precision is min10float, which is 10-bit floating point.

### `D3D_MIN_PRECISION_RESERVED:3`

Reserved

### `D3D_MIN_PRECISION_SINT_16:4`

Minimum precision is min16int, which is 16-bit signed integer.

### `D3D_MIN_PRECISION_UINT_16:5`

Minimum precision is min16uint, which is 16-bit unsigned integer.

### `D3D_MIN_PRECISION_ANY_16:0xf0`

Minimum precision is any 16-bit value.

### `D3D_MIN_PRECISION_ANY_10:0xf1`

Minimum precision is any 10-bit value.

## Remarks

For more info, see [Scalar Types](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-scalar) and [Using HLSL minimum precision](https://learn.microsoft.com/windows/desktop/direct3dhlsl/using-hlsl-minimum-precision).

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)