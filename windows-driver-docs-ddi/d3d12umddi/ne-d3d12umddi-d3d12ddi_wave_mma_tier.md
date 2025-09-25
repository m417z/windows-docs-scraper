## Description

A **D3D12DDI_WAVE_MMA_TIER** enumeration value indicates the driver's support for wave matrix-matrix arithmetic (MMA) operations.

## Constants

### `D3D12DDI_WAVE_MMA_TIER_NOT_SUPPORTED:0`

The driver doesn't support WaveMMA operations.

### `D3D12DDI_WAVE_MMA_TIER_0_5_EXPERIMENTAL:5`

The driver supports experimental WaveMMA operations.

## Remarks

For more information, see [Wave MMA](https://microsoft.github.io/DirectX-Specs/d3d/HLSL_SM_6_x_WaveMatrix.html).

## See also

[**D3D12DDI_SHADER_CAPS_0084**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shader_caps_0084)

[**PFND3DDDI_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)