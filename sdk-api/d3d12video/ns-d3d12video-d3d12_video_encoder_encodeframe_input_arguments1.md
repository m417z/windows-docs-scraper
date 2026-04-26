## Description

Represents input arguments for [ID3D12VideoEncodeCommandList4::EncodeFrame1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-encodeframe1), with support for optional metadata.

## Members

### `SequenceControlDesc`

A [D3D12_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_sequence_control_desc) specifying the configuration for the video encoding sequence.

### `PictureControlDesc`

A [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_desc) specifying the configuration for the video encoding picture.

### `pInputFrame`

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) representing the input frame to encode.

### `InputFrameSubresource`

The subresource index of the input frame.

### `CurrentFrameBitstreamMetadataSize`

The expected size in bytes of the current frame bitstream metadata.

### `OptionalMetadata`

A [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags) value indicating which optional metadata to enable when encoding this frame.

## Remarks

This structure extends [D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_input_arguments) with the *OptionalMetadata* field.

## See also

[ID3D12VideoEncodeCommandList4::EncodeFrame1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-encodeframe1)

[D3D12_VIDEO_ENCODER_ENCODEFRAME_INPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encodeframe_input_arguments)