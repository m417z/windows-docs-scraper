## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0** structure contains configuration information for a video codec.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pH264Config`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_0082_0) structure that contains H.264 codec configuration information.

### `pHEVCConfig`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_0082_0) structure that contains HEVC codec configuration information.

### `pAV1Config`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_0095) structure that contains AV1 codec configuration information. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDIARG_CREATE_VIDEO_ENCODER_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_video_encoder_0082_0)

[**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support_data_0083_0)