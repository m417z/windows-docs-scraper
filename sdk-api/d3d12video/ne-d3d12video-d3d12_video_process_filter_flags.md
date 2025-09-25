# D3D12_VIDEO_PROCESS_FILTER_FLAGS enumeration

## Description

Specifies support for the image filters.

## Constants

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_NONE`

The video processor doesn't support any filters.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_BRIGHTNESS`

The video processor can adjust the brightness level.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_CONTRAST`

The video processor can adjust the contrast level.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_HUE`

The video processor can adjust hue.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_SATURATION`

The video processor can adjust the saturation level.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_NOISE_REDUCTION`

The video processor can perform noise reduction.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_EDGE_ENHANCEMENT`

The video processor can perform edge enhancement.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_ANAMORPHIC_SCALING`

The video processor can perform anamorphic scaling. Anamorphic scaling can be used to stretch 4:3 content to a widescreen 16:9 aspect ratio.

### `D3D12_VIDEO_PROCESS_FILTER_FLAG_STEREO_ADJUSTMENT`

For stereo 3D video, the video processor can adjust the offset between the left and right views, allowing the user to reduce potential eye strain.

## Remarks

See [D3D12\_VIDEO\_PROCESS\_INPUT\_STREAM\_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_desc) for information on applying a particular filter.

## See also