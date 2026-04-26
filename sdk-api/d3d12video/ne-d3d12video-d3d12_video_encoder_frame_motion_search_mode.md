## Description

Specifies motion search modes for video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_FULL_SEARCH` : 0

The driver performs the full motion search. When [NumHintsPerPixel](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_data_motion_vectors) is greater than zero, the motion vectors are hints for the driver.

### `D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_START_HINT` : 1

The driver takes the motion vectors input per pixel, converts them to the codec-specific block partition, and uses the input motion vectors as starting points in the motion search algorithm. The driver is allowed to perform additional motion search to fine-tune and optimize based on the input motion vector hints.

### `D3D12_VIDEO_ENCODER_FRAME_MOTION_SEARCH_MODE_START_HINT_LIMITED_DISTANCE` : 2

The driver takes the motion vectors input per pixel, converts them to the codec-specific block partition, and uses the input motion vectors as starting points in the motion search algorithm. The driver is allowed to perform limited motion search to fine-tune and optimize, but the resulting new motion vectors must not deviate more than [SearchDeviationLimit](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_frame_motion_search_mode_config) percent in terms of Euclidean vector distance from the input motion vector.

## Remarks

## See also