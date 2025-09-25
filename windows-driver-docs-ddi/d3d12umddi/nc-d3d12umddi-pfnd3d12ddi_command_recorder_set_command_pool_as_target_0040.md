# PFND3D12DDI_COMMAND_RECORDER_SET_COMMAND_POOL_AS_TARGET_0040 callback function

## Description

Implemented by the client driver to set the command pool as a target for the command recorder.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A handle to the command recorder.

### `unnamedParam3`

A handle to the command pool.

## Prototype

```cpp
//Declaration

PFND3D12DDI_COMMAND_RECORDER_SET_COMMAND_POOL_AS_TARGET_0040 Pfnd3d12ddiCommandRecorderSetCommandPoolAsTarget0040;

// Definition

VOID Pfnd3d12ddiCommandRecorderSetCommandPoolAsTarget0040
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HCOMMANDRECORDER_0040
	 D3D12DDI_HCOMMANDPOOL_0040
)
{...}

PFND3D12DDI_COMMAND_RECORDER_SET_COMMAND_POOL_AS_TARGET_0040

```

## See also