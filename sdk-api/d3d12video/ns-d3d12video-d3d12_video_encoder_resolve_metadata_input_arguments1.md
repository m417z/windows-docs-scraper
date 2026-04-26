## Description

Represents input arguments for [ID3D12VideoEncodeCommandList4::ResolveEncoderOutputMetadata1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveencoderoutputmetadata1), with support for optional metadata.

## Members

### `EncoderCodec`

A [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) specifying the codec of the associated encode operation.

### `EncoderProfile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) specifying the profile for the selected codec in the associated encode operation.

### `EncoderInputFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) specifying the input format of the associated encode operation.

### `EncodedPictureEffectiveResolution`

A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) describing the resolution used for the encoding operation.

### `HWLayoutMetadata`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) representing the opaque metadata buffer received from [EncodeFrame1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-encodeframe1).

### `OptionalMetadata`

A [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags) value indicating which optional metadata was enabled during encoding and needs layout resolving.

### `CodecConfiguration`

A [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration) specifying the codec configuration used in the associated **EncodeFrame1** call. Required when any flags are set in *OptionalMetadata*; otherwise pass as zeroed/NULL.

## Remarks

This structure extends [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_input_arguments) with *OptionalMetadata* and *CodecConfiguration* fields.

## See also

[ID3D12VideoEncodeCommandList4::ResolveEncoderOutputMetadata1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveencoderoutputmetadata1)

[D3D12_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_input_arguments)