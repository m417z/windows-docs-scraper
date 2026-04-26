## Description

Encodes a bitstream, with support for subregion notification.

## Parameters

### `pEncoder`

A [ID3D12VideoEncoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoder) representing the video encoder to be used for the encode operation.

### `pHeap`

A [ID3D12VideoEncoderHeap](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videoencoderheap) representing the video encoder heap to be used for this operation.

The encoder heap object allocation must not be released before any in-flight GPU commands that reference it finish execution.

### `pInputArguments`

A pointer to a [D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_input_arguments1) representing input arguments for the encode operation.

### `pOutputArguments`

A pointer to a [D3D12_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_output_arguments1) representing output arguments for the encode operation.

## Remarks

This method extends [ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) by accepting [D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_input_arguments1) for optional metadata support and [D3D12_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_output_arguments1) for subregion notification support.

The video encoder and video encoder heap may be used to record commands from multiple command lists, but may only be associated with one command list at a time. The application is responsible for synchronizing single accesses to the video encoder and video encoder heap at a time.

## See also

[ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe)