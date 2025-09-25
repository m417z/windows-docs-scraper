# CD3D11_UNORDERED_ACCESS_VIEW_DESC::CD3D11_UNORDERED_ACCESS_VIEW_DESC(D3D11_UAV_DIMENSION,DXGI_FORMAT,UINT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85)) structure that is initialized with [D3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_unordered_access_view_desc) values.

## Parameters

### `viewDimension`

Type: **[D3D11_UAV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_uav_dimension)**

A [D3D11_UAV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_uav_dimension)-typed value that specifies the resource type of the view.

### `format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format.

### `mipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the mipmap level to use mip slice. **FirstElement** for [D3D11_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_uav).

### `firstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first element to use in an array of elements.

**NumElements** for [D3D11_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_uav). **FirstWSlice** for [D3D11_TEX3D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_uav).

### `arraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of elements in the array. **WSize** for [D3D11_TEX3D_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex3d_uav).

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [D3D11_BUFFER_UAV_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_buffer_uav_flag)-typed value that identifies view options for a buffer. For [D3D11_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_uav) only.

## See also

[CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85))