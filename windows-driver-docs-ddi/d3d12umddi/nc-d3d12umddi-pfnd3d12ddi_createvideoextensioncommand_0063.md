# PFND3D12DDI_CREATEVIDEOEXTENSIONCOMMAND_0063 callback function

## Description

Creates a video extension command. All significant internal resource allocations used by the extension command should be created during video extension creation.

## Parameters

### `hDrvDevice`

Handle for the Direct3D 12 device.

### `pArgs`

Pointer to a [D3D12DDIARG_CREATE_VIDEO_EXTENSION_COMMAND_0063](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_extension_command_0063) structure that contains arguments.

### `hDrvVideoExtensionCommand`

A handle to a video extension command D3D12DDI_HVIDEOEXTENSIONCOMMAND_0063.

## Return value

Returns HRESULT.

## Prototype

```
//Declaration

PFND3D12DDI_CREATEVIDEOEXTENSIONCOMMAND_0063 Pfnd3d12ddiCreatevideoextensioncommand0063;

// Definition

HRESULT Pfnd3d12ddiCreatevideoextensioncommand0063
(
	D3D12DDI_HDEVICE hDrvDevice
	 const D3D12DDIARG_CREATE_VIDEO_EXTENSION_COMMAND_0063 *pArgs
	D3D12DDI_HVIDEOEXTENSIONCOMMAND_0063 hDrvVideoExtensionCommand
)
{...}

```

## Remarks

## See also