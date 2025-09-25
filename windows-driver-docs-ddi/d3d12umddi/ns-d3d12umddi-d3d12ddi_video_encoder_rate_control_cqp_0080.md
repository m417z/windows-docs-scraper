## Description

The **D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CQP_0080** structure contains the rate control definition for constant quantization parameter (CQP) mode.

## Members

### `ConstantQP_FullIntracodedFrame`

The quantization parameter that should be used for each fully intra-encoded frame.

### `ConstantQP_InterPredictedFrame_PrevRefOnly`

The quantization parameter that should be used for each encoded frame that has inter-picture references to pictures, in display order, before the current one.

### `ConstantQP_InterPredictedFrame_BiDirectionalRef`

The quantization parameter that should be used for each encoded frame that has inter-picture references to pictures, in display order, both from the previous and next frames.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_CONFIGURATION_PARAMS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_configuration_params_0080_2)