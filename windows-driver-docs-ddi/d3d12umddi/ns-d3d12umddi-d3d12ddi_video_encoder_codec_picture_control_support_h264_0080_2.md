## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT_H264_0080_2** structure represents picture control support settings for H.264 encoding.

## Members

### `MaxL0ReferencesForP`

The maximum value allowed in the slice headers for ```(num_ref_idx_l0_active_minus1 plus 1)``` when encoding P frames. This is equivalent to the maximum size of an L0 for a P frame supported.

### `MaxL0ReferencesForB`

The maximum value allowed in the slice headers for ```(num_ref_idx_l0_active_minus1 plus 1)``` when encoding B frames. This is equivalent to the maximum size of an L0 for a B frame supported.

### `MaxL1ReferencesForB`

The maximum value allowed in the slice headers for ```(num_ref_idx_l1_active_minus1 plus 1)``` when encoding B frames. This is equivalent to the maximum size of an L1 for a B frame supported.

### `MaxLongTermReferences`

The maximum number of references used in a frame that can be marked as long term reference.

### `MaxDPBCapacity`

The maximum number of unique pictures that can be used from the decoded picture buffer (DPB) that the caller manages (number of unique indices in L0 union L1) for a given [**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command on the hardware.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_picture_control_support_0080_2)