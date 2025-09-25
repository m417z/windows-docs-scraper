# D3D12_VIDEO_DECODE_INPUT_STREAM_ARGUMENTS structure

## Description

Specifies the parameters for the input stream for a video decode operation.

## Members

### `NumFrameArguments`

The count of frame parameters provided in the *FrameArguments* field. The maximum number of frame arguments is 10.

### `FrameArguments`

An array of [D3D12_VIDEO_DECODE_FRAME_ARGUMENT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_frame_argument) structures containing the parameters to decode a frame.

### `ReferenceFrames`

A [D3D12_VIDEO_DECODE_REFERENCE_FRAMES](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_reference_frames) structure containing the reference frames needed to decode a frame.

### `CompressedBitstream`

A [D3D12_VIDEO_DECODE_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_compressed_bitstream) structure representing the compressed bitstream in a single continuous buffer.

### `pHeap`

An [ID3D12VideoDecoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoderheap) representing a pointer to the heap for the current decode resolution.

## Remarks

## See also