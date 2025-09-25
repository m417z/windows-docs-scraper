## Description

Defines constants that specify sampler feedback support.

## Constants

### `D3D12_SAMPLER_FEEDBACK_TIER_NOT_SUPPORTED:0`

Specifies that sampler feedback is not supported. Attempts at calling sampler feedback APIs represent an error.

### `D3D12_SAMPLER_FEEDBACK_TIER_0_9:90`

Specifies that sampler feedback is supported to tier 0.9. This indicates the following:

Sampler feedback is supported for samplers with these texture addressing modes:
* D3D12_TEXTURE_ADDRESS_MODE_WRAP
* D3D12_TEXTURE_ADDRESS_MODE_CLAMP

The Texture2D shader resource view passed in to feedback-writing HLSL methods has these restrictions:
* The MostDetailedMip field must be 0.
* The MipLevels count must span the full mip count of the resource.
* The PlaneSlice field must be 0.
* The ResourceMinLODClamp field must be 0.

The Texture2DArray shader resource view passed in to feedback-writing HLSL methods has these restrictions:
* All the limitations as in Texture2D above, and
* The FirstArraySlice field must be 0.
* The ArraySize field must span the full array element count of the resource.

### `D3D12_SAMPLER_FEEDBACK_TIER_1_0:100`

Specifies sample feedback is supported to tier 1.0. This indicates that sampler feedback is supported for all texture addressing modes, and feedback-writing methods are supported irrespective of the passed-in shader resource view.

### `D3D12_MESH_SHADER_TIER_NOT_SUPPORTED:0`

## Remarks

## See also

* [Sampler feedback spec](https://microsoft.github.io/DirectX-Specs/d3d/SamplerFeedback.html)