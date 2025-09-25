# D3D12_VIDEO_PROCESS_INPUT_STREAM_FLAGS enumeration

## Description

Specifies flags for video processing input streams. Used by the [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments) structure.

## Constants

### `D3D12_VIDEO_PROCESS_INPUT_STREAM_FLAG_NONE`

No flags specified.

### `D3D12_VIDEO_PROCESS_INPUT_STREAM_FLAG_FRAME_DISCONTINUITY`

Set this flag when not processing frames in order, such as seeking between frames

### `D3D12_VIDEO_PROCESS_INPUT_STREAM_FLAG_FRAME_REPEAT`

Set this flag when applying video process operation to the same set of inputs.

## Remarks

## See also