# CD3D11_UNORDERED_ACCESS_VIEW_DESC::CD3D11_UNORDERED_ACCESS_VIEW_DESC(ID3D11Texture2D,D3D11_UAV_DIMENSION,DXGI_FORMAT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85)) structure that is initialized with 2D texture values.

## Parameters

### `pTex2D`

A pointer to a **ID3D11Texture2D** interface for a 2D texture.

### `viewDimension`

A **D3D11_UAV_DIMENSION**-typed value that specifies the resource type of the view.

### `format`

A **DXGI_FORMAT**-typed value that specifies the viewing format.

### `mipSlice`

The index of the mipmap level to use mip slice.

### `firstArraySlice`

The index of the first element to use in an array of elements.

### `arraySize`

Number of elements in the array.

## See also

[CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85))