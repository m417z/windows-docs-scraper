## Description

Records a command to execute a video extension command into an encode command list.

## Parameters

### `pExtensionCommand`

Pointer to an [ID3D12VideoExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoextensioncommand) representing the video extension command to execute. The caller is responsible for maintaining object lifetime until command execution is complete.

### `pExecutionParameters`

A pointer to the execution parameters structure, which is defined by the command. The parameters structure must match the parameters enumerated by a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with the feature value of [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) and a parameter stage value of [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_EXECUTION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage).

### `ExecutionParametersSizeInBytes`

The size of the *pExecutionParameters* parameter structure, in bytes.

## Remarks

Errors initializing the extension command are reported via debug layers and the return value of the command list's [Close](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist-close) method.

## See also