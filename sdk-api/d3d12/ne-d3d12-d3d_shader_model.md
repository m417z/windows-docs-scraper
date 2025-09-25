## Description

Specifies a shader model.

## Constants

### `D3D_SHADER_MODEL_5_1:0x51`

Indicates shader model 5.1.

### `D3D_SHADER_MODEL_6_0:0x60`

Indicates shader model 6.0. Compiling a shader model 6.0 shader requires using the DXC compiler (see [DirectX Shader Compiler](https://github.com/Microsoft/DirectXShaderCompiler)), and is not supported by legacy **FXC**.

### `D3D_SHADER_MODEL_6_1:0x61`

Indicates shader model 6.1.

### `D3D_SHADER_MODEL_6_2:0x62`

### `D3D_SHADER_MODEL_6_3:0x63`

### `D3D_SHADER_MODEL_6_4:0x64`

Shader model 6.4 support was added in Windows 10, Version 1903, and is required for DirectX Raytracing (DXR).

### `D3D_SHADER_MODEL_6_5:0x65`

Shader model 6.5 support was added in Windows 10, Version 2004, and is required for Direct Machine Learning.

### `D3D_SHADER_MODEL_6_6:0x66`

Shader model 6.6 support was added in Windows 11 and the DirectX 12 Agility SDK.

### `D3D_SHADER_MODEL_6_7:0x67`

Shader model 6.7 support was added in the DirectX 12 Agility SDK v1.6. See [Agility SDK 1.606.3: Shader Model 6.7 is now publicly available!](https://devblogs.microsoft.com/directx/shader-model-6-7/) on the DirectX developer blog.

## Remarks

This enum is used by the [D3D12_FEATURE_DATA_SHADER_MODEL](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_shader_model) structure.

## See also

[Core enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)