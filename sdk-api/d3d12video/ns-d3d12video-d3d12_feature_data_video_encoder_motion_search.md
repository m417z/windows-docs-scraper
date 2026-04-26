## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is D3D12_FEATURE_VIDEO_ENCODER_MOTION_SEARCH.

## Members

### `NodeIndex`

Input parameter. In multi-adapter operation, indicates which physical adapter of the device this operation applies to.

### `SessionInfo`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_SESSION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_session_info) containing information pertaining to the encoding session.

### `MotionSearchMode`

Input parameter. A [D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_motion_search_mode) specifying the desired motion search mode to check support for.

### `MapSource`

Input parameter. A [D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_input_map_source) indicating which source the user intends to use.

### `BidirectionalRefFrameEnabled`

Input parameter. Indicates if the user will use the feature for bidirectional reference frames (for example, B frames for H264).

### `SupportFlags`

Output parameter. A combination of [D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_motion_search_support_flags) indicating supported features.

### `MaxMotionHints`

Output parameter. Indicates the maximum value supported by the driver for NumHintsPerPixel on GPU texture mode or NumMoveRegions on CPU buffer mode.

### `MinDeviation`

Output parameter. For D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_START_HINT_LIMITED_DISTANCE, indicates the minimum value supported for SearchDeviationLimit.

### `MaxDeviation`

Output parameter. For D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_START_HINT_LIMITED_DISTANCE, indicates the maximum value supported for SearchDeviationLimit.

### `MapSourcePreferenceRanking`

Output parameter. Indicates the driver preference (allowed output range [0..1]) for the input MapSource. The lowest the value reported, the best performance for this MapSource input type.

### `MotionUnitPrecisionSupport`

Output parameter. A combination of [D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_input_motion_unit_precision_support_flags) reporting supported precision modes for input vectors.

## Remarks

## See also