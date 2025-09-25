# D3D11_FEATURE_DATA_D3D10_X_HARDWARE_OPTIONS structure

## Description

Describes compute shader and raw and structured buffer support in the current graphics driver.

## Members

### `ComputeShaders_Plus_RawAndStructuredBuffers_Via_Shader_4_x`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if compute shaders and raw and structured buffers are supported; otherwise **FALSE**.

## Remarks

Direct3D 11 devices (D3D_FEATURE_LEVEL_11_0) are required to support Compute Shader model 5.0.
Direct3D 10.x devices (D3D_FEATURE_LEVEL_10_0, D3D_FEATURE_LEVEL_10_1) can optionally support Compute Shader model 4.0 or 4.1.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)