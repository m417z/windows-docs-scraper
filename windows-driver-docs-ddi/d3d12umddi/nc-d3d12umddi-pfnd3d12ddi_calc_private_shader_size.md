# PFND3D12DDI_CALC_PRIVATE_SHADER_SIZE callback function

## Description

Determines the size of the user-mode display driver's private region of memory (that is, the size of internal driver structures, not the size of the resource video memory) for a shader.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `pShaderCode`

Pointer to a shader code.

### `unnamedParam3`

A handle to a root signature.

### `unnamedParam4`

Pointer to a D3D12DDIARG_STAGE_IO_SIGNATURES structure.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALC_PRIVATE_SHADER_SIZE Pfnd3d12ddiCalcPrivateShaderSize;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateShaderSize
(
	D3D12DDI_HDEVICE Arg1
	 const UINT *pShaderCode
	D3D12DDI_HROOTSIGNATURE Arg2
	 const D3D12DDIARG_STAGE_IO_SIGNATURES *
)
{...}

```

## Remarks

## See also