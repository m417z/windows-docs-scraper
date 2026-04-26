## Description

Specifies the motion search mode and associated parameters for how the driver uses motion vector hints.

## Members

### `MotionSearchMode`

A [D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_motion_search_mode) specifying the mode in which the driver uses motion vector hints.

### `SearchDeviationLimit`

The maximum allowed percent deviation in Euclidean vector distance from the input motion vector. Used with D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_START_HINT_LIMITED_DISTANCE.

## Remarks

## See also