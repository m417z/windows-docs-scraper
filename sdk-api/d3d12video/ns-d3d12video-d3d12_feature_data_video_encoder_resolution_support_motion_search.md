## Description

Defines the reported support for motion search as output for [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits1).

## Members

### `MaxMotionHints`

Indicates the maximum value supported for NumHintsPerPixel or NumMoveRegions.

### `MinDeviation`

For D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_START_HINT_LIMITED_DISTANCE, the minimum supported SearchDeviationLimit.

### `MaxDeviation`

For D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_START_HINT_LIMITED_DISTANCE, the maximum supported SearchDeviationLimit.

### `MapSourcePreferenceRanking`

Indicates the driver preference ranking for the map source.

### `MotionUnitPrecisionSupportFlags`

A combination of [D3D12_VIDEO_ENCODER_FRAME_INPUT_MOTION_UNIT_PRECISION_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_input_motion_unit_precision_support_flags) reporting supported precision modes.

### `MotionSearchSupportFlags`

A combination of [D3D12_VIDEO_ENCODER_MOTION_SEARCH_SUPPORT_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_motion_search_support_flags) indicating supported features.

## Remarks

## See also