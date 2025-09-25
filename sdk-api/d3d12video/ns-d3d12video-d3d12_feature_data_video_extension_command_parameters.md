## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the list of video extension command parameters for the specified parameter stage.

## Members

### `CommandId`

The unique identifier for the video extension command for which parameters are retrieved.

### `Stage`

A member of the [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage) enumeration specifying the parameter stage for which the parameters are retrieved.

### `ParameterCount`

The supported number of video extension command parameters. This value must be the count returned by a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) specified as the feature.

### `pParameterInfos`

Receives a list of [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_extension_command_parameter_info) structures describing video extension command parameters.

## Remarks

## See also