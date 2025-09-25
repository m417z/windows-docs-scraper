# D3D12_FEATURE_DATA_D3D12_OPTIONS2 structure

## Description

Indicates the level of support that the adapter provides for depth-bounds tests and programmable sample positions.

## Members

### `DepthBoundsTestSupported`

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-structs-and-classes): `_Out_`

On return, contains true if depth-bounds tests are supported; otherwise, false.

### `ProgrammableSamplePositionsTier`

[SAL](https://learn.microsoft.com/visualstudio/code-quality/annotating-structs-and-classes): `_Out_`

On return, contains a value that indicates the level of support offered for programmable sample positions.

## Remarks

Use this structure with [CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) to determine the level of support offered for the optional Depth-bounds test and programmable sample positions features.

See the enumeration constant D3D12_FEATURE_D3D12_OPTIONS2 in the [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature) enumeration.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)