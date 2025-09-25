## Description

Specifies configuration flags for HEVC video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_DISABLE_LOOP_FILTER_ACROSS_SLICES`

Disables loop filtering across slices.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_ALLOW_REQUEST_INTRA_CONSTRAINED_SLICES`

Allows the usage of the intra constrained slices flag in picture control. This mode restricts the motion vector search range to the region box of the current slice, i.e. motion vectors outside the slice boundary can't be used.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_ENABLE_SAO_FILTER`

Enables the sample adaptive offset filter.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_ENABLE_LONG_TERM_REFERENCES`

Enables the usage of long term references in the picture reference management structures for HEVC.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_USE_ASYMETRIC_MOTION_PARTITION`

Enables asymetric motion partitioning.

**Note** If [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_ASYMETRIC_MOTION_PARTITION_REQUIRED](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec_configuration_support_hevc_flags) was reported, this flag must be enabled.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_ENABLE_TRANSFORM_SKIPPING`

Enables transform skipping.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_USE_CONSTRAINED_INTRAPREDICTION`

Enables constrained intra prediction. This refers to constrained_intra_pred_flag in the PPS.

## Remarks

## See also