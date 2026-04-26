## Description

Specifies support flags for dirty regions in video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_DIRTY_REGIONS_SUPPORT_FLAG_NONE` : 0x0

Indicates no support.

### `D3D12_VIDEO_ENCODER_DIRTY_REGIONS_SUPPORT_FLAG_REPEAT_FRAME` : 0x1

Indicates the driver supports setting FullFrameIdentical to TRUE in [D3D12_VIDEO_ENCODER_DIRTY_RECT_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_dirty_rect_info) or [D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_DIRTY_REGIONS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_data_dirty_regions).

### `D3D12_VIDEO_ENCODER_DIRTY_REGIONS_SUPPORT_FLAG_DIRTY_REGIONS` : 0x2

Indicates the driver supports setting FullFrameIdentical to FALSE in [D3D12_VIDEO_ENCODER_DIRTY_RECT_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_dirty_rect_info) or [D3D12_VIDEO_ENCODER_INPUT_MAP_DATA_DIRTY_REGIONS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_input_map_data_dirty_regions).

### `D3D12_VIDEO_ENCODER_DIRTY_REGIONS_SUPPORT_FLAG_DIRTY_REGIONS_REQUIRE_FULL_ROW` : 0x4

Indicates that when the driver supports D3D12_VIDEO_ENCODER_DIRTY_REGIONS_SUPPORT_FLAG_DIRTY_REGIONS, the regions passed by the app must be full rows.

## Remarks

## See also