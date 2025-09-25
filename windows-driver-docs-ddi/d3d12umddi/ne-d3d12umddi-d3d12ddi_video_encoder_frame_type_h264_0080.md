## Description

The **D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_H264_0080** enumeration lists possible H.264 encoder frame types.

## Constants

### `D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_H264_0080_I_FRAME`

An I-frame: completely intra-coded frame.

### `D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_H264_0080_P_FRAME`

A P-frame (predicted frame): allows references to past frames.

### `D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_H264_0080_B_FRAME`

A B-frame (bi-directional frame): allows references to both past and future frames, in display order.

### `D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_H264_0080_IDR_FRAME`

An IDR frame (instantaneous decoder refresh frame): A special type of I-frame where no frame after it can reference any frame before it.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0)

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_0082_0)