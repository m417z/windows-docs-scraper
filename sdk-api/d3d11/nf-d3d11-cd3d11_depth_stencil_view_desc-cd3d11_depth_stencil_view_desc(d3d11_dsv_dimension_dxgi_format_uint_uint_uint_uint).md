# CD3D11_DEPTH_STENCIL_VIEW_DESC::CD3D11_DEPTH_STENCIL_VIEW_DESC(D3D11_DSV_DIMENSION,DXGI_FORMAT,UINT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151639(v=vs.85)) structure that is initialized with [D3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_depth_stencil_view_desc) values.

## Parameters

### `viewDimension`

Type: **[D3D11_DSV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_dsv_dimension)**

A [D3D11_DSV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_dsv_dimension)-typed value that specifies the depth-stencil type of the view.

### `format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format.

### `mipSlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the mipmap level to use mip slice.

### `firstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first element to use in an array of elements.

### `arraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of elements in the array.

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value that describes whether the texture is read only. Pass 0 to specify that it is not read only; otherwise, pass one of the members of
the [D3D11_DSV_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_dsv_flag) enumerated type.

## See also

[CD3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151639(v=vs.85))