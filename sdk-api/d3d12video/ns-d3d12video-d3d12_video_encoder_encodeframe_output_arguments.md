## Description

Represents output arguments to [ID3D12VideoEncodeCommandList2::EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe).

## Members

### `Bitstream`

A [A D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream) containing the result of the encoding operation.

### `ReconstructedPicture`

A [D3D12_VIDEO_ENCODER_RECONSTRUCTED_PICTURE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_reconstructed_picture) representing a reconstructed picture generated from the input frame. This resource is only needed if the encoded picture is marked to be used as a reference picture in the corresponding picture control structure for this encode operation, NULL can be set otherwise as the reconstructed picture will not be written in the output.

### `EncoderOutputMetadata`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) representing encoding metadata returned by the encoder in hardware-specific layout. This data must be resolved into a readable format using [ID3D12VIDEOCOMMANDLIST2::ResolveEncoderOutputMetadata](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-resolveencoderoutputmetadata).

## Remarks

The caller must check for alignment requirements for the output resources used for the encoding operation.

## See also