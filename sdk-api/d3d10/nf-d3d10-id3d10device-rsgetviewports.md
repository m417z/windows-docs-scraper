# ID3D10Device::RSGetViewports

## Description

Get the array of [viewports](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage-getting-started) bound
to the [rasterizer stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-rasterizer-stage)

## Parameters

### `NumViewports` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Number of viewports in *pViewports*.
If *pViewports* is **NULL**, this will be filled with the number of viewports currently bound.

### `pViewports` [out]

Type: **[D3D10_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_viewport)***

An array of viewports (see [D3D10_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_viewport)) to be filled with information from the device. If NumViewports is greater than
the actual number of viewports currently bound, then unused members of the array will contain 0.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)