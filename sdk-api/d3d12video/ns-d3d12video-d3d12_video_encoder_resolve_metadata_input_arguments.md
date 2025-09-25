## Description

Represents input arguments for a call to [ID3D12VideoEncodeCommandList2::ResolveEncoderOutputMetadata](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-resolveencoderoutputmetadata).

## Members

### `EncoderCodec`

A [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) specifying the codec of the associated encode operation.

### `EncoderProfile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) specifying the profile for the selected codec in the associated encode operation.

### `EncoderInputFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) specifying the input format of the associated encode operation.

### `EncodedPictureEffectiveResolution`

A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) structure describing the resolution used for the encoding operation.

### `HWLayoutMetadata`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) representing the associated opaque metadata buffer received from [EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe).

## Remarks

## See also