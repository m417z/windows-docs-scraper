# PFND3D12DDI_CALC_PRIVATE_TESSELLATION_SHADER_SIZE callback function

## Description

Determines the size of the user-mode display driver's private region of memory for a hull or domain shader.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `pShaderCode`

Pointer to a shader code.

### `unnamedParam3`

A handle to a root signature.

### `unnamedParam4`

Pointer to a D3D12DDIARG_TESSELLATION_IO_SIGNATURES structure.

## Return value

Returns SIZE_T.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_TESSELLATION_SHADER_SIZE Pfnd3d12ddiCalcPrivateTessellationShaderSize;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateTessellationShaderSize
(
	 D3D12DDI_HDEVICE
	CONST UINT *pShaderCode
	 D3D12DDI_HROOTSIGNATURE
	CONST D3D12DDIARG_TESSELLATION_IO_SIGNATURES *
)
{...}

PFND3D12DDI_CALC_PRIVATE_TESSELLATION_SHADER_SIZE

```