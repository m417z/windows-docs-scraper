## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0082_0** structure contains user-requested HEVC configuration parameters for HEVC encoding.

## Members

### `SupportFlags`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_flags_0082_0) value that indicates which optional feature(s) are requested for the codec.

### `MinLumaCodingUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_cusize_0080) value that indicates the requested minimum luma coding block size. This value matches the value used by the user in the sequence parameter set (SPS).

### `MaxLumaCodingUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_cusize_0080) value that indicates the requested maximum luma coding block size. This value matches the value used by the user in the sequence parameter set (SPS).

### `MinLumaTransformUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_tusize_0082_0) value that indicates the requested minimum luma transform block size. This value must be consistent with the pixel size coded by the user in *SPS.log2_min_luma_transform_block_size_minus2*.

### `MaxLumaTransformUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_tusize_0082_0) value that indicates the requested maximum luma transform block size. This value must by consistent with the pixel size the coded by the user in *SPS.log2_diff_max_min_luma_transform_block_size*. The variable *MaxTbLog2SizeY* is set equal to *log2_min_luma_transform_block_size_minus2 plus 2 plus log2_diff_max_min_luma_transform_block_size*.

### `max_transform_hierarchy_depth_inter`

The maximum hierarchy depth for transform units of coding units coded in inter prediction mode. This value is in the range of zero to *CtbLog2SizeY minus MinTbLog2SizeY*, inclusive.

### `max_transform_hierarchy_depth_intra`

The maximum hierarchy depth for transform units of coding units coded in intra prediction mode. This value is in the range of zero to *CtbLog2SizeY minus MinTbLog2SizeY*, inclusive.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0)