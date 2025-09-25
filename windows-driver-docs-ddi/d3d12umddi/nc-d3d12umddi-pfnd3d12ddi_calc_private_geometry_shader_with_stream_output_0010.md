# PFND3D12DDI_CALC_PRIVATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 callback function

## Description

Calculates the geometry shader with stream output.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 structure.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 Pfnd3d12ddiCalcPrivateGeometryShaderWithStreamOutput0010;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateGeometryShaderWithStreamOutput0010
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0010

```

## Remarks

## See also