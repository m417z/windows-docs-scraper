## Description

Retrieves resource requirements for video encoding, with support for optional metadata. Used with [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) and the **D3D12_FEATURE_VIDEO_ENCODER_RESOURCE_REQUIREMENTS1** feature value.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (one of the device's physical adapters) to which the command queue applies. Each bit in the mask corresponds to a single node. Only one bit must be set.

### `Codec`

A [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) specifying the codec to query.

### `Profile`

A [D3D12_VIDEO_ENCODER_PROFILE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_profile_desc) specifying the encoder profile.

### `InputFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) specifying the input format.

### `PictureTargetResolution`

A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) specifying the target resolution.

### `IsSupported`

Output. Indicates whether the configuration is supported.

### `CompressedBitstreamBufferAccessAlignment`

Output. The required alignment for the compressed bitstream buffer.

### `EncoderMetadataBufferAccessAlignment`

Output. The required alignment for the encoder metadata buffer.

### `MaxEncoderOutputMetadataBufferSize`

Output. The maximum size in bytes of the encoder output metadata buffer.

### `OptionalMetadata`

A [D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags) value indicating which optional metadata is requested.

### `CodecConfiguration`

A [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration) specifying the codec configuration. Required when any flags are set in *OptionalMetadata*; otherwise pass as zeroed/NULL.

### `EncoderOutputMetadataQPMapTextureDimensions`

Output. A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) indicating the texture dimensions for the QP map output. Valid when **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_QP_MAP** is set. The block size can be derived by dividing *PictureTargetResolution* by these dimensions.

### `EncoderOutputMetadataSATDMapTextureDimensions`

Output. A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) indicating the texture dimensions for the SATD map output. Valid when **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SATD_MAP** is set. The block size can be derived by dividing *PictureTargetResolution* by these dimensions.

### `EncoderOutputMetadataBitAllocationMapTextureDimensions`

Output. A [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) indicating the texture dimensions for the bit allocation map output. Valid when **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_RC_BIT_ALLOCATION_MAP** is set. The block size can be derived by dividing *PictureTargetResolution* by these dimensions.

### `EncoderOutputMetadataFramePSNRComponentsNumber`

Output. The number of PSNR components (Y, U, and V in that order) written for frame-level PSNR. Valid when **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_FRAME_PSNR** is set.

### `EncoderOutputMetadataSubregionsPSNRComponentsNumber`

Output. The number of PSNR components (Y, U, and V in that order) written per subregion. Valid when **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SUBREGIONS_PSNR** is set.

### `EncoderOutputMetadataSubregionsPSNRResolvedMetadataBufferSize`

Output. The required *Width* size of the buffer for subregion PSNR data. Valid when **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SUBREGIONS_PSNR** is set.

## Remarks

When *OptionalMetadata* is **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_NONE**, the outputs that are also present in [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements) must report identical values for backward compatibility. Output fields for non-selected optional metadata flags are reported as zero.

## See also

[D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements)

[D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_optional_metadata_enable_flags)