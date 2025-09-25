# PFND3D12DDI_GET_SHADER_STACK_SIZE_0054 callback function

## Description

Retrieves the amount of stack memory required to invoke a ray tracing shader in HLSL (High-Level Shader Language). Ray generation shaders may return nonzero despite being at the bottom of the stack.

## Parameters

### `unnamedParam1`

A handle to the state object.

### `pExportName`

Shader entry point in the state object for which to retrieve stack size.

## Return value

Returns the amount of stack, in bytes, required to invoke the shader.

## Prototype

```cpp
//Declaration

PFND3D12DDI_GET_SHADER_STACK_SIZE_0054 Pfnd3d12ddiGetShaderStackSize0054;

// Definition

UINT Pfnd3d12ddiGetShaderStackSize0054
(
	D3D12DDI_HSTATEOBJECT_0054 Arg1
	LPCWSTR pExportName
)
{...}

```

## Remarks

## See also