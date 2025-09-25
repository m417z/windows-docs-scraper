## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_0083_0** structure is used to represent a codec-specific configuration for video encoding.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pH264Support`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0) structure that contains configuration support parameters for H.264 encoding.

### `pHEVCSupport`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0) structure that contains configuration support parameters for HEVC encoding.

### `pAV1Support`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_support_0095) structure that contains configuration support parameters for AV1 encoding. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDICAPS_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_codec_configuration_support_data_0083_0)