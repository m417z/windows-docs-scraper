# CD3D11_SHADER_RESOURCE_VIEW_DESC::CD3D11_SHADER_RESOURCE_VIEW_DESC(ID3D11Texture3D,DXGI_FORMAT,UINT,UINT)

## Description

Instantiates a new instance of a [CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85)) structure that is initialized with 3D texture values.

## Parameters

### `pTex3D`

A pointer to a **ID3D11Texture3D** interface for a 3D texture.

### `format`

A **DXGI_FORMAT**-typed value that specifies the viewing format.

### `mostDetailedMip`

Index of the most detailed mipmap level to use; this number is from 0 to *mipLevels* -1.

### `mipLevels`

The maximum number of mipmap levels for the view.

## See also

[CD3D11_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151684(v=vs.85))