## Description

The **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_VBR_0080** structure contains the extended rate control definition for variable bitrate (VBR) mode.

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

### `VBVCapacity`

When [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAG_0080_1_ENABLE_VBV_SIZES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080) is set, **VBVCapacity** specifies the capacity, in bits, of the Video Buffer Verifier (VBV) to be used in the rate control algorithm.

### `InitialVBVFullness`

When [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAG_0080_1_ENABLE_VBV_SIZES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080) is set, **InitialVBVFullness** specifies the initial fullness, in bits, of the VBV to be used in the rate control algorithm.

### `QualityVsSpeed`

The quality versus speed trade-off. This value must be in the range [0, D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT1.MaxQualityVsSpeed]. The lower the value, the faster the encode operation.

The settings associated to each of the levels exposed by **QualityVsSpeed** must only refer to hardware/driver implementation optimizations and heuristics that aren't related to specific codec configurations or encoding tools selection, which are already independently exposed in the D3D12 API to the user individually. Please note that other codec configurations and codec encoding tools exposed through this API may also affect quality and speed.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_configuration_params_0080_2)

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080)