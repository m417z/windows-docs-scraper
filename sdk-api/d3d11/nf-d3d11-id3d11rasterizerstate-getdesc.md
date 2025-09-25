# ID3D11RasterizerState::GetDesc

## Description

Gets the description for rasterizer state that you used to create the rasterizer-state object.

## Parameters

### `pDesc` [out]

Type: **[D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc)***

A pointer to a [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc) structure that receives a description of the rasterizer state.

## Remarks

You use the description for rasterizer state in a call to the [ID3D11Device::CreateRasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createrasterizerstate) method to create the rasterizer-state object.

## See also

[ID3D11RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rasterizerstate)