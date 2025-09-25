## Description

The **D3D12_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS** enumeration defines the list of distinct interpolation filter types that can be used in the AV1 video encoding process, where each value represents a specific interpolation filter.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_EIGHTTAP:0`

The eight-tap interpolation filter uses eight samples to create a prediction.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_EIGHTTAP_SMOOTH:1`

The eight-tap smooth interpolation filter is a variant of the eight-tap filter that applies a smoothing function to reduce sharpness.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_EIGHTTAP_SHARP:2`

The eight-tap sharp interpolation filter is another variant of the eight-tap filter that emphasizes sharpness.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_BILINEAR:3`

The bilinear interpolation filter uses two samples to create a prediction.

### `D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_SWITCHABLE:4`

The encoder has the capability to dynamically switch between different interpolation filters based on the content of each block. Instead of using a single filter for the entire video frame, the encoder can choose the most appropriate filter for each block to optimize quality and compression efficiency.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_interpolation_filters_0095_flags)