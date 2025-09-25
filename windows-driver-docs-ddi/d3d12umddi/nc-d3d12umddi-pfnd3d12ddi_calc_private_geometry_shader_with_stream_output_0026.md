# PFND3D12DDI_CALC_PRIVATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0026 callback function

## Description

Calculates the geometry shader with stream output.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0026 structure.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALC_PRIVATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0026 Pfnd3d12ddiCalcPrivateGeometryShaderWithStreamOutput0026;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateGeometryShaderWithStreamOutput0026
(
	D3D12DDI_HDEVICE Arg1
	const D3D12DDIARG_CREATE_GEOMETRY_SHADER_WITH_STREAM_OUTPUT_0026 *
)
{...}

```

## Remarks

## See also