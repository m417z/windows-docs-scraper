# D3D10_FILTER enumeration

## Description

Filtering options during texture sampling.

## Constants

### `D3D10_FILTER_MIN_MAG_MIP_POINT:0`

Use point sampling for minification, magnification, and mip-level sampling.

### `D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR:0x1`

Use point sampling for minification and magnification; use linear interpolation for mip-level sampling.

### `D3D10_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT:0x4`

Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling.

### `D3D10_FILTER_MIN_POINT_MAG_MIP_LINEAR:0x5`

Use point sampling for minification; use linear interpolation for magnification and mip-level sampling.

### `D3D10_FILTER_MIN_LINEAR_MAG_MIP_POINT:0x10`

Use linear interpolation for minification; use point sampling for magnification and mip-level sampling.

### `D3D10_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x11`

Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling.

### `D3D10_FILTER_MIN_MAG_LINEAR_MIP_POINT:0x14`

Use linear interpolation for minification and magnification; use point sampling for mip-level sampling.

### `D3D10_FILTER_MIN_MAG_MIP_LINEAR:0x15`

Use linear interpolation for minification, magnification, and mip-level sampling.

### `D3D10_FILTER_ANISOTROPIC:0x55`

Use anisotropic interpolation for minification, magnification, and mip-level sampling.

### `D3D10_FILTER_COMPARISON_MIN_MAG_MIP_POINT:0x80`

Use point sampling for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR:0x81`

Use point sampling for minification and magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT:0x84`

Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR:0x85`

Use point sampling for minification; use linear interpolation for magnification and mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT:0x90`

Use linear interpolation for minification; use point sampling for magnification and mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x91`

Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT:0x94`

Use linear interpolation for minification and magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR:0x95`

Use linear interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_COMPARISON_ANISOTROPIC:0xd5`

Use anisotropic interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D10_FILTER_TEXT_1BIT:0x80000000`

For use in pixel shaders with textures that have the R1_UNORM format.

## Remarks

During texture sampling, one or more texels are read and combined (this is calling filtering) to produce a single value. Point sampling reads a single texel while linear sampling reads two texels (endpoints) and linearly interpolates a third value between the endpoints.

HLSL texture-sampling functions also support comparison filtering during texture sampling. Comparison filtering compares each sampled texel against a comparison value. The boolean result is blended the same way that normal texture filtering is blended.

You can use HLSL intrinsic texture-sampling functions that implement texture filtering only or companion functions that use texture filtering with comparison filtering.

| Texture Sampling Function | Texture Sampling Function with Comparison Filtering |
| --- | --- |
| [sample](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-sample) | [samplecmp](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmp) or [samplecmplevelzero](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmplevelzero) |

Comparison filters only work with textures that have the following [formats](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format): R32_FLOAT_X8X24_TYPELESS, R32_FLOAT, R24_UNORM_X8_TYPELESS, R16_UNORM.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-enums)