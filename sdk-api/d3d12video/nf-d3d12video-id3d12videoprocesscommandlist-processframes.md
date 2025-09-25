# ID3D12VideoProcessCommandList::ProcessFrames

## Description

Records a video processing operation to the command list, operating on one or more input samples and writing the result to an output surface.

> [!NOTE]
> This version of the method does not allow you to change the [D3D12_VIDEO_FIELD_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_field_type) without recreating the interface. It is recommended that you use [ID3D12VideoProcessCommandList::ProcessFrames1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist1-processframes1) instead, which allows you to change the field type with each call.

## Parameters

### `pVideoProcessor`

A pointer to an [ID3D12VideoProcessor](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoprocessor) interface representing a video processor instance.

### `pOutputArguments`

A [D3D12_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_output_stream_arguments) structure specifying the output surface and output arguments.

### `NumInputStreams`

The count of input streams.

### `pInputArguments`

A pointer to an array of [D3D12_VIDEO_PROCESS_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_arguments) structures specifying the input parameters.

## Remarks

This version of the method does not allow you to change the [D3D12_VIDEO_FIELD_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_field_type). When dealing with mixed content, use [ID3D12VideoProcessCommandList::ProcessFrames1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist1-processframes1) instead, which allows you to specify a field type with each call.

## See also

[ID3D12VideoProcessCommandList::ProcessFrames1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist1-processframes1)