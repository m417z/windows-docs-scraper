## Description

**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODES_0082_0** values correspond with the block edge filtering configuration values identified by the *disable_deblocking_filter_idc* syntax in the H.264 specification.

## Constants

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_0_ALL_LUMA_CHROMA_SLICE_BLOCK_EDGES_ALWAYS_FILTERED`

When set, always filter all luma and chroma block edges of the slice. Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_0_ALL_LUMA_CHROMA_SLICE_BLOCK_EDGES_ALWAYS_FILTERED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) flag for support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_1_DISABLE_ALL_SLICE_BLOCK_EDGES`

When set, deblocking is disabled for all block edges of the slice. Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_1_DISABLE_ALL_SLICE_BLOCK_EDGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) flag for support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_2_DISABLE_SLICE_BOUNDARIES_BLOCKS`

When set, filter all luma and chroma block edges of the slice except for the block edges that coincide with slice boundaries. Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_2_DISABLE_SLICE_BOUNDARIES_BLOCKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) flag for support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_3_USE_TWO_STAGE_DEBLOCKING`

When set, indicates a two-stage deblocking filter process for the slice:

1. Filter all luma and chroma block edges that do not coincide with slice boundaries (like **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_2_DISABLE_SLICE_BOUNDARIES_BLOCKS**).
2. Filter the luma and chroma block edges that coincide with slice boundaries.

Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_3_USE_TWO_STAGE_DEBLOCKING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) flag for support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_4_DISABLE_CHROMA_BLOCK_EDGES`

When set, filter all luma block edges of the slice. The deblocking for chroma block edges is disabled. Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_4_DISABLE_CHROMA_BLOCK_EDGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) flag for support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_5_DISABLE_CHROMA_BLOCK_EDGES_AND_LUMA_BOUNDARIES`

When set, filter all luma block edges of the slice with the exception of the block edges that coincide with slice boundaries (like **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_2_DISABLE_SLICE_BOUNDARIES_BLOCKS**). Deblocking for chroma block edges of the slice is disabled. Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_5_DISABLE_CHROMA_BLOCK_EDGES_AND_LUMA_BOUNDARIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) flag for support.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_6_DISABLE_CHROMA_BLOCK_EDGES_AND_USE_LUMA_TWO_STAGE_DEBLOCKING`

When set, the deblocking for chroma block edges is disabled. Use the two-stage deblocking filter process for luma block edges of the slice:

1. Filter all luma block edges that do not coincide with slice boundaries (like **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_2_DISABLE_SLICE_BOUNDARIES_BLOCKS**).
2. Filter the luma block edges that coincide with slice boundaries.

Check the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_6_DISABLE_CHROMA_BLOCK_EDGES_AND_USE_LUMA_TWO_STAGE_DEBLOCKING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0) flag for support.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_mode_flags_0082_0)

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_0080_2)

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_flags_0080)