## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_0080_2** structure contains configuration information for an H.264 codec.

## Members

### `ConfigurationFlags`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_flags_0080) value that defines the set of enabled features for an H.264 codec. Flags can be combined.

### `DirectModeConfig`

A [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_DIRECT_MODES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_h264_direct_modes_0080) value that specifies configuration information related to DIRECT modes.

### `pic_order_cnt_type`

The picture order count type filter mode as defined in the H.264 standard under *pic_order_cnt_type* in the sequence parameter set. The value of **pic_order_cnt_type** is in the range of 0 to 2, inclusive.

### `log2_max_frame_num_minus4`

The value of the variable *MaxFrameNum* that is used in *frame_num* related derivations as follows: ``` MaxFrameNum = 2^(log2_max_frame_num_minus4 + 4) ```.

The value of **log2_max_frame_num_minus4** is in the range of 0 to 12, inclusive.

### `log2_max_pic_order_cnt_lsb_minus4`

The value of the variable *MaxPicOrderCntLsb* that is used in the decoding process for picture order count as specified in the H.264 specification as follows: ```MaxPicOrderCntLsb = 2^ (log2_max_pic_order_cnt_lsb_minus4 + 4)```.

The value of **log2_max_pic_order_cnt_lsb_minus4** is in the range of 0 to 12, inclusive.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0080_2)