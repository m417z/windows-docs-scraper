# ID3D10Device::RSSetViewports

## Description

Bind an array of [viewports](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-getting-started) to the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage) of the pipeline.

## Parameters

### `NumViewports` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of viewports to bind.

### `pViewports` [in]

Type: **const [D3D10_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_viewport)***

An array of viewports (see [D3D10_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_viewport)) to bind to the device. Each viewport must have its extents within the allowed ranges: D3D10_VIEWPORT_BOUNDS_MIN, D3D10_VIEWPORT_BOUNDS_MAX, D3D10_MIN_DEPTH, and D3D10_MAX_DEPTH.

## Remarks

All viewports must be set atomically as one operation. Any viewports not defined by the call are disabled.

Which viewport to use is determined by the SV_ViewportArrayIndex semantic output by a geometry shader (see [shader semantic syntax](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics)). If a geometry shader does not make use of the SV_ViewportArrayIndex semantic then Direct3D will use the first viewport in the array.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)