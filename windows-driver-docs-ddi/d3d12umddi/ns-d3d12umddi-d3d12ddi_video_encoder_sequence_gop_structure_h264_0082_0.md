## Description

The **D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_H264_0082_0** structure represents the group of pictures (GOP) structure for H.264 video encoding.

## Members

### `GOPLength`

The distance between I-frames in the sequence, or the number of pictures in a GOP. If set to 0, only the first frame will be an I frame (infinite GOP).

### `PPicturePeriod`

The period for P-frames to be inserted within the GOP. If **GOPLength** is set to 0 for infinite GOP, **PPicturePeriod** must be greater than zero. An example usage follows:

Let *A* = **GOPLength** and *B* = **PPictureInterval**:

A=0; B=1 => IPPPPPPPP...
A=0; B=2 => IBPBPBPBP...
A=0; B=3 => IBBPBBPBB...
A=1; B=0 => IIIIIIIII...
A=2; B=1 => IPIPIPIPI...
A=3; B=1 => IPPIPPIPP...
A=3; B=2 => IBPIBPIBP...
A=4; B=3 => IBBPIBBPIBBP...

### `pic_order_cnt_type`

The picture order count type filter mode as defined in the H.264 standard under *pic_order_cnt_type* in the sequence parameter set (SPS). The value of **pic_order_cnt_type** must be in the range of 0 to 2, inclusive.

### `log2_max_frame_num_minus4`

Specifies the value of a variable *MaxFrameNum* that is used in *frame_num*-related derivations as follows: `MaxFrameNum = 2^(log2_max_frame_num_minus4 + 4)`. The value of **log2_max_frame_num_minus4** must be in the range of 0 to 12, inclusive.

### `log2_max_pic_order_cnt_lsb_minus4`

Specifies the value of a variable *MaxPicOrderCntLsb* that is used in the decoding process for picture order count as specified in clause 8.2.1 of the specification as follows: `MaxPicOrderCntLsb = 2^ (log2_max_pic_order_cnt_lsb_minus4 + 4)`. The value of **log2_max_pic_order_cnt_lsb_minus4** must be in the range of 0 to 12, inclusive.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_gop_structure_0082_0)