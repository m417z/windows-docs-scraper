# ID3D10Device::RSGetState

## Description

Get the [rasterizer state](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_rasterizer_desc) from the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage) of the pipeline.

## Parameters

### `ppRasterizerState` [out]

Type: **[ID3D10RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)****

Address of a pointer to a rasterizer-state interface (see [ID3D10RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)) to fill with information from the device.

## Remarks

Any returned interfaces will have their reference count incremented by one. Applications should call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the returned interfaces when they are no longer needed to avoid memory leaks.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)