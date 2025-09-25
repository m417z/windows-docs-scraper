## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAGS** enumeration specifies flags for the interpolation filters that can be used in the AV1 video encoding process.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAG_NONE`

Indicates that no interpolation filters are selected or supported.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAG_EIGHTTAP`

Indicates support for the eight-tap interpolation filter.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAG_EIGHTTAP_SMOOTH`

Indicates support for the eight-tap smooth interpolation filter.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAG_EIGHTTAP_SHARP`

 Indicates support for the eight-tap sharp interpolation filter.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAG_BILINEAR`

Indicates support for the bilinear interpolation filter.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAG_SWITCHABLE`

Indicates support for switchable interpolation filters, where the encoder can choose the best filter on a per-block basis depending on the content.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_interpolation_filters_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_support_0095)