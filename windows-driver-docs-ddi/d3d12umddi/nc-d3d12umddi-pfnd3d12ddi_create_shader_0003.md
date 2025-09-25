# PFND3D12DDI_CREATE_SHADER_0003 callback function

## Description

Create shader.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `pShaderCode`

Pointer to the shader code.

### `unnamedParam3`

A root signature handle.

### `unnamedParam4`

A shader handle.

### `unnamedParam5`

Pointer to a D3D12DDIARG_STAGE_IO_SIGNATURES structure.

### `unnamedParam6`

Flags to create a shader.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_SHADER_0003 Pfnd3d12ddiCreateShader0003;

// Definition

VOID Pfnd3d12ddiCreateShader0003
(
	 D3D12DDI_HDEVICE
	CONST UINT *pShaderCode
	 D3D12DDI_HROOTSIGNATURE
	 D3D12DDI_HSHADER
	CONST D3D12DDIARG_STAGE_IO_SIGNATURES *
	 D3D12DDI_CREATE_SHADER_FLAGS
)
{...}

PFND3D12DDI_CREATE_SHADER_0003

```