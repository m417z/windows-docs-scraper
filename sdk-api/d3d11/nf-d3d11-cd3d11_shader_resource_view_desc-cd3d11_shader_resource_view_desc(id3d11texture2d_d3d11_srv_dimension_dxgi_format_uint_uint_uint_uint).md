# CD3D11_SHADER_RESOURCE_VIEW_DESC::CD3D11_SHADER_RESOURCE_VIEW_DESC(ID3D11Texture2D,D3D11_SRV_DIMENSION,DXGI_FORMAT,UINT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85)) structure that is initialized with 2D texture values.

## Parameters

### `pTex2D`

A pointer to a **ID3D11Texture2D** interface for a 2D texture.

### `viewDimension`

A **D3D11_SRV_DIMENSION**-typed value that specifies the resource type of the view.

### `format`

A **DXGI_FORMAT**-typed value that specifies the viewing format.

### `mostDetailedMip`

Index of the most detailed mipmap level to use; this number is from 0 to *mipLevels* -1.

### `mipLevels`

The maximum number of mipmap levels for the view.

### `firstArraySlice`

The index of the first element to use in an array of elements.
**First2DArrayFace** of **D3D11_TEXCUBE_ARRAY_SRV**.

### `arraySize`

Number of elements in the array.
**NumCubes** of **D3D11_TEXCUBE_ARRAY_SRV**.

## See also

[CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85))