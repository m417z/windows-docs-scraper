# ID2D1RenderTarget::SetDpi

## Description

Sets the dots per inch (DPI) of the render target.

## Parameters

### `dpiX`

Type: **FLOAT**

A value greater than or equal to zero that specifies the horizontal DPI of the render target.

### `dpiY`

Type: **FLOAT**

A value greater than or equal to zero that specifies the vertical DPI of the render target.

## Remarks

This method specifies the mapping from pixel space to device-independent space for the render target. If both *dpiX* and *dpiY* are 0, the factory-read system DPI is chosen. If one parameter is zero and the other unspecified, the DPI is not changed.

For [ID2D1HwndRenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget), the DPI defaults to the most recently factory-read system DPI. The default value for all other render targets is 96 DPI.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)