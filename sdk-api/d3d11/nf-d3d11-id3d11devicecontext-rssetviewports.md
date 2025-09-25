# ID3D11DeviceContext::RSSetViewports

## Description

Bind an array of viewports to the rasterizer stage of the pipeline.

## Parameters

### `NumViewports` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of viewports to bind.

### `pViewports` [in, optional]

Type: **const [D3D11_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_viewport)***

An array of [D3D11_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_viewport) structures to bind to the device. See the structure page for details about how the viewport size is dependent on the device feature level which has changed between Direct3D 11 and Direct3D 10.

## Remarks

All viewports must be set atomically as one operation. Any viewports not defined by the call are disabled.

Which viewport to use is determined by the [SV_ViewportArrayIndex](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) semantic output by a geometry shader; if a geometry shader does not specify the semantic, Direct3D will use the first viewport in the array.

**Note** Even though you specify float values to the members of the [D3D11_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_viewport) structure for the *pViewports* array in a call to **ID3D11DeviceContext::RSSetViewports** for [feature levels](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9_x, **RSSetViewports** uses DWORDs internally. Because of this behavior, when you use a negative top left corner for the viewport, the call to **RSSetViewports** for feature levels 9_x fails. This failure occurs because **RSSetViewports** for 9_x casts the floating point values into unsigned integers without validation, which results in integer overflow.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)