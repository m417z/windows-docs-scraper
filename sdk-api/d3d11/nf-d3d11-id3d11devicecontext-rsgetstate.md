# ID3D11DeviceContext::RSGetState

## Description

Get the [rasterizer state](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc) from the rasterizer stage of the pipeline.

## Parameters

### `ppRasterizerState` [out]

Type: **[ID3D11RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rasterizerstate)****

Address of a pointer to a rasterizer-state interface (see [ID3D11RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11rasterizerstate)) to fill with information from the device.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call IUnknown::Release on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)