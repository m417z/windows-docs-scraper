## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAGS_0080** enumeration reports the hardware capabilities for H.264 encoding.

## Constants

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_NONE`

Indicates no flags.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_CABAC_ENCODING_SUPPORT`

Indicates whether support is available for context-adaptive binary arithmetic coding (CABAC) Encoding.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT`

Indicates whether support is available for slice constrained encoding, in which every slice in a frame is encoded independently from other slices in the same frame. This mode restricts the motion vector search range to the region box of the current slice; that is, motion vectors cannot be used outside the slice boundary.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_BFRAME_LTR_COMBINED_SUPPORT`

Indicates whether support is available for using B-frames and long-term references at the same time.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_ADAPTIVE_8x8_TRANSFORM_ENCODING_SUPPORT`

Indicates whether support is available for using adaptive 8x8 transforms when encoding.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_DIRECT_SPATIAL_ENCODING_SUPPORT`

Indicates support for spatial direct mode.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_DIRECT_TEMPORAL_ENCODING_SUPPORT`

Indicates support for temporal direct mode.

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0080_CONSTRAINED_INTRAPREDICTION_SUPPORT`

Indicates whether support is available for constrained intra-prediction. When constrained intra-prediction is activated, it forces the encoding of each intra-coded block with residual data only from other intra-coded blocks (and not from inter-coded blocks). This flag refers to *constrained_intra_pred_flag* in the picture parameter set (PPS).

### `D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_0099_0_NUM_REF_IDX_ACTIVE_OVERRIDE_FLAG_SLICE_SUPPORT`

Indicates that the encoder supports overriding the number of active reference indices at the slice level. This allows for more fine-grained control of reference frames used for prediction on a per-slice basis. Added in Windows 11, version 24H2 (WDDM 3.2).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0)