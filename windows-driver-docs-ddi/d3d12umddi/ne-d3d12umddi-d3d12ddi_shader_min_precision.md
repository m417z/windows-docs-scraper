## Description

The **D3D12DDI_SHADER_MIN_PRECISION** enumeration describes the driver's minimum precision support options for shaders.

## Constants

### `D3D12DDI_SHADER_MIN_PRECISION_NONE:0x0`

The driver supports only full 32-bit precision for all shader stages.

### `D3D12DDI_SHADER_MIN_PRECISION_10_BIT:0x1`

The driver supports 10-bit precision.

### `D3D12DDI_SHADER_MIN_PRECISION_16_BIT:0x2`

The driver supports 16-bit precision.

## Remarks

The returned information just indicates that the graphics hardware can perform HLSL operations at a lower precision than the standard 32-bit float precision, but doesn’t guarantee that the graphics hardware will actually run at a lower precision.

## See also

[**D3D12DDI_SHADER_CAPS_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_caps_0084)