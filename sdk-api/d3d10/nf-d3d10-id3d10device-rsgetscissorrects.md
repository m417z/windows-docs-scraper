# ID3D10Device::RSGetScissorRects

## Description

Get the array of [scissor rectangles](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-getting-started) bound to the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage).

## Parameters

### `NumRects` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Number of scissor rectangles to get. If pRects is **NULL**, this will be filled with the number of scissor rectangles currently bound.

### `pRects` [out]

Type: **[D3D10_RECT](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-rect)***

An array of scissor rectangles (see [D3D10_RECT](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-rect)). If NumRects is greater than the number of scissor rects currently bound, then unused members of the array will contain 0.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)