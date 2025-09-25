## Description

Represents codec configuration for HEVC encoding.

## Members

### `ConfigurationFlags`

A bitwise OR combination of flags from the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_hevc_flags) enumeration defining the set of enabled codec features.

### `MinLumaCodingUnitSize`

A value from the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_hevc_cusize) enumeration indicating the minimum luma coding block size to be used in the encoder. This value matches what the caller will code in SPS.

### `MaxLumaCodingUnitSize`

A value from the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_CUSIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_hevc_cusize) enumeration indicating the maximum luma coding block size to be used in the encoder. This value matches what the caller will code in SPS.

### `MinLumaTransformUnitSize`

A value from the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_hevc_tusize) enumeration indicating the minimum luma transform block size to be used in the encoder. This value matches the pixel size of what the user will code in SPS.log2_min_luma_transform_block_size_minus2.

### `MaxLumaTransformUnitSize`

D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE

A value from the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_TUSIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_hevc_tusize) enumeration indicating the maximum luma transform block size to be used in the encoder. This value has to be consistent with the pixel size the user will code in SPS.log2_diff_max_min_luma_transform_block_size. The variable MaxTbLog2SizeY is set equal to log2_min_luma_transform_block_size_minus2 + 2 + log2_diff_max_min_luma_transform_block_size.

### `max_transform_hierarchy_depth_inter`

A UCHAR indicating the maximum hierarchy depth for transform units of coding units coded in inter prediction mode. The value of max_transform_hierarchy_depth_inter shall be in the range of 0 to CtbLog2SizeY − MinTbLog2SizeY, inclusive. The value indicated here must be consistent with the caller-coded SPS headers.

### `max_transform_hierarchy_depth_intra`

A UCHAR indicating the maximum hierarchy depth for transform units of coding units coded in intra prediction mode. The value of max_transform_hierarchy_depth_intra shall be in the range of 0 to CtbLog2SizeY − MinTbLog2SizeY, inclusive. The value indicated here must be consistent with the caller-coded SPS headers.

## Remarks

## See also