# PFND3D12DDI_CALCPRIVATEVIDEOEXTENSIONCOMMANDSIZE_0061 callback function

## Description

Returns the driver for the video extension object size. Direct3D runtime allocates space for this driver object. On creation, the driver places the object into the allocation that was provided by the runtime.

## Parameters

### `hDrvDevice`

Handle for the D3D12 device.

### `pArgs`

Pointer to a [D3D12DDIARG_CREATE_VIDEO_EXTENSION_COMMAND_0063](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_extension_command_0063) structure.

## Return value

Returns SIZE_T.

## Prototype

```
//Declaration

PFND3D12DDI_CALCPRIVATEVIDEOEXTENSIONCOMMANDSIZE_0061 Pfnd3d12ddiCalcprivatevideoextensioncommandsize0061;

// Definition

SIZE_T Pfnd3d12ddiCalcprivatevideoextensioncommandsize0061
(
	D3D12DDI_HDEVICE hDrvDevice
	 const D3D12DDIARG_CREATE_VIDEO_EXTENSION_COMMAND_0063 *pArgs
)
{...}

```

## Remarks

## See also