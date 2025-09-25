## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_0080_2** structure contains configuration information for an HEVC (H.265) codec. Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_0082_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## Members

### `ConfigurationFlags`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_flags_0080) value that defines the set of enabled features. Flags can be combined.

### `MinLumaCodingUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_cusize_0080) value that indicates the minimum luma coding block size to be used in the encoder. This value matches the value coded by the user in the Sequence Parameter Set (SPS).

### `MaxLumaCodingUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_cusize_0080) value that indicates the maximum luma coding block size to be used in the encoder. This value matches the value that coded by the user in the SPS.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_0082_0) for full video encoding feature support for Windows 11 (WDDM 3.0).