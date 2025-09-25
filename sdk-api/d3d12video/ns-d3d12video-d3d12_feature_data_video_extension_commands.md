## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_EXTENSION_COMMANDS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the list of video extension commands from the driver.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `CommandCount`

The supported number of video extension commands. This value must be the count returned by a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with [D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video) specified as the feature.

### `pCommandInfos`

Receives a list of [D3D12_VIDEO_EXTENSION_COMMAND_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_extension_command_info) structures describing video extension commands.

## Remarks

## See also