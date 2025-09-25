# PFND3D12DDI_CALC_PRIVATE_COMMAND_POOL_SIZE_0040 callback function

## Description

Calculates the size of the command pool for display.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A pointer to the D3D12DDIARG_CREATE_COMMAND_POOL_0040 structure that contains arguments to create a command pool.

## Return value

Returns SIZE_T that represents the size of the command pool.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_COMMAND_POOL_SIZE_0040 Pfnd3d12ddiCalcPrivateCommandPoolSize0040;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateCommandPoolSize0040
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_POOL_0040 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_COMMAND_POOL_SIZE_0040

```

## See also