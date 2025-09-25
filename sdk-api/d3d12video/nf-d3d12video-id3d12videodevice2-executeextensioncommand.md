## Description

Executes a video extension command.

## Parameters

### `pExtensionCommand`

Pointer to an [ID3D12VideoExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoextensioncommand) representing the video extension command to execute. The caller is responsible for maintaining object lifetime until command execution is complete.

### `pExecutionParameters`

A pointer to the execution input parameters structure, which is defined by the command. The parameters structure must match the parameters enumerated by a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with the feature value of [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) and a parameter stage value of [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE_EXECUTION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage).

### `ExecutionParametersSizeInBytes`

The size of the *pExecutionParameters* parameter structure, in bytes.

### `pOutputData`

A pointer to the execution output parameters structure, which is defined by the command.

### `OutputDataSizeInBytes`

Receives the size of the *pExecutionParameters* parameter structure, in bytes.

## Return value

This method returns HRESULT.

## Remarks

Video extension commands executed through this method must complete before this method returns. For efficiency, extension implementations should schedule work in command lists instead of using this method, whenever possible. Each video command list type provides an **ExecuteExtensionCommand** for scheduled work. These include:

- [ID3D12VideoDecodeComandlist2::ExecuteExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist2-executeextensioncommand)
- [ID3D12VideoEncodeComandlist1::ExecuteExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice2-executeextensioncommand)
- [ID3D12VideoProcessComandlist2::ExecuteExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist2-executeextensioncommand)

## See also

- [ID3D12VideoDecodeComandlist2::ExecuteExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodecodecommandlist2-executeextensioncommand)
- [ID3D12VideoEncodeComandlist1::ExecuteExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice2-executeextensioncommand)
- [ID3D12VideoProcessComandlist2::ExecuteExtensionCommand](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist2-executeextensioncommand)