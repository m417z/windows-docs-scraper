# ID3D11BlendState::GetDesc

## Description

Gets the description for blending state that you used to create the blend-state object.

## Parameters

### `pDesc` [out]

Type: **[D3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_blend_desc)***

A pointer to a [D3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_blend_desc) structure that receives a description of the blend state.

## Remarks

You use the description for blending state in a call to the [ID3D11Device::CreateBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createblendstate) method to create the blend-state object.

## See also

[ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)