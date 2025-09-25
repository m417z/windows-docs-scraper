# ID2D1RenderTarget::GetMaximumBitmapSize

## Description

Gets the maximum size, in device-dependent units (pixels), of any one bitmap dimension supported by the render target.

## Return value

Type: **UINT32**

 The maximum size, in pixels, of any one bitmap dimension supported by the render target.

## Remarks

This method returns the maximum texture size of the Direct3D device.

**Note** The software renderer and WARP devices return the value of 16 megapixels (16*1024*1024). You can create a [Direct2D](https://learn.microsoft.com/windows/win32/Direct2D/direct2d-portal) texture that is this size, but not a Direct3D texture that is this size.

## See also

[ID2D1RenderTarget](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1rendertarget)