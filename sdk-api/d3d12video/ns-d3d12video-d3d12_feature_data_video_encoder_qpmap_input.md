## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_QPMAP_INPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

## Members

### `NodeIndex`

Input parameter. In multi-adapter operation, indicates which physical adapter of the device this operation applies to.

### `SessionInfo`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_session_info) containing information pertaining to the encoding session.

### `MapSource`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_input_map_source) indicating which source the user intends to use.

### `IsSupported`

Output parameter. Indicates if the given value for feature is supported.

### `MapSourcePreferenceRanking`

Output parameter. Indicates the driver preference (allowed output range [0..1]) for the input *MapSource*. The lowest the value reported, the best performance for this *MapSource* input type.

### `BlockSize`

Output parameter. Indicates the pixel size of the blocks. When input is [D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE_CPU_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_input_map_source), this must match the driver-reported [QPMapRegionPixelsSize](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits) value.

## Remarks

## See also