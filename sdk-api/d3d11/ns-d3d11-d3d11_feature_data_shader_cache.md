# D3D11_FEATURE_DATA_SHADER_CACHE structure

## Description

Describes the level of shader caching supported in the current graphics driver.

## Members

### `SupportFlags`

Indicates the level of caching supported.

## Remarks

Use this structure with [CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) to determine the level of support offered for the optional shader-caching features.

See the enumeration constant D3D11_FEATURE_SHADER_CACHE in the [D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature) enumeration.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)