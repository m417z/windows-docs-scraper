# D3D_SHADER_DATA structure

## Description

Describes shader data.

## Members

### `pBytecode`

A pointer to shader data.

### `BytecodeLength`

Length of shader data that **pBytecode** points to.

## Remarks

An array of **D3D_SHADER_DATA** structures is passed to [D3DCompressShaders](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompressshaders) to compress the shader data into a more compact form.

## See also

[Structures](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-structs)