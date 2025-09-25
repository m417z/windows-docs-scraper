## Description

Represents the GOP structure for H.264 video encoding.

## Members

### `GOPLength`

The distance between I-frames in the sequence, or the number of pictures on a GOP. If set to 0, only the first frame will be an I frame (infinite GOP).

### `PPicturePeriod`

The period for P-frames to be inserted within the GOP. Note that if GOPLength is set to 0 for infinite GOP, this value must be greater than zero.

Example usage; Let A=GOPLength; B=PPictureInterval

- A=0; B=1 => IPPPPPPPP...
- A=0; B=2 => IBPBPBPBP...
- A=0; B=3 => IBBPBBPBB...
- A=1; B=0 => IIIIIIIII...
- A=2; B=1 => IPIPIPIPI...
- A=3; B=1 => IPPIPPIPP...
- A=3; B=2 => IBPIBPIBP...
- A=4; B=3 => IBBPIBBPIBBP...

### `pic_order_cnt_type`

Specifies the picture order count type filter mode as defined in the H264 standard under pic_order_cnt_type in the sequence parameter set. The value of pic_order_cnt_type shall be in the range of 0 to 2, inclusive.

### `log2_max_frame_num_minus4`

Specifies the value of the variable MaxFrameNum that is used in frame_num related derivations as follows:
MaxFrameNum = 2^(log2_max_frame_num_minus4 + 4)
The value of log2_max_frame_num_minus4 shall be in the range of 0 to 12, inclusive.

### `log2_max_pic_order_cnt_lsb_minus4`

Specifies the value of the variable MaxPicOrderCntLsb that is used in the decoding process for picture order count as specified in clause 8.2.1 as follows:
MaxPicOrderCntLsb = 2^ (log2_max_pic_order_cnt_lsb_minus4 + 4)
The value of log2_max_pic_order_cnt_lsb_minus4 shall be in the range of 0 to 12, inclusive.

## Remarks

## See also