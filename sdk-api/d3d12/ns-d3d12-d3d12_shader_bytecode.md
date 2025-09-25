# D3D12_SHADER_BYTECODE structure

## Description

Describes shader data.

## Members

### `pShaderBytecode`

A pointer to a memory block that contains the shader data.

### `BytecodeLength`

The size, in bytes, of the shader data that the **pShaderBytecode** member points to.

## Remarks

The [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) objects contain **D3D12_SHADER_BYTECODE** structures that describe various shader types.

When loading a shader from FXC/DXC, this may be the entire compiled blob as is loaded from disk.

## See also

[CD3DX12_SHADER_BYTECODE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-shader-bytecode)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)