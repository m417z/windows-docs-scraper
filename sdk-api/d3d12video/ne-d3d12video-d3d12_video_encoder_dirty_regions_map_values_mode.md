## Description

Specifies the interpretation of dirty regions map values.

## Constants

### `D3D12_VIDEO_ENCODER_DIRTY_REGIONS_MAP_VALUES_MODE_DIRTY` : 0

Indicates that a non-zero value means the pixel is different, and zero means the pixel is identical. When applied to [D3D12_VIDEO_ENCODER_DIRTY_RECT_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_dirty_rect_info), indicates the group of pixels inside the rect have this meaning.

### `D3D12_VIDEO_ENCODER_DIRTY_REGIONS_MAP_VALUES_MODE_SKIP` : 1

Indicates that a zero value means the pixel is different, and non-zero means the pixel is identical. When applied to [D3D12_VIDEO_ENCODER_DIRTY_RECT_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_dirty_rect_info), indicates the group of pixels inside the rect have this meaning.

## Remarks

## See also