## Description

Translates the motion vector output of the [EstimateMotion](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist-estimatemotion) method from hardware-dependent formats into a consistent format defined by the video motion estimation APIs.

## Parameters

### `pOutputArguments`

A [D3D12_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_OUTPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_resolve_video_motion_vector_heap_output) structure containing the translated motion vectors.

### `pInputArguments`

A [D3D12_RESOLVE_VIDEO_MOTION_VECTOR_HEAP_INPUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_resolve_video_motion_vector_heap_input) structure containing the motion vectors to translate.

## Remarks

## See also