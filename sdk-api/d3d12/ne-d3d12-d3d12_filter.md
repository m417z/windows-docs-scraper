# D3D12_FILTER enumeration

## Description

Specifies filtering options during texture sampling.

## Constants

### `D3D12_FILTER_MIN_MAG_MIP_POINT:0`

Use point sampling for minification, magnification, and mip-level sampling.

### `D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR:0x1`

Use point sampling for minification and magnification; use linear interpolation for mip-level sampling.

### `D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT:0x4`

Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling.

### `D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR:0x5`

Use point sampling for minification; use linear interpolation for magnification and mip-level sampling.

### `D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT:0x10`

Use linear interpolation for minification; use point sampling for magnification and mip-level sampling.

### `D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x11`

Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling.

### `D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT:0x14`

Use linear interpolation for minification and magnification; use point sampling for mip-level sampling.

### `D3D12_FILTER_MIN_MAG_MIP_LINEAR:0x15`

Use linear interpolation for minification, magnification, and mip-level sampling.

### `D3D12_FILTER_ANISOTROPIC:0x55`

Use anisotropic interpolation for minification, magnification, and mip-level sampling.

### `D3D12_FILTER_COMPARISON_MIN_MAG_MIP_POINT:0x80`

Use point sampling for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR:0x81`

Use point sampling for minification and magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT:0x84`

Use point sampling for minification; use linear interpolation for magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR:0x85`

Use point sampling for minification; use linear interpolation for magnification and mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT:0x90`

Use linear interpolation for minification; use point sampling for magnification and mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x91`

Use linear interpolation for minification; use point sampling for magnification; use linear interpolation for mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT:0x94`

Use linear interpolation for minification and magnification; use point sampling for mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR:0x95`

Use linear interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_COMPARISON_ANISOTROPIC:0xd5`

Use anisotropic interpolation for minification, magnification, and mip-level sampling. Compare the result to the comparison value.

### `D3D12_FILTER_MINIMUM_MIN_MAG_MIP_POINT:0x100`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR:0x101`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:0x104`

