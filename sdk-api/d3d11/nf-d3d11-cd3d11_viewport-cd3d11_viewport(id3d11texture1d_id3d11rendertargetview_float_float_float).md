# CD3D11_VIEWPORT::CD3D11_VIEWPORT(ID3D11Texture1D,ID3D11RenderTargetView,FLOAT,FLOAT,FLOAT)

## Description

Instantiates a new instance of a [CD3D11_VIEWPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151722(v=vs.85)) structure that is initialized with **D3D11_TEX1D_RTV** or **D3D11_TEX1D_ARRAY_RTV** values.

## Parameters

### `pTex1D`

A pointer to a **ID3D11Texture1D** interface for a 1D texture.

### `pRTView`

A pointer to a **ID3D11RenderTargetView** interface for the render-target view.

### `topLeftX`

X position of the left hand side of the viewport.
Ranges between **D3D11_VIEWPORT_BOUNDS_MIN** and **D3D11_VIEWPORT_BOUNDS_MAX**.

### `minDepth`

Minimum depth of the viewport.
Ranges between 0 and 1.

### `maxDepth`

Maximum depth of the viewport.
Ranges between 0 and 1.

## See also

[CD3D11_VIEWPORT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151722(v=vs.85))