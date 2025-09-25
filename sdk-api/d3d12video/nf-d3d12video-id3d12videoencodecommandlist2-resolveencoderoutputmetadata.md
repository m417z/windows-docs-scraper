## Description

Resolves the output metadata from a call to [ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) to a readable format.

## Parameters

### `pInputArguments`

A pointer to a [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_input_arguments), containing a pointer to the opaque [D3D12_VIDEO_ENCODER_OUTPUT_METADATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_output_metadata) received from a previous call to **EncodeFrame**.

### `pOutputArguments`

A pointer to a [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments), containing a pointer to the [D3D12_VIDEO_ENCODER_OUTPUT_METADATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_output_metadata) where the resolved, readable metadata will be written.

## Remarks

The caller can interpret the contents of *pOutputArguments* as a memory blob that contains a [D3D12_VIDEO_ENCODER_OUTPUT_METADATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_output_metadata) structure and the metadata array contents. The array contents of the dynamic size metadata based on the subregion number are positioned in memory contiguously right after the struct allocation and the pointers in the struct point to the start addresses of the array contents.

## See also