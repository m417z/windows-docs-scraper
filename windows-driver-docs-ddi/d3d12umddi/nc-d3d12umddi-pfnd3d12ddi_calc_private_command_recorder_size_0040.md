# PFND3D12DDI_CALC_PRIVATE_COMMAND_RECORDER_SIZE_0040 callback function

## Description

Calculates the command recorder size.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_COMMAND_RECORDER_0040 structure that contains the arguments to create a command recorder.

## Return value

Returns SIZE_T that represents the size of the command recorder.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CALC_PRIVATE_COMMAND_RECORDER_SIZE_0040 Pfnd3d12ddiCalcPrivateCommandRecorderSize0040;

// Definition

SIZE_T Pfnd3d12ddiCalcPrivateCommandRecorderSize0040
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_RECORDER_0040 *
)
{...}

PFND3D12DDI_CALC_PRIVATE_COMMAND_RECORDER_SIZE_0040

```

## See also