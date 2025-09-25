# CD3D11_SHADER_RESOURCE_VIEW_DESC::CD3D11_SHADER_RESOURCE_VIEW_DESC(ID3D11Texture1D,D3D11_SRV_DIMENSION,DXGI_FORMAT,UINT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85)) structure that is initialized with **D3D11_TEX1D_SRV** or **D3D11_TEX1D_ARRAY_SRV** values.

## Parameters

### `pTex1D`

A pointer to a **ID3D11Texture1D** interface for a 1D texture.

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

### `arraySize`

Number of elements in the array.

## See also

[CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85))