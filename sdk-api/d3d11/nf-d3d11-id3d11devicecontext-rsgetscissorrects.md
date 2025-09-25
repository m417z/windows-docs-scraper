# ID3D11DeviceContext::RSGetScissorRects

## Description

Get the array of scissor rectangles bound to the rasterizer stage.

## Parameters

### `pNumRects` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The number of scissor rectangles (ranges between 0 and D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE) bound; set *pRects* to **NULL** to use *pNumRects* to see how many rectangles would be returned.

### `pRects` [out, optional]

Type: **[D3D11_RECT](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-rect)***

An array of scissor rectangles (see [D3D11_RECT](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-rect)). If NumRects is greater than the number of scissor rects currently bound, then unused members of the array will contain 0.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)