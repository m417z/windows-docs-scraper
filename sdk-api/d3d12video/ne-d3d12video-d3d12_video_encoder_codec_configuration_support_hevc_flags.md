## Description

Specifies configuration support flags for HEVC video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_BFRAME_LTR_COMBINED_SUPPORT`

Support for usage of B frames and long term references frames simultaneously.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT`

Support for slice-contrained encoding, in which every slice in a frame is encoded independently from other slices in the same frame. This mode restricts the motion vector search range to the region box of the current slice, e.g. motion vectors outside the slice boundary can't be used.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_CONSTRAINED_INTRAPREDICTION_SUPPORT`

Support for constrained intraprediction, that if activated will force the encoding of each intra-coded block with residual data only from other intra-coded blocks, e.g. not from inter-coded blocks. This refers to constrained_intra_pred_flag in the picture parameter set (PPS).

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_SAO_FILTER_SUPPORT`

Support for sample adaptive offset.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_ASYMETRIC_MOTION_PARTITION_SUPPORT`

Support for asymmetric motion partition.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_ASYMETRIC_MOTION_PARTITION_REQUIRED`

Asymmetric motion partition must be always enabled. If this flag is set, D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_ASYMETRIC_MOTION_PARTITION_SUPPORT must also be set.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_TRANSFORM_SKIP_SUPPORT`

Support for transform skip.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_DISABLING_LOOP_FILTER_ACROSS_SLICES_SUPPORT`

Support for disabling loop filter across slices.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_P_FRAMES_IMPLEMENTED_AS_LOW_DELAY_B_FRAMES`

When this flag is set, indicates that when encoding frames with type [D3D12_VIDEO_ENCODER_FRAME_TYPE_HEVC_P_FRAME](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_type_hevc), they will be written as low delay B-Frames in the compressed bitstream. When this flag is not set, indicates that P frames will be written in the compressed bitstream.

**Note** When operating under this mode, it is the caller's responsibility to code the correct frame type in AUD_NUT and other parts of the HEVC bitstream, taking into account that P frames will be treated as generalized B frames with only references to past frames in POC order.

## Remarks

## See also