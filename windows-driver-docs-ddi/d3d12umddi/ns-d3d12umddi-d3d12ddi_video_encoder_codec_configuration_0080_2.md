## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0080_2** structure contains configuration information for a video codec. Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0082_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pH264Config`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_0080_2) structure that contains H.264 codec configuration information.

### `pHEVCConfig`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_0080_2) structure that contains HEVC codec configuration information.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0082_0) for full video encoding feature support for Windows 11 (WDDM 3.0).