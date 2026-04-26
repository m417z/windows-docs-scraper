## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is D3D12_FEATURE_VIDEO_ENCODER_DIRTY_REGIONS.

## Members

### `NodeIndex`

Input parameter. In multi-adapter operation, indicates which physical adapter of the device this operation applies to.

### `SessionInfo`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_session_info) containing information pertaining to the encoding session.

### `MapSource`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_input_map_source) indicating which source the user intends to use.

### `MapValuesType`

Input parameter. A [D3D12_VIDEO_ENCODER_DIRTY_REGIONS_MAP_VALUES_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_dirty_regions_map_values_mode) specifying the desired dirty region map type to check support for.

### `SupportFlags`

Output parameter. A combination of [D3D12_VIDEO_ENCODER_DIRTY_REGIONS_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_dirty_regions_support_flags) indicating supported features.

### `MapSourcePreferenceRanking`

Output parameter. Indicates the driver preference (allowed output range [0..1]) for the input MapSource. The lowest the value reported, the best performance for this MapSource input type.

## Remarks

## See also