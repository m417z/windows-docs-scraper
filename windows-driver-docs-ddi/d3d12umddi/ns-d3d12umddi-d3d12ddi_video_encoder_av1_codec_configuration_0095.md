## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_0095** structure describes the AV1 codec configuration.

## Members

### `FeatureFlags`

A [**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags) enumeration that defines the set of enabled features. Flags can be combined based on the reported capabilities/requirements by the driver.

### `OrderHintBitsMinus1`

The number of bits used to represent the order hint value.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_0082_0)