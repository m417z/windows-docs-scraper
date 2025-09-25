# D3D12_SHADER_MIN_PRECISION_SUPPORT enumeration

## Description

Describes minimum precision support options for shaders in the current graphics driver.

## Constants

### `D3D12_SHADER_MIN_PRECISION_SUPPORT_NONE:0`

The driver supports only full 32-bit precision for all shader stages.

### `D3D12_SHADER_MIN_PRECISION_SUPPORT_10_BIT:0x1`

The driver supports 10-bit precision.

### `D3D12_SHADER_MIN_PRECISION_SUPPORT_16_BIT:0x2`

The driver supports 16-bit precision.

## Remarks

This enum is used by the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure.

The returned info just indicates that the graphics hardware can perform HLSL operations at a lower precision than the standard 32-bit float precision, but doesn’t guarantee that the graphics hardware will actually run at a lower precision.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)