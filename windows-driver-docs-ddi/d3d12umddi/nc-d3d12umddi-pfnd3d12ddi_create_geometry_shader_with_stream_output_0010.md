# PFND3D12DDI_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 callback function

## Description

Create geometry shader with stream output.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 structure.

### `unnamedParam3`

A shader handle.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 Pfnd3d12ddiCreateGeometryShaderWithStreamOutput0010;

// Definition

VOID Pfnd3d12ddiCreateGeometryShaderWithStreamOutput0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 *
	 D3D12DDI_HSHADER
)
{...}

PFND3D12DDI_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010

```