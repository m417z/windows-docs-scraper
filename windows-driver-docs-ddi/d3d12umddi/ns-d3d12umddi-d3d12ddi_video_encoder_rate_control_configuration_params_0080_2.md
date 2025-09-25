## Description

The **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS_0080_2** structure contains rate control configuration mode-specific parameters.

## Members

### `DataSize`

Size of the referenced data, in bytes.

### `pConfiguration_CQP`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CQP_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_cqp_0080) structure that contains the rate control structure definition for constant quantization parameter (CQP) mode.

### `pConfiguration_CBR`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CBR_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_cbr_0080) structure that contains the rate control structure definition for constant bitrate (CBR) mode.

### `pConfiguration_VBR`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_VBR_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_vbr_0080) structure that contains the rate control structure definition for variable bitrate (VBR) mode.

### `pConfiguration_QVBR`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_QVBR_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_qvbr_0080_2) structure that contains the rate control structure definition for constant quality target with constrained (variable) bitrate (QVBR) mode.

### `pConfiguration_CQP1`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CQP1_0096**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_cqp1_0096) structure that contains the extended rate control structure definition for constant quantization parameter (CQP) mode. Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `pConfiguration_CBR1`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CBR1_0096**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_cbr1_0096) structure that contains the extended rate control structure definition for constant bitrate (CBR) mode. Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `pConfiguration_VBR1`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_VBR1_0096**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_vbr1_0096) structure that contains the extended rate control structure definition for variable bitrate (VBR) mode. Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `pConfiguration_QVBR1`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_QVBR1_0096**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_qvbr1_0096) structure that contains the extended rate control structure definition for constant quality target with variable bitrate (QVBR) mode. Available starting with Windows 11, version 24H2 (WDDM 3.2).

### `pConfiguration_AbsoluteQPMap`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_ABSOLUTE_QP_MAP_0096**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_absolute_qp_map_0096) structure that contains the rate control structure definition for absolute QP map mode. Available starting with Windows 11, version 24H2 (WDDM 3.2).

## Remarks

The configuration mode-specific structure to use is based on the value of **[D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_0080_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_0080_2).Mode**.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_0080_2)