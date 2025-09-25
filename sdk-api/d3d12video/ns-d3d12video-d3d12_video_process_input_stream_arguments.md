# D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS structure

## Description

Specifies input stream arguments for an input stream passed to [ID3D12VideoCommandList::ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes).

## Members

### `InputStream`

An array of [D3D12_VIDEO_PROCESS_INPUT_STREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream) structures containing the set of references for video processing. If the stereo format is [D3D12_VIDEO_PROCESS_STEREO_FORMAT_SEPARATE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_frame_stereo_format), then two sets of input streams must be supplied. For all other stereo formats, the first set of reference must be supplied, and the second should be zero initialized.

### `Transform`

A [D3D12_VIDEO_PROCESS_TRANSFORM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_transform) structure specifying the flip, rotation, scale and destination translation for the video input.

### `Flags`

A value from the [D3D12_VIDEO_PROCESS_INPUT_STREAM_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_input_stream_flags) enumeration specifying the options for the input stream.

### `RateInfo`

A [D3D12_VIDEO_PROCESS_INPUT_STREAM_RATE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_rate) structure specifying the framerate and input and output indices for framerate conversion and deinterlacing.

### `FilterLevels`

The level to apply for each enabled filter. The filter level is specified in the order that filters appear in the [D3D12_VIDEO_PROCESS_FILTER_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_process_filter_flags) enumeration. Specify 0 if a filter is not enabled or the filter index is reserved.

### `AlphaBlending`

A [D3D12_VIDEO_PROCESS_ALPHA_BLENDING](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_alpha_blending) structure specifying the planar alpha for an input stream on the video processor.

## Remarks

## See also

-[D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments1)
-[ID3D12VideoProcessCommandList::ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes)