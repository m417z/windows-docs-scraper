## Description

**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAGS_0082_0** values are used to indicate codec support for various block edge filtering modes.

## Constants

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_NONE`

No flags are set.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_0_ALL_LUMA_CHROMA_SLICE_BLOCK_EDGES_ALWAYS_FILTERED`

Indicates whether support is available to filter all luma and chroma block edges of a slice.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_1_DISABLE_ALL_SLICE_BLOCK_EDGES`

Indicates whether support is available to disable deblocking for all block edges of a slice.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_2_DISABLE_SLICE_BOUNDARIES_BLOCKS`

Indicates whether support is available to filter all luma and chroma block edges of a slice except for the block edges that coincide with slice boundaries.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_3_USE_TWO_STAGE_DEBLOCKING`

Indicates whether support is available to perform a two-stage deblocking process a slice. See [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODES_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_modes_0082_0) for details.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_4_DISABLE_CHROMA_BLOCK_EDGES`

Indicates whether support is available to filter all luma block edges of a slice (deblocking for chroma block edges of a slice is disabled).

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_5_DISABLE_CHROMA_BLOCK_EDGES_AND_LUMA_BOUNDARIES`

Indicates whether support is available to filter all luma block edges of a slice *with the exception of the block edges that coincide with slice boundaries* (deblocking for chroma block edges of a slice is disabled).

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_0082_0_FLAG_6_DISABLE_CHROMA_BLOCK_EDGES_AND_USE_LUMA_TWO_STAGE_DEBLOCKING`

Indicates whether support is available to disable the deblocking for chroma block edges *and* to use a two-stage deblocking filter process for luma block edges of a slice. See [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODES_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_modes_0082_0) for details.

## Remarks

**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAGS_0082_0** support flags correspond to the [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODES_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_modes_0082_0) mode values.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_0080_2)

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODES_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_slices_deblocking_modes_0082_0)

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0)