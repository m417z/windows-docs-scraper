## Description

Contains motion vectors data with a union for either GPU texture or CPU buffer source. The user must check support for D3D12_FEATURE_VIDEO_ENCODER_MOTION_SEARCH before using this feature.

## Members

### `MapSource`

A [D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_input_map_source) indicating which source is used.

### `pOpaqueLayoutBuffer`

Use with D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE_GPU_TEXTURE. Pointer to an ID3D12Resource containing the resolved output in hardware-specific layout.

### `pCPUBuffer`

Use with D3D12_VIDEO_ENCODER_INPUT_MAP_SOURCE_CPU_BUFFER. Pointer to a [D3D12_VIDEO_ENCODER_MOVEREGION_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_moveregion_info).

## Remarks

## See also