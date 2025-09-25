# ID3D10Device::RSSetScissorRects

## Description

Bind an array of [scissor rectangles](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-getting-started) to the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage).

## Parameters

### `NumRects` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of scissor rectangles to bind.

### `pRects` [in]

Type: **const [D3D10_RECT](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-rect)***

An array of scissor rectangles (see [D3D10_RECT](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-rect)).

## Remarks

The scissor rectangles will only be used if ScissorEnable is set to true in the rasterizer state (see [D3D10_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_rasterizer_desc)).

Which scissor rectangle to use is determined by the SV_ViewportArrayIndex semantic output by a geometry shader (see [shader semantic syntax](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics)). If a geometry shader does not make use of the SV_ViewportArrayIndex semantic then Direct3D will use the first scissor rectangle in the array.

Each scissor rectangle in the array corresponds to a viewport in an array of viewports (see [ID3D10Device::RSSetViewports](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-rssetviewports)).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)