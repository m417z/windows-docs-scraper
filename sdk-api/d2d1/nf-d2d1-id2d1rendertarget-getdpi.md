# ID2D1RenderTarget::GetDpi

## Description

Return the render target's dots per inch (DPI).

## Parameters

### `dpiX` [out]

Type: **FLOAT***

When this method returns, contains the horizontal DPI of the render target. This parameter is passed uninitialized.

### `dpiY` [out]

Type: **FLOAT***

When this method returns, contains the vertical DPI of the render target. This parameter is passed uninitialized.

## Remarks

This method indicates the mapping from pixel space to device-independent space for the render target.

For [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget), the DPI defaults to the most recently factory-read system DPI. The default value for all other render targets is 96 DPI.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)