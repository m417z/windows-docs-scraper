## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS_0082_0** enumeration specifies configuration support flags for HEVC encoding. Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_flags_0083_0) for full video encoding feature support for Windows 11 (WDDM 3.0).

## Constants

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_NONE`

No flags.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_BFRAME_LTR_COMBINED_SUPPORT`

Indicates support for use of B frames and long term references frames simultaneously.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT`

Indicates support for slice-constrained encoding, in which every slice in a frame is encoded independently from other slices in the same frame. This mode restricts the motion vector search range to the region box of the current slice; that is, motion vectors outside the slice boundary cannot be used.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_CONSTRAINED_INTRAPREDICTION_SUPPORT`

Indicates support for constrained intra-prediction that, if activated, will force the encoding of each intra-coded block with residual data only from other intra-coded blocks (and not from inter-coded blocks). This flag refers to *constrained_intra_pred_flag* in the picture parameter set (PPS).

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_SAO_FILTER_SUPPORT`

Indicates support for sample adaptive offset.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_ASYMETRIC_MOTION_PARTITION_SUPPORT`

Indicates support for asymmetric motion partition.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_ASYMETRIC_MOTION_PARTITION_REQUIRED`

Indicates that asymmetric motion partition must always be enabled. If this flag is set, D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_ASYMETRIC_MOTION_PARTITION_SUPPORT must also be set.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_TRANSFORM_SKIP_SUPPORT`

Indicates support for transform skip.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0082_0_DISABLING_LOOP_FILTER_ACROSS_SLICES_SUPPORT`

Indicates support for disabling loop filter across slices.

## Remarks

Use [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_flags_0083_0) for full video encoding feature support for Windows 11 (WDDM 3.0).