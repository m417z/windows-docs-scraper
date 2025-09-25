## Description

Represents output arguments for a call to [ID3D12VideoEncodeCommandList2::ResolveEncoderOutputMetadata](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-resolveencoderoutputmetadata).

## Members

### `ResolvedLayoutMetadata`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) representing the resolved metadata buffer.

This buffer must be read back to the CPU by the caller and cast to a [D3D12_VIDEO_ENCODER_OUTPUT_METADATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_output_metadata) structure. The remaining data in the buffer, corresponds to **D3D12_VIDEO_ENCODER_OUTPUT_METADATA.WrittenSubregionsCount** packed entries of type [D3D12_VIDEO_ENCODER_FRAME_SUBREGION_METADATA](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_frame_subregion_metadata).

## Remarks

The following diagram illustrates the resolved metadata memory layout in an ID3D12Resource.

:::image type="content" source="images/d3d12-video-resolved-metadata-layout.png" alt-text="Diagram of the resolved metadata memory layout in an ID3D12Resource":::

## See also