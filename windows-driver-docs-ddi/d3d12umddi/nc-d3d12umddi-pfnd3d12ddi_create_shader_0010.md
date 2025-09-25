# PFND3D12DDI_CREATE_SHADER_0010 callback function

## Description

Create shader.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_SHADER_0010 structure.

### `unnamedParam3`

Shader handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_SHADER_0010 Pfnd3d12ddiCreateShader0010;

// Definition

VOID Pfnd3d12ddiCreateShader0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_SHADER_0010 *
	 D3D12DDI_HSHADER
)
{...}

PFND3D12DDI_CREATE_SHADER_0010

```