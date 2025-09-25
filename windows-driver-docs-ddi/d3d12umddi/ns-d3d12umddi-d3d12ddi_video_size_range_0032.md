# D3D12DDI_VIDEO_SIZE_RANGE_0032 structure

## Description

The **D3D12DDI_VIDEO_SIZE_RANGE_0032** structure describes a supported range of output sizes for a scaler.

## Members

### `MaxWidth`

The largest output Width that can be scaled to. The largest value allowed is D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION (16384).

### `MaxHeight`

The largest output Height that can be scaled to. The largest value allowed is D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION (16384).

### `MinWidth`

The smallest output Width that can be scaled to. The smallest allowed value is 1.

### `MinHeight`

The smallest output Height that can be scaled to. The smallest allowed value is 1.

## Remarks

By default, the supported range indicates all possible output size combinations that exist between the Max size and Min size for the extent, ScaleSupportFlags may add additional caveats.

When scaling is not supported, the Min and Max sizes should both be set to the input size and no flags specified.

## See also

[**D3D12DDI_VIDEO_SCALE_SUPPORT_0032**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_scale_support_0032)