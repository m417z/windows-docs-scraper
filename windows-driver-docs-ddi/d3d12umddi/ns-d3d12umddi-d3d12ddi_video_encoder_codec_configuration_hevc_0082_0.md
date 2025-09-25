## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_0082_0** structure contains configuration information for an HEVC (H.265) codec.

## Members

### `ConfigurationFlags`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_flags_0082_0) value that defines the set of enabled features. Flags can be combined.

### `MinLumaCodingUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_cusize_0080) value that indicates the minimum luma coding block size to be used in the encoder. This value matches the value coded by the user in the Sequence Parameter Set (SPS).

### `MaxLumaCodingUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_cusize_0080) value that indicates the maximum luma coding block size to be used in the encoder. This value matches the value coded by the user in the SPS.

### `MinLumaTransformUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_tusize_0082_0) value that indicates the minimum luma transform block size to be used in the encoder. This value matches the pixel size coded by the user in *SPS.log2_min_luma_transform_block_size_minus2*.

### `MaxLumaTransformUnitSize`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_tusize_0082_0) value that indicates the maximum luma transform block size to be used in the encoder. This value must be consistent with the pixel size coded by the user in *SPS.log2_diff_max_min_luma_transform_block_size*. The variable *MaxTbLog2SizeY* is set equal to ```log2_min_luma_transform_block_size_minus2 + 2 + log2_diff_max_min_luma_transform_block_size```.

### `max_transform_hierarchy_depth_inter`

Indicates for the associated encoder, the maximum hierarchy depth for transform units of coding units coded in inter prediction mode. The value of **max_transform_hierarchy_depth_inter** must be in the range of 0 to ```CtbLog2SizeY − MinTbLog2SizeY```, inclusive. The value of **max_transform_hierarchy_depth_inter** must be consistent with the user-coded SPS headers.

### `max_transform_hierarchy_depth_intra`

Indicates for the associated encoder, the maximum hierarchy depth for transform units of coding units coded in intra prediction mode. The value of **max_transform_hierarchy_depth_intra** must be in the range of 0 to ```CtbLog2SizeY − MinTbLog2SizeY```, inclusive. The value of **max_transform_hierarchy_depth_intra** must be consistent with the user-coded SPS headers.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0082_0)