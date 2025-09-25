# PFND3D12DDI_INITIALIZE_VIDEO_EXTENSION_COMMAND_0063 callback function

## Description

Records a command to initialize or re-initialize a Video Extension Command into a command list.

## Parameters

### `hDrvCommandList`

Handle for the command list.

### `hDrvVideoExtensionCommand`

Handle to the video extension command to initialize.

### `pInitializationParameters`

Pointer to the initialization parameters structure. Parameters for this structure must match the parameter enumeration for [D3D12DDI_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_0063_INITIALIZATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_extension_command_parameter_stage_0063).

### `InitializationParametersSizeInBytes`

The size of the initialization parameters structure in bytes.

## Return value

The following error codes are allowed:

|Return value | Description|
|---|---|
|S_OK|Initialization succeeded.|
|D3DDDIERR_APPLICATIONERROR|The caller has attempted to initialize the command incorrectly. For example, provided an invalid argument. This error puts the command list in error and an error code is returned from the Close method on the API command list.|
|D3DDDIERR_DEVICEREMOVED|Cannot initialize the command because the device is in a device removed state. If the runtime has not already realized that the device was removed, this will set the device and command list in error.|

## Prototype

```
//Declaration

PFND3D12DDI_INITIALIZE_VIDEO_EXTENSION_COMMAND_0063 Pfnd3d12ddiInitializeVideoExtensionCommand0063;

// Definition

HRESULT Pfnd3d12ddiInitializeVideoExtensionCommand0063
(
	D3D12DDI_HCOMMANDLIST hDrvCommandList
	D3D12DDI_HVIDEOEXTENSIONCOMMAND_0063 hDrvVideoExtensionCommand
	 const void *pInitializationParameters
	SIZE_T InitializationParametersSizeInBytes
)
{...}

```

## Remarks

## See also