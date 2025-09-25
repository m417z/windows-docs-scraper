# ID3D11BlendState1::GetDesc1

## Description

Gets the description for blending state that you used to create the blend-state object.

## Parameters

### `pDesc` [out]

A pointer to a [D3D11_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-cd3d11_blend_desc1) structure that receives a description of the blend state. This blend state can specify logical operations as well as blending operations.

## Remarks

You use the description for blending state in a call to the [ID3D11Device1::CreateBlendState1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-createblendstate1) method to create the blend-state object.

## See also

[ID3D11BlendState1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11blendstate1)