## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAGS_0083_0** enumeration specifies configuration support flags for HEVC encoding.

## Constants

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_NONE`

No flags.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_BFRAME_LTR_COMBINED_SUPPORT`

Indicates support for use of B frames and long term references frames simultaneously.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT`

Indicates support for slice-constrained encoding, in which every slice in a frame is encoded independently from other slices in the same frame. This mode restricts the motion vector search range to the region box of the current slice; that is, motion vectors outside the slice boundary cannot be used.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_CONSTRAINED_INTRAPREDICTION_SUPPORT`

Indicates support for constrained intra-prediction that, if activated, will force the encoding of each intra-coded block with residual data only from other intra-coded blocks (and not from inter-coded blocks). This flag refers to *constrained_intra_pred_flag* in the picture parameter set (PPS).

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_SAO_FILTER_SUPPORT`

Indicates support for sample adaptive offset.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_ASYMETRIC_MOTION_PARTITION_SUPPORT`

Indicates support for asymmetric motion partition.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_ASYMETRIC_MOTION_PARTITION_REQUIRED`

Indicates that asymmetric motion partition must always be enabled. If this flag is set, D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_ASYMETRIC_MOTION_PARTITION_SUPPORT must also be set.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_TRANSFORM_SKIP_SUPPORT`

Indicates support for transform skip.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_DISABLING_LOOP_FILTER_ACROSS_SLICES_SUPPORT`

Indicates support for disabling loop filter across slices.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0083_0_P_FRAMES_IMPLEMENTED_AS_LOW_DELAY_B_FRAMES`

Indicates that frames being encoded with type [**D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_HEVC_0080_P_FRAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_type_hevc_0080) will be written as low delay B-frames in the compressed bit stream. If this flag is not set, P frames will be written in the compressed bit stream.

> [!NOTE]
>
> When operating in this mode, it is the caller's responsibility to code the correct frame type in _AUD_NUT_ and other parts of the HEVC bit stream, taking into account that P frames will be treated as generalized B frames with only references to past frames in picture order count (POC) order.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_FLAG_0099_0_NUM_REF_IDX_ACTIVE_OVERRIDE_FLAG_SLICE_SUPPORT`

Indicates that the encoder supports overriding the number of active reference indices at the slice level. This allows for more fine-grained control of reference frames used for prediction on a per-slice basis. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0)