## Description

A flags enumeration allowing bitwise OR combinations of values from the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODES](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_h264_slices_deblocking_modes) which specifies the slice deblocking mode as defined by the *disable_deblocking_filter_idc* syntax in the H.264 specification.

## Constants

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_0_ALL_LUMA_CHROMA_SLICE_BLOCK_EDGES_ALWAYS_FILTERED`

*disable_deblocking_filter_idc* value of 0. All luma and chroma block edges of the slice are filtered.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_1_DISABLE_ALL_SLICE_BLOCK_EDGES`

*disable_deblocking_filter_idc* value of 1. Deblocking is disabled for all block edges of the slice.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_2_DISABLE_SLICE_BOUNDARIES_BLOCKS`

*disable_deblocking_filter_idc* value of 2. All luma and chroma block edges of the slice are filtered with exception of the block edges that coincide with slice boundaries

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_3_USE_TWO_STAGE_DEBLOCKING`

*disable_deblocking_filter_idc* value of 3. A two stage deblocking filter process for the slice: After filtering all block luma and chroma block edges that do not coincide with slice boundaries (as if disable_deblocking_filter_idc were equal to 2), the luma and chroma block edges that coincide with slice boundaries are filtered.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_4_DISABLE_CHROMA_BLOCK_EDGES`

*disable_deblocking_filter_idc* value of 4. All luma block edges of the slice are filtered, but the Rec. ITU-T H.264 (06/2019) 477
deblocking of the chroma block edges is disabled.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_5_DISABLE_CHROMA_BLOCK_EDGES_AND_LUMA_BOUNDARIES`

*disable_deblocking_filter_idc* value of 5. All luma block edges of the slice are filtered with exception of the block edges that coincide with slice boundaries (as if disable_deblocking_filter_idc were equal to 2), and that deblocking for chroma block edges of the slice is disabled. 5

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_SLICES_DEBLOCKING_MODE_FLAG_6_DISABLE_CHROMA_BLOCK_EDGES_AND_USE_LUMA_TWO_STAGE_DEBLOCKING`

*disable_deblocking_filter_idc* of 6. The deblocking for chroma block edges is disabled and that the two stage deblocking filter process is used for luma block edges of the slice: After filtering all block luma block edges that do not coincide with slice boundaries (as if disable_deblocking_filter_idc were equal to 2), the luma block edges that coincide
with slice boundaries are filtered.

## Remarks

Values from this enumeration are used by the [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration_support_h264) structure for checking feature support.

## See also