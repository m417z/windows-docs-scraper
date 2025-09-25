## Description

The **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_ABSOLUTE_QP_MAP_0096** structure specifies the rate control parameters when an absolute QP map is used.

## Members

### `QualityVsSpeed`

The quality versus speed trade-off. This value must be in the range [0, D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT1.MaxQualityVsSpeed]. The lower the value, the faster the encode operation.

The settings associated to each of the levels exposed by **QualityVsSpeed** must only refer to hardware/driver implementation optimizations and heuristics that aren't related to specific codec configurations or encoding tools selection, which are already independently exposed in the D3D12 API to the user individually. Please note that other codec configurations and codec encoding tools exposed through this API may also affect quality and speed.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_configuration_params_0080_2)

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_flags_0080)