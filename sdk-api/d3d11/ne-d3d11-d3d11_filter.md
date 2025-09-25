# D3D11_FILTER enumeration

## Description

Filtering options during texture sampling.

## Constants

### `D3D11_FILTER_MIN_MAG_MIP_POINT:0`

Use point sampling for minification, magnification, and mip-level sampling.

### `D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR:0x1`

Use point sampling for minification and magnification; use linear interpolation for mip-level sampling.

### `D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT:0x4`

Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling.

### `D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR:0x5`

Use point sampling for minification; use linear interpolation for magnification and mip-level sampling.

### `D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT:0x10`

Use linear interpolation for minification; use point sampling for magnification and mip-level sampling.

### `D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x11`

Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling.

### `D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT:0x14`

Use linear interpolation for minification and magnification; use point sampling for mip-level sampling.

### `D3D11_FILTER_MIN_MAG_MIP_LINEAR:0x15`

Use linear interpolation for minification, magnification, and mip-level sampling.

### `D3D11_FILTER_ANISOTROPIC:0x55`

Use anisotropic interpolation for minification, magnification, and mip-level sampling.

### `D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT:0x80`

Use point sampling for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR:0x81`

Use point sampling for minification and magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT:0x84`

Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR:0x85`

Use point sampling for minification; use linear interpolation for magnification and mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT:0x90`

Use linear interpolation for minification; use point sampling for magnification and mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x91`

Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT:0x94`

Use linear interpolation for minification and magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR:0x95`

Use linear interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_COMPARISON_ANISOTROPIC:0xd5`

Use anisotropic interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D11_FILTER_MINIMUM_MIN_MAG_MIP_POINT:0x100`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_MIP_POINT and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR:0x101`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:0x104`

Fetch the same set of texels as D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR:0x105`

Fetch the same set of texels as D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT:0x110`

Fetch the same set of texels as D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x111`

Fetch the same set of texels as D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT:0x114`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR:0x115`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_MIP_LINEAR and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MINIMUM_ANISOTROPIC:0x155`

Fetch the same set of texels as D3D11_FILTER_ANISOTROPIC and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_POINT:0x180`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_MIP_POINT and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR:0x181`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:0x184`

Fetch the same set of texels as D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR:0x185`

Fetch the same set of texels as D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT:0x190`

Fetch the same set of texels as D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x191`

Fetch the same set of texels as D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT:0x194`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR:0x195`

Fetch the same set of texels as D3D11_FILTER_MIN_MAG_MIP_LINEAR and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D11_FILTER_MAXIMUM_ANISOTROPIC:0x1d5`

Fetch the same set of texels as D3D11_FILTER_ANISOTROPIC and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

## Remarks

**Note** If you use different filter types for min versus mag filter, undefined behavior occurs in certain cases where the choice between whether magnification or minification happens is ambiguous. To prevent this undefined behavior, use filter modes that use similar filter operations for both min and mag (or use anisotropic filtering, which avoids the issue as well).

During texture sampling, one or more texels are read and combined (this is calling filtering) to produce a single value. Point sampling reads a single texel while linear sampling reads two texels (endpoints) and linearly interpolates a third value between the endpoints.

HLSL texture-sampling functions also support comparison filtering during texture sampling. Comparison filtering compares each sampled texel against a comparison value. The boolean result is blended the same way that normal texture filtering is blended.

You can use HLSL intrinsic texture-sampling functions that implement texture filtering only or companion functions that use texture filtering with comparison filtering.

| Texture Sampling Function | Texture Sampling Function with Comparison Filtering |
| --- | --- |
| sample | samplecmp or samplecmplevelzero |

Comparison filters only work with textures that have the following DXGI formats: R32_FLOAT_X8X24_TYPELESS, R32_FLOAT, R24_UNORM_X8_TYPELESS, R16_UNORM.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-enums)