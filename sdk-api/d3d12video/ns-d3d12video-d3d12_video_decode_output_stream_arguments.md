# D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS structure

## Description

Specifies the parameters for the output stream for a video decode operation. [D3D12_VIDEO_DECODE_OUTPUT_STREAM_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_output_stream_arguments1) is used for the same purpose, but provides an additional field for histograms.

## Members

### `pOutputTexture2D`

An [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) representing the output texture. If decode conversion is enabled, this texture will contain the post-conversion output. If decode conversion is not enabled, this texture will contain the decode output.

### `OutputSubresource`

The index of the output subresource of *pOutputTexture2D* to use. This allows you to specify array indices if the output is an array.

### `ConversionArguments`

An optional [D3D12_VIDEO_DECODE_CONVERSION_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_conversion_arguments) structure containing output conversion parameters.

## Remarks

## See also