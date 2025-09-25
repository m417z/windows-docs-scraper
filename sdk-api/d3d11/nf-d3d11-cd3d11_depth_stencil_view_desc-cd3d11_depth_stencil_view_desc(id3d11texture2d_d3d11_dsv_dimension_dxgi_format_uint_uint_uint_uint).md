# CD3D11_DEPTH_STENCIL_VIEW_DESC::CD3D11_DEPTH_STENCIL_VIEW_DESC(ID3D11Texture2D,D3D11_DSV_DIMENSION,DXGI_FORMAT,UINT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151639(v=vs.85)) structure that is initialized with 2D texture values.

## Parameters

### `pTex2D`

A pointer to a **ID3D11Texture2D**.

### `viewDimension`

A **D3D11_DSV_DIMENSION**-typed value that specifies the depth-stencil type of the view.

### `format`

A **DXGI_FORMAT**-typed value that specifies the viewing format.

### `mipSlice`

The index of the mipmap level to use mip slice.

### `firstArraySlice`

The index of the first element to use in an array of elements.

### `arraySize`

Number of elements in the array.

### `flags`

A value that describes whether the texture is read only.
Pass 0 to specify that it is not read only; otherwise, pass one of the members of the **D3D11_DSV_FLAG** enumerated type.

## See also

[CD3D11_DEPTH_STENCIL_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151639(v=vs.85))