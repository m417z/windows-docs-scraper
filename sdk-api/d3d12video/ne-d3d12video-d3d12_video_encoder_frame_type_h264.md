## Description

Specifies the type of an H.264 video frame.

## Constants

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_H264_I_FRAME`

I-Frame. Completely intra-coded frame.

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_H264_P_FRAME`

P-Frame. Allows references to past frames.

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_H264_B_FRAME`

B-Frame. Allows references to both past and future (in display order) frames.

### `D3D12_VIDEO_ENCODER_FRAME_TYPE_H264_IDR_FRAME`

Instantaneous decode refresh frame. Special type of I-frame where no frame after it can reference any frame before it.

## Remarks

## See also