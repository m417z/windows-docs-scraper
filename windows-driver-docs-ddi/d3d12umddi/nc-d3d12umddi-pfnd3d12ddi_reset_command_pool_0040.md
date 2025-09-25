# PFND3D12DDI_RESET_COMMAND_POOL_0040 callback function

## Description

Implemented by the client driver to reset a command pool.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A handle to the command pool to reset.

## Prototype

```cpp
//Declaration

PFND3D12DDI_RESET_COMMAND_POOL_0040 Pfnd3d12ddiResetCommandPool0040;

// Definition

VOID Pfnd3d12ddiResetCommandPool0040
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HCOMMANDPOOL_0040
)
{...}

PFND3D12DDI_RESET_COMMAND_POOL_0040

```

## See also