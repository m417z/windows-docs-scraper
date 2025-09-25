# PFND3D12DDI_CALC_PRIVATE_SHADER_SIZE_0026 callback function

## Description

Determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a shader.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_SHADER_0026 structure.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALC_PRIVATE_SHADER_SIZE_0026 Pfnd3d12ddiCalcPrivateShaderSize0026;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateShaderSize0026
(
	D3D12DDI_HDEVICE Arg1
	 const D3D12DDIARG_CREATE_SHADER_0026 *
)
{...}

```

## Remarks

## See also