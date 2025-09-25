# CD3D11_RENDER_TARGET_VIEW_DESC::CD3D11_RENDER_TARGET_VIEW_DESC(ID3D11Buffer,DXGI_FORMAT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151668(v=vs.85)) structure that is initialized with [D3D11_RTV_DIMENSION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_rtv_dimension) values.

## Parameters

### `unnamedParam1`

A pointer to a **ID3D11Buffer** interface for a buffer.

### `format`

A **DXGI_FORMAT**-typed value that specifies the viewing format.

### `firstElement`

Number of bytes between the beginning of the buffer and the first element to access.

### `numElements`

Total number of elements in the view.

## See also

[CD3D11_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151668(v=vs.85))