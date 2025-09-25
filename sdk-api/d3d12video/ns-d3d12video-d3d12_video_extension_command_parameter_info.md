## Description

Describes a video extension command parameter.

## Members

### `Name`

A pointer to a wide string containing the name of the command.

### `Type`

A member of the [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_type) specifying the type of the parameter.

### `Flags`

A member of the [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_extension_command_parameter_flags) enumeration specifying the usage of the parameter.

## Remarks

An array of this structure is provided in a [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_command_parameters) structure returned from a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

## See also