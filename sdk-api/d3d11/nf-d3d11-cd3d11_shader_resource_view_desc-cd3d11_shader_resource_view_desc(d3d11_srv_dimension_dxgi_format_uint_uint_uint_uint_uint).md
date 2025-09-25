# CD3D11_SHADER_RESOURCE_VIEW_DESC::CD3D11_SHADER_RESOURCE_VIEW_DESC(D3D11_SRV_DIMENSION,DXGI_FORMAT,UINT,UINT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85)) structure that is initialized with [D3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_shader_resource_view_desc) values.

## Parameters

### `viewDimension`

Type: **[D3D11_SRV_DIMENSION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff476217(v=vs.85))**

A [D3D11_SRV_DIMENSION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff476217(v=vs.85))-typed value that specifies the resource type of the view.

### `format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format.

### `mostDetailedMip`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the most detailed mipmap level to use; this number is from 0 to *mipLevels* -1. For a buffer, this is the number of bytes between the beginning of the buffer and the first element to access.

**FirstElement** of [D3D11_BUFFER_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_srv).

### `mipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels for the view. For a buffer, this is the total number of elements in the view. **NumElements** of [D3D11_BUFFER_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_buffer_srv).

### `firstArraySlice`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the first element to use in an array of elements.

**First2DArrayFace** of [D3D11_TEXCUBE_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texcube_array_srv).

### `arraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of elements in the array. **NumCubes** of [D3D11_TEXCUBE_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texcube_array_srv).

### `flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [D3D11_BUFFEREX_SRV_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bufferex_srv_flag)-typed value that identifies view options for a buffer. For [D3D11_BUFFEREX_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_bufferex_srv) only.

## See also

[CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85))