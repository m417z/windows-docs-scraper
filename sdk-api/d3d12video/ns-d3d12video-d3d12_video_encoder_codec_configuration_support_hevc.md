## Description

Represents encoder codec configuration support for HEVC encoding.

## Members

### `SupportFlags`

A bitwise OR combination of flags from the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_support_hevc_flags) specifying which optional features are supported for the codec.

### `MinLumaCodingUnitSize`

The minimum luma coding block size requested. This value must match what the caller will code in the sequence parameter set (SPS).

### `MaxLumaCodingUnitSize`

The maximum luma coding block size requested. This value matches what the user will code in SPS.

### `MinLumaTransformUnitSize`

The minimum luma transform block size requested. This value matches the pixel size of what the user will code in SPS.log2_min_luma_transform_block_size_minus2.

### `MaxLumaTransformUnitSize`

The maximum luma transform block size requested. This value must be consistent with the pixel size the user will code in SPS.log2_diff_max_min_luma_transform_block_size. The variable MaxTbLog2SizeY is set equal to log2_min_luma_transform_block_size_minus2 + 2 + log2_diff_max_min_luma_transform_block_size.

### `max_transform_hierarchy_depth_inter`

The maximum hierarchy depth for transform units of coding units coded in inter prediction mode. The value of max_transform_hierarchy_depth_inter shall be in the range of 0 to CtbLog2SizeY − MinTbLog2SizeY, inclusive.

### `max_transform_hierarchy_depth_intra`

Specifies the maximum hierarchy depth for transform units of coding units coded in intra prediction mode. The value of max_transform_hierarchy_depth_intra shall be in the range of 0 to CtbLog2SizeY − MinTbLog2SizeY, inclusive.

## Remarks

## See also