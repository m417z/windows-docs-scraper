# ID3D11SamplerState::GetDesc

## Description

Gets the description for sampler state that you used to create the sampler-state object.

## Parameters

### `pDesc` [out]

Type: **[D3D11_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_sampler_desc)***

A pointer to a [D3D11_SAMPLER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_sampler_desc) structure that receives a description of the sampler state.

## Remarks

You use the description for sampler state in a call to the [ID3D11Device::CreateSamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createsamplerstate) method to create the sampler-state object.

## See also

[ID3D11SamplerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11samplerstate)