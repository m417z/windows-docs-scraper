# PFND3D12DDI_CREATE_COMMAND_RECORDER_0040 callback function

## Description

Create a command to start recording data.

## Parameters

### `unnamedParam1`

A handle to the display device (graphics context).

### `unnamedParam2`

Pointer to a D3D12DDIARG_CREATE_COMMAND_RECORDER_0040 structure that describes the parameters that the user-mode display driver uses to create a command recorder.

### `unnamedParam3`

The command recorder.

## Return value

Returns an HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_CREATE_COMMAND_RECORDER_0040 Pfnd3d12ddiCreateCommandRecorder0040;

// Definition

HRESULT Pfnd3d12ddiCreateCommandRecorder0040
(
	 D3D12DDI_HDEVICE
	CONST D3D12DDIARG_CREATE_COMMAND_RECORDER_0040 *
	 D3D12DDI_HCOMMANDRECORDER_0040
)
{...}

PFND3D12DDI_CREATE_COMMAND_RECORDER_0040

```

## Remarks

## See also