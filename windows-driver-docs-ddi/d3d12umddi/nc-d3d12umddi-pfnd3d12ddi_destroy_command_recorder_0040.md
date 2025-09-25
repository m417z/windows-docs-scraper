# PFND3D12DDI_DESTROY_COMMAND_RECORDER_0040 callback function

## Description

Implemented by the client driver to clean up command recorder resources.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

A handle to the command recorder.

## Prototype

```cpp
//Declaration

PFND3D12DDI_DESTROY_COMMAND_RECORDER_0040 Pfnd3d12ddiDestroyCommandRecorder0040;

// Definition

VOID Pfnd3d12ddiDestroyCommandRecorder0040
(
	 D3D12DDI_HDEVICE
	 D3D12DDI_HCOMMANDRECORDER_0040
)
{...}

PFND3D12DDI_DESTROY_COMMAND_RECORDER_0040

```

## See also