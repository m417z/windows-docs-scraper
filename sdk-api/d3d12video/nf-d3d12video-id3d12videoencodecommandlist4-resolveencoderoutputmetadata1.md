## Description

Resolves encoder output metadata into a readable format, with support for optional metadata outputs including QP maps, SATD maps, bit allocation maps, and PSNR data.

## Parameters

### `pInputArguments`

A pointer to a [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_input_arguments1) specifying the input arguments for the resolve operation.

### `pOutputArguments`

A pointer to a [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments1) specifying the output arguments for the resolve operation.

## Remarks

This method extends [ID3D12VideoEncodeCommandList2::ResolveEncoderOutputMetadata](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-resolveencoderoutputmetadata) by accepting [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_input_arguments1) and [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments1), which include optional metadata support.

## See also

[ID3D12VideoEncodeCommandList2::ResolveEncoderOutputMetadata](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-resolveencoderoutputmetadata)

[D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_input_arguments1)

[D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments1)