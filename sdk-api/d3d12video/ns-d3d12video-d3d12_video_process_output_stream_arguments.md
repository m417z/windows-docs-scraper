# D3D12_VIDEO_PROCESS_OUTPUT_STREAM_ARGUMENTS structure

## Description

Specifies output stream arguments for the output passed to [ID3D12VideoCommandList::ProcessFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoprocesscommandlist-processframes).

## Members

### `OutputStream`

An array of [D3D12_VIDEO_PROCESS_OUTPUT_STREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_output_stream) structures representing the output surfaces for the video process command. If stereo output is enabled, index zero contains the left output while index 1 contains the right input. If stereo output is not enabled, only index 0 is used to specify the output while index 1 should be set to nullptr.

### `TargetRectangle`

The target rectangle is the area within the destination surface where the output will be drawn. The target rectangle is given in pixel coordinates, relative to the destination surface.

## Remarks

## See also