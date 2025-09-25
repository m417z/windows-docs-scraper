# D3D12DDI_VIDEO_SCALE_SUPPORT_0032 structure

## Description

The **D3D12DDI_VIDEO_SCALE_SUPPORT_0032** structure describes a supported range of output sizes for a scaler.

## Members

### `OutputSizeRange`

A [**D3D12DDI_VIDEO_SIZE_RANGE_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_size_range_0032) structure that specifies the supported range of output sizes for a scaler.

### `Flags`

A [**D3D12DDI_VIDEO_SCALE_SUPPORT_FLAGS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_scale_support_flags_0022) value that indicated level of scale support.

## Remarks

By default, the supported range indicates all possible output size combinations that exist between the Max size and Min size for the extent, ScaleSupportFlags may add additional caveats.

When scaling is not supported, the Min and Max sizes should both be set to the input size and no flags specified.

## See also

[**D3D12DDI_VIDEO_DECODE_CONVERSION_SUPPORT_DATA_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_support_data_0032)

[**D3D12DDI_VIDEO_PROCESS_SUPPORT_DATA_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_process_support_data_0032)

[**D3D12DDI_VIDEO_SCALE_SUPPORT_FLAGS_0022**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_scale_support_flags_0022)

[**D3D12DDI_VIDEO_SIZE_RANGE_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_size_range_0032)