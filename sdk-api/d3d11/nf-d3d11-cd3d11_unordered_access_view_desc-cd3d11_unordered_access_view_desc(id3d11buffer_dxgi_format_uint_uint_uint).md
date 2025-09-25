# CD3D11_UNORDERED_ACCESS_VIEW_DESC::CD3D11_UNORDERED_ACCESS_VIEW_DESC(ID3D11Buffer,DXGI_FORMAT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85)) structure that is initialized with **D3D11_BUFFER_UAV** values.

## Parameters

### `unnamedParam1`

A pointer to a **ID3D11Buffer** interface for a buffer.

### `format`

A **DXGI_FORMAT**-typed value that specifies the viewing format.

### `firstElement`

Number of bytes between the beginning of the buffer and the first element to access.

### `numElements`

Total number of elements in the view.

### `flags`

A **D3D11_BUFFER_UAV_FLAG**-typed value that identifies view options for a buffer.

## See also

[CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85))