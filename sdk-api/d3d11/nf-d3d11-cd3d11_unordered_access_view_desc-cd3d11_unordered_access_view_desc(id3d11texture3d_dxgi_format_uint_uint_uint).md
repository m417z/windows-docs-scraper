# CD3D11_UNORDERED_ACCESS_VIEW_DESC::CD3D11_UNORDERED_ACCESS_VIEW_DESC(ID3D11Texture3D,DXGI_FORMAT,UINT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85)) structure that is initialized with 3D texture values.

## Parameters

### `pTex3D`

A pointer to a **ID3D11Texture3D** interface for a 3D texture.

### `format`

A **DXGI_FORMAT**-typed value that specifies the viewing format.

### `mipSlice`

The index of the mipmap level to use mip slice.

### `firstWSlice`

First depth level to use.

### `wSize`

Number of depth levels to use in the render-target view, starting from *firstWSlice*.
A value of -1 indicates all of the slices along the w axis, starting from *firstWSlice*.

## See also

[CD3D11_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151712(v=vs.85))