## Description

Describes a video extension command.

## Members

### `CommandId`

The unique identifier for the video extension command.

### `Name`

A pointer to a wide string containing the name of the command.

### `CommandListSupportFlags`

A member of the [D3D12_COMMAND_LIST_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_support_flags) enumeration. Indicates the video command queue that the video extension targets. Only one value from the enumeration can be set.

## Remarks

An array of this structure is provided in a [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMANDS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_commands) structure returned from a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_EXTENSION_COMMANDS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

## See also

[D3D12_COMMAND_LIST_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_command_list_support_flags)