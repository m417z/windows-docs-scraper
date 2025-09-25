# PFND3D12DDI_CREATE_COMMAND_POOL_0040 callback function

## Description

Implemented by the client driver to create a command pool.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a structure that contains arguments to create a command pool.

### `unnamedParam3`

A handle to a command pool.

## Return value

Returns STATUS_SUCCESS if completed successfully.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_COMMAND_POOL_0040 Pfnd3d12ddiCreateCommandPool0040;

// Definition

HRESULT Pfnd3d12ddiCreateCommandPool0040
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_POOL_0040 *
	 D3D12DDI_HCOMMANDPOOL_0040
)
{...}

PFND3D12DDI_CREATE_COMMAND_POOL_0040

```

## See also