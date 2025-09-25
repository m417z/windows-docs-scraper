## Description

The **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080** enumeration lists the possible rate control modes.

## Constants

### `D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080_ABSOLUTE_QP_MAP`

Indicates no rate control budgeting. Each [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) call will interpret the quantization parameter (QP) values in **pRateControlQPMap** as a map of absolute values.

### `D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080_CQP`

Indicates constant quantization parameter (CQP) rate control mode.

### `D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080_CBR`

Indicates constant bit rate (CBR) rate control mode.

### `D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080_VBR`

Indicates variable bit rate (VBR) rate control mode.

### `D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080_QVBR`

Indicates constant quality target rate variable bit rate (QVBR) rate control mode.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_0080_2)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)