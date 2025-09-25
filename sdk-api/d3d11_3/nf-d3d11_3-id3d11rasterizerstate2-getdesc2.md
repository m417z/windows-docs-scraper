# ID3D11RasterizerState2::GetDesc2

## Description

Gets the description for rasterizer state that you used to create the rasterizer-state object.

## Parameters

### `pDesc` [out]

A pointer to a [D3D11_RASTERIZER_DESC2](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ns-d3d11_3-cd3d11_rasterizer_desc2) structure that receives a description of the rasterizer state. This rasterizer state can specify forced sample count and conservative rasterization mode.

## Remarks

You use the description for rasterizer state in a call to the [ID3D11Device3::CreateRasterizerState2](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createrasterizerstate2) method to create the rasterizer-state object.

## See also

[ID3D11RasterizerState2](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nn-d3d11_3-id3d11rasterizerstate2)