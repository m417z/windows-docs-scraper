# ID3D11RasterizerState1::GetDesc1

## Description

Gets the description for rasterizer state that you used to create the rasterizer-state object.

## Parameters

### `pDesc` [out]

A pointer to a [D3D11_RASTERIZER_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-cd3d11_rasterizer_desc1) structure that receives a description of the rasterizer state. This rasterizer state can specify forced sample count.

## Remarks

You use the description for rasterizer state in a call to the [ID3D11Device1::CreateRasterizerState1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3d11device1-createrasterizerstate1) method to create the rasterizer-state object.

## See also

[ID3D11RasterizerState1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11rasterizerstate1)