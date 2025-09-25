# D2D1_FILTER enumeration

## Description

Represents filtering modes that a transform may select to use on input textures.

## Constants

### `D2D1_FILTER_MIN_MAG_MIP_POINT:0x00`

Use point sampling for minification, magnification, and mip-level sampling.

### `D2D1_FILTER_MIN_MAG_POINT_MIP_LINEAR:0x01`

Use point sampling for minification and magnification; use linear interpolation for mip-level sampling.

### `D2D1_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT:0x04`

Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling.

### `D2D1_FILTER_MIN_POINT_MAG_MIP_LINEAR:0x05`

Use point sampling for minification; use linear interpolation for magnification and mip-level sampling.

### `D2D1_FILTER_MIN_LINEAR_MAG_MIP_POINT:0x10`

Use linear interpolation for minification; use point sampling for magnification and mip-level sampling.

### `D2D1_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x11`

Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling.

### `D2D1_FILTER_MIN_MAG_LINEAR_MIP_POINT:0x14`

Use linear interpolation for minification and magnification; use point sampling for mip-level sampling.

### `D2D1_FILTER_MIN_MAG_MIP_LINEAR:0x15`

Use linear interpolation for minification, magnification, and mip-level sampling.

### `D2D1_FILTER_ANISOTROPIC:0x55`

Use anisotropic interpolation for minification, magnification, and mip-level sampling.

### `D2D1_FILTER_FORCE_DWORD:0xffffffff`

## Remarks

This enumeration has the same numeric values as [D3D11_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_filter).

## See also

[D3D11_FILTER](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_filter)