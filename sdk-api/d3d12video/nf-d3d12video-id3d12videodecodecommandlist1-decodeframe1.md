# ID3D12VideoDecodeCommandList1::DecodeFrame1

## Description

Records a decode frame operation to the command list. Inputs, outputs, and parameters for the decode are specified as arguments to this method. Takes a [D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_output_stream_arguments1) structure to support video decode histograms.

## Parameters

### `pDecoder`

A pointer to an [ID3D12VideoDecoder](https://learn.microsoft.com/windows/win32/api/d3d12video/nn-d3d12video-id3d12videodecoder) interface representing a decoder instance.

### `pOutputArguments`

A [D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_output_stream_arguments1) structure specifying the output surface and output arguments.

### `pInputArguments`

A [D3D12_VIDEO_DECODE_INPUT_STREAM_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_input_stream_arguments) structure specifying the input bitstream, reference frames, and other input parameters.

## Remarks

## See also