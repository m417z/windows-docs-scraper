# ID3D10Device::RSSetState

## Description

Set the [rasterizer state](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_rasterizer_desc) for the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage) of the pipeline.

## Parameters

### `pRasterizerState` [in]

Type: **[ID3D10RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)***

Pointer to a rasterizer-state interface (see [ID3D10RasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10rasterizerstate)) to bind to the pipeline.

## Remarks

To create a rasterizer state interface, call [ID3D10Device::CreateRasterizerState](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createrasterizerstate). For more details on setting up the rasterizer state, see [Set Rasterizer State](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-getting-started).

The method will not hold a reference to the interfaces passed in. For that reason, applications should be careful not to release an interface currently in use by the device.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)