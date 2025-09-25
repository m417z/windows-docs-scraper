## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the number of video extension command parameters for the specified parameter stage.

## Members

### `CommandId`

The unique identifier for the video extension command for which the parameter count is queried.

### `Stage`

A member of the [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_STAGE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_stage) enumeration specifying the parameter stage for which the parameter count is retrieved.

### `ParameterCount`

Receives the number of parameters in the parameter stage.

### `ParameterPacking`

Receives the parameter packing for the parameter stage.

## Remarks

## See also