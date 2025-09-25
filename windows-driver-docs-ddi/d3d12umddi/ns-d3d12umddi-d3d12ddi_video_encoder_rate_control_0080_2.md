## Description

The **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_0080_2** structure specifies the rate control configuration.

## Members

### `Mode`

A [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_mode_0080) value that specifies the rate control mode.

### `Flags`

A [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080) value that specifies the flags for rate control.

### `ConfigParams`

A [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_configuration_params_0080_2) structure whose members point to specific configuration structures based on **Mode**. For absolute quantization parameter (QP) matrix mode, the configuration arguments are provided on a per [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) basis.

If **Mode** is **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080_ABSOLUTE_QP_MAP**, the QP values in **pRateControlQPMap** are used as absolute QP values.

For the other rate control modes, the QP values in **pRateControlQPMap** are interpreted as a delta QP map to be used for the current [frame encode operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0). The values provided in the map are incremented/decremented on top of the QP values decided by the rate control algorithm or the baseline QP constant set in CQP mode.

### `TargetFrameRate`

A [**DXGI_RATIONAL**](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_rational) structure that indicates the target frame rate for the encoded stream. This value is a hint for the rate control budgeting algorithm.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_control_desc_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)