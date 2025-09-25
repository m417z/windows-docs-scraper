# PFND3D12DDI_CREATE_COMPUTE_SHADER_0003 callback function

## Description

Create a compute shader.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `pShaderCode`

Pointer to a shader code.

### `unnamedParam3`

A handle to a root signature.

### `unnamedParam4`

A shader handle.

### `unnamedParam5`

Flags to create a shader.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_COMPUTE_SHADER_0003 Pfnd3d12ddiCreateComputeShader0003;

// Definition

VOID Pfnd3d12ddiCreateComputeShader0003
(
	 D3D12DDI_HDEVICE
	CONST UINT *pShaderCode
	 D3D12DDI_HROOTSIGNATURE
	 D3D12DDI_HSHADER
	 D3D12DDI_CREATE_SHADER_FLAGS
)
{...}

PFND3D12DDI_CREATE_COMPUTE_SHADER_0003

```