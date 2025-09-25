## Description

The supported sampler feedback tier.

## Constants

### `D3D12DDI_SAMPLER_FEEDBACK_TIER_NOT_SUPPORTED:0`

Sampler feedback is not supported.

### `D3D12DDI_SAMPLER_FEEDBACK_TIER_0_9:90`

Sampler feedback is supported for samplers with texture addressing modes D3D12_TEXTURE_ADDRESS_MODE_WRAP or D3D12_TEXTURE_ADDRESS_MODE_CLAMP.

### `D3D12DDI_SAMPLER_FEEDBACK_TIER_1_0:100`

Sampler feedback is supported for all texture addressing modes, and feedback-writing methods are supported irrespective of the passed-in shader resource view.

## Remarks

See the [D3D Sampler Feedback Specification](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html) for more information.

## See also

[**D3D12DDI_D3D12_OPTIONS_DATA_0089**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0073)