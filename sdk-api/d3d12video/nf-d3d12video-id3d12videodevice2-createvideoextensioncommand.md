## Description

Creates a video extension command.

## Parameters

### `pDesc`

The [D3D12_VIDEO_EXTENSION_COMMAND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_extension_command_desc) describing the command to be created.

### `pCreationParameters`

A pointer to the creation parameters structure, which is defined by the command. The parameters structure must match the parameters enumerated by a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with the feature value of [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) and a parameter stage value of [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_CREATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage).

### `CreationParametersDataSizeInBytes`

The size of the *pCreationParameters* parameter structure, in bytes.

### `pProtectedResourceSession`

A [ID3D12ProtectedResourceSession](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12protectedresourcesession) for managing access to protected resources.

### `riid`

The globally unique identifier (GUID) for the [ID3D12VideoExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoextensioncommand) interface.

### `ppVideoExtensionCommand`

A pointer to a memory block that receives a pointer to the [ID3D12VideoExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoextensioncommand) interface.

## Return value

This method returns an HRESULT.

## Remarks

## See also