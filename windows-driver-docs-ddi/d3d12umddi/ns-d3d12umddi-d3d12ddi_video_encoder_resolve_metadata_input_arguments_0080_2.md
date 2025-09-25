## Description

The **D3D12DDI_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS_0080_2** structure contains input arguments for a call to [**PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_resolve_output_metadata_0082_0).

## Members

### `EncoderCodec`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that specifies the codec of the associated encode operation.

### `EncoderProfile`

A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure that specifies the profile of the associated operation.

### `EncoderInputFormat`

A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) value that specifies the input format of the associated operation.

### `EncodedPictureEffectiveResolution`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structure that specifies the encoded resolution of the associated frame.

### `HWLayoutEncoderMetadataDrvBuffer`

A [**D3D12DDI_VIDEO_ENCODER_ENCODE_OPERATION_METADATA_BUFFER_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encode_operation_metadata_buffer_0080_2) structure that represents the associated opaque metadata buffer received from an [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) operation.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_resolve_output_metadata_0082_0)