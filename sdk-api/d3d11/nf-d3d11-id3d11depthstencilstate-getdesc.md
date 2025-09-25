# ID3D11DepthStencilState::GetDesc

## Description

Gets the description for depth-stencil state that you used to create the depth-stencil-state object.

## Parameters

### `pDesc` [out]

Type: **[D3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_desc)***

A pointer to a [D3D11_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_desc) structure that receives a description of the depth-stencil state.

## Remarks

You use the description for depth-stencil state in a call to the [ID3D11Device::CreateDepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createdepthstencilstate) method to create the depth-stencil-state object.

## See also

[ID3D11DepthStencilState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11depthstencilstate)