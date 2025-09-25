## Description

The **D3D12DDICAPS_VIDEO_ENCODER_RESOURCE_REQUIREMENTS_DATA_0080_2** structure specifies resource access requirements.

## Members

### `NodeIndex`

[in] In a multi-adapter operation, **NodeIndex** indicates which physical adapter of the device that the operation applies to.

### `Codec`

[in] A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that specifies the codec to check support for.

### `Profile`

[in] A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure that specifies the profile to check support for.

### `InputFormat`

[in] A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) value that specifies the input format of the input frames.

### `PictureTargetResolution`

[in] A [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structure that indicates the picture resolution for which resource requirements are being queried.

### `IsSupported`

[out] Indicates whether the given input values are supported.

### `CompressedBitstreamBufferAccessAlignment`

[out] Indicates the alignment required in bytes for the resource to be passed in the **hDrvBuffer** and **Offset** members of [**D3D12DDI_VIDEO_ENCODER_COMPRESSED_BITSTREAM_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_compressed_bitstream_0080). If no alignment is required, the driver should report 1 to indicate 1 byte (trivial) alignment.

### `EncoderMetadataBufferAccessAlignment`

[out] Indicates the alignment required in bytes for the resource to be passed in [**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_OUTPUT_STREAM_ARGUMENTS_0080_2.HWLayoutEncoderMetadataDrvBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_output_stream_arguments_0080_2). If no alignment is required, the driver should report 1 to convey 1 byte (trivial) alignment.

### `MaxEncoderOutputMetadataBufferSize`

[out] Indicates the maximum size in bytes needed for the resource that will be allocated by the host and used as output in [**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) for output encoder metadata based on the input arguments.

## Remarks

The D3D runtime calls [**PFND3D12DDI_VIDEO_GETCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with [**D3D12DDICAPS_TYPE_VIDEO_0080_ENCODER_RESOURCE_REQUIREMENTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddicaps_type_video_0020) specified as the capability type.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_VIDEO_GETCAPS_0020**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_video_getcaps_0020)