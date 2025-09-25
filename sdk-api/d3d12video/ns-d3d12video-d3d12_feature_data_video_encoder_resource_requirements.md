## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves values indicating resource requirements for video encoding with the specified encoding configuration.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which resource requirements are being queried.

### `Profile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) structure specifying the profile for which resource requirements are being queried.

### `InputFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) structure representing the input format for which resource requirements are being queried.

### `PictureTargetResolution`

A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) structure representing the resolution for which resource requirements are being queried.

### `IsSupported`

Receives a boolean value indicating if the specified parameters are supported.

### `CompressedBitstreamBufferAccessAlignment`

Receives a UINT indicating the alignment required in bytes for the resource to be passed in [D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM.pBuffer](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_compressed_bitstream) and **D3D12_VIDEO_ENCODER_COMPRESSED_BITSTREAM.Offset**. If no alignment is required, 1 should is returned to indicate 1 byte (trivial) alignment.

### `EncoderMetadataBufferAccessAlignment`

Receives a UINT indicating the alignment required in bytes for the resource to be passed in D3D12_VIDEO_ENCODER_OUTPUT_ARGUMENTS.pEncoderOutputMetadata. If no alignment required, 1 should be reported to convey 1 byte (trivial) alignment.

### `MaxEncoderOutputMetadataBufferSize`

Receives a UINT indicating the maximum size in bytes needed for the [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) that will be allocated by the host and used as output in the [EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) for output encoder metadata based on the input arguments.

## Remarks

## See also

[DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)

[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)

[EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe)