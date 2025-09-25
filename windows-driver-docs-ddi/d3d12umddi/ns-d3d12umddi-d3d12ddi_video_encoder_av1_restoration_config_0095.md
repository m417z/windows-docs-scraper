## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_CONFIG_0095** structure provides configuration details for the restoration features of an AV1 video encoder.

## Members

### `FrameRestorationType[3]`

A [**D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TYPE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_restoration_type_0095) enumeration that specifies the restoration type for each plane.

### `LoopRestorationPixelSize[3]`

A [**D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_restoration_tilesize_0095) enumeration that specifies the size of the restoration tile for each plane.

## Remarks

This structure is related to AV1 syntax lr_params(). The array entries correspond to Y, U, V planes.

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)