Fetch the same set of texels as [D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR:0x105`

Fetch the same set of texels as [D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT:0x110`

Fetch the same set of texels as [D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x111`

Fetch the same set of texels as [D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT:0x114`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR:0x115`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MINIMUM_ANISOTROPIC:0x155`

Fetch the same set of texels as [D3D12_FILTER_ANISOTROPIC](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the minimum of the texels. Texels that are weighted 0 during filtering aren't counted towards the minimum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_POINT:0x180`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR:0x181`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_POINT_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT:0x184`

Fetch the same set of texels as [D3D12_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR:0x185`

Fetch the same set of texels as [D3D12_FILTER_MIN_POINT_MAG_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT:0x190`

Fetch the same set of texels as [D3D12_FILTER_MIN_LINEAR_MAG_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR:0x191`

Fetch the same set of texels as [D3D12_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT:0x194`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_LINEAR_MIP_POINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR:0x195`

Fetch the same set of texels as [D3D12_FILTER_MIN_MAG_MIP_LINEAR](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

### `D3D12_FILTER_MAXIMUM_ANISOTROPIC:0x1d5`

Fetch the same set of texels as [D3D12_FILTER_ANISOTROPIC](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_filter) and instead of filtering them return the maximum of the texels. Texels that are weighted 0 during filtering aren't counted towards the maximum. You can query support for this filter type from the **MinMaxFiltering** member in the [D3D11_FEATURE_DATA_D3D11_OPTIONS1](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options1) structure.

## Remarks

This enum is used by the [D3D12_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_sampler_desc) structure.

**Note** If you use different filter types for min versus mag filter, undefined behavior occurs in certain cases where the choice between whether magnification or minification happens is ambiguous. To prevent this undefined behavior, use filter modes that use similar filter operations for both min and mag (or use anisotropic filtering, which avoids the issue as well).

During texture sampling, one or more texels are read and combined (this is calling filtering) to produce a single value. Point sampling reads a single texel while linear sampling reads two texels (endpoints) and linearly interpolates a third value between the endpoints.

Microsoft High Level Shader Language (HLSL) texture-sampling functions also support comparison filtering during texture sampling. Comparison filtering compares each sampled texel against a comparison value. The boolean result is blended the same way that normal texture filtering is blended.

You can use HLSL intrinsic texture-sampling functions that implement texture filtering only or companion functions that use texture filtering with comparison filtering.

Also note the following defines:

``` syntax
#define D3D12_FILTER_REDUCTION_TYPE_MASK    ( 0x3 )

#define D3D12_FILTER_REDUCTION_TYPE_SHIFT   ( 7 )

#define D3D12_FILTER_TYPE_MASK  ( 0x3 )

#define D3D12_MIN_FILTER_SHIFT  ( 4 )

#define D3D12_MAG_FILTER_SHIFT  ( 2 )

#define D3D12_MIP_FILTER_SHIFT  ( 0 )

#define D3D12_ANISOTROPIC_FILTERING_BIT ( 0x40 )

#define D3D12_ENCODE_BASIC_FILTER( min, mag, mip, reduction )                                                     \
                                   ( ( D3D12_FILTER ) (                                                           \
                                   ( ( ( min ) & D3D12_FILTER_TYPE_MASK ) << D3D12_MIN_FILTER_SHIFT ) |           \
                                   ( ( ( mag ) & D3D12_FILTER_TYPE_MASK ) << D3D12_MAG_FILTER_SHIFT ) |           \
                                   ( ( ( mip ) & D3D12_FILTER_TYPE_MASK ) << D3D12_MIP_FILTER_SHIFT ) |           \
                                   ( ( ( reduction ) & D3D12_FILTER_REDUCTION_TYPE_MASK ) << D3D12_FILTER_REDUCTION_TYPE_SHIFT ) ) )

#define D3D12_ENCODE_ANISOTROPIC_FILTER( reduction )                                                  \
                                         ( ( D3D12_FILTER ) (                                         \
                                         D3D12_ANISOTROPIC_FILTERING_BIT |                            \
                                         D3D12_ENCODE_BASIC_FILTER( D3D12_FILTER_TYPE_LINEAR,         \
                                                                    D3D12_FILTER_TYPE_LINEAR,         \
                                                                    D3D12_FILTER_TYPE_LINEAR,         \
                                                                    reduction ) ) )
#define D3D12_DECODE_MIN_FILTER( D3D12Filter )                                                              \
                                 ( ( D3D12_FILTER_TYPE )                                                    \
                                 ( ( ( D3D12Filter ) >> D3D12_MIN_FILTER_SHIFT ) & D3D12_FILTER_TYPE_MASK ) )

#define D3D12_DECODE_MAG_FILTER( D3D12Filter )                                                              \
                                 ( ( D3D12_FILTER_TYPE )                                                    \
                                 ( ( ( D3D12Filter ) >> D3D12_MAG_FILTER_SHIFT ) & D3D12_FILTER_TYPE_MASK ) )

#define D3D12_DECODE_MIP_FILTER( D3D12Filter )                                                              \
                                 ( ( D3D12_FILTER_TYPE )                                                    \
                                 ( ( ( D3D12Filter ) >> D3D12_MIP_FILTER_SHIFT ) & D3D12_FILTER_TYPE_MASK ) )

#define D3D12_DECODE_FILTER_REDUCTION( D3D12Filter )                                                        \
                                 ( ( D3D12_FILTER_REDUCTION_TYPE )                                          \
                                 ( ( ( D3D12Filter ) >> D3D12_FILTER_REDUCTION_TYPE_SHIFT ) & D3D12_FILTER_REDUCTION_TYPE_MASK ) )

#define D3D12_DECODE_IS_COMPARISON_FILTER( D3D12Filter )                                                    \
                                 ( D3D12_DECODE_FILTER_REDUCTION( D3D12Filter ) == D3D12_FILTER_REDUCTION_TYPE_COMPARISON )

#define D3D12_DECODE_IS_ANISOTROPIC_FILTER( D3D12Filter )                                               \
                            ( ( ( D3D12Filter ) & D3D12_ANISOTROPIC_FILTERING_BIT ) &&                  \
                            ( D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MIN_FILTER( D3D12Filter ) ) &&   \
                            ( D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MAG_FILTER( D3D12Filter ) ) &&   \
                            ( D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MIP_FILTER( D3D12Filter ) ) )

```

| Texture Sampling Function | Texture Sampling Function with Comparison Filtering |
| --- | --- |
| [Sample](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-sample) | [SampleCmp](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmp) or [SampleCmpLevelZero](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-to-samplecmplevelzero) |

Comparison filters only work with textures that have the following formats: [DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), [DXGI_FORMAT_R32_FLOAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), [DXGI_FORMAT_R24_UNORM_X8_TYPELESS](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format), [DXGI_FORMAT_R16_UNORM](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)

[Descriptors](https://learn.microsoft.com/windows/desktop/direct3d12/descriptors)