## Description

The **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_QVBR_0080_2** structure contains the rate control definition for constant quality target with constrained bitrate.

## Members

### `InitialQP`

When the [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAG_0080_ENABLE_INITIAL_QP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080) flag is set, **InitialQP** can be used by the rate control algorithm.

### `MinQP`

When the [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAG_0080_ENABLE_QP_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080) flag is set, **MinQP** limits the quantization parameter (QP) range of the rate control algorithm.

### `MaxQP`

When the [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAG_0080_ENABLE_QP_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080) flag is set, **MaxQP** limits the QP range of the rate control algorithm.

### `MaxFrameBitSize`

Maximum size for each frame to be encoded, in bits. When [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAG_0080_ENABLE_MAX_FRAME_SIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080) is set, **MaxFrameBitSize** limits each frame's maximum size in the rate control algorithm.

### `TargetAvgBitRate`

Average bitrate to be used, in bits per second.

### `PeakBitRate`

Maximum bitrate that can be reached, in bits per second.

### `ConstantQualityTarget`

Indicates the quality level. Values are codec-specific as each standard defines the range for this argument (for example, H.264 / HEVC 0-51, et cetera).

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_configuration_params_0080_2)

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080)