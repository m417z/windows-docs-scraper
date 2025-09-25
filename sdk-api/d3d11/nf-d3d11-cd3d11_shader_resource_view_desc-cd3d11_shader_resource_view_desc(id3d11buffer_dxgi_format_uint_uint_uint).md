# CD3D11_SHADER_RESOURCE_VIEW_DESC::CD3D11_SHADER_RESOURCE_VIEW_DESC(ID3D11Buffer,DXGI_FORMAT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85)) structure that is initialized with **D3D11_BUFFEREX_SRV** values.

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

A **D3D11_BUFFEREX_SRV_FLAG**-typed value that identifies view options for a buffer.

## See also

[CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85))