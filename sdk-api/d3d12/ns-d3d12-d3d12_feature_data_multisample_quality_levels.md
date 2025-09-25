# D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS structure

## Description

Describes the multi-sampling image quality levels for a given format and sample count.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the format to return info about.

### `SampleCount`

The number of multi-samples per pixel to return info about.

### `Flags`

Flags to control quality levels, as a bitwise-OR'd combination of [D3D12_MULTISAMPLE_QUALITY_LEVEL_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_multisample_quality_level_flags) enumeration constants.
The resulting value specifies options for determining quality levels.

### `NumQualityLevels`

The number of quality levels.

## Remarks

See [D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_feature)