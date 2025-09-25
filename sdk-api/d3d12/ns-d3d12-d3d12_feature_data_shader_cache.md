# D3D12_FEATURE_DATA_SHADER_CACHE structure

## Description

Describes the level of shader caching supported in the current graphics driver.

## Members

### `SupportFlags`

Type: [**D3D12_SHADER_CACHE_SUPPORT_FLAGS**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_shader_cache_support_flags)

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-structs-and-classes): `_Out_`

Indicates the level of caching supported.

## Remarks

Use this structure with [CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) to determine the level of support offered for the optional shader-caching features.

See the enumeration constant D3D12_FEATURE_SHADER_CACHE in the [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature) enumeration.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)