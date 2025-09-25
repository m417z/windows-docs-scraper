# ID3D11DeviceContext::RSSetScissorRects

## Description

Bind an array of scissor rectangles to the rasterizer stage.

## Parameters

### `NumRects` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of scissor rectangles to bind.

### `pRects` [in, optional]

Type: **const [D3D11_RECT](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-rect)***

An array of scissor rectangles (see [D3D11_RECT](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-rect)).

## Remarks

All scissor rects must be set atomically as one operation. Any scissor rects not defined by the call are disabled.

The scissor rectangles will only be used if ScissorEnable is set to true in the rasterizer state (see [D3D11_RASTERIZER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_rasterizer_desc)).

Which scissor rectangle to use is determined by the SV_ViewportArrayIndex semantic output by a geometry shader (see shader semantic syntax). If a geometry shader does not make use of the SV_ViewportArrayIndex semantic then Direct3D will use the first scissor rectangle in the array.

Each scissor rectangle in the array corresponds to a viewport in an array of viewports (see [ID3D11DeviceContext::RSSetViewports](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-rssetviewports)).

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)