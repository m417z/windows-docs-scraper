## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_0082_0** structure is used to represent a codec-specific configuration for video encoding.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pH264Support`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0) structure that contains configuration support parameters for H.264 encoding.

### `pHEVCSupport`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0082_0) structure that contains configuration support parameters for HEVC encoding.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_0083_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_0083_0)