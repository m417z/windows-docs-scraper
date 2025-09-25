## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAGS_0082_0** enumeration lists the possible set of enabled features for an HEVC (H.265) codec.

## Constants

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_NONE:0x0`

No flags are specified.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_DISABLE_LOOP_FILTER_ACROSS_SLICES:0x1`

If set, disable the loop filtering across slices.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_ALLOW_REQUEST_INTRA_CONSTRAINED_SLICES:0x2`

If set, allows the use of the intra constrained slices flag in picture control. This mode restricts the motion vector search range to the region box of the current slice (that is, motion vectors outside the slice boundary cannot be used).

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_ENABLE_SAO_FILTER:0x4`

If set, enables the sample adaptive offset filter.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_ENABLE_LONG_TERM_REFERENCES:0x8`

If set, enables the use of long-term references in the picture reference management structures for HEVC.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_USE_ASYMETRIC_MOTION_PARTITION:0x10`

If set, enables asymmetric motion partitioning. If [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_ASYMETRIC_MOTION_PARTITION_REQUIRED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_flags_0083_0) was reported, this flag must always be enabled.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_ENABLE_TRANSFORM_SKIPPING:0x20`

If set, enables transform skipping.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_FLAG_0082_0_USE_CONSTRAINED_INTRAPREDICTION:0x40`

If set, enables constrained intra prediction. This value refers to *constrained_intra_pred_flag* in the Picture Parameter Set (PPS).

## Remarks

The host (D3D12 lower-level encoding API) sets these configuration flags based on the limits queried at the API level.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_hevc_0082_0)

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_flags_0083_0)