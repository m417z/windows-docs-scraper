## Description

Represents output arguments for [ID3D12VideoEncodeCommandList4::ResolveEncoderOutputMetadata1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveencoderoutputmetadata1), with support for optional metadata outputs including QP maps, SATD maps, bit allocation maps, and PSNR data.

## Members

### `ResolvedLayoutMetadata`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) containing the mandatory resolved metadata. The resolved layout is unchanged from previous versions.

### `pOutputQPMap`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) texture for QP map output. Can be **NULL** if **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_QP_MAP** is not set. When present, the texture format must be **DXGI_FORMAT_R8_SINT** for H.264 and HEVC, or **DXGI_FORMAT_R8_UINT** for AV1. Dimensions must match *EncoderOutputMetadataQPMapTextureDimensions* from [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements1).

### `pOutputSATDMap`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) texture for SATD map output. Can be **NULL** if **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SATD_MAP** is not set. When present, the texture format must be **DXGI_FORMAT_R32_UINT**. Dimensions must match *EncoderOutputMetadataSATDMapTextureDimensions* from [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements1).

### `pOutputBitAllocationMap`

A pointer to an [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) texture for bit allocation map output. Can be **NULL** if **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_RC_BIT_ALLOCATION_MAP** is not set. When present, the texture format must be **DXGI_FORMAT_R32_UINT**. Dimensions must match *EncoderOutputMetadataBitAllocationMapTextureDimensions* from [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements1).

### `ResolvedFramePSNRData`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) for frame-level PSNR data. The associated **ID3D12Resource** can be **NULL** if **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_FRAME_PSNR** is not set. When present, the resource must be a **D3D12_RESOURCE_DIMENSION_BUFFER** with *Width* set to `sizeof(D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_PSNR_RESOLVED_LAYOUT)`. The contents are interpreted as [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_PSNR_RESOLVED_LAYOUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_psnr_resolved_layout).

### `ResolvedSubregionsPSNRData`

A [D3D12_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_encode_operation_metadata_buffer) for subregion-level PSNR data. The associated **ID3D12Resource** can be **NULL** if **D3D12_VIDEO_ENCODER_OPTIONAL_METADATA_ENABLE_FLAG_SUBREGIONS_PSNR** is not set. When present, the resource must be a **D3D12_RESOURCE_DIMENSION_BUFFER** with *Width* matching *EncoderOutputMetadataSubregionsPSNRResolvedMetadataBufferSize* from [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS1](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements1). The contents are interpreted as a packed array of [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_PSNR_RESOLVED_LAYOUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_psnr_resolved_layout) with one element per subregion.

## Remarks

This structure extends [D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments) with optional metadata outputs.

## See also

[ID3D12VideoEncodeCommandList4::ResolveEncoderOutputMetadata1](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist4-resolveencoderoutputmetadata1)

[D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_arguments)

[D3D12_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_PSNR_RESOLVED_LAYOUT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_resolve_metadata_output_psnr_resolved_layout)