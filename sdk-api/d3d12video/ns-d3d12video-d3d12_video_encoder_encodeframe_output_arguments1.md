## Description

Represents output arguments for [ID3D12VideoEncodeCommandList4::EncodeFrame1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-encodeframe1), with support for subregion notification.

## Members

### `Bitstream`

A [D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream1) containing the result of the encoding operation.

### `ReconstructedPicture`

A [D3D12_VIDEO_ENCODER_RECONSTRUCTED_PICTURE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_reconstructed_picture) representing a reconstructed picture generated from the input frame. This resource is only needed if the encoded picture is marked to be used as a reference picture in the corresponding picture control structure. Set to NULL otherwise.

### `EncoderOutputMetadata`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) representing encoding metadata returned by the encoder in hardware-specific layout. This data must be resolved into a readable format using [ID3D12VideoEncodeCommandList2::ResolveEncoderOutputMetadata](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-resolveencoderoutputmetadata).

### `FrameAnalysisReconstructedPicture`

A [D3D12_VIDEO_ENCODER_RECONSTRUCTED_PICTURE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_reconstructed_picture) for the frame analysis reconstructed picture, used with the frame analysis (two-pass encoding) feature.

## Remarks

The caller must check for alignment requirements for the output resources used in the encoding operation.

## See also

[ID3D12VideoEncodeCommandList4::EncodeFrame1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-encodeframe1)

[D3D12_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_output_arguments)