## Description

The **D3D12DDIARG_CREATE_VIDEO_ENCODER_0082_0** structure contains the encoder creation parameters for the [**PFND3D12DDI_CALCPRIVATEVIDEOENCODERSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoencodersize_0082_0) and [**PFND3D12DDI_CREATEVIDEOENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoder_0082_0) callback functions.

## Members

### `NodeMask`

For a single GPU operation, set **NodeMask** to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only one bit can be set.

### `Flags`

A [**D3D12DDI_VIDEO_ENCODER_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_flags_0080) value that specifies the encoder creation flags.

### `EncodeCodec`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_0080) value that identifies the codec type.

### `EncodeProfile`

A [**D3D12DDI_VIDEO_ENCODER_PROFILE_DESC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_profile_desc_0080_2) structure that identifies the codec's profile.

### `InputFormat`

A [**DXGI_FORMAT**](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) structure that indicates the format of the source stream.

### `CodecConfiguration`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0082_0) structure that indicates the sequence-level codec-specific parameters.

### `MaxMotionEstimationPrecision`

A [**D3D12DDI_VIDEO_ENCODER_MOTION_ESTIMATION_PRECISION_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_motion_estimation_precision_mode_0080) value that identifies the motion estimation precision mode.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**PFND3D12DDI_CALCPRIVATEVIDEOENCODERSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_calcprivatevideoencodersize_0082_0)

[**PFND3D12DDI_CREATEVIDEOENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoder_0082_0)