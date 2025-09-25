## Description

Specifies configuration support flags for H.264 video encoding.

## Constants

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_NONE`

None.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_CABAC_ENCODING_SUPPORT`

Support for context-adaptive binary arithmetic coding (CABAC) encoding.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_INTRA_SLICE_CONSTRAINED_ENCODING_SUPPORT`

Support for slice constrained encoding in which every slice in a frame is encoded independently from other slices in the same frame. This mode restricts the motion vector search range to the region box of the current slice, e.g. motion vectors outside the slice boundary can't be used.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_BFRAME_LTR_COMBINED_SUPPORT`

Support for using B-frames and long term references at the same time.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_ADAPTIVE_8x8_TRANSFORM_ENCODING_SUPPORT`

Support for using adaptive 8x8 transforms when encoding.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_DIRECT_SPATIAL_ENCODING_SUPPORT`

Support for spatial direct mode.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_DIRECT_TEMPORAL_ENCODING_SUPPORT`

Support for temporal direct mode.

### `D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_FLAG_CONSTRAINED_INTRAPREDICTION_SUPPORT`

Support for constrained intraprediction, that if activated will force the encoding of each intra-coded block with residual data only from other intra-coded blocks, e.g. not from inter-coded blocks. This refers to constrained_intra_pred_flag in the picture parameter set (PPS).

## Remarks

## See also