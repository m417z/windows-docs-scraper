# ID3D11DeviceContext::RSSetState

## Description

Set the [rasterizer state](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc) for the rasterizer stage of the pipeline.

## Parameters

### `pRasterizerState` [in, optional]

Type: **[ID3D11RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rasterizerstate)***

Pointer to a rasterizer-state interface (see [ID3D11RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rasterizerstate)) to bind to the pipeline.

## Remarks

To create a rasterizer state interface, call [ID3D11Device::CreateRasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createrasterizerstate).

The method will hold a reference to the interfaces passed in.
This differs from the device state behavior in Direct3D 10.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